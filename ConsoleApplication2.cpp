#include <iostream>

using namespace std;

void transfer(unsigned int* buffer, unsigned int* array, size_t& size)
{
	for (int i = 0; i < size; i++)
	{
		buffer[i] = array[i];
	}
}

unsigned int* increase_size(unsigned int* array, size_t& size)
{
	unsigned int* buffer = new unsigned int[size + 1] {0};

	for (size_t i = size; i > 0; i--)
	{
		buffer[i] = array[i - 1];
	}
	
	return buffer;
}

int main()
{
	size_t size = 2;
	unsigned int N = 0;
	cout << "Enter N: ";
	cin >> N;

	unsigned int* num_1 = new unsigned int[size] {0};
	unsigned int* num_2 = new unsigned int[size] {0};
	unsigned int* buff = new unsigned int[size] {0};
	num_2[size - 1] = 1;

	int remainder = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t k = 1; k < size; k++)
		{
			cout << num_1[k];
		}
		cout << " ";
		for (size_t k = 1; k < size; k++)
		{
			cout << num_2[k];
		}
		cout << " | ";

		transfer(buff, num_2, size);

		for (size_t j = size; j > 0; j--)
		{
			if (num_1[j - 1] + num_2[j - 1] + remainder < 10)
			{
				num_2[j - 1] = num_1[j - 1] + num_2[j - 1] + remainder;
				remainder = 0;
			}
			else
			{
				num_2[j - 1] = (num_1[j - 1] + num_2[j - 1] + remainder) % 10;
				remainder = 1;
			}
		}
		if (num_2[0] > 0)
		{
			num_1 = increase_size(num_1, size);
			num_2 = increase_size(num_2, size);
			buff = increase_size(buff, size);
			size += 1;
		}
		transfer(num_1, buff, size);
	}
	cout << endl;
	cout << "Answer = ";

	for (size_t k = 1; k < size; k++)
	{
		cout << num_1[k];
	}

	cout << endl;
	cout << "runtime = " << clock() / 1000.0 << endl;

	delete[] num_1;
	delete[] num_2;
	delete[] buff;
}