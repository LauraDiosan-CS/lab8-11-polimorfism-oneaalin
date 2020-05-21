#pragma once
#include "Medicament.h"
#include "Angajat.h"
#include "User.h"
#include <vector>
#include <string>
#include <assert.h>
#include <sstream>
class validator
{
public:
	void validateMed(Medicament);
	void validateAngajat(Angajat);
	void validateUser(User);
};

class ValidateException
{
private:
	vector<string> msgs;
public:
	ValidateException(const vector<string>& errors) :msgs(errors){}
	friend ostream& operator<<(ostream& out, const ValidateException& ex)
	{
		for (const auto& msg : ex.msgs)
			out << msg << " ";
		return out;
	}
};

void testValidator();
