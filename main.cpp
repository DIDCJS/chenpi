#include <conpoment/cp_position.h>
#include <reflection/reflection.h>
#include <core/cp_object.h>

#include <iostream>


class A: public Object{
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

    static Object* Create(){
        A* pA = new A();
        return static_cast<Object*>(pA);
    }

public:
    int m_nNum;
};

template<typename T>
class TestA{
public:
    template<typename... Args>
    void TestFunc0(Args... args){
        std::cout<< "TestFunc0" << std::endl;
        TestFunc1(args...);
    }

    template<typename T1, typename... Args>
    void TestFunc1(T1 value, Args... args){
        std::cout<< "TestFunc1 : value :" << value <<std::endl;
        TestFunc1(args...);
    }

    void TestFunc1(){
        std::cout<< "TestFunc1 : end" << std::endl;
    }
};


void Register(){
    A::Register();
    // static std::map<std::string, std::map<std::string, WrapperPropertyBase*>> s_MapProperty;
    // WrapperProperty* pWrapperProperty = new WrapperProperty()

    Wrapper("A", "m_nNum", &A::SetNum, &A::GetNum);
    auto pSetFunc = &A::SetNum;
    
    auto pWrapperProperty = s_MapClassProperty["A"]["m_nNum"];
    // pWrapperProperty->
}



int main(int, char**) {
    // A* pA = new A();
    // std::cout<<A::SetNum <<std::endl;
    // std::cout<<&A::SetNum <<std::endl;
    Register();

    TestA<int>* pTestA = new TestA<int>();
    pTestA->TestFunc0(1,"??");
    return 0;

}
