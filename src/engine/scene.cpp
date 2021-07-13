#include <engine/scene.h>
#include <engine/node.h>

namespace chenpi{
    Scene::Scene(){
        
    }

    Scene::~Scene(){

    }

    void Scene::Draw(){
        m_pRootNode->Draw();
    }

    void Scene::SetRootNode(Node* pNode){
        m_pRootNode = pNode;
    }
}