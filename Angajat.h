#pragma once

#include <string>
using namespace std;

class Angajat
{
private:
	int id;
	string nume;
	string email;
	int acces;
public:
	Angajat();
	Angajat(int, string, string, int);
	Angajat(string, char);
	Angajat(const Angajat&);
	int getID();
	string getNume();
	string getEmail();
	int getAcces();
	void setID(int);
	void setNume(string);
	void setEmail(string);
	void setAcces(int);
	bool operator==(const Angajat&);
	string toString();
	string toStringDelimiter(char);
	~Angajat();
};