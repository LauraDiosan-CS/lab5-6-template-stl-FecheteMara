#ifndef REPOFILE_H
#define REPOFILE_H
#include "Repo.h"
#include"Produs.h"
#include <fstream>
#include <iostream>
using namespace std;

template <class T, int CAP > class RepoFile : public Repo <T, CAP> {
public:
	RepoFile();
	RepoFile(Repo<T, CAP>&v);
	RepoFile(RepoFile<T, CAP>const &v);
	~RepoFile();
	T getElemPos(int);
	void setElemPos(int, T);
	int get_size()const;
	void setSize(int s);

	void addElem(T);
	void delete_element(int);
	void updateElem(T& oldp, T& newp);
	T* getAll();
	void writeToFile(string filename);
	void readFromFile(string fileName);
	Produs splitLinieToProdus(string linie);

};

//constructor fara paramentrii
template <class T, int CAP> RepoFile<T, CAP>::RepoFile() {
	Repo<T, CAP>::Repo();
}

//constructor cu param
template <class T, int CAP> RepoFile<T, CAP>::RepoFile(Repo<T, CAP>& v)
{
	this->size = v.getSize();
	this->elem = v.elem;
}

//constructor de copiere
template <class T, int CAP>
RepoFile<T, CAP>::RepoFile(const RepoFile<T, CAP> &v)
{
	//setSize(v.getSize());
}
//destructor
template <class T, int CAP> RepoFile<T, CAP>::~RepoFile()
{
	Repo<T, CAP>::~Repo();
}

template <class T, int CAP> void RepoFile<T, CAP>::addElem(T e)
{
	Repo<T, CAP>::addElem(e);

	//adaugare in fisier
}

//stergere de element
template <class T, int CAP> void RepoFile<T, CAP>::delete_element(int pos)
{
	Repo<T, CAP>::deleteElem(pos);
}
//update elem
template <class T, int CAP> void RepoFile <T, CAP>::updateElem(T& oldp, T& newp) {
	Repo<T, CAP>::updateElem(oldp, newp);
}
//returneaza un element
template <class T, int CAP> T RepoFile<T, CAP>::getElemPos(int pos)
{
	return Repo<T, CAP>::getElemPos(pos);
}

//seteaza un element
template <class T, int CAP> void RepoFile<T, CAP>::setElemPos(int pos, T e)
{
	Repo<T, CAP>::setElemPos(pos, e);
}
//seteaza lungimea
template <class T, int CAP> void RepoFile<T, CAP>::setSize(int s)
{
	Repo<T, CAP>::setSize(s);
}
//returneaza lungimea

template <class T, int CAP> int RepoFile<T, CAP>::get_size()const
{
	return Repo<T, CAP>::getSize();
}
//returneaza lista
template <class T, int CAP> T* RepoFile<T, CAP>::getAll()
{
	return Repo<T, CAP>::getAll();
}

template <class T, int CAP> void RepoFile<T, CAP>::writeToFile(string filename) {
	ofstream fout(filename);
	T* allElems = this->getAll();
	for (int i = 0; i < this->getSize(); i++) {
		fout << allElems[i].toString() << endl;
	}
	fout.close();
}

template <class T, int CAP> void RepoFile<T, CAP>::readFromFile(string fileName) {
	ifstream myReadFile;
	myReadFile.open(fileName);
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {

			string linie = "";
			myReadFile >> linie;

			if (linie != "") {
				Produs p = this->splitLinieToProdus(linie);
				this->addElem(p);
			}
		}
	}
	myReadFile.close();
}

template <class T, int CAP> Produs RepoFile<T, CAP>::splitLinieToProdus(string linie) {
	string delimitator = "//";

	size_t pos = 0;
	string campuriLinie[3];
	Produs p;
	int i = 0;
	while ((pos = linie.find(delimitator)) != std::string::npos) {
		campuriLinie[i] = linie.substr(0, pos);
		linie.erase(0, pos + delimitator.length());
		i++;
	}
	campuriLinie[2] = linie;

	if ((campuriLinie[0] != "") && (campuriLinie[1] != "") && (campuriLinie[2] != "")) {
		p = Produs(std::stoi(campuriLinie[0]), campuriLinie[1], std::stoi(campuriLinie[2]));
	}

	return p;

}
#endif



