#include <gtest/gtest.h>
#include "ColorCode.h"
#include <sstream>

std::string generateExpectedOutput() {
    std::ostringstream oss;
    int totalPairs = ColorCode::majorColors.size() * ColorCode::minorColors.size();
    for (int pairNumber = 1; pairNumber <= totalPairs; ++pairNumber) {
        auto colors = ColorCode::getColorsFromPairNumber(pairNumber);
        oss << "Pair number " << pairNumber << ": " << colors.first << " - " << colors.second << std::endl;
    }
    return oss.str();
}

TEST(ColorCodeTest, testNumberToPair) {
	auto m_pairNumber{4};
	auto colors = ColorCode::getColorsFromPairNumber(m_pairNumber);
	ASSERT_EQ(colors.first, ColorCode::majorColors[0]);
	ASSERT_EQ(colors.second, ColorCode::minorColors[3]);
}

TEST(ColorCodeTest, testPairToNumber) {
	auto pairNumber = ColorCode::getPairNumberFromColors(ColorCode::majorColors[2],ColorCode::minorColors[1]);
	ASSERT_EQ(pairNumber, 12);
}

TEST(ColorCodeTest, PrintAllColorPairs) {
    std::string expectedOutput = generateExpectedOutput();
    std::string actualOutput = ColorCode::getAllColorPairs();
    EXPECT_EQ(expectedOutput, actualOutput);
}

