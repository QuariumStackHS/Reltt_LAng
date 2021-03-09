#include <iostream>
#include <string>
#include "config.hpp"
using namespace std;
class Reltt_Info{
    string QSR="Quarium Stack Reltt";
    string QSR_Version="1.1.0";
    public:
    Reltt_Info(){
        cout<<BLUE<<QSR<<GREEN<<" (QSR) Version: "<<BOLDCYAN<<QSR_Version<<RESET<<endl;
    }
};