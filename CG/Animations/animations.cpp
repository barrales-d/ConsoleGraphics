#include "Rainbow.hpp"
#include "Bouncingball.hpp"

#define WIDTH 30
#define HEIGHT 20
int main() {
    BouncingBall animation(WIDTH, HEIGHT);
    animation.play_animation();
}