#include "umum.hpp"

// Khusus buat di Windows
#if defined(_WIN32)
#include <libloaderapi.h>
#endif

#if defined(unix)
#include <unistd.h>
#endif

#include <iostream>
#include <regex.h>

// Khusus buat di Windows
#if defined(_WIN32)
std::string GetExePath()
{
    wchar_t path[1280];
    GetModuleFileNameW(NULL, path, 1280);
    std::wstring ws(path);
    std::string rawString(ws.begin(), ws.end());
    int lastIndex = rawString.find("main.exe");
    rawString = rawString.replace(lastIndex, 8, "");
    return rawString;
}
#endif

// Khusus buat di Linux
#if defined(unix)
std::string GetExePath()
{
    char path[1280];
    ssize_t count = readlink("/proc/self/exe", path, 1280);
    if (count < 0)
    {
        std::cout << "Error di GetExePath\n";
        std::exit(1);
    }
    
    std::string rawString(path, count);
    int lastIndex = rawString.find("/main");
    rawString = rawString.replace(lastIndex, 5, "/");
    return rawString;
}
#endif