#include "./CG_Animator.hpp"

#include <unistd.h>

void CG_Animator::play() {
    while(1) {
        m_animation->onUpdate(1/20);
        m_animation->onRender();
    }
}