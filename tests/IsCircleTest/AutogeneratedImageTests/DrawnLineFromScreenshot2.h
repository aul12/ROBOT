TEST_TRUE(isCircleTest, DrawnLineFromScreenshot2){
	EXPECT_FALSE(crclfnd::isCircle(
		{
		Point(20,127),
		Point(19,128),
		Point(18,128),
		Point(18,131),
		Point(19,131),
		Point(20,132),
		Point(22,132),
		Point(23,133),
		Point(24,133),
		Point(28,137),
		Point(29,137),
		Point(30,138),
		Point(31,138),
		Point(32,139),
		Point(33,139),
		Point(34,140),
		Point(35,140),
		Point(36,141),
		Point(37,141),
		Point(40,144),
		Point(41,144),
		Point(42,145),
		Point(43,145),
		Point(44,146),
		Point(45,146),
		Point(48,149),
		Point(49,149),
		Point(50,150),
		Point(51,150),
		Point(52,151),
		Point(53,151),
		Point(55,153),
		Point(56,153),
		Point(57,154),
		Point(58,154),
		Point(59,155),
		Point(60,155),
		Point(62,157),
		Point(63,157),
		Point(65,159),
		Point(66,159),
		Point(67,160),
		Point(68,160),
		Point(70,162),
		Point(71,162),
		Point(72,163),
		Point(73,163),
		Point(75,165),
		Point(76,165),
		Point(77,166),
		Point(78,166),
		Point(80,168),
		Point(81,168),
		Point(83,170),
		Point(84,170),
		Point(87,173),
		Point(88,173),
		Point(89,174),
		Point(90,174),
		Point(95,179),
		Point(96,179),
		Point(106,189),
		Point(106,190),
		Point(111,195),
		Point(111,196),
		Point(116,201),
		Point(116,202),
		Point(117,203),
		Point(117,205),
		Point(118,206),
		Point(118,207),
		Point(121,210),
		Point(121,211),
		Point(126,216),
		Point(126,217),
		Point(127,218),
		Point(127,219),
		Point(128,220),
		Point(128,221),
		Point(130,223),
		Point(133,223),
		Point(133,220),
		Point(131,218),
		Point(131,217),
		Point(130,216),
		Point(130,215),
		Point(128,213),
		Point(128,211),
		Point(123,206),
		Point(123,205),
		Point(120,202),
		Point(120,200),
		Point(118,198),
		Point(118,196),
		Point(113,191),
		Point(113,190),
		Point(108,185),
		Point(108,184),
		Point(101,177),
		Point(100,177),
		Point(95,172),
		Point(94,172),
		Point(93,171),
		Point(92,171),
		Point(89,168),
		Point(88,168),
		Point(86,166),
		Point(85,166),
		Point(83,164),
		Point(82,164),
		Point(81,163),
		Point(80,163),
		Point(78,161),
		Point(77,161),
		Point(76,160),
		Point(75,160),
		Point(74,159),
		Point(73,159),
		Point(71,157),
		Point(70,157),
		Point(68,155),
		Point(67,155),
		Point(65,153),
		Point(64,153),
		Point(63,152),
		Point(62,152),
		Point(61,151),
		Point(60,151),
		Point(58,149),
		Point(57,149),
		Point(56,148),
		Point(55,148),
		Point(54,147),
		Point(53,147),
		Point(51,145),
		Point(50,145),
		Point(48,143),
		Point(47,143),
		Point(46,142),
		Point(45,142),
		Point(43,140),
		Point(42,140),
		Point(41,139),
		Point(40,139),
		Point(38,137),
		Point(37,137),
		Point(36,136),
		Point(35,136),
		Point(34,135),
		Point(33,135),
		Point(29,131),
		Point(28,131),
		Point(27,130),
		Point(26,130),
		Point(25,129),
		Point(23,129),
		Point(22,128),
		Point(21,128)
		}
	).isCircle);
}