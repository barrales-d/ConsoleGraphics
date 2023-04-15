#ifndef __ANSI_CODES_H__
#define __ANSI_CODES_H__
#include "Color.h"
#include <iostream>
#include <string>

namespace ansi_codes {
    void reset();
    void hide_cursor();
    void move_cursor(int up, int left);
    void background(CG::Color col);
}

#endif //   __ANSI_CODES_H__
