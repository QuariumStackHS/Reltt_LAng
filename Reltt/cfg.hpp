#include <filesystem>
#include <dirent.h>
#include <cstdlib>
Configurator::Configurator()
{
this->buildtype = EXE;this->CPPLang = CPP17;this->ProgrameName = "RELTT";this->Termwidth=90;this->debug=0;setenv("RelttPath","/Users/christopherclement/Projects/Reltt_LAng/Reltt/",1);this->Reltt_path=getenv("RelttPath");}