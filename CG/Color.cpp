#include "./Color.hpp"


CG::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) 
{
    color = ((a << 8 * 3) | (b << 8 * 2) | (g << 8 * 1) | (r << 8 * 0));
}

CG::Color::Color(RGBA<uint8_t> col)
{
    color = ((col.a << 8 * 3) | (col.b << 8 * 2) | (col.g << 8 * 1) | (col.r << 8 * 0));
}

CG::Color::Color(RGBA<float> col)
{
    uint8_t r = col.r * 255;
    uint8_t g = col.g * 255;
    uint8_t b = col.b * 255;
    uint8_t a = col.a * 255;
    color = ((a << 8 * 3) | (b << 8 * 2) | (g << 8 * 1) | (r << 8 * 0));
}

bool CG::Color::operator==(const CG::Color& rhs) const noexcept { return (color == rhs.color); }
bool CG::Color::operator!=(const CG::Color& rhs) const noexcept { return !(*this == rhs); }
CG::Color CG::Color::operator+(const Color& rhs) const noexcept
{
    RGBA<float> bg = this->normalized();
    RGBA<float> fg = rhs.normalized();

    float alpha = fg.a + bg.a * (1 - fg.a);
    float epsilon = 0.00000001; // both bg and fg have 0 transparency 
    if(alpha < epsilon) 
        return CG::Color();

    return CG::Color (
        (((fg.r * fg.a + bg.r * bg.a * (1 - fg.a)) / alpha) * 255),
        (((fg.g * fg.a + bg.g * bg.a * (1 - fg.a)) / alpha) * 255),
        (((fg.b * fg.a + bg.b * bg.a * (1 - fg.a)) / alpha) * 255),
        (alpha * 255)
    );    
}

const std::string ansi_code::reset = "\033[0m";
const std::string ansi_code::hide_cursor = "\x1b[?25l";

const std::string ansi_code::background(CG::Color col)
{
    CG::RGBA<uint8_t> color = col.rgba();
    return "\033[48;2;" + 
    std::to_string(color.r) + ";" + 
    std::to_string(color.g) + ";" + 
    std::to_string(color.b) + "m";
}

const std::string ansi_code::foreground(CG::Color col)
{
    CG::RGBA<uint8_t> color = col.rgba();
    return "\033[38;2;" + 
    std::to_string(color.r) + ";" + 
    std::to_string(color.g) + ";" + 
    std::to_string(color.b) + "m";
}

const std::string ansi_code::move_cursor(int up, int left)
{
    return "\x1b["+ std::to_string(left) +"D\x1b["+ std::to_string(up) +"A";
}