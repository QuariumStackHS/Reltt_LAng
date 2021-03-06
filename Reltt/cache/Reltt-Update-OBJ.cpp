#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Reltt-Update_Code[] = {"Begin:","import","Std","import","\"Generator\"","using","scripts/CSscript.RlS","func","update","(",")","as:","App-RCP","call","Native","->","\"Reltt-Update\"","\"scripts/Update.RlS\"","call","Native","->","\"Reltt-Compile\"","\"scripts/Compile.RlS\"","call","Native","->","\"Reltt-Help\"","\"scripts/help.qf\"","end;","call","update","end;"};
int Reltt-Update_size=32;
	Reltt_INT *i =new Reltt_INT(Reltt-Update_size,Reltt-Update_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"));
	i->Parse();
	return 0;
}

