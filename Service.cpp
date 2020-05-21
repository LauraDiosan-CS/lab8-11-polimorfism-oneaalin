#include "Service.h"
#include "assert.h"

Service::Service()
{
}

Service::Service(IRepository<Medicament>* repoMedicamente ,IRepository<Angajat>* repoAngajati, IRepository<User>* repoUseri)
{
	this->repoMedicamente = repoMedicamente;
	this->repoAngajati = repoAngajati;
	this->repoUseri = repoUseri;
}

bool Service::login(string u, string p)
{
	User user(u, p);
	return repoUseri->find(user) != -1;
}

vector<Medicament> Service::search(string medName)
{
	vector<Medicament> allMeds = repoMedicamente->getAll();
	vector<Medicament> foundMeds;
	for (Medicament med : allMeds)
		if (med.getNume().find(medName) != string::npos)
			foundMeds.push_back(med);
	return foundMeds;
}

vector<User> Service::getAllUsers()
{
	return repoUseri->getAll();
}

void Service::add(Medicament m)
{
	repoMedicamente->add(m);
}

void Service::remove(int id)
{
	repoMedicamente->remove(id);
}

vector<Medicament> Service::getAll()
{
	return repoMedicamente->getAll();
}

Medicament Service::update(Medicament m1, Medicament m2)
{
	repoMedicamente->update(m1, m2);
	return m1;
}

void Service::addAngajat(Angajat a)
{
	repoAngajati->add(a);
}

void Service::delAngajat(int id)
{
	repoAngajati->remove(id);
}

vector<Angajat> Service::getlAllAngajati()
{
	return repoAngajati->getAll();
}

Angajat Service::updateAngajat(Angajat a1, Angajat a2)
{
	repoAngajati->update(a1, a2);
	return a1;
}

void Service::addUser(User a)
{
	repoUseri->add(a);
}

void Service::modifyAccesUser(string username, int id, int acces)
{
	vector<Angajat> allAngajati;
	int accesUser=0, accesChange=0, idChange=0;
	string numeChange, emailChange;
	for (int i = 0; i < getlAllAngajati().size(); i++)
	{
		if (username == getlAllAngajati()[i].getNume())
		{
			accesUser = getlAllAngajati()[i].getAcces();
			break;
		}
	}
	for (int i = 0; i < getlAllAngajati().size(); i++)
	{	
		if (id == getlAllAngajati()[i].getID())
		{
			idChange = getlAllAngajati()[i].getID();
			numeChange = getlAllAngajati()[i].getNume();
			emailChange = getlAllAngajati()[i].getEmail();
			accesChange = getlAllAngajati()[i].getAcces();
			break;
		}

	}
	/*bool ok = 0;
	for (Angajat angajat : allAngajati)
		if (id == angajat.getID())
			ok = 1;
	if (ok == 0)
		throw ServiceException("Nu exista Angajat cu acest id!\n");*/
	Angajat angajatChange(idChange, numeChange, emailChange, accesChange);
	if (accesUser > accesChange)
	{
		Angajat aux(idChange, numeChange, emailChange, acces);
		repoAngajati->update(angajatChange, aux);
	}
	//((RepositoryFileTXT<Angajat>*)repoAngajati)->saveToFile();
}

Service::~Service()
{
}

string random_string()
{
	const char* caractere = "123456789ABCDEFGHIJKLMNOPQRSTabcdefghijklmnopqrst";
	string random;
	for (int i = 1; i <= 10; i++)
		random = random + caractere[rand() % 48];
	return random;
}

void testService()
{
	IRepository<Medicament>* repoMedicamente = new RepositoryFileTXT<Medicament>("Medicamente.txt");
	IRepository<Angajat>* repoAngajat = new RepositoryFileTXT<Angajat>("Angajati.txt");
	IRepository<User>* repoUseri = new RepositoryFileTXT<User>("Users.txt");
	Service s(repoMedicamente, repoAngajat, repoUseri);
	Medicament m1(100, "parasinus", false, 10, "p1");
	Medicament m2(200, "ketanol", false, 90, "p2");
	Medicament m3(300, "antibiotic", true, 70, "p3");
	s.add(m1);
	s.add(m2);
	s.add(m3);
	assert(s.getAll().size() == 3);
	s.remove(200);
	assert(s.getAll().size() == 2);
	assert(s.search("parasinus").size() == 1);
	s.addAngajat(Angajat(1, "Alin", "alinalin@yahoo.com", 1005));
	for (int i = 2; i <= 111; i++)
		s.addAngajat(Angajat(i, random_string(), random_string(), rand()));
	User u("Alin", "alinalin");
	s.addUser(u);
	int accesRandom;
	for (int i = 0; i < 1001; i++)
	{
		bool isItOkToChange = false;
		accesRandom = rand()%1005;
		int actual_id = 2 + (i % 110);
		vector<Angajat> angajatiTest = s.getlAllAngajati();
		auto it = angajatiTest.begin();
		if (s.getlAllAngajati()[actual_id - 1].getAcces() < 1005)
			isItOkToChange = true;
		s.modifyAccesUser("Alin",actual_id, accesRandom);
		if (isItOkToChange == true)
		{
			/*vector<Angajat> angajatiTest = s.getlAllAngajati();
			auto it = angajatiTest.begin();
			while (it != angajatiTest.end())
			{
				if ((*it).getID() == actual_id)
				{

					assert((*it).getAcces() == accesRandom);
					break;
				}
				++it;
			}*/
			assert(s.getlAllAngajati()[actual_id - 1].getAcces() == accesRandom);
		}
	}
	int i = 0;
}