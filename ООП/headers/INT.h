#ifndef HEADERS_INT_H

class INT
{
public:
	INT();
	INT(INT* param);
	INT(const int param);
	INT(const char param);
	INT(const char* param);

	~INT();

	//size_t getSize();
	void screen();
	void screen(const char* param);

	int format(unsigned char& param);
	unsigned char format(int param);

	INT operator+(const INT& param);

	void operator=(const INT& param);
	void operator=(const int param);
	void operator=(const char param);
	void operator=(const char* param);
private:
	size_t m_size;
	size_t m_array_size = 1000000;
	unsigned char* m_container;
};

#endif // !HEADERS_INT_H
