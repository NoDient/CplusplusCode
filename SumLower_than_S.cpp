#include <iostream>
#include <cmath>
using namespace std;

// Return value of above limit
int ReturnAboveLimit(const int& S)
{
	if (S <= 1) return -1; // including negative number, 0 or 1
	
	float delta = 1 + 4*2*S; // described in attached file
	
	int x1 = (-1 - sqrt(delta)) / 2; // cast to integer
	int x2 = (-2*S) / x1;
	
	return x1 < x2 ? x2 : x1;
}

int main(){
	int S = 0;
	cout << "Nhap so S: ";
	cin >> S;
	int result = ReturnAboveLimit(S);
	
	if (result <= 0)
	{
		cout << "Not Found";
	}
	else
	{
		cout << result - 1;
	}
	
	cout << endl;
	return 0;
}

