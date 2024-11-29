#ifndef HARDWARE_INFO_H
#define HARDWARE_INFO_H

#include <string>

class HardwareInfo {
public:
    static void performBasicCheck();    // 执行常规检测
    static void performFullCheck();     // 执行全面深度检测
    static void performSelectiveCheck(const std::string& component);  // 执行选择性检测

private:
    static void checkCPU();             // 检测 CPU
    static void checkMemory();          // 检测内存
    static void checkDisk();            // 检测硬盘
    static void checkGPU();             // 检测 GPU
    static void checkTemperature();     // 检测温度
    static void checkSMART();           // 检测硬盘健康（S.M.A.R.T）
    static void logToFile(const std::string& content);  // 将结果输出到文件
    static std::string getCommandOutput(const std::string& command);  // 执行命令并获取输出
};

#endif // HARDWARE_INFO_H
