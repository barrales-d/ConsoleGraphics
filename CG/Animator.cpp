#include "./Animator.hpp"

float CG::Animator::fps = 30.0f;

void CG::Animator::play_animation(int width, int height) {
    auto current = std::chrono::steady_clock::now();
    //  Use \e[?25l to hide cursor
    std::printf("\x1b[?25l");
    // std::printf("\x1b\e[?25l");

    //TODO: create a way to exit the loop and set the cursor to the bottom right again 
    while(1) {

        std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - current;
        float dt = deltaTime.count();

        m_animation->on_update(dt);
        m_animation->on_render();
        
        //  move cursor to top left corner of image every frame
        std::printf("\x1b[%dD\x1b[%dA", width, height);
        current = std::chrono::steady_clock::now();
        usleep(1000 * 1000 / CG::Animator::fps);
    }
}