/*put includes here*/
#include "Modules/Generator.hpp"
#include "Modules/Cmp.hpp"
#include "Modules/RelttSTD.hpp"
#include "Modules/ASM.hpp"
#include "Modules/cpp-compile.hpp"
#include "includes/Reltt.hpp"

/*put your module in this function to add it*/
void Init_Modules(Reltt_INT *I){
    I->add_Module(Generator());
    I->add_Module(RelttSTD_Module());
    I->add_Module(ASM_MOD());
    I->add_Module(Compilator());
    I->add_Module(CPP_Module());

}