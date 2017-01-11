TEST(isCircleTest, VerticalLine){
	EXPECT_FALSE(crclfnd::isCircle(
		{
		Point(285,60),
		Point(283,62),
		Point(283,445),
		Point(284,446),
		Point(300,446),
		Point(300,61),
		Point(299,60)
		}
	));
}