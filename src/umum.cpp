#include "umum.hpp"

std::string GetExePath()
{
    wchar_t path[1280];
    GetModuleFileNameW(NULL, path, 1280);
    std::wstring ws(path);
    std::string string(ws.begin(), ws.end());
    int lastIndex = string.find("main.exe");
    string = string.replace(lastIndex, 8, "");
    return string;
}
