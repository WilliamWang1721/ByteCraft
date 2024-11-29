// 文件路径：src/main.cpp

#include <iostream>
#include "hardware_info.h"
#include "language_manager.h"

int main() {
    int choice = -1;
    int langChoice = 0;

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

        switch (choice) {
            case 1:
                HardwareInfo::performBasicCheck();
                break;
            case 2:
                HardwareInfo::performFullCheck();
                break;
            case 3:
                std::cout << "请输入要检测的硬件（CPU, Memory, Disk, GPU）: ";
                std::string component;
                std::cin >> component;
                HardwareInfo::performSelectiveCheck(component);
                break;
            case 0:
                std::cout << langManager.getText("menu.exit_message") << std::endl;
                break;
            default:
                std::cout << langManager.getText("menu.invalid_option") << std::endl;
        }
    }

    return 0;
}
