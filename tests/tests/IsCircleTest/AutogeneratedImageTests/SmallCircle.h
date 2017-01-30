TEST(isCircleTest, SmallCircle){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(144,237),
		Point(143,238),
		Point(139,238),
		Point(138,239),
		Point(136,239),
		Point(135,240),
		Point(134,240),
		Point(133,241),
		Point(132,241),
		Point(130,243),
		Point(129,243),
		Point(125,247),
		Point(125,248),
		Point(123,250),
		Point(123,251),
		Point(122,252),
		Point(122,253),
		Point(121,254),
		Point(121,256),
		Point(120,257),
		Point(120,261),
		Point(119,262),
		Point(119,264),
		Point(120,265),
		Point(120,269),
		Point(121,270),
		Point(121,272),
		Point(122,273),
		Point(122,274),
		Point(123,275),
		Point(123,276),
		Point(125,278),
		Point(125,279),
		Point(129,283),
		Point(130,283),
		Point(132,285),
		Point(133,285),
		Point(134,286),
		Point(136,286),
		Point(137,287),
		Point(141,287),
		Point(142,288),
		Point(148,288),
		Point(149,287),
		Point(153,287),
		Point(154,286),
		Point(156,286),
		Point(157,285),
		Point(158,285),
		Point(160,283),
		Point(161,283),
		Point(165,279),
		Point(165,278),
		Point(167,276),
		Point(167,275),
		Point(168,274),
		Point(168,272),
		Point(169,271),
		Point(169,267),
		Point(170,266),
		Point(170,260),
		Point(169,259),
		Point(169,255),
		Point(168,254),
		Point(168,252),
		Point(167,251),
		Point(167,250),
		Point(165,248),
		Point(165,247),
		Point(161,243),
		Point(160,243),
		Point(158,241),
		Point(157,241),
		Point(156,240),
		Point(155,240),
		Point(154,239),
		Point(152,239),
		Point(151,238),
		Point(147,238),
		Point(146,237)
		}
	).isCircle);
}