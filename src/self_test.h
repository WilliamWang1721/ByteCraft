// 文件路径：src/self_test.h

#ifndef SELF_TEST_H
#define SELF_TEST_H

#include <string>

class SelfTest {
public:
    bool runAllTests();
    
private:
    bool testSystemInfo();
    bool testPerformanceMonitor();
    bool testNetworkTools();
    void logError(const std::string& message);
};

#endif // SELF_TEST_H
