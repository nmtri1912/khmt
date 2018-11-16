#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;
string DecToBin(int n);

class QInt
{
	int data[4];
public:

	//a là chuổi số hệ 10, 2, 16
	//3 phương thức này dùng để chuyển chuổi a thành số QInt
	QInt()
	{
		for (int i = 0; i < 4; i++)
		{
			this->data[i] = 0;
		}
	}

	void SetBit(int vitri);
	void NhapTuHe10(string a);
	void NhapTuHe2(string a);
	void NhapTuHe16(string a);

	//3 phương thức này lấy ra chuổi hệ 2,10,16 của số Qint
	string LayHe2();
	string LayHe10();
	string LayHe16();

	//toán tử
	QInt operator +(QInt b);
	QInt operator -(QInt b);
	QInt operator *(QInt b);
	QInt operator /(QInt b);

	QInt operator&(QInt b);
	QInt operator|(QInt b);
	QInt operator^(QInt b);
	QInt operator~();
	QInt operator<<(int k);
	QInt operator>>(int k);
	QInt ror(int k);
	QInt rol(int k);
	~QInt()
	{
		for (int i = 0; i < 4; i++)
		{
			this->data[i] = 0;
		}
	}

};


