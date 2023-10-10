#include <iostream>

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

void transfer(unsigned char* buffer, unsigned char* array, int& size)
{
	memcpy(buffer, array, size);
}

int main()
{
	setlocale(0, "");
	time_t start, end;
	time(&start);

	int progress = 100;
	int size = 2;
	int array_size = 1000000;

	unsigned int N = 2;
	unsigned int breakpoint = 0;
	unsigned int k = 0;
	bool mode = false;
	cout << "Enter K: ";
	cin >> k;
	cout << "[ ";

	unsigned char* a = new unsigned char[array_size] ();
	unsigned char* b = new unsigned char[array_size] ();
	unsigned char* c = new unsigned char[array_size] ();
	unsigned char* d = new unsigned char[array_size] ();

	for (int i = 0; i < array_size; i++)
	{
		a[i] = '0';
		b[i] = '0';
		c[i] = '0';
		d[i] = '0';
	}
	b[array_size - 1] = 49;

	int count = 0;
	int count_buf = 0;
	bool flag = false;
	int remainder = 0;
	for (int i = 0; i < N; i++)
	{
		transfer(c, b, array_size);
		count = 0;
		for (int j = array_size, l = 0; l < size; j--, l++)
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
			breakpoint = i + 1;
			break;
		}

		if (format(b[array_size - size]) > 0)
		{
			size += 1;
		}
		transfer(a, c, array_size);

		for (int t = array_size - size, l = 1; l < size; t++, l++)
		{
			if (b[t + 1] == '0' && flag == false)
			{
				count += 1;
				if (count > count_buf)
				{
					count_buf = count;
					cout << "[" << count_buf << "]";
				}
				if (count == k)
				{
					transfer(d, b, array_size);
					flag = true;
				}
			}
			else
			{
				count = 0;
			}
		}

		N++;
	}
	cout << " ]" << endl;

	cout << "\n";
	cout << "FLAG answer = ";

	for (int t = array_size - size, l = 1; l < size; t++, l++)
	{
		cout << d[t + 1];
	}

	cout << "\n";
	cout << "FLAG = " << flag << endl;
	cout << "N = " << breakpoint;

	delete[] a;
	delete[] b;
	delete[] c;
	delete[] d;

	time(&end);
	double seconds = difftime(end, start);

	cout << endl;
	cout << "runtime = " << seconds << endl;

	return 0;
}