#ifndef Generator_hpp
#define Generator_hpp 1
#include "../includes/Mods.hpp"
#include <sstream>
using namespace std;

void *Gen_Help(Reltt_INT *IN)
{IN->p.begin_info();
stringstream ssd2;


    ssd2 << GREEN << "Reltt C++ Modules: (" << IN->QS.size() + 1 << "):" << RESET;
    IN->p.print_info(ssd2.str());
    vector<string> VOM;
    ofstream myfile;
    string Pathtohelp=(string)getenv("RelttPath")+(string)"RlS/help.RlS";
    myfile.open(Pathtohelp);
    myfile << "Begin:\n";
    myfile << "-help Base\n";
    cout << GREEN << "│\tModule\t" << BLUE << "Base (Reltt)" << RESET << GREEN << "\tWith " << BOLDBLUE << IN->__Tasks.size() << RESET << GREEN << " Functions" << endl;
    int Functions = IN->__Tasks.size();
    for (int i = 0; i < IN->QS.size(); i++)
    {
        cout << "│\tModule\t" << BLUE << IN->QS[i].Module_Name << RESET << GREEN << "\tWith " << BOLDBLUE << IN->QS[i].__Tasks.size() << RESET << GREEN << " Functions";
        Functions += IN->QS[i].__Tasks.size();
        VOM.push_back(IN->QS[i].Module_Name.c_str());
        myfile << "-help " << IN->QS[i].Module_Name.c_str() << "\n";
    }
    std::stringstream ssd;
    ssd << "Total of:\t" << BOLDBLUE << IN->QS.size() + 1 << RESET << GREEN << " Modules and " << BOLDBLUE << Functions << " Functions" << RESET;
    IN->p.print_info(ssd.str());

    myfile << "end;";

    myfile.close();
}
void *As_Native(Reltt_INT *IN)
{


    string Appname = IN->getVar(IN->get_Next_Token())->S_value.c_str();
    string Fname = IN->getVar(IN->get_Next_Token())->S_value.c_str();
    ifstream Src(IN->get_fileOBJ(Fname));
    //cout<<Appname<<IN->StackPointer<<endl;
    string Code;
    vector<string> CodeH;
    if (Src)
    {
        while (getline(Src, Code))
        {
            //SG++;
            std::vector<std::string> v;
            split(Code, v, ' ');

            //cout << Code<<endl;
            int k = v.size();
            for (int i = 0; i < k; i++)
            {
                if (strcmp(v[i].c_str(), ""))
                {
                    CodeH.push_back(v[i].c_str());
                    //this->argc++;
                }
                //this->lines.push_back(SG);
            }
        }
    }


    ofstream myfile;
    string fileout = getenv("RelttPath") + (string) "cache/";
    //system(((string)"mkdir ").append(fileout).c_str());
    fileout.append(Appname).append("-OBJ.cpp");
    myfile.open(fileout.c_str());

    myfile << "#include \"../includes/Reltt.hpp\"\n";

    string ilegalchar = "\\\"\'";
    myfile << "int main(int Aargc,char** Aargv){\n";
    myfile << "char *" << Appname << "_Code[] = {";

    for (int i = 0; i < CodeH.size(); i++)
    {
        string code = "\"";
        for (int j = 0; j < CodeH[i].size(); j++)
        {
            //code+="\"";
            bool wasit = 0;
            string nextcharT = CodeH[i];
            string buffer;
            for (int k = 0; k < ilegalchar.size(); k++)
            {
                if ((int)nextcharT[j] == (int)ilegalchar[k])
                {
                    code += "\\";
                    code += nextcharT[j];
                    wasit = 1;
                }
            }
            if (!wasit)
            {
                code += nextcharT[j];
            }
        }

        code += "\"";
        if (i + 1 == CodeH.size())
        {
        }
        else
        {
            code += ",";
        }
        //cout<<code<<endl;
        myfile << code;
    }
    string RP = getenv("RelttPath");
    //RP.pop_back();
    myfile << "};\nint " << Appname << "_size=" << CodeH.size() << ";";
    myfile << "\n\tReltt_INT *i =new Reltt_INT(" << Appname << "_size," << Appname << "_Code);\n\t	for (int ij=0;ij<Aargc;ij++)\ti->New_Var(new Value(\"argv-\"+to_string(ij),Aargv[ij],\"string\"),0);\n\ti->Parse();\n\treturn 0;\n}\n";
    myfile << "\n";
    string CompileCommand = ((string) "g++ -w -std=c++17 -c ").append(getenv("RelttPath")).append("cache/").append(Appname).append("-OBJ.cpp");
    CompileCommand.append(" -o ").append(getenv("RelttPath")).append("cache/").append(Appname).append("-OBJ.o");

    myfile.close();
}
void *Gen_App(Reltt_INT *IN)
{
    ifstream Src(IN->getVar(IN->getnextIns())->S_value.c_str());
    string Appname = IN->getVar(IN->getnextIns())->S_value.c_str();
    string Code;
    vector<string> CodeH;
    while (getline(Src, Code))
    {
        //SG++;
        std::vector<std::string> v;
        split(Code, v, ' ');

        //cout << Code<<endl;
        int k = v.size();
        for (int i = 0; i < k; i++)
        {
            if (strcmp(v[i].c_str(), ""))
            {
                CodeH.push_back(v[i].c_str());
                //this->argc++;
            }
            //this->lines.push_back(SG);
        }
    }

    ofstream myfile;
    string fileout = "QSR/APPs/";
    fileout.append(Appname).append(".hpp");
    myfile.open(fileout.c_str());

    myfile << "#ifndef " << Appname << "_hpp\n#define " << Appname << "_hpp\n#include \"../includes/Reltt.hpp\"\n";

    string ilegalchar = "\\\"\'";
    myfile << "\napp APP_" << Appname << "(){\n";
    myfile << "char *" << Appname << "_Code[] = {";

    for (int i = 0; i < CodeH.size(); i++)
    {
        string code = "\"";
        for (int j = 0; j < CodeH[i].size(); j++)
        {
            //code+="\"";
            bool wasit = 0;
            string nextcharT = CodeH[i];
            string buffer;
            for (int k = 0; k < ilegalchar.size(); k++)
            {
                if ((int)nextcharT[j] == (int)ilegalchar[k])
                {
                    code += "\\";
                    code += nextcharT[j];
                    wasit = 1;
                }
            }
            if (!wasit)
            {
                code += nextcharT[j];
            }
        }

        code += "\"";
        if (i + 1 == CodeH.size())
        {
        }
        else
        {
            code += ",";
        }
        //cout<<code<<endl;
        myfile << code;
    }

    myfile << "};\nint " << Appname << "_size=" << CodeH.size() << ";\n app APP_" << Appname << "=app(\"" << Appname << "\"," << Appname << "_size ," << Appname << "_Code);\n";
    myfile << "\n\treturn APP_" << Appname << ";\n\t}\n";
    myfile << "\n#endif";
    /*add shit to shit
    myfile.open("QSR/ConstArgv.hpp",std::ios::app);
    myfile<<"#include \""<<fileout<<"\"\n";
    myfile.close();*/
}
void *clean(Reltt_INT *IN)
{
    string Appname = resolve_parentensis(IN)->S_value;
    string fileout = "";
    fileout.append(Appname).append("-OBJ.cpp");
    remove(fileout.c_str());
    fileout = "";
    fileout.append(Appname).append(".o");
    remove(fileout.c_str());
}

Reltt_INT::QSRcModule Generator()
{
    Reltt_INT::QSRcModule M;
    M.Set_Name("Generator");
    M.add_Cask("Gen_Help", "Gen helper", &Gen_Help);
    M.add_Cask("Gen_APP", "", &Gen_App);
    M.add_Cask("As_Native", " [exe_name] scriptpath ", &As_Native);
    M.add_Cask("Clean", " [exe_name] ", &clean);
    return M;
}

#endif