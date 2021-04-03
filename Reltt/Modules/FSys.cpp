
#include "../includes/Mods.hpp"

void *del_f_in_dir(Reltt_INT*IN){
    IN->

}



Reltt_INT::QSRcModule FSys(){
    Reltt_INT::QSRcModule M;
    M.Set_Name("FileSys");
    M.add_Cask("del_f_in_dir", " -> Path to folder to delete every file in", &del_f_in_dir);
    return M;
}