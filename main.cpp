#include <conpoment/cp_position.h>
#include <reflection/reflection.h>

#include <iostream>
typedef int (*pf)(int, int); //函数指针

class Object{

};

class A: public Object{

public:
    void SetNum(){
        std::cout<< "SetNum "<< std::endl;
    }

    int GetNum(){
        std::cout<< "GetNum "<< std::endl;
        return m_nNum;
    }

public:
    int m_nNum;
};

class WrapperBase{

};

template<typename SetFunc, typename GetFunc>
class WrapperProperty{
public:
    WrapperProperty(SetFunc setFunc, GetFunc getFunc){
        std::cout<< "WrapperProperty::WrapperProperty "<< std::endl;
        m_SetFunc = setFunc;
        m_GetFunc = getFunc;
    }
    SetFunc GetSetFunc(){
        return m_SetFunc;
    }

    GetFunc GetGetFunc(){
        return m_GetFunc;
    }
private:
    SetFunc m_SetFunc;
    GetFunc m_GetFunc;
};


template<typename SetFunc, typename GetFunc, typename ClassType>
void Wrapper(SetFunc setFunc, GetFunc getFunc, ClassType* ptr){
    std::cout<<"Wrapper" << std::endl;
    WrapperProperty<SetFunc, GetFunc> wrapperProperty(setFunc, getFunc);
    A a;
    // std::invoke(setFunc, ptr);
    auto setFunc1 = wrapperProperty.GetSetFunc();
    std::invoke(setFunc1, ptr);
    // (*ft)(a);
}

void Register(){
    CPPosition::Register();
}

template<typename ReturnType, typename Class, typename... args>
using FuncPtr = ReturnType (Class::*)(args...);

template<typename TargetClass, typename ReturnType, typename Class, typename... args>
auto ClassFuncCast(FuncPtr<ReturnType, Class, args...> pFunc){
    std::cout<<"ClassFuncCast"<<std::endl;
    return static_cast<FuncPtr<ReturnType, TargetClass, args...>>(pFunc);
}



int main(int, char**) {
    A* pA = new A();
    Wrapper(&A::SetNum, &A::GetNum, pA);

    void (A::*setFun)() = &A::SetNum;

    Object* pO = static_cast<Object*>(pA);
    (pA->*setFun)();

    auto setFun2 = ClassFuncCast<Object>(setFun);
    (pO->*setFun2)();


    // // Object::*

    // Test(&A::m_nNum);
    // TestFunc(&A::SetNum);

    return 0;












    //register all metatype
    Register();

    CPPosition* pCPPosition =static_cast<CPPosition*>(MetaType::CreateClassObject("CPPosition"));
    if(pCPPosition == nullptr){
        std::cout<< "pCPPosition == nullptr "<< std::endl; 
        return -1;
    }
    
    pCPPosition->m_vPos.x = 1.0f;

    Vec3* pPos = static_cast<Vec3*>(CPPosition::GetPos(pCPPosition) );
    std::cout<< " pos : "<<pPos->x << " " << pPos->y << " " << pPos->z <<std::endl;
    return 0;
}
