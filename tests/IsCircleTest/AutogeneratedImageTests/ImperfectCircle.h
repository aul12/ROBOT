TEST_TRUE(isCircleTest, ImperfectCircle){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(266,67),
		Point(265,68),
		Point(263,68),
		Point(262,69),
		Point(261,69),
		Point(260,68),
		Point(253,68),
		Point(252,69),
		Point(246,69),
		Point(245,70),
		Point(241,70),
		Point(240,71),
		Point(237,71),
		Point(236,72),
		Point(233,72),
		Point(232,73),
		Point(229,73),
		Point(228,74),
		Point(226,74),
		Point(225,75),
		Point(223,75),
		Point(222,76),
		Point(220,76),
		Point(219,77),
		Point(218,77),
		Point(217,78),
		Point(215,78),
		Point(214,79),
		Point(212,79),
		Point(211,80),
		Point(210,80),
		Point(209,81),
		Point(208,81),
		Point(207,82),
		Point(206,82),
		Point(205,83),
		Point(204,83),
		Point(203,84),
		Point(202,84),
		Point(201,85),
		Point(200,85),
		Point(199,86),
		Point(198,86),
		Point(197,87),
		Point(196,87),
		Point(195,88),
		Point(194,88),
		Point(192,90),
		Point(191,90),
		Point(190,91),
		Point(189,91),
		Point(187,93),
		Point(186,93),
		Point(184,95),
		Point(183,95),
		Point(180,98),
		Point(179,98),
		Point(176,101),
		Point(175,101),
		Point(169,107),
		Point(168,107),
		Point(159,116),
		Point(159,117),
		Point(153,123),
		Point(153,124),
		Point(143,134),
		Point(143,135),
		Point(137,141),
		Point(137,142),
		Point(134,145),
		Point(134,146),
		Point(131,149),
		Point(131,150),
		Point(129,152),
		Point(129,153),
		Point(127,155),
		Point(127,156),
		Point(126,157),
		Point(126,158),
		Point(124,160),
		Point(124,161),
		Point(123,162),
		Point(123,163),
		Point(122,164),
		Point(122,165),
		Point(121,166),
		Point(121,167),
		Point(120,168),
		Point(120,169),
		Point(119,170),
		Point(119,171),
		Point(118,172),
		Point(118,173),
		Point(117,174),
		Point(117,175),
		Point(116,176),
		Point(116,177),
		Point(115,178),
		Point(115,180),
		Point(114,181),
		Point(114,182),
		Point(113,183),
		Point(113,185),
		Point(112,186),
		Point(112,188),
		Point(111,189),
		Point(111,191),
		Point(110,192),
		Point(110,194),
		Point(109,195),
		Point(109,198),
		Point(108,199),
		Point(108,202),
		Point(107,203),
		Point(107,206),
		Point(106,207),
		Point(106,211),
		Point(105,212),
		Point(105,218),
		Point(104,219),
		Point(104,230),
		Point(103,231),
		Point(103,241),
		Point(104,242),
		Point(104,253),
		Point(105,254),
		Point(105,260),
		Point(106,261),
		Point(106,265),
		Point(107,266),
		Point(107,269),
		Point(108,270),
		Point(108,273),
		Point(109,274),
		Point(109,277),
		Point(110,278),
		Point(110,280),
		Point(111,281),
		Point(111,283),
		Point(112,284),
		Point(112,286),
		Point(113,287),
		Point(113,289),
		Point(114,290),
		Point(114,293),
		Point(115,294),
		Point(115,297),
		Point(116,298),
		Point(116,301),
		Point(117,302),
		Point(117,305),
		Point(118,306),
		Point(118,308),
		Point(119,309),
		Point(119,311),
		Point(120,312),
		Point(120,314),
		Point(121,315),
		Point(121,317),
		Point(122,318),
		Point(122,319),
		Point(123,320),
		Point(123,322),
		Point(124,323),
		Point(124,324),
		Point(125,325),
		Point(125,326),
		Point(126,327),
		Point(126,328),
		Point(127,329),
		Point(127,330),
		Point(128,331),
		Point(128,332),
		Point(129,333),
		Point(129,334),
		Point(130,335),
		Point(130,336),
		Point(131,337),
		Point(131,338),
		Point(132,339),
		Point(132,340),
		Point(134,342),
		Point(134,343),
		Point(135,344),
		Point(135,345),
		Point(137,347),
		Point(137,348),
		Point(139,350),
		Point(139,351),
		Point(142,354),
		Point(142,355),
		Point(145,358),
		Point(145,359),
		Point(151,365),
		Point(151,366),
		Point(160,375),
		Point(161,375),
		Point(167,381),
		Point(168,381),
		Point(171,384),
		Point(172,384),
		Point(175,387),
		Point(176,387),
		Point(178,389),
		Point(179,389),
		Point(181,391),
		Point(182,391),
		Point(183,392),
		Point(184,392),
		Point(186,394),
		Point(187,394),
		Point(188,395),
		Point(189,395),
		Point(190,396),
		Point(191,396),
		Point(192,397),
		Point(193,397),
		Point(194,398),
		Point(195,398),
		Point(196,399),
		Point(197,399),
		Point(198,400),
		Point(199,400),
		Point(200,401),
		Point(201,401),
		Point(202,402),
		Point(204,402),
		Point(205,403),
		Point(206,403),
		Point(207,404),
		Point(209,404),
		Point(210,405),
		Point(212,405),
		Point(213,406),
		Point(215,406),
		Point(216,407),
		Point(218,407),
		Point(219,408),
		Point(222,408),
		Point(223,409),
		Point(226,409),
		Point(227,410),
		Point(230,410),
		Point(231,411),
		Point(235,411),
		Point(236,412),
		Point(242,412),
		Point(243,413),
		Point(254,413),
		Point(255,414),
		Point(269,414),
		Point(270,413),
		Point(281,413),
		Point(282,412),
		Point(288,412),
		Point(289,411),
		Point(293,411),
		Point(294,410),
		Point(297,410),
		Point(298,409),
		Point(301,409),
		Point(302,408),
		Point(305,408),
		Point(306,407),
		Point(308,407),
		Point(309,406),
		Point(311,406),
		Point(312,405),
		Point(314,405),
		Point(315,404),
		Point(317,404),
		Point(318,403),
		Point(319,403),
		Point(320,402),
		Point(322,402),
		Point(323,401),
		Point(324,401),
		Point(325,400),
		Point(326,400),
		Point(327,399),
		Point(328,399),
		Point(329,398),
		Point(330,398),
		Point(331,397),
		Point(332,397),
		Point(333,396),
		Point(335,396),
		Point(336,395),
		Point(338,395),
		Point(339,394),
		Point(340,394),
		Point(341,393),
		Point(343,393),
		Point(344,392),
		Point(345,392),
		Point(346,391),
		Point(347,391),
		Point(348,390),
		Point(349,390),
		Point(350,389),
		Point(351,389),
		Point(352,388),
		Point(353,388),
		Point(354,387),
		Point(355,387),
		Point(356,386),
		Point(357,386),
		Point(358,385),
		Point(359,385),
		Point(361,383),
		Point(362,383),
		Point(363,382),
		Point(364,382),
		Point(366,380),
		Point(367,380),
		Point(369,378),
		Point(370,378),
		Point(373,375),
		Point(374,375),
		Point(377,372),
		Point(378,372),
		Point(384,366),
		Point(385,366),
		Point(394,357),
		Point(394,356),
		Point(400,350),
		Point(400,349),
		Point(403,346),
		Point(403,345),
		Point(406,342),
		Point(406,341),
		Point(408,339),
		Point(408,338),
		Point(410,336),
		Point(410,335),
		Point(411,334),
		Point(411,333),
		Point(413,331),
		Point(413,330),
		Point(414,329),
		Point(414,328),
		Point(415,327),
		Point(415,326),
		Point(416,325),
		Point(416,324),
		Point(417,323),
		Point(417,322),
		Point(418,321),
		Point(418,320),
		Point(419,319),
		Point(419,318),
		Point(420,317),
		Point(420,316),
		Point(421,315),
		Point(421,313),
		Point(422,312),
		Point(422,311),
		Point(423,310),
		Point(423,308),
		Point(424,307),
		Point(424,305),
		Point(425,304),
		Point(425,302),
		Point(426,301),
		Point(426,299),
		Point(427,298),
		Point(427,295),
		Point(428,294),
		Point(428,291),
		Point(429,290),
		Point(429,287),
		Point(430,286),
		Point(430,283),
		Point(431,282),
		Point(431,279),
		Point(432,278),
		Point(432,275),
		Point(433,274),
		Point(433,271),
		Point(434,270),
		Point(434,266),
		Point(435,265),
		Point(435,259),
		Point(436,258),
		Point(436,247),
		Point(437,246),
		Point(437,232),
		Point(436,231),
		Point(436,220),
		Point(435,219),
		Point(435,213),
		Point(434,212),
		Point(434,208),
		Point(433,207),
		Point(433,204),
		Point(432,203),
		Point(432,200),
		Point(431,199),
		Point(431,196),
		Point(430,195),
		Point(430,193),
		Point(429,192),
		Point(429,190),
		Point(428,189),
		Point(428,187),
		Point(427,186),
		Point(427,184),
		Point(426,183),
		Point(426,182),
		Point(425,181),
		Point(425,179),
		Point(424,178),
		Point(424,177),
		Point(423,176),
		Point(423,175),
		Point(422,174),
		Point(422,173),
		Point(421,172),
		Point(421,171),
		Point(420,170),
		Point(420,169),
		Point(419,168),
		Point(419,167),
		Point(418,166),
		Point(418,165),
		Point(417,164),
		Point(417,163),
		Point(415,161),
		Point(415,160),
		Point(414,159),
		Point(414,158),
		Point(412,156),
		Point(412,155),
		Point(410,153),
		Point(410,152),
		Point(407,149),
		Point(407,148),
		Point(404,145),
		Point(404,144),
		Point(398,138),
		Point(398,137),
		Point(393,132),
		Point(393,131),
		Point(390,128),
		Point(390,127),
		Point(387,124),
		Point(387,123),
		Point(381,117),
		Point(381,116),
		Point(372,107),
		Point(371,107),
		Point(365,101),
		Point(364,101),
		Point(361,98),
		Point(360,98),
		Point(357,95),
		Point(356,95),
		Point(354,93),
		Point(353,93),
		Point(351,91),
		Point(350,91),
		Point(349,90),
		Point(348,90),
		Point(346,88),
		Point(345,88),
		Point(344,87),
		Point(343,87),
		Point(342,86),
		Point(341,86),
		Point(340,85),
		Point(339,85),
		Point(338,84),
		Point(337,84),
		Point(336,83),
		Point(335,83),
		Point(334,82),
		Point(333,82),
		Point(332,81),
		Point(331,81),
		Point(330,80),
		Point(329,80),
		Point(328,79),
		Point(326,79),
		Point(325,78),
		Point(324,78),
		Point(323,77),
		Point(321,77),
		Point(320,76),
		Point(318,76),
		Point(317,75),
		Point(315,75),
		Point(314,74),
		Point(312,74),
		Point(311,73),
		Point(306,73),
		Point(305,72),
		Point(304,72),
		Point(303,71),
		Point(300,71),
		Point(299,70),
		Point(298,71),
		Point(297,71),
		Point(296,70),
		Point(295,70),
		Point(294,69),
		Point(288,69),
		Point(287,68),
		Point(276,68),
		Point(275,67),
		Point(274,67),
		Point(273,68),
		Point(271,68),
		Point(270,67)
		}
	).isCircle);
}