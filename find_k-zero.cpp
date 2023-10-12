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
	unsigned char* ptr_border = &b[array_size - 2];
	b[array_size - 1] = 1;

	int count = 0;
	int count_buf = 0;
	int temp = 0;
	int remainder = 0;
	bool flag = false;
	for (int i = 0;; i++)
	{
		count = 0;
		for (int j = array_size; j > 0; j--)
		{
			temp = a[j - 1];
			a[j - 1] = b[j - 1];

			if (temp + (int)b[j - 1] + remainder < 10)
			{
				b[j - 1] = temp + (int)b[j - 1] + remainder;
				remainder = 0;
			}
			else
			{
				b[j - 1] = (temp + (int)b[j - 1] + remainder) % 10;
				remainder = 1;
			}

			//
			// Граница числа
			// 
			// Требуется для экономии время при расчете.
			// В случае отсутствия условия программа будет
			// складывать нули до нулевого индекса, что не допустимо
			//
			if (&b[j - 1] == ptr_border)
			{
				if ((int)b[j - 1] > 0)
				{
					ptr_border = &b[j - 2];
				}
				break;
			}

			// 
			// Система подсчета нулей
			// 
			// Если найдется требуемое число нулей, то
			// цикл for остановит свою работу
			// 
			if (b[j - 1] == 0)
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

	int start_point = 0;
	for (int j = array_size; j > 0; j--)
	{
		if (&b[j - 1] == ptr_border)
		{
			start_point = j;
			break;
		}
	}
	for (int j = start_point; j < array_size; j++)
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