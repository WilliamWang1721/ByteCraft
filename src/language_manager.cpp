// 文件路径：src/language_manager.cpp

#include "language_manager.h"
#include <iostream>

void LanguageManager::setLanguage(int langChoice) {
    if (langChoice == 1) {
        // 中文
        lang["menu.title"] = "字节工具";
        lang["menu.system_info"] = "查看系统信息";
        lang["menu.performance_monitor"] = "性能监控";
        lang["menu.network_tools"] = "网络工具";
        lang["menu.exit"] = "退出";
        lang["menu.select_option"] = "请选择功能";
        lang["menu.exit_message"] = "感谢使用字节工具！";
        lang["menu.invalid_option"] = "无效的选项，请重试。";
    } else {
        // 英文
        lang["menu.title"] = "Byte Toolbox";
        lang["menu.system_info"] = "System Info";
        lang["menu.performance_monitor"] = "Performance Monitor";
        lang["menu.network_tools"] = "Network Tools";
        lang["menu.exit"] = "Exit";
        lang["menu.select_option"] = "Please select an option";
        lang["menu.exit_message"] = "Thank you for using Byte Toolbox!";
        lang["menu.invalid_option"] = "Invalid option, please try again.";
    }
}

std::string LanguageManager::getText(const std::string& key) const {
    auto it = lang.find(key);
    if (it != lang.end()) {
        return it->second;
    } else {
        return "Text not found!";
    }
}
