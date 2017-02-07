TEST(DISABLED_isCircleTest, CircleWithLine){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(300,63),
		Point(299,64),
		Point(292,64),
		Point(291,65),
		Point(286,65),
		Point(285,66),
		Point(281,66),
		Point(280,67),
		Point(277,67),
		Point(276,68),
		Point(273,68),
		Point(272,69),
		Point(270,69),
		Point(269,70),
		Point(267,70),
		Point(266,71),
		Point(264,71),
		Point(263,72),
		Point(261,72),
		Point(260,73),
		Point(259,73),
		Point(258,74),
		Point(256,74),
		Point(255,75),
		Point(254,75),
		Point(253,76),
		Point(251,76),
		Point(250,77),
		Point(249,77),
		Point(248,78),
		Point(247,78),
		Point(246,79),
		Point(245,79),
		Point(244,80),
		Point(243,80),
		Point(241,82),
		Point(240,82),
		Point(239,83),
		Point(238,83),
		Point(237,84),
		Point(236,84),
		Point(234,86),
		Point(233,86),
		Point(231,88),
		Point(230,88),
		Point(228,90),
		Point(227,90),
		Point(223,94),
		Point(222,94),
		Point(218,98),
		Point(217,98),
		Point(205,110),
		Point(205,111),
		Point(201,115),
		Point(201,116),
		Point(197,120),
		Point(197,121),
		Point(195,123),
		Point(195,124),
		Point(193,126),
		Point(193,127),
		Point(191,129),
		Point(191,130),
		Point(190,131),
		Point(190,132),
		Point(189,133),
		Point(189,134),
		Point(187,136),
		Point(187,137),
		Point(186,138),
		Point(186,139),
		Point(185,140),
		Point(185,141),
		Point(184,142),
		Point(184,143),
		Point(183,144),
		Point(183,146),
		Point(182,147),
		Point(182,148),
		Point(181,149),
		Point(181,151),
		Point(180,152),
		Point(180,153),
		Point(179,154),
		Point(179,156),
		Point(178,157),
		Point(178,159),
		Point(177,160),
		Point(177,162),
		Point(176,163),
		Point(176,165),
		Point(175,166),
		Point(175,169),
		Point(174,170),
		Point(174,174),
		Point(173,175),
		Point(173,179),
		Point(172,180),
		Point(172,184),
		Point(171,185),
		Point(171,192),
		Point(170,193),
		Point(170,213),
		Point(171,214),
		Point(171,221),
		Point(172,222),
		Point(172,227),
		Point(173,228),
		Point(173,232),
		Point(174,233),
		Point(174,236),
		Point(175,237),
		Point(175,240),
		Point(176,241),
		Point(176,244),
		Point(177,245),
		Point(177,247),
		Point(178,248),
		Point(178,250),
		Point(179,251),
		Point(179,253),
		Point(180,254),
		Point(180,255),
		Point(181,256),
		Point(181,258),
		Point(182,259),
		Point(182,260),
		Point(183,261),
		Point(183,263),
		Point(185,265),
		Point(185,266),
		Point(186,267),
		Point(186,268),
		Point(187,269),
		Point(187,270),
		Point(188,271),
		Point(188,272),
		Point(190,274),
		Point(190,275),
		Point(191,276),
		Point(191,277),
		Point(193,279),
		Point(193,280),
		Point(195,282),
		Point(195,283),
		Point(197,285),
		Point(197,286),
		Point(201,290),
		Point(201,291),
		Point(205,295),
		Point(205,296),
		Point(218,309),
		Point(219,309),
		Point(222,312),
		Point(223,312),
		Point(224,313),
		Point(224,314),
		Point(223,315),
		Point(221,315),
		Point(220,314),
		Point(101,314),
		Point(100,315),
		Point(98,315),
		Point(98,317),
		Point(97,318),
		Point(97,341),
		Point(98,342),
		Point(98,344),
		Point(530,344),
		Point(530,315),
		Point(528,315),
		Point(527,314),
		Point(400,314),
		Point(399,315),
		Point(397,315),
		Point(396,314),
		Point(396,313),
		Point(397,312),
		Point(398,312),
		Point(401,309),
		Point(402,309),
		Point(416,295),
		Point(416,294),
		Point(420,290),
		Point(420,289),
		Point(424,285),
		Point(424,284),
		Point(426,282),
		Point(426,281),
		Point(428,279),
		Point(428,278),
		Point(429,277),
		Point(429,276),
		Point(431,274),
		Point(431,273),
		Point(432,272),
		Point(432,271),
		Point(433,270),
		Point(433,269),
		Point(435,267),
		Point(435,266),
		Point(436,265),
		Point(436,264),
		Point(437,263),
		Point(437,261),
		Point(438,260),
		Point(438,259),
		Point(439,258),
		Point(439,256),
		Point(440,255),
		Point(440,254),
		Point(441,253),
		Point(441,251),
		Point(442,250),
		Point(442,248),
		Point(443,247),
		Point(443,245),
		Point(444,244),
		Point(444,241),
		Point(445,240),
		Point(445,237),
		Point(446,236),
		Point(446,233),
		Point(447,232),
		Point(447,228),
		Point(448,227),
		Point(448,220),
		Point(449,219),
		Point(449,187),
		Point(448,186),
		Point(448,180),
		Point(447,179),
		Point(447,175),
		Point(446,174),
		Point(446,170),
		Point(445,169),
		Point(445,166),
		Point(444,165),
		Point(444,163),
		Point(443,162),
		Point(443,160),
		Point(442,159),
		Point(442,157),
		Point(441,156),
		Point(441,154),
		Point(440,153),
		Point(440,152),
		Point(439,151),
		Point(439,149),
		Point(438,148),
		Point(438,147),
		Point(437,146),
		Point(437,144),
		Point(436,143),
		Point(436,142),
		Point(435,141),
		Point(435,140),
		Point(434,139),
		Point(434,138),
		Point(433,137),
		Point(433,136),
		Point(432,135),
		Point(432,134),
		Point(430,132),
		Point(430,131),
		Point(429,130),
		Point(429,129),
		Point(427,127),
		Point(427,126),
		Point(425,124),
		Point(425,123),
		Point(423,121),
		Point(423,120),
		Point(419,116),
		Point(419,115),
		Point(415,111),
		Point(415,110),
		Point(403,98),
		Point(402,98),
		Point(398,94),
		Point(397,94),
		Point(393,90),
		Point(392,90),
		Point(390,88),
		Point(389,88),
		Point(387,86),
		Point(386,86),
		Point(384,84),
		Point(383,84),
		Point(382,83),
		Point(381,83),
		Point(379,81),
		Point(378,81),
		Point(377,80),
		Point(376,80),
		Point(375,79),
		Point(374,79),
		Point(373,78),
		Point(372,78),
		Point(371,77),
		Point(370,77),
		Point(369,76),
		Point(368,76),
		Point(367,75),
		Point(365,75),
		Point(364,74),
		Point(363,74),
		Point(362,73),
		Point(360,73),
		Point(359,72),
		Point(358,72),
		Point(357,71),
		Point(355,71),
		Point(354,70),
		Point(352,70),
		Point(351,69),
		Point(348,69),
		Point(347,68),
		Point(344,68),
		Point(343,67),
		Point(340,67),
		Point(339,66),
		Point(335,66),
		Point(334,65),
		Point(329,65),
		Point(328,64),
		Point(321,64),
		Point(320,63)
		}
	).isCircle);
}