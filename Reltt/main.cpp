#include "includes/Reltt.hpp"
#include "includes/info.hpp"
//   ___       __   _______           ___       ___  ___  __    _______           ________  ________  ________  ___  ___          ________  ________  _________  ________
//  |\  \     |\  \|\  ___ \         |\  \     |\  \|\  \|\  \ |\  ___ \         |\   __  \|\   ____\|\   ____\|\  \|\  \        |\   __  \|\   __  \|\___   ___|\   ____\
//  \ \  \    \ \  \ \   __/|        \ \  \    \ \  \ \  \/  /|\ \   __/|        \ \  \|\  \ \  \___|\ \  \___|\ \  \ \  \       \ \  \|\  \ \  \|\  \|___ \  \_\ \  \___|_
//   \ \  \  __\ \  \ \  \_|/__       \ \  \    \ \  \ \   ___  \ \  \_|/__       \ \   __  \ \_____  \ \  \    \ \  \ \  \       \ \   __  \ \   _  _\   \ \  \ \ \_____  \
//    \ \  \|\__\_\  \ \  \_|\ \       \ \  \____\ \  \ \  \\ \  \ \  \_|\ \       \ \  \ \  \|____|\  \ \  \____\ \  \ \  \       \ \  \ \  \ \  \\  \|   \ \  \ \|____|\  \
//     \ \____________\ \_______\       \ \_______\ \__\ \__\\ \__\ \_______\       \ \__\ \__\____\_\  \ \_______\ \__\ \__\       \ \__\ \__\ \__\\ _\    \ \__\  ____\_\  \
//      \|____________|\|_______|        \|_______|\|__|\|__| \|__|\|_______|        \|__|\|__|\_________\|_______|\|__|\|__|        \|__|\|__|\|__|\|__|    \|__| |\_________\
//                                                                                            \|_________|                                                         \|_________|
//
//
int main(int argc, char **argv)
{
    cout << "---------Reltt_Lang---------" << endl;
    /*while(true){
    cin>>ch;
    //cout<<ch;
    }*/
    string logo="""                                                              ,,\n"
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
                "    """;
    string error_message=""" ________  ________  _____ ______   _______  _________  ___  ___  ___  ________   ________     \n"
                         "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\|\\___   ___|\\  \\|\\  \\|\\  \\|\\   ___  \\|\\   ____\\    \n"
                         "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/\\|___ \\  \\_\\ \\  \\\\\\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\___|    \n"
                         " \\ \\_____  \\ \\  \\\\\\  \\ \\  \\\\|__| \\  \\ \\  \\_|/__  \\ \\  \\ \\ \\   __  \\ \\  \\ \\  \\\\ \\  \\ \\  \\  ___  \n"
                         "  \\|____|\\  \\ \\  \\\\\\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\  \\ \\  \\ \\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\ \n"
                         "    ____\\_\\  \\ \\_______\\ \\__\\    \\ \\__\\ \\_______\\  \\ \\__\\ \\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\\n"
                         "   |\\_________\\|_______|\\|__|     \\|__|\\|_______|   \\|__|  \\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\n"
                         "   \\|_________|                                                                                \n"
                         "                                                                                               \n"
                         "                                                                                               \n"
                         " ___       __   _______   ________   _________                                                 \n"
                         "|\\  \\     |\\  \\|\\  ___ \\ |\\   ___  \\|\\___   ___\\                                               \n"
                         "\\ \\  \\    \\ \\  \\ \\   __/|\\ \\  \\\\ \\  \\|___ \\  \\_|                                               \n"
                         " \\ \\  \\  __\\ \\  \\ \\  \\_|/_\\ \\  \\\\ \\  \\   \\ \\  \\                                                \n"
                         "  \\ \\  \\|\\__\\_\\  \\ \\  \\_|\\ \\ \\  \\\\ \\  \\   \\ \\  \\                                               \n"
                         "   \\ \\____________\\ \\_______\\ \\__\\\\ \\__\\   \\ \\__\\                                              \n"
                         "    \\|____________|\\|_______|\\|__| \\|__|    \\|__|                                              \n"
                         "                                                                                               \n"
                         "                                                                                               \n"
                         "                                                                                               \n"
                         " ___       __   ________  ________  ________   ________                                        \n"
                         "|\\  \\     |\\  \\|\\   __  \\|\\   __  \\|\\   ___  \\|\\   ____\\                                       \n"
                         "\\ \\  \\    \\ \\  \\ \\  \\|\\  \\ \\  \\|\\  \\ \\  \\\\ \\  \\ \\  \\___|                                       \n"
                         " \\ \\  \\  __\\ \\  \\ \\   _  _\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\  ___                                     \n"
                         "  \\ \\  \\|\\__\\_\\  \\ \\  \\\\  \\\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\|\\  \\                                    \n"
                         "   \\ \\____________\\ \\__\\\\ _\\\\ \\_______\\ \\__\\\\ \\__\\ \\_______\\                                   \n"
                         "    \\|____________|\\|__|\\|__|\\|_______|\\|__| \\|__|\\|_______|                                   """;
    try

    {Reltt_Info();
        char *argcv[3];
        if (argc == 1)
        {
            cout<<YELLOW<<"""\n"
                          "░██████╗░░██████╗██████╗░\n"
                          "██╔═══██╗██╔════╝██╔══██╗\n"
                          "██║██╗██║╚█████╗░██████╔╝\n"
                          "╚██████╔╝░╚═══██╗██╔══██╗\n"
                          " ░╚═██╔═╝░██████╔╝██║░░██║\n"
                          " ░░░╚═╝░░░╚═════╝░╚═╝░░╚═╝"""<<RESET<<endl;





            string command = "";
            string buffer = "";
            Reltt_INT *Args = new Reltt_INT();
            //cout<<BLUE<<error_message<<RESET<<endl;
            cout <<BOLDRED<<"R̳e̳l̳t̳t̳"<<CYAN<<" ~>"<<RESET;
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