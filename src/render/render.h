#pragma once
#include <vector>
namespace chenpi{
class Render
{
public:
    Render(/* args */);
    virtual ~Render();
public:
    void SetVertexBuffer(float * ptr, int vertexNum, int vertexGroupNum);
    virtual void ClearColor(float r, float g, float b, float a);
protected:
    float* m_pVertexBuffer = nullptr;
    int m_nVertexNum = 0; //顶点数
    int m_nVertexGroupNum = 0; //顶点组数，比如需要position，uv0，uv1，传递3（默认vec3类型）
    // float* m_pPosition = nullptr;
    // std::vector<float*> 
    
};

}
