#include <iostream>
#include "hardware_info.h"
#include "language_manager.h"
#include "performance_monitor.h"  // 如果需要性能监控模块
#include "network_tools.h"  // 如果需要网络工具模块

int main() {
    int choice = -1;
    int langChoice = 0;

    // 创建语言管理器
    LanguageManager langManager;
    
    // 选择语言
    std::cout << "选择语言: 1. 中文 2. English" << std::endl;
    std::cin >> langChoice;
    langManager.setLanguage(langChoice);

    // 提供硬件检测选项
    while (choice != 0) {
        std::cout << "=== " << langManager.getText("menu.title") << " ===" << std::endl;
        std::cout << "1. 常规硬件检测" << std::endl;
        std::cout << "2. 全面深度硬件检测" << std::endl;
        std::cout << "3. 选择性硬件检测" << std::endl;
        std::cout << "0. " << langManager.getText("menu.exit") << std::endl;

        std::cout << langManager.getText("menu.select_option") << ": ";
        std::cin >> choice;

        // 确保 switch 内部变量在每次进入时初始化
        switch (choice) {
            case 1:  // 常规硬件检测
                HardwareInfo::performBasicCheck();
                break;
            case 2:  // 全面深度硬件检测
                HardwareInfo::performFullCheck();
                break;
            case 3:  // 选择性硬件检测
                {
                    // 确保组件在进入 case 前初始化
                    std::string component;
                    std::cout << "请输入要检测的硬件（CPU, Memory, Disk, GPU）: ";
                    std::cin >> component;
                    HardwareInfo::performSelectiveCheck(component);
                    break;
                }
            case 0:  // 退出
                std::cout << langManager.getText("menu.exit_message") << std::endl;
                break;
            default:  // 无效选项
                std::cout << langManager.getText("menu.invalid_option") << std::endl;
        }
    }

    return 0;
}
