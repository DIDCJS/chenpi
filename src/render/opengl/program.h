#pragma once
namespace chenpi{
    //TODO:做成program池去管理会更合理
    class Program
    {
    public:
        Program(const char* vs, const char* fs);
        ~Program();
    public:
        unsigned int GetProgramID(){return m_programID;}
    private:
        unsigned int m_programID = 0;
    };
    
  
    
}