#include "./Animation.hpp"

float CG::Animation::fps = 30.0f;

void CG::Animation::play_animation()
{
    auto current = std::chrono::steady_clock::now();
    std::cout << ansi_code::hide_cursor;

    //TODO: create a way to exit the loop and set the cursor to the bottom right again 
    while(1) {
        std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - current;
        float dt = deltaTime.count();

        this->on_update(dt);
        this->on_render();
        
        //  move cursor to top left corner of image every frame
        std::cout << ansi_code::move_cursor(this->get_height(), this->get_width());
        current = std::chrono::steady_clock::now();
        usleep(1000 * 1000 / CG::Animation::fps);
    }
}
