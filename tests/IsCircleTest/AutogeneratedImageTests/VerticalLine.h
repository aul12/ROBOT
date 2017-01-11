TEST(isCircleTest, VerticalLine){
	#warning Change Value!
	EXPECT_TRUE(crclfnd::isCircle(
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