#include "includes/Reltt.hpp"

Value::~Value()
{
}
Value::Value(string Name, float Value)
{
    this->v_Name = Name;
    this->F_value = Value;
    this->T_R = "float";
}
Value::Value(string Name, int Value)
{
    this->v_Name = Name;
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
Value *resolve_parentensis(Reltt_INT *IN)
{
    Value *tokenB = IN->getVar(IN->get_Next_Token());
    Value token=*tokenB;
    Value *cachevalue = new Value("", "", "string");
    Value *Arrayvalue = new Value();
    Value *return_Value = new Value("", "", "string");
    int par = 0;
    bool isarray = 0;
    bool isfirst = 1;
    while (par >= 1 || isfirst)
    {
        //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
        if (strcmp(token.S_value.c_str(), " ") == 0)
        {
            cachevalue->S_value.append(" ");
        }
        if (strcmp(token.S_value.c_str(), "+") == 0)
        {
            //cout<<"Plus"<<endl;

            tokenB = IN->getVar(IN->get_Next_Token());
            token=*tokenB;
            if (strcmp(token.S_value.c_str(), " ") == 0)
            {
                cachevalue->S_value = cachevalue->S_value.append(" ");
            }
            if (strcmp(token.T_R.c_str(), "string") == 0)
            {
                cachevalue->S_value = cachevalue->S_value.append(token.S_value);
                cachevalue = new Value(cachevalue->v_Name, cachevalue->S_value, "string");
            }
            else
            {
                cachevalue->I_value = cachevalue->I_value + token.I_value;
                cachevalue->F_value = cachevalue->F_value + token.F_value;
                cachevalue->S_value = to_string(cachevalue->F_value);
                cachevalue->T_R = "float";
            }
        }
        elif (strcmp(token.S_value.c_str(), "-") == 0)
        {
            //cout<<"Plus"<<endl;

            tokenB = IN->getVar(IN->get_Next_Token());
            token=*tokenB;

            if (strcmp(token.T_R.c_str(), "string") == 0)
            {
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue->I_value = cachevalue->I_value - i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator - is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator - is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue->F_value = cachevalue->F_value - i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator - is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator - is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");
            }
            else
            {
                cachevalue->I_value = cachevalue->I_value - token.I_value;
                cachevalue->F_value = cachevalue->F_value - token.F_value;
                cachevalue->S_value = to_string(cachevalue->F_value);
                cachevalue->T_R = "float";
            }
        }
        elif (strcmp(token.S_value.c_str(), "/") == 0)
        {
            //cout<<"divide"<<endl;

            tokenB = IN->getVar(IN->get_Next_Token());
            token=*tokenB;

            if (strcmp(token.T_R.c_str(), "string") == 0)
            {
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue->I_value = cachevalue->I_value / i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator / is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator / is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue->F_value = cachevalue->F_value / i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator / is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator / is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");
            }
            else
            {
                cachevalue->I_value = cachevalue->I_value / token.I_value;
                cachevalue->F_value = cachevalue->F_value / token.F_value;
                cachevalue->S_value = to_string(cachevalue->F_value);
                cachevalue->T_R = "float";
            }
        }
        elif (strcmp(token.S_value.c_str(), "*") == 0)
        {
            //cout<<"multiply"<<endl;

            tokenB = IN->getVar(IN->get_Next_Token());
            token=*tokenB;

            if (strcmp(token.T_R.c_str(), "string") == 0)
            {
                try
                {
                    int i = std::stoi(token.S_value);
                    cachevalue->I_value = cachevalue->I_value * i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator * is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator * is not available for strings" << endl;
                    cachevalue->I_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                try
                {
                    float i = std::stof(token.S_value);
                    cachevalue->F_value = cachevalue->F_value * i;
                    //std::cout << i << '\n';
                }
                catch (std::invalid_argument const &e)
                {
                    cout << "operator * is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Bad input: std::invalid_argument thrown" << '\n';
                }
                catch (std::out_of_range const &e)
                {
                    cout << "operator * is not available for strings" << endl;
                    cachevalue->F_value = -1;
                    //std::cout << "Integer overflow: std::out_of_range thrown" << '\n';
                }
                //cachevalue.S_value=cachevalue.S_value.s(token.S_value);
                //cachevalue=Value("",cachevalue.S_value,"string");
            }
            else
            {
                cachevalue->I_value = cachevalue->I_value * token.I_value;
                cachevalue->F_value = cachevalue->F_value * token.F_value;
                cachevalue->S_value = to_string(cachevalue->F_value);
                cachevalue->T_R = "float";
            }
        }
        elif (strcmp(token.S_value.c_str(), "&&") == 0)
        {
            cout << cachevalue->B_value;
            token = *IN->getVar(IN->get_Next_Token());

            cachevalue->B_value = (cachevalue->F_value && token.F_value) || (cachevalue->I_value && token.I_value);
        }
        elif (strcmp(token.S_value.c_str(), "||") == 0)
        {
            cout << cachevalue->B_value;
            token = *IN->getVar(IN->get_Next_Token());

            cachevalue->B_value = (cachevalue->F_value || token.F_value);
        }
        elif (strcmp(token.S_value.c_str(), "==") == 0)
        {
            token = *IN->getVar(IN->get_Next_Token());
            cachevalue->B_value = (strcmp(cachevalue->S_value.c_str(), token.S_value.c_str()) == 0);
        }
        elif (strcmp(token.S_value.c_str(), "!=") == 0)
        {
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            token = *IN->getVar(IN->get_Next_Token());
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            cachevalue->B_value = (strcmp(cachevalue->S_value.c_str(), token.S_value.c_str()));
            //cout<<cachevalue.B_value<<endl;
            //cachevalue.S_value=to_string(cachevalue.B_value);
        }
        elif (strcmp(token.S_value.c_str(), ">=") == 0)
        {
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            token = *IN->getVar(IN->get_Next_Token());
            //cout<<"Token: "<<token.v_Name<<" -> "<<token.S_value<<endl;
            cachevalue->B_value = (cachevalue->F_value >=token.F_value);
            //cout<<cachevalue.B_value<<endl;
            //cachevalue.S_value=to_string(cachevalue.B_value);
        }
        elif (strcmp(token.S_value.c_str(), "(") == 0)
        {
            if (par)
            {
                cachevalue = resolve_parentensis(IN);
            }
            else
            {
                par++;
            }
        }
        elif (strcmp(token.S_value.c_str(), ")") == 0)
        {
            par--;
            if (par == 0)
            {
                return_Value = *(&cachevalue);
                //cout<<"return fast"<<endl;
                return return_Value;
            }
        }
        elif (strcmp(token.S_value.c_str(), "[") == 0)
        {
            isarray = true;
            if (par)
            {
                cachevalue = resolve_parentensis(IN);
            }
            else
            {
                par++;
            }
        }
        elif (strcmp(token.S_value.c_str(), "]") == 0)
        {
            par--;
            if (par == 0)
            {
                //Arrayvalue.T_R="Array";ƒ
                //return_Value=;
                //cout<<"return fast"<<endl;
                if (IN->Cfg.debug)
                    cout << cachevalue->S_value << endl;

                Arrayvalue->Push_Back(cachevalue);
                Arrayvalue->S_value = Reltt_Array_to_string(Arrayvalue);
                return Arrayvalue;
            }
        }
        elif (strcmp(token.S_value.c_str(), ",") == 0)
        {
            if (IN->Cfg.debug)
                cout << cachevalue->S_value << endl;
            Value *f = cachevalue;
            Arrayvalue->Push_Back(f);
        }
        elif (isfirst)
        {
            //cout<<"Reterning"<<token.S_value<<endl;
            //Value *R=new Value();
            return IN->getVar(token.S_value);
        }
        elif (par == 0)
        {
            Value R = *IN->getVar(cachevalue->S_value);
            return_Value = &R;
            //cout<<"return laster"<<return_Value.v_Name<<endl;
            return return_Value;
        }
        else
        {

            Value *R = IN->getVar(token.v_Name);
            cachevalue = R;
        }
        isfirst = 0;

        token = *IN->getVar(IN->get_Next_Token());
    }
    //cout<<"Reterning after: "<<return_Value.S_value<<endl;
    return return_Value;
}

void Reltt_INT::New_Var(Value *TR, int SP)
{
    if (SP <= -1 || SP > this->Math_Var.size())
    {
        SP = 0;
    }
    //cout<<"new var: "<<TR.v_Name<<" Value: "<<TR.S_value.c_str()<<endl;
    //Value VTR = TR;
    //Value *VR=new Value(TR);
    //cout<<"NewVarBLBL:"<<VR->Objects.size()<<endl;
    if (strcmp(this->getVar(TR->v_Name)->S_value.c_str(), TR->v_Name.c_str()) == 0)
    {
        cout<<"new var"<<TR->v_Name<<" with value "<<TR->S_value<<" at:"<<SP<<endl;
        if ((SP) <= (this->Math_Var.size()))
        {
            this->Math_Var[SP]->localVars.push_back(TR);
            cout<<"BLBLB: "<<this->Math_Var[SP]->localVars[this->Math_Var[SP]->localVars.size()-1]->Objects.size()<<endl;
        }
    }
    else
    { //cout<<"Altering "<<TR.v_Name<<endl;
        for (int k = 0; k <= SP; k++)
        {
            for (int i = 0; i < this->Math_Var[k]->localVars.size(); i++)
            {
                //cout << varname << i << endl;
                //cout<<this->vars[i+1]<<"?"<<endl;
                if (strcmp(this->Math_Var[k]->localVars[i]->v_Name.c_str(), TR->v_Name.c_str()) == 0)
                {
                    this->Math_Var[k]->localVars[i] = TR;
                    //cout<<"[DEBUG]"<<this->Math_Var[StackPointer]->localVars[i]->v_Name<<" V: "<<this->Math_Var[StackPointer]->localVars[i]->S_value<<endl;
                    //return E;
                }
            }
        }
    }
}