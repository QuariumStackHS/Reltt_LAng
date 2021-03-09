#include "includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *@2_exe_Code[] = {};
int @2_exe_size=0;
	Reltt_INT *i =new Reltt_INT(@2_exe_size,@2_exe_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"));
	i->Parse();
	return 0;
}

