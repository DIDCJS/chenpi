#include <render/opengl/opengl.h>
#include <render/opengl/program.h>
#include <glad/glad.h>
#include <iostream>
namespace chenpi{
OpenGL::OpenGL(){
}

OpenGL::~OpenGL(){
    delete m_pProgram;
}

void OpenGL::Init(const char* vs, const char* fs){
    m_pProgram = new Program(vs, fs);    
}

void OpenGL::ClearColor(float r, float g, float b, float a){
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGL::Draw(){
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_nVertexNum, m_pVertexBuffer, GL_STATIC_DRAW);

    SetAttribute("aPos", 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    // draw our first triangle
    glUseProgram(m_pProgram->GetProgramID());
    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, m_nVertexNum); // set the count to 6 since we're drawing 6 vertices now (2 triangles); not 3!

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(m_pProgram->GetProgramID());
}

void OpenGL::SetAttribute(const char* nameStr,
                                const GLint& size,
                                const GLenum& type,
                                const GLboolean& normalized,
                                const GLsizei& stride,
                             	const void * pointer){
    GLint index = glGetAttribLocation(m_pProgram->GetProgramID(), nameStr);
    if(index == -1){
        std::cout<<"ERROR glGetAttribLocation : no attribute in vsfs"<<std::endl;
        return;
    }
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void OpenGL::SetUniformVec(const char* nameStr, const short& numValue, 
                const float& v0/* = 0.0f*/, const float& v1/* = 0.0f*/, const float& v2 /* = 0.0f*/, const float& v3 /* = 0.0f*/){
    if(numValue <=0 || numValue > 4){
        std::cout<<"ERROR SetUniformVec numValue <=0 || numValue > 4"<<std::endl;
        return;
    }    
    GLuint index = glGetAttribLocation(m_pProgram->GetProgramID(), nameStr);
    switch (numValue)
    {
    case 1:
        /* code */
        glUniform1f(index, v0);
        break;
    case 2:
        /* code */
        glUniform2f(index, v0, v1);
        break;
    case 3:
        /* code */
        glUniform3f(index, v0, v1, v2);
        break;
    case 4:
        /* code */
        glUniform4f(index, v0, v1, v2, v3);
        break;
    
    default:
        break;
    }
    
}

}
