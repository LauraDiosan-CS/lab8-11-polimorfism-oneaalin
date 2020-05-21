#pragma once
#include <string>
using namespace std;

class Medicament
{
private:
	int id;
	string nume;
	bool reteta;
	int stoc;
	string producator;
public:
	Medicament();
	Medicament(int, string, bool, int, string);
	Medicament(string, char);
	Medicament(const Medicament&);
	int getID();
	string getNume();
	bool getReteta();
	int getStoc();
	string getProducator();
	void setID(int);
	void setNume(string);
	void setReteta(bool);
	void setStoc(int);
	void setProducator(string);
	bool operator==(const Medicament&);
	bool operator!=(const Medicament&);
	string toString();
	string toStringDelimiter(char);
	~Medicament();
};