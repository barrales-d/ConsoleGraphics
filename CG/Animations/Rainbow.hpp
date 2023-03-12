#ifndef __COLOR_ANIMATION_HPP__
#define __COLOR_ANIMATION_HPP__

#include "../Color.hpp"
#include "../Image.hpp"
#include "../Animation.hpp"

#include <cmath>

using CG::Color;

#define PI 3.14159265359f

class Rainbow : public CG::Animation {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    float global_time;
public:
    Rainbow(int width, int height) : CG::Animation(width, height)
    {
        r = 0;
        g = 0;
        b = 0;
    }

    void on_update(float dt);
    void on_render();
};


void Rainbow::on_update(float dt)
{
    global_time += dt;
    r = (sinf(global_time) + 1) / 2 * 255;
    g = (cosf(global_time) + 1) / 2 * 255;
    b = (sinf(global_time) * PI + 1) / 2 * 255;
}

void Rainbow::on_render()
{
    this->fill_background( Color(r, g, b));
    this->show();
}

//  ************************************ IN MAIN *****************************************  //
//   Rainbow col_anime(WIDTH, HEIGHT);                                                      //
//   col_anime.play_animation();                                                              //
//  **************************************************************************************  //
#endif // __COLOR_ANIMATION_HPP__