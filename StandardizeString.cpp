#include <iostream>
#include <cstring>
using namespace std;

// Hàm xóa các khoảng trắng đầu chuỗi
void BegStandardize(char *&str)
{
	unsigned int i = 0;
	while (str[i++] == ' ');
	str = str + i - 1;
}

// Hàm xóa khoảng trắng ở cuối chuỗi
void EndStandardize(char *str)
{
	unsigned int i = strlen(str) - 1;
	while (str[i--] == ' ');
	str[i + 2] = '\0';
}

// Hàm xóa khoảng trắng thừa trong nội dung chuỗi
void CurStandardize(char *str)
{
	unsigned int diff = 0;
	unsigned len = strlen(str) - 1;
	for (unsigned int i = 1; i < len; i++)
	{
		while (str[i] == ' ' && str[i+1] == ' ')
		{
			for (unsigned int j = i; j < len-1; j++)
			{
				str[j] = str[j+1];
			}
			str[len--] = '\0';
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

