//
// Created by test on 10.01.17.
//

#ifndef ORANGEBALL_HALFCIRCLE_H
#define ORANGEBALL_HALFCIRCLE_H
TEST(isCircleTest, HalfCircleImage){
    EXPECT_TRUE(crclfnd::isCircle(
            {
                    Point(278, 278),
                    Point(277, 277),
                    Point(277, 277),
                    Point(278, 278),
                    Point(280, 280),
                    Point(281, 281),
                    Point(293, 293),
                    Point(294, 294),
                    Point(300, 300),
                    Point(301, 301),
                    Point(305, 305),
                    Point(306, 306),
                    Point(310, 310),
                    Point(311, 311),
                    Point(314, 314),
                    Point(315, 315),
                    Point(318, 318),
                    Point(319, 319),
                    Point(321, 321),
                    Point(322, 322),
                    Point(325, 325),
                    Point(326, 326),
                    Point(327, 327),
                    Point(328, 328),
                    Point(330, 330),
                    Point(331, 331),
                    Point(333, 333),
                    Point(334, 334),
                    Point(335, 335),
                    Point(336, 336),
                    Point(338, 338),
                    Point(339, 339),
                    Point(340, 340),
                    Point(341, 341),
                    Point(342, 342),
                    Point(343, 343),
                    Point(344, 344),
                    Point(345, 345),
                    Point(346, 346),
                    Point(347, 347),
                    Point(348, 348),
                    Point(349, 349),
                    Point(350, 350),
                    Point(351, 351),
                    Point(352, 352),
                    Point(353, 353),
                    Point(354, 354),
                    Point(355, 355),
                    Point(356, 356),
                    Point(357, 357),
                    Point(358, 358),
                    Point(360, 360),
                    Point(361, 361),
                    Point(363, 363),
                    Point(364, 364),
                    Point(366, 366),
                    Point(367, 367),
                    Point(369, 369),
                    Point(370, 370),
                    Point(373, 373),
                    Point(374, 374),
                    Point(378, 378),
                    Point(379, 379),
                    Point(386, 386),
                    Point(387, 387),
                    Point(392, 392),
                    Point(392, 392),
                    Point(399, 399),
                    Point(399, 399),
                    Point(403, 403),
                    Point(403, 403),
                    Point(406, 406),
                    Point(406, 406),
                    Point(408, 408),
                    Point(408, 408),
                    Point(410, 410),
                    Point(410, 410),
                    Point(412, 412),
                    Point(412, 412),
                    Point(414, 414),
                    Point(414, 414),
                    Point(415, 415),
                    Point(415, 415),
                    Point(416, 416),
                    Point(416, 416),
                    Point(417, 417),
                    Point(417, 417),
                    Point(418, 418),
                    Point(418, 418),
                    Point(419, 419),
                    Point(419, 419),
                    Point(420, 420),
                    Point(420, 420),
                    Point(421, 421),
                    Point(421, 421),
                    Point(422, 422),
                    Point(422, 422),
                    Point(423, 423),
                    Point(423, 423),
                    Point(424, 424),
                    Point(424, 424),
                    Point(425, 425),
                    Point(425, 425),
                    Point(426, 426),
                    Point(426, 426),
                    Point(427, 427),
                    Point(427, 427),
                    Point(428, 428),
                    Point(428, 428),
                    Point(429, 429),
                    Point(429, 429),
                    Point(430, 430),
                    Point(430, 430),
                    Point(431, 431),
                    Point(431, 431),
                    Point(432, 432),
                    Point(432, 432),
                    Point(433, 433),
                    Point(433, 433),
                    Point(434, 434),
                    Point(434, 434),
                    Point(435, 435),
                    Point(435, 435),
                    Point(436, 436),
                    Point(436, 436),
                    Point(437, 437),
                    Point(437, 437),
                    Point(436, 436),
                    Point(436, 436),
                    Point(435, 435),
                    Point(435, 435),
                    Point(434, 434),
                    Point(434, 434),
                    Point(433, 433),
                    Point(433, 433),
                    Point(432, 432),
                    Point(432, 432),
                    Point(431, 431),
                    Point(431, 431),
                    Point(430, 430),
                    Point(430, 430),
                    Point(429, 429),
                    Point(429, 429),
                    Point(428, 428),
                    Point(428, 428),
                    Point(427, 427),
                    Point(427, 427),
                    Point(426, 426),
                    Point(426, 426),
                    Point(425, 425),
                    Point(425, 425),
                    Point(424, 424),
                    Point(424, 424),
                    Point(423, 423),
                    Point(423, 423),
                    Point(422, 422),
                    Point(422, 422),
                    Point(421, 421),
                    Point(421, 421),
                    Point(420, 420),
                    Point(420, 420),
                    Point(419, 419),
                    Point(419, 419),
                    Point(418, 418),
                    Point(418, 418),
                    Point(417, 417),
                    Point(417, 417),
                    Point(416, 416),
                    Point(416, 416),
                    Point(415, 415),
                    Point(415, 415),
                    Point(414, 414),
                    Point(414, 414),
                    Point(412, 412),
                    Point(412, 412),
                    Point(410, 410),
                    Point(410, 410),
                    Point(408, 408),
                    Point(408, 408),
                    Point(406, 406),
                    Point(406, 406),
                    Point(403, 403),
                    Point(403, 403),
                    Point(399, 399),
                    Point(399, 399),
                    Point(392, 392),
                    Point(392, 392),
                    Point(387, 387),
                    Point(386, 386),
                    Point(379, 379),
                    Point(378, 378),
                    Point(374, 374),
                    Point(373, 373),
                    Point(370, 370),
                    Point(369, 369),
                    Point(367, 367),
                    Point(366, 366),
                    Point(364, 364),
                    Point(363, 363),
                    Point(361, 361),
                    Point(360, 360),
                    Point(358, 358),
                    Point(357, 357),
                    Point(356, 356),
                    Point(355, 355),
                    Point(354, 354),
                    Point(353, 353),
                    Point(352, 352),
                    Point(351, 351),
                    Point(350, 350),
                    Point(349, 349),
                    Point(348, 348),
                    Point(347, 347),
                    Point(346, 346),
                    Point(345, 345),
                    Point(344, 344),
                    Point(343, 343),
                    Point(342, 342),
                    Point(341, 341),
                    Point(340, 340),
                    Point(339, 339),
                    Point(338, 338),
                    Point(337, 337),
                    Point(336, 336),
                    Point(334, 334),
                    Point(333, 333),
                    Point(332, 332),
                    Point(331, 331),
                    Point(329, 329),
                    Point(328, 328),
                    Point(326, 326),
                    Point(325, 325),
                    Point(324, 324),
                    Point(323, 323),
                    Point(320, 320),
                    Point(319, 319),
                    Point(317, 317),
                    Point(316, 316),
                    Point(313, 313),
                    Point(312, 312),
                    Point(309, 309),
                    Point(308, 308),
                    Point(304, 304),
                    Point(303, 303),
                    Point(299, 299),
                    Point(298, 298),
                    Point(292, 292),
                    Point(291, 291)
            }
    ));
}
#endif //ORANGEBALL_HALFCIRCLE_H
