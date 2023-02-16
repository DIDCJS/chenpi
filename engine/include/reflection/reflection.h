#pragma once
#include <conpoment/cp_position.h>
#include <core/cp_object.h>
#include <iostream>
#include <map>
#include <functional>


class WrapperClassBase{
public:
    virtual Object* Create() = 0;
};

class WrapperPropertyBase{
public:
    virtual void SetValue(Object* pObject) = 0;
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

    void SetValue(Object* pObject) override{
        //todo
        // A a;
        // a->m_SetFunc();
    }


private:
    SetFunc m_SetFunc;
    GetFunc m_GetFunc;
};

static std::map<std::string, WrapperClassBase*> s_MapClass;
static std::map<std::string, std::map<std::string, WrapperPropertyBase*>> s_MapClassProperty;


template<typename SetFunc, typename GetFunc>
void Wrapper(const std::string& sClassName, const std::string& sPropertyName, 
                    SetFunc setFunc, GetFunc getFunc){
    std::cout<<"Wrapper" << std::endl;
    if(s_MapClassProperty.find(sClassName) == s_MapClassProperty.end()){
        s_MapClassProperty.emplace(std::pair(sClassName, std::map<std::string, WrapperPropertyBase*>()));
    }
    auto& propertyMap = s_MapClassProperty[sClassName];
    WrapperProperty<SetFunc, GetFunc>* pWrapperProperty = new WrapperProperty<SetFunc, GetFunc>(setFunc, getFunc);
    propertyMap.emplace(std::pair(sPropertyName, pWrapperProperty));
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

#define CHEN_PI(ClassType) \
public: \
    static void Register(){\
        WrapperClass<ClassType>* pWClass = new WrapperClass<ClassType>();\
        pWClass->SetCreateFunc(std::function<Object*()>(ClassType::Create));\
        s_MapClass[#ClassType] = pWClass;\
    }

