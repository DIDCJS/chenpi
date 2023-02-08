#include <conpoment/cp_position.h>
#include <reflection/reflection.h>

#include <iostream>


void Register(){
    CPPosition::Register();
}
int main(int, char**) {
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
