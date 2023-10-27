#include <iostream>
#include "headers/INT.h"

using namespace std;

int main()
{
	INT a = 0;
	INT b = 1;
	INT c = 0;

	int N = 0;

	cout << "Enter N: ";
	cin >> N;

	for (size_t i = 0;; i++)
	{
		c = b;
		b = a + b;
		a = c;
		if (a[N ])
		{
			break;
		}
	}
	cout << "\n";

	cout << "Answer = ";
	a.screen();
}