#include "IntRange.h"
#include "IntRange.h"
#include <sstream>
#include <iostream>

class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}
	string What() { return message; }
};

class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}
	string What() { return message; }
};
IntRange::IntRange()
{
	first = 0;
	second = 5;
}

IntRange::IntRange(int f , int s)
{
	try
	{
		if (f < s)
		{
			first = f;
			second = s;
		}
		else
		{
			throw E("second greater than first");
		}
	}
	catch (E a)
	{
		cerr << a.what() << endl;
	}
}

IntRange::IntRange(const IntRange& f)
{
	first = f.first;
	second = f.second;
}

IntRange::~IntRange()
{ }

void IntRange::setfirst(int f)
{
	first = f;
}

void IntRange::setsecond(int s)
{
	second = s;
}

IntRange::operator string () const
{
	stringstream sss;
	sss << "first = " << first << endl;
	sss << "second = " << second << endl;

	return sss.str();
}

ostream& operator << (ostream& out, const IntRange& f)
{
	out << string(f);
	return out;
}

istream& operator >> (istream& in, IntRange& f)
{
	cout << " First = "; in >> f.first;
	cout << "Second = "; in >> f.second;
	cout << endl;
	return in;
}

void IntRange::rangeCheck1()
{
	int n;
	cout << "Number: "; cin >> n;
	try 
	{
		if (n >= first && n < second)
		{
			cout << "Yessss" << endl;
		}
		else
		{
			throw new bad_exception();
		}
	}
	catch (bad_exception* a)
	{
		cout << a->what() << endl;
	}
};

void IntRange::rangeCheck2()
{
	int n;
	cout << "Number: "; cin >> n;
	try
	{
		if (n >= first && n < second)
		{
			cout << "Yessss" << endl;
		}
		else
		{
			throw Error("Enter the correct number!!!");
		}
	}
	catch (Error a)
	{
		cout << a.What() << endl;
	}
};

void IntRange::rangeCheck3()
{
	int n;
	cout << "Number: "; cin >> n;
	try
	{
		if (n >= first && n < second)
		{
			cout << "Yessss" << endl;
		}
		else
		{
			throw Error("Number isn`t in range ((( ");
		}
	}
	catch (Error a)
	{
		cout << a.What() << endl;
	}
};