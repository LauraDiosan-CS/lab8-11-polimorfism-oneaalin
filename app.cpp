#include "RepositoryFile.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "RepositoryInMemory.h"
#include "User.h"
#include "Medicament.h"
#include "Angajat.h"
#include <assert.h>
#include <iostream>
#include "Service.h"
#include "TestRepo.h"
#include "UI.h"

void testLiveRepo()
{
    IRepository<Medicament>* repo = new RepositoryFileTXT<Medicament>("Medicamente.txt");
    Medicament m1(100, "parasinus", false, 10, "p1");
    Medicament m2(200, "ketonal", false, 90, "p2");
    Medicament m3(300, "antibiotic", true, 70, "p3");

    repo->add(m1);
    repo->add(m2);
    assert(repo->getAll().size() == 2);
    assert(repo->getAll()[0] == m1);
    assert(repo->getAll()[1] == m2);
    repo->add(m3);
    assert(repo->getAll()[2] == m3);

    Medicament m1_new(100, "paracetamol", false, 50, "p1");
    repo->update(m1, m1_new);
    assert(repo->getAll()[0] != m1);
    assert(repo->getAll()[0] == m1_new);

    repo->remove(200);
    assert(repo->getAll().size() == 2);
}

void testLiveService()
{
    IRepository<Medicament>* repoMedicamente = new RepositoryFileTXT<Medicament>("Medicamente.txt");
    IRepository<Angajat>* repoAngajat = new RepositoryFileTXT<Angajat>("Angajati.txt");
    IRepository<User>* repoUseri = new RepositoryFileTXT<User>("Users.txt");
    Service service(repoMedicamente, repoAngajat, repoUseri);
    Medicament m1(100, "parasinus", false, 10, "p1");
    Medicament m2(200, "ketonal", false, 90, "p2");
    Medicament m3(300, "antibiotic", true, 70, "p3");

    service.add(m1);
    service.add(m2);
    assert(service.getAll().size() == 2);
    assert(service.getAll()[0] == m1);
    assert(service.getAll()[1] == m2);
    service.add(m3);
    assert(service.getAll()[2] == m3);

    assert(service.search("ic").size() == 1);
    assert(service.search("a").size() == 3);

    Medicament m1_new(100, "altceva", false, 50, "p1");
    service.update(m1, m1_new);
    assert(service.search("al").size() == 2);
    assert(service.search("al")[0] == m1_new);
    assert(service.search("al")[1] == m2);
    service.remove(200);
    assert(service.search("al").size() == 1);
    assert(service.search("al")[0] == m1_new);
}

int main()
{
    cout << "start..."<<endl;
    
    testLiveRepo();
    TestRepo test;
    test.runTests();
    testLiveService();
    //testService();


    IRepository<Medicament>* repoMed = new RepositoryFileTXT<Medicament>("meds.txt");
    IRepository<Angajat>* repoAngajati = new RepositoryFileTXT<Angajat>("angj.txt");
    IRepository<User>* repoUsers = new RepositoryFileTXT<User>("usrs.txt");
    ((RepositoryFileTXT<Medicament>*)repoMed)->loadFromFile();
    ((RepositoryFileTXT<Angajat>*)repoAngajati)->loadFromFile();
    ((RepositoryFileTXT<User>*)repoUsers)->loadFromFile();
    Service service(repoMed, repoAngajati, repoUsers);
    UI ui(service);
    ui.showMenu();
    ((RepositoryFileTXT<Medicament>*)repoMed)->saveToFile();
    ((RepositoryFileTXT<Angajat>*)repoAngajati)->saveToFile();
    ((RepositoryFileTXT<User>*)repoUsers)->saveToFile();


    cout << "Succesfuly done!";
}
