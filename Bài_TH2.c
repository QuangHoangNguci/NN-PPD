#include<stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, L;

    printf("Nhap xau: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    i = 0;
    L = strlen(str);

    if (isdigit(str[i])) { // Nếu ký hiệu đầu tiên là một chữ số
        i = i + 1; // Đọc ký hiệu tiếp theo trên xâu vào

        while (isdigit(str[i])) {
            i = i + 1; // Đọc tiếp nếu đang ở trạng thái q1 (vẫn là chữ số)
        }

        if (i == L) {
            printf("%s la so nguyen\n", str); // Đọc hết xâu vào, là số nguyên
        } else if (str[i] != '.') {
            printf("%s khong duoc doan nhan (%d)\n", str, i + 1);
        } else { // Đã đọc được dãy số và dấu ‘.’
            i = i + 1;

            while (isdigit(str[i])) {
                i = i + 1; // Đang ở trạng thái q2 (đọc phần thập phân của số thực)
            }

            if (i == L) {
                printf("%s la so thuc dau phay tinh\n", str); // Đọc hết xâu vào, là số thực
            } else {
                printf("%s khong duoc doan nhan (%d)\n", str, i + 1);
            }
        }
    } else {
        printf("%s khong duoc doan nhan (%d)\n", str, i + 1);
    }

    return 0;
}
