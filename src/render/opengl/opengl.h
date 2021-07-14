#pragma once
#include <render/render.h>
#include <global/global.h>
#include <glad/glad.h>
namespace chenpi{
class Program;
class OpenGL : public Render
{

public:
    OpenGL();
    virtual ~OpenGL();
public:
    void Init(const char* vs, const char* fs);
    void Draw();
public:

    void ClearColor(float r, float g, float b, float a) override;
    virtual void SetAttribute(const char* nameStr,
                                const GLint& size,
                                const GLenum& type,
                                const GLboolean& normalized,
                                const GLsizei& stride,
                             	const void * pointer);

    virtual void SetUniformVec(const char* nameStr, const short& numValue, const float& v0 = 0.0f,
                                     const float& v1 = 0.0f, const float& v2 = 0.0f, const float& v3 = 0.0f);
private:
    Program* m_pProgram = nullptr;
};
}

