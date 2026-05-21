# Add2Num — Chương trình cộng 2 số tự nhiên theo thứ tự từ phải sang trái

**Phiên bản:** `0.0.1`

## 1. Mô tả chương trình

### Thuật toán sử dụng

Hàm `MyBigNumber::sum(stn1, stn2)` sử dụng thuật toán **Cộng chuỗi số bằng hai con trỏ ngược (Two-Pointer Reverse Traversal)** kết hợp **Biến nhớ carry**.

**Luồng xử lý trong code:**

1. **Khởi tạo hai chỉ số** `i` và `j` trỏ đến **ký tự cuối cùng** (hàng đơn vị) của `stn1` và `stn2`:
   ```cpp
   int i = (int)stn1.size() - 1;
   int j = (int)stn2.size() - 1;
   ```

2. **Vòng lặp `while`** chạy khi còn chữ số chưa xử lý hoặc còn số nhớ:
   ```cpp
   while (i >= 0 || j >= 0 || carry > 0)
   ```

3. **Trích chữ số** — chuyển ký tự thành số bằng phép trừ mã ASCII. Nếu chuỗi nào đã hết thì coi chữ số đó là `0`:
   ```cpp
   int d1 = (i >= 0) ? (stn1[i--] - '0') : 0;
   int d2 = (j >= 0) ? (stn2[j--] - '0') : 0;
   ```

4. **Tính tổng** tại vị trí hiện tại (hai chữ số + số nhớ từ bước trước):
   ```cpp
   int total = d1 + d2 + carry;
   ```

5. **Tách kết quả** bằng phép chia lấy dư và chia nguyên:
   - `total % 10` là phần đơn vị của phép toán cộng tại vị trí hiện tại và nối vào chuỗi `result`
   - `total / 10` là phần chục của phép toán cộng tại vị trí hiện tại và được lưu vào số nhớ `carry` để truyền sang bước tiếp theo
   ```cpp
   carry = total / 10;
   result += char('0' + total % 10);
   ```

6. **Đảo ngược chuỗi kết quả** — vì các chữ số được nối từ hàng đơn vị lên, ta cần `reverse` để có đáp án đúng của phép toán:
   ```cpp
   std::reverse(result.begin(), result.end());
   ```

**Ví dụ minh họa** với `sum("1234", "897")`:

| Bước | i | j | d1 | d2 | carry (cũ) | total | Kết quả nối | carry (mới) |
|:----:|:-:|:-:|:--:|:--:|:----------:|:-----:|:-----------:|:-----------:|
| 1 | 3 | 2 | 4 | 7 | 0 | 11 | `"1"` | 1 |
| 2 | 2 | 1 | 3 | 9 | 1 | 13 | `"13"` | 1 |
| 3 | 1 | 0 | 2 | 8 | 1 | 11 | `"131"` | 1 |
| 4 | 0 | -1 | 1 | 0 | 1 | 2 | `"1312"` | 0 |

Sau khi `reverse("1312")` thì ta sẽ được kết quả đúng của phép toán là **`"2131"`**.

### Độ phức tạp của thuật toán

| | Giá trị | Giải thích |
|---|---------|-----------|
| **Thời gian** | **O(max(n, m))** | Vòng `while` chạy đúng `max(n, m)` lần (cộng tối đa 1 lần nữa nếu carry cuối). Mỗi lần lặp chỉ thực hiện phép cộng, chia, lấy dư — đều là O(1). |
| **Bộ nhớ** | **O(max(n, m))** | Chuỗi `result` chứa tối đa `max(n, m) + 1` ký tự. Không dùng thêm mảng phụ nào khác. |

---

## 2. Cấu trúc thư mục

```
Add2Num2/
├── .gitignore          
├── CMakeLists.txt     
├── README.md           
├── src/                
│   ├── Logger.h            
│   ├── MyBigNumber.h       
│   ├── MyBigNumber.cpp     
│   └── main.cpp            
└── tests/              
    └── test.cpp            
```

---

## 3. Tải chương trình về máy

Mở **PowerShell** hoặc **Command Prompt** để chạy lệnh sau:

```
git clone https://github.com/HoangLam1005/Add2Num.git
```

Sau khi chạy xong, thư mục `Add2Num` sẽ xuất hiện trên máy bạn.

---

## 4. Yêu cầu về môi trường trước khi biên dịch

Cài đặt trình biên dịch **g++ (MinGW)** trên máy Windows.

| Bước | Hướng dẫn |
|------|-----------|
| **Kiểm tra** | Mở PowerShell, gõ `g++ --version`. Nếu hiện phiên bản g++ thì máy đã có sẵn g++, bỏ qua bước cài đặt. |
| **Cài đặt** | Tải tại https://winlibs.com rồi giải nén zip và thêm thư mục `bin` vào biến môi trường `PATH`. |

---

## 5. Biên dịch và kiểm thử chương trình

Mở **PowerShell**, di chuyển vào thư mục project:

```
cd "đường dẫn tới thư mục Add2Num"
```

### 5.1 Biên dịch

Chạy 2 lệnh sau để biên dịch chương trình

```
g++ -std=c++17 -O2 -o add2num.exe src/main.cpp src/MyBigNumber.cpp -Isrc
g++ -std=c++17 -O2 -o test_add2num.exe tests/test.cpp src/MyBigNumber.cpp -Isrc
```

Nếu không có lỗi hiện ra → biên dịch thành công.

### 5.2 Chạy chương trình

```
.\add2num.exe
```

Nhập số thứ nhất rồi enter để nhập số thứ hai. Ví dụ:

```
=== Chuong trinh tinh toan cong 2 so tu nhien ===
Nhap so thu nhat : 1234
Nhap so thu hai  : 897

[21/05/2026 14:00:00] Phep tinh: 1234 + 897
[21/05/2026 14:00:00] Buoc 1: 4 + 7 = 11, nho 1
[21/05/2026 14:00:00] Buoc 2: 3 + 9 + nho 1 = 13, nho 1
[21/05/2026 14:00:00] Buoc 3: 2 + 8 + nho 1 = 11, nho 1
[21/05/2026 14:00:00] Buoc 4: 1 + 0 + nho 1 = 2
[21/05/2026 14:00:00] Ket qua: 2131

=> 1234 + 897 = 2131
```

### 5.3 Chạy kiểm thử tự động

```
.\test_add2num.exe
```

Kết quả đúng — 10/10 PASS:

```
============================================
       Unit Tests - MyBigNumber::sum()
============================================

[PASS] 1. 1234 + 897 = 2131
[PASS] 2. 0 + 0 = 0
[PASS] 3. 4 + 5 = 9
[PASS] 4. 9 + 9 = 18
[PASS] 5. 123 + 456 = 579
[PASS] 6. 999 + 1 = 1000
[PASS] 7. 5 + 99999 = 100004
[PASS] 8. 50000 + 50000 = 100000
[PASS] 9. 11111 + 22222 = 33333
[PASS] 10. 10001 + 9999 = 20000

============================================
  Tong hop: 10 tests | PASS: 10 | FAIL: 0
============================================
```
