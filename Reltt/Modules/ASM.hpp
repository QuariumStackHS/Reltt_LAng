#ifndef ASM_HPP
#define ASM_HPP 0

#include "../includes/Reltt.hpp"
using namespace std;

void *new_asmfun(Reltt_INT *IN){
        IN->charstr++;
        string FucName = IN->getcurrentIns();
        vector<ArgType> G;
        if (strcmp(IN->get_Next_Token().c_str(), "(") == 0)
        {
            string i = IN->get_Next_Token();
            //cout<<"open par"<<endl;

            while (strcmp(i.c_str(), ")") != 0)
            {

                G.push_back(i);
                //cout<<i<<endl;
                i = IN->get_Next_Token();
            }
        }
        int beginline = IN->charstr + 1;
        //cout<<"Adding Func name: "<<FucName<<endl;
        string FncCode;
        int EndOFFunc = 0;
        while (!EndOFFunc)
        {
            IN->charstr++;
            //cout<<getcurrentIns()<<endl;
            string InStr = IN->getcurrentIns();
            if (strcmp(InStr.c_str(), "end;") == 0)
            {
                EndOFFunc = IN->charstr;
            }
            else
            {
                FncCode.append(InStr.c_str());
                FncCode.append(" ");
            }
        }
        ofstream NasmFile;
        NasmFile.open((FucName+".nasm").c_str());
        NasmFile<<FncCode<<"\n";
        NasmFile.close();
        IN->newFunc(FucName, beginline, EndOFFunc, G);
}
Reltt_INT::QSRcModule ASM_MOD(){
    Reltt_INT::QSRcModule E=Reltt_INT::QSRcModule();
    E.Module_Name="ASM";
    E.add_Cask("ASM","",&new_asmfun);
    //E.add_Cask("Sys","execute value as interpreted",&system);
    return E;
}


#endif