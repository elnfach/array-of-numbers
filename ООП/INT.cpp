#include <iostream>
#include "headers/INT.h"

INT::INT()
{
	counter = 0;
	count = 0;
	count_buf = 0;
	m_size = m_array_size - 1;
	m_container = new unsigned char[m_array_size]();
}

INT::INT(INT* param)
{
	counter = 0;
	count = 0;
	count_buf = 0;
	m_size = param->m_size;

	delete[] m_container;
	m_container = new unsigned char[m_array_size]();

	memcpy(m_container, param->m_container, m_array_size);
}

INT::INT(const int param)
{
	counter = 0;
	count = 0;
	count_buf = 0;
	int _param = param;
	int buff = _param;
	int size = 1;

	m_size = 2;

	while (buff > 9)
	{
		size += 1;
		buff /= 10;
	}

	delete[] this->m_container;
	m_container = new unsigned char[m_array_size]();

	m_size = m_array_size - size;
	m_container = this->m_container;

	for (int i = m_array_size - 1; i >= m_size; i--)
	{
		m_container[i] = _param % 10;
		_param /= 10;
	}
}

INT::~INT()
{
	delete[] m_container;
}

void INT::screen()
{
	for (int i = m_size; i < m_array_size; i++)
	{
		std::cout << (int)m_container[i];
	}
}

void INT::screen(const char* param)
{
	for (int i = 0; i < strlen(param); i++)
	{
		std::cout << param[i];
	}
	for (int i = m_size; i < m_array_size; i++)
	{
		std::cout << (int)m_container[i];
	}
	std::cout << std::endl;
}

INT INT::operator+(const INT& param)
{
	INT temp;
	temp.m_size = (param.m_size > m_size) ? m_size : param.m_size;
	int remainder = 0;
	int padding;
	for (int i = m_array_size - 1; i >= temp.m_size; i--)
	{
		padding = m_container[i] + param.m_container[i] + remainder;
		if (padding < 10)
		{
			temp.m_container[i] = padding;
			remainder = 0;
		}
		else
		{
			temp.m_container[i] = padding % 10;
			remainder = 1;
			if (temp.m_size == i)
			{
				temp.m_size = i - 1;
			}
		}
	}
	counter += 1;
	return temp;
}

bool INT::operator[](const int param)
{
	for (int i = m_array_size - 1; i >= m_size; i--)
	{
		if (m_container[i] == 0)
		{
			count += 1;
			if (count > count_buf)
			{
				count_buf = count;
				std::cout << "[" << count_buf << " - " << counter << "]";
			}
			if (count == param)
			{
				return true;
			}
		}
		else
		{
			count = 0;
		}
	}
	return false;
}

void INT::operator=(const INT& param)
{
	m_size = param.m_size;
	delete[]m_container;
	m_container = new unsigned char[m_array_size];
	memcpy(m_container, param.m_container, m_array_size);
}