TEST(isCircleTest, Triangle){
	#warning Change Value!
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(93,39),
		Point(92,40),
		Point(91,40),
		Point(90,41),
		Point(89,41),
		Point(87,43),
		Point(86,43),
		Point(86,44),
		Point(84,46),
		Point(84,47),
		Point(83,48),
		Point(83,49),
		Point(82,50),
		Point(82,58),
		Point(83,59),
		Point(83,61),
		Point(84,62),
		Point(84,63),
		Point(85,64),
		Point(85,66),
		Point(86,67),
		Point(86,69),
		Point(87,70),
		Point(87,72),
		Point(88,73),
		Point(88,74),
		Point(89,75),
		Point(89,80),
		Point(90,81),
		Point(90,82),
		Point(91,83),
		Point(91,85),
		Point(92,86),
		Point(92,88),
		Point(93,89),
		Point(93,91),
		Point(94,92),
		Point(94,93),
		Point(95,94),
		Point(95,96),
		Point(96,97),
		Point(96,99),
		Point(97,100),
		Point(97,102),
		Point(98,103),
		Point(98,104),
		Point(99,105),
		Point(99,107),
		Point(100,108),
		Point(100,110),
		Point(101,111),
		Point(101,112),
		Point(102,113),
		Point(102,115),
		Point(103,116),
		Point(103,121),
		Point(104,122),
		Point(104,123),
		Point(105,124),
		Point(105,126),
		Point(106,127),
		Point(106,129),
		Point(107,130),
		Point(107,131),
		Point(108,132),
		Point(108,134),
		Point(109,135),
		Point(109,137),
		Point(110,138),
		Point(110,140),
		Point(111,141),
		Point(111,142),
		Point(112,143),
		Point(112,145),
		Point(113,146),
		Point(113,148),
		Point(114,149),
		Point(114,151),
		Point(115,152),
		Point(115,153),
		Point(116,154),
		Point(116,156),
		Point(117,157),
		Point(117,161),
		Point(118,162),
		Point(118,164),
		Point(119,165),
		Point(119,167),
		Point(120,168),
		Point(120,170),
		Point(121,171),
		Point(121,172),
		Point(122,173),
		Point(122,175),
		Point(123,176),
		Point(123,178),
		Point(124,179),
		Point(124,180),
		Point(125,181),
		Point(125,183),
		Point(126,184),
		Point(126,186),
		Point(127,187),
		Point(127,189),
		Point(128,190),
		Point(128,191),
		Point(129,192),
		Point(129,194),
		Point(130,195),
		Point(130,199),
		Point(131,200),
		Point(131,202),
		Point(132,203),
		Point(132,205),
		Point(133,206),
		Point(133,208),
		Point(134,209),
		Point(134,210),
		Point(135,211),
		Point(135,213),
		Point(136,214),
		Point(136,216),
		Point(137,217),
		Point(137,219),
		Point(138,220),
		Point(138,221),
		Point(139,222),
		Point(139,224),
		Point(140,225),
		Point(140,227),
		Point(141,228),
		Point(141,229),
		Point(142,230),
		Point(142,232),
		Point(143,233),
		Point(143,235),
		Point(144,236),
		Point(144,240),
		Point(145,241),
		Point(145,243),
		Point(146,244),
		Point(146,246),
		Point(147,247),
		Point(147,248),
		Point(148,249),
		Point(148,251),
		Point(149,252),
		Point(149,254),
		Point(150,255),
		Point(150,257),
		Point(151,258),
		Point(151,259),
		Point(152,260),
		Point(152,262),
		Point(153,263),
		Point(153,265),
		Point(154,266),
		Point(154,268),
		Point(155,269),
		Point(155,270),
		Point(156,271),
		Point(156,273),
		Point(157,274),
		Point(157,276),
		Point(158,277),
		Point(158,281),
		Point(159,282),
		Point(159,284),
		Point(160,285),
		Point(160,287),
		Point(161,288),
		Point(161,289),
		Point(162,290),
		Point(162,292),
		Point(163,293),
		Point(163,295),
		Point(164,296),
		Point(164,297),
		Point(165,298),
		Point(165,300),
		Point(166,301),
		Point(166,303),
		Point(167,304),
		Point(167,306),
		Point(168,307),
		Point(168,308),
		Point(169,309),
		Point(169,310),
		Point(171,312),
		Point(171,313),
		Point(172,313),
		Point(174,315),
		Point(175,315),
		Point(176,316),
		Point(188,316),
		Point(189,315),
		Point(190,315),
		Point(191,314),
		Point(193,314),
		Point(194,313),
		Point(196,313),
		Point(197,312),
		Point(198,312),
		Point(199,311),
		Point(200,311),
		Point(202,309),
		Point(203,309),
		Point(204,308),
		Point(206,308),
		Point(207,307),
		Point(209,307),
		Point(210,306),
		Point(211,306),
		Point(212,305),
		Point(214,305),
		Point(215,304),
		Point(217,304),
		Point(218,303),
		Point(219,303),
		Point(220,302),
		Point(221,302),
		Point(223,300),
		Point(225,300),
		Point(226,299),
		Point(227,299),
		Point(228,298),
		Point(230,298),
		Point(231,297),
		Point(233,297),
		Point(234,296),
		Point(235,296),
		Point(236,295),
		Point(238,295),
		Point(239,294),
		Point(240,294),
		Point(242,292),
		Point(243,292),
		Point(244,291),
		Point(246,291),
		Point(247,290),
		Point(248,290),
		Point(249,289),
		Point(251,289),
		Point(252,288),
		Point(254,288),
		Point(255,287),
		Point(256,287),
		Point(257,286),
		Point(258,286),
		Point(260,284),
		Point(262,284),
		Point(263,283),
		Point(264,283),
		Point(265,282),
		Point(267,282),
		Point(268,281),
		Point(270,281),
		Point(271,280),
		Point(272,280),
		Point(273,279),
		Point(275,279),
		Point(276,278),
		Point(277,278),
		Point(278,277),
		Point(279,277),
		Point(281,275),
		Point(283,275),
		Point(284,274),
		Point(285,274),
		Point(286,273),
		Point(288,273),
		Point(289,272),
		Point(291,272),
		Point(292,271),
		Point(293,271),
		Point(294,270),
		Point(296,270),
		Point(297,269),
		Point(298,269),
		Point(300,267),
		Point(301,267),
		Point(302,266),
		Point(304,266),
		Point(305,265),
		Point(307,265),
		Point(308,264),
		Point(309,264),
		Point(310,263),
		Point(312,263),
		Point(313,262),
		Point(314,262),
		Point(315,261),
		Point(316,261),
		Point(318,259),
		Point(320,259),
		Point(321,258),
		Point(322,258),
		Point(323,257),
		Point(325,257),
		Point(326,256),
		Point(328,256),
		Point(329,255),
		Point(330,255),
		Point(331,254),
		Point(333,254),
		Point(334,253),
		Point(336,253),
		Point(337,252),
		Point(338,252),
		Point(340,250),
		Point(341,250),
		Point(342,249),
		Point(344,249),
		Point(345,248),
		Point(346,248),
		Point(347,247),
		Point(349,247),
		Point(350,246),
		Point(351,246),
		Point(352,245),
		Point(354,245),
		Point(355,244),
		Point(356,244),
		Point(358,242),
		Point(359,242),
		Point(360,241),
		Point(362,241),
		Point(363,240),
		Point(365,240),
		Point(366,239),
		Point(367,239),
		Point(368,238),
		Point(370,238),
		Point(371,237),
		Point(373,237),
		Point(374,236),
		Point(375,236),
		Point(376,235),
		Point(377,235),
		Point(379,233),
		Point(381,233),
		Point(382,232),
		Point(383,232),
		Point(384,231),
		Point(386,231),
		Point(387,230),
		Point(388,230),
		Point(389,229),
		Point(391,229),
		Point(392,228),
		Point(394,228),
		Point(395,227),
		Point(396,227),
		Point(398,225),
		Point(399,225),
		Point(400,224),
		Point(402,224),
		Point(403,223),
		Point(404,223),
		Point(405,222),
		Point(407,222),
		Point(408,221),
		Point(409,221),
		Point(411,219),
		Point(412,219),
		Point(413,218),
		Point(413,217),
		Point(415,215),
		Point(415,214),
		Point(416,213),
		Point(416,201),
		Point(415,200),
		Point(415,199),
		Point(413,197),
		Point(413,196),
		Point(411,194),
		Point(410,194),
		Point(408,192),
		Point(407,192),
		Point(406,191),
		Point(405,191),
		Point(404,190),
		Point(402,190),
		Point(401,189),
		Point(400,189),
		Point(398,187),
		Point(397,187),
		Point(396,186),
		Point(395,186),
		Point(394,185),
		Point(392,185),
		Point(390,183),
		Point(389,183),
		Point(388,182),
		Point(387,182),
		Point(386,181),
		Point(384,181),
		Point(383,180),
		Point(382,180),
		Point(380,178),
		Point(379,178),
		Point(378,177),
		Point(377,177),
		Point(376,176),
		Point(374,176),
		Point(372,174),
		Point(371,174),
		Point(370,173),
		Point(369,173),
		Point(368,172),
		Point(366,172),
		Point(365,171),
		Point(364,171),
		Point(363,170),
		Point(362,170),
		Point(361,169),
		Point(360,169),
		Point(359,168),
		Point(358,168),
		Point(357,167),
		Point(356,167),
		Point(354,165),
		Point(353,165),
		Point(352,164),
		Point(351,164),
		Point(350,163),
		Point(348,163),
		Point(347,162),
		Point(346,162),
		Point(345,161),
		Point(344,161),
		Point(343,160),
		Point(342,160),
		Point(341,159),
		Point(340,159),
		Point(339,158),
		Point(338,158),
		Point(336,156),
		Point(335,156),
		Point(334,155),
		Point(333,155),
		Point(332,154),
		Point(330,154),
		Point(329,153),
		Point(328,153),
		Point(327,152),
		Point(326,152),
		Point(325,151),
		Point(324,151),
		Point(323,150),
		Point(322,150),
		Point(321,149),
		Point(320,149),
		Point(319,148),
		Point(317,148),
		Point(315,146),
		Point(314,146),
		Point(313,145),
		Point(312,145),
		Point(311,144),
		Point(310,144),
		Point(309,143),
		Point(308,143),
		Point(307,142),
		Point(306,142),
		Point(305,141),
		Point(304,141),
		Point(303,140),
		Point(302,140),
		Point(301,139),
		Point(299,139),
		Point(297,137),
		Point(296,137),
		Point(295,136),
		Point(294,136),
		Point(293,135),
		Point(292,135),
		Point(291,134),
		Point(290,134),
		Point(289,133),
		Point(288,133),
		Point(287,132),
		Point(286,132),
		Point(285,131),
		Point(284,131),
		Point(283,130),
		Point(281,130),
		Point(279,128),
		Point(278,128),
		Point(277,127),
		Point(276,127),
		Point(275,126),
		Point(274,126),
		Point(273,125),
		Point(272,125),
		Point(271,124),
		Point(270,124),
		Point(269,123),
		Point(268,123),
		Point(267,122),
		Point(266,122),
		Point(265,121),
		Point(263,121),
		Point(261,119),
		Point(260,119),
		Point(259,118),
		Point(258,118),
		Point(257,117),
		Point(256,117),
		Point(255,116),
		Point(254,116),
		Point(253,115),
		Point(252,115),
		Point(251,114),
		Point(250,114),
		Point(249,113),
		Point(248,113),
		Point(247,112),
		Point(245,112),
		Point(243,110),
		Point(242,110),
		Point(241,109),
		Point(240,109),
		Point(239,108),
		Point(237,108),
		Point(235,106),
		Point(234,106),
		Point(233,105),
		Point(232,105),
		Point(231,104),
		Point(230,104),
		Point(229,103),
		Point(227,103),
		Point(225,101),
		Point(224,101),
		Point(223,100),
		Point(222,100),
		Point(221,99),
		Point(219,99),
		Point(217,97),
		Point(216,97),
		Point(215,96),
		Point(214,96),
		Point(213,95),
		Point(212,95),
		Point(211,94),
		Point(209,94),
		Point(207,92),
		Point(206,92),
		Point(205,91),
		Point(204,91),
		Point(203,90),
		Point(201,90),
		Point(199,88),
		Point(198,88),
		Point(197,87),
		Point(196,87),
		Point(195,86),
		Point(194,86),
		Point(193,85),
		Point(191,85),
		Point(189,83),
		Point(188,83),
		Point(187,82),
		Point(186,82),
		Point(185,81),
		Point(183,81),
		Point(182,80),
		Point(181,80),
		Point(179,78),
		Point(178,78),
		Point(177,77),
		Point(176,77),
		Point(175,76),
		Point(173,76),
		Point(171,74),
		Point(170,74),
		Point(169,73),
		Point(168,73),
		Point(167,72),
		Point(165,72),
		Point(164,71),
		Point(163,71),
		Point(161,69),
		Point(160,69),
		Point(159,68),
		Point(158,68),
		Point(157,67),
		Point(155,67),
		Point(153,65),
		Point(152,65),
		Point(151,64),
		Point(150,64),
		Point(149,63),
		Point(147,63),
		Point(146,62),
		Point(145,62),
		Point(143,60),
		Point(142,60),
		Point(141,59),
		Point(140,59),
		Point(139,58),
		Point(137,58),
		Point(135,56),
		Point(134,56),
		Point(133,55),
		Point(132,55),
		Point(131,54),
		Point(129,54),
		Point(128,53),
		Point(127,53),
		Point(125,51),
		Point(124,51),
		Point(123,50),
		Point(122,50),
		Point(121,49),
		Point(119,49),
		Point(117,47),
		Point(116,47),
		Point(115,46),
		Point(114,46),
		Point(113,45),
		Point(111,45),
		Point(110,44),
		Point(109,44),
		Point(107,42),
		Point(106,42),
		Point(105,41),
		Point(104,41),
		Point(103,40),
		Point(102,40),
		Point(101,39)
		}
	));
}