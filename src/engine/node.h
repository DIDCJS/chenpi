#pragma once
#include <vector>
#include<engine/effect/effect.h>
namespace chenpi{
    class Node{
        public:
            Node();
            ~Node();
        public:
            void Draw();
            void PushEffect(Effect* effect);
        protected:
            std::vector<Effect*> m_vEffectVector;
    };
}