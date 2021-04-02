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
    cout<<YELLOW<<""" _______ _______ _   _________________                                                 \n"
               "(  ____ |  ____ ( \\  \\__   __|__   __/                                                 \n"
               "| (    )| (    \\/ (     ) (     ) (                                                    \n"
               "| (____)| (__   | |     | |     | |                                                    \n"
               "|     __)  __)  | |     | |     | |                                                    \n"
               "| (\\ (  | (     | |     | |     | |                                                    \n"
               "| ) \\ \\_| (____/\\ (____/\\ |     | |                                                    \n"
               "|/   \\__(_______(_______)_(     )_(                                                    \n"
               "                                                                                       \n"
               "   _   __________       _______________________ _       _       _______ _______    _   \n"
               "  / )  \\__   __( (    /(  ____ \\__   __(  ___  | \\     ( \\     (  ____ (  ____ )  ( \\  \n"
               " / /      ) (  |  \\  ( | (    \\/  ) (  | (   ) | (     | (     | (    \\/ (    )|   \\ \\ \n"
               "( (       | |  |   \\ | | (_____   | |  | (___) | |     | |     | (__   | (____)|    ) )\n"
               "| |       | |  | (\\ \\) (_____  )  | |  |  ___  | |     | |     |  __)  |     __)    | |\n"
               "( (       | |  | | \\   |     ) |  | |  | (   ) | |     | |     | (     | (\\ (       ) )\n"
               " \\ \\   ___) (__| )  \\  /\\____) |  | |  | )   ( | (____/\\ (____/\\ (____/\\ ) \\ \\__   / / \n"
               "  \\_)  \\_______//    )_)_______)  )_(  |/     \\(_______(_______(_______//   \\__/  (_/  """<<RESET<<endl;
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
    int cloned=system((((string)"git clone https://github.com/QuariumStackHS/Reltt_LAng.git ").append(i)).c_str());
    if (cloned!=0){
        cout<<"Error while Cloning..."<<endl;
    }
    string j=i;
    i.append("Reltt/");
    ofstream myfile;
    string fileout = getenv("RelttPath") + (string) "cache/";
    system(((string)"mkdir ").append(fileout).c_str());
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
    string CMD="cd ";
    CMD.append(j).append(" && sh ").append(i).append("../compile.sh");
    myfile.open(i+"Env.sh");
    myfile<<"export RelttPath=\""<<i<<"\""<<"\nexport PATH=\"$RelttPath/bin:$PATH\"";

    return system(CMD.c_str());
}
