#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Update_Code[] = {"Begin:","import","Std","import","\"Generator\"","using","scripts/CSscript.RlS","func","update","(",")","as:","App-RCP","call","Native","->","\"Update\"","\"scripts/Update.RlS\"","call","Native","->","\"Compile\"","\"scripts/Compile.RlS\"","call","Native","->","\"Help\"","\"scripts/help.qf\"","end;","call","update","end;"};
int Update_size=32;
	Reltt_INT *i =new Reltt_INT(Update_size,Update_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(Value("argv-"+to_string(ij),Aargv[ij],"string"));
	i->Parse();
	return 0;
}

