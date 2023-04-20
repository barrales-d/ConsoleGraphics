#ifndef __ANSI_H__
#define __ANSI_H__
#include "Color.h"
#include <iostream>
#include <string>

namespace ansi {
    void reset();
    void hide_cursor();
    void move_cursor(int up, int left);
    void background(CG::Color col);
    void linewrap(bool enable = false);
}

#endif //   __ANSI_H__
