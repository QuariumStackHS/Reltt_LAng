#ifndef ReltSTD_HPP
#define ReltSTD_HPP

#include "../includes/Reltt.hpp"



void *print(Reltt_INT *IN){
string PT=IN->getVar(IN->get_Next_Token()).S_value;
    cout<<PT<<endl;

}
void *system(Reltt_INT *IN){
string PT=IN->get_Next_Token();
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