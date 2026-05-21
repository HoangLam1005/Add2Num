#include "MyBigNumber.h"
#include "Logger.h"
#include <algorithm>

// Hàm cộng hai số được biểu diễn dưới dạng chuỗi, cộng từng chữ số từ phải sang trái.
// Hàm sử dụng Logger để ghi lại từng bước và kết quả cuối cùng.
std::string MyBigNumber::sum(const std::string& stn1, const std::string& stn2) {
    Logger& log = Logger::getInstance();
    log.info("Phep tinh: " + stn1 + " + " + stn2);

    std::string result;
    int carry = 0;
    int i = (int)stn1.size() - 1;
    int j = (int)stn2.size() - 1;
    int step = 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int d1 = (i >= 0) ? (stn1[i--] - '0') : 0;
        int d2 = (j >= 0) ? (stn2[j--] - '0') : 0;
        int oldCarry = carry;
        int total = d1 + d2 + carry;

        carry = total / 10;
        result += char('0' + total % 10);

        // Log tung buoc
        std::string msg = "Buoc " + std::to_string(step++) + ": " + std::to_string(d1) + " + " + std::to_string(d2);
        if (oldCarry > 0) msg += " + nho " + std::to_string(oldCarry);
        msg += " = " + std::to_string(total);
        if (carry > 0) msg += ", nho " + std::to_string(carry);
        log.info(msg);
    }

    std::reverse(result.begin(), result.end());
    log.info("Ket qua: " + result);
    return result;
}
