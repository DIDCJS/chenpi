#include <conpoment/cp_position.h>
#include <reflection/reflection.h>
#include <reflection/metatype.h>
#include <core/cp_object.h>

#include <iostream>


class A: public CPObject{
REFLECTION_CLASS(A)

    static void RefectionAllProperty(){
        Wrapper("A", "m_nNum", &A::SetNum, &A::GetNum);
    }

public:
    void SetNum(int value){
        m_nNum = value;
        std::cout<< "SetNum m_nNum : " << m_nNum << std::endl;
    }

    int GetNum(){
        std::cout<< "GetNum "<< std::endl;
        return m_nNum;
    }

public:
    int m_nNum;
};

void Register(){
    A::Register();
}

int main(int, char**) {
    Register();

    A* pA = static_cast<A*>(MetaType::Create("A"));
    pA->SetNum(2);
    std::cout<< pA->GetNum() << std::endl;

    return 0;
    
}
