#pragma once
namespace chenpi{
    class Node;
    class Scene
    {
    public:
        Scene(/* args */);
        ~Scene();
    public:
        void Draw();
    private:
        /* data */
        int m_nWidth = 0;
        int m_nHeight = 0;
        Node* m_pRootNode = nullptr;
    };
}
