#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Reltt_Update_Code[] = {"Begin:","import","Std","import","\"Generator\"","using","scripts/CSscript.RlS","func","update","(",")","as:","App-RCP","Gen_Help","call","Native","->","\"Reltt_Update\"","\"scripts/Update.RlS\"","call","Native","->","\"Reltt_Compile\"","\"scripts/Compile.RlS\"","call","Native","->","\"Reltt_Help\"","\"scripts/help.qf\"","end;","call","update","end;"};
int Reltt_Update_size=33;
	Reltt_INT *i =new Reltt_INT(Reltt_Update_size,Reltt_Update_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"));
	i->Parse();
	return 0;
}

