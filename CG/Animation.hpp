#ifndef __CG_ANIMATION_HPP__
#define __CG_ANIMATION_HPP__

#include "./Image.hpp"

#include <unistd.h>
#include <chrono>
#include <iostream>

namespace CG {
    class Animation : protected CG::Image {
    public:
        Animation(int width, int height) : CG::Image(width, height) {}
        virtual ~Animation() { this->CG::Image::~Image(); }
        
        virtual void on_update(float) {}
        virtual void on_render() {}
        
        void play_animation();
        static float fps;
    };
}
#endif // __CG_ANIMATION_HPP__