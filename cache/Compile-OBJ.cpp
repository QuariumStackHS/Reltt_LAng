#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Compile_Code[] = {"Begin:","using","\"scripts/CSscript.RlS\"","import","\"Generator\"","call","Native","->","argv-1","argv-2","end;"};
int Compile_size=11;
	Reltt_INT *i =new Reltt_INT(Compile_size,Compile_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"));
	i->Parse();
	return 0;
}

