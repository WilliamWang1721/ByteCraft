// 文件路径：src/modules/hardware_info.cpp

#include "hardware_info.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // For system calls
#include <cstring>

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
    // 在此添加针对 CPU 的检测逻辑
    std::string cpuInfo = "CPU信息: Intel i7-9700K\n"; // 示例数据
    std::cout << cpuInfo;
}

void HardwareInfo::checkMemory() {
    // 在此添加内存检测逻辑
    std::string memoryInfo = "内存信息: 16GB DDR4\n"; // 示例数据
    std::cout << memoryInfo;
}

void HardwareInfo::checkDisk() {
    // 在此添加硬盘检测逻辑
    std::string diskInfo = "硬盘信息: 512GB SSD\n"; // 示例数据
    std::cout << diskInfo;
}

void HardwareInfo::checkGPU() {
    // 在此添加 GPU 检测逻辑
    std::string gpuInfo = "GPU信息: NVIDIA GeForce GTX 1080\n"; // 示例数据
    std::cout << gpuInfo;
}

void HardwareInfo::checkTemperature() {
    // 假设这是获取温度的逻辑
    std::string temperatureInfo = "温度信息: CPU 45°C, GPU 40°C\n"; // 示例数据
    std::cout << temperatureInfo;
}

void HardwareInfo::checkSMART() {
    // 假设这是 S.M.A.R.T 健康检测的逻辑
    std::string smartInfo = "硬盘健康状态: 正常\n"; // 示例数据
    std::cout << smartInfo;
}

void HardwareInfo::logToFile(const std::string& content) {
    std::ofstream logFile("hardware_info.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << content << "\n";
        logFile.close();
        std::cout << "信息已导出至 hardware_info.txt\n";
    }
}
