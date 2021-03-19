# Reltt (Quarium Stack Reltt)
![alt text](https://media.discordapp.net/attachments/747998694267289700/817183931622228008/reltt.png)
(Logo By MasterPisop Artz)

QSR_Lang is a runtime that use a specific syntaxe (exemples in scripts/*.qf)
it is write in c++ by a 15 year old (ME)

note this is not ready for ditribution

for help on how to use QSR_lang type in terminal: "./{QSR_executable} Help"

you can compile any RlS script to the interpreter
```
┌───────Function────────┬───────Description──────────────────────────────────────────┐
│       compile         |       [Compilable_Module]
│       link            |       Link all objs together
│       App-RCP         |       Recompile app from local source √
│       App-RUP         |       Update from master-Github and recompile
│       run             |       run exe file in build/exe
│       import          |       import [Module], note those are c++ import √
│       using           |       using [Module], note those are QF import √
│       func            |       [Fname] ( argtype1 argtype2 ) as begin: {Code} end; √
│       call            |       [Func] √
│       >               |       [Func] √
│       with            |       call [Func] with/-> Args √
│       exit            |       exit Programme √
│       add             |       add [Compilable_Module]
│       init            |       init Project
│       -RlS            |       Run Reltt Script √
│       -help           |       [module] √
│       <>              |       [varname] ["var value"] √
│       var             |       [varname] [var_value] √
│       *>              |       [varname], delete var √
│       PATH            |       add to the looking path√
│       DMP             |       show loaded UD_function. Note this function do not work with compiled script √
│       if              |       if ( bool ) if else ( bool ) else endif; √
│       SET             |       set RelttPath (Restart Reltt to take change) √
│       show            |       show all variables √
│       Gen_this        |       Generate a script with this code √
│       wait            |       wait for enter key √
│       cin             |       get until enter key √
└─────────────────────────────────────────────────────────────────────────────────────────────┘
┌───────Function┬─Module:Generator────┬───Description───Version:─────────────────────────────────┐
│       Gen_Help        |Generator              |       Gen helper
│       Gen_APP         |Generator              |       
│       As_Native       |Generator              |        [exe_name] scriptpath 
│       Clean           |Generator              |        [exe_name] 
└─────────────────────────────────────────────────────────────────────────────────────────────┘
┌───────Function┬─Module:Std────┬───Description───Version:─────────────────────────────────┐
│       cout    |Std            |       print value as interpreted
│       Sys     |Std            |       execute value as interpreted
└─────────────────────────────────────────────────────────────────────────────────────────────┘
┌───────Function┬─Module:ASM────┬───Description───Version:─────────────────────────────────┐
│       ASM     |ASM            |       
└─────────────────────────────────────────────────────────────────────────────────────────────┘
┌───────Function┬─Module:Compilator────┬───Description───Version:─────────────────────────────────┐
│       Set_Main        |Compilator             |       set Main_executable for project
│       Set_Name        |Compilator             |       
│       Set_output_Path |Compilator             |       
│       Compile         |Compilator             |        [exe_name] scriptpath 
│       add_file        |Compilator             |        [exe_name] 
│       Clean           |Compilator             |       Clean OBJ for compilation require Set_Name 
│       Setup           |Compilator             |       setup OBJ for compilation require Set_Name 
│       Run             |Compilator             |       run Main_executable
└─────────────────────────────────────────────────────────────────────────────────────────────┘
┌───────Function┬─Module:C++────┬───Description───Version:─────────────────────────────────┐
│       module          |C++            |       add module I
│       Exe             |C++            |       execute value as interpreted
│       Add             |C++            |       add to linker
│       link-this       |C++            |       compile+link
│       link-this_DLL   |C++            |       compile+link
│       Add_DLL         |C++            |       
└─────────────────────────────────────────────────────────────────────────────────────────────┘
```
