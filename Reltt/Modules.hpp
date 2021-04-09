#include "includes/Mods.hpp"
    /*put your module in this function to add it*/
    void Init_Modules(Reltt_INT *I){I->add_Module(Compilator());
I->add_Module(CPP_Module());
I->add_Module(Generator());
I->add_Module(RelttSTD());
I->add_Module(FSys());
I->add_Module(Remote());
}