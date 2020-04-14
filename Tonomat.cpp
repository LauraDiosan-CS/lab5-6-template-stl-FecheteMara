#include "pch.h"
#include "Tonomat.h"
#include <iostream>
#include<string>
using namespace std;
//constructor fara parametrii
Tonomat::Tonomat()
{
	this->bancnota = 0;
	this->moneda50 = 0;
	this->moneda10 = 0;


}
//constructor cu parametrii
Tonomat::Tonomat(int bancnota, int moneda50, int moneda10)
{
	this->bancnota = bancnota;
	this->moneda50 = moneda50;
	this->moneda10 = moneda10;


}

Tonomat::Tonomat(const Tonomat &t)
{
	this->bancnota = t.bancnota;
	this->moneda50 = t.moneda50;
	this->moneda10 = t.moneda10;



}
//desctructor
Tonomat::~Tonomat()
{

}
//constructor de copiere
Tonomat& Tonomat ::  operator =(const Tonomat &t)
{

	if (this != &t)
	{
		this->setBancnota(t.bancnota);
		this->setMoneda50(t.moneda50);
		this->setMoneda10(t.moneda10);



	}
	else
		cout << "self assignment ... " << endl;
	return *this;
}
void Tonomat::setBancnota(int bancnota)
{
	this->bancnota = bancnota;
}
void Tonomat::setMoneda50(int moneda50)
{
	this->moneda50 = moneda50;
}
void Tonomat::setMoneda10(int moneda10)
{
	this->moneda10 = moneda10;
}

int Tonomat::getBancnota()
{
	return this->bancnota;
}
int Tonomat::getMoneda50()
{
	return this->moneda50;
}
int Tonomat::getMoneda10()
{
	return this->moneda10;
}

string Tonomat::toString()
{
	string result = "";
	result += std::to_string(this->getBancnota());
	result += "//";
	result += std::to_string(this->getMoneda50());
	result += "//";
	result += std::to_string(this->getMoneda10());
	return result;
}

bool Tonomat::operator<(Tonomat &t) {
	if ((moneda50 < t.moneda50) && (moneda10 < t.moneda10))
		return true;
	return false;
}
bool Tonomat::operator>(Tonomat &t) {
	if ((moneda50 > t.moneda50) && (moneda10 > t.moneda10))
		return true;
	return false;
}
bool Tonomat::operator==(Tonomat &t) {
	return  ((this->moneda50 == t.moneda50) && (this->moneda10 = t.moneda10));
}