#include <iostream>
#include "headers/INT.h"

INT::INT()
{
	m_size = 2;
	m_container = new unsigned char[m_array_size]();
}

INT::INT(INT* param)
{
	m_size = param->m_size;
	unsigned char* buffer = new unsigned char[m_array_size]();

	memcpy(buffer, param->m_container, m_array_size);
	delete[] m_container;
	m_container = buffer;
}

INT::INT(const int param)
{
	int _param = param;
	int buff = _param;
	int j = 0;
	size_t size = 1;

	m_size = 2;

	while (buff > 9)
	{
		size += 1;
		buff /= 10;
	}

	delete[] this->m_container;
	this->m_container = new unsigned char[m_array_size]();

	m_size = size + 1;
	m_container = this->m_container;

	for (size_t i = m_array_size, l = 1; l < m_size; i--, l++)
	{
		this->m_container[i - 1] = _param % 10;
		_param /= 10;
	}
}

INT::~INT()
{
	delete[] m_container;
}

void INT::screen()
{
	for (size_t i = m_array_size - m_size, l = 1; l < m_size; i++, l++)
	{
		std::cout << (int)m_container[i + 1];
	}
}

void INT::screen(const char* param)
{
	for (size_t i = 0; i < strlen(param); i++)
	{
		std::cout << param[i];
	}
	for (size_t i = m_array_size - m_size, l = 1; l < m_size; i++, l++)
	{
		std::cout << (int)m_container[i + 1];
	}
}

INT INT::operator+(const INT& param)
{
	INT temp;
	temp.m_size = (param.m_size > m_size) ? param.m_size : m_size;
	int remainder = 0;
	int padding;
	for (size_t i = m_array_size - 1, l = 0; l < temp.m_size; i--, l++)
	{
		padding = m_container[i] + param.m_container[i] + remainder;
		if (padding < 10)
		{
			temp.m_container[i] = padding;
			remainder = 0;
		}
		else
		{
			temp.m_container[i] = (padding) % 10;
			remainder = 1;
		}
	}
	if (temp.m_container[m_array_size - temp.m_size] > 0)
	{
		temp.m_size += 1;
	}
	return temp;
}

void INT::operator=(const INT& param)
{
m_size = param.m_size;
	delete[]m_container;
	m_container = new unsigned char[m_array_size];
	memcpy(m_container, param.m_container, m_array_size);
}