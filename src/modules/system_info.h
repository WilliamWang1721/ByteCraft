#ifndef SYSTEM_INFO_H
#define SYSTEM_INFO_H

#include <string>

class SystemInfo {
public:
    static std::string getOSInfo();
    static std::string getCPUInfo();
    static std::string getMemoryInfo();
    static std::string getDiskInfo();
    static void printSystemInfo();
};

#endif // SYSTEM_INFO_H
