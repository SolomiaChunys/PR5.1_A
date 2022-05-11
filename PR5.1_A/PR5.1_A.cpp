#include <iostream>
#include "IntRange.h";

using namespace std;

int main()
{
	IntRange in(1, 5);
	in.rangeCheck1();
	in.rangeCheck2();
	in.rangeCheck3();

	cin.get();
	return 0;
}