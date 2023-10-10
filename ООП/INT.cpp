#include <iostream>
#include "headers/INT.h"

INT::INT()
{
	m_size = 2;
	m_container = new unsigned char[m_array_size] ();
	for (size_t i = 0; i < m_array_size; i++)
	{
		m_container[i] = '0';
	}
}

INT::INT(INT* param)
{
	m_size = param->m_size;
	unsigned char* buffer = new unsigned char[m_array_size] ();

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
	this->m_container = new unsigned char[m_array_size] ();

	m_size = size + 1;
	m_container = this->m_container;

	for (size_t i = m_array_size, l = 1; l < m_size; i--, l++)
	{
		this->m_container[i - 1] = (_param % 10) + 48;
		_param /= 10;
	}
}

INT::INT(const char param)
{
	char _param = param;
	m_size = 2;
	m_container = new unsigned char[m_size];

	for (size_t i = 0; i < m_size; i++)
	{
		m_container[i] = 48;
	}

	for (size_t i = m_size; i > 0; i--)
	{
		m_container[i - 1] = _param;
		if ((int)_param - 48 > 9)
		{
			throw;
		}
	}
}

INT::INT(const char* param)
{
	m_size = 2;
	m_container = new unsigned char[m_size];

	for (size_t i = 0; i < m_size; i++)
	{
		m_container[i] = 48;
	}
	size_t size = strlen(param);
	int j = size;
	const char* _param = param;
	unsigned char* buffer = new unsigned char[size + 1];

	for (size_t i = 0; i < j; i++)
	{
		buffer[i] = 48;
	}

	try
	{
		for (size_t i = size; i > 0; i--)
		{
			buffer[i] = _param[i - 1];
			if ((int)_param[i - 1] - 48 > 9)
			{
				throw;
			}
		}
		m_size = size + 1;
		m_container = buffer;
		delete[] buffer;
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

INT::~INT()
{
	delete[] m_container;
}

//size_t INT::getSize()
//{
//	return m_size;
//}

void INT::screen()
{
	for (size_t i = m_array_size - m_size, l = 1; l < m_size; i++, l++)
	{
		std::cout << m_container[i + 1];
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
		std::cout << m_container[i + 1];
	}
}

int INT::format(unsigned char& param)
{
	int _param = 0;
	_param = param;
	if (_param - 48 > -1 && _param - 48 < 10)
	{
		return _param - 48;
	}
	else {
		return 0;
	}
}

unsigned char INT::format(int param)
{
	if (param > 9)
	{
		return '0';
	}
	return param + 48;
}

INT INT::operator+(const INT& param)
{
	INT temp;
	size_t size = (param.m_size > m_size) ? param.m_size : m_size;
	temp.m_size = size;
	int remainder = 0;

	for (size_t i = m_array_size, l = 0; l < size; i--, l++)
	{
		if (format(m_container[i - 1]) + format(param.m_container[i - 1]) + remainder < 10)
		{
			temp.m_container[i - 1] = format(format(m_container[i - 1]) + format(param.m_container[i - 1]) + remainder);
			remainder = 0;
		}
		else
		{
			temp.m_container[i - 1] = format((format(m_container[i - 1]) + format(param.m_container[i - 1]) + remainder) % 10);
			remainder = 1;
		}
	}
	std::cout << "\n";
	if (format(temp.m_container[m_array_size - size]) > 0)
	{
		temp.m_size += 1;
	}
	return temp;
}

void INT::operator=(const INT& param)
{
	this->m_size = param.m_size;
	delete[] this->m_container;
	this->m_container = new unsigned char[m_array_size];
	memcpy(m_container, param.m_container, m_array_size);
}

INT& INT::operator=(const int param)
{
	int _param = param;
	m_size = 2;
	m_container = new unsigned char[m_size];

	for (size_t i = 0; i < m_size; i++)
	{
		m_container[i] = 48;
	}

	for (size_t i = m_size; i > 0; i--)
	{
		m_container[i - 1] = (_param % 10) + 48;
		_param /= 10;
		if ((int)m_container[0] - 48 > 0 || i > 0)
		{
			unsigned char* buffer = new unsigned char[m_size + 1] {0};
			for (size_t i = m_size; i > 0; i--)
			{
				buffer[i] = m_container[i - 1];
			}
			m_size += 1;
			i++;
			m_container = buffer;
		}
	}
	return *this;
}

INT& INT::operator=(const char param)
{
	char _param = param;
	m_size = 2;
	m_container = new unsigned char[m_size];

	for (size_t i = 0; i < m_size; i++)
	{
		m_container[i] = 48;
	}

	try
	{
		for (size_t i = this->m_size; i > 0; i--)
		{
			this->m_container[i - 1] = _param;
			if ((int)_param - 48 > 9)
			{
				throw;
			}
		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}

INT& INT::operator=(const char* param)
{
	const char* _param = param;
	int j = 2;
	m_size = 2;
	m_container = new unsigned char[m_size];

	for (size_t i = 0; i < m_size; i++)
	{
		m_container[i] = 48;
	}
	try
	{
		for (size_t i = strlen(param); i > 0; i--)
		{
			m_container[j - 1] = _param[i - 1];
			if ((int)_param[i - 1] - 48 > 9)
			{
				throw;
			}
			j--;
			if ((int)m_container[0] - 48 > 0 || i > 0)
			{
				unsigned char* buffer = new unsigned char[m_size + 1] {0};
				for (size_t i = m_size; i > 0; i--)
				{
					buffer[i] = m_container[i - 1];
				}
				m_size += 1;
				j++;
				m_container = buffer;
			}
		}
	}

	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return *this;
}