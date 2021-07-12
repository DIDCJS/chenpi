#include <vector>
#include<engine/effect/effect.h>

class Node{
    public:
        Node();
        ~Node();
    protected:
        std::vector<Effect*> m_effectVector;
};