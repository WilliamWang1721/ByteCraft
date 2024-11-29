// 文件路径：src/main.cpp

#include <iostream>
#include "language_manager.h"

int main() {
    int choice = -1;
    int langChoice = 0;

    LanguageManager langManager;

    // 选择语言
    std::cout << "选择语言: 1. 中文 2. English" << std::endl;
    std::cin >> langChoice;
    langManager.setLanguage(langChoice);

    while (choice != 0) {
        std::cout << "=== " << langManager.getText("menu.title") << " ===" << std::endl;
        std::cout << "1. " << langManager.getText("menu.system_info") << std::endl;
        std::cout << "2. " << langManager.getText("menu.performance_monitor") << std::endl;
        std::cout << "3. " << langManager.getText("menu.network_tools") << std::endl;
        std::cout << "0. " << langManager.getText("menu.exit") << std::endl;

        std::cout << langManager.getText("menu.select_option") << ": ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "查看系统信息..." << std::endl;
                break;
            case 2:
                std::cout << "开始性能监控..." << std::endl;
                break;
            case 3:
                std::cout << "运行网络诊断..." << std::endl;
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
