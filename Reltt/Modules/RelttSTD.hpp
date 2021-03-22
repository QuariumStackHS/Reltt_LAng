#ifndef ReltSTD_HPP
#define ReltSTD_HPP

#include "../includes/Reltt.hpp"



void *print(Reltt_INT *IN){
Reltt_array PT=resolve_parentensis(IN);
    IN->p.begin_info();
    IN->p.print_info(PT.v_Name);
    IN->p.print_info(to_string(PT.Objects.size()));
    IN->p.print_info(Reltt_Array_to_string(&PT));
    IN->p.print_info(PT.S_value);
    IN->p.print_info(PT.T_R);

    IN->p.end_info();
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