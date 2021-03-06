#include "includes/Reltt.hpp"
#include "includes/info.hpp"
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

            cout <<BOLDRED<<"Reltt"<<CYAN<<" ~>"<<RESET;
            while (getline(cin, buffer))

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