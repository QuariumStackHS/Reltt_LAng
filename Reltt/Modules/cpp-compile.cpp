//
// Created by Christopher Clement on 2021-03-17.
//

#ifndef CPPSTD_HPP
#define CPPSTD_HPP

#include "../includes/Mods.hpp"
#include <fstream>

#include <algorithm>
#include <iterator>
#include <string>
#include <fstream>

template<typename InputIterator1, typename InputIterator2>
bool
range_equal(InputIterator1 first1, InputIterator1 last1,
            InputIterator2 first2, InputIterator2 last2)
{
    while(first1 != last1 && first2 != last2)
    {
        if(*first1 != *first2) return false;
        ++first1;
        ++first2;
    }
    return (first1 == last1) && (first2 == last2);
}

bool compare_files(const std::string& filename1, const std::string& filename2)
{
    std::ifstream file1(filename1);
    std::ifstream file2(filename2);

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    std::istreambuf_iterator<char> end;

    return range_equal(begin1, end, begin2, end);
}
std::ifstream::pos_type filesize(string filename)
{
    std::ifstream in(filename.c_str(), std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

// copy in binary mode
bool copyFile(string SRC, string DEST)
{
    std::ifstream src(SRC, std::ios::binary);

    try {
        //cout<<srcD.rdbuf()==src.rdbuf();
        if(filesize(SRC)==filesize(DEST)){
            return 0;
        }
        else if(!compare_files(SRC,DEST))
        {
            return 0;
        }
        else{
            std::ofstream dest(DEST, std::ios::binary);
            dest << src.rdbuf();
            return 1;
        }
    }
    catch (const std::exception& e){
        std::ofstream dest(DEST, std::ios::binary);
        dest << src.rdbuf();
        return 1;
    }

    //return src && dest;
}

static string linkcmd;
static string Param;
static string DLL;


void *mod(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    //IN->charstr--;
    string PT2=resolve_parentensis(IN)->S_value;
    bool compile=copyFile(PT2,RelttCache+PT+"_Bc");
    //cout<<PT2<<":"<<compile<<endl;
    if (compile) {
        string cmd = "g++ -c -o ";
        cmd.append(RelttCache).append(PT).append(".o -std=c++17 -w ").append(PT2);
        system(cmd.c_str());
    }
    else{
        cout<<"Skiped an object"<<endl;
    }

    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    //IN->p.end_info();
}
void *link(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    linkcmd.append(RelttCache).append(PT).append(".o ");
    //IN->p.end_info();
}
void *add_switch_to_gpp(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    Param.append(" ").append(PT);
}
void *linker(Reltt_INT *IN){
    string cmd="g++ ";
    cmd.append(linkcmd).append(" -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    int j=system(cmd.c_str());
    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    if (j==0)
        cout<<GREEN<<"Compiled Module: "<<getenv("EXENAME")<<" Succefuly"<<RESET<<endl;
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
   /* vector<string>K;
    split(linkcmd,K,' ');
    for(int i=0;i<K.size();i++){
        remove(K[i].c_str());
    }*/
    linkcmd="";
    DLL="";
    Param="";
}
void *linker_(Reltt_INT *IN){
    string cmd="g++ ";
    cmd.append(linkcmd).append(" -shared -Wl, -std=c++17 -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    int j=system(cmd.c_str());
    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    if (j==0)
    cout<<GREEN<<"Compiled Module: "<<getenv("EXENAME")<<" Succefuly"<<RESET<<endl;
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    /*vector<string>K;
    split(linkcmd,K,' ');
    for(int i=0;i<K.size();i++){
        remove(K[i].c_str());
    }
     */
    linkcmd="";
    Param="";
    DLL="";
}
void *set_exe_name(Reltt_INT *IN){
    string PT=resolve_parentensis(IN)->S_value;
    setenv("EXENAME",IN->getVar(PT)->S_value.c_str(),1);
}
void*add_DLL(Reltt_INT*IN ){
    string PT=resolve_parentensis(IN)->S_value;
    DLL.append(" ").append(PT);
}
Reltt_INT::QSRcModule CPP_Module(){
    Reltt_INT::QSRcModule E=Reltt_INT::QSRcModule();
    E.Module_Name="C++";
    E.add_Cask("module","add module I",&mod);
    E.add_Cask("Exe","execute value as interpreted",&set_exe_name);
    E.add_Cask("Add","add to linker",&link);
    E.add_Cask("link-this","compile+link",&linker);
    E.add_Cask("link-this_DLL","compile+link",&linker_);
    E.add_Cask("Add_DLL","",&add_DLL);
    E.add_Cask("Add_Switch","",&add_switch_to_gpp);
    //link
    return E;
}


#endif