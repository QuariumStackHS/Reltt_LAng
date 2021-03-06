import os


os.system("g++ QSR/Reltt.cpp -std=c++17 -c -o QSR/Obj/Reltt.o -w")
"""
g++ QSR/main.cpp -std=c++17 -c -o QSR/Obj/main.o -w

g++ QSR/installer.cpp -std=c++17 -o Reltt-installer -w

g++ QSR/Obj/Reltt.o QSR/Obj/main.o -o bin/Reltt
exit

export RelttPath="/Users/christopherclement/Desktop/QSRLang/QSR_Lang/"
export PATH="$RelttPath/bin:$PATH"");

"""