#include <iostream>
#include "headers/INT.h"

INT::INT()
{
	m_size = m_array_size - 1;
	m_container = new unsigned char[m_array_size]();
}

INT::INT(INT& param)
{
	m_size = param.m_size;

	delete[] m_container;
	m_container = new unsigned char[m_array_size]();

	memcpy(m_container, param.m_container, m_array_size);
}

INT::INT(const int param)
{
	int _param = param;

	if(_param > 9)
		throw ()

	delete[m_array_size] this->m_container;
	m_container = new unsigned char[m_array_size]();

	m_size = m_array_size - size;
	m_container = this->m_container;
}

INT::~INT()
{
	delete[m_array_size] m_container;
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
	return temp;
}

void INT::operator=(const INT& param)
{
	m_size = param.m_size;
	delete[m_array_size] m_container;
	m_container = new unsigned char[m_array_size];
	memcpy(m_container, param.m_container, m_array_size);
}