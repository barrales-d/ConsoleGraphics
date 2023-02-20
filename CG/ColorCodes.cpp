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
const CG_Color CG_Color::lightpurple = CG_Color(255, 85, 255);
const CG_Color CG_Color::turquoise   = CG_Color(0x30D5C8);
const CG_Color CG_Color::lightwhite  = CG_Color(0xD1D1D1);

const int CG_Color::colors_count = 16;

CG_Color CG_Color::colors[CG_Color::colors_count] = {
    CG_Color::black,
    CG_Color::red,
    CG_Color::green,
    CG_Color::yellow,
    CG_Color::blue,
    CG_Color::magenta,
    CG_Color::cyan,
    CG_Color::white,
    CG_Color::darkgrey,
    CG_Color::lightred,
    CG_Color::lightgreen,
    CG_Color::lightyellow,
    CG_Color::lightblue,
    CG_Color::lightpurple,
    CG_Color::turquoise,
    CG_Color::lightwhite
};

std::string ANSICodes::Reset = "\033[0m";
