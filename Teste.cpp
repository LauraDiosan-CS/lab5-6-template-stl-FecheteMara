#include"pch.h"
#include"assert.h"
#include"Repo.h"
#include"Produs.h"
#include "Teste.h"
#include"Tonomat.h"
#include"RepoFile.h"
#include"Controller.h"
#include <iostream>
using namespace std;
void teste_constructori_produs()
{
	//Arrange
	Produs c1 = Produs();
	Produs c2 = Produs();
	//Act
	c2.setCod(1);
	c2.setNume("cola");
	c2.setPret(4);
	//Assert
	assert(c1.getCod() == 0);
	assert(c1.getNume() == "");
	assert(c1.getPret() == 0);
	assert(c2.getCod() == 1);
	assert(c2.getNume() == "cola");
	assert(c2.getPret() == 4);
	cout << "ok-clasa produs" << endl;

}
void test_constructori_tonomat() {
	//Arrange
	Tonomat c1 = Tonomat();
	Tonomat c2 = Tonomat();
	//Act
	c2.setBancnota(1);
	c2.setMoneda50(4);
	c2.setMoneda10(4);
	//Assert
	assert(c1.getBancnota() == 0);
	assert(c1.getMoneda50() == 0);
	assert(c1.getMoneda10() == 0);
	assert(c2.getBancnota() == 1);
	assert(c2.getMoneda50() == 4);
	assert(c2.getMoneda10() == 4);
	cout << "ok-clasa tonomat constructori" << endl;
}
void test_operator_tonomat() {
	//Arrange
	Tonomat c1 = Tonomat();
	Tonomat c2 = Tonomat(1, 4, 4);
	//Act
	c1 = Tonomat(c2);
	//Assert
	assert(c1.getBancnota() == 1);
	assert(c1.getMoneda50() == 4);
	assert(c1.getMoneda10() == 4);
	cout << "ok-clasa tonomat operator=" << endl;
}
void test_repo_create() {
	Repo <Produs, 10> v;
	Produs p = Produs(1,"apa",5);
	v.setElemPos(0, p);
	assert(v.getElemPos(0) == p);
	cout << "ok-test repo create" << endl;
}
void test_repo_add() {
	Repo <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	assert(v.getSize() == 2);
	cout << "ok-test repo add" << endl;
}
void test_repo_delete()
{
	Repo <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.deleteElem(2);
	assert(v.getSize() == 1);
	cout << "ok-teste repo delete" << endl;

}
void test_repo_update()
{
	Repo <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.updateElem(p, p2);
	cout << "ok-teste repo update" << endl;

}
void test_repofile_create() {
	RepoFile <Produs, 10>v;
	Produs p = Produs();
	p.setCod(1);
	p.setNume("apa");
	p.setPret(5);
	v.setElemPos(1, p);
	assert(v.getElemPos(1) == p);
	cout << "ok-test repofile create" << endl;
}
void test_repofile_add() {
	RepoFile <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	assert(v.getSize() == 2);
	cout << "ok-test repofile add" << endl;
}
void test_repofile_delete()
{
	RepoFile <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.delete_element(2);
	assert(v.getSize() == 1);
	cout << "ok-teste repofile delete" << endl;

}
void test_repofile_update()
{
	RepoFile <Produs, 10>v;
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.updateElem(p, p2);
	cout << "ok-teste repofile update" << endl;

}
void test_controller_add() {
	RepoFile<Produs, 15> v;
	Controller<Produs, 15>c2(v);
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	assert(v.getSize() == 2);
	cout << "ok-test controller add" << endl;
}
void test_controller_delete()
{
	RepoFile<Produs, 15> v;
	Controller<Produs, 15>c2(v);
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.delete_element(2);
	assert(v.getSize() == 1);
	cout << "ok-teste controller delete" << endl;

}
void test_controller_update()
{
	RepoFile<Produs, 15> v;
	Controller<Produs, 15>c2(v);
	Produs p = Produs(1, "cola", 4);
	Produs p2 = Produs(1, "coa", 4);
	v.addElem(p);
	v.addElem(p2);
	v.updateElem(p, p2);
	cout << "ok-teste controller update" << endl;

}
void test_controller_operatie() {
	RepoFile<Produs, 15> v;
	Controller<Produs, 15>c2(v);
	Produs p = Produs(1, "cola", 4);
	Produs p1 = Produs(2, "apa", 5);
	Produs p2 = Produs(2, "mar", 3);
	assert(c2.rest(p, 10) == 12);
	assert(c2.rest(p1, 10) == 10);
	assert(c2.rest(p2, 3) == 0);
	cout << "ok-teste controller rest" << endl;

}