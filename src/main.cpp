#include <iostream>
#include "MMS/export.h"
#include "FIOU/export.h"
using namespace std;
#include <windows.h>
#include <tchar.h>
using namespace MMS;
SophiscatedMMInstance smmi;
void PathRemoveFileSpec(GCHAR *path)
{
    GCHAR *last = NULL;
    GCHAR *p = path;
    while (*p)
    {
        if (*p == _TEXT('\\') || *p == _TEXT('/'))
            last = p;
        p++;
    }
    if (last)
        *last = _TEXT('\0');
}
char buffer[100 * 1024 * 1024];
int main(){
    smmi.setInit([&](void ** ptr){
        *ptr = buffer;
    });
    smmi.memInit();
     #ifdef _WIN32
        TCHAR szPath[MAX_PATH];
        GetModuleFileName(NULL, szPath, MAX_PATH);
        PathRemoveFileSpec(szPath);
        SetCurrentDirectory(szPath);
    #else 
        char szPath[PATH_MAX];
        //change cwd to the directory of the executable 
        readlink("/proc/self/exe", szPath, PATH_MAX);
        PathRemoveFileSpec(szPath);
        chdir(szPath);

    #endif
    FileHandle::memoryInterface = &smmi;
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