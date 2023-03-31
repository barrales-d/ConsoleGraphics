#ifndef __BOUNCING_BALL_HPP__
#define __BOUNCING_BALL_HPP__

#include "../Color.hpp"
#include "../Image.hpp"
#include "../Animation.hpp"

#include <cstdlib>
#include <ctime>


using CG::Color;


struct v2 {
    float x;
    float y;
};
// v2 GRAVITY = { .x = 0, .y = 5.0f };
v2 GRAVITY = { .x = 0, .y = 1.2f };
class BouncingBall : public CG::Animation {

    v2 position;
    v2 velocity;
    int radius;
public:
    BouncingBall(int width, int height) : CG::Animation(width, height)
    {
        srand(time(nullptr));
        // position = v2{.x = (float)width / 2, .y = (float)height / 2};
        // velocity = v2{.x = 0.9f, .y = 2.0f};
        radius = 4;
        position = v2{
            .x = (float) (rand() % (width - radius*2) + radius),
            .y = (float) (rand() % (height - radius*2) + radius)
        };
        velocity = v2{
            .x = (float) (rand() % 3 + 1), 
            .y = (float) (rand() % 3 + 1)};
    }

    void on_update(float dt);
    void on_render();
};


void BouncingBall::on_update(float dt)
{
    position.y += velocity.y + GRAVITY.y*dt;
    position.x += velocity.x;

    if(position.y + radius >= this->get_height() - 1 || position.y - radius <= 0) {
        velocity.y *= -1;
    }
    if(position.x + radius >= this->get_width() / WIDTH_SCALER || position.x - radius <= 0) {
        velocity.x *= -1;
    }

}

void BouncingBall::on_render()
{
    this->fill_background(Color::black);
    this->fill_rect(this->get_width() / WIDTH_SCALER / 2  - 4, 
                    this->get_height() / 2 - 4,
                    8, 8, Color::red);
    this->fill_circle(position.x, position.y, radius, Color(0x45FF2084));
    // this->fill_rect(position.x, position.y, 2, 2, Color(0xCCE320FF));
    this->show();
}

#endif // __BOUNCING_BALL_HPP__