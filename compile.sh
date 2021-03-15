g++ Reltt/main.cpp -o Reltt/OBJ/main.o -c -w -std=c++17
g++ Reltt/Reltt.cpp -o Reltt/OBJ/Reltt.o -c -w -std=c++17
mkdir Reltt/cache
g++ Reltt/OBJ/Reltt.o Reltt/OBJ/main.o -o Reltt/bin/Reltt -std=c++17
