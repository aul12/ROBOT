TEST(isCircleTest, HorizontalLine){
	EXPECT_FALSE(crclfnd::isCircle(
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