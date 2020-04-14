#include "pch.h"
#include "Produs.h"
Produs::Produs()
{
	this->cod = 0;
	this->nume = "";
	this->pret = 0;
}
Produs::Produs(int cod, string nume, int pret)
{
	this->cod = cod;
	this->nume = nume;
	this->pret = pret;
}
Produs::Produs(const Produs &p)
{
	this->cod = p.cod;
	this->nume = p.nume;
	this->pret = p.pret;
}
Produs::~Produs()
{

}
Produs& Produs ::  operator =(const Produs &p)
{

	if (this != &p)
	{
		this->setCod(p.cod);
		this->setNume(p.nume);
		this->setPret(p.pret);


	}
	else
		cout << "self assignment ... " << endl;
	return *this;
}
void Produs::setCod(int cod)
{
	this->cod = cod;
}
void Produs::setNume(string nume)
{
	this->nume = nume;
}
void Produs::setPret(int  pret)
{
	this->pret = pret;
}
int Produs::getPret()
{
	return this->pret;
}
string Produs::getNume()
{
	return this->nume;
}
int Produs::getCod()
{
	return this->cod;
}
string Produs::toString()
{
	string result = "";
	result += std::to_string(this->getCod());
	result += "//";
	result += this->getNume();
	result += "//";
	result += std::to_string(this->getPret());
	return result;
}
bool Produs::operator==(const Produs& p)
{
	return (this->cod == p.cod &&this->nume==p.nume && this->pret == p.pret);
}