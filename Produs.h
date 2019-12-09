#ifndef __PRODUS_H__
#define __PRODUS_H__

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produs
{
private:
	string denumire;
	float pretUnitate;
	float cantitate;
	string unitate;
public:
	Produs();
	Produs(string nume, float pret, float cant, string unit);
	~Produs();
	Produs(const Produs &p);

	void operator=(const Produs &p);

	string getNume();
	float getPret();
	float getCantitate();
	void setCantitate(float n);
	string getUnitate();

	friend ostream & operator << (ostream &out, const Produs &p);
	friend istream & operator >> (istream &in, Produs &p);
};

#endif