//
// Created by Christopher Clement on 2021-03-07.
//

#include "Ide.h"
#include <iostream>


#include <vector>
#include <string>
#include "../Reltt/includes/Reltt.hpp"
#include <iomanip>
#include <unistd.h>
#include <termios.h>
using namespace std;
#define BACKSPACE 127
#define SPACE 32
#define ENTER 10
#define ctrlA 1
#define ctrlB 2
#define ctrlD 4
#define CTRLE 5
#define CTRLF 6
#define CTRLG 7


int main(){
    //vector<string> Buffer;
    Reltt_INT *RI= new Reltt_INT();
    char lastchar='0';
    int j=0;
    for(int i=0;lastchar!='\n';i++) {
        vector<string> Buffer;
        Buffer.push_back("as:");
        string last_word = "";
        while (lastchar != ENTER) {
            char lastchar=getch();
            if (lastchar == SPACE) {
                Buffer.push_back(last_word);
                cout<<" "

            } else {
                cout<<lastchar;
                //cout<<(int)lastchar<<endl;
                last_word.push_back(lastchar);
            }


        }
        cout<<endl<<Buffer.size();
        RI->AddVector(Buffer.size(),Buffer);
        RI->Parse();
    }
        //Buffer[]
    for (int i=getch();i!=27;i=getch()){
        cout<<i<<endl;

    }

    return 0;
}
/*
┌─────────────────────┐
│
│
│
│
 */