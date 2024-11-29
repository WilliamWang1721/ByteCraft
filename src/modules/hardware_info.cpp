#include "hardware_info.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // For system calls
#include <cstring>
#include <unistd.h>

void HardwareInfo::performBasicCheck() {
    std::stringstream report;
    
    report << "=== 常规硬件检测 ===\n";
    checkCPU();
    checkMemory();
    checkDisk();
    checkGPU();

    logToFile(report.str());
}

void HardwareInfo::performFullCheck() {
    std::stringstream report;

    report << "=== 全面深度硬件检测 ===\n";
    checkCPU();
    checkMemory();
    checkDisk();
    checkGPU();
    checkTemperature();
    checkSMART();

    logToFile(report.str());
}

void HardwareInfo::performSelectiveCheck(const std::string& component) {
    std::stringstream report;

    report << "=== 选择性硬件检测 ===\n";
    if (component == "CPU") {
        checkCPU();
    } else if (component == "Memory") {
        checkMemory();
    } else if (component == "Disk") {
        checkDisk();
    } else if (component == "GPU") {
        checkGPU();
    }

    logToFile(report.str());
}

void HardwareInfo::checkCPU() {
    std::string cpuInfo;
    #ifdef _WIN32
        cpuInfo = getCommandOutput("wmic cpu get caption");
    #elif __linux__
        cpuInfo = getCommandOutput("lscpu | grep 'Model name'");
    #elif __APPLE__
        cpuInfo = getCommandOutput("sysctl -n machdep.cpu.brand_string");
    #endif

    std::cout << "CPU信息: " << cpuInfo << std::endl;
}

void HardwareInfo::checkMemory() {
    std::string memoryInfo;
    #ifdef _WIN32
        memoryInfo = getCommandOutput("wmic memorychip get capacity");
    #elif __linux__
        memoryInfo = getCommandOutput("free -h | grep Mem");
    #elif __APPLE__
        memoryInfo = getCommandOutput("sysctl hw.memsize");
    #endif

    std::cout << "内存信息: " << memoryInfo << std::endl;
}

void HardwareInfo::checkDisk() {
    std::string diskInfo;
    #ifdef _WIN32
        diskInfo = getCommandOutput("wmic diskdrive get caption, size");
    #elif __linux__
        diskInfo = getCommandOutput("lsblk");
    #elif __APPLE__
        diskInfo = getCommandOutput("diskutil list");
    #endif

    std::cout << "硬盘信息: " << diskInfo << std::endl;
}

void HardwareInfo::checkGPU() {
    std::string gpuInfo;
    #ifdef _WIN32
        gpuInfo = getCommandOutput("wmic path win32_videocontroller get caption");
    #elif __linux__
        gpuInfo = getCommandOutput("lspci | grep VGA");
    #elif __APPLE__
        gpuInfo = getCommandOutput("system_profiler SPDisplaysDataType");
    #endif

    std::cout << "GPU信息: " << gpuInfo << std::endl;
}

void HardwareInfo::checkTemperature() {
    std::string temperatureInfo;
    #ifdef _WIN32
        temperatureInfo = getCommandOutput("wmic /namespace:\\\\root\\wmi PATH MSAcpi_ThermalZoneTemperature get CurrentTemperature");
    #elif __linux__
        temperatureInfo = getCommandOutput("sensors | grep 'Core 0'");
    #elif __APPLE__
        temperatureInfo = getCommandOutput("osx-cpu-temp");
    #endif

    std::cout << "温度信息: " << temperatureInfo << std::endl;
}

void HardwareInfo::checkSMART() {
    std::string smartInfo;
    #ifdef _WIN32
        smartInfo = getCommandOutput("wmic diskdrive get status");
    #elif __linux__
        smartInfo = getCommandOutput("smartctl -a /dev/sda");
    #elif __APPLE__
        smartInfo = getCommandOutput("diskutil info /dev/disk0 | grep 'SMART Status'");
    #endif

    std::cout << "硬盘健康状态: " << smartInfo << std::endl;
}

void HardwareInfo::logToFile(const std::string& content) {
    std::ofstream logFile("hardware_info.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << content << "\n";
        logFile.close();
        std::cout << "信息已导出至 hardware_info.txt\n";
    }
}

std::string HardwareInfo::getCommandOutput(const std::string& command) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "无法执行命令: " << command << std::endl;
        return result;
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}
