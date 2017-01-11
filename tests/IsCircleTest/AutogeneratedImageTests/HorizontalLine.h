TEST(isCircleTest, HorizontalLine){
	#warning Change Value!
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(94,174),
		Point(92,176),
		Point(93,177),
		Point(601,177),
		Point(601,175),
		Point(600,174)
		}
	));
}