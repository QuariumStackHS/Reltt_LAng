#include "../includes/Mods.hpp"

void*connect(Reltt_INT*IN){

}

void*Accept(Reltt_INT*IN){
}
void*Ex(Reltt_INT*IN){

}
void*PLS(Reltt_INT*IN){

}

Reltt_INT::QSRcModule Remote()
{
    Reltt_INT::QSRcModule M;
    M.Set_Name("Remote");
    M.add_Cask("connect", "-> IP Port", &connect);
    M.add_Cask("Listen", "wait for client to connect", &Accept);
    M.add_Cask("Run_last_string", "", &Ex);
    M.add_Cask("Print_last_string", "", &PLS);
    return M;
}

