#ifndef __CG_ANIMATOR_HPP__
#define __CG_ANIMATOR_HPP__

#include <unistd.h>
#include <chrono>

#define FPS 15.0f

class CG_Animation {
public: 
    virtual ~CG_Animation() = default;
    virtual void onUpdate(float) = 0;
    virtual void onRender() = 0;
};

class CG_Animator {
private:
    CG_Animation *m_animation;    
public:
    CG_Animator(CG_Animation *animation) : m_animation(animation) {}
    ~CG_Animator() = default;

    void play();

};


#endif __CG_ANIMATOR_HPP__