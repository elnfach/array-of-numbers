#include <iostream>
#include "headers/INT.h"

using namespace std;

int main()
{
	INT a = 0;
	INT b = 1;
	INT c = 0;

	// b = 01
	// c = 01
	// b = 01 + 01
	//

	int N = 0;

	cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		c = b;
		b = a + b;
		//b.screen();
		a = c;
	}

	cout << "Answer = ";

	a.screen();
}