TEST(isCircleTest, VerySmallCircle){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(257,138),
		Point(256,139),
		Point(253,139),
		Point(252,140),
		Point(251,140),
		Point(250,141),
		Point(249,141),
		Point(245,145),
		Point(245,146),
		Point(244,147),
		Point(244,148),
		Point(243,149),
		Point(243,152),
		Point(242,153),
		Point(243,154),
		Point(243,157),
		Point(244,158),
		Point(244,159),
		Point(245,160),
		Point(245,161),
		Point(249,165),
		Point(250,165),
		Point(251,166),
		Point(254,166),
		Point(255,167),
		Point(259,167),
		Point(260,166),
		Point(263,166),
		Point(264,165),
		Point(265,165),
		Point(269,161),
		Point(269,160),
		Point(270,159),
		Point(270,156),
		Point(271,155),
		Point(271,151),
		Point(270,150),
		Point(270,147),
		Point(269,146),
		Point(269,145),
		Point(265,141),
		Point(264,141),
		Point(263,140),
		Point(262,140),
		Point(261,139),
		Point(258,139)
		}
	));
}