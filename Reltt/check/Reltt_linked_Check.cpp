//
// Created by Christopher Clement on 2021-03-26.
//
#include "includes/Reltt.hpp"
static Value* R_Null=new Value("Null","Null","Null");
//static int max_Prev = -443055;
Value *Value::get_next(){
    if (this->Next_Obj!=nullptr){
        return this->Next_Obj;
    }
    else{
        //cout<<"Random_ERROR"<<endl;
        return nullptr;
    }

}
Value *Value::get_prev(){
    if (this->Prev_Obj!=nullptr){
        return this->Prev_Obj;
    }
    else{
        //cout<<"Random_ERROR"<<endl;
        return nullptr;
    }
}
void Value::set_next(Value* IN){
    this->Next_Obj=IN;
    this->Next_Obj->L_index=this->L_index+1;
}
void Value::set_prev(Value*IN){
    this->Prev_Obj=IN;
    this->Next_Obj->L_index=this->L_index+1;
}
void Value::Push_Forward(Value*IN){
    if(this->Prev_Obj==nullptr){
        this->Prev_Obj=IN;
        this->Prev_Obj->L_index=this->L_index-1;
    }
    else{
        this->Prev_Obj->Push_Forward(IN);
    }
}
void Value::Push_Back(Value*IN){
    cout<<"Push_back"<<endl;
    if(IN->Next_Obj==nullptr){
        if(this->Next_Obj==nullptr){
            this->Next_Obj=IN;
            //this->Next_Obj->Next_Obj->L_index=
            this->Next_Obj->L_index=this->L_index+1;
        }
        else{
            this->Next_Obj->Push_Back(IN);
        }
    }
    else{
        if(this->Next_Obj==nullptr){
            this->Next_Obj=IN;
            this->Next_Obj->Next_Obj=nullptr;
            //this->Next_Obj->Next_Obj->L_index=
            this->Next_Obj->L_index=this->L_index+1;
        }
        else{
            this->Next_Obj->Push_Back(IN);
        }
    }
}
int Value::L_size(){
    //cout<<"Getting_size"<<this->L_index<<endl;
    int ikl=0;
    for(Value*i=this;i!=nullptr;i=i->get_next()){
        ikl++;
        //cout<<ikl<<endl;
        if (i->Next_Obj==nullptr){
            return i->L_index;

        }
    }

}
string Reltt_Array_to_string(Value*I){

    string retstr="[ \"";
    for (Value *K=I->get_next();K!=nullptr;K=K->get_next()){
        cout<<K->S_value<<endl;
        retstr.append(K->S_value);
        retstr.append("\" , \"");

    }
    retstr.pop_back();
    retstr.pop_back();
    retstr.pop_back();
    retstr.append("]");
    cout<<"Debug: "<<retstr<<endl;
    return retstr;
}