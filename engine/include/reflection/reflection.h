#pragma once
#include <conpoment/cp_position.h>
#include <core/cp_object.h>
#include <iostream>
#include <map>
#include <functional>


class WrapperClassBase{
public:
    virtual CPObject* Create() = 0;
};

class WrapperPropertyBase{
public:
    virtual void SetValue(CPObject* pObject, void* pValue) = 0;
};

template<typename Class>
class WrapperClass : public WrapperClassBase{
public:
    CPObject* Create() override{
        return static_cast<CPObject*>(new Class());
    }
    void SetCreateFunc(std::function<CPObject*()> value){m_Function = value;}
private:
    std::function<CPObject*()> m_Function;
    using ClassType = Class;
};


template<typename ReturnType, typename Class, typename... args>
using FuncPtr = ReturnType (Class::*)(args...);

template<typename TargetClass, typename ReturnType, typename Class, typename... args>
auto ClassFuncPtrCast(FuncPtr<ReturnType, Class, args...> pFunc){
    std::cout<<"ClassFuncCast"<<std::endl;
    return static_cast<FuncPtr<ReturnType, TargetClass, args...>>(pFunc);
}

template <typename Func>
struct FuncTraits;

template < typename R, typename Class, typename... Args>
struct FuncTraits<R (Class::*)(Args...)> 
{
    using ReturnType = R;
};

template<typename SetFunc, typename GetFunc>
class WrapperProperty : public WrapperPropertyBase{
public:
    WrapperProperty(SetFunc setFunc, GetFunc getFunc){
        std::cout<< "WrapperProperty::WrapperProperty "<< std::endl;
        m_SetFunc = setFunc;
        m_GetFunc = getFunc;
    }

    void SetValue(CPObject* pObject, void* pValue) override{
        std::cout<< "WrapperProperty::SetValue" << std::endl;
        ReturnType* pNewValue = static_cast<ReturnType*>(pValue);
        auto pNewSetFunc = ClassFuncPtrCast<CPObject>(m_SetFunc);
        (pObject->*pNewSetFunc)(*pNewValue);
    }

private:
    SetFunc m_SetFunc;
    GetFunc m_GetFunc;
    using ReturnType = typename FuncTraits<GetFunc>::ReturnType;
    
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

#define REFLECTION_CLASS(ClassType) \
public: \
    static CPObject* Create(){\
        ClassType* pNew = new ClassType();\
        return static_cast<CPObject*>(pNew);\
    }\
    static void Register(){\
        WrapperClass<ClassType>* pWClass = new WrapperClass<ClassType>();\
        pWClass->SetCreateFunc(std::function<CPObject*()>(ClassType::Create));\
        s_MapClass[#ClassType] = pWClass;\
        ClassType::RefectionAllProperty();\
    }

