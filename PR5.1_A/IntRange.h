#pragma once
#include <iostream>
#include <string>

using namespace std;

class IntRange
{
	int first, second;
public:
	IntRange();
	IntRange(int, int);
	IntRange(const IntRange&);
	~IntRange();

	int getfirst() const { return first; };
	int getsecond() const { return second; };
	void setfirst(int);
	void setsecond(int);

	operator string() const;

	void rangeCheck1();
	void rangeCheck2();
	void rangeCheck3();

	friend ostream& operator << (ostream&, const IntRange&);
	friend istream& operator >> (istream&, IntRange&);

};


