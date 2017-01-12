TEST(isCircleTest, KeyFromKeyboardFromScreenshot){
	EXPECT_FALSE(crclfnd::isCircle(
		{
		Point(398,345),
		Point(398,346),
		Point(397,347),
		Point(398,348),
		Point(398,349),
		Point(399,350),
		Point(400,350),
		Point(401,351),
		Point(405,351),
		Point(406,352),
		Point(409,352),
		Point(410,353),
		Point(416,353),
		Point(417,354),
		Point(447,354),
		Point(448,353),
		Point(451,353),
		Point(452,352),
		Point(452,349),
		Point(449,349),
		Point(448,350),
		Point(446,350),
		Point(445,351),
		Point(419,351),
		Point(418,350),
		Point(412,350),
		Point(411,349),
		Point(408,349),
		Point(407,348),
		Point(404,348),
		Point(401,345)
		}
	).isCircle);
}