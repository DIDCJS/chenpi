#pragma once

#include <reflection/reflection.h>
#include <iostream>
struct Vec3{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};
class CPPosition{
public:
    static void SetPos(void* pInstance, void* pValue){
        std::cout<< "CPPosition::SetPos " << std::endl;
        auto pCP = static_cast<CPPosition*>(pInstance);
        auto pV = static_cast<Vec3*>(pInstance);
        if(pCP==nullptr || pV == nullptr){return; }
        pCP->m_vPos = *pV;
    }

    static Vec3* GetPos(void* pInstance){
        auto pCP = static_cast<CPPosition*>(pInstance);
        if(pCP==nullptr){return nullptr;}
        return &pCP->m_vPos;
    }

    static std::string GetPosName(){return "Position";}

    static CPPosition* CreateClassObject(){return new CPPosition();}

    static void Register(){
        std::cout<<"### CPPosition::Register "<< std::endl;
        SetFunc setFunc(&SetPos);
        GetFunc getFunc(&GetPos);
        GetPropertyNameFunc getName(&GetPosName);
        PropertyTuple propertyTuple(setFunc, getFunc, getName);
        s_propertyMap.insert(std::make_pair("CPPosition", propertyTuple));

        CreateClassObjectFunc creatFunc(&CreateClassObject);
        ClassTuple classTuple(creatFunc);
        s_classMap.insert(std::make_pair("CPPosition", classTuple));

    }

public:
    Vec3 m_vPos;
};