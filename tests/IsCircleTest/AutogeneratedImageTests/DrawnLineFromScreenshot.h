TEST(isCircleTest, DrawnLineFromScreenshot){
	EXPECT_FALSE(crclfnd::isCircle(
		{
		Point(120,164),
		Point(120,165),
		Point(119,166),
		Point(119,167),
		Point(120,168),
		Point(120,175),
		Point(121,176),
		Point(121,179),
		Point(122,180),
		Point(122,186),
		Point(123,187),
		Point(123,188),
		Point(124,189),
		Point(124,191),
		Point(125,192),
		Point(125,193),
		Point(126,194),
		Point(126,195),
		Point(128,197),
		Point(128,198),
		Point(131,201),
		Point(132,201),
		Point(134,203),
		Point(135,203),
		Point(140,208),
		Point(141,208),
		Point(144,211),
		Point(145,211),
		Point(146,212),
		Point(147,212),
		Point(148,213),
		Point(149,213),
		Point(151,215),
		Point(152,215),
		Point(153,216),
		Point(154,216),
		Point(155,217),
		Point(156,217),
		Point(157,218),
		Point(159,218),
		Point(160,219),
		Point(161,219),
		Point(162,220),
		Point(163,220),
		Point(164,221),
		Point(165,221),
		Point(166,222),
		Point(167,222),
		Point(168,223),
		Point(170,223),
		Point(171,224),
		Point(173,224),
		Point(174,225),
		Point(176,225),
		Point(177,226),
		Point(178,226),
		Point(179,227),
		Point(180,227),
		Point(181,228),
		Point(182,228),
		Point(183,229),
		Point(190,229),
		Point(190,226),
		Point(189,225),
		Point(189,224),
		Point(188,224),
		Point(187,223),
		Point(186,223),
		Point(185,222),
		Point(184,222),
		Point(183,221),
		Point(182,221),
		Point(181,220),
		Point(180,220),
		Point(179,219),
		Point(176,219),
		Point(175,218),
		Point(173,218),
		Point(172,217),
		Point(171,217),
		Point(170,216),
		Point(168,216),
		Point(166,214),
		Point(165,214),
		Point(164,213),
		Point(163,213),
		Point(162,212),
		Point(161,212),
		Point(160,211),
		Point(159,211),
		Point(158,210),
		Point(156,210),
		Point(154,208),
		Point(153,208),
		Point(152,207),
		Point(151,207),
		Point(147,203),
		Point(146,203),
		Point(142,199),
		Point(141,199),
		Point(138,196),
		Point(137,196),
		Point(132,191),
		Point(132,190),
		Point(131,189),
		Point(131,188),
		Point(130,187),
		Point(130,186),
		Point(129,185),
		Point(129,183),
		Point(128,182),
		Point(128,174),
		Point(127,173),
		Point(125,173),
		Point(125,174),
		Point(126,173),
		Point(128,175),
		Point(128,182),
		Point(129,183),
		Point(129,185),
		Point(130,186),
		Point(130,187),
		Point(131,188),
		Point(131,189),
		Point(132,190),
		Point(132,191),
		Point(133,192),
		Point(133,193),
		Point(135,195),
		Point(136,195),
		Point(139,198),
		Point(140,198),
		Point(144,202),
		Point(145,202),
		Point(149,206),
		Point(150,206),
		Point(151,207),
		Point(152,207),
		Point(154,209),
		Point(155,209),
		Point(156,210),
		Point(158,210),
		Point(160,212),
		Point(162,212),
		Point(163,213),
		Point(164,213),
		Point(166,215),
		Point(167,215),
		Point(168,216),
		Point(170,216),
		Point(171,217),
		Point(172,217),
		Point(173,218),
		Point(175,218),
		Point(176,219),
		Point(179,219),
		Point(180,220),
		Point(181,220),
		Point(182,221),
		Point(183,221),
		Point(184,222),
		Point(185,222),
		Point(186,223),
		Point(187,223),
		Point(190,226),
		Point(190,228),
		Point(189,229),
		Point(183,229),
		Point(182,228),
		Point(181,228),
		Point(180,227),
		Point(179,227),
		Point(178,226),
		Point(177,226),
		Point(176,225),
		Point(174,225),
		Point(173,224),
		Point(171,224),
		Point(170,223),
		Point(168,223),
		Point(167,222),
		Point(166,222),
		Point(165,221),
		Point(164,221),
		Point(163,220),
		Point(162,220),
		Point(161,219),
		Point(160,219),
		Point(159,218),
		Point(157,218),
		Point(156,217),
		Point(155,217),
		Point(154,216),
		Point(153,216),
		Point(151,214),
		Point(150,214),
		Point(149,213),
		Point(148,213),
		Point(147,212),
		Point(146,212),
		Point(143,209),
		Point(142,209),
		Point(137,204),
		Point(136,204),
		Point(134,202),
		Point(133,202),
		Point(127,196),
		Point(127,195),
		Point(125,193),
		Point(125,192),
		Point(124,191),
		Point(124,189),
		Point(123,188),
		Point(123,187),
		Point(122,186),
		Point(122,180),
		Point(121,179),
		Point(121,176),
		Point(120,175),
		Point(120,168),
		Point(119,167),
		Point(119,166),
		Point(121,164),
		Point(123,166),
		Point(123,174),
		Point(123,165),
		Point(122,164)
		}
	).isCircle);
}