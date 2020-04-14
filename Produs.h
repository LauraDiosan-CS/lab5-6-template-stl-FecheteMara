#pragma once
#ifndef PRODUS_H
#define PRODUS_H
#include<string>
#include<iostream>
using namespace std;
class Produs
{
private:
	int cod;
	string nume;
	int pret;
public:
	Produs();
	Produs(int, string, int);
	Produs(const Produs &p);
	~Produs();
	Produs& operator=(const Produs &p);
	void setCod(int cod);
	void setNume(string nume);
	void setPret(int  pret);
	int getPret();
	int getCod();
	string getNume();
	string toString();
	bool operator==(const Produs& p);
	friend ostream& operator<<(ostream &os, Produs &s)
	{
		os << "cod=  " << s.cod << "nume= " << s.nume << "pret= " << s.pret << endl;
		return os;
	}
	friend istream& operator>>(istream &is, Produs &f) {
		int cod;
		int pret;
		string nume;
		cout << "cod= ";
		is >> cod;
		f.setCod(cod);
		cout << "nume= ";
		is >> nume;
		f.setNume(nume);
		cout << "pret= ";
		is >> pret;
		f.setPret(pret);
		return is;
	}

};

#endif