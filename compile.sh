g++ Reltt/main.cpp -o Reltt/OBJ/main.o -c -w -std=c++17 -w
g++ Reltt/Reltt.cpp -o Reltt/OBJ/Reltt.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Linked_List.cpp -o Reltt/OBJ/Reltt_LL.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Value.cpp -o Reltt/OBJ/Reltt_Value.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Instruction_func.cpp -o Reltt/OBJ/Reltt_INS.o -c -w -std=c++17 -w
g++ Reltt/Utils.cpp -o Reltt/OBJ/Utils.o -c -w -std=c++17 -w

g++ Reltt/Modules/RelttSTD.cpp -o Reltt/OBJ/RelttSTD.o -c -w -std=c++17 -w
g++ Reltt/Modules/Generator.cpp -o Reltt/OBJ/Generator.o -c -w -std=c++17 -w
g++ Reltt/Modules/cpp-compile.cpp -o Reltt/OBJ/cpp-compile.o -c -w -std=c++17 -w
g++ Reltt/Modules/Cmp.cpp -o Reltt/OBJ/Cmp.o -c -w -std=c++17 -w
g++ Reltt/Modules/ASM.cpp -o Reltt/OBJ/ASM.o -c -w -std=c++17 -w

mkdir Reltt/cache
g++ Reltt/OBJ/Reltt.o Reltt/OBJ/RelttSTD.o Reltt/OBJ/ASM.o Reltt/OBJ/Cmp.o Reltt/OBJ/cpp-compile.o Reltt/OBJ/Generator.o Reltt/OBJ/Utils.o Reltt/OBJ/main.o Reltt/OBJ/Reltt_INS.o Reltt/OBJ/Reltt_Value.o Reltt/OBJ/Reltt_LL.o -o Reltt/bin/Reltt -std=c++17 -w
