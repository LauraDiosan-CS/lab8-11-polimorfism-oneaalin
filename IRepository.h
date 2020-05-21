#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
// Repository type object using template class

class RepoException
{
private:
	string msg;
public:
	RepoException(string s) : msg{ s } {}
	string getMessage()
	{
		return msg;
	}
};

template<class T> class IRepository
{
protected:
	vector<T> elem;
public:
	/*
		Constructor
		Input:-
		Output:-
	*/
	IRepository();
	/*
		Adds a T type object in the repository
		Input:T type object
		Output:-
	*/
	void add(T&);
	/*
		Find a T type object in 
	*/
	int find(T&);
	void update(T&, T&);
	int remove(int);
	int size();
	vector<T> getAll();
};

template<class T>
inline IRepository<T>::IRepository()
{
}

template<class T>
inline void IRepository<T>::add(T& e)
{
	if (find(e) > -1)
		throw RepoException("Entitatea exista deja in lista !\n");
	elem.push_back(e);
}

template<class T>
inline int IRepository<T>::find(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end())
		return std::distance(elem.begin(), it);
	return -1;
}

template<class T>
inline void IRepository<T>::update(T& vechi, T& nou)
{
	if (find(vechi) == -1)
		throw RepoException("Entitatea nu exista in lista!\n");
	replace(elem.begin(), elem.end(), vechi, nou);
}

template<class T>
inline int IRepository<T>::remove(int id)
{
	bool ok=0;
	for (int i = 0; i < elem.size(); i++)
		if (elem[i].getID() == id)
			ok = 1;
	if (ok == 0)
		throw RepoException("Nu exista entitate cu acest id\n");
	for (int i=0;i<=elem.size();i++)
		if (elem[i].getID() == id)
		{
			elem.erase(elem.begin() + i);
				return 1;
		}
	return -1;
}

template<class T>
inline int IRepository<T>::size()
{
	return elem.size();
}

template<class T>
inline vector<T> IRepository<T>::getAll()
{
	return elem;
}



