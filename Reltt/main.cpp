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
            cout<<YELLOW<<""" _______ _______ _   _________________     _ _______    _______    _______ _   \n"
                          "(  ____ |  ____ ( \\  \\__   __|__   __/    / |  ___  )  (  ____ \\  (  ____ | \\  \n"
                          "| (    )| (    \\/ (     ) (     ) (      / /| (   ) |  | (    \\/  | (    )|\\ \\ \n"
                          "| (____)| (__   | |     | |     | |     ( ( | |   | |  | (_____   | (____)| ) )\n"
                          "|     __)  __)  | |     | |     | |     | | | |   | |  (_____  )  |     __) | |\n"
                          "| (\\ (  | (     | |     | |     | |     ( ( | | /\\| |        ) |  | (\\ (    ) )\n"
                          "| ) \\ \\_| (____/\\ (____/\\ |     | |      \\ \\| (_\\ \\ |  /\\____) |  | ) \\ \\__/ / \n"
                          "|/   \\__(_______(_______)_(     )_(       \\_|____\\/_)  \\_______)  |/   \\__(_/  """<<RESET<<endl;





            string command = "";
            string buffer = "";
            Reltt_INT *Args = new Reltt_INT();
            //Args->New_Var(Value("RelttPath",getenv("RelttPath"),"string"),0);
            //cout<<BLUE<<error_message<<RESET<<endl;
            //cout <<RED<<"╚═"<<CYAN<<"#"<<RESET;
            printer P =printer(getenv("USER"),"Reltt_Shell");
            P.B_cin();
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

                //cout<<GREEN<<"╔═"<<RED<<"("<<BLUE<<"RELTT_INFO"<<RED<<")\n"<<GREEN<<"╚═["<<RESET;
                Args->Parse();
                //cout<<GREEN<<"\r]"<<RESET<<endl;
                buffer = "as: ";
                //cout<<RED<<"╔══("<<BLUE<<"Reltt"<<RED<<")🪢["<<getenv("USER")<<"]"<<endl;
                //cout <<RED<<"╚═"<<CYAN<<"#"<<RESET<<BLUE;
                P.B_cin();
                }

        }
        else
        {   argcv[0] = "begin:";
            argcv[1] = "-RlS";
            //char *ijk=(char *)TT.get_fileOBJ().c_str();
            string k=argv[1];
            string SKN=argv[1];
            SKN.pop_back();
            SKN.pop_back();
            SKN.pop_back();
            SKN.pop_back();
            if(strcmp(k.c_str(),SKN.append(".RlS").c_str())==0 ){

            }
            else{
                SKN=k.append(".RlS");
                //IN->p.begin_info();
                //IN->p.print_info("importing "+SKN);
                //IN->p.end_info();
            }
            Reltt_INT TT=Reltt_INT();
            char *ijk=(char *)SKN.c_str();
            argcv[2] = ijk;
            //delete &TT;

            cout << argcv[1] << " | " << argcv[2] << endl;
            Reltt_INT *Args = new Reltt_INT(3, argcv);
            for(int i=2;i<argc;i++){
            string vname="arg";
            vname.append(to_string(i-1));
            Value*v=new Value(vname,argv[i],"string");
            Args->New_Var(v,0);
            
            }
            Value*v=new Value("argc",to_string(argc-2),"int");
            Args->New_Var(v,0);
            Args->Parse();
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