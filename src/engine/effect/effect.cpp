#include <engine/effect/effect.h>

namespace chenpi{
    Effect::Effect(){

    }
    Effect::~Effect(){
        if(m_pRender) delete m_pRender;
    }

    void Effect::Draw(){

    }
}