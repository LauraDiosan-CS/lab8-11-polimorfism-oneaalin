#include "TestRepo.h"
#include <assert.h>
void TestRepo::runCSVTests()
{
	// Medicamente 
	RepositoryFile<Medicament>* repoMedicament = new RepositoryFileCSV<Medicament>("Medicamente.csv");
	((RepositoryFileCSV<Medicament>*)repoMedicament)->loadFromFile();
	assert(repoMedicament->size() == 1);

	Medicament m(1, "paracetamol", 0, 20, "ducfarm");
	repoMedicament->add(m);
	//((RepositoryFileCSV<Medicament>*)repoMedicament)->saveToFile();

	try
	{
		repoMedicament->add(m); assert(false);
	}
	catch (RepoException& ex) {
		assert(ex.getMessage() == "Entitatea exista deja in lista !\n");
	}

	assert(repoMedicament->find(m) == 1);

	Medicament m1(1, "paracetamol", 1, 25, "ducfarm");
	repoMedicament->update(m, m1);

	try
	{
		repoMedicament->update(m, m1); assert(false);
	}
	catch (RepoException& ex) {
		assert(ex.getMessage() == "Entitatea nu exista in lista!\n");
	}

	assert(repoMedicament->find(m1) == 1);
	assert(repoMedicament->find(m) == -1);
	assert(repoMedicament->size() == 2);

	// Angajati 
	const char* fileNameAngajati = "Angajati.csv";
	RepositoryFile<Angajat>* repoAngajat = new RepositoryFileCSV<Angajat>(fileNameAngajati);
	((RepositoryFile<Angajat>*)repoAngajat)->loadFromFile();
	assert(repoAngajat->size() == 0);

	Angajat  a(3, "Catalin", "catalin@yahoo.com", 3);
	repoAngajat->add(a);
	assert(repoAngajat->size() == 1);

	repoAngajat->remove(3);
	assert(repoAngajat->size() == 0);

	assert(repoAngajat->find(a) == -1);
}

void TestRepo::runTXTTests()
{
	// Medicamente 
	RepositoryFile<Medicament>* repoMedicament = new RepositoryFileCSV<Medicament>("Medicamente.txt");
	((RepositoryFileCSV<Medicament>*)repoMedicament)->loadFromFile();
	assert(repoMedicament->size() == 1);

	Medicament m(1, "paracetamol", 0, 20, "ducfarm");
	repoMedicament->add(m);
	//((RepositoryFileCSV<Medicament>*)repoMedicament)->saveToFile();
	
	assert(repoMedicament->find(m) == 1);

	Medicament m1(1, "paracetamol", 1, 25, "ducfarm");
	repoMedicament->update(m, m1);
	assert(repoMedicament->find(m1) == 1);
	assert(repoMedicament->find(m) == -1);
	assert(repoMedicament->size() == 2);

	// Angajati 
	const char* fileNameAngajati = "Angajati.txt";
	RepositoryFile<Angajat>* repoAngajat = new RepositoryFileCSV<Angajat>(fileNameAngajati);
	((RepositoryFile<Angajat>*)repoAngajat)->loadFromFile();
	assert(repoAngajat->size() == 0);

	Angajat  a(3, "Catalin", "catalin@yahoo.com", 3);
	repoAngajat->add(a);
	assert(repoAngajat->size() == 1);

	repoAngajat->remove(3);
	assert(repoAngajat->size() == 0);

	assert(repoAngajat->find(a) == -1);
}

void TestRepo::runInMemoryTest()
{
	IRepository<User>* repoUseri = new RepositoryInMemory<User>();
	User u("Alin", "1234");

	repoUseri->add(u);
	assert(repoUseri->size() == 1);

	assert(repoUseri->find(u) == 0);
}

TestRepo::TestRepo()
{
}

void TestRepo::runTests()
{
	runCSVTests();
	runTXTTests();
	runInMemoryTest();
}

TestRepo::~TestRepo()
{
}