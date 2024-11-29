// 文件路径：src/modules/hardware_info.h

#ifndef HARDWARE_INFO_H
#define HARDWARE_INFO_H

#include <string>

class HardwareInfo {
public:
    static void performBasicCheck();
    static void performFullCheck();
    static void performSelectiveCheck(const std::string& component);

private:
    static void checkCPU();
    static void checkMemory();
    static void checkDisk();
    static void checkGPU();
    static void checkTemperature();
    static void checkSMART();
    static void logToFile(const std::string& content);
};

#endif // HARDWARE_INFO_H
