// 文件路径：src/modules/system_info.cpp
#include <iostream>
#include "system_info.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

namespace SystemInfo {

void printSystemInfo() {
    std::cout << "=== 系统信息 ===" << std::endl;
#ifdef _WIN32
    SYSTEM_INFO si;
    GetSystemInfo(&si);
    std::cout << "处理器架构：" << si.dwProcessorType << std::endl;
#else
    struct utsname buffer;
    if (uname(&buffer) == 0) {
        std::cout << "系统名称：" << buffer.sysname << std::endl;
        std::cout << "主机名：" << buffer.nodename << std::endl;
        std::cout << "版本：" << buffer.version << std::endl;
    } else {
        std::cerr << "无法获取系统信息。" << std::endl;
    }
#endif
}

} // namespace SystemInfo
