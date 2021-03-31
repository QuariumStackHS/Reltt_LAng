#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Reltt_Help_Code[] = {};
int Reltt_Help_size=0;
	Reltt_INT *i =new Reltt_INT(Reltt_Help_size,Reltt_Help_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(new Value("argv-"+to_string(ij),Aargv[ij],"string"),0);
	i->Parse();
	return 0;
}

