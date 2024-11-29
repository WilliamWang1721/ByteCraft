#include "self_test.h"
#include <iostream>
#include <fstream>
#include "system_info.h"  // 确保您已实现该模块，如果没有可以注释掉相关部分

// 如果不使用 PerformanceMonitor 和 NetworkTools，可以注释掉它们相关的部分
// #include "performance_monitor.h"
// #include "network_tools.h"

bool SelfTest::runAllTests() {
    bool result = true;

    // 进行系统信息检测
    if (!testSystemInfo()) {
        logError("系统信息检测失败");
        result = false;
    }

    // 如果没有 PerformanceMonitor 和 NetworkTools 模块，直接跳过
    // 进行性能监控检测
    // if (!testPerformanceMonitor()) {
    //     logError("性能监控检测失败");
    //     result = false;
    // }

    // 进行网络工具检测
    // if (!testNetworkTools()) {
    //     logError("网络工具检测失败");
    //     result = false;
    // }

    if (result) {
        std::cout << "所有自检通过！" << std::endl;
    } else {
        std::cout << "部分自检失败，请检查错误日志。" << std::endl;
    }

    return result;
}

bool SelfTest::testSystemInfo() {
    try {
        // 尝试获取并显示系统信息
        SystemInfo::printSystemInfo();
        return true;
    } catch (...) {
        return false;
    }
}

// 如果需要性能监控模块和网络工具模块，可以按以下方式解注释并实现相关功能
// bool SelfTest::testPerformanceMonitor() {
//     try {
//         // 尝试启动性能监控（这里只做简单的模拟）
//         PerformanceMonitor::startMonitoring();
//         return true;
//     } catch (...) {
//         return false;
//     }
// }

// bool SelfTest::testNetworkTools() {
//     try {
//         // 尝试运行网络工具（这里只做简单的 ping 测试）
//         NetworkTools::runNetworkDiagnostics();
//         return true;
//     } catch (...) {
//         return false;
//     }
// }

void SelfTest::logError(const std::string& message) {
    std::ofstream logFile("error_log.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}
