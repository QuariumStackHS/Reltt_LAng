//
// Created by Christopher Clement on 2021-03-06.
//
//#include <windows.h>
#include <string>
#include <filesystem>
#include <iostream>
namespace fs = std::experimental::filesystem;

// We could use fs::path as return type, but if you're not aware of
// std::experimental::filesystem, you probably handle filenames
// as strings anyway in the remainder of your code.  I'm on Japanese
// Windows, so wide chars are a must.
std::wstring getDirectoryWithCurrentExecutable()
{
    int size = 256;
    std::vector<wchar_t> charBuffer;
    // Let's be safe, and find the right buffer size programmatically.
    do {
        size *= 2;
        charBuffer.resize(size);
        // Resize until filename fits.  GetModuleFileNameW returns the
        // number of characters written to the buffer, so if the
        // return value is smaller than the size of the buffer, it was
        // large enough.
    } while (GetModuleFileNameW(NULL, charBuffer.data(), size) == size);
    // Typically: c:/program files (x86)/something/foo/bar/exe/files/win64/baz.exe
    // (Note that windows supports forward and backward slashes as path
    // separators, so you have to be careful when searching through a path
    // manually.)

    // Let's extract the interesting part:
    fs::path path(charBuffer.data());  // Contains the full path including .exe
    return path.remove_filename()  // Extract the directory ...
            .w_str();           // ... and convert to a string.
}
using namespace std;

int main(){
    cout<<getDirectoryWithCurrentExecutable().c_str()<<endl;
    return 0;
}