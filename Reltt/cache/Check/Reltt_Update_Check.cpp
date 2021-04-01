#include "../includes/Reltt.hpp"
int main(int Aargc,char** Aargv){
char *Reltt_Update_Code[] = {"Begin:","import","Std","import","C++","import","\"Generator\"","Set_Cache","(","RelttPath","+","\"cache/\"",")","func","Add_RelttDll","(",")","Add_DLL","(","RelttPath","+","\"/bin/Reltt.so\"",")","end;","func","Add_Reltt_import","(",")","Add","Reltt_Utils","Add","Reltt_Ins_func","Add","Reltt_Value","Add","Reltt_linked","Add","Reltt","Add","ASM","Add","Cmp","Add","cpp-compile","Add","Generator","Add","RelttSTD","Add","Remote","Add","asmReltt","end;","func","Add_Reltt","(",")","/*","Reltt","is","compiled","here","*/","module","\"Reltt\"","(","RelttPath","+","\"Reltt.cpp\"",")","module","\"Reltt_Value\"","(","RelttPath","+","\"Reltt_Value.cpp\"",")","module","\"Reltt_linked\"","(","RelttPath","+","\"Reltt_Linked_List.cpp\"",")","module","\"Reltt_Ins_func\"","(","RelttPath","+","\"Reltt_Instruction_func.cpp\"",")","module","\"Reltt_Utils\"","(","RelttPath","+","\"Utils.cpp\"",")","module","\"ASM\"","(","RelttPath","+","\"Modules/ASM.cpp\"",")","module","\"Cmp\"","(","RelttPath","+","\"Modules/Cmp.cpp\"",")","module","\"cpp-compile\"","(","RelttPath","+","\"Modules/cpp-compile.cpp\"",")","module","\"Generator\"","(","RelttPath","+","\"Modules/Generator.cpp\"",")","module","\"RelttSTD\"","(","RelttPath","+","\"Modules/RelttSTD.cpp\"",")","module","\"Remote\"","(","RelttPath","+","\"Modules/Remote.cpp\"",")","asm_module","\"asmReltt\"","(","RelttPath","+","\"../asm/Reltt.S\"",")","/*","Tell","the","linked",".o","here","*/",">","Add_Reltt_import","end;","func","Native","(","string","string",")","As_Native","@1","@2","Exe","(","RelttPath","+","\"bin/\"","+","@1",")",">","Add_RelttDll","Add","@1","module","@1","(","RelttPath","+","\"cache/\"","+","@1","+","\"-OBJ.cpp\"",")","link-this","/*","bundling","it","*/","/*","Exe","(","RelttPath","+","\"bin/Bundled/\"","+","@1",")","Add","@1",">","Add_Reltt_import","module","@1","(","RelttPath","+","\"cache/\"","+","@1","+","\"-OBJ.cpp\"",")","link-this","*/","/*","Clean","(","\"cache/\"","+","@1",")","*/","end;","func","update","(",")","/*",">","update_Reltt","*/","<>","Update","(","RelttPath","+","\"RlS/build.RlS\"",")","<>","Help","(","RelttPath","+","\"RlS/help.RlS\"",")",">","Native","->","\"Reltt_Update\"","Update","Clean","\"Reltt_Update\"","Gen_Help",">","Native","->","\"Reltt_Help\"","Help","Clean","\"Reltt_Help\"","exit","end;","func","build_Reltt","(",")","Exe","(","RelttPath","+","\"bin/Reltt.so\"",")",">","Add_Reltt","link-this_DLL","end;","func","build_Reltt_int","(",")","Exe","(","RelttPath","+","\"bin/Reltt\"",")","Add_DLL","(","RelttPath","+","\"/bin/Reltt.so\"",")","Add","main","module","\"main\"","(","RelttPath","+","\"/main.cpp\"",")","Add","asmain","asm_module","\"asmain\"","(","RelttPath","+","\"../asm/Main.S\"",")","link-this","/*","Exe","(","RelttPath","+","\"bin/Bundled/Reltt\"",")",">","Add_Reltt_import","Add","main","module","\"main\"","(","RelttPath","+","\"/main.cpp\"",")","Add","asmain","asm_module","\"asmain\"","(","RelttPath","+","\"../asm/Main.S\"",")","link-this","*/","end;","func","build_Installer","(",")","Exe","(","RelttPath","+","\"bin/\"","+","\"Reltt-Installer\"",")","module","\"Installer\"","(","RelttPath","+","\"../Installer/Installer.cpp\"",")","Add","Installer","link-this","end;",">","build_Reltt",">","build_Reltt_int",">","build_Installer",">","update","end;"};
int Reltt_Update_size=379;
	Reltt_INT *i =new Reltt_INT(Reltt_Update_size,Reltt_Update_Code);
		for (int ij=0;ij<Aargc;ij++)	i->New_Var(new Value("argv-"+to_string(ij),Aargv[ij],"string"),0);
	i->Parse();
	return 0;
}

