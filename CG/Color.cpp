#include "./Color.hpp"


CG::Color::Color(uint8_t r, uint8_t g, uint8_t b) 
{
    color = (0xFF000000 | (b << 8 * 2) | (g << 8 * 1) | (r << 8 * 0));
}

const int CG::Color::r() const { return ((color >> 8 * 0) & 0xFF); }
const int CG::Color::g() const { return ((color >> 8 * 1) & 0xFF); }
const int CG::Color::b() const { return ((color >> 8 * 2) & 0xFF); }

bool CG::Color::operator==(const CG::Color& rhs) const noexcept { return (color == rhs.color); }
bool CG::Color::operator!=(const CG::Color& rhs) const noexcept { return !(*this == rhs); }

const CG::Color CG::Color::black       = CG::Color(0x000000);
const CG::Color CG::Color::red         = CG::Color(0x0000FF);
const CG::Color CG::Color::green       = CG::Color(0x00FF00);
const CG::Color CG::Color::blue        = CG::Color(0xFF0000);
const CG::Color CG::Color::yellow      = CG::Color(0x00FFFF);
const CG::Color CG::Color::magenta     = CG::Color(0x9000FF);
const CG::Color CG::Color::cyan        = CG::Color(0xFFFF00);
const CG::Color CG::Color::white       = CG::Color(0xFFFFFF);
const CG::Color CG::Color::darkgrey    = CG::Color(0x474747);
const CG::Color CG::Color::lightred    = CG::Color(0x6F6FFF);
const CG::Color CG::Color::lightgreen  = CG::Color(0x90EE90);
const CG::Color CG::Color::lightyellow = CG::Color(0xE0FFFF);
const CG::Color CG::Color::lightblue   = CG::Color(0xE6D8AD);
const CG::Color CG::Color::lightpurple = CG::Color(255, 85, 255);
const CG::Color CG::Color::turquoise   = CG::Color(0xC8D530);
const CG::Color CG::Color::lightwhite  = CG::Color(0xD1D1D1);

const int CG::Color::colors_count = 16;

CG::Color CG::Color::colors[CG::Color::colors_count] = {
    CG::Color::black,
    CG::Color::red,
    CG::Color::green,
    CG::Color::yellow,
    CG::Color::blue,
    CG::Color::magenta,
    CG::Color::cyan,
    CG::Color::white,
    CG::Color::darkgrey,
    CG::Color::lightred,
    CG::Color::lightgreen,
    CG::Color::lightyellow,
    CG::Color::lightblue,
    CG::Color::lightpurple,
    CG::Color::turquoise,
    CG::Color::lightwhite
};

const std::string ansi_code::reset = "\033[0m";
const std::string ansi_code::hide_cursor = "\x1b[?25l";

const std::string ansi_code::background(CG::Color col)
{
    return "\033[48;2;" + 
    std::to_string(col.r()) + ";" + 
    std::to_string(col.g()) + ";" + 
    std::to_string(col.b()) + "m";
}

const std::string ansi_code::foreground(CG::Color col)
{
    return "\033[38;2;" + 
    std::to_string(col.r()) + ";" + 
    std::to_string(col.g()) + ";" + 
    std::to_string(col.b()) + "m";
}

const std::string ansi_code::move_cursor(int up, int left)
{
    return "\x1b["+ std::to_string(left) +"D\x1b["+ std::to_string(up) +"A";
}