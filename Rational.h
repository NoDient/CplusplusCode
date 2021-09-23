#pragma once
#include <iostream>
#include <fstream>
using namespace std;
int GCD(int, int);

class Rational 
{
	int numberator; // tử số
	int denominator; // mẫu số
	void reduce(); // rút gọn phân số
public:
	// Constructtor mặc định
	Rational(): numberator(0), denominator(1) {}
	Rational(int a, int b): numberator(a), denominator(b) {}
	// Copy Constructor
	Rational(const Rational& obj):
		numberator(obj.numberator),
		denominator(obj.denominator)
	{}
	// Destructor
	~Rational()
	{
		numberator = 0;
		denominator = 1;
	}
	void xuat() {
		cout << numberator << "/" << denominator << endl;
	}
	Rational operator + (Rational obj);
	Rational operator - (Rational obj);
	Rational operator * (Rational obj);
	Rational operator / (Rational obj);

	bool operator < (const Rational& obj);
	bool operator > (const Rational& obj);
	bool operator == (const Rational& obj);
	bool operator != (const Rational& obj);

	Rational operator + (int); // rational + integer
	friend Rational operator + (int, Rational); // integer + rational

	operator double();

	friend istream& operator >> (istream& in, Rational& obj);
	friend ostream& operator << (ostream& out, const Rational& obj);

	bool isNegative();

};