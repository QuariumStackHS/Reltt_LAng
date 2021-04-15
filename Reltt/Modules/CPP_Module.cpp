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
#include <algorithm>
#include <sys/stat.h>
inline bool F_exist (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

bool compare_files(const std::string &filename1, const std::string &filename2)
{
    std::ifstream file1(filename1, std::ifstream::ate | std::ifstream::binary); //open file at the end
    std::ifstream file2(filename2, std::ifstream::ate | std::ifstream::binary); //open file at the end
    const std::ifstream::pos_type fileSize = file1.tellg();

    if (fileSize != file2.tellg())
    {
        return false; //different file size
    }

    file1.seekg(0); //rewind
    file2.seekg(0); //rewind

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    return std::equal(begin1, std::istreambuf_iterator<char>(), begin2); //Second argument is end-of-range iterator
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

    try
    {
        //cout<<srcD.rdbuf()==src.rdbuf();
        if (compare_files(SRC, DEST))
        {
            //cout<<RED<<SRC<<"!="<<DEST<<RESET<<endl;
            std::ofstream dest(DEST, std::ios::binary);
            dest << src.rdbuf();
            if(F_exist(getenv("EXENAME"))==1){
                return 0;
            }
            else{
                return 1;
            }
            
        }
        else
        {
            //cout<<GREEN<<SRC<<"=="<<DEST<<RESET<<endl;
            std::ofstream dest(DEST, std::ios::binary);
            dest << src.rdbuf();
            return 1;
        }
    }
    catch (const std::exception &e)
    {
        std::ofstream dest(DEST, std::ios::binary);
        dest << src.rdbuf();
        return 1;
    }

    //return src && dest;
}

static string linkcmd;
static string Param;
static string DLL;
static bool CMP = 0;
string mods_array="Mods=[";
void *mod_N(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    //IN->charstr--;
    string PT2 = resolve_parentensis(IN)->S_value;
    bool compile = copyFile(PT2, IN->RelttCheck + PT + "_.XS");
    //cout<<PT2<<":"<<compile<<endl;
    mods_array+='"'+IN->RelttCache+PT+".o\",";
    if (compile)
    {
        string cmd = "gcc -c -o ";
        cmd.append(IN->RelttCache).append(PT).append(".o ").append(PT2);
        int i = system(cmd.c_str());

        cout<<cmd<<endl;
        if (i != 0)
        {
            cout << "Error" << endl;
            exit(0);
        }

        cout << BLUE << "(ASM)\t|\tCompiled object: \"" << YELLOW << PT << BLUE << "\"" << RESET << endl;
        CMP = 1;
    }
    else
    {
        cout << MAGENTA << "(ASM)\t|\tSkipped object \"" << YELLOW << PT << MAGENTA << "\"" << RESET << " (Already up to date)" << endl;
    }

    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    //IN->p.end_info();
}
void* create_mod_list(Reltt_INT*IN){
string path=resolve_parentensis(IN)->S_value;
std::ofstream(path, std::ios::out).close();
cout<<path<<endl;
ofstream Mod_list;
Mod_list.open(path,ios::app);
Mod_list<<"import os\n"
<<"def convert_bytes(num):\n"
<<"\tfor x in ['bytes', 'KB', 'MB', 'GB', 'TB']:\n"
<<"\t\tif num < 1024.0:\n"
<<"\t\t\treturn \"%3.1f %s\" % (num, x)\n"
<<"\t\tnum /= 1024.0\n"
<<"def file_size(file_path):\n"
<<"\tif os.path.isfile(file_path):\n"
<<"\t\tfile_info = os.stat(file_path)\n"
<<"\t\treturn convert_bytes(file_info.st_size)\n"
<<"\nclass mod:\n\t"
        <<"def __init__(self,name,Path,size):\n\t"
        <<"\tself.name=name\n\t"
        <<"\tself.Path=Path\n\t"
        <<"\tself.size=file_size(Path)\n\t"
        <<"\tself.isused=1;\n"
        <<mods_array;
Mod_list<<"]\n";
Mod_list.close();
//cout<<mods_array<<endl;
}
void *mod(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    //IN->charstr--;
    string PT2 = resolve_parentensis(IN)->S_value;
    bool compile = copyFile(PT2, IN->RelttCheck + PT + "_Check.Xcpp");
    //cout<<PT2<<":"<<compile<<endl;
    mods_array+="mod(\""+PT+"\",\""+IN->RelttCache+PT+".o\",'None',),";
    if (compile)
    {
        string cmd = "g++ -c -o ";
        cmd.append(IN->RelttCache).append(PT).append(".o -std=c++17 -w ").append(PT2);
        int i = system(cmd.c_str());

        //cout<<cmd<<endl;
        if (i != 0)
        {
            cout << "Error" << endl;
            exit(0);
        }
        cout << BLUE << "(C++)\t|\tCompiled object: \"" << YELLOW << PT << BLUE << "\"" << RESET << endl;
        CMP = 1;
    }
    else
    {
        cout << MAGENTA << "(C++)\t|\tSkipped object \"" << YELLOW << PT << MAGENTA << "\"" << RESET << " (Already up to date)" << endl;
    }

    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    //IN->p.end_info();
}
void *link(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    linkcmd.append(IN->RelttCache).append(PT).append(".o ");
    //IN->p.end_info();
}
void *add_switch_to_gpp(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    Param.append(" ").append(PT);
}
void *linker(Reltt_INT *IN)
{
    string cmd = "g++ ";
    cmd.append(linkcmd).append(" -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    int j = 1;
    if (CMP)
        j = system(cmd.c_str());
    else
    {
        cout << GREEN << "(Build)\t|\tSkipping " << getenv("EXENAME") << RESET << endl;
    }
    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    if (j == 0)
        cout << GREEN << "(Build)\t|\tLinked " << getenv("EXENAME") << " Succefuly" << RESET << endl;

    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    /* vector<string>K;
    split(linkcmd,K,' ');
    for(int i=0;i<K.size();i++){
        remove(K[i].c_str());
    }*/
    CMP = 0;
    linkcmd = "";
    DLL = "";
    Param = "";
}
void *linker_(Reltt_INT *IN)
{
    string cmd = "g++ ";
    cmd.append(linkcmd).append(" -shared -Wl, -std=c++17 -w -o ").append(getenv("EXENAME")).append(DLL).append(Param);
    int j = 1;
    if (CMP)
        j = system(cmd.c_str());
    else
    {
        cout << GREEN << "(Build)\t|\tSkipping " << getenv("EXENAME") << RESET << endl;
    }
    //IN->p.begin_info();
    //IN->p.print_info(cmd);
    if (j == 0)
        cout << GREEN << "(Build)\t|\tLinked " << getenv("EXENAME") << " Succefuly" << RESET << endl;
    //IN->p.end_info();
    //string PT=resolve_parentensis(IN).S_value;
    /*vector<string>K;
    split(linkcmd,K,' ');
    for(int i=0;i<K.size();i++){
        remove(K[i].c_str());
    }
     */
    CMP = 0;
    linkcmd = "";
    Param = "";
    DLL = "";
}
void *set_exe_name(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    setenv("EXENAME", IN->getVar(PT)->S_value.c_str(), 1);
}
void *add_DLL(Reltt_INT *IN)
{
    string PT = resolve_parentensis(IN)->S_value;
    DLL.append(" ").append(PT);
}
void *Set_Cache(Reltt_INT *IN)
{
    IN->RelttCache = resolve_parentensis(IN)->S_value;
    IN->RelttCheck = IN->RelttCache + "/Check/";
    string cmd = "mkdir " + IN->RelttCheck;
    int i = system(cmd.c_str());
}

Reltt_INT::QSRcModule CPP_Module()
{
    Reltt_INT::QSRcModule E = Reltt_INT::QSRcModule();
    E.Module_Name = "C++";
    E.constructorname="CPP_Module";
    E.add_Cask("asm_module", "add module I", &mod_N);
    E.add_Cask("module", "add module I", &mod);
    E.add_Cask("Exe", "execute value as interpreted", &set_exe_name);
    E.add_Cask("Add", "add to linker", &link);
    E.add_Cask("link-this", "compile+link", &linker);
    E.add_Cask("link-this_DLL", "compile+link", &linker_);
    E.add_Cask("Add_DLL", "", &add_DLL);
    E.add_Cask("Add_Switch", "", &add_switch_to_gpp);
    E.add_Cask("Set_Cache", "", &Set_Cache);
    E.add_Cask("create_mod_list","->PATH-of.py",&create_mod_list);
    //link
    return E;
}

#endif