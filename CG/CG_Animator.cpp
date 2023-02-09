#include "./CG_Animator.hpp"

void CG_Animator::play() {
    auto current = std::chrono::steady_clock::now();
    while(1) {
        std::printf("\x1b[%dA\x1b[%dD", m_animation->getWidth(), m_animation->getHeight());
        
        std::chrono::duration<float> deltaTime = std::chrono::steady_clock::now() - current;
        float dt = deltaTime.count();

        m_animation->onUpdate(dt);
        m_animation->onRender();
        
        current = std::chrono::steady_clock::now();
        usleep(1000 * 1000 / FPS);
    }
}