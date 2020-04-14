#pragma once
#include"RepoFile.h"
#include"Tonomat.h"
#include"Produs.h"
template <class T, int CAP = 10> class Controller
{
private:
	RepoFile<T, CAP> r;
public:
	Controller();
	Controller(RepoFile <T, CAP>r);
	Controller(const Controller &rf);

	void addElem(T);
	void delete_element(int);
	void updateElem(T& oldp, T& newp);
	T* getAll();
	int rest(Produs p, int suma);
	void operatie(Produs p, Tonomat t);
	void vectorProcess();
	void readVector(RepoFile < T, CAP>&v);
	void printVector(RepoFile < T, CAP>&v);
	~Controller();
};

//constructor fara paramentrii
template <class T, int CAP> Controller<T, CAP>::Controller() {
	RepoFile<T, CAP>::RepoFile();
}
//constructor cu paramentrii
template <class T, int CAP> Controller<T, CAP>::Controller(RepoFile<T, CAP>r)
{
	this->r = RepoFile<T, CAP>(r);
}
//constructor de copiere
template <class T, int CAP> Controller<T, CAP>::Controller(const Controller<T, CAP>& rf)
{
	this->size = rf.size;
}

//destructor
template <class T, int CAP> Controller<T, CAP>::~Controller()
{
	this->r.~RepoFile();
}

template<class T, int CAP> void Controller<T, CAP>::vectorProcess()
{
	Repo <T, CAP> v;
	int n;
	cout << "Numarul de produse pe care vreti sa le adaugati: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int el;
		cin >> el;
		v.addElem(el);
	}
	for (int i = 0; i < v.getSize(); i++)
		cout << v.getElemPos(i) << " ";
	cout << endl;
}
template <class T, int CAP> void Controller <T, CAP>::readVector(RepoFile<T, CAP> &v) {
	int n;
	cout << "Numarul de produse pe care vreti sa le adaugati:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << " Produs " << i + 1 << ": ";
		cout << endl;
		T el;
		cin >> el;
		v.addElem(el);
	}
}

template <class T, int CAP> void Controller<T, CAP>::printVector(RepoFile<T, CAP> &v) {
	for (int i = 0; i < v.getSize(); i++)
	{
		cout << v.getElemPos(i).toString() << " ";
		cout << endl;
	}
}

template <class T, int CAP> void Controller<T, CAP>::addElem(T e)
{
	RepoFile<T, CAP>::addElem(e);

	//adaugare in fisier
}

//stergere de element
template <class T, int CAP> void Controller<T, CAP>::delete_element(int pos)
{
	RepoFile<T, CAP>::deleteElem(pos);
}
//update elem
template <class T, int CAP> void Controller <T, CAP>::updateElem(T& oldp, T& newp) {
	RepoFile<T, CAP>::updateElem(oldp, newp);
}
template <class T, int CAP> T* Controller<T, CAP>::getAll()
{
	return RepoFile<T, CAP>::getAll();
}
template<class T, int CAP>int Controller<T, CAP>::rest(Produs p, int suma) {
	int rest = 0, pret = 0,  r = 0;
	pret = p.getPret();
	r = suma - pret;
	rest = r * 2;
	return rest;
}

template<class T, int CAP>void Controller<T, CAP>::operatie(Produs p, Tonomat t)
{
	int restt = 0, pret = 0, cod = 0, r = 0, m = 0, suma = 0;
	m = t.getMoneda50();
	pret = p.getPret();
	cout << "Dati suma de bani pentru produsul ales: ";
	cin >> suma;

	//r = suma - pret;
	//rest = r * 2;
	restt = rest(p, suma);

	if (suma == pret)
	{
		restt = 0;
		cout << "Nu aveti rest." << endl;
	}

	if (suma < pret)
	{
		cout << "Ati dat bani insuficienti!!" << endl;
	}

	if (suma > pret)
	{
		
		if (restt <= m)
		{
			cout<<"Rest: "<< restt << " monede de 50 de bani" << endl;
			m = m - restt;
			t.setMoneda50(m);
		}
		else
		{
			if (restt > m)
			{
				cout << "Tonomatul nu mai are bani, mai cumparati ceva!";
			}
		}

	}



}


