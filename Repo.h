#ifndef REPO_H
#define REPO_H

#include <iostream>
using namespace std;

template <class T, int CAP = 10> class Repo
{
private:
	T elem[CAP];
	int size;
public:
	Repo();
	Repo(const Repo<T, CAP>&);
	~Repo();
	T getElemPos(int);
	void setElemPos(int, T);
	int getSize();
	void addElem(T);
	void deleteElem(int);
	void updateElem(T& oldp, T& newp);
	T* getAll();

};

//constr fara parametrii
template <class T, int CAP> Repo<T, CAP>::Repo()
{
	this->size = 0;
}
//constr de copiere
template <class T, int CAP> Repo<T, CAP>::Repo(const Repo<T, CAP>& r)
{
	this->size = r.size;
}
//descructor
template <class T, int CAP> Repo<T, CAP>::~Repo()
{

}
//adauga un element intr o lista repo
template <class T, int CAP> void Repo<T, CAP>::addElem(T e) {
	if (this->size < CAP)
		this->elem[this->size++] = e;
	else
		cout << "not enogh space..." << endl;
}
//acceseaza un elem dintr o lista repo
template <class T, int CAP> T Repo<T, CAP>::getElemPos(int pos) {
	return this->elem[pos];
	
}
//schimba un elem dintr o lista repo
template <class T, int CAP> void Repo<T, CAP>::setElemPos(int pos, T e) {
	this->elem[pos] = e;
}
//acceseaza lungimea listei repo
template <class T, int CAP> int Repo<T, CAP>::getSize() {
	return this->size;
}
//elimina un element din lista
template <class T, int CAP> void Repo<T, CAP>::deleteElem(int pos) {
	this->elem[pos] = this->elem[--size];
}
//update elem
template <class T, int CAP> void Repo <T, CAP>::updateElem(T& oldp, T& newp) {
	for (int i = 0; i < this->getSize(); i++)
	{
		if (this->elem[i] == oldp)
		{
			this->elem[i] = newp;
		}
	}
}
template <class T,int CAP> T* Repo<T,CAP>::getAll()
{
	return this->elem;
}
#endif