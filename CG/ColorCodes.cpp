#include "ColorCodes.hpp"

CG_Color::CG_Color(const uint8_t r, const uint8_t g, const uint8_t b) {
    color = ((r << 8 * 2) | (g << 8 * 1) | (b << 8 * 0));
}

const uint8_t CG_Color::r() const { return    ((color >> 8 * 2) & 0xFF); }
const uint8_t CG_Color::g() const { return  ((color >> 8 * 1) & 0xFF); }
const uint8_t CG_Color::b() const { return   ((color >> 8 * 0) & 0xFF);}

const std::string CG_Color::to_ansi_bg() const {
    return "\033[48;2;" + 
            std::to_string(this->r()) + ";" + 
            std::to_string(this->g()) + ";" + 
            std::to_string(this->b()) + "m";
}

const std::string CG_Color::to_ansi_fg() const {
    return "\033[38;2;" + 
            std::to_string(this->r()) + ";" + 
            std::to_string(this->g()) + ";" + 
            std::to_string(this->b()) + "m";
}

bool CG_Color::operator==(const CG_Color& rhs) const noexcept {
    return (color == rhs.color);
}
bool CG_Color::operator!=(const CG_Color& rhs) const noexcept {
    return !(*this == rhs);
}


const CG_Color CG_Color::black       = CG_Color(0x000000);
const CG_Color CG_Color::red         = CG_Color(0xFF0000);
const CG_Color CG_Color::green       = CG_Color(0x00FF00);
const CG_Color CG_Color::yellow      = CG_Color(0xFFFF00);
const CG_Color CG_Color::blue        = CG_Color(0x0000FF);
const CG_Color CG_Color::magenta     = CG_Color(0xFF0090);
const CG_Color CG_Color::cyan        = CG_Color(0x00FFFF);
const CG_Color CG_Color::white       = CG_Color(0xFFFFFF);
const CG_Color CG_Color::darkgrey    = CG_Color(0x474747);
const CG_Color CG_Color::lightred    = CG_Color(0xFF6F6F);
const CG_Color CG_Color::lightgreen  = CG_Color(0x90EE90);
const CG_Color CG_Color::lightyellow = CG_Color(0xFFFFE0);
const CG_Color CG_Color::lightblue   = CG_Color(0xADD8E6);
const CG_Color CG_Color::lightpurple = CG_Color(0xCBC3E3);
const CG_Color CG_Color::turquoise   = CG_Color(0x30D5C8);
const CG_Color CG_Color::lightwhite  = CG_Color(0xD1D1D1);


std::string ColorCodes::Reset = "\033[0m";

std::string ColorCodes::fg_Black = "\033[30m";
std::string ColorCodes::fg_Red = "\033[31m";
std::string ColorCodes::fg_Green = "\033[32m";
std::string ColorCodes::fg_Yellow = "\033[33m";
std::string ColorCodes::fg_Blue = "\033[34m";
std::string ColorCodes::fg_Magenta = "\033[35m";
std::string ColorCodes::fg_Cyan = "\033[36m";
std::string ColorCodes::fg_White = "\033[37m";

std::string ColorCodes::bg_Black = "\033[40m";
std::string ColorCodes::bg_Red = "\033[41m";
std::string ColorCodes::bg_Green = "\033[42m";
std::string ColorCodes::bg_Yellow = "\033[43m";
std::string ColorCodes::bg_Blue = "\033[44m";
std::string ColorCodes::bg_Magenta = "\033[45m";
std::string ColorCodes::bg_Cyan = "\033[46m";
std::string ColorCodes::bg_White = "\033[47m";

std::string ColorCodes::fg_DarkGrey = "\033[90m";
std::string ColorCodes::fg_LightRed = "\033[91m";
std::string ColorCodes::fg_LightGreen = "\033[92m";
std::string ColorCodes::fg_LightYellow = "\033[93m";
std::string ColorCodes::fg_LightBlue = "\033[94m";
std::string ColorCodes::fg_LightPurple = "\033[95m";
std::string ColorCodes::fg_Turquoise = "\033[96m";
std::string ColorCodes::fg_LightWhite = "\033[97m";

std::string ColorCodes::bg_DarkGrey = "\033[100m";
std::string ColorCodes::bg_LightRed = "\033[101m";
std::string ColorCodes::bg_LightGreen = "\033[102m";
std::string ColorCodes::bg_LightYellow = "\033[103m";
std::string ColorCodes::bg_LightBlue = "\033[104m";
std::string ColorCodes::bg_LightPurple = "\033[105m";
std::string ColorCodes::bg_Turquoise = "\033[106m";
std::string ColorCodes::bg_LightWhite = "\033[107m";