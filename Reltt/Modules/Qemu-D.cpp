
#include "../includes/Mods.hpp"
#include <time.h>
#include <sstream>
void*launch(Reltt_INT*IN){
    string cmd="qemu-system-x86_64 ";
    if(strcmp(getenv("Boot-drive"),""))
    cmd.append(((string)"-hda ").append(IN->get_fileOBJ(getenv("Boot-drive")))).append(" ");
    cmd.append("-cpu max ");
    cmd.append(((string)"-smp ").append(getenv("cores")));
    cmd.append(((string)" -m ").append((getenv("Mem"))).append("G"));
    if(strcmp(getenv("install-drive"),""))
    cmd.append(((string)" -cdrom ").append(IN->get_fileOBJ(getenv("install-drive"))));
    cout<<cmd<<endl;
    system(cmd.c_str());

}
void*Backup_VM(Reltt_INT*IN){
  time_t rawtime;
  struct tm * timeinfo;
  char buffer [80];

  time (&rawtime);
  timeinfo = localtime (&rawtime);

  strftime (buffer,80,"%B-%d-%Y-%I-%M",timeinfo);
    string cmd="qemu-img convert -p -f vpc -O qcow2 ";
    cmd.append(getenv("Boot-drive"));
    cmd.append(((string)" ")+buffer+(getenv("Boot-drive")));
    cmd.append(".qcow2");
    cout<<cmd<<endl;
    system(cmd.c_str());

}
void*create_HDD(Reltt_INT*IN){
    
    string cmd="qemu-img create -f vpc ";
    cmd.append(resolve_parentensis(IN)->S_value);
    cmd.append(" ");
    cmd.append(resolve_parentensis(IN)->S_value);
    cout<<cmd<<endl;;
    system(cmd.c_str());
}
void*Restore_VM(Reltt_INT*IN){
    string cmd="qemu-img convert -p -f qcow2 -O vpc ";
    cmd.append(getenv("Boot-drive"));
    cmd.append(" ");
    cmd.append(resolve_parentensis(IN)->S_value);
    
    cout<<cmd<<endl;
    system(cmd.c_str());
}
void*Set_HDD(Reltt_INT*IN){
    string iso=resolve_parentensis(IN)->S_value;
    setenv("Boot-drive",iso.c_str(),1);
}
void*Add_iso(Reltt_INT*IN){
    string iso=resolve_parentensis(IN)->S_value;
    setenv("install-drive",iso.c_str(),1);
}
void*set_cores(Reltt_INT*IN){
    string iso=resolve_parentensis(IN)->S_value;
    setenv("cores",iso.c_str(),1);
}
void*set_Mem(Reltt_INT*IN){
    string iso=resolve_parentensis(IN)->S_value;
    setenv("Mem",iso.c_str(),1);
}
void*Create_script(Reltt_INT*IN){
    string Vmname=resolve_parentensis(IN)->S_value;
    string PATH=resolve_parentensis(IN)->S_value;
    string size=resolve_parentensis(IN)->S_value;
    string iso=resolve_parentensis(IN)->S_value;
    string Mem=resolve_parentensis(IN)->S_value;
    string Cores=resolve_parentensis(IN)->S_value;
    stringstream ss;
    ss<<"Begin:";

ss<<"\n\nPATH "<<PATH<<"\n";
ss<<"\n\nSet_HDD "<<Vmname<<".vhd\n";
ss<<"\n\n<> ISO "<<iso<<"\n";
ss<<"\n\ncores "<<Cores<<"\n";
ss<<"\n\nMem "<<Mem<<"\nend;";
    ofstream myfile;
    string fileout = PATH;
    fileout.append(Vmname).append(".RlS");
    myfile.open(fileout.c_str());
    myfile<<ss.str();
    myfile.close();

    string cmd="qemu-img create -f vpc ";
    cmd.append(PATH+Vmname+".vhd");
    cmd.append(" ");
    cmd.append(size);
    system(cmd.c_str());


}
Reltt_INT::QSRcModule Qemu_D()
{
    Reltt_INT::QSRcModule M;
    setenv("Backup-Folder","NONE",0);
    setenv("Boot-drive","NONE",0);
    setenv("install-drive","",0);
    setenv("Mem","6000",0);
    setenv("cores","1",0);
    M.Set_Name("qemu");
    M.add_Cask("launch", " run command build with no args", &launch);
    M.add_Cask("Set_HDD", "-> /Boot-drive", &Set_HDD);
    M.add_Cask("add_iso_boot", " -> /Iso.iso", &Add_iso);
    M.add_Cask("cores", " -> int", &set_cores);
    M.add_Cask("Mem", " -> int", &set_Mem);
    M.add_Cask("Backup", " -> int", &Backup_VM);
    M.add_Cask("Restore", " -> Path_of_backup", &Restore_VM);
    M.add_Cask("Create_Hdd"," disk_name size ",&create_HDD);
    M.add_Cask("Create_script","-> VMname PATH size ISO MEM CORES ",&Create_script);
    return M;
}