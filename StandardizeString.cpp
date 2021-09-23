#include <iostream>
#include <cstring>
using namespace std;

// Hàm xóa các khoảng trắng đầu chuỗi 
//- LƯU Ý: CHỈ LÀM VIỆC VỚI char*, KHÔNG THỂ LÀM VIỆC VỚI char[]
// Giải thích: Vì char [] có hằng con trỏ của mảng, nên không thể thay đổi địa chỉ của con trỏ đầu tiên
void BegStandardize(char *&str) // Thay đổi giá trị của con trỏ đòi hỏi tham chiếu con trỏ (*&) hoặc dùng con trỏ bậc 2 (**)
{
	unsigned int i = 0;
	while (str[i++] == ' '); // Khi vòng lặp dừng, thì vị trí i-1 là vị trí cần tìm (vì ngay khi tìm được, thì hậu tố đã cộng thêm 1)
	str = str + i - 1; // Di chuyển con trỏ đầu đến vị trí ký tự (khác Space)
}

// Hàm xóa khoảng trắng ở cuối chuỗi
void EndStandardize(char *str)
{
	unsigned int i = strlen(str) - 1;
	while (str[i--] == ' ');
	str[i + 2] = '\0'; 
	// Lí do cộng thêm 2: Vì lúc xét là i = strlen(str) - 1, và hậu tố (--) đã vô tình trừ đi 1 trước khi dừng vòng lặp.
}

// Hàm xóa khoảng trắng thừa trong nội dung chuỗi
void CurStandardize(char *str)
{
	unsigned len = strlen(str) - 1;
	for (unsigned int i = 1; i < len; i++)
	{
		while (str[i] == ' ' && str[i+1] == ' ')
		{
			// Chép các phần tử sau lên trước 1 bậc
			for (unsigned int j = i; j < len-1; j++)
			{
				str[j] = str[j+1];
			}
			str[len--] = '\0'; // Bỏ đi phần tử thừa ở cuối sau khi chép
		}
	}
}

int main(){
	char *s = new char[100];
	cin.getline(s, 100);
	BegStandardize(s);
	CurStandardize(s);
	EndStandardize(s);
	cout << s;
	return 0;
}

