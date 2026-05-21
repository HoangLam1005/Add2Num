#include "MyBigNumber.h"
#include "Logger.h"
#include <iostream>
#include <string>

static int total = 0, passed = 0, failed = 0;

void test(const std::string& a, const std::string& b, const std::string& expected) {
    ++total;
    MyBigNumber calc;
    std::string got = calc.sum(a, b);
    if (got == expected) {
        ++passed;
        std::cout << "[PASS] " << total << ". " << a << " + " << b << " = " << got << std::endl;
    } else {
        ++failed;
        std::cout << "[FAIL] " << total << ". " << a << " + " << b << std::endl;
        std::cout << "       Expected: " << expected << std::endl;
        std::cout << "       Got:      " << got << std::endl;
    }
}

int main() {
    Logger::getInstance().setConsoleOutput(false);

    std::cout << "============================================" << std::endl;
    std::cout << "       Unit Tests - MyBigNumber::sum()      " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;

    test("1234",  "897",   "2131");     // Ví dụ trong đề bài
    test("0",     "0",     "0");        // Kiểm tra trường hợp cộng 0
    test("4",     "5",     "9");        // Phép toán 1 chữ số không nhớ
    test("9",     "9",     "18");       // Phép toán 1 chữ số có nhớ
    test("123",   "456",   "579");      // Phép toán không nhớ
    test("999",   "1",     "1000");     // Phép toán có nhớ
    test("5",     "99999", "100004");   // Phép toán chênh lệch độ dài giữa 2 số 
    test("50000", "50000", "100000");   // 
    test("11111", "22222", "33333");    // 
    test("10001", "9999",  "20000");    // 

    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  Tong hop: " << total << " tests | "
              << "PASS: " << passed << " | FAIL: " << failed << std::endl;
    std::cout << "============================================" << std::endl;

    return (failed > 0) ? 1 : 0;
}
