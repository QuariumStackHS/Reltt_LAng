#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Reltt_Help_Code[] = {"Begin:","-help","Base","-help","Generator","-help","Std","-help","ASM","-help","Compilator","end;"};
int Reltt_Help_size=12;
	Reltt_INT *i =new Reltt_INT(Reltt_Help_size,Reltt_Help_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"),0);
	i->Parse();
	return 0;
}

