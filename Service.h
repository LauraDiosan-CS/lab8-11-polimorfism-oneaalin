#pragma once
#include "RepositoryFileCSV.h";
#include "RepositoryFileTXT.h";
#include "Angajat.h";
#include "Medicament.h";
#include "User.h";

class Service
{
private:
	IRepository<Medicament>* repoMedicamente;
	IRepository<Angajat>* repoAngajati;
	IRepository<User>* repoUseri;
public:
	Service();
	Service(IRepository<Medicament>* , IRepository<Angajat>* , IRepository<User>*);
	bool login(string, string);
	vector<Medicament> search(string);
	vector<User> getAllUsers();
	void add(Medicament);
	void remove(int);
	vector<Medicament> getAll();
	Medicament update(Medicament, Medicament);
	void addAngajat(Angajat);
	void delAngajat(int);
	vector<Angajat> getlAllAngajati();
	Angajat updateAngajat(Angajat, Angajat);
	void addUser(User);
	void modifyAccesUser(string ,int, int);
	~Service();
};

class ServiceException
{
private:
	string msg;
public:
	ServiceException(string s) :msg(s)
	{
	}
	string getMessage()
	{
		return msg;
	}
};

void testService();