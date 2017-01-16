# Orange Ball detection
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

#### CircleFinder submodule

## Toolchain
### Main Toolchain
* OpenCV (3.1)
* g++ (5.4.0)
* CMake (3.6)

### Optional
* Doxygen (1.8.11)
* Google-Test (1.8.0)

### Installation
At the moment Ubuntu (16.04 amd64) is the only supported OS.
The code can run on all *nix system but hasn't been tested.

First install the compiler, cmake (the build-system), 
doxygen (used for documentation) and git (used as VCS):

    sudo apt-get install build-essential cmake doxygen git


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
