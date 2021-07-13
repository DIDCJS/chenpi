#pragma once
#include <render/render.h>
#include <global/global.h>
namespace chenpi{
class Program;
class OpenGL : public Render
{

public:
    OpenGL(const char* vs, const char* fs);
    virtual ~OpenGL();
public:
    void Draw(float* pfPos, int nSize);
private:
    Program* m_pProgram = nullptr;
};
}

