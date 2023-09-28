#include <iostream>
#include "headers/INT.h"
INT::INT()
{
	m_size = 2;
	m_container = new unsigned char[m_size] {48, 48};
}

//INT::INT(INT& param)
//{
//	m_size = param.m_size;
//	m_container = new unsigned char[m_size] {48};
//	for (size_t i = m_size; i > 0; i--)
//	{
//		m_container[i - 1] = param.m_container[i - 1];
//	}
//}

INT::INT(INT* param)
{
	m_size = param->m_size;
	m_container = new unsigned char[m_size] {48};
	for (size_t i = m_size; i > 0; i--)
	{
		m_container[i - 1] = param->m_container[i - 1];
	}
}

INT::INT(const int param)
{
	int _param = param;
	m_size = 2;
	m_container = new unsigned char[m_size] {48, 48};
	for (size_t i = m_size; i > 0; i--)
	{
		m_container[i - 1] = (_param % 10) + 48;
		_param /= 10;
		if ((int)m_container[0] - 48 > 0 || _param > 9)
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
}

INT::INT(const char param)
{
	m_size = 2;
	m_container = new unsigned char[m_size] {48, 48};

	try
	{
		for (size_t i = this->m_size; i > 0; i--)
		{
			this->m_container[i - 1] = param;
			if ((int)param - 48 > 9)
			{
				throw;
			}
		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

INT::INT(const char* param)
{
	const char* _param = param;
	int j = 2;
	m_size = 2;
	m_container = new unsigned char[m_size] {48, 48};
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
}

size_t INT::getSize()
{
	return m_size;
}

void INT::screen()
{
	for (size_t i = 1; i < m_size; i++)
	{
		std::cout << m_container[i];
	}
	std::cout << std::endl;
}

const INT& INT::operator+(const INT& param)
{
	INT _param = param;
	int size = 0;

	if (m_size > _param.m_size)
	{
		unsigned char* buffer = new unsigned char[_param.m_size + (m_size - _param.m_size)] {0};
		for (size_t i = _param.m_size; i > 0; i--)
		{
			buffer[i - 1] = '0';
			buffer[i] = _param.m_container[i - 1];
		}
		_param.m_size = m_size;
		size = m_size;
		_param.m_container = buffer;
	}
	if (_param.m_size > m_size)
	{
		unsigned char* buffer = new unsigned char[m_size + (_param.m_size - m_size)] {0};
		for (size_t i = m_size; i > 0; i--)
		{
			buffer[i - 1] = '0';
			buffer[i] = m_container[i - 1];
		}
		m_size = _param.m_size;
		size = _param.m_size;
		m_container = buffer;
	}
	int remainder = 0;

	for (size_t i = size; i > 0; i--)
	{
		if (m_container[i - 1] + param.m_container[i - 1]  + remainder - 96 < 10)
		{
			m_container[i - 1] = (m_container[i - 1] + param.m_container[i - 1] + remainder - 96) + 48;
			remainder = 0;
		}
		else
		{
			m_container[i - 1] = ((m_container[i - 1] + param.m_container[i - 1] + remainder - 96) % 10) + 48;
			remainder = 1;
		}
		if ((int)m_container[0] - 48 > 0 || i > 0)
		{
			unsigned char* buffer = new unsigned char[m_size + 1] {0};
			for (size_t i = m_size; i > 0; i--)
			{
				buffer[i] = m_container[i - 1];
			}
			m_size += 1;
			m_container = buffer;
		}
	}

	return *this;
}

INT& INT::operator=(const INT& param)
{
	INT _param = param;
	m_size = param.m_size;
	m_container = new unsigned char[m_size] {48};
	for (size_t i = m_size; i > 0; i--)
	{
		m_container[i - 1] = _param.m_container[i - 1];
	}
	return *this;
}

INT& INT::operator=(const int param)
{
	int _param = param;
	m_size = 2;
	m_container = new unsigned char[m_size] {48, 48};
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
	m_container = new unsigned char[m_size] {48, 48};

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
	m_container = new unsigned char[m_size] {48, 48};
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