
#include<string> 
#include <iostream>
using namespace std;

// http://31.154.73.178:8000/?backend=5670&exercise=EX2

class CircularInt {
	int min;
	int max;
	int number;
public:
	CircularInt(CircularInt &p)
	{
		this->number = p.number;
		this->max = p.max;
		this->min = p.min;
	}

	CircularInt(int x, int y) {
		this->number = 1;
		this->min = x;
		this->max = y;
	}

	const CircularInt operator --(int)
	{
		CircularInt newone(*this);
		int num;

		if (number == min) {
			num = max;
		}
		else {
			num = number - 1;
		}
		number = num;
		return newone;
	}

	const CircularInt operator ++(int)
	{
		CircularInt newone(*this);
		int num;

		if (number == max) {
			num = min;
		}
		else {
			num = number + 1;
		}
		number = num;
		return newone;
	}
	CircularInt& operator ++()
	{
		int p;
		if (number == max) {
			p = min;
			number = p;
		}
		else
			p = number + 1;
		number = p;

		return *this;
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


	CircularInt operator-() {
		CircularInt temp(min, max);
		temp.number = number;

		temp.number = (-number) % max;
		if (temp.number == 0) {
			temp.number = max;
			return temp;
		}
		temp.number = max + temp.number;

		return temp;
	}

	friend ostream &operator<<(ostream &output, const CircularInt &temp) {
		output << temp.number;
		return output;
	}

	friend ostream &operator>>(ostream &output, const CircularInt &temp) {
		output << temp.number;
		return output;
	}

	friend CircularInt operator - (const int less, CircularInt &p)
	{
		CircularInt newCir(p.min, p.max);
		newCir.number = p.number;
		if (less - p.number < p.min) {
			newCir.number = p.max - (p.number - less);
		}
		else {
			newCir.number = less - p.number;
		}
		return newCir;
	}


	CircularInt operator-(int a)
	{
		int num = this->number - a;
		if (num < 0) { this->number = abs(num); }
		else if (num == 0) { 
			this->number = this->max; 
		}
		else {
			num = num % this->max;
			if (num == 0) { this->number = this->max; }
			else { this->number = num; }
		}
		return *this;
	}

	CircularInt operator-(CircularInt &p)
	{
		CircularInt temp(*this);

		int num = temp.number - p.number;

		if (num < 0) {
			temp.number = abs(num);
		}
		else if (num == 0) { temp.number = temp.max; }
		else {
			num = num % temp.max;
			if (num == 0) { temp.number = temp.max; }
			else { temp.number = num; }
		}

		return temp;
	}

	CircularInt operator -=(int m) {
		int sum, num = number - m;
		num = num % (max)+min;
		if (num > 0) {
			sum = num;
		}
		else
			sum = max + num;

		number = sum;
		return *this;
	}

	CircularInt operator -=(CircularInt& p) {
		int sum, num = number - p.number;
		num = num % (max)+min;
		if (num > 0) {
			sum = num;
		}
		else
			sum = max + num;

		number = sum;
		return *this;
	}



	CircularInt operator+(CircularInt p)
	{
		CircularInt temp(p);
		temp = temp + p.number;

		return temp;
	}

	CircularInt operator+(int a)
	{
		CircularInt temp(min, max);
		if ((number + a) % max == 0)
			temp.number = max;
		else {
			temp.number = (number + a) % max;
		}

		return temp;
	}

	friend CircularInt operator+(int a, CircularInt &p)
	{
		CircularInt temp(p.min, p.max);
		temp.number = a + p.number;
		if (temp.number > p.max)
			temp.number = temp.number%p.max;

		return temp;
	}

	CircularInt& operator += (int m) {
		CircularInt temp(*this);
		temp = temp + m;

		this->number = temp.number;
		return *this;
	}

	CircularInt& operator += (CircularInt& p) {
		CircularInt temp(*this);
		temp = temp + p.number;

		this->number = temp.number;
		return *this;
	}

	CircularInt operator * (int m) {
		CircularInt temp(*this);

		int num = (temp.number*m) % max;
		if (num == 0) {
			temp.number = max;
		}
		else {
			temp.number = num;
		}

		return temp;
	}

	CircularInt operator *(CircularInt& p) {
		CircularInt temp(*this);
		temp = temp * p.number;

		return temp;
	}

	CircularInt& operator *=(CircularInt& p) {
		int num = (number * p.number) % max;
		if (num == 0) {
			number = max;
		}
		else {
			number = num;
		}
		return *this;
	}

	CircularInt& operator *=(int m) {
		int num = (number * m) % max;
		if (num == 0) {
			number = max;
		}
		else {
			number = num;
		}
		return *this;
	}

	friend CircularInt operator / (int d, CircularInt& p) {
		CircularInt temp(p.min,p.max);
		int num = d / p.number;
		temp.number = num;

		return temp;
	}


	CircularInt& operator /= (int m) {

		int num = (number / m) % max;
		if (num == 0) {
			num = max;
		}
		number = num;
		return *this;
	}



	bool operator == (CircularInt &p) {
		return (this->number == p.number);
	}

	bool operator == (int num) {
		return (this->number == num);
	}

	friend bool operator == (int num, CircularInt &p) {
		return (num == p.number);
	}

	CircularInt operator = (int a) {
		this->number = a;
	}

	bool operator !=(CircularInt &p) {
		return  (this->number != p.number);
	}

	bool operator != (int num) {
		if (this->number != num);
	}

	friend bool operator != (int num, CircularInt &p) {
		return (num != p.number);
	}

	bool operator > (CircularInt &p) {
		return  (this->number > p.number);
	}

	bool operator > (int num) {
		if (this->number > num);
	}

	friend bool operator > (int num, CircularInt &p) {
		return (num > p.number);
	}

	bool operator < (CircularInt &p) {
		return  (this->number< p.number);
	}

	bool operator < (int num) {
		if (this->number < num);
	}

	friend bool operator < (int num, CircularInt &p) {
		return (num < p.number);
	}

	bool operator >=(CircularInt &p) {
		return  (this->number >= p.number);
	}

	bool operator >= (int num) {
		if (this->number >= num);
	}

	friend bool operator >= (int num, CircularInt &p) {
		return (num >= p.number);
	}

	bool operator <=(CircularInt &p) {
		return  (this->number <= p.number);
	}

	bool operator <= (int num) {
		if (this->number <= num);
	}

	friend bool operator <= (int num, CircularInt &p) {
		return (num <= p.number);
	}

};