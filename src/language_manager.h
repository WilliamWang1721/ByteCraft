// 文件路径：src/language_manager.h

#ifndef LANGUAGE_MANAGER_H
#define LANGUAGE_MANAGER_H

#include <map>
#include <string>

class LanguageManager {
public:
    void setLanguage(int langChoice);
    std::string getText(const std::string& key) const;

private:
    std::map<std::string, std::string> lang;
};

#endif // LANGUAGE_MANAGER_H
