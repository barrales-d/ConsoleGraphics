#ifndef __ANSI_CODES_H__
#define __ANSI_CODES_H__
#include "Color.h"
#include <string>

namespace Ansi {
    struct Codes {
        inline static std::string reset = "\x1b[0m";
        inline static std::string hide_cursor = "\x1b[?25l";

        static const std::string move_cursor(int up, int left);
        static const std::string background(CG::Color col);
    };
}

#endif //   __ANSI_CODES_H__
