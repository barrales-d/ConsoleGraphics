#ifndef __CG_ANIMATOR_HPP__
#define __CG_ANIMATOR_HPP__

#include <unistd.h>
#include <chrono>
#include <iostream>

#define FPS 15.0f

class CG_Animation {
public: 
    virtual ~CG_Animation() = default;
    virtual void onUpdate(float) = 0;
    virtual void onRender() = 0;
    //  provide the width and height of the Animation you create, so that the Animator has access to it 
    virtual int getWidth() = 0;
    virtual int getHeight() = 0;
};

class CG_Animator {
private:
    CG_Animation *m_animation;    
public:
    CG_Animator(CG_Animation *animation) : m_animation(animation) {}
    ~CG_Animator() = default;

    void play();

};


#endif // __CG_ANIMATOR_HPP__