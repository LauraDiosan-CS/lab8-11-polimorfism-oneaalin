#pragma once
#include "RepositoryFile.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "RepositoryInMemory.h"
#include "User.h"
#include "Medicament.h"
#include "Angajat.h"

class TestRepo
{
private:
	void runCSVTests();
	void runTXTTests();
	void runInMemoryTest();
public:
	TestRepo();
	void runTests();
	~TestRepo();
};