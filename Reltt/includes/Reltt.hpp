#ifndef Reltt_Hpp
//#include "../ConstArgv.hpp"
#define Reltt_Hpp 1
#define COLOR 1

#include "config.hpp"
#include <cstring>

#include <fstream> // std::fstream
#define elif else if
//user definable Function
/*
class Value{
    public:
        Value(string value){
            this->S_V=value;

        }
        Value(int value){ƒ
            this->I_V=value;

        }
        Value(float value){
            this->F_V=value;

        }

    string S_V;
    int I_V;
    float F_V;
    
    };*/

class app
{
public:
    app(string, int, char **);

    string app_name;
    int app_length;
    vector<string> ins;
};
class instruction
{
public:
    instruction(int, int);
    int line;
    int insnumber;
};

size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
class Value
{
public:
    string Get_as_String()
    {
        return this->S_value;
    }
    Value *GetAS() { return this; }
    Value(string Name, string Value, string type);
    Value(string Name, float Value);
    Value(string Name, int Value);
    ~Value();
    int I_value;
    float F_value;
    bool B_value;
    string S_value;
    string v_Name;
    string T_R;
};

class ArgType
{
public:
    ArgType(string);
    string ArgTyper;
};

class UD_Function
{
public:
    UD_Function(string Fname, int Bl, int El)
    {
        this->FuncName = Fname;
        this->BeginLine = Bl;
        this->EndLine = El;
    }
    //argtype.size() is the number of args and argtype[i] is the type of arg
    vector<ArgType> ArgsT;

    string FuncName;

    int BeginLine;
    int EndLine;
};
class func_INS_Var
{
public:
    Value get_Value(string);
    int values;
    func_INS_Var();
    void Add_Value(Value &);

    vector<Value *> localVars;
};
class Reltt_INT
{
public:
    int get_line_fromcharstr(int CharStr2)
    {
        for (int i = 0; i < INSD.size(); i++)
        {
            if (INSD[i].insnumber == CharStr2)
            {
                return INSD[i].line;
            }
        }
        return 0;
    }
    vector<string> paths;
    string get_fileOBJ(string ik){

        for (int i=0;i<paths.size();i++){
            ifstream Src((paths[i]+((string)ik)).c_str());
            if (Src){
                return paths[i]+(ik);
            }
        }

            return "None";



    }
    void add_path(string i){
        this->paths.push_back(i);
    }
    int ifnbr;
    vector<instruction> INSD;
    Value Resolve_statement();
    //void *Init_APP();
    vector<app> CaPP;
    vector<UD_Function> Functions;
    int StackPointer = 0;
    Reltt_INT(int argcr, char **argrv);
    Reltt_INT(){
    this->init_Func();
    //this->Init_APP();
    Cfg = Configurator();
    func_INS_Var *R = new func_INS_Var();
    Value *D = new Value("None", 0);
    R->localVars.push_back(D);
    //cout<<GREEN<<R->localVars.size()<<endl;
    this->Math_Var.push_back(R);
    }

    void AddVector(int argcv, vector<string> argvS)
    {
        //this->LastMathValue=;
        this->argc+= argcv;
        for (int i = 0; i <argcv; i++)
        {
            string f = argvS.at((size_t)i);
            this->argv.push_back(f);
        }
        //this->init_Func();
        //Cfg = Configurator();
    }
    struct CallableObj
    {
        void *(*Taddr)(Reltt_INT *);
        string Name;
        string Desk;
    };
    struct CallableOperator
    {
        void *(*Taddr)(Reltt_INT *, Value &);
        string Name;
        string Desk;
    };
    vector<CallableOperator> Operators;
    int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *, Value &))
    {
        CallableOperator NCO;
        NCO.Desk = desk;
        NCO.Name = fname;
        NCO.Taddr = taddr;
        Operators.push_back(NCO);
        return 0;
    }
    class QSRcModule
    {
    public:
        /*
        QSRcModule(string ModuleName)
        {
            this->Module_Name = ModuleName;
        }
        QSRcModule()
        {
            
        }*/
        int Set_Name(string name)
        {
            this->Module_Name = name;
            return 0;
        }
        int Set_Version(string version)
        {
            this->Version = version;
            return 0;
        }
        int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *))
        {
            CallableObj NCO;
            NCO.Desk = desk;
            NCO.Name = fname;
            NCO.Taddr = taddr;
            __Tasks.push_back(NCO);
            return 0;
        }

        vector<CallableObj> __Tasks;
        string Module_Name;
        string Version;
    };
    //typedef void *(*TaskAddr)(Reltt_INT*);

    //int AddCFnc(TaskAddr, string);

    int Parse();
    //int Update();
    int runfile();
    //int newVar(string, string);
    int DeleteVar(string);
    Value getVar(string);
    void New_Var(Value TR,int SP)
    {
        if(SP<=-1||SP>this->Math_Var.size()){
            SP=0;
        }
        //cout<<"new var: "<<TR.v_Name<<" Value: "<<TR.S_value.c_str()<<endl;
        Value *VR = new Value(TR.v_Name, TR.S_value, TR.T_R);
        if (strcmp(this->getVar(TR.v_Name).S_value.c_str(), TR.v_Name.c_str()) == 0)
        {
            //cout<<"new var"<<TR.v_Name<<" with value "<<TR.S_value<<" at:"<<SP<<endl;
            if ((SP) <= (this->Math_Var.size()))
                this->Math_Var[SP]->localVars.push_back(VR);
        }
        else
        { //cout<<"Altering "<<TR.v_Name<<endl;
            for (int k = 0; k <= SP; k++)
            {
                for (int i = 0; i < this->Math_Var[k]->localVars.size(); i++)
                {
                    //cout << varname << i << endl;
                    //cout<<this->vars[i+1]<<"?"<<endl;
                    if (strcmp(this->Math_Var[k]->localVars[i]->v_Name.c_str(), TR.v_Name.c_str()) == 0)
                    {
                        this->Math_Var[k]->localVars[i] = VR;
                        //cout<<"[DEBUG]"<<this->Math_Var[StackPointer]->localVars[i]->v_Name<<" V: "<<this->Math_Var[StackPointer]->localVars[i]->S_value<<endl;
                        //return E;
                    }
                }
            }
        }
    }
    string get_Next_Token();
    bool is_operator(string name);
    int is_Func_or_var(string ins);
    vector<QSRcModule> QS;
    int add_Module(QSRcModule MD)
    {
        QS.push_back(MD);
        return 0;
    }
    int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *))
    {
        CallableObj NCO;
        NCO.Desk = desk;
        NCO.Name = fname;
        NCO.Taddr = taddr;
        __Tasks.push_back(NCO);
        return 0;
    }
    int RunTask()
    {

        //return Taddr();
        return 0;
    }
    bool is_Name(CallableObj Obj, string Test_Name)
    {
        return (strcmp(Obj.Name.c_str(), Test_Name.c_str()) == 0);
    }
    /*string getname()
        {
            return Name;
        }
*/
    int init_Func();

    int try_task(string tname);
    QSRcModule getModule(string name);

    vector<CallableObj> __Tasks;
    struct Fnc
    {
        int (Reltt_INT::*CPP_Addr)();
        string Fname;
    };
    int DBuf = -2;
    Value LastMathValue = Value("None", 0);
    string getcurrentIns();
    //int edit(string);
    int varsN = 0;
    int charstr = 0;
    //int Compile();
    //int Link();
    int executeFunc(string);
    //int Run();
    int newFunc(string, int, int, vector<ArgType>);
    //int import();
    string getnextIns();
    vector<func_INS_Var *> Math_Var;

    //vector<string> vars;
    vector<Fnc> Fncs;

    //2d xyz, x=func, y=code z=call
    int NextFNCID = 0;

    /*vector<string> FuncName;
    vector<int> FuncStackP;

    vector<int> Begin_Line;
    vector<int> End_line;*/
    //vector<std::string> vardata;
    Configurator Cfg;
    int argc;
    vector<int> lines;
    vector<string> argv;
};
/*int Reltt_INT::GetSRCFId(string SrcF){
    for (int i=0;i<FuncSrc.size();i++){
        if(strcmp(SrcF.c_str(),FuncSrc[i].c_str())==0){
            return i;
        }
    }
    return -1;
}*/
Value resolve_parentensis(Reltt_INT *IN);
class Helper
{
public:
    Helper(Reltt_INT *);
};
#else

#endif
/*

Reltt index 


*/
