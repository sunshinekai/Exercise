#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>

using namespace std;

void func(char **m)
{
	++m;
	cout << *m << endl;
}

int func(int a)
{
	a ^= (1 << 5) - 1;
	return a;
}

int main()
{
	static char *a[] = { "morning", "afternoon", "evening" };
	char **p; 
	p = a;
	func(p);
	cout << func(21) << endl;
	return 0;
}