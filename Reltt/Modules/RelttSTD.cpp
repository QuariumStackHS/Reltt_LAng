#ifndef ReltSTD_HPP
#define ReltSTD_HPP

#include "../includes/Mods.hpp"

void *print(Reltt_INT *IN)
{
    Value *PT = IN->getVar(IN->get_Next_Token());
    IN->p.begin_info();
    IN->p.print_info(PT->v_Name);
    int size = PT->L_size();
    cout << "LSINZE@" << size << endl;
    IN->p.print_info(to_string(size));
    IN->p.print_info(Reltt_Array_to_string(PT));
    IN->p.print_info(PT->S_value);
    IN->p.print_info(PT->T_R);

    IN->p.end_info();
}
void *system(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    system(IN->getVar(PT)->S_value.c_str());
}
Reltt_INT::QSRcModule RelttSTD_Module()
{
    Reltt_INT::QSRcModule E = Reltt_INT::QSRcModule();
    E.Module_Name = "Std";
    E.add_Cask("cout", "print value as interpreted", &print);
    E.add_Cask("Sys", "execute value as interpreted", &system);
    return E;
}

#endif