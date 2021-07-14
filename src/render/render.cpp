#include <render/render.h>
namespace chenpi{

Render::Render(/* args */){
}

Render::~Render(){

}

void Render::SetVertexBuffer(float * ptr, int vertexNum, int vertexGroupNum){
    m_pVertexBuffer = ptr;
    m_nVertexNum = vertexNum;
    m_nVertexGroupNum = vertexGroupNum;
}

void Render::ClearColor(float r, float g, float b, float a){
    
}

}
