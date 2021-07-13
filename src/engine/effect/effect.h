#pragma once
#include <render/render.h>
namespace chenpi{
// class Render;
class Effect{
public:
    Effect();
    ~Effect();
public:
    void Draw();
protected:
    Render* m_pRender = nullptr; //根据平台决定了渲染的方式（opengl,vulkan,metal and so on ）
};
}