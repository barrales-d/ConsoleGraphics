#include "./CG_Animator.hpp"

void CG_Animator::play() {
    auto current = std::chrono::steady_clock::now();
    while(1) {
        //TODO: figure out delta time
        //TODO: move terminal cursor to (0, 0) I have it in the CG_Image cpp file

        std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - current;
        float dt = deltaTime.count();

        m_animation->onUpdate(dt);
        m_animation->onRender();
        
        usleep(1000 * 1000 / FPS);
        current = std::chrono::steady_clock::now();

    }
}