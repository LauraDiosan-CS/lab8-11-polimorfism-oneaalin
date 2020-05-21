#include "User.h"

User::User()
{
}

User::User(string a, string b) :userName(a), password(b)
{
}

User::User(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	userName = tokens[0];
	password = tokens[1];
}

string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

void User::setUserName(string a)
{
	userName = a;
}

void User::setPassword(string a)
{
	password = a;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

string User::toString()
{
	return userName + " " + password;
}

string User::toStringDelimiter(char delimiter)
{
	return userName + delimiter + password;
}

User::~User()
{
}