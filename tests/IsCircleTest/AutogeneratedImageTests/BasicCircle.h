TEST(isCircleTest, BasicCircle){
	#warning Change Value!
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(160,32),
		Point(159,33),
		Point(153,33),
		Point(152,34),
		Point(148,34),
		Point(147,35),
		Point(143,35),
		Point(142,36),
		Point(140,36),
		Point(139,37),
		Point(137,37),
		Point(136,38),
		Point(134,38),
		Point(133,39),
		Point(131,39),
		Point(130,40),
		Point(129,40),
		Point(128,41),
		Point(126,41),
		Point(125,42),
		Point(124,42),
		Point(123,43),
		Point(122,43),
		Point(121,44),
		Point(120,44),
		Point(119,45),
		Point(118,45),
		Point(117,46),
		Point(116,46),
		Point(114,48),
		Point(113,48),
		Point(112,49),
		Point(111,49),
		Point(109,51),
		Point(108,51),
		Point(106,53),
		Point(105,53),
		Point(103,55),
		Point(102,55),
		Point(97,60),
		Point(96,60),
		Point(87,69),
		Point(87,70),
		Point(82,75),
		Point(82,76),
		Point(80,78),
		Point(80,79),
		Point(78,81),
		Point(78,82),
		Point(76,84),
		Point(76,85),
		Point(75,86),
		Point(75,87),
		Point(73,89),
		Point(73,90),
		Point(72,91),
		Point(72,92),
		Point(71,93),
		Point(71,94),
		Point(70,95),
		Point(70,96),
		Point(69,97),
		Point(69,98),
		Point(68,99),
		Point(68,101),
		Point(67,102),
		Point(67,103),
		Point(66,104),
		Point(66,106),
		Point(65,107),
		Point(65,109),
		Point(64,110),
		Point(64,112),
		Point(63,113),
		Point(63,115),
		Point(62,116),
		Point(62,120),
		Point(61,121),
		Point(61,125),
		Point(60,126),
		Point(60,132),
		Point(59,133),
		Point(59,153),
		Point(60,154),
		Point(60,160),
		Point(61,161),
		Point(61,165),
		Point(62,166),
		Point(62,170),
		Point(63,171),
		Point(63,173),
		Point(64,174),
		Point(64,176),
		Point(65,177),
		Point(65,179),
		Point(66,180),
		Point(66,182),
		Point(67,183),
		Point(67,184),
		Point(68,185),
		Point(68,187),
		Point(69,188),
		Point(69,189),
		Point(70,190),
		Point(70,191),
		Point(71,192),
		Point(71,193),
		Point(72,194),
		Point(72,195),
		Point(73,196),
		Point(73,197),
		Point(75,199),
		Point(75,200),
		Point(76,201),
		Point(76,202),
		Point(78,204),
		Point(78,205),
		Point(80,207),
		Point(80,208),
		Point(82,210),
		Point(82,211),
		Point(87,216),
		Point(87,217),
		Point(96,226),
		Point(97,226),
		Point(102,231),
		Point(103,231),
		Point(105,233),
		Point(106,233),
		Point(108,235),
		Point(109,235),
		Point(111,237),
		Point(112,237),
		Point(113,238),
		Point(114,238),
		Point(116,240),
		Point(117,240),
		Point(118,241),
		Point(119,241),
		Point(120,242),
		Point(121,242),
		Point(122,243),
		Point(123,243),
		Point(124,244),
		Point(126,244),
		Point(127,245),
		Point(128,245),
		Point(129,246),
		Point(131,246),
		Point(132,247),
		Point(134,247),
		Point(135,248),
		Point(137,248),
		Point(138,249),
		Point(140,249),
		Point(141,250),
		Point(145,250),
		Point(146,251),
		Point(150,251),
		Point(151,252),
		Point(157,252),
		Point(158,253),
		Point(182,253),
		Point(183,252),
		Point(189,252),
		Point(190,251),
		Point(194,251),
		Point(195,250),
		Point(199,250),
		Point(200,249),
		Point(202,249),
		Point(203,248),
		Point(205,248),
		Point(206,247),
		Point(208,247),
		Point(209,246),
		Point(211,246),
		Point(212,245),
		Point(213,245),
		Point(214,244),
		Point(216,244),
		Point(217,243),
		Point(218,243),
		Point(219,242),
		Point(220,242),
		Point(221,241),
		Point(222,241),
		Point(223,240),
		Point(224,240),
		Point(226,238),
		Point(227,238),
		Point(228,237),
		Point(229,237),
		Point(231,235),
		Point(232,235),
		Point(234,233),
		Point(235,233),
		Point(237,231),
		Point(238,231),
		Point(243,226),
		Point(244,226),
		Point(253,217),
		Point(253,216),
		Point(258,211),
		Point(258,210),
		Point(260,208),
		Point(260,207),
		Point(262,205),
		Point(262,204),
		Point(264,202),
		Point(264,201),
		Point(265,200),
		Point(265,199),
		Point(267,197),
		Point(267,196),
		Point(268,195),
		Point(268,194),
		Point(269,193),
		Point(269,192),
		Point(270,191),
		Point(270,190),
		Point(271,189),
		Point(271,187),
		Point(272,186),
		Point(272,185),
		Point(273,184),
		Point(273,182),
		Point(274,181),
		Point(274,179),
		Point(275,178),
		Point(275,176),
		Point(276,175),
		Point(276,173),
		Point(277,172),
		Point(277,168),
		Point(278,167),
		Point(278,163),
		Point(279,162),
		Point(279,156),
		Point(280,155),
		Point(280,131),
		Point(279,130),
		Point(279,124),
		Point(278,123),
		Point(278,119),
		Point(277,118),
		Point(277,114),
		Point(276,113),
		Point(276,111),
		Point(275,110),
		Point(275,108),
		Point(274,107),
		Point(274,105),
		Point(273,104),
		Point(273,102),
		Point(272,101),
		Point(272,100),
		Point(271,99),
		Point(271,97),
		Point(270,96),
		Point(270,95),
		Point(269,94),
		Point(269,93),
		Point(268,92),
		Point(268,91),
		Point(267,90),
		Point(267,89),
		Point(265,87),
		Point(265,86),
		Point(264,85),
		Point(264,84),
		Point(262,82),
		Point(262,81),
		Point(260,79),
		Point(260,78),
		Point(258,76),
		Point(258,75),
		Point(253,70),
		Point(253,69),
		Point(244,60),
		Point(243,60),
		Point(238,55),
		Point(237,55),
		Point(235,53),
		Point(234,53),
		Point(232,51),
		Point(231,51),
		Point(229,49),
		Point(228,49),
		Point(227,48),
		Point(226,48),
		Point(224,46),
		Point(223,46),
		Point(222,45),
		Point(221,45),
		Point(220,44),
		Point(219,44),
		Point(218,43),
		Point(217,43),
		Point(216,42),
		Point(215,42),
		Point(214,41),
		Point(212,41),
		Point(211,40),
		Point(210,40),
		Point(209,39),
		Point(207,39),
		Point(206,38),
		Point(204,38),
		Point(203,37),
		Point(201,37),
		Point(200,36),
		Point(198,36),
		Point(197,35),
		Point(193,35),
		Point(192,34),
		Point(188,34),
		Point(187,33),
		Point(181,33),
		Point(180,32)
		}
	));
}