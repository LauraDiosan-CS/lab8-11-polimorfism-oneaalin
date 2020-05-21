#include "Medicament.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

Medicament::Medicament()
{
}

Medicament::Medicament(int id, string nume, bool reteta, int stoc, string producator)
{
	this->id = id;
	this->nume = nume;
	this->reteta = reteta;
	this->stoc = stoc;
	this->producator = producator;
}

Medicament::Medicament(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	id = stoi(tokens[0]);
	nume = tokens[1];
	reteta = stoi(tokens[2]);
	stoc = stoi(tokens[3]);
	producator = tokens[4];
}

Medicament::Medicament(const Medicament& m)
{
	id = m.id;
	nume = m.nume;
	reteta = m.reteta;
	stoc = m.stoc;
	producator = m.producator;
}

int Medicament::getID()
{
	return id;
}

string Medicament::getNume()
{
	return nume;
}

bool Medicament::getReteta()
{
	return reteta;
}

int Medicament::getStoc()
{
	return stoc;
}

string Medicament::getProducator()
{
	return producator;
}

void Medicament::setID(int n)
{
	id = n;
}

void Medicament::setNume(string s)
{
	nume = s;
}

void Medicament::setReteta(bool n)
{
	reteta = n;
}

void Medicament::setStoc(int n)
{
	stoc = n;
}

void Medicament::setProducator(string s)
{
	producator = s;
}

bool Medicament::operator==(const Medicament& m)
{
	return (id == m.id) and (nume == m.nume) and (reteta == m.reteta) and (stoc == m.stoc) and (producator == m.producator);
}

bool Medicament::operator!=(const Medicament& m)
{
	return (id != m.id) or (nume != m.nume) or (reteta != m.reteta) or (stoc != m.stoc) or (producator != m.producator);
}

string Medicament::toString()
{
	return to_string(id) + " " + nume + " " + to_string(reteta) + " " + to_string(stoc) + " " + producator;
}

string Medicament::toStringDelimiter(char delim)
{
	return to_string(id) + delim + nume + delim + to_string(reteta) + delim + to_string(stoc) + delim + producator;
}

Medicament::~Medicament()
{
}