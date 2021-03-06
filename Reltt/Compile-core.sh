g++ Reltt.cpp -std=c++17 -c -o Obj/Reltt.o -w

g++ main.cpp -std=c++17 -c -o Obj/main.o -w

#g++ installer.cpp -std=c++17 -o Reltt-installer -w

#g++ QSR/Obj/Reltt.o QSR/Obj/main.o -o bin/Reltt
#exit
export RelttPath="/Users/christopherclement/Projects/Reltt_LAng/Reltt/"
export PATH="$RelttPath\ bin:$PATH"