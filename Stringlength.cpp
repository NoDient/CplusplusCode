#include <iostream>
using namespace std;
#define MAX_STR 50

int length(const char* str){
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}
int count_char(const char* str, char c){
    int len = length(str), count = 0;
    for (int i = 0; i < len; i++){
        if (str[i] == c) count++;
    }
    return count;
}
void printCountNum(const char* str) {
    int num[] = {0,0,0,0,0,0,0,0,0,0};
    int len = length(str);
    for (int i = 0; i < len; i++){
        if (str[i] >= '0' && str[i] <= '9'){
            num[str[i] - 48]++;
        }
    }
    for (int i = 0; i < 10; i++){
        if (num[i]) cout << "So lan xuat hien cua " << i << ": " << num[i] << " lan\n";
    }
}

int main() {
    char str[MAX_STR];
    cout << "\nNhap vao 1 chuoi: ";
    cin.getline(str, MAX_STR-1); // nhập chuỗi vào bàn phím
    cout << "Chuoi sau khi nhap: ";
    cout << str << endl; // xuất chuỗi ra màn hình
    cout << "Do dai cua chuoi vua nhap: ";
    cout << length(str) << endl; // xuất ra độ dài chuỗi
    cout << "So ky tu trang: ";
    cout << count_char(str, ' ') << endl; //  xuất ra số lượng dấu cách
    printCountNum(str);
    return 0;
}
