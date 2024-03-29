TEST(DISABLED_isCircleTest, CircleWithEdges){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(197,48),
		Point(196,49),
		Point(193,49),
		Point(192,50),
		Point(190,50),
		Point(189,49),
		Point(182,49),
		Point(181,50),
		Point(174,50),
		Point(173,51),
		Point(169,51),
		Point(168,52),
		Point(164,52),
		Point(163,53),
		Point(160,53),
		Point(159,54),
		Point(156,54),
		Point(155,55),
		Point(152,55),
		Point(151,56),
		Point(149,56),
		Point(148,57),
		Point(146,57),
		Point(145,58),
		Point(143,58),
		Point(142,59),
		Point(140,59),
		Point(139,60),
		Point(138,60),
		Point(137,61),
		Point(135,61),
		Point(134,62),
		Point(133,62),
		Point(132,63),
		Point(131,63),
		Point(131,65),
		Point(132,66),
		Point(132,68),
		Point(133,69),
		Point(132,70),
		Point(132,71),
		Point(129,74),
		Point(128,74),
		Point(127,75),
		Point(126,75),
		Point(125,76),
		Point(124,76),
		Point(123,77),
		Point(122,77),
		Point(121,78),
		Point(120,78),
		Point(119,79),
		Point(118,79),
		Point(117,80),
		Point(116,80),
		Point(114,82),
		Point(113,82),
		Point(112,83),
		Point(111,83),
		Point(109,85),
		Point(108,85),
		Point(106,87),
		Point(105,87),
		Point(102,90),
		Point(101,90),
		Point(99,92),
		Point(98,92),
		Point(94,96),
		Point(93,96),
		Point(78,111),
		Point(77,111),
		Point(76,110),
		Point(75,110),
		Point(73,108),
		Point(69,108),
		Point(66,111),
		Point(66,112),
		Point(62,116),
		Point(62,117),
		Point(59,120),
		Point(59,121),
		Point(57,123),
		Point(57,124),
		Point(55,126),
		Point(55,127),
		Point(53,129),
		Point(53,130),
		Point(51,132),
		Point(51,133),
		Point(50,134),
		Point(50,138),
		Point(55,143),
		Point(55,144),
		Point(54,145),
		Point(54,146),
		Point(53,147),
		Point(53,148),
		Point(52,149),
		Point(52,150),
		Point(51,151),
		Point(51,152),
		Point(50,153),
		Point(50,154),
		Point(49,155),
		Point(49,156),
		Point(48,157),
		Point(48,159),
		Point(47,160),
		Point(47,161),
		Point(46,162),
		Point(46,164),
		Point(45,165),
		Point(45,166),
		Point(44,167),
		Point(44,169),
		Point(43,170),
		Point(43,172),
		Point(42,173),
		Point(42,176),
		Point(41,177),
		Point(41,179),
		Point(40,180),
		Point(40,183),
		Point(39,184),
		Point(39,187),
		Point(38,188),
		Point(38,192),
		Point(37,193),
		Point(37,195),
		Point(36,196),
		Point(35,196),
		Point(34,195),
		Point(31,195),
		Point(31,196),
		Point(29,198),
		Point(29,199),
		Point(28,200),
		Point(28,202),
		Point(27,203),
		Point(27,204),
		Point(26,205),
		Point(26,217),
		Point(25,218),
		Point(25,228),
		Point(26,229),
		Point(26,241),
		Point(27,242),
		Point(27,249),
		Point(28,250),
		Point(28,254),
		Point(29,255),
		Point(29,259),
		Point(30,260),
		Point(30,263),
		Point(31,264),
		Point(31,267),
		Point(32,268),
		Point(32,271),
		Point(33,272),
		Point(33,274),
		Point(34,275),
		Point(34,277),
		Point(35,278),
		Point(35,280),
		Point(36,281),
		Point(36,283),
		Point(37,284),
		Point(37,285),
		Point(38,286),
		Point(38,288),
		Point(39,289),
		Point(39,290),
		Point(40,291),
		Point(40,292),
		Point(41,293),
		Point(41,295),
		Point(42,296),
		Point(42,297),
		Point(43,298),
		Point(43,299),
		Point(44,300),
		Point(44,301),
		Point(45,302),
		Point(45,303),
		Point(46,304),
		Point(46,305),
		Point(47,306),
		Point(47,307),
		Point(49,309),
		Point(49,310),
		Point(50,311),
		Point(50,312),
		Point(51,313),
		Point(51,314),
		Point(53,316),
		Point(53,317),
		Point(55,319),
		Point(55,320),
		Point(57,322),
		Point(57,323),
		Point(59,325),
		Point(59,326),
		Point(62,329),
		Point(62,330),
		Point(66,334),
		Point(66,335),
		Point(72,341),
		Point(72,342),
		Point(81,351),
		Point(82,351),
		Point(88,357),
		Point(89,357),
		Point(93,361),
		Point(94,361),
		Point(97,364),
		Point(98,364),
		Point(100,366),
		Point(101,366),
		Point(103,368),
		Point(104,368),
		Point(106,370),
		Point(107,370),
		Point(109,372),
		Point(110,372),
		Point(111,373),
		Point(112,373),
		Point(113,374),
		Point(114,374),
		Point(116,376),
		Point(117,376),
		Point(118,377),
		Point(119,377),
		Point(120,378),
		Point(121,378),
		Point(122,379),
		Point(123,379),
		Point(124,380),
		Point(125,380),
		Point(126,381),
		Point(128,381),
		Point(129,382),
		Point(130,382),
		Point(131,383),
		Point(132,383),
		Point(133,384),
		Point(135,384),
		Point(136,385),
		Point(137,385),
		Point(138,386),
		Point(142,386),
		Point(142,385),
		Point(143,384),
		Point(144,384),
		Point(148,380),
		Point(152,380),
		Point(153,381),
		Point(157,381),
		Point(158,382),
		Point(160,382),
		Point(161,383),
		Point(163,383),
		Point(164,384),
		Point(167,384),
		Point(170,387),
		Point(170,392),
		Point(169,393),
		Point(169,394),
		Point(171,394),
		Point(172,395),
		Point(179,395),
		Point(180,396),
		Point(192,396),
		Point(193,397),
		Point(207,397),
		Point(208,396),
		Point(220,396),
		Point(221,395),
		Point(228,395),
		Point(229,394),
		Point(233,394),
		Point(234,393),
		Point(238,393),
		Point(239,392),
		Point(242,392),
		Point(243,391),
		Point(246,391),
		Point(247,390),
		Point(250,390),
		Point(251,389),
		Point(253,389),
		Point(254,388),
		Point(256,388),
		Point(257,387),
		Point(259,387),
		Point(260,386),
		Point(262,386),
		Point(263,385),
		Point(264,385),
		Point(265,384),
		Point(267,384),
		Point(268,383),
		Point(269,383),
		Point(270,382),
		Point(271,382),
		Point(272,381),
		Point(274,381),
		Point(275,380),
		Point(276,380),
		Point(277,379),
		Point(278,379),
		Point(279,378),
		Point(280,378),
		Point(281,377),
		Point(280,376),
		Point(280,372),
		Point(281,371),
		Point(281,370),
		Point(284,367),
		Point(285,367),
		Point(287,365),
		Point(288,365),
		Point(289,364),
		Point(290,364),
		Point(292,362),
		Point(293,362),
		Point(295,360),
		Point(296,360),
		Point(299,357),
		Point(300,357),
		Point(302,355),
		Point(303,355),
		Point(307,351),
		Point(308,351),
		Point(317,342),
		Point(317,341),
		Point(319,339),
		Point(319,335),
		Point(320,334),
		Point(320,331),
		Point(321,330),
		Point(322,330),
		Point(322,329),
		Point(323,328),
		Point(325,328),
		Point(326,327),
		Point(328,327),
		Point(330,325),
		Point(330,324),
		Point(332,322),
		Point(332,321),
		Point(337,316),
		Point(339,316),
		Point(339,315),
		Point(342,312),
		Point(342,311),
		Point(343,310),
		Point(345,310),
		Point(346,309),
		Point(350,309),
		Point(351,310),
		Point(351,309),
		Point(353,307),
		Point(353,306),
		Point(354,305),
		Point(354,304),
		Point(355,303),
		Point(355,302),
		Point(356,301),
		Point(356,300),
		Point(357,299),
		Point(357,298),
		Point(358,297),
		Point(358,295),
		Point(359,294),
		Point(359,293),
		Point(360,292),
		Point(360,291),
		Point(361,290),
		Point(361,288),
		Point(362,287),
		Point(362,286),
		Point(363,285),
		Point(363,283),
		Point(364,282),
		Point(364,280),
		Point(365,279),
		Point(365,277),
		Point(366,276),
		Point(366,274),
		Point(367,273),
		Point(367,270),
		Point(368,269),
		Point(368,266),
		Point(369,265),
		Point(369,262),
		Point(370,261),
		Point(370,257),
		Point(371,256),
		Point(371,252),
		Point(372,251),
		Point(372,244),
		Point(373,243),
		Point(373,231),
		Point(374,230),
		Point(374,216),
		Point(373,215),
		Point(373,203),
		Point(372,202),
		Point(372,195),
		Point(371,194),
		Point(371,190),
		Point(370,189),
		Point(370,185),
		Point(369,184),
		Point(369,181),
		Point(368,180),
		Point(368,177),
		Point(367,176),
		Point(367,173),
		Point(366,172),
		Point(366,170),
		Point(365,169),
		Point(365,167),
		Point(364,166),
		Point(364,164),
		Point(363,163),
		Point(363,161),
		Point(362,160),
		Point(362,159),
		Point(361,158),
		Point(361,156),
		Point(360,155),
		Point(360,154),
		Point(359,153),
		Point(359,152),
		Point(358,151),
		Point(358,149),
		Point(357,148),
		Point(357,147),
		Point(356,146),
		Point(356,145),
		Point(355,144),
		Point(355,143),
		Point(354,142),
		Point(354,141),
		Point(353,140),
		Point(353,139),
		Point(351,137),
		Point(351,136),
		Point(350,135),
		Point(350,134),
		Point(349,133),
		Point(349,132),
		Point(347,130),
		Point(347,129),
		Point(345,127),
		Point(345,126),
		Point(343,124),
		Point(343,123),
		Point(341,121),
		Point(341,120),
		Point(338,117),
		Point(338,116),
		Point(334,112),
		Point(334,111),
		Point(330,107),
		Point(327,107),
		Point(326,108),
		Point(324,108),
		Point(323,109),
		Point(321,109),
		Point(319,111),
		Point(318,111),
		Point(305,98),
		Point(305,94),
		Point(306,93),
		Point(306,90),
		Point(307,89),
		Point(306,88),
		Point(306,85),
		Point(303,82),
		Point(302,82),
		Point(300,80),
		Point(299,80),
		Point(297,78),
		Point(296,78),
		Point(294,76),
		Point(293,76),
		Point(291,74),
		Point(290,74),
		Point(289,73),
		Point(288,73),
		Point(287,72),
		Point(286,72),
		Point(284,70),
		Point(283,70),
		Point(282,69),
		Point(281,69),
		Point(280,68),
		Point(279,68),
		Point(278,67),
		Point(277,67),
		Point(276,66),
		Point(275,66),
		Point(274,65),
		Point(273,65),
		Point(272,64),
		Point(270,64),
		Point(269,63),
		Point(268,63),
		Point(267,62),
		Point(266,62),
		Point(265,61),
		Point(263,61),
		Point(262,60),
		Point(261,60),
		Point(260,59),
		Point(258,59),
		Point(257,58),
		Point(255,58),
		Point(254,57),
		Point(251,57),
		Point(250,56),
		Point(247,56),
		Point(246,55),
		Point(245,55),
		Point(244,54),
		Point(241,54),
		Point(240,53),
		Point(237,53),
		Point(236,52),
		Point(232,52),
		Point(231,51),
		Point(227,51),
		Point(226,50),
		Point(219,50),
		Point(218,49),
		Point(211,49),
		Point(210,50),
		Point(209,50),
		Point(208,49),
		Point(206,49),
		Point(205,48)
		}
	).isCircle);
}