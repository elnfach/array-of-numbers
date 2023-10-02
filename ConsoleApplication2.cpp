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
	for (size_t i = 0; i < size; i++)
	{
		buffer[i] = array[i];
	}
}

unsigned char* increase_size(unsigned char* array, size_t& size)
{
	unsigned char* buffer = new unsigned char[size + 1] {0};

	for (size_t i = size; i > 0; i--)
	{
		buffer[i] = array[i - 1];
	}
	delete[] array;
	return buffer;
}

int main()
{
	size_t size = 2;
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
	cout << "Enter N: ";
	cin >> N;

	unsigned char* a = new unsigned char[size] {48, 48};
	unsigned char* b = new unsigned char[size] {48, 48};
	unsigned char* c = new unsigned char[size] {48, 48};
	unsigned char* d = new unsigned char[size] {48, 48};

	b[size - 1] = 49;

	int count = 0;
	bool flag = false;
	int remainder = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t t = 1; t < size; t++)
		{
			if (mode)
			{
				if (a[t] == '0' && flag == false)
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
			cout << a[t];
#endif // _DEBUG

			
			
		}
#if _DEBUG
		cout << " | ";
		for (size_t t = 1; t < size; t++)
		{
			cout << b[t];
		}

		cout << endl;
#endif // _DEBUG

		transfer(c, b, size);
		count = 0;
		for (size_t j = size; j > 0; j--)
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

		if (format(b[0]) > 0)
		{
			a = increase_size(a, size);
			b = increase_size(b, size);
			c = increase_size(c, size);
			d = increase_size(d, size);
			size += 1;
		}
		transfer(a, c, size);
	}

	if (mode)
	{
		cout << "\n";
		cout << "FLAG answer = ";

		for (size_t t = 1; t < size; t++)
		{
			cout << d[t];
	}

		cout << "\n";
		cout << "FLAG = " << flag << endl;
		cout << "N = " << breakpoint;
	}
	else
	{
		cout << endl;
		cout << "Answer = ";

		for (size_t t = 1; t < size; t++)
		{
			cout << a[t];
		}
	}

	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;
}