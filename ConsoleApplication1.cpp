#include <iostream>

#define _DEBUG 1

using namespace std;

int format(unsigned char& param)
{
	int _param = 0;
	_param = (int)param;
	if (_param - 48 > -1 && _param - 48 < 10)
	{
		return _param - 48;
	}
	else {
		//cout << "[ERROR]: int format(unsigned char& param, size_t& size)\n";
		return 0;
	}
}

unsigned char format(int param)
{
	if (param > 9)
	{
		return '0';
	}
	return param + 48;
}

void transfer(unsigned char* buffer, unsigned char* array, size_t& size)
{
	memcpy(buffer, array, size);
}

int main()
{
	size_t size = 2;
	size_t temp = 0;
	size_t array_size = 2;
	
	unsigned int N = 0;
	unsigned int breakpoint = 0;
	unsigned int k = 0;
	bool mode = false;
	cout << "Which wanna use mode? \n0 - Find number fibonacci\n1 - Find K-zero's in number\n";
	cin >> mode;
	if (mode)
	{
		cout << "Enter K: ";
		cin >> k;
	}

	cout << "Enter size: ";
	cin >> temp;
	array_size = (array_size < 1) ? 2 : temp;
	cout << "Enter N: ";
	cin >> N;

	unsigned char* a = new unsigned char[array_size];
	unsigned char* b = new unsigned char[array_size];
	unsigned char* c = new unsigned char[array_size];
	unsigned char* d = new unsigned char[array_size];

	for (size_t i = 0; i < array_size; i++)
	{
		a[i] = '0';
		b[i] = '0';
		c[i] = '0';
		d[i] = '0';
	}
	b[array_size - 1] = 49;
	a[array_size] = '\0';
	b[array_size] = '\0';
	c[array_size] = '\0';
	d[array_size] = '\0';

	int count = 0;
	bool flag = false;
	int remainder = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t t = array_size - size, l = 1; l < size; t++, l++)
		{
			if (mode)
			{
				if (a[t + 1] == '0' && flag == false)
				{
					count += 1;
					if (count == k)
					{
						transfer(d, a, size);
						flag = true;
					}
				}
				else
				{
					count = 0;
				}
			}
#if _DEBUG
			cout << a[t + 1];
#endif // _DEBUG



		}
#if _DEBUG
		cout << " | ";
		for (size_t t = array_size - size, l = 1; l < size; t++, l++)
		{
			cout << b[t + 1];
		}

		cout << endl;
#endif // _DEBUG

		transfer(c, b, array_size);
		count = 0;
		for (size_t j = array_size, l = 0; l < size; j--, l++)
		{
			if (format(a[j - 1]) + format(b[j - 1]) + remainder < 10)
			{
				b[j - 1] = format(format(a[j - 1]) + format(b[j - 1]) + remainder);
				remainder = 0;
			}
			else
			{
				b[j - 1] = format((format(a[j - 1]) + format(b[j - 1]) + remainder) % 10);
				remainder = 1;
			}
		}
		
		if (flag)
		{
			breakpoint = i;
			break;
		}

		if (format(b[array_size - size]) > 0)
		{
			size += 1;
		}
		transfer(a, c, array_size);
	}

	if (mode)
	{
		cout << "\n";
		cout << "FLAG answer = ";

		for (size_t t = array_size - size, l = 1; l < size; t++, l++)
		{
			cout << d[t + 1];
		}

		cout << "\n";
		cout << "FLAG = " << flag << endl;
		cout << "N = " << breakpoint;
	}
	else
	{
		cout << endl;
		cout << "Answer = ";

		for (size_t t = array_size - size, l = 1; l < size; t++, l++)
		{
			cout << a[t + 1];
		}
	}

	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
}