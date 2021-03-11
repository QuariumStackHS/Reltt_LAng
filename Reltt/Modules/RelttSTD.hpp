#ifndef ReltSTD_HPP
#define ReltSTD_HPP

#include "../includes/Reltt.hpp"



void *print(Reltt_INT *IN){
string PT=resolve_parentensis(IN).S_value;
    cout<<IN->getVar(PT).S_value<<endl;
}
void *system(Reltt_INT *IN){
string PT=resolve_parentensis(IN).S_value;
    system(IN->getVar(PT).S_value.c_str());
}
Reltt_INT::QSRcModule RelttSTD_Module(){
    Reltt_INT::QSRcModule E=Reltt_INT::QSRcModule();
    E.Module_Name="Std";
    E.add_Cask("cout","print value as interpreted",&print);
    E.add_Cask("Sys","execute value as interpreted",&system);
    return E;
}


#endif