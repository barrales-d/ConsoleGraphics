#ifndef __CG_ANIMATOR_HPP__
#define __CG_ANIMATOR_HPP__

#include <unistd.h>
#include <chrono>
#include <iostream>

namespace CG {
    class Animation {
    public: 
        virtual ~Animation() {}
        virtual void on_update(float) = 0;
        virtual void on_render() = 0;
    };

    class Animator {
    private:
        Animation *m_animation;    
    public:
        Animator(Animation *animation) : m_animation(animation) {}
        ~Animator() = default;

        void play_animation(int width, int height);

        static float fps;

    };
}
#endif // __ANIMATOR_HPP__