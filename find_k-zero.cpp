#include <iostream>

using namespace std;

int main()
{
	time_t start, end;
	time(&start);

	int array_size = 10000000000;

	unsigned int breakpoint = 0;
	unsigned int k = 0;
	cout << "Enter K: ";
	cin >> k;
	cout << "[ ";

	unsigned char* a = new unsigned char[array_size]();
	unsigned char* b = new unsigned char[array_size]();
	unsigned int start_number = array_size - 1;
	b[array_size - 1] = 1;

	int count = 0;
	int count_buf = 0;
	int temp = 0;
	int remainder = 0;
	bool flag = false;
	for (int i = 0;; i++)
	{
		for (int j = array_size - 1; j >= start_number; j--)
		{
			temp = a[j];
			a[j] = b[j];

			if (temp + b[j] + remainder < 10)
			{
				b[j] = temp + b[j] + remainder;
				remainder = 0;
			}
			else
			{
				b[j] = (temp + b[j] + remainder) % 10;
				remainder = 1;
				if (start_number == j)
				{
					start_number = j - 1;
				}
			}

			// 
			// Система подсчета нулей
			// 
			// Если найдется требуемое число нулей, то
			// внешний цикл for остановит свою работу
			// 
			if (b[j] == 0)
			{
				count += 1;
				if (count > count_buf)
				{
					count_buf = count;
					cout << "[" << count_buf << " - " << i + 1 << "]";
				}
				if (count == k)
				{
					flag = true;
				}
			}
			else
			{
				count = 0;
			}
		}

		if (flag)
		{
			breakpoint = i + 1;
			break;
		}
	}
	cout << " ]" << endl;

	cout << endl;
	cout << "FLAG answer = ";

	for (int j = start_number; j < array_size; j++)
	{
		cout << (int)b[j];
	}

	cout << endl;
	cout << "FLAG = " << flag << endl;
	cout << "N = " << breakpoint << endl;

	delete[] a;
	delete[] b;

	time(&end);
	double seconds = difftime(end, start);

	cout << endl;
	cout << "runtime = " << seconds << endl;

	return 0;
}