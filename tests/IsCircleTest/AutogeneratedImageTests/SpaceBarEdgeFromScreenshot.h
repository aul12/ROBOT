TEST(isCircleTest, SpaceBarEdgeFromScreenshot){
	EXPECT_FALSE(crclfnd::isCircle(
		{
		Point(298,322),
		Point(298,323),
		Point(297,324),
		Point(297,332),
		Point(296,333),
		Point(296,340),
		Point(294,342),
		Point(280,342),
		Point(279,341),
		Point(262,341),
		Point(261,340),
		Point(252,340),
		Point(251,339),
		Point(231,339),
		Point(230,338),
		Point(212,338),
		Point(211,337),
		Point(193,337),
		Point(192,336),
		Point(173,336),
		Point(172,335),
		Point(160,335),
		Point(159,334),
		Point(145,334),
		Point(144,333),
		Point(123,333),
		Point(122,332),
		Point(105,332),
		Point(104,331),
		Point(96,331),
		Point(95,330),
		Point(94,330),
		Point(93,331),
		Point(92,331),
		Point(92,333),
		Point(93,333),
		Point(94,334),
		Point(102,334),
		Point(103,335),
		Point(120,335),
		Point(121,336),
		Point(142,336),
		Point(143,337),
		Point(157,337),
		Point(158,338),
		Point(170,338),
		Point(171,339),
		Point(190,339),
		Point(191,340),
		Point(209,340),
		Point(210,341),
		Point(228,341),
		Point(229,342),
		Point(249,342),
		Point(250,343),
		Point(259,343),
		Point(260,344),
		Point(277,344),
		Point(278,345),
		Point(297,345),
		Point(299,343),
		Point(299,335),
		Point(300,334),
		Point(300,326),
		Point(301,325),
		Point(301,322)
		}
	).isCircle);
}