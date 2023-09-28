#ifndef HEADERS_INT_H

class INT
{
public:
	INT();
	INT(INT* param);
	INT(const int param);
	INT(const char param);
	INT(const char* param);

	size_t getSize();
	void screen();

	const INT& operator+(const INT& param);

	INT& operator=(const INT& param);
	INT& operator=(const int param);
	INT& operator=(const char param);
	INT& operator=(const char* param);
private:
	size_t m_size;
	unsigned char* m_container;
};

#endif // !HEADERS_INT_H
