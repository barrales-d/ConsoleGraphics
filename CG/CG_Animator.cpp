#include "./CG_Animator.hpp"

#include <unistd.h>

void CG_Animator::play() {
    while(1) {
        //TODO: figure out delta time
        //TODO: move terminal cursor to (0, 0) I have it in the CG_Image cpp file
        m_animation->onUpdate(1/20);
        m_animation->onRender();

    }
}