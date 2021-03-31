g++ Reltt/main.cpp -o Reltt/cache/main.o -c -w -std=c++17 -w
g++ Reltt/Reltt.cpp -o Reltt/cache/Reltt.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Linked_List.cpp -o Reltt/cache/Reltt_LL.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Value.cpp -o Reltt/cache/Reltt_Value.o -c -w -std=c++17 -w
g++ Reltt/Reltt_Instruction_func.cpp -o Reltt/cache/Reltt_INS.o -c -w -std=c++17 -w
g++ Reltt/Utils.cpp -o Reltt/cache/Utils.o -c -w -std=c++17 -w

g++ Reltt/Modules/RelttSTD.cpp -o Reltt/cache/RelttSTD.o -c -w -std=c++17 -w
g++ Reltt/Modules/Generator.cpp -o Reltt/cache/Generator.o -c -w -std=c++17 -w
g++ Reltt/Modules/cpp-compile.cpp -o Reltt/cache/cpp-compile.o -c -w -std=c++17 -w
g++ Reltt/Modules/Cmp.cpp -o Reltt/cache/Cmp.o -c -w -std=c++17 -w
g++ Reltt/Modules/ASM.cpp -o Reltt/cache/ASM.o -c -w -std=c++17 -w

mkdir Reltt/cache
g++ Reltt/cache/Reltt.o Reltt/cache/RelttSTD.o Reltt/cache/ASM.o Reltt/cache/Cmp.o Reltt/cache/cpp-compile.o Reltt/cache/Generator.o Reltt/cache/Utils.o Reltt/cache/main.o Reltt/cache/Reltt_INS.o Reltt/cache/Reltt_Value.o Reltt/cache/Reltt_LL.o -o Reltt/bin/Reltt -std=c++17 -w
