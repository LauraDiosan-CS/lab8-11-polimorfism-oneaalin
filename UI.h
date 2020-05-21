#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI
{
private:
	Service s;
	User u;
	int login();
	void add();
	void remove();
	void update();
	void search();
	void showAll();
	void showAllAngajati();
	void modify();

public:
	UI();
	UI(Service&);
	void showMenu();
	~UI();
};

