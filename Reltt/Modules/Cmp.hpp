#ifndef CMP_HPP
#define CMP_HPP 1
#include "../includes/Reltt.hpp"
void *Compile_Reltt(Reltt_INT *IN)
{

    string Appname = getenv("APPNAME");
    string Fname = getenv("MainFile");
    cout<<"Building "<<Appname<<" with main file "<<Fname<<endl;
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
                //int wasusing=0;
                if (strcmp(v[i].c_str(), ""))
                {
                    if (strcmp(v[i].c_str(),"using")==0){
                        string j=v[i+1];
                        //cout<<"using:"<<j<<endl;
                        ifstream SrcS(IN->get_fileOBJ(j));
                        if (SrcS) {
                            //cout << "Isfile" << endl;
                            string CodeS;

                            int SG = 0;
                            int sk = 0;
                            vector<std::string> vB;

                            while (getline(SrcS, CodeS)) {
                                SG++;
                                std::vector<std::string> vS;
                                //cout << CodeS << endl;
                                split(CodeS, vS, ' ');
                                sk += v.size();
                                vB.insert(vB.end(), vS.begin(), vS.end());

                                //this->argc++;

                                //cout << Code<<endl;
                            }
                            //cout << "Importing for real:" << endl;
                            CodeH.insert(CodeH.begin() + i + 1, vB.begin() + 1, vB.end() - 1);
                           i++;

                        }}
                        else {
                        CodeH.push_back(v[i].c_str());
                    }
                    //cout<<v[i]<<endl;
                    //this->argc++;

                //this->lines.push_back(SG);
            }
        }
    }
    }


    ofstream myfile;

    string fileout ="cache/";
    //system(((string)"mkdir ").append(fileout).c_str());
    fileout.append(Appname).append("-OBJ.cpp");
    myfile.open(fileout.c_str());

    myfile << "#include \"includes/Reltt.hpp\"\n";

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
    myfile << "\n\tReltt_INT *i =new Reltt_INT(" << Appname << "_size," << Appname << "_Code);\n\t	for (int ij=0;ij<Aargc;ij++){\t i->charstr--; i->New_Var(Value(\"argv-\"+to_string(ij),Aargv[ij],\"string\"),0);i->charstr++;}\n\ti->Parse();\n\treturn 0;\n}\n";
    myfile << "\n";
    string CompileCommand = ((string) "g++ -w -std=c++17 -I$RelttPath -c ").append("cache/").append(Appname).append("-OBJ.cpp");
    CompileCommand.append(" -o ").append("cache/").append(Appname).append("-OBJ.o");

    myfile.close();
    //cout<<CompileCommand<<endl;
    int didobj = system(CompileCommand.c_str());
    if (didobj != 0)
    {
        cout<<"Unknown error"<<endl;
        remove(((string)"bin"+Appname).c_str());
    }
    else
    {
        string linking = ((string) "g++ -std=c++17 ").append(getenv("RelttPath")).append("OBJ/Reltt.o ");

        linking.append("cache/").append(Appname).append("-OBJ.o -o" ).append("bin/").append(Appname);
        int did_link =system(linking.c_str());
        if (did_link==0){
            cout << BLUE << Appname << GREEN << " created att: \"" << BOLDBLUE<<"bin/" << Appname << RESET << GREEN << "\"" << endl;
        }
        else{
            cout<<BOLDRED<<"[ERROR] Reltt Core is not compiled!"<<RESET<<endl;
            exit(0);
        }
    }

}
void *set_Main(Reltt_INT *IN){
    string i=IN->getVar(resolve_parentensis(IN)->S_value).S_value;
    setenv("MainFile",i.c_str(),1);

}
void *set_Name(Reltt_INT *IN){
    string i=resolve_parentensis(IN)->S_value;
    setenv("APPNAME",i.c_str(),1);
}
void *add_File(Reltt_INT*IN){
    string i=resolve_parentensis(IN)->S_value;

}
void *set_output(Reltt_INT *IN){
    string i=IN->getVar(IN->get_Next_Token()).S_value;
    setenv("OUTPUTPATH",i.c_str(),1);
}
void *Setup(Reltt_INT *IN){
    system("mkdir cache");
    system("mkdir bin");
}
void *clean_up(Reltt_INT *IN)
{
    string Appname = getenv("APPNAME");
    string fileout = "cache/";
    fileout.append(Appname).append("-OBJ.cpp");
    remove(fileout.c_str());
    fileout = "cache/";
    fileout.append(Appname).append("-OBJ.o");
    remove(fileout.c_str());
}
void* run(Reltt_INT *IN){
    string appname=getenv("APPNAME");
    string cmd=((string)"./bin/").append(appname);
    system(cmd.c_str());
}
Reltt_INT::QSRcModule Compilator()
{
    Reltt_INT::QSRcModule M;
    M.Set_Name("Compilator");
    M.add_Cask("Set_Main", "set Main_executable for project", &set_Main);
    M.add_Cask("Set_Name", "", &set_Name);
    M.add_Cask("Set_output_Path", "", &set_output);
    M.add_Cask("Compile", " [exe_name] scriptpath ", &Compile_Reltt);
    M.add_Cask("add_file", " [exe_name] ", &add_File);
    M.add_Cask("Clean", "Clean OBJ for compilation require Set_Name ", &clean_up);
    M.add_Cask("Setup", "setup OBJ for compilation require Set_Name ", &Setup);
    M.add_Cask("Run", "run Main_executable", &run);
    return M;
}

#endif