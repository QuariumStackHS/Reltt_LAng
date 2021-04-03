
#include "../includes/Mods.hpp"

void *del_f_in_dir(Reltt_INT *IN)
{
    string Path = resolve_parentensis(IN)->S_value;
    string CMD = "rm -r ";
    CMD.append(Path);
    int i = system(CMD.c_str());
    if (i == 0)
    {
        cout << "Deleted all files in: " << Path << endl;
    }
    else
    {
        cout << "OOF" << endl;
    }
}

Reltt_INT::QSRcModule FSys()
{
    Reltt_INT::QSRcModule M;
    M.Set_Name("FileSys");
    M.add_Cask("del_f_in_dir", " -> Path to folder to delete every file in", &del_f_in_dir);
    return M;
}