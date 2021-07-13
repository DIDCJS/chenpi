#include <engine/node.h>
namespace chenpi{
    Node::Node(){

    }

    Node::~Node(){

    }

    void Node::Draw(){
        for(auto it : m_vEffectVector){
            
        }
    }

    void Node::PushEffect(Effect* effect){
        m_vEffectVector.push_back(effect);
    }
}