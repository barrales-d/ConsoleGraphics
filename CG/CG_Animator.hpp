#ifndef __CG_ANIMATOR_HPP__
#define __CG_ANIMATOR_HPP__

#include <unistd.h>
#include <chrono>
#include <iostream>

#define FPS 15.0f

class CG_Animation {
public: 
    virtual ~CG_Animation() = default;
    virtual void on_update(float) = 0;
    virtual void on_render() = 0;
    //  provide the width and height of the Animation you create, so that the Animator has access to it 
    virtual int get_width() = 0;
    virtual int get_height() = 0;
};

class CG_Animator {
private:
    CG_Animation *m_animation;    
public:
    CG_Animator(CG_Animation *animation) : m_animation(animation) {}
    ~CG_Animator() = default;

    void play_animation();

};


#endif // __CG_ANIMATOR_HPP__