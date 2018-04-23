#pragma once
#include <iostream>
#include<string> 
using namespace std;


class CircularInt {
	int number;
	int max, min;

public:
	CircularInt(int n, int m) {
		this->number = n;
		this->min = n;
		this->max = m;
	}

	CircularInt operator += (const int add)
	{
		int more = add % (max + 1 - min);
		if (more + number > max) {
			number = min + ((more + number) % max + 1);
		}
		else {
			number = more + number;
		}
		return *this;
	}

	CircularInt operator *= (const int mul)
	{
		int extra = (mul - 1) * number;
		return (*this + extra);
	}

	CircularInt  operator ++ (int)
	{
		++number;
		if (number > max) {
			number = min + (number % (max + 1));
		}
		return *this;
	}

	CircularInt operator + (const int add)
	{
		CircularInt newCir(min, max);
		newCir.number = number;
		int more = add % (max + 1 - min);
		if (more + number > max) {
			newCir.number = min + ((more + number) % max + 1);
		}
		else {
			newCir.number = more + number;
		}
		return newCir;
	}

	CircularInt operator + (const CircularInt add)
	{
		CircularInt newCir(min, max);
		newCir.number = number;
		int more = (add.number) % (max + 1 - min);
		if (more + number > max) {
			newCir.number = min + ((more + number) % max + 1);
		}
		else {
			newCir.number = more + number;
		}
		return newCir;
	}

	CircularInt operator - (const int less)
	{
		CircularInt newCir(min, max);
		newCir.number = number;
		int down = less % (max + 1 - min);
		if (number-down < min) {
			newCir.number = max - (number - down);
		}
		else {
			newCir.number = number - down;
		}
		return newCir;
	}

	CircularInt operator - ()
	{
		return (*this - number);
	}


	CircularInt operator / (const int a)
	{
		CircularInt newCir(min, max);
		newCir.number = number / a;
		if (newCir.number < min) {
			newCir.number = max - newCir.number;
		}
		return newCir;
	}

	friend ostream &operator<< (ostream& s, const CircularInt &a)
	{
		s << a.number;
		return s;
	}

};