#include "gtest/gtest.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "../CircleFinder.hpp"

#include "IsCircleTest/ToFewPoints.h"
#include "IsCircleTest/NoMatchingPoints.h"
#include "IsCircleTest/ImageTests/BasicCircle.h"
#include "IsCircleTest/ImageTests/CircleFragment.h"
#include "IsCircleTest/ImageTests/HalfCircle.h"
#include "IsCircleTest/ImageTests/HorizontalLine.h"
#include "IsCircleTest/ImageTests/ImperfectCircle.h"
#include "IsCircleTest/ImageTests/LineWithEdges.h"
#include "IsCircleTest/ImageTests/LineWithLargeEdge.h"
#include "IsCircleTest/ImageTests/LineWithSmallEdge.h"
#include "IsCircleTest/ImageTests/RoundedLine.h"
#include "IsCircleTest/ImageTests/SmallCircle.h"
#include "IsCircleTest/ImageTests/Triangle.h"
#include "IsCircleTest/ImageTests/VerticalLine.h"

//@TODO CircleWithEdges generieren


int main(int argc, char **argv) {
      ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
