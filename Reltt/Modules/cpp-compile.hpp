//
// Created by Christopher Clement on 2021-03-17.
//

#ifndef CPPSTD_HPP
#define CPPSTD_HPP

#include "../includes/Reltt.hpp"
static string linkcmd;
static string Param;
static string DLL;

void *mod(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    //IN->charstr--;
    string PT2=resolve_parentensis(IN)->S_value;
    string cmd="g++ -c -o ";
    cmd.append("cache/").append(PT).append(".o -std=c++17 -w ").append(PT2);
    system(cmd.c_str());
    IN->p.begin_info();
    IN->p.print_info(cmd);
    //IN->p.end_info();
}
void *link(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    linkcmd.append(" cache/").append(PT).append(".o");
    IN->p.end_info();
}
void *add_switch_to_gpp(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    Param.append(" ").append(PT);
}
void *linker(Reltt_INT *IN){
    string cmd="g++";
    cmd.append(linkcmd).append(" -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    system(cmd.c_str());
    //IN->p.begin_info();
    IN->p.print_info(cmd);
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    linkcmd="";
    DLL="";
    Param="";
}
void *linker_(Reltt_INT *IN){
    string cmd="g++";
    cmd.append(linkcmd).append(" -shared -Wl, -std=c++17 -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    system(cmd.c_str());
    //IN->p.begin_info();
    IN->p.print_info(cmd);
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    linkcmd="";
    Param="";
    DLL="";
}
void *set_exe_name(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    setenv("EXENAME",IN->getVar(PT).S_value.c_str(),1);
}
void*add_DLL(Reltt_INT*IN ){
    string PT=resolve_parentensis(IN)->S_value;
    DLL.append(" ").append(PT);
}
Reltt_INT::QSRcModule CPP_Module(){
    Reltt_INT::QSRcModule E=Reltt_INT::QSRcModule();
    E.Module_Name="C++";
    E.add_Cask("module","add module I",&mod);
    E.add_Cask("Exe","execute value as interpreted",&set_exe_name);
    E.add_Cask("Add","add to linker",&link);
    E.add_Cask("link-this","compile+link",&linker);
    E.add_Cask("link-this_DLL","compile+link",&linker_);
    E.add_Cask("Add_DLL","",&add_DLL);
    E.add_Cask("Add_Switch","",&add_switch_to_gpp);
    //link
    return E;
}


#endif