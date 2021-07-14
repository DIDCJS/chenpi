// #include <engine/effect/dermabrasionEffect.h>
// //TODO: need to choose the true api rendering(such as opengl\vulkan\..) ,depands on plaform macro
// #include <render/opengl/dermabrasionOpengl.h>
// namespace chenpi{
// //TODO: need to choose the true api rendering(such as opengl\vulkan\..) ,depands on plaform macro
// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "void main()\n"
//     "{\n"
//     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//     "}\n\0";


// DermabrasionEffect::DermabrasionEffect(/* args */){
//     //TODO: need to choose the true api rendering(such as opengl\vulkan\..) ,depands on plaform macro
//     m_pRender = new DermabrasionOpengl();
//     auto pRender = dynamic_cast<DermabrasionOpengl*>(m_pRender);
//     m_pRender->Init(vertexShaderSource, fragmentShaderSource);
// }

// DermabrasionEffect::~DermabrasionEffect(){
//     if(m_pRender) delete m_pRender;
// }

// void DermabrasionEffect::Draw(){
//     //test for triangle

//     float pos[] = {
//         -1.0f, -1.0f, 0.0f,  
//         1.0f, 1.0f, 0.0f,  
//         -1.0f, 1.0f, 0.0f,  
//     }; 
//     auto pRender = dynamic_cast<DermabrasionOpengl*>(m_pRender);
//     pRender->Draw(pos, sizeof(pos)/ sizeof(float));   
// }

// }