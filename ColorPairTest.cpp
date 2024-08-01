#include "ColorPair.h"
#include "gtest/gtest.h"

TEST(ColorPair, testNumberToPair) {
	auto m_pairNumber{4};
	TelCoColorCoder::ColorPair col(TelCoColorCoder::WHITE, TelCoColorCoder::BROWN);
	TelCoColorCoder::ColorPair colorPair = col.GetColorFromPairNumber(m_pairNumber);
	std::cout << "Got pair " << col.ToString() << std::endl;
	ASSERT_EQ(col.getMajor(), TelCoColorCoder::WHITE);
	ASSERT_EQ(col.getMinor(), TelCoColorCoder::BROWN);
}

TEST(ColorPair, testPairToNumber) {
	auto m_expectedPairNumber{12};
	TelCoColorCoder::ColorPair col(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE);
	int pairNumber = col.GetPairNumberFromColor();
	std::cout << "Got pair number " << pairNumber << std::endl;
	ASSERT_EQ(pairNumber, m_expectedPairNumber);
}

