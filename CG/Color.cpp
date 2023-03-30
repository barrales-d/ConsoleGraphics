#include "./Color.hpp"


CG::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) 
{
    color = ((a << 8 * 3) | (b << 8 * 2) | (g << 8 * 1) | (r << 8 * 0));
}

const uint8_t CG::Color::r() const { return ((color >> 8 * 0) & 0xFF); }
const uint8_t CG::Color::g() const { return ((color >> 8 * 1) & 0xFF); }
const uint8_t CG::Color::b() const { return ((color >> 8 * 2) & 0xFF); }
const uint8_t CG::Color::a() const { return ((color >> 8 * 3) & 0xFF); }

const float CG::Color::normalized_r() const { return this->r() / 255.0f; }
const float CG::Color::normalized_g() const { return this->g() / 255.0f; }
const float CG::Color::normalized_b() const { return this->b() / 255.0f; }
const float CG::Color::normalized_a() const { return this->a() / 255.0f; }

bool CG::Color::operator==(const CG::Color& rhs) const noexcept { return (color == rhs.color); }
bool CG::Color::operator!=(const CG::Color& rhs) const noexcept { return !(*this == rhs); }
CG::Color CG::Color::operator+(const Color& rhs) const noexcept
{
    float rf =  rhs.normalized_r();
    float rb =  this->normalized_r();
    float gf =  rhs.normalized_g();
    float gb =  this->normalized_g();
    float bf =  rhs.normalized_b();
    float bb =  this->normalized_b();
    float af =  rhs.normalized_a();
    float ab =  this->normalized_a();

    float alpha = af + ab * (1 - af);
    float epsilon = 0.00000001; // both bg and fg have 0 transparency 
    if(alpha < epsilon) 
        return CG::Color();
    
    return CG::Color (
        (((rf * af + rb * ab * (1 - af)) / alpha) * 255),
        (((gf * af + gb * ab * (1 - af)) / alpha) * 255),
        (((bf * af + bb * ab * (1 - af)) / alpha) * 255),
        (alpha * 255)
    );    
}

const CG::Color CG::Color::black       = CG::Color(0xFF000000);
const CG::Color CG::Color::red         = CG::Color(0xFF0000FF);
const CG::Color CG::Color::green       = CG::Color(0xFF00FF00);
const CG::Color CG::Color::blue        = CG::Color(0xFFFF0000);
const CG::Color CG::Color::yellow      = CG::Color(0xFF00FFFF);
const CG::Color CG::Color::magenta     = CG::Color(0xFF9000FF);
const CG::Color CG::Color::cyan        = CG::Color(0xFFFFFF00);
const CG::Color CG::Color::white       = CG::Color(0xFFFFFFFF);
const CG::Color CG::Color::darkgrey    = CG::Color(0xFF474747);
const CG::Color CG::Color::lightred    = CG::Color(0xFF6F6FFF);
const CG::Color CG::Color::lightgreen  = CG::Color(0xFF90EE90);
const CG::Color CG::Color::lightyellow = CG::Color(0xFFE0FFFF);
const CG::Color CG::Color::lightblue   = CG::Color(0xFFE6D8AD);
const CG::Color CG::Color::lightpurple = CG::Color(255, 85, 255);
const CG::Color CG::Color::turquoise   = CG::Color(0xFFC8D530);
const CG::Color CG::Color::lightwhite  = CG::Color(0xFFD1D1D1);

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