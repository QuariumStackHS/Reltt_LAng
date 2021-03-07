//
// Created by Christopher Clement on 2021-03-06.
//
#include <iostream>
#include <string>
//#include <ofstream>
#include <cstring>
#include <filesystem>
#include <fstream>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"
using namespace std;
int main(){
    cout<<RED<<""" /$$$$$$$            /$$   /$$     /$$                                      \n"
          "| $$__  $$          | $$  | $$    | $$                                      \n"
          "| $$  \\ $$  /$$$$$$ | $$ /$$$$$$ /$$$$$$                                    \n"
          "| $$$$$$$/ /$$__  $$| $$|_  $$_/|_  $$_/                                    \n"
          "| $$__  $$| $$$$$$$$| $$  | $$    | $$                                      \n"
          "| $$  \\ $$| $$_____/| $$  | $$ /$$| $$ /$$                                  \n"
          "| $$  | $$|  $$$$$$$| $$  |  $$$$/|  $$$$/                                  \n"
          "|__/  |__/ \\_______/|__/   \\___/   \\___/                                    \n"
          "\n"
          " /$$$$$$                       /$$               /$$ /$$                    \n"
          "|_  $$_/                      | $$              | $$| $$                    \n"
          "  | $$   /$$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$ | $$| $$  /$$$$$$   /$$$$$$ \n"
          "  | $$  | $$__  $$ /$$_____/|_  $$_/   |____  $$| $$| $$ /$$__  $$ /$$__  $$\n"
          "  | $$  | $$  \\ $$|  $$$$$$   | $$      /$$$$$$$| $$| $$| $$$$$$$$| $$  \\__/\n"
          "  | $$  | $$  | $$ \\____  $$  | $$ /$$ /$$__  $$| $$| $$| $$_____/| $$      \n"
          " /$$$$$$| $$  | $$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$| $$|  $$$$$$$| $$      \n"
          "|______/|__/  |__/|_______/    \\___/   \\_______/|__/|__/ \\_______/|__/"""<<RESET<<endl;
    string i=((string)"/Users/").append(getenv("USER")).append("/Reltt");
    cout<<"enter path to install Reltt or enter 0 to use: "<<RED<<i<<RESET<<endl;
    cout<<CYAN<<"~>"<<RESET;

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
    string fileout = getenv("RelttPath") + (string) "cache/";
    system(((string)"mkdir ").append(fileout).c_str());
    return system(CMD.c_str());

}