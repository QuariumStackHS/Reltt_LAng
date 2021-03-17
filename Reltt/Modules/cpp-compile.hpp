//
// Created by Christopher Clement on 2021-03-17.
//

#ifndef CPPSTD_HPP
#define CPPSTD_HPP

#include "../includes/Reltt.hpp"
static string linkcmd;

void *mod(Reltt_INT *IN){
    string PT=resolve_parentensis(IN).S_value;
    //IN->charstr--;
    string PT2=resolve_parentensis(IN).S_value;
    string cmd="g++ -c -o ";
    cmd.append("cache/").append(PT).append(".o -std=c++17 -w ").append(PT2);
    system(cmd.c_str());
    IN->p.begin_info();
    IN->p.print_info(cmd);
    //IN->p.end_info();
}
void *link(Reltt_INT *IN){
    string PT=resolve_parentensis(IN).S_value;
    linkcmd.append(" cache/").append(PT).append(".o");
    IN->p.end_info();
}
void *linker(Reltt_INT *IN){
    string cmd="g++";
    cmd.append(linkcmd).append(" -std=c++17 -w -o ").append(getenv("EXENAME"));
    system(cmd.c_str());
    //IN->p.begin_info();
    IN->p.print_info(cmd);
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    linkcmd="";
}
void *set_exe_name(Reltt_INT *IN){
    string PT=resolve_parentensis(IN).S_value;
    setenv("EXENAME",IN->getVar(PT).S_value.c_str(),1);
}
Reltt_INT::QSRcModule CPP_Module(){
    Reltt_INT::QSRcModule E=Reltt_INT::QSRcModule();
    E.Module_Name="C++";
    E.add_Cask("module","add module I",&mod);
    E.add_Cask("Exe","execute value as interpreted",&set_exe_name);
    E.add_Cask("Add","add to linker",&link);
    E.add_Cask("link-this","compile+link",&linker);
    //link
    return E;
}


#endif