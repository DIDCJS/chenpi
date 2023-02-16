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

    static Object* Create(){
        A* pA = new A();
        return static_cast<Object*>(pA);
    }

public:
    int m_nNum;
};

class WrapperClassBase{
public:
    virtual Object* Create() = 0;
};

class WrapperPropertyBase{
public:
    virtual void Invoke(Object*) = 0;
};

template<typename Class>
class WrapperClass : public WrapperClassBase{
public:
    Object* Create() override{
        //TODO
        return new Object();
    }
    void SetCreateFunc(std::function<Object*()> value){m_Function = value;}
private:
    std::function<Object*()> m_Function;
    using ClassType = Class;
};

template<typename SetFunc, typename GetFunc>
class WrapperProperty : public WrapperPropertyBase{
public:
    WrapperProperty(SetFunc setFunc, GetFunc getFunc){
        std::cout<< "WrapperProperty::WrapperProperty "<< std::endl;
        m_SetFunc = setFunc;
        m_GetFunc = getFunc;
    }

    void Invoke(Object* pObject) override{
        //todo
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

// void Register(){
//     CPPosition::Register();
// }

template<typename ReturnType, typename Class, typename... args>
using FuncPtr = ReturnType (Class::*)(args...);

template<typename TargetClass, typename ReturnType, typename Class, typename... args>
auto ClassFuncCast(FuncPtr<ReturnType, Class, args...> pFunc){
    std::cout<<"ClassFuncCast"<<std::endl;
    return static_cast<FuncPtr<ReturnType, TargetClass, args...>>(pFunc);
}

static std::map<std::string, WrapperClassBase*> s_MapClass;
static std::map<std::string, std::map<std::string, WrapperPropertyBase*>> s_MapProperty;

void Register(){
    WrapperClass<A>* pWClass = new WrapperClass<A>();
    pWClass->SetCreateFunc(std::function<Object*()>(A::Create));
    s_MapClass["A"] = pWClass;



    auto pObject = pWClass->Create();
    auto pA = static_cast<A*>(pObject);
    std::cout<<pA->GetNum()<<std::endl;

    // std::function<Object*()> pFunc(A::Create);
    // auto pObject = pFunc();
    // auto pA = static_cast<A*>(pObject);
    // std::cout<<pA->GetNum()<<std::endl;
}

int main(int, char**) {
        
    Register();
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
