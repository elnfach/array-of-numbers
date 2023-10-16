#ifndef HEADERS_INT_H
#define HEADERS_INT_H

class INT
{
public:
	INT();
	INT(INT* param);
	INT(const int param);

	~INT();

	void screen();
	void screen(const char* param);

	INT operator+(const INT& param);

	void operator=(const INT& param);
private:
	int m_size;
	int m_array_size = 1000000000;
	unsigned char* m_container;
};

#endif // !HEADERS_INT_H
