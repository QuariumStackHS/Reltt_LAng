import os
import sys
import platform
from flask.helpers import url_for
import mods
from flask import render_template
from flask import Flask, session, redirect, url_for, escape, request, send_file
app = Flask(__name__)




app.secret_key = "any random string"
nmods=[]
@app.route('/')
def home():
    return render_template("Reltt_main.html",OS=platform.system())

modcons={""}
@app.route('/mod')
def py_mod():
    return render_template("Reltt_mod.html",OS=platform.system(),Mods=mods.Mods)

def nones(RelttPath):
    k=open("../Reltt/cfg.hpp","w")
    i="""#include <filesystem>
    #include <dirent.h>
    #include <cstdlib>
    Configurator::Configurator()
    {
    this->buildtype = EXE;this->CPPLang = CPP17;this->ProgrameName = "RELTT";this->Termwidth=90;this->debug=0;setenv("RelttPath",\""""+RelttPath+"""\",1);this->Reltt_path=getenv("RelttPath");}"""
    k.write(i)
    k.close()
def build_Reltt():
    objects="../Reltt/Cache/Rmain.o ../Reltt/Cache/Reltt.o ../Reltt/Cache/Reltt_Instruction_func.o ../Reltt/Cache/Utils.o ../Reltt/Cache/Reltt_Linked_List.o ../Reltt/Cache/Reltt_Value.o"
    os.system("g++ -w -std=c++17 -c ../Reltt/main.cpp -o ../Reltt/Cache/Rmain.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt.cpp -o ../Reltt/Cache/Reltt.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Linked_List.cpp -o ../Reltt/Cache/Reltt_Linked_List.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Value.cpp -o ../Reltt/Cache/Reltt_Value.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Utils.cpp -o ../Reltt/Cache/Utils.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Instruction_func.cpp -o ../Reltt/Cache/Reltt_Instruction_func.o")
    for i in mods.Mods:
        if i.isused:
            objects+=" "+i.Path
    os.system("g++ -w -o ../Reltt/bin/Reltt -std=c++17 "+objects)
@app.route('/mod/compile')
def cmp():
    k=open("../Reltt/includes/Mods.hpp","w")
    i="""#ifndef RELTT_LANG_MODS_HPP
        #define RELTT_LANG_MODS_HPP
        #include "Reltt.hpp\"\n"""
    for j in mods.Mods:
        if j.isused:
            i+="Reltt_INT::QSRcModule "+j.name+"();\n"
    i+="#endif //RELTT_LANG_MODS_HPP"
    k.write(i)
    k.close()
    k=open("../Reltt/Modules.hpp","w")
    i="""#include "includes/Mods.hpp"
    /*put your module in this function to add it*/
    void Init_Modules(Reltt_INT *I){"""
    for j in mods.Mods:
        if j.isused:
            i+="I->add_Module("+j.name+"());\n"
    i+="}"
    k.write(i)
    k.close()
    build_Reltt()
    return send_file("../Reltt/bin/Reltt", as_attachment=True)

@app.route('/mod/D/<Module_name>')
def py_mod_disable(Module_name):
    print(Module_name)
    ih=0
    for i in mods.Mods:
        if i.name==Module_name:
            mods.Mods[ih].isused=0;
        ih+=1

    return redirect(url_for("py_mod"))
@app.route('/mod/A/<Module_name>')
def Enable(Module_name):
    print(Module_name)
    ih=0
    for i in mods.Mods:
        if i.name==Module_name:
            mods.Mods[ih].isused=1;
        ih+=1

    return redirect(url_for("py_mod"))

def about():
    return

if __name__=="__main__":
    app.run(debug=1)
