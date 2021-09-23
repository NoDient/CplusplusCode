#include <iostream>
using namespace std;

// Viết hàm tìm số lớn thứ rank trong mảng các số nguyên
int FindMaxWithGivenRank(int *arr, int size, int rank = 1)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > arr[i]) count++;
		}
		if (rank-1 == count) return arr[i];
		else count = 0; // reset count
	}
}

int main()
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
	int a = FindMaxWithGivenRank(arr, 10, 6);
	cout << a << endl;
	return 0;
}
