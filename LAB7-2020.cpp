#include "pch.h"
#include"Produs.h"
#include"Tonomat.h"
#include"Repo.h"
#include"Teste.h"
#include"RepoFile.h"
#include"Controller.h"
#include <iostream>

void indicatii_meniu()
{
	cout << "Laboratorul 7" << endl;
	cout << "1.Testare" << endl;
	cout << "2.Citire lista de produse" << endl;
	cout << "3.Proprietatea ceruta in cerinta" << endl;
	cout << "4.Afisare lista produse" << endl;
	cout << "5.Actualizare fisier" << endl;
	cout << "6.Iesire meniu" << endl;

}
int main()
{
	int val = 0;
	bool ok = true;
	RepoFile<Produs, 15> v2;
	Controller<Produs, 15>c2(v2);
	indicatii_meniu();
	v2.readFromFile("t_repo_file.txt");
	while (ok == true)
	{
		cout << "Dati operatia: ";
		cin >> val;
		if (val == 1)
		{
			teste_constructori_produs();
			test_constructori_tonomat();
			test_operator_tonomat();
			test_repo_create();
			test_repo_add();
			test_repo_delete();
			test_repo_update();
			test_repofile_create();
			test_repofile_add();
			test_repofile_delete();
			test_repofile_update();
			test_controller_add();
			test_controller_delete();
			test_controller_update();
			test_controller_operatie();
		}
		if (val == 2)
		{
			c2.readVector(v2);
		}
		if (val == 3)
		{  
			Tonomat t=Tonomat(100,100,100);
			int nr_elem = 0,cod;

			nr_elem = v2.getSize();
			for (int i = 0; i < nr_elem; i++)
			{
				cout << "Dati codul produsului pe care vreti sa il cumparat:  ";
				cin >> cod;
				for (int j = 0; j < nr_elem; j++) {
					if (cod == v2.getElemPos(j).getCod())
					{
						c2.operatie(v2.getElemPos(j), t);
					}
				}
				
			}
		}
		if (val == 4)
		{
			c2.printVector(v2);
		}
		if (val == 5)
		{
			v2.writeToFile("t_repo_file.txt");
		}
		if (val == 6)
		{
			ok = false;
		}
	}

	return 0;
}
