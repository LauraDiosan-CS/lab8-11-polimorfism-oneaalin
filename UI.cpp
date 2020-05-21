#include "UI.h"
#include <iostream>
using namespace std;
#include "Validator.h";

int UI::login()
{
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user: ";
	cin >> user;
	cout << endl << "Parola: ";
	cin >> pass;
	return s.login(user, pass);
}

void UI::add()
{
	cout << "Dati ID-ul : ";
	int id;
	cin >> id;
	cout << "Dati numele medicamentului : ";
	string nume;
	cin >> nume;
	cout << "Necesita reteta [true,false] : ";
	bool reteta;
	cin >> reteta;
	cout << "Dati numarul stocului : ";
	int stoc;
	cin >> stoc;
	cout << "Dati numele producatorului : ";
	string producator;
	cin >> producator;
	Medicament m(id, nume, reteta, stoc, producator);
	s.add(m);
}

void UI::remove()
{
	cout << "Dati ID-ul medicamentului de sters : ";
	int id; cin >> id;
	s.remove(id);
}

void UI::update()
{
	cout << "Dati ID-ul medicamentului de modificat : ";
	int id_vechi; cin >> id_vechi;
	cout << "Dati numele medicamentului de modificat : ";
	string nume_vechi; cin >> nume_vechi;
	cout << "Dati necesitatea retetei de modificat : ";
	bool reteta_veche; cin >> reteta_veche;
	cout << "Dati stocul medicamentului de moficiat : ";
	int stoc_vechi; cin >> stoc_vechi;
	cout << "Dati numele producatorului de modificat : ";
	string producator_vechi; cin >> producator_vechi;
	cout << "Dati noul ID al medicamentului : ";
	int id_nou; cin >> id_nou;
	cout << "Dati noul nume al medicamentului : ";
	string nume_nou; cin >> nume_nou;
	cout << "Dati noua necesitate a retei : ";
	bool reteta_noua; cin >> reteta_noua;
	cout << "Dati noul stoc al medicamentului : ";
	int stoc_nou; cin >> stoc_nou;
	cout << "Dati noul producator al medicamentului : ";
	string producator_nou; cin >> producator_nou;
	Medicament med_vechi(id_vechi, nume_vechi, reteta_veche, stoc_vechi, producator_vechi);
	Medicament med_nou(id_nou, nume_nou, reteta_noua, stoc_nou, producator_nou);
	s.update(med_vechi, med_nou);
}

void UI::search()
{
	cout << "Dati secventa pe care doriti sa o cautati : ";
	string to_search; cin >> to_search;
	vector<Medicament> toShow = s.search(to_search);
	for (Medicament med : toShow)
		cout << med.toString() << endl;
}

void UI::modify()
{
	cout << "Dati ID-ul angajatului : ";
	int id; cin >> id;
	cout << "Dati noul grad de acces al angajatului : ";
	int acces; cin >> acces;
	s.modifyAccesUser(u.getUserName(), id, acces);
}

void UI::showAll()
{
	vector<Medicament> allMeds = s.getAll();
	for (Medicament med : allMeds)
		cout << med.toString() << endl;
}

void UI::showAllAngajati()
{
	vector<Angajat> allAngajati = s.getlAllAngajati();
	for (Angajat ang : allAngajati)
		cout << ang.toString() << endl;
}
UI::UI()
{
}

UI::UI(Service& ss)
{
	s = ss;
}

void UI::showMenu()
{
	bool gata = false;
	int rez;
	while (!gata)
	{
		cout << "Te rugam sa te loghezi : " << endl;
		rez = login();
		if (rez == 0)
			cout << "Logarea a esuat ! " << endl;
		while (rez != 0)
		{
			cout << "1. Adauga un medicament" << endl;
			cout << "2. Sterge un medicament" << endl;
			cout << "3. Modifica un medicament" << endl;
			cout << "4. Afiseaza toate medicamentele" << endl;
			cout << "5. Afiseaza toate medicamentele care contin o secventa data" << endl;
			cout << "6. Modifica gradul de acces al unui angajat dupa id" << endl;
			cout << "7. Logout" << endl;
			cout << "8. Afiseaza toti angajatii" << endl;
			cout << "0. Exit" << endl;
			int opt;
			cout << "Dati optiunea : " << endl;
			cin >> opt;
			try{
				switch (opt) {
				case 1: {add(); break; }
				case 2: {remove(); break; }
				case 3: {update(); break; }
				case 4: {showAll(); break; }
				case 5: {search(); break; }
				case 6: {modify(); break; }
				case 7: {rez = 0; break; }
				case 8: {showAllAngajati(); break; }
				case 0: {gata = true; rez = 0; break; }
				}
			}
			catch (RepoException& ex)
			{
				cout << ex.getMessage();
			}
			catch (ServiceException& ex)
			{
				cout << ex.getMessage();
			}
			catch (ValidateException& ex)
			{
				cout << ex;
			}
		}
	}
}

UI::~UI()
{
}