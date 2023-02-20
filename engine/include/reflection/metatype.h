#pragma once
#include <core/cp_object.h>
#include <reflection/reflection.h>

#include <iostream>

class MetaType{
public:
    explicit MetaType(std::string sClassName){
        m_sClassName = sClassName;
    }

public:
    std::shared_ptr<CPObject> Create(){
        auto iter = s_MapClass.find(m_sClassName);
        if(iter == s_MapClass.end()){
            return std::shared_ptr<CPObject>();
        }
        std::shared_ptr<CPObject> pObject = iter->second->Create();
        return pObject;
    }

    // static std::map<std::string, std::map<std::string, WrapperPropertyBase*>> s_MapClassProperty;

    void SetValue(CPObject* pOj, std::string sPropertyName, void* pValue){
        auto iterClass = s_MapClassProperty.find(m_sClassName);
          if(iterClass == s_MapClassProperty.end()){
            return;
        }
        auto iterProperty = iterClass->second.find(sPropertyName);
        if(iterProperty == iterClass->second.end()){
            return;
        }
        iterProperty->second->SetValue(pOj, pValue);
    }

    std::string m_sClassName;
};
