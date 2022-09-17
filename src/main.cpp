#include <iostream>
#include "export.h"
using namespace std;
#include <windows.h>
#include <tchar.h>

int main(){
    FileHandle fh, fh2;
    fh.setFileName(_T("a.txt"));
    fh.setGeneralReadMode();
    const char * ret = fh.readFromFile();
    fh2.setFileName(_T("b.txt"));
    fh2.setGeneralWriteMode();
    fh2.writeToFile(ret, strlen(ret));
    fh.closeFile();
    fh2.closeFile();
    return 0;
}