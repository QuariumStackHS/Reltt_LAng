//
// Created by Christopher Clement on 2021-03-06.
//
#include <iostream>
#include <string>
//#include <ofstream>
#include <filesystem>
#include <fstream>
using namespace std;
int main(){
    string i=((string)"/Users/").append(getenv("USER")).append("/Reltt");
    cout<<"enter path to install Reltt or enter 0 to use: "<<i<<endl;

    cin >>i;
    if (strcmp(i.c_str(),"0")==0){
        i=((string)"/Users/").append(getenv("USER")).append("/Reltt/");
    }
    if (i[i.size()-1]=='/'){

    }
    else{
        i.append("/");
    }
    system((((string)"git clone https://github.com/QuariumStackHS/Reltt_LAng.git ").append(i)).c_str());
    i.append("Reltt/");
    ofstream myfile;
    cout<<"RelttPath="<<i<<endl;
    myfile.open(i+"/cfg.hpp");
    myfile<<"#include <filesystem>\n"
          <<"#include <dirent.h>\n"
          <<"#include <cstdlib>\nConfigurator::Configurator()\n"
          <<"{\n"
          <<"this->buildtype = EXE;"
          <<"this->CPPLang = CPP17;"
          <<"this->ProgrameName = \"RELTT\";"
          <<"this->Termwidth=90;"
          <<"this->debug=0;"
          <<"setenv(\"RelttPath\",\""<<i<<"\",1);"
          <<"this->Reltt_path=getenv(\"RelttPath\");"
          <<"}";

    myfile.close();
    string CMD;
    CMD.append("g++ -std=c++17 -o ").append(i).append("bin/Reltt ").append(i).append("*.cpp -w");
    return system(CMD.c_str());

}