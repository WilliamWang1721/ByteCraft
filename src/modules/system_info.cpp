#include "system_info.h"
#include <iostream>
#include <sstream>
#include <sys/utsname.h>
#include <sys/statvfs.h>

#ifdef _WIN32
#include <windows.h>
#include <tchar.h>
#else
#include <fstream>
#endif

std::string SystemInfo::getOSInfo() {
    std::ostringstream oss;

#ifdef _WIN32
    // Windows 操作系统信息
    oss << "操作系统: Windows\n";
    OSVERSIONINFOEX osvi;
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
        oss << "版本: " << osvi.dwMajorVersion << "." << osvi.dwMinorVersion << "\n";
        oss << "版本名: " << osvi.szCSDVersion << "\n";
    }
#elif defined(__linux__)
    // Linux 操作系统信息
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        oss << "操作系统: " << buffer.sysname << "\n";
        oss << "主机名: " << buffer.nodename << "\n";
        oss << "版本: " << buffer.version << "\n";
    }
#elif defined(__APPLE__) && defined(__MACH__)
    // macOS 操作系统信息
    oss << "操作系统: macOS\n";
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        oss << "版本: " << buffer.version << "\n";
    }
#else
    oss << "操作系统: Unknown\n";
#endif

    return oss.str();
}

std::string SystemInfo::getCPUInfo() {
    std::ostringstream oss;

#ifdef _WIN32
    // Windows CPU 信息
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    oss << "CPU 核心数: " << si.dwNumberOfProcessors << "\n";
#else
    // Linux 或 macOS 获取 CPU 信息
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    while (std::getline(cpuinfo, line)) {
        if (line.find("model name") != std::string::npos) {
            oss << "CPU: " << line.substr(line.find(":") + 2) << "\n";
            break;
        }
    }
    cpuinfo.close();
#endif

    return oss.str();
}

std::string SystemInfo::getMemoryInfo() {
    std::ostringstream oss;

#ifdef _WIN32
    // Windows 内存信息
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memStatus)) {
        oss << "总内存: " << memStatus.ullTotalPhys / 1024 / 1024 << " MB\n";
        oss << "可用内存: " << memStatus.ullAvailPhys / 1024 / 1024 << " MB\n";
    }
#else
    // Linux 或 macOS 获取内存信息
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal") != std::string::npos) {
            oss << "总内存: " << std::stoi(line.substr(line.find(":") + 1)) / 1024 << " MB\n";
        } else if (line.find("MemFree") != std::string::npos) {
            oss << "可用内存: " << std::stoi(line.substr(line.find(":") + 1)) / 1024 << " MB\n";
        }
    }
    meminfo.close();
#endif

    return oss.str();
}

std::string SystemInfo::getDiskInfo() {
    std::ostringstream oss;

#ifdef _WIN32
    // Windows 磁盘信息
    ULARGE_INTEGER freeBytes, totalBytes, totalFreeBytes;
    if (GetDiskFreeSpaceEx(L"C:\\", &freeBytes, &totalBytes, &totalFreeBytes)) {
        oss << "磁盘总空间: " << totalBytes.QuadPart / 1024 / 1024 / 1024 << " GB\n";
        oss << "可用空间: " << totalFreeBytes.QuadPart / 1024 / 1024 / 1024 << " GB\n";
    }
#else
    // Linux 或 macOS 磁盘信息
    struct statvfs stat;
    if (statvfs("/", &stat) == 0) {
        oss << "磁盘总空间: " << (stat.f_blocks * stat.f_frsize) / 1024 / 1024 / 1024 << " GB\n";
        oss << "可用空间: " << (stat.f_bfree * stat.f_frsize) / 1024 / 1024 / 1024 << " GB\n";
    }
#endif

    return oss.str();
}

void SystemInfo::printSystemInfo() {
    std::cout << getOSInfo();
    std::cout << getCPUInfo();
    std::cout << getMemoryInfo();
    std::cout << getDiskInfo();
}
