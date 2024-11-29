// 文件路径：src/self_test.cpp

#include "self_test.h"
#include <iostream>
#include <fstream>
#include "system_info.h"  // 假设您已有 system_info.cpp 模块
#include "performance_monitor.h"  // 假设您已有 performance_monitor.cpp 模块
#include "network_tools.h"  // 假设您已有 network_tools.cpp 模块

bool SelfTest::runAllTests() {
    bool result = true;

    // 进行系统信息检测
    if (!testSystemInfo()) {
        logError("系统信息检测失败");
        result = false;
    }

    // 进行性能监控检测
    if (!testPerformanceMonitor()) {
        logError("性能监控检测失败");
        result = false;
    }

    // 进行网络工具检测
    if (!testNetworkTools()) {
        logError("网络工具检测失败");
        result = false;
    }

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

bool SelfTest::testPerformanceMonitor() {
    try {
        // 尝试启动性能监控（这里只做简单的模拟）
        PerformanceMonitor::startMonitoring();
        return true;
    } catch (...) {
        return false;
    }
}

bool SelfTest::testNetworkTools() {
    try {
        // 尝试运行网络工具（这里只做简单的 ping 测试）
        NetworkTools::runNetworkDiagnostics();
        return true;
    } catch (...) {
        return false;
    }
}

void SelfTest::logError(const std::string& message) {
    std::ofstream logFile("error_log.txt", std::ios_base::app);
    if (logFile.is_open()) {
        logFile << message << std::endl;
        logFile.close();
    }
}
