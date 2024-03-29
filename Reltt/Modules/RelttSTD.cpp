#ifndef ReltSTD_HPP
#define ReltSTD_HPP

#include "../includes/Mods.hpp"

void *print(Reltt_INT *IN)
{
    Value *PT = IN->getVar(IN->get_Next_Token());
    IN->p.begin_info();
    IN->p.print_info(PT->S_value);
    IN->p.end_info();
}
void *system(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    system(IN->getVar(PT)->S_value.c_str());
}
Reltt_INT::QSRcModule RelttSTD()
{
    Reltt_INT::QSRcModule E = Reltt_INT::QSRcModule();
    E.Module_Name = "Std";
    E.constructorname="RelttSTD_Module";
    E.add_Cask("cout", "print value as interpreted", &print);
    E.add_Cask("Sys", "execute value as interpreted", &system);
    return E;
}

#endif