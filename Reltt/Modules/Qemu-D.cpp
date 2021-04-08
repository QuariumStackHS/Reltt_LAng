
#include "../includes/Mods.hpp"
#include <time.h>
#include <sstream>
string hdd;
int hdds = 0;
string cdrom;
string Phdd;
string sharedfolder;

void *launch(Reltt_INT *IN)
{
    string cmd = "qemu-system-x86_64";
    if (strcmp(hdd.c_str(), ""))
        cmd.append(hdd);
    cmd.append(" -cpu max");
    cmd.append(sharedfolder);
    cmd.append(((string) " -smp ").append(getenv("cores")));
    cmd.append(((string) " -m ").append((getenv("Mem"))).append("G"));
    if (strcmp(cdrom.c_str(), ""))
        cmd.append(cdrom);
    cout << cmd << endl;
    system(cmd.c_str());
}
void *Add_shared_folder(Reltt_INT *IN)
{
    string acces=resolve_parentensis(IN)->S_value;
    string Path=resolve_parentensis(IN)->S_value;
    sharedfolder.append(" -drive file=fat:"+acces+":"+Path+",format=raw");
}
void *Backup_VM(Reltt_INT *IN)
{
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%B-%d-%Y-%I-%M", timeinfo);
    string cmd = "qemu-img convert -p -f vpc -O qcow2 ";
    cmd.append(IN->get_fileOBJ(Phdd));
    cmd.append(" ");
    cmd.append(((string)getenv("backup_folder")) + Phdd + "-Snapshot-" + buffer);
    cmd.append(".qcow2");
    cout << cmd << endl;
    system(cmd.c_str());
}
void *create_HDD(Reltt_INT *IN)
{

    string cmd = "qemu-img create -f vpc ";
    cmd.append(resolve_parentensis(IN)->S_value);
    cmd.append(" ");
    cmd.append(resolve_parentensis(IN)->S_value);
    cout << cmd << endl;
    ;
    system(cmd.c_str());
}
void *Restore_VM(Reltt_INT *IN)
{
    string cmd = "qemu-img convert -p -f qcow2 -O vpc ";
    cmd.append(resolve_parentensis(IN)->S_value);
    cmd.append(" ");

    cmd.append(IN->get_fileOBJ(Phdd));
    cout << cmd << endl;
    system(cmd.c_str());
}
void *Set_HDD(Reltt_INT *IN)
{
    string iso = resolve_parentensis(IN)->S_value;
    string hd;
    if (hdds == 0)
    {
        hd=" -hda ";
        Phdd=iso;
    }
    elif (hdds == 1)
    {
        hd=" -hdb ";
    }
    elif (hdds == 2)
    {
        hd=" -hdc ";
    }
    elif (hdds == 3)
    {
        hd=" -hdd ";
    }
    hdds++;
    hdd.append(hd);
    hdd.append(IN->get_fileOBJ(iso));
    
}
void *Add_iso(Reltt_INT *IN)
{
    string iso = resolve_parentensis(IN)->S_value;
    cdrom.append(" -cdrom");
    cdrom.append(IN->get_fileOBJ(iso));
}
void *set_cores(Reltt_INT *IN)
{
    string iso = resolve_parentensis(IN)->S_value;
    setenv("cores", iso.c_str(), 1);
}
void *set_Mem(Reltt_INT *IN)
{
    string iso = resolve_parentensis(IN)->S_value;
    setenv("Mem", iso.c_str(), 1);
}
void *Create_script(Reltt_INT *IN)
{
    string Vmname = resolve_parentensis(IN)->S_value;
    string PATH = resolve_parentensis(IN)->S_value;
    string size = resolve_parentensis(IN)->S_value;
    string iso = resolve_parentensis(IN)->S_value;
    string Mem = resolve_parentensis(IN)->S_value;
    string Cores = resolve_parentensis(IN)->S_value;
    stringstream ss;
    ss << "Begin:\n\n";
    ss << "PATH " << PATH+Vmname << "/\n";
    ss << "set_bcfolder " << PATH+"snapshot/" << "\n";
    ss << "Set_HDD " << Vmname << ".vhd\n";
    ss << "<> ISO " << iso << "\n";
    ss << "cores " << Cores << "\n";
    ss << "Mem " << Mem << "\nend;";
    ofstream myfile;

    string fileout = getenv("RelttPath");fileout.append("VM/");
    
    fileout.append(Vmname).append(".RlS");
    cout<<fileout<<endl<<ss.str()<<endl;
    myfile.open(fileout.c_str(),ios::app);
    myfile << ss.str();
    myfile.close();

    string cmd = "qemu-img create -f vpc ";
    cmd.append(PATH + Vmname + ".vhd");
    cmd.append(" ");
    cmd.append(size);
    system(cmd.c_str());
}
void *bcfolder(Reltt_INT *IN)
{
    string iso = resolve_parentensis(IN)->S_value;
    setenv("backup_folder", iso.c_str(), 1);
}
Reltt_INT::QSRcModule Qemu_D()
{
    Reltt_INT::QSRcModule M;
    setenv("Backup-Folder", "NONE", 0);
    setenv("Boot-drive", "NONE", 0);
    setenv("install-drive", "", 0);
    setenv("Mem", "6000", 0);
    setenv("cores", "1", 0);
    setenv("backup_folder", "None", 0);
    M.Set_Name("qemu");
    M.add_Cask("launch", " run command build with no args", &launch);
    M.add_Cask("Set_HDD", "-> /Boot-drive", &Set_HDD);
    M.add_Cask("add_iso_boot", " -> /Iso.iso", &Add_iso);
    M.add_Cask("set_bcfolder", " -> /Iso.iso", &bcfolder);
    M.add_Cask("cores", " -> int", &set_cores);
    M.add_Cask("Mem", " -> int", &set_Mem);
    M.add_Cask("Backup", " -> int", &Backup_VM);
    M.add_Cask("Restore", " -> Path_of_backup", &Restore_VM);
    M.add_Cask("Create_Hdd", " disk_name size ", &create_HDD);
    M.add_Cask("Create_script", "-> VMname PATH size ISO MEM CORES ", &Create_script);
    M.add_Cask("Add_shared_folder","-> rw/r/w Path",&Add_shared_folder);
    return M;
}