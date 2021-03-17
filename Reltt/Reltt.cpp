//
// Created by Christopher Clement on 2021-03-06.
//

//#include "ConstArgv.hpp"
#include "includes/Reltt.hpp"
//#include "../Cfg.hpp"
#include "cfg.hpp"
#include "Modules.hpp"
#include <filesystem>
#include <dirent.h>
#include <time.h>
#include <cstdlib>
Value resolve_parentensis(Reltt_INT *IN){
    Value token=IN->getVar(IN->get_Next_Token());
    Value cachevalue=Value("","","string");
    Value return_Value=Value("","","string");
    int par=0;
    bool isfirst=1;
    while(par>=1 || isfirst){
        //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
        if (strcmp(token.S_value.c_str()," ")==0){
            cachevalue.S_value.append(" ");
        }
        if (strcmp(token.S_value.c_str(),"+")==0) {
            //cout<<"Plus"<<endl;

            token = IN->getVar(IN->get_Next_Token());
            if (strcmp(token.S_value.c_str()," ")==0){
                cachevalue.S_value =cachevalue.S_value.append(" ");
            }
            if (strcmp(token.T_R.c_str(), "string") == 0) {
                cachevalue.S_value = cachevalue.S_value.append(token.S_value);
                cachevalue = Value(cachevalue.v_Name, cachevalue.S_value, "string");
            } else {
                cachevalue.I_value = cachevalue.I_value + token.I_value;
                cachevalue.F_value = cachevalue.F_value + token.F_value;
                cachevalue.S_value = to_string(cachevalue.F_value);
                cachevalue.T_R = "float";
            }
        }
        elif (strcmp(token.S_value.c_str(),"-")==0){
            //cout<<"Plus"<<endl;

            token=IN->getVar(IN->get_Next_Token());

            if(strcmp(token.T_R.c_str(),"string")==0){
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue.I_value = cachevalue.I_value-i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator - is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator - is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue.F_value = cachevalue.F_value-i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator - is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator - is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");

            }
            else{
                cachevalue.I_value=cachevalue.I_value-token.I_value;
                cachevalue.F_value=cachevalue.F_value-token.F_value;
                cachevalue.S_value=to_string(cachevalue.F_value);
                cachevalue.T_R="float";
            }
        }
        elif (strcmp(token.S_value.c_str(),"/")==0){
            //cout<<"divide"<<endl;

            token=IN->getVar(IN->get_Next_Token());

            if(strcmp(token.T_R.c_str(),"string")==0){
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue.I_value = cachevalue.I_value/i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator / is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator / is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue.F_value = cachevalue.F_value/i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator / is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator / is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");

            }
            else{
                cachevalue.I_value=cachevalue.I_value/token.I_value;
                cachevalue.F_value=cachevalue.F_value/token.F_value;
                cachevalue.S_value=to_string(cachevalue.F_value);
                cachevalue.T_R="float";
            }
        }
        elif (strcmp(token.S_value.c_str(),"*")==0){
            //cout<<"multiply"<<endl;

            token=IN->getVar(IN->get_Next_Token());

            if(strcmp(token.T_R.c_str(),"string")==0){
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue.I_value = cachevalue.I_value*i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator * is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator * is not available for strings"<<endl;
                    cachevalue.I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue.F_value = cachevalue.F_value*i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {cout<<"operator * is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {cout<<"operator * is not available for strings"<<endl;
                    cachevalue.F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");

            }
            else{
                cachevalue.I_value=cachevalue.I_value*token.I_value;
                cachevalue.F_value=cachevalue.F_value*token.F_value;
                cachevalue.S_value=to_string(cachevalue.F_value);
                cachevalue.T_R="float";
            }
        }
        elif(strcmp(token.S_value.c_str(),"&&")==0){
            cout<<cachevalue.B_value;
            token=IN->getVar(IN->get_Next_Token());

            cachevalue.B_value=(cachevalue.F_value&&token.F_value)||(cachevalue.I_value&&token.I_value);
        }
        elif(strcmp(token.S_value.c_str(),"||")==0){
            cout<<cachevalue.B_value;
            token=IN->getVar(IN->get_Next_Token());

            cachevalue.B_value=(cachevalue.F_value||token.F_value);
        }
        elif(strcmp(token.S_value.c_str(),"==")==0){
            token=IN->getVar(IN->get_Next_Token());
            cachevalue.B_value=(strcmp(cachevalue.S_value.c_str(),token.S_value.c_str())==0);
        }
        elif(strcmp(token.S_value.c_str(),"!=")==0){
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            token=IN->getVar(IN->get_Next_Token());
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            cachevalue.B_value=(strcmp(cachevalue.S_value.c_str(),token.S_value.c_str()));
            //cout<<cachevalue.B_value<<endl;
            //cachevalue.S_value=to_string(cachevalue.B_value);
        }
        elif(strcmp(token.S_value.c_str(),"(")==0){
            if (par){
                cachevalue=resolve_parentensis(IN);
            }else{
            par++;
            }

        }
        elif(strcmp(token.S_value.c_str(),")")==0){
            par--;
            if (par==0){
                return_Value=cachevalue;
                //cout<<"return fast"<<endl;
                return return_Value;
            }
        }
        elif (isfirst){
            //cout<<"Reterning"<<token.S_value<<endl;
            return IN->getVar(token.S_value);
        }
        elif (par==0)
        {
            return_Value=IN->getVar(cachevalue.S_value);
            //cout<<"return laster"<<return_Value.v_Name<<endl;
            return return_Value;
        }
        else{
            cachevalue=IN->getVar(token.v_Name);;
        }
        isfirst=0;

        token=IN->getVar(IN->get_Next_Token());

    }
    //cout<<"Reterning after: "<<return_Value.S_value<<endl;
    return return_Value;

}
void * Sleeper(Reltt_INT *IN){
    char s;
    cin>>s;
    //wait(resolve_parentensis(IN).I_value);
}
app::app(string name, int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        string C = argv[i];
        this->ins.push_back(C);
    }
    this->app_length = argc;
    this->app_name = name;
}
instruction::instruction(int charline, int charstr2)
{
    this->insnumber = charstr2;
    this->line = charline;
}

ArgType::ArgType(string ArgTypeD)
{
    this->ArgTyper = ArgTypeD;
}

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch)
{
    size_t pos = txt.find(ch);
    size_t initialPos = 0;
    strs.clear();

    // Decompose statement
    while (pos != std::string::npos)
    {
        strs.push_back(txt.substr(initialPos, pos - initialPos));
        initialPos = pos + 1;

        pos = txt.find(ch, initialPos);
    }

    // Add the last one
    strs.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

    return strs.size();
}
int Reltt_INT::try_task(string tname)
{
    string nullname = "";
    if (strcmp(tname.c_str(), nullname.c_str()))
    {
        for (int i = 0; i < this->__Tasks.size(); i++)
        {
            if (is_Name(this->__Tasks[i], tname))
            {
                //cout<<tname<<endl;
                auto Tadr = __Tasks[i].Taddr;
                Tadr(this);
                //cout<<tname<<"OK"<<endl;
                return 1;
            }
        }
    }
    else
    {
        return 1;
    }
    return 0;
}
Value::Value(string Name, float Value)
{this->v_Name=Name;
    this->F_value = Value;
    this->T_R = "float";
}
Value::Value(string Name, int Value)
{   this->v_Name=Name;
    this->I_value = Value;
    this->T_R = "int";
}
Value::Value(string Name, string Value, string type)
{
    //this->F_value= stof(Value);

    std::string s = Value;
    this->T_R = type;

    try
    {
        int i = std::stoi(s);
        this->I_value = i;
        //std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        this->I_value = -1;
        //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        this->I_value = -1;
        //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    try
    {
        float i = std::stof(s);
        this->F_value = i;
        //std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        this->F_value = -1;
        //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        this->F_value = -1;
        //std::cout << "Float overflow: std::out_of_range thrown" << '\n';
    }
    //this->I_value= stoi(Value.c_str());
    this->S_value = Value;
    this->v_Name = Name;
}
Reltt_INT::QSRcModule Reltt_INT::getModule(string name)
{
    for (int i = 0; i < this->QS.size(); i++)
    {
        if (strcmp(this->QS[i].Module_Name.c_str(), name.c_str()) == 0)
        {

            //auto Tadr = __Tasks[i].Taddr;
            //Tadr(this);
            return this->QS[i];
        }
    }
    QSRcModule M;
    return M;
}
string Reltt_INT::get_Next_Token()
{
    // read strings
    string next_Token = "";
    string null_Token;
    int isinstring = 0;
    int isread = 0;
    for (int i = 0; i < this->argv.size() - 2; i++)
    {
        string Word = this->getnextIns();
        bool is = ((Word[0] == '"') && (Word[Word.size() - 1] == '"') && (isinstring == 0));
        bool isnoS = ((int)Word[Word.size()] == (int)'"');
        //cout<<is<<endl;
        bool isfirst = ((Word[0] == '"') && (isinstring == 0) && (is == 0));
        //bool isMath = ((Word[0] == '(') &&(Word[g] == ')')&&(isinstring == 0) && (is == 0));
        bool islast = ((Word[Word.size() - 1] == '"') && (isinstring == 1) && (is == 0));
        bool isunique = (this->argv[charstr].size()==1)&&(this->argv[charstr+1].size()==1);
        if (isfirst)
        {
            //cout << "is first" << endl;
            for (int j = 1; j < Word.size(); j++)
            {
                next_Token.push_back(Word[j]);
            }
            next_Token.append(" ");

            isinstring = 1;
        }
        elif (isunique&&!isinstring){
            return " ";
        }
        elif ((Word[0] == '"') &&(Word.size()==1)){
            isinstring=1;
            next_Token.append(" ");
        }
        elif (islast)
        {
            string lastbuffer = "";
            for (int i = 0; i < Word.size() - 1; i++)
            {
                lastbuffer.push_back(Word[i]);
            }
            //next_Token.append(" ");
            next_Token.append(lastbuffer);
            return next_Token;
        }

        elif (is)
        {
            //cout<<Word<<endl;
            //cout << "is 'is'" << endl;
            for (int i = 1; i < Word.size() - 1; i++)
            {
                //cout<<Word[i];
                next_Token += Word[i];
            }

            //cout<<null_Token.c_str()<<endl;
            //next_Token.append(null_Token);
            return next_Token;
        }

        elif (!isinstring)
        {
            return getVar(Word).S_value;
        }

        else
        {
            next_Token.append(Word).append(" ");
        }
    }

} //private:
bool Reltt_INT::is_operator(string name)
{
    for (int i = 0; i < Operators.size() - 1; i++)
    {
        if (strcmp(Operators[i].Name.c_str(), name.c_str()) == 0)
        {
            return i;
        }
    }
    return -1;
}
int Reltt_INT::is_Func_or_var(string ins)
{
    for (int i = 0; i < __Tasks.size(); i++)
    {
        if (strcmp(__Tasks[i].Name.c_str(), ins.c_str()) == 0)
        {
            return 1;
        }
    }
    for (int i = 0; i < Math_Var[this->Math_Var.size() - 1]->localVars.size(); i++)
    {
        if (strcmp(Math_Var[this->Math_Var.size() - 1]->localVars[i]->v_Name.c_str(), ins.c_str()) == 0)
        {
            return 1;
        }
    }
    return 0;
}
using std::cin;
using std::cout;
using std::endl;
using std::vector;
/*
Args parser, analyze and execute
*/
vector<string> list_dir(string dird)
{
    DIR *dir;
    struct dirent *diread;
    vector<string> files;
    dir = dir = opendir(dird.c_str());
    if (dir != nullptr)
    {
        while ((diread = readdir(dir)) != nullptr)
        {
            files.push_back(diread->d_name);
        }
        closedir(dir);
    }
    else
    {
        perror("opendir");
        //return 0;
    }
    return files;
    //for (auto file : files) cout << file << "| ";
    //cout << endl;
}

Helper::Helper(Reltt_INT *HTL)
{
    //cout << "help" << endl;
    string Module = HTL->argv[HTL->charstr + 1];
    if (strcmp(Module.c_str(), "Base") == 0)
    {
        // Reltt_INT::QSRcModule M = HTL->;
        cout << BOLDCYAN << "┌";
        for (float i = 0; i < 11 - 4; i++)
        {
            cout << "─";
        }
        //cout
        cout << "Function────────"
             << "┬───────"
             << "Description";
        for (float i = 1; i < (HTL->Cfg.Termwidth / 2.1); i++)
        {
            cout << BOLDCYAN << "─";
        }
        cout << "┐" << RESET << endl;
        for (int i = 0; i < HTL->__Tasks.size(); i++)
        {

            cout << BOLDCYAN << "│\t" << BOLDBLUE << HTL->__Tasks[i].Name << BOLDCYAN << "\t\t|\t" << GREEN << HTL->__Tasks[i].Desk << endl;
        }
    }
    else
    {
        Reltt_INT::QSRcModule M = HTL->getModule(Module);
        if (M.__Tasks.size() == 0)
        {
            cout << "No Module named: " << Module << endl;
            exit(0);
        }
        else
        {

            cout << BOLDCYAN << "┌";
            for (float i = 0; i < 11 - 4; i++)
            {
                cout << "─";
            }
            //cout
            cout << "Function┬─Module:"
                 << M.Module_Name << "────┬───"
                 << "Description───Version:" << M.Version;
            for (float i = 1; i < (HTL->Cfg.Termwidth / 2.7); i++)
            {
                cout << BOLDCYAN << "─";
            }
            cout << "┐" << RESET << endl;
            for (int i = 0; i < M.__Tasks.size(); i++)
            {

                cout << BOLDCYAN << "│\t" << BOLDBLUE << M.__Tasks[i].Name << BOLDCYAN << "\t|" << MAGENTA << M.Module_Name << BOLDCYAN << "\t\t|\t" << GREEN << M.__Tasks[i].Desk << endl;
                /*for (float i = 0; i < HTL->Cfg.Termwidth + (strlen(HTL->__Tasks[i].Name.c_str()) - strlen("|\t\t|\t") - strlen(HTL->__Tasks[i].Desk.c_str()) / 2); i++)
        {
            cout << " ";
        }*/
                //cout << "│" << endl;
            }
        }
    }
    cout << BOLDCYAN << "└";
    for (float i = 1; i < (HTL->Cfg.Termwidth + 4); i++)
    {
        cout << BOLDCYAN << "─";
    }
    cout << "┘" << endl;
    HTL->charstr++;
    //exit(0);
}
int Reltt_INT::newFunc(string funcName, int line, int endline, vector<ArgType> AG)
{
    UD_Function F = UD_Function(funcName, line, endline);
    for (int i = 0; i < AG.size(); i++)
    {
        F.ArgsT.push_back(AG[i]);
    }
    this->Functions.push_back(F);
    /*this->FuncName.push_back(funcName);
    //this->FuncStackP.push_back(StackP);
    this->End_line.push_back(endline);
    this->Begin_Line.push_back(line);
    //this->Func*/
    //this->FuncSrc.push_back(funcSrc);
    //cout<<"attempting to Create function: "<<funcName<<" | "<<funcCode<<endl;
    this->NextFNCID++;

    return this->NextFNCID;
}
int Reltt_INT::executeFunc(string tFuncName)
{
    for (int i = 0; i < this->NextFNCID; i++)
    {
        if (strcmp(tFuncName.c_str(), this->Functions[i].FuncName.c_str()) == 0)
        {
            int oldCharstr = this->charstr;
            this->charstr = this->charstr = this->Functions[i].BeginLine;
            this->Parse();
            this->charstr = oldCharstr;

            //std::__1::vector<std::__1::string>::iterator it = this->argv.begin();
            //vector<string> Ins;
            //split(this->FuncCode[i], Ins, ' ');

            //for (int j = 2; j < Ins.size(); j++)
            //{
            //this->argc++;
            //this->argv.insert(it + charstr + j, Ins[j]);
            //vector<int>::iterator itL = this->lines.begin();
            //this->lines.insert(itL + charstr + j, 0);
            //}
        }
    }
    return 0;
}
int Reltt_INT::DeleteVar(string varname)
{
    for (int k = 0; k <= StackPointer - 1; k++)
    {
        for (int i = 0; i < Math_Var[k]->localVars.size(); i++)
        {
            if (strcmp(this->Math_Var[k]->localVars[i]->v_Name.c_str(), varname.c_str()) == 0)
            {
                Math_Var[k]->localVars.erase(Math_Var[k]->localVars.begin() + i);
            }
        }
    }
    return 0;
}
Value Reltt_INT::getVar(string varname)
{//this->StackPointer++;
    //cout <<"is?"<< varname << endl;
    for (int k = 0; k <= StackPointer; k++)
    {
        for (int i = 0; i < this->Math_Var[k]->localVars.size(); i++)
        {
            //cout << varname << i << endl;
            //cout<<this->vars[i+1]<<"?"<<endl;
            if (strcmp(this->Math_Var[k]->localVars[i]->v_Name.c_str(), varname.c_str()) == 0)
            {
                Value E = *this->Math_Var[k]->localVars[i];
                //cout<<"[DEBUG]"<<this->Math_Var[StackPointer]->localVars[i]->v_Name<<" V: "<<this->Math_Var[StackPointer]->localVars[i]->S_value<<endl;
                return E;
            }
        }
    }
   Value v= Value(varname, varname, "string");
    try
    {
        int i = std::stoi(v.S_value);
        //cachevalue.I_value = cachevalue.I_value-i;
        v.T_R="int";
        //std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {//cout<<"operator - is not available for strings"<<endl;
        //cachevalue.I_value = -1;
        //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {//cout<<"operator - is not available for strings"<<endl;
        //cachevalue.I_value = -1;
        //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    try
    {
        float i = std::stof(v.S_value);
        v.T_R="float";
        //cachevalue.F_value = cachevalue.F_value-i;
        //std::cout << i << '\n';
    }
    catch (std::invalid_argument const &e)
    {
        //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
    }
    catch (std::out_of_range const &e)
    {
        //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
    }
    //this->StackPointer--;
    return v;

}

int Reltt_INT::runfile()
{
    string Code;
    //cout << "Riun" << endl;
    string RQFS = "-----Running Reltt Script: ";
    string SKN = getVar(getcurrentIns()).S_value;
    //cout << "Riun" << endl;
    if (this->Cfg.debug)
        cout << RQFS << RESET << RED << SKN << RESET << "-----" << endl;
    // Read from the text file
    ifstream Src(this->get_fileOBJ(getVar(getcurrentIns()).S_value.c_str()));
    charstr++;
    int SG = 0;
    while (getline(Src, Code))
    {
        SG++;
        std::vector<std::string> v;
        split(Code, v, ' ');
        //cout << Code<<endl;
        int k = v.size();
        for (int i = 0; i < k; i++)
        {
            /*if (strcmp(v[i].c_str(), ""))
            {*/
            this->argv.push_back(v[i].c_str());
            this->argc++;
            this->INSD.push_back(instruction(SG + 1, this->argc));

            /*}
            else{

            }*/

            //this->lines.push_back(SG);
        }

        if (this->Cfg.debug)
        {
            cout << BOLDGREEN << "Line: " << BOLDCYAN << SG << RESET << " \t|" << Code;
        }
        int Termwidth = this->Cfg.Termwidth - Code.size() * 2;
        for (int i = 0; i < Termwidth / 2; i++)
        {
            if (this->Cfg.debug)
                cout << " ";
        }
        if (Termwidth % 2 != 0)
        {
            if (this->Cfg.debug)
                cout << " ";
        }
        if (this->Cfg.debug)
            cout << "|" << BOLDYELLOW << ";" << RESET << endl;

        //cout << "Line: " << SG<< " " << Code << endl;
        //return 0;
    }
    if (this->Cfg.debug)
        cout << endl;
    string EOFD = "End Of File";

    int Termwidth = this->Cfg.Termwidth - EOFD.size() * 2;
    for (int i = 0; i < Termwidth / 2; i++)
    {
        if (this->Cfg.debug)
            cout << "-";
    }
    if (this->Cfg.debug)
        cout << RESET << RED << EOFD << RESET;
    for (int i = 0; i < Termwidth / 2; i++)
    {
        if (this->Cfg.debug)
            cout << "-";
    }
    if (Termwidth % 2 != 0)
    {
        if (this->Cfg.debug)
            cout << "-";
    }
    if (this->Cfg.debug)
        cout << endl
             << endl;
    // Close the file
    Src.close();
    return 0;
}
void *Run(Reltt_INT *IN)
{
    string Cmd01 = "./Build/exe/";
    string Cmd02 = IN->Cfg.ProgrameName;
    string Cmd03 = ".exe";
    string Cmd = Cmd01.append(Cmd02);
    string Cmd1 = Cmd.append(Cmd03);
    string i=((string)"Running using: \"");
    //i.append(Cmd.c_str()).append("\" | Return: ").append(system(Cmd1.c_str()));
    //IN.p.print_info(((string) ) );
    return 0;
}
void *Link(Reltt_INT *IN)
{
    string Cmd01 = "g++ Build/obj/*.QSRobj -o Build/exe/";
    string Cmd02 = IN->Cfg.ProgrameName;
    string Cmd03 = ".exe -std=c++";
    string Cmd = Cmd01.append(Cmd02);
    string Cmd1 = Cmd.append(Cmd03);
    string Cmd04 = to_string(IN->Cfg.CPPLang);
    string Cmd2 = Cmd1.append(Cmd04);
    int result = system(Cmd2.c_str());
    cout << BOLDBLUE << "Linking using: \"" << BOLDMAGENTA << Cmd2 << BLUE << "\" | Return: " << GREEN << result / 256 << RESET << endl;
    return 0;
}
/*
#define si if
#define sinon else
#define sinonsi elif
*/

void *Update(Reltt_INT *IN)
{
    if ((strcmp(IN->getcurrentIns().c_str(), "App-RCP") == 0))
    {
        string PG=getenv("RelttPath");
        IN->p.begin_info();
        IN->p.print_info("Recompiling Reltt interpreter:");
        int i = system(((string)"g++ ").append(PG).append("Reltt.cpp -std=c++17 -c -o ").append(PG).append("OBJ/Reltt.o -w").c_str());
        if (i == 0)
        {
            IN->p.print_info(((string)GREEN).append("\tCompiled ").append(BLUE).append("Reltt ").append(GREEN).append("With Return code: ").append(CYAN).append(to_string(i / 256)));

            int j = system((((string)"g++ ").append(PG).append("main.cpp -std=c++17 -c -o ").append(PG).append("OBJ/main.o -w")).c_str());
            if (j == 0)
            {
                IN->p.print_info(((string)GREEN).append("\tCompiled ").append(BLUE).append("Reltt_Main ").append(GREEN).append("With Return code: ").append(CYAN).append(to_string(j / 256)));
                j = system((((string)"g++ -std=c++17 ").append(PG).append("OBJ/Reltt.o ").append(PG).append("OBJ/main.o -o ").append(PG).append("bin/Reltt -w")).c_str());

                IN->p.print_info(((string)GREEN).append("\tLinked Reltt interpreter With Return code: ").append(to_string(j / 256)));
                //j = system("g++ -std=c++17  $RelttPath/QSR/Obj/Reltt.o $RelttPath/QSR/Obj/main.o -o $RelttPath/Reltt.app/Contents/MacOS/Reltt -w");
            }
            else
            {
                cout << BOLDRED "Error while Compiling Main_Reltt Return code: " << j / 256 << RESET << endl;
            }

            //exit(0);
        }
        else
        {
            cout << BOLDRED "Error while Compiling Reltt Return code: " << i / 256 << RESET << endl;
        }
        IN->p.end_info();
    }
    elif ((strcmp(IN->getcurrentIns().c_str(), "App-RUP") == 0))
    {
        string cloneC = "git clone https://github.com/QuariumStackHS/QSR_Lang";
        system(cloneC.c_str());
        int i = system("g++ QSR_Lang/QSR/Reltt.cpp -std=c++17 -c -o QSR/Obj/Reltt.o -w");

        if (i == 0)
        {
            cout << GREEN << "\tCompiled " << BLUE << "Reltt " << GREEN << "With Return code: " << CYAN << i / 256 << endl;

            int j = system("g++ QSR_Lang/QSR/main.cpp -std=c++17 -c -o QSR/Obj/main.o -w");
            if (j == 0)
            {
                cout << GREEN << "\tCompiled " << BLUE << "Reltt_Main " << GREEN << "With Return code: " << CYAN << j / 256 << endl;
                j = system("g++ -std=c++17 QSR/Obj/Reltt.o QSR/Obj/main.o -o QSR.E -w");
                cout << GREEN << "\tLinked " << BLUE << "Reltt interpreter " << GREEN << "With Return code: " << CYAN << j / 256 << endl;
            }
            else
            {
                cout << BOLDRED "Error while Compiling Main_Reltt Return code: " << j / 256 << RESET << endl;
            }

            //exit(0);
        }
        else
        {
            cout << BOLDRED "Error while Compiling Reltt Return code: " << i / 256 << RESET << endl;
        }

        cout << "\nRecompiling QSR:" << endl;
        cout << "\tUpdating configuration.." << endl;
        cout << "\tCompiling QSR With Return code: " << i / 256 << endl;

        //exit(0);
    }
    //return 1;
}
void *Compile(Reltt_INT *In)
{ /*
    In->charstr++;
    cout << BOLDGREEN << "compiling: " << BOLDCYAN << In->Cfg.ProgrameName << "." << In->getVar(In->getcurrentIns()).S_value << RESET << " as: " << BOLDYELLOW << In->getVar(In->getcurrentIns()).S_value << ".QSRobj" << endl;
    string Cmd01 = "g++ ";
    string Cmd02 = In->getVar(In->getcurrentIns()).S_value;
    string Cmd03 = " -c -o Build/obj/";
    string Cmd = Cmd01.append(Cmd02);
    string Cmd1 = Cmd.append(Cmd03);
    replace(Cmd02.begin(), Cmd02.end(), '/', '.');
    string Cmd2 = Cmd1.append(Cmd02);
    string Cmd3 = Cmd2.append(".QSRobj -Iincludes -std=c++");
    string Cmd04 = to_string(In->Cfg.CPPLang);
    string Cmd05 = Cmd3.append(Cmd04);
    int result = system(Cmd3.c_str());
    cout << BOLDYELLOW << "Compile using: \"" << BOLDMAGENTA << Cmd05 << YELLOW << "\" | Return: " << GREEN << result / 256 << RESET << endl;

    //return 0;*/
}
string Reltt_INT::getcurrentIns()
{
    return (string)argv[charstr];
}
string Reltt_INT::getnextIns()
{
    charstr++;
    return getcurrentIns();
}
void *import_T(Reltt_INT *IN)
{

    string SKN = IN->getVar(IN->get_Next_Token()).S_value;
    string k=SKN;

    SKN.pop_back();
    SKN.pop_back();
    SKN.pop_back();
    SKN.pop_back();
    if(strcmp(k.c_str(),SKN.append(".RlS").c_str())==0 ){

    }
    else{
        SKN=k.append(".RlS");
        IN->p.begin_info();
        IN->p.print_info("importing "+SKN);
        IN->p.end_info();
    }
    //cout << "importing: " << SKN << endl;
    ifstream Src(IN->get_fileOBJ(SKN));
    if (Src)
    {
        string Code;

        int SG = 0;
        int sk = 0;
        vector<std::string> vB;
        while (getline(Src, Code))
        {
            SG++;
            std::vector<std::string> v;
            split(Code, v, ' ');
            sk += v.size();
            vB.insert(vB.end(), v.begin(), v.end());

            //this->argc++;

            //cout << Code<<endl;
        }
        //cout << "Importing for real:" << endl;
        IN->argv.insert(IN->argv.begin() + IN->charstr + 1, vB.begin() + 1, vB.end() - 1);

        IN->getnextIns();
        //IN->charstr++;
        // cout << "klol" << endl;
    }
    return 0;
}
void *Init(Reltt_INT *In)
{
    system("mkdir Src");
    //string SKN = getVar(getnextIns());

    system("mkdir includes");
    system("mkdir Build");
    system("mkdir Build/obj");
    system("mkdir Build/exe");
    system("mkdir scripts");
    system("mkdir Private");
}
void *Exit(Reltt_INT *In)
{
    In->p.begin_info();
    In->p.print_info("---Exiting! Reltt---");
    In->p.print_info("Good Bye!");
    In->p.end_info();
    exit(0);
}
void *QF(Reltt_INT *In)
{
    In->charstr++;
    In->runfile();
}
void *add(Reltt_INT *In)
{
    string Cmd00 = "mkdir src/";
    string Cmd01 = In->getVar(In->getnextIns()).S_value;
    string Cmd02 = Cmd00.append(Cmd01);
    system(Cmd02.c_str());
    string Cmd03 = "mkdir includes/";
    string Cmd04 = In->getVar(In->getcurrentIns()).S_value;
    string Cmd05 = Cmd03.append(Cmd04);
    system(Cmd05.c_str());
    ofstream myfile;
    myfile.open((string) "Private/Regen.qf", std::ios_base::app);
    myfile << "\n/* Regen: */\nadd " << Cmd04 << "\n";

    myfile.open(((string) "scripts/").append(RED).append(Cmd04.append(".qf")));
    myfile << "Begin: \nvar Module " << Cmd01 << "\ncompile Module"
           << "\n";
    myfile.close();

    myfile.open(((string) "scripts/Compile_").append(In->Cfg.ProgrameName), std::ios_base::app);
    myfile << "/* Compile Module: " << In->Cfg.ProgrameName << "." << Cmd01 << " */ \nvar Module " << Cmd01 << "\ncompile Module"
           << "\n";
    myfile.close();
}
int Reltt_INT::Parse()
{
    int first_ins = 1;
    //while True until there is no more argv to exeute
    while (charstr < this->argv.size())
    {
        charstr++;
        //cout<<charstr<<endl;
        //cout<<this->argv.size()<<endl;
        //cout << charstr << getcurrentIns() << endl;
        //if ()
        if (this->is_Func_or_var(getcurrentIns()) && this->try_task(getcurrentIns()))
        {
            //execution would be there if it was executing a func, if it was not encounter it will return 0 so would continue in the if else statement
        }
        elif (strcmp(getcurrentIns().c_str(), "end;") == 0)
        {
            return charstr;
        }
        elif (strcmp(getcurrentIns().c_str(), "endif;") == 0)
        {
            return charstr;
        }
        elif (strcmp(getcurrentIns().c_str(), "else") == 0)
        {
            return charstr;
        }
        elif (strcmp(getcurrentIns().c_str(), "then:") == 0)
        {
            //return charstr;
        }
        elif (strcmp(getcurrentIns().c_str(), "elif") == 0)
        {
            return charstr;
        }
        elif (strcmp(getcurrentIns().c_str(), "/*") == 0)
        {
            while (strcmp(getcurrentIns().c_str(), "*/") != 0)
            {
                charstr++;
            }
        }
        else
        {
            bool isexist = 0;
            //cout<<this->FuncName.size()<<endl;
            for (int i = 0; i < this->Functions.size(); i++)
            {
                if (strcmp(this->Functions[i].FuncName.c_str(), getcurrentIns().c_str()) == 0)
                {
                    isexist = 1;
                }
            }
            if ((isexist == 0) && (strcmp(getcurrentIns().c_str(), "Begin:") != 0)&&(strcmp(getcurrentIns().c_str(), "")!=0))
            {

                this->p.print_Error((string)RED +"Unknown Instruction: \""+getcurrentIns()+"\"  at line : " +to_string(get_line_fromcharstr(charstr))+(string)RESET);
                //exit(0);
            }
        }
        if ((this->DBuf == 0) && (first_ins == 1))
        {
            return 1;
        }
        if (this->DBuf != 0)
        {
            DBuf--;
        }

        first_ins = 0;
        //cout<<getVar(getcurrentIns())<<endl;
        //cout<<"isvar??"<<getcurrentIns()<<"->"<<(strcmp(getVar(getcurrentIns()).c_str(),"Null") == 1)<<endl;
    }
    return 0;
}
/*int Reltt_INT::AddCFnc(int (Reltt_INT::*CPP_Addrs)(), string Fnames)
{
    Fnc I;
    I.CPP_Addr = CPP_Addrs;
    I.Fname = Fnames;

    Fncs.push_back(I);
}*/
void *Call(Reltt_INT *IN)
{
    bool isexist = 0;
    //cout<<this->FuncName.size()<<endl;
    int Path;
    int bfcharstr = 0;
    string Fname = IN->get_Next_Token();
    for (int i = 0; i < IN->Functions.size(); i++)
    {
        if (strcmp(IN->Functions[i].FuncName.c_str(), Fname.c_str()) == 0)
        {
            Path = i;
            isexist = 1;
        }
    }
    if (isexist)
    {
        //cout << GREEN << "executing Function" << RESET << " \"" << YELLOW << IN->argv[IN->charstr + 1] << RESET << "\":\n";

        //IN->StackPointer--;
        //IN->StackPointer
        //string funcname = IN->get_Next_Token();
        func_INS_Var *S = new func_INS_Var();
        IN->Math_Var.push_back(S);
        string C = IN->get_Next_Token();
        bool args = 0;
        vector<Value> VA;
        if ((strcmp(C.c_str(), "with") == 0) || (strcmp(C.c_str(), "->") == 0))
        {
            args = 1;

            //cout<<"With"<<IN->Functions[Path].ArgsT.size()<<endl;
            //IN->StackPointer--;
            string j = IN->get_Next_Token();
            for (int i = 0; i < IN->Functions[Path].ArgsT.size(); i++)
            {
                string type = IN->Functions[Path].ArgsT[i].ArgTyper;
                string p2 = to_string(i + 1);
                string Arg = "@";
                Arg.append(p2);
                //cout<<"Var: "<<Arg<<" v: "<<j;
                Value V = Value(Arg, j, type);

                //cout << "Addo" << endl;

                //cout<<"writing in"<<IN->StackPointer<<endl;
                VA.push_back(V);

                //cout << "Addo ok" << endl;
                j = IN->get_Next_Token();
                //cout<<"V: "<<j<<endl;
                bfcharstr = i;
            }

            for (int i = 0; i < VA.size(); i++)
            {
                //cout << VA[i].S_value << VA[i].v_Name << endl;
                IN->New_Var(VA[i],IN->StackPointer);
            }
        }
        else
        {


            IN->charstr -= 1;
            if(IN->Functions[Path].ArgsT.size()>=1){
                cout<<RED<<"[ERROR] did you forget to use '->'? because Function: \""<<IN->Functions[Path].FuncName<<"\" use "<<IN->Functions[Path].ArgsT.size()<<" Args;"<<RESET<<endl;
                isexist=0;
            }
        }
        IN->StackPointer++;
        //cout << IN->StackPointer << endl;
        //IN->Math_Var.size()++;
        //1 sec before execution
        int add = 0;
            if(isexist) {
                int oldCharstr = IN->charstr - 1;
                IN->charstr = IN->Functions[Path].BeginLine;
                IN->Parse();
                //IN->StackPointer--;
                IN->charstr = oldCharstr;

            }
        //IN->charstr
        //1 1 after
        /*for (int i=0;IN->Math_Var[IN->StackPointer]->localVars.size();i++){
                IN->Math_Var[IN->StackPointer]->localVars[i]->~Value();
            }*/
        if (args)
        {
            for (int i = 0; i < VA.size(); i++)
                IN->DeleteVar(VA[i].v_Name);
        }
        IN->Math_Var.pop_back();

        IN->StackPointer--;
        //cout << IN->charstr << endl;
        //cout << IN->get_line_fromcharstr(IN->charstr) << endl;
        //IN->charstr += IN->Functions[Path].ArgsT.size();
        //IN->charstr+=IN->Functions[Path].ArgsT.size()+1;
        //IN->Math_Var.size()--;
    }
    else
    {
        cout << "Unknown Function:\"" << IN->argv[IN->charstr + 1] << "\"" << endl;
    }
    //charstr++;

    //charstr++;
}

void *Export(Reltt_INT *IN)
{
}
void *import_Module(Reltt_INT *IN)
{int didran = 0;
    string N = IN->getVar(IN->get_Next_Token()).S_value;

    //cout << N << endl;
    for (int i = 0; i < IN->QS.size(); i++)
    {

        if (strcmp(IN->QS[i].Module_Name.c_str(), N.c_str()) == 0)
        {
            for (int j = 0; j < IN->QS[i].__Tasks.size(); j++)
            {
                IN->__Tasks.push_back(IN->QS[i].__Tasks[j]);
                didran = 1;
            }
            //cout << "Module: " << N << " imported" << endl;
        }
    }
    if (!didran)
    {
        cout << RED << "ERROR can't import module named: \"" << N << "\"" << endl;
    }

    //IN->add_Cask();
}
void *Plus(Reltt_INT *IN, Value &Ret)
{
    string A = IN->argv[IN->charstr - 1];
    string B = IN->argv[IN->charstr + 1];

    Value a = IN->getVar(A);
    Value b = IN->getVar(B);
    //Ret.S_value=strcat(a.S_value.c_str(),b.S_value.c_str());
    //Value("Register",a.S_value.append(b.S_value).c_str(),"string");
}
void *Del(Reltt_INT *IN)
{
    IN->DeleteVar(IN->get_Next_Token());
}
void *String(Reltt_INT *IN)
{
    string Varname = IN->get_Next_Token();
    string VarValue = resolve_parentensis(IN).S_value;
    //cout<<"VarValue"<<VarValue<<endl;
    //Value T =;
    //cout<<"NewVar Name: "<<Varname<<"Var value:"<<VarValue<<endl;
    //IN->StackPointer--;
    IN->New_Var(Value(Varname, VarValue, "string"),IN->StackPointer-1);
    //IN->StackPointer++;
    //cout<<"VAR:"<<T.S_value<<T.v_Name<<endl;
}
void *func(Reltt_INT *IN)
{
    IN->charstr++;
    string FucName = IN->getcurrentIns();
    vector<ArgType> G;
    if (strcmp(IN->get_Next_Token().c_str(), "(") == 0)
    {
        string i = IN->get_Next_Token();
        //cout<<"open par"<<endl;

        while (strcmp(i.c_str(), ")") != 0)
        {

            G.push_back(i);
            //cout<<i<<endl;
            i = IN->get_Next_Token();
        }
    }
    int beginline = IN->charstr + 1;
    //cout<<"Adding Func name: "<<FucName<<endl;
    string FncCode;
    int EndOFFunc = 0;
    while (!EndOFFunc)
    {
        IN->charstr++;
        //cout<<getcurrentIns()<<endl;
        string InStr = IN->getcurrentIns();
        if (strcmp(InStr.c_str(), "end;") == 0)
        {
            EndOFFunc = IN->charstr;
        }
        else
        {
            FncCode.append(InStr.c_str());
            FncCode.append(" ");
        }
    }

    IN->newFunc(FucName, beginline, EndOFFunc, G);
    //cout << "analized Func properly" << endl;
    //charstr--;
}
void *HelperI(Reltt_INT *TLM)
{
    Helper H = Helper(TLM);
}
void *Dump(Reltt_INT *IN)
{
    for (int i = 0; i < IN->Functions.size(); i++)
    {
        string Strs;
        if (IN->Functions[i].ArgsT.size()!=0){
            for (int j=0;j<IN->Functions[i].ArgsT.size();j++){
                if (j+1<IN->Functions[i].ArgsT.size()){
                    Strs.append(RED).append(IN->Functions[i].ArgsT[j].ArgTyper).append(RESET).append(BLUE).append(", ").append(RESET);
                }
                else{
                    Strs.append(RED).append(IN->Functions[i].ArgsT[j].ArgTyper).append(RESET).append(BLUE).append(" ").append(RESET);

                }
            }
        }
        else{
            Strs.append("None ");
        }
        Strs.append("as arg(s)");
        cout << BLUE <<"\""<< IN->Functions[i].FuncName <<"\""<< RESET <<" -> "<<Strs<< " at addr:" <<CYAN <<"0x"<<hex<<(int64_t)&IN->Functions[i] <<IN->Functions[i].BeginLine<<dec<< RESET << endl;
    }
}
void *with(Reltt_INT *IN)
{
    cout << BOLDRED << "[ERROR]"
         << "Bad usage of with, with should be use in a call to a UD_Func " << endl;
}
void *R_If(Reltt_INT *IN)
{
    int Ifer=0;
   Value V=resolve_parentensis(IN);
   if(IN->Cfg.debug==1)
    cout << "if" <<IN->argv[IN->charstr+2]<<Ifer<< endl;
    Ifer++;
   if (V.B_value==1){
       IN->Parse();
       if(IN->Cfg.debug==1)
    cout<<"True"<<endl;
   }
   elif (V.B_value==0){
       if(IN->Cfg.debug==1)
       cout<<"False"<<endl;
       bool no_Ifer=0;
       bool isfirst=1;
       int JmpL=0;
       while ((Ifer>=1)||(isfirst)) {

           if(strcmp(IN->argv[IN->charstr].c_str(),"endif;")==0){
               if(IN->Cfg.debug==1)
               cout<<"endif;"<<Ifer<<endl;

               Ifer--;
               if (Ifer==0){
                   JmpL=IN->charstr;
               }
           }
           elif(strcmp(IN->argv[IN->charstr].c_str(),"elif")==0){
               if(IN->Cfg.debug==1)
               cout<<"elif"<<IN->argv[IN->charstr+2]<<Ifer<<endl;
               if (Ifer==0){
                   //IN->charstr++;
                   cout<<"resolving parentesis"<<endl;
                   int re=resolve_parentensis(IN).B_value;
                   if (re==1){
                   R_If(IN);
                   }
               }
               isfirst=0;
           }
           elif(strcmp(IN->argv[IN->charstr].c_str(),"else")==0){
               if(IN->Cfg.debug==1)
               cout<<"else"<<Ifer<<endl;
               if (Ifer==1){

                   JmpL=IN->charstr+1;
               }

           }

           //cout<<IN->argv[IN->charstr]<<endl;
           IN->charstr++;
       }
       //cout<<"gonna parse.."<<endl;
       IN->charstr=JmpL;
       IN->Parse();


   }
   else{
       //cout<<"None"<<endl;
   }
}
void *add_Path(Reltt_INT *IN){
    string newpat=IN->getVar(IN->get_Next_Token()).S_value;
    IN->add_path(newpat);
}
void *set_RelttPath(Reltt_INT *IN){
    string i=IN->getVar(IN->get_Next_Token()).S_value;
    ofstream myfile;
    cout<<"RelttPath="<<i<<endl;
    myfile.open(i+"/cfg.hpp");
    myfile<<"#include <filesystem>\n"
          <<"#include <dirent.h>\n"
          <<"#include <cstdlib>\nConfigurator::Configurator()\n"
          <<"{\n"
          <<"this->buildtype = EXE;"
          <<"this->CPPLang = CPP17;"
          <<"this->ProgrameName = \"RELTT\";"
          <<"this->Termwidth=90;"
          <<"this->debug=0;"
          <<"setenv(\"RelttPath\",\""<<i<<"\",1);"
          <<"this->Reltt_path=getenv(\"RelttPath\");"
          <<"}";

    myfile.close();
}
void *Gen_this(Reltt_INT *IN){
    string i=IN->getVar(IN->get_Next_Token()).S_value;
    ofstream myfile;
    myfile.open(i);
    for(int i=0;i<IN->argv.size();i++){
        myfile<<IN->argv[i]<<" ";

    }
    myfile.close();

}
void *ShowVar(Reltt_INT *IN){
    int lastaddr=0;
    for(int i=0; i<IN->Math_Var.size();i++){
        for(int j=0; j<IN->Math_Var[i]->localVars.size();j++) {

            cout << BLUE << IN->Math_Var[i]->localVars[j]->T_R << CYAN << ":" << RED
                 << IN->Math_Var[i]->localVars[j]->v_Name << RESET << " with S_value: " << BLUE <<
                 IN->Math_Var[i]->localVars[j]->S_value << RESET << " SP: " << i << " and Addr: " << CYAN << "0x"
                 << std::hex << ((int64_t) &IN->Math_Var[i]->localVars[j]) << dec<<" Vsize: "
                 << ((int64_t) &IN->Math_Var[i]->localVars[j])-lastaddr << RESET << endl;
            lastaddr=((int64_t)&IN->Math_Var[i]->localVars[j]);
        }
    }
}
void *Add_To_Search(Reltt_INT *IN){
    IN->add_path(resolve_parentensis(IN).S_value);
}
void *ciner(Reltt_INT*IN){
    string varname=IN->get_Next_Token();
    string value;
    cin>>value;
    IN->New_Var(Value(varname,value,"string"),IN->StackPointer);
}
void *handler(Reltt_INT *IN){

}
int Reltt_INT::init_Func()
{
    //&Compile;
    add_Cask("compile", "[Compilable_Module]", &Compile);
    add_Cask("link", "Link all objs together", &Link);
    add_Cask("App-RCP", "Recompile app from local source √", &Update);
    add_Cask("App-RUP", "Update from master-Github and recompile", &Update);
    add_Cask("run", "run exe file in build/exe", &Run);
    add_Cask("import", "import [Module], note those are c++ import √", &import_Module);
    add_Cask("using", "using [Module], note those are QF import √", &import_T);
    add_Cask("func", "[Fname] ( argtype1 argtype2 ) as begin: {Code} end; √", &func);
    add_Cask("call", "[Func] √", &Call);
    add_Cask(">", "[Func] √", &Call);
    add_Cask("with", "call [Func] with/-> Args √", &with);
    add_Cask("exit", "exit Programme √", &Exit);
    add_Cask("add", "add [Compilable_Module]", &add);
    add_Cask("init", "init Project", &Init);
    add_Cask("-RlS", "Run Reltt Script √", &QF);
    add_Cask("-help", "[module] √", &HelperI);
    add_Cask("<>", "[varname] [\"var value\"] √", &String);
    add_Cask("var", "[varname] [var_value] √", &String);
    //add_Cask("elif", "(statement) √", &R_If);

    //add_Cask("float", "[varname] [var_value] √", &Float);
    add_Cask("*>", "[varname], delete var √", &Del);
    add_Cask("PATH", "add to the looking path√", &Add_To_Search);
    add_Cask("DMP", "show loaded UD_function. Note this function do not work with compiled script √", &Dump);
    add_Cask("if", "if ( bool ) if else ( bool ) else endif; √", &R_If);
    add_Cask("SET", "set RelttPath (Restart Reltt to take change) √", &set_RelttPath);
    add_Cask("show", "show all variables √", &ShowVar);
    add_Cask("Gen_this", "Generate a script with this code √", &Gen_this);
    add_Cask("wait", "wait for enter key √", &Sleeper);
    add_Cask("cin", "get until enter key √", &ciner);
    //add_Cask("endif", "end if else statement", &handler);
    //add_Cask("PATH", "Generate a script with this code)", &Add_To_Search);


   // Gen_this



    add_path(getenv("RelttPath"));
    add_path("");
    add_path(((string)getenv("RelttPath")).append("RlS/"));
    add_path(((string)getenv("RelttPath")).append("scripts/"));
    //inline asm("mov ")
    /*



     */
    //add_Cask("print", "[varname]", &print);
    /*add Operators*/
    //add_Cask("+", "[module]", &Plus);

    Init_Modules(this);

    return 0;
}
Reltt_INT::Reltt_INT(int argcr, char **argrv)
{
    //this->LastMathValue=;
    //cout << "initialising" << endl;
    //if(const char* env_p = std::getenv("PATH"))
    //std::cout << "Your PATH is: " << env_p << '\n';
    this->init_Func();
    //this->Init_APP();
    Cfg = Configurator();
    func_INS_Var *R = new func_INS_Var();
    //Value *D = new Value("None", 0);
    //R->localVars.push_back(D);
    //cout<<GREEN<<R->localVars.size()<<endl;
    this->Math_Var.push_back(R);
    if (argcr > 2)
    {
        //cout << "first way" << endl;
        this->argc = argcr;
        for (int i = 0; i < argcr; i++)
        {
            string f = argrv[i];
            this->argv.push_back(f);
        }
        //this->init_Func();
        //Cfg = Configurator();
    }
    else
    {

        //cout << "way 2\n";

        //cout<< sizeof(vinit)<<endl;
        //this->argc = vinit_size;
        //cout<<argc<<endl;
        if (argcr <= 1)
        {

            cout << GREEN << "App\t:\tapp_size" << endl;
            for (int i = 0; i < this->CaPP.size(); i++)
            {
                cout << BOLDCYAN << CaPP[i].app_name << BOLDBLUE << "\t:\t" << BOLDCYAN << CaPP[i].app_length << "->(Q_Words)" << endl;
            }
            cout << RESET << endl;
            exit(0);
        }
        else
        {

            //cout << argrv[1] << endl;

            for (int i = 0; i < this->CaPP.size(); i++)
            {
                if (strcmp(argrv[1], CaPP[i].app_name.c_str()) == 0)
                {
                    for (int j = 0; j < CaPP[i].app_length; j++)
                    {
                        this->argv.push_back(CaPP[i].ins[j]);
                    }
                }
                //string f = (string)vinit[i];
                //this->argv.push_back(f);
            }
        }
    }
}
Value::~Value()
{
}
func_INS_Var::func_INS_Var()
{

    //int values=localVars.size();
    //Value *S = new Value("Noone", 0);
    //this->localVars.push_back(S);
    //this->localVars.begin();
    //cout<<this->localVars[0]->I_value<<endl;

    //this->values=9;
    //cout << "New Dimention" << endl;
}
void func_INS_Var::Add_Value(Value &V)
{
}
Value func_INS_Var::get_Value(string Varnmae)
{
    //cout<<BOLDRED<<Varnmae<<endl<<endl;
    for (int i = 0; i < localVars.size(); i++)
    {
        if (strcmp(Varnmae.c_str(), localVars[i]->v_Name.c_str()) == 0)
        {
            return *localVars[i];
        }
    }

    return Value(Varnmae, Varnmae, "string");
}
