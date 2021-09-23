# C-c-b-i-code-C-
Lưu trữ những dòng code đã từng làm qua
__________________ FILE *.H __________________
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

__________________ FILE *.CPP __________________
#include "Rational.h"

int GCD(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void Rational::reduce() 
{
    int gcd = GCD(this->numberator, this->denominator);
    this->numberator /= gcd;
    this->denominator /= gcd;
}
Rational Rational::operator + (Rational obj) 
{
    int tuso= this->numberator * obj.denominator + this->denominator * obj.numberator;
    int mauso = this->denominator * obj.denominator;
    return Rational(tuso, mauso);
}
Rational Rational::operator - (Rational obj) 
{
    int tuso = this->numberator * obj.denominator - this->denominator * obj.numberator;
    int mauso = this->denominator * obj.denominator;
    return Rational(tuso, mauso);
}
Rational Rational::operator * (Rational obj) 
{
    int tuso = this->numberator * obj.numberator;
    int mauso = this->denominator * obj.denominator;
    return Rational(tuso, mauso);
}
Rational Rational::operator / (Rational obj)
{
    int tuso = this->numberator * obj.denominator;
    int mauso = this->denominator * obj.numberator;
    if (mauso == 0) return Rational(); // chia cho 0
    return Rational(tuso, mauso);
}
bool Rational::operator < (const Rational& obj) 
{
    int a = this->numberator - this->denominator;
    int b = obj.numberator - obj.denominator;
    return (a < b);
}
bool Rational::operator > (const Rational& obj)
{
    return !(*this < obj);
}
bool Rational::operator == (const Rational& obj) 
{
    int a = this->numberator * obj.denominator;
    int b = obj.numberator * this->denominator;
    return (a == b);
}
bool Rational::operator != (const Rational& obj) 
{
    return !(*this == obj);
}
Rational Rational::operator + (int integer_num) 
{
    Rational plus;
    plus.numberator = this->denominator * integer_num;
    plus.denominator = this->denominator;
    plus = plus + *this;
    plus.reduce();
    return plus;
}
Rational operator + (int integer_num, Rational obj) 
{
    return (obj + integer_num);
}

istream& operator >> (istream& in, Rational& obj) 
{
    cout << "Tu so: ";
    in >> obj.numberator;
    cout << "Mau so: ";
    in >> obj.denominator;
    return in;
}
ostream& operator << (ostream& out, const Rational& obj) 
{
    if (obj.denominator == 1) {
        out << obj.numberator;
        return out;
    }
    else if (obj.numberator*obj.denominator == 0) {
        out << 0.0;
        return out;
    }
    out << obj.numberator << "/" << obj.denominator;
    return out;
}

bool Rational::isNegative() 
{
    return (this->numberator * this->denominator) < 0;
}
Rational::operator double() 
{
    if (this->denominator == 0) return 0.0;
    return static_cast<double>(this->numberator) / this->denominator;
}

