#include <conpoment/cp_position.h>
#include <reflection/reflection.h>
#include <core/cp_object.h>

#include <iostream>


class A: public CPObject{
CHEN_PI(A)
public:
    void SetNum(int value){
        m_nNum = value;
        std::cout<< "SetNum m_nNum : " << m_nNum << std::endl;
    }

    int GetNum(){
        std::cout<< "GetNum "<< std::endl;
        return m_nNum;
    }

    static CPObject* Create(){
        A* pA = new A();
        return static_cast<CPObject*>(pA);
    }

public:
    int m_nNum;
};

void Register(){
    A::Register();

    Wrapper("A", "m_nNum", &A::SetNum, &A::GetNum);
    
    auto pWrapperProperty = s_MapClassProperty["A"]["m_nNum"];
    A a; 
    int nNum = 2;
    pWrapperProperty->SetValue(&a, &nNum);

}

template <typename T1, typename... Args>
class TestB{

};



int main(int, char**) {
    Register();
    return 0;
    
}
