#include <engine/effect/effect.h>
//TODO: need to choose the true api rendering(such as opengl\vulkan\..) ,depands on plaform macro

#include <render/opengl.h>

namespace chenpi{
    Effect::Effect(){
        //TODO: need to choose the true api rendering(such as opengl\vulkan\..) ,depands on plaform macro
        m_pRender = new OpenGL();
    }
    Effect::~Effect(){
        if(m_pRender) delete m_pRender;
    }
}