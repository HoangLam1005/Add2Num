#include "MyBigNumber.h"
#include "Logger.h"
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    Logger::getInstance().setLogFile("add2num.log");

    std::cout << "=== Chuong trinh tinh toan cong 2 so tu nhien ===" << std::endl;

    std::string stn1, stn2;
    std::cout << "Nhap so thu nhat : ";
    std::cin >> stn1;
    std::cout << "Nhap so thu hai  : ";
    std::cin >> stn2;
    std::cout << std::endl;

    MyBigNumber calc;
    std::string result = calc.sum(stn1, stn2);

    std::cout << "\n=> " << stn1 << " + " << stn2 << " = " << result << std::endl;
    return 0;
}
