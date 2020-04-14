#pragma once
#include<iostream>
#include<string>
using namespace std;
class Tonomat
{
private:
	int bancnota;
	int moneda50;
	int moneda10;
public:
	Tonomat();
	Tonomat(int, int, int);
	Tonomat(const Tonomat &t);
	~Tonomat();
	Tonomat& operator=(const Tonomat &t);

	void setBancnota(int bancnota);
	void setMoneda50(int moneda50);
	void setMoneda10(int moneda10);

	int getBancnota();
	int getMoneda50();
	int getMoneda10();

	string toString();
	bool operator<(Tonomat &t);
	bool operator>(Tonomat &t);
	bool operator==(Tonomat &t);

	/*friend ostream& operator<<(ostream &os, Tonomat &t)
	{
		os << "pretul pordusului = " << t.moneda << endl;
		return os;
	}
	friend istream& operator>>(istream &is, Tonomat &t)
	{
		int bancnota, moneda;
		cout << "bancnota= ";
		is >> bancnota;
		t.setBancnota(bancnota);
		cout << "moneda= ";
		is >> moneda;
		t.setMoneda(moneda);
		return is;
	}*/

};



