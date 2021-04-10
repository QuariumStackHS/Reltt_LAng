import os
import sys
import platform
from flask.helpers import url_for
import mods
import subprocess
from flask import render_template
from flask import Flask, session, redirect, url_for, escape, request, send_file,flash,session
from werkzeug.utils import secure_filename
from flask_sqlalchemy import SQLAlchemy
app = Flask(__name__)
app.config["SQLALCHEMY_DATABASE_URI"] = 'sqlite:///DB3.sqlite3'
app.config["SQLALCHEMY_TRACK_MODIFICATION"] = False
db = SQLAlchemy(app)
ALLOWED_EXTENSIONS = {'o', 'obj', 'png', 'jpg', 'jpeg', 'gif'}
app.config['UPLOAD_FOLDER'] = "../Reltt/Cache/"
def allowed_file(filename):
    return '.' in filename and \
           filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS
class Mods(db.Model):
    """DB CLASSES"""

    _id = db.Column(db.Integer, primary_key=True)
    isused=db.Column(db.Integer)
    name = db.Column(db.String(100))
    Developer = db.Column(db.String(100))
    Version = db.Column(db.String(100))
    Description = db.Column(db.String(100))
    OS = db.Column(db.String(100))
    contructor=db.Column(db.String(100))
    Path=db.Column(db.String(100))

    def __init__(self, name, Developer, Version, OS,OBJPATH,cppconstructor,Desk):
        """DB CLASSES"""
        self.isused=0
        self.contructor=cppconstructor
        self.name = name
        self.Developer = Developer
        self.Version = Version
        self.OS = OS
        self.Description=Desk
        self.Path=OBJPATH
@app.route('/Up/<constructor>/<Dev>/<Desc>/<Version>/<OS>', methods=['GET', 'POST'])
def upload_file(constructor,Dev,Desc,Version,OS):
    if request.method == 'POST':
        # check if the post request has the file part
        if 'file' not in request.files:
            flash('No file part')
            return redirect(request.url)
        file = request.files['file']
        # if user does not select file, browser also
        # submit an empty part without filename
        if file.filename == '':
            flash('No selected file')
            return redirect(request.url)
        if file and allowed_file(file.filename):
            filename = secure_filename(file.filename)
            file.save(os.path.join(app.config['UPLOAD_FOLDER'], constructor+".o"))
            if Mods.query.filter(Mods.name == constructor).first() is None:
                h=Mods(constructor,Dev,Version,OS,os.path.join(app.config['UPLOAD_FOLDER'], constructor+".o"),constructor,Desc)
                db.session.add(h)
                db.session.commit()

            return redirect(url_for('upload_file',
                                    filename=filename,constructor=constructor,Dev=Dev,Desc=Desc,Version=Version,OS=OS))
    return render_template("Reltt_uplaud.html",name=Dev,constructor=constructor)

app.secret_key = "any random string"
nmods=[]
@app.route('/')
def home():
    return render_template("Reltt_main.html",OS=platform.system())
@app.route('/mod/add')
def py_mods():
    return render_template("Reltt_addmodule.html",OS=platform.system())
modcons={""}
@app.route('/mod')
def py_mod():
    return render_template("Reltt_mod.html",OS=platform.system(),Mods=Mods.query.all())

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
    os.system("g++ -std=c++17 -c ../Reltt/Reltt.cpp -o ../Reltt/Cache/Reltt.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Linked_List.cpp -o ../Reltt/Cache/Reltt_Linked_List.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Value.cpp -o ../Reltt/Cache/Reltt_Value.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Utils.cpp -o ../Reltt/Cache/Utils.o")
    os.system("g++ -w -std=c++17 -c ../Reltt/Reltt_Instruction_func.cpp -o ../Reltt/Cache/Reltt_Instruction_func.o")
    for i in Mods.query.all():
        if i.isused:
            objects+=" "+i.Path
    os.system("g++ -w -o ../Reltt/bin/Reltt -std=c++17 "+objects)
@app.route('/run/<file>')
def run(file):
    open("Out.txt","w").close()
    k=open("../Reltt/tmp.RlS","w")
    k.write(file)
    k.close
    os.system("Reltt build.RlS>>Out.txt")
    return open("Out.txt","r").read();
    
@app.route('/shell')
def shell():
    return render_template("Reltt_Shell.html")
@app.route('/mod/compile')
def cmp():
    k=open("../Reltt/includes/Mods.hpp","w")
    i="""#ifndef RELTT_LANG_MODS_HPP
        #define RELTT_LANG_MODS_HPP
        #include "Reltt.hpp\"\n"""
    for j in Mods.query.all():
        if j.isused:
            i+="Reltt_INT::QSRcModule "+j.name+"();\n"
    i+="#endif //RELTT_LANG_MODS_HPP"
    k.write(i)
    k.close()
    k=open("../Reltt/Modules.hpp","w")
    i="""#include "includes/Mods.hpp"
    /*put your module in this function to add it*/
    void Init_Modules(Reltt_INT *I){"""
    for j in Mods.query.all():
        if j.isused:
            i+="I->add_Module("+j.name+"());\n"
    i+="}"
    k.write(i)
    k.close()
    build_Reltt()
    return "compiled"
@app.route('/mod/download')
def downloadReltt():
    return send_file("../Reltt/bin/Reltt", as_attachment=True)
@app.route('/mod/exist/<Module_name>')
def existmod(Module_name):
    mod=Mods.query.filter(Mods.name == Module_name).first()
    if mod is not None:
        return str(mod.isused)
    print("-1")
    return "-1"
@app.route('/mod/D/<Module_name>')
def py_mod_disable(Module_name):
    print(Module_name)
    ih=0
    """
    for i in mods.Mods:
        if i.name==Module_name:
            mods.Mods[ih].isused=0
            print(Module_name,"yes")
            return str(mods.Mods[ih].isused)
        ih+=1
    """
    k=Mods.query.filter(Mods.name == Module_name).first()
    k.isused=0
    db.session.commit()
    return str(0)
    return redirect(url_for("py_mod"))
@app.route('/mod/A/<Module_name>')
def Enable(Module_name):
    print(Module_name)
    ih=0
    """
    for i in mods.Mods:
        if i.name==Module_name:
            print(Module_name,"yes")
            mods.Mods[ih].isused=1
            return str(mods.Mods[ih].isused)
        ih+=1
    """
    k=Mods.query.filter(Mods.name == Module_name).first()
    k.isused=1
    db.session.commit()

    return str(1)

def about():
    return

if __name__=="__main__":
    db.create_all()
    app.run(debug=1)
