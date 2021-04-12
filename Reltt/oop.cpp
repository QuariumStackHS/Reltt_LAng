#include "includes/Reltt.hpp"
        Reltt_INT::C_Object::C_Object(string classnameS){
            this->classname=classnameS;
        }
        int Reltt_INT::C_Object::add_Property(Value*V){
            this->Propertys.push_back(V);
        }
        int Reltt_INT::C_Object::add_UDF(UD_Function*F){
            this->Methods.push_back(F);
        }