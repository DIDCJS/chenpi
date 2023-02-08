#pragma once
#include <conpoment/cp_position.h>

#include <iostream>
#include <map>
#include <functional>



typedef std::function<void(void*, void*)> SetFunc;
typedef std::function<void*(void*)> GetFunc;
typedef std::function<std::string()> GetPropertyNameFunc;
typedef std::function<void*()> CreateClassObjectFunc;

typedef std::tuple<SetFunc, GetFunc, GetPropertyNameFunc> PropertyTuple;
typedef std::tuple<CreateClassObjectFunc> ClassTuple;
static std::multimap<std::string, PropertyTuple> s_propertyMap;
static std::map<std::string, ClassTuple> s_classMap;

class MetaType{
public:
    static void GetPropertys(std::string value){
        // auto iter = s_classMap.find(value);
        // if(iter == s_classMap.end()){return;}
        // SetFunc createFunc = std::get<0>(iter->second);
        // return createFunc();

    }

    static void* CreateClassObject(std::string value){
        auto iter = s_classMap.find(value);
        if(iter == s_classMap.end()){return nullptr;}
        CreateClassObjectFunc createFunc = std::get<0>(iter->second);
        return createFunc();
    }
private:
    std::string m_metaType;
    // std::vector<PropertyTuple> m_allPropertysTuple;
};