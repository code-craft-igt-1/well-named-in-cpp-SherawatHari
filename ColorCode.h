#ifndef COLORCODE_H
#define COLORCODE_H

#include <string>
#include <vector>

class ColorCode {
public:
    static const std::vector<std::string> majorColors;
    static const std::vector<std::string> minorColors;

    static int getPairNumberFromColors(const std::string& major, const std::string& minor);
    static std::pair<std::string, std::string> getColorsFromPairNumber(int pairNumber);
    static std::string getAllColorPairs();

private:
    static int getColorIndex(const std::vector<std::string>& colors, const std::string& color);
};

#endif // COLORCODE_H
