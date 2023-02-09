#include "./CG_Animator.hpp"

void CG_Animator::play() {
    auto current = std::chrono::steady_clock::now();
    //  move cursor to bottom right corner of image to reset properly AND use \e[?25l to hide cursor
    std::printf("\x1b[%dC\x1b[%dB\e[?25l", m_animation->getWidth(), m_animation->getHeight());

    //TODO: create a way to exit the loop and set the cursor to the bottom right again 
    while(1) {
        //  move cursor to top left corner of image every frame
        std::printf("\x1b[%dD\x1b[%dA", m_animation->getWidth(), m_animation->getHeight());

        std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - current;
        float dt = deltaTime.count();

        m_animation->onUpdate(dt);
        m_animation->onRender();
        
        current = std::chrono::steady_clock::now();
        usleep(1000 * 1000 / FPS);
    }
}