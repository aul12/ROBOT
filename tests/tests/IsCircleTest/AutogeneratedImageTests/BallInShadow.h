TEST(isCircleTest, BallInShadow){
	EXPECT_TRUE(crclfnd::isCircle(
		{
		Point(582,142),
		Point(581,143),
		Point(578,143),
		Point(577,144),
		Point(575,144),
		Point(574,145),
		Point(573,145),
		Point(572,146),
		Point(571,146),
		Point(570,147),
		Point(569,147),
		Point(567,149),
		Point(566,149),
		Point(561,154),
		Point(561,155),
		Point(559,157),
		Point(559,158),
		Point(558,159),
		Point(558,160),
		Point(557,161),
		Point(557,163),
		Point(556,164),
		Point(556,167),
		Point(555,168),
		Point(555,179),
		Point(556,180),
		Point(556,182),
		Point(557,183),
		Point(557,184),
		Point(558,185),
		Point(558,186),
		Point(559,187),
		Point(559,188),
		Point(560,189),
		Point(560,190),
		Point(563,193),
		Point(563,194),
		Point(566,197),
		Point(567,197),
		Point(570,200),
		Point(572,200),
		Point(573,201),
		Point(575,201),
		Point(576,202),
		Point(578,202),
		Point(579,203),
		Point(595,203),
		Point(596,202),
		Point(598,202),
		Point(599,201),
		Point(601,201),
		Point(602,200),
		Point(604,200),
		Point(605,199),
		Point(606,199),
		Point(608,197),
		Point(609,197),
		Point(613,193),
		Point(613,192),
		Point(616,189),
		Point(616,188),
		Point(617,187),
		Point(617,185),
		Point(618,184),
		Point(618,182),
		Point(619,181),
		Point(619,178),
		Point(620,177),
		Point(620,167),
		Point(619,166),
		Point(619,164),
		Point(618,163),
		Point(618,161),
		Point(617,160),
		Point(617,158),
		Point(616,157),
		Point(616,156),
		Point(614,154),
		Point(614,153),
		Point(611,150),
		Point(610,150),
		Point(607,147),
		Point(606,147),
		Point(605,146),
		Point(604,146),
		Point(603,145),
		Point(602,145),
		Point(601,144),
		Point(599,144),
		Point(598,143),
		Point(595,143),
		Point(594,142)
		}
	).isCircle);
}