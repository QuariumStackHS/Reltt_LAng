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

    Value *get_next();
    Value *get_prev();
    void set_next(Value*);
    void set_prev(Value*);
    void Push_Back(Value*);
    void Push_Forward(Value*);
    int L_index=0;
    int L_size();
    Value *GetAS() { return this; }
    Value(string Name, string Value, string type);
    Value(string Name, float Value);
    Value(string Name, int Value);

    Value(){
this->T_R="(Linked)Array";
    };
<<<<<<< Updated upstream
    Value* Next_Obj=nullptr;
    Value* Prev_Obj=nullptr;
=======

    vector<Value*>Objects;
>>>>>>> Stashed changes
    ~Value();
    int I_value;
    float F_value;
    bool B_value;
    //Reltt_array V_Array;
    string S_value;
    string v_Name;
    string T_R;
};
<<<<<<< Updated upstream
string Reltt_Array_to_string(Value*I);
=======
class Reltt_array:public Value{
public:
    Reltt_array(Value *value) {
        Value value_c=*value;
        this->S_value=value_c.S_value;
        //cout<<RED<<this->S_value<<":|:"<<value_c.S_value<<endl<<RESET;
        this->F_value=value_c.F_value;
        this->I_value=value_c.I_value;
        this->B_value=value_c.B_value;
        this->T_R="Array";
        if (value->Objects.size()>=1){
            cout<<"Value was already an Reltt_array and then converted into a value!"<<endl;
        }
    }
    Reltt_array(){
        this->T_R="Array";
    }
    Reltt_array(string Name, string Value, string type)
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

    //int pushback(Value value);
    int popback();
    Value Get_at_index(int index);

    //vector<Value>;

    int pushback(Value *value);
};
string Reltt_Array_to_string(Reltt_array*I);
>>>>>>> Stashed changes
class ArgType
{
public:
    ArgType(string);
    string ArgTyper;
};

class UD_Function
{
public:
    UD_Function(string Fname, int Bl, int El);
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

    vector<Reltt_array *> localVars;
};
class printer{
public:
    printer(string user,string Thread);
    void begin_info();
    void end_info();
    void print_info(string info);
    void print_Error(string Error);
    void B_cin();


    string Suser;
    string SThread;

};

class Reltt_INT
{
public:
    printer p=printer("Dev","Reltt_INT");
    int get_line_fromcharstr(int CharStr2);
    vector<string> paths;
    string get_fileOBJ(string ik);
    void add_path(string i);
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
    Reltt_array *D = new Reltt_array();
    R->localVars.push_back(D);
    //cout<<GREEN<<R->localVars.size()<<endl;
    this->Math_Var.push_back(R);
        this->New_Var(Reltt_array("RelttPath",getenv("RelttPath"),"string"),0);
    }

    void AddVector(int argcv, vector<string> argvS);
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
    int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *, Value &));
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
        int Set_Name(string name);
        int Set_Version(string version);
        int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *));

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
<<<<<<< Updated upstream
    Value *getVar(string);
    void New_Var(Value TR,int SP);
    void New_Var(Value *TR,int SP);
=======
    Reltt_array getVar(string);
    void New_Var(Reltt_array TR,int SP);
>>>>>>> Stashed changes
    string get_Next_Token();
    bool is_operator(string name);
    int is_Func_or_var(string ins);
    vector<QSRcModule> QS;
    int add_Module(QSRcModule MD);
    int add_Cask(string fname, string desk, void *(taddr)(Reltt_INT *));
    bool is_Name(CallableObj Obj, string Test_Name);
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
Value* resolve_parentensis(Reltt_INT *IN);
size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
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
