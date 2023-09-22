#include <iostream>

using namespace std;

void transfer(unsigned int* buffer, unsigned int* array, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		buffer[i] = array[i];
	}
}

int main()
{
	size_t size = 0;
	unsigned int N = 0;
	cout << "Enter size: ";
	cin >> size;
	cout << "Enter N: ";
	cin >> N;
	
	unsigned int* num_1 = new unsigned int[size] {0};
	unsigned int* num_2 = new unsigned int[size] {0};
	unsigned int* buff = new unsigned int[size] {0};
	num_2[size - 1] = 1;
	

	int remainder = 0;
	for (int i = 0; i < N; i++)
	{

		transfer(buff, num_2, size);
		
		for (int k = 0; k < size; k++)
		{
			cout << num_1[k];
		}
		cout << " ";
		for (int k = 0; k < size; k++)
		{
			cout << num_2[k];
		}
		cout << " | ";
		
		for (int j = size - 1; j >= 0; j--)
		{
			if (num_1[j] + num_2[j] + remainder < 10)
			{
				num_2[j] = num_1[j] + num_2[j] + remainder;
				remainder = 0;
			}
			else
			{
				num_2[j] = (num_1[j] + num_2[j] + remainder) % 10;
				remainder = 1;
			}
		}
		transfer(num_1, buff, size);
	}
	cout << endl;
	for (int k = 0; k < size; k++)
	{
		cout << num_1[k];
	}
	delete[] num_1;
	delete[] num_2;
	delete[] buff;
}