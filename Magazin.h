#ifndef __MAGAZIN_H__
#define __MAGAZIN_H__

#include "Produs.h"
#include "listaCumparaturi.h"
#include <fstream>
#include <algorithm>
class Magazin {
private:
	float totalBani;
	vector<Produs*> produseAccesibile;
	vector<pair<float, vector<Produs*>>> produseVandute;
public:
	Magazin();
	Magazin(vector<Produs*> produse);
	Magazin(string fileName);
	~Magazin();

	void tranzactie(float pret, vector<Produs*> produse);
	float calculeazaPret(vector<Produs*> produse);
	vector<Produs*> checkList(vector<pair<string, float>> produse);
	void finalZi();

	friend ostream & operator << (ostream &out, const Magazin &m);
	friend istream & operator >> (istream &in, Magazin &m);
};

#endif