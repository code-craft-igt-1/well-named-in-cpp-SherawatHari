#include "ColorCode.h"
#include <sstream>

const std::vector<std::string> ColorCode::majorColors = { "White", "Red", "Black", "Yellow", "Violet" };
const std::vector<std::string> ColorCode::minorColors = { "Blue", "Orange", "Green", "Brown", "Slate" };

int ColorCode::getPairNumberFromColors(const std::string& major, const std::string& minor) {
    int majorIndex = getColorIndex(majorColors, major);
    int minorIndex = getColorIndex(minorColors, minor);

    if (majorIndex == -1 || minorIndex == -1) {
        return -1; // Invalid color
    }

    return majorIndex * minorColors.size() + minorIndex + 1;
}

std::pair<std::string, std::string> ColorCode::getColorsFromPairNumber(int pairNumber) {
    int totalPairs = majorColors.size() * minorColors.size();
    if (pairNumber < 1 || pairNumber > totalPairs) {
        return { "", "" }; // Invalid pair number
    }

    int zeroBasedPairNumber = pairNumber - 1;
    std::string major = majorColors[zeroBasedPairNumber / minorColors.size()];
    std::string minor = minorColors[zeroBasedPairNumber % minorColors.size()];

    return { major, minor };
}

std::string ColorCode::getAllColorPairs() {
    std::ostringstream oss;
    int totalPairs = majorColors.size() * minorColors.size();
    for (int pairNumber = 1; pairNumber <= totalPairs; ++pairNumber) {
        std::pair<std::string, std::string> colors = getColorsFromPairNumber(pairNumber);
        oss << "Pair number " << pairNumber << ": " << colors.first << " - " << colors.second << std::endl;
    }
    return oss.str();
}

int ColorCode::getColorIndex(const std::vector<std::string>& colors, const std::string& color) {
    for (size_t i = 0; i < colors.size(); ++i) {
        if (colors[i] == color) {
            return i;
        }
    }
    return -1;
}
