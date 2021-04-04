
#include "../includes/Mods.hpp"

void*launch(Reltt_INT*IN){
    string cmd="qemu-system-x86_64 ";
    if(strcmp(getenv("Boot-drive"),""))
    cmd.append(((string)"-hda ").append(IN->get_fileOBJ(getenv("Boot-drive"))));
    cmd.append(" -cpu max ");
    cmd.append(((string)"-smp ").append(getenv("cores")));
    cmd.append(((string)" -m ").append(getenv("Mem")));
    if(strcmp(getenv("install-drive"),""))
    cmd.append(((string)"-cdrom ").append(IN->get_fileOBJ(getenv("install-drive"))));
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
Reltt_INT::QSRcModule Qemu_D()
{
    Reltt_INT::QSRcModule M;
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
    return M;
}