#pragma once
#include <core/cp_object.h>
#include <reflection/reflection.h>

#include <iostream>

class MetaType{
public:
    static CPObject* Create(std::string sClassName){
        auto& iter = s_MapClass.find(sClassName);
        if(iter == s_MapClass.end()){
            return nullptr;
        }
        return s_MapClass.find(sClassName)->second->Create();
    }
};
