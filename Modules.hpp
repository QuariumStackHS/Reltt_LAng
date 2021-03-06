/*put includes here*/
#include "Modules/Generator.hpp"
#include "Modules/RelttSTD.hpp"
#include "includes/Reltt.hpp"
/*put your module in this function to add it*/
void Init_Modules(Reltt_INT *I){
    I->add_Module(Generator());
    I->add_Module(RelttSTD_Module());

}