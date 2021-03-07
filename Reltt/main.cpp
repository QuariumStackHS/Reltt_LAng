#include "includes/Reltt.hpp"
#include <iomanip>
#include <unistd.h>
#include <termios.h>
#define BACKSPACE 127
#define SPACE 32
#define ENTER 10
#define ctrlA 1
#define ctrlB 2
#define ctrlD 4
#define CTRLE 5
#define CTRLF 6
#define CTRLG 7
#include "includes/info.hpp"
char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}
string getline(){
    string BF;
    for(int i=getch();(char)i!=(char)ENTER;i=getch()){
        BF.push_back((char)i);
    }
    return BF;


}
int main(int argc, char **argv)
{
    cout << "---------Reltt_Lang---------" << endl;
    /*while(true){
    cin>>ch;
    //cout<<ch;
    }*/
    try
    {Reltt_Info();
        char *argcv[3];
        if (argc == 1)
        {
            cout<<BOLDRED<<"""                                                              ,,\n"
                  "                                                           -#M=5@@%-\n"
                  "                                                       ,#@=====55MMMM@m,\n"
                  "                                                   .-@M========55MMMMMMM@@Q,\n"
                  "                                               ,-#M============55MMMMMMMMMMM@@g,\n"
                  "                                            -#M================55MMMMMMMMMMMMMMM@#\n"
                  "                                            7==================55MMMMMMMMMMM@@=\"\n"
                  "                                            7==================55MMMMMMMM@=`\n"
                  "                                            7==================55MMMM@=\"\n"
                  "                                            7==================55@M\"\n"
                  "                                            7==================\"`\n"
                  "                     ,==[===                7===============\",,\n"
                  "                 ,==,-\"\"\"\"\"\"-==,            7===========\"\",,,,,\n"
                  "             ,-=,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-==,        7=======\"\",,,,,,,,,\n"
                  "          ===\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-,==,    7===\"\",,,,,,,,,,,,,\n"
                  "      -==-\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\",== 7\",,,,,,,,,,,,,,,,,\n"
                  "        \"\"=-\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"=`,,,,,,,,,,,,,\n"
                  "            `=[\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"=`,,,,,,,,,,\n"
                  "                \"=-\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-\"\"=``,,,,,\n"
                  "                   `\"=\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-\"\"=`,,\n"
                  "                       `\"=,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"-\"\"\n"
                  "                           `=,\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"=`\n"
                  "                               \"==\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"[=\"\n"
                  "                                   \"=-\"\"\"\"\"\"\"\"\"\"\"\"-\"`\n"
                  "                                       \"=[\"\"\"\"\"=\"`\n"
                  "                                           \"=`\n"
                  "    """<<RESET<<endl;

            string command = "";
            string buffer = "";
            Reltt_INT *Args = new Reltt_INT();

            cout <<BOLDRED<<"Reltt DS"<<CYAN<<" ~>"<<RESET;
            for(string k=getline();)

            {vector<string> argvz;
                //cout << "eareaing vector:" << endl;
                //argvz->clear();
                //cout << "eareaing vector: √" << endl;
                //cin >> argvz;

                //cout << "Splitting" << endl;
                //cout << "splitting vector:" << endl;
                buffer=((string)"as: ").append(buffer);
                split(buffer, argvz, ' ');

                //char **argvY;
                //cout << "splitting vector:√" << endl;
                //cout << "going to make args char**" << endl;
                //cout << argvz.size()<< endl;
                //cout << "PAssing vector:" << endl;
                Args->AddVector(argvz.size(), argvz);
                //cout << "PAssing vector:√" << endl;


                Args->Parse();
                buffer = "as: ";
                cout <<BOLDRED<<"Reltt"<<CYAN<<" ~>"<<RESET<<BLUE;            }
        }
        elif (argc == 2)
        {
            argcv[0] = "begin:";
            argcv[1] = "-RlS";
            argcv[2] = argv[argc - 1];
            cout << argcv[1] << " | " << argcv[2] << endl;
            Reltt_INT Args = Reltt_INT(3, argcv);

            Args.Parse();
        }
        else
        {
            //cout<<"Run try"<<endl;
            //cout << argc << endl;
            Reltt_INT Args = Reltt_INT(argc, argv);
            //cout<<"ARGC: "<<argc<<endl;
            Args.Parse();
        }
        char ch;
        //cin >> ch;
        //Args.Update();
    }
    catch (const std::exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}