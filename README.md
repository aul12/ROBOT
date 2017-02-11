# ROBOT - ROBOT Orange Ball-shaped Object Tracker

[![build status](https://git.markdorf-robotics.de/panykiel/OrangeBall/badges/master/build.svg)](https://git.markdorf-robotics.de/panykiel/OrangeBall/commits/master)

## Modules
### Color Based

---

#### HSV colorspace
The module converts the BGR (<b>B</b>lue-<b>G</b>reen-<b>R</b>ed) 
image to a HSV (<b>H</b>ue-<b>S</b>aturation-<b>V</b>alue).
The HSV colorspace has the huge advantage that only the Hue and Saturation values
need to be precise. The value (comparable to the brightness), does not need to be
checked so the filter shouldn't be influenced by changing brightness.

---

The algorithm blurs the image at first to reduce noise. Next it checks pixel-wise if
the respective pixel fits the criteria (minHue, maxHue, minSaturation...). If it fits
it will be drawn as a white pixel on the output img, if not it will be drawn as a black image.

Finally all contour areas get sorted by size and the largest is highlighted in the image.

### Canny
The Canny algorithm is used to detect edges in the image. 
The algorithm only works on a single color plane (for example Black and White),
that's why we apply a special colour filter beforehand. The contours
then are checked on their circularity.

#### Colour Filter
The colour filter was designed to get the best possible contrast between
the ball and its surroundings. Therefore we use two filters:
* The first one is a simple red filter, changing objects with high green 
  component to dark and bright or reddish objects to white. This however 
  results in the Canny algorithm being unable to clearly distinguish between white 
  lines and the ball. When the ball lies on said lines, its contours might melt together
  with the lines' ones. To avoid this problem we use a second filter.
* The second filter is a simple green filter. After applying this filter
  to the original image the field and the line appear white and the ball completely
  black. We additionally invert the filtered image so the ball becomes a white object
  while the field and other objects become dark.
  
Both images are combined, but with different weight. This results in an overall grayish
image where only orange / red objects are clearly visible.

#### Canny algorithm
The algorithm uses gradient based edge detection to find possible edges in an image. 
It basically consists of following procedures:
1. A Gaussian blur is applied to smooth the image in order to reduce noise
2. Calculate the intensity gradients of pixels
3. Suppress maximums close to larger intensity gradient maximums
4. Apply double threshold to classify edges in strong, weak edges. Edges below both thresholds 
will be ignored
5. Edge tracking: Ignore weak edges which are not connected to strong ones.

For further information on the Canny algorithm see: https://en.wikipedia.org/wiki/Canny_edge_detector
#### CircleFinder submodule
The CircleFinder submodule determines which objects created by the Canny algorithm resemble a circle-like object. 
Every Canny-object will be put through following procedures:
1. If an object contains less than a specific amount of points
   (e.g. a line which only has a start and an end or a small noise dot),
   it will be determined a non-circle object.
2. The algorithm places a triangle with two equally long edges in the object.
3. If the triangle is to flat (two angles are smaller than a specific threshold),
   the object will be determined a non-circle object.
4. For each triangle edge the midperpendicular is calculated.
5. The intersections of said midperpendiculars are calculated. If there is no intersection,
   the object is determined a non-circle object.
6. Since more than one intersection of the midperpendiculars can exist (due to inaccuracy during
   measurement or calculation), the middle of all intersections is calculated. If however the 
   intersections differ to far from each other, the object will be determined an non-cirlce object.
7. The middle of the three intersections resembles the center of a potential circle.
8. The radius of the potential circle is calculated as the average of the distances of each 
   triangle corner to the center.
9. The distance of every point of the object to the center is calculated. If said distance differs 
   to far from the radius calculated in step 9, the object will be determined a non-circle object.
   The difference-threshold used in this step to determine whether an object is a circle is 
   calculated according to the potential circle's radius.
10. If all previous steps are passed, the object will be determined a circle-like object.

## Runner
Because there is no build server available gitlab requires a runner to build, 
execute and test the program, therefore you are advised to install a runner on your
development machine.

### Installation
First add the gitlab-runner package to your package-list:

    wget https://packages.gitlab.com/install/repositories/runner/gitlab-ci-multi-runner/script.deb.sh
    
    sudo bash script.deb.sh

Finally install the gitlab-runner:

    sudo apt-get install gitlab-ci-multi-runner
    
If you haven't already installed all dev-dependencies you are advised to do so, the gitlab-runner requires them.
     
## Configure the runner
To use the runner you need to configure the runner to build the project in the right repo:

    sudo gitlab-ci-multi-runner register
    
During execution enter [https://git.markdorf-robotics.de/ci](https://git.markdorf-robotics.de/ci) 
as the "gitlab-ci coordinator URL".

Next get a token for the repo. The token is available
in the settings of the gitlab page 
([https://git.markdorf-robotics.de/panykiel/OrangeBall/runners](https://git.markdorf-robotics.de/panykiel/OrangeBall/runners)).
Enter this token as "gitlab-ci token for this runner".

Next enter a description of your runner (e.g. John Doe's Laptop).

Finally you need to select a executor, just choose "shell".

## Coding Style
The code style should follow the kernel.org code style 
[https://www.kernel.org/doc/Documentation/process/coding-style.rst](https://www.kernel.org/doc/Documentation/process/coding-style.rst).
The only difference is the naming convention: we strictly advise you to use camelCase
naming, this helps the readability and reduces the length of variable names.

## Toolchain
### Main Toolchain
* OpenCV (3.1)
* g++ (5.4.0)
* CMake (3.6)
* Doxygen (1.8.11)
* Google-Test (1.8.0)
* cppcheck (1.72)

### Installation
At the moment Ubuntu (16.04 amd64) is the only supported OS.
The code can run on all *nix system but hasn't been tested.

First install the compiler, cmake (the build-system), 
doxygen (used for documentation), git (used as VCS) 
and cppcheck (used for static code analysis):

    sudo apt-get install build-essential cmake doxygen git cppcheck


#### OpenCV

Next you have to compile OpenCV:
First install all dependencies:


    sudo apt-get install libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev


Create a new folder in your working directory (for example ~/OpenCVInstallation).
In the Terminal change directory to folder (cd ~/OpenCVInstallation).
Then run:


    git clone https://github.com/Itseez/opencv.git


Next compile it, therefore create a build directory:

Change to repo folder:

    cd opencv


Create a new folder:

    mkdir build


Change to build folder:

    cd build


Next run CMake to configure your installation:

    cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..


If there is no error, compile OpenCV, this may take some time:

    make


Finally, install the compiled OpenCV:

    sudo make install


#### GTest

To do unit-testing you need to install GTest.

Download the source and install the dependencies:
    
    sudo apt-get install libgtest-dev


Next change to source-directoy:

    cd /usr/src/gtest


Next run CMake to configure the project: 
    
    sudo cmake CMakeLists.txt


Compile the project:    
    
    sudo make


Finally install GTest:

    sudo cp *.a /usr/lib


## Calibration

### CircleFinder Module

#### Calibration during runtime


There are three sliders which let you configure the canny threshold and the colour filter:
1. Threshold: Sets the threshold for the edge detector. A high value means that only prominent
 and clearly visible edges will be detected by the Canny algorithm. At a low value the edge detector
 is more tolerant.
2. Color bias: Determines the ratio of the two pre-color-filters. Low values (slider on the right)
 mean that the inverted green filter will be weighted greater than the red filter and vise versa.
3. Contrast: Sets the contrast of the filtered image.

Example how to configure the three values to ensure the best results:
1.  Set Threshold and Color bias to maximum and Contrast to the lowest possible amount before the
    image becomes only gray.
    <br><br><br>
    ![Image Step 1](https://git.markdorf-robotics.de/panykiel/OrangeBall/raw/master/calibrationImg/filterStep1.png "Step 1")
    <br><br><br>
2.  Set Color bias to a value where all background colors appear in the same grayish tone and
    only reddish colors are clearly distinguished.
    <br><br><br>
    ![Image Step 2](https://git.markdorf-robotics.de/panykiel/OrangeBall/raw/master/calibrationImg/filterStep2.png "Step 2")
    <br><br><br>
3.  Adjust the contrast so reddish areas are marked by red / green lines (detected as edge). You can do this
    simultaneously with the previous step if necessary.
    <br><br><br>
    ![Image Step 3](https://git.markdorf-robotics.de/panykiel/OrangeBall/raw/master/calibrationImg/filterStep3.png "Step 3")

    <br><br><br>
4.  Reduce the Canny threshold to improve edge detection of reddish objects. Don't go to low
    to avoid noise.
    <br><br><br>
    ![Image Step 4](https://git.markdorf-robotics.de/panykiel/OrangeBall/raw/master/calibrationImg/filterStep4.png "Step 4")
    <br><br><br>
    or (with a lower contrast, the canny threshold needs to be lower. 
    Both setups work equally well. Choose one depending on the environmental lighting)
    <br><br><br>
    ![Image Step 4 alternative](https://git.markdorf-robotics.de/panykiel/OrangeBall/raw/master/calibrationImg/filterStep4_1.png "Step 4 alternative")

 

---
#### Configure the circle detection

Following variables let you configure the CircleFinder module:
*   **minimumPoints**: Edge-objects consisting of less points than specified will be ignored without
    even being put through the whole test procedure. You can use this variable to reduce the amount
    of objects the CircleFinder has to go through. A recommended value would be around 10.
*   **maxRadius** and **minRadius**: Round edges with a radius not between max and minRadius will be
    sorted out. Use this option to ignore small noise dots or large slightly rounded edges which
    don't resemble a circle.