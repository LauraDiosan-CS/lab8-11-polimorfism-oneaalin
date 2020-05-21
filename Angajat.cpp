#include "Angajat.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Angajat::Angajat()
{
}

Angajat::Angajat(int id, string nume, string email, int acces)
{
	this->id = id;
	this->nume = nume;
	this->email = email;
	this->acces = acces;
}

Angajat::Angajat(string linie, char delim)
{
	vector<string>tokens = splitLine(linie, delim);
	id = stoi(tokens[0]);
	nume = tokens[1];
	email = tokens[2];
	acces = stoi(tokens[3]);
}

Angajat::Angajat(const Angajat& a)
{
	id = a.id;
	nume = a.nume;
	email = a.email;
	acces = a.acces;
}

int Angajat::getID()
{
	return id;
}

string Angajat::getNume()
{
	return nume;
}

string Angajat::getEmail()
{
	return email;
}

int Angajat::getAcces()
{
	return acces;
}

void Angajat::setID(int n)
{
	id = n;
}

void Angajat::setNume(string s)
{
	nume = s;
}

void Angajat::setEmail(string s)
{
	email = s;
}

void Angajat::setAcces(int n)
{
	acces = n;
}

bool Angajat::operator==(const Angajat& a)
{
	return (id == a.id) and (nume == a.nume) and (email == a.email) and (acces == a.acces);
}

string Angajat::toString()
{
	return to_string(id) + " " + nume + " " + email + " " + to_string(acces);
}
string Angajat::toStringDelimiter(char delim)
{
	return to_string(id) + delim + nume + delim + email + delim + to_string(acces);
}

Angajat::~Angajat()
{
}