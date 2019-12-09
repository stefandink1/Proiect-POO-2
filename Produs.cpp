#include "pch.h"
#include "Produs.h"


// CONSTRUCTORS & DESTRUCTOR

Produs::Produs() {

}

Produs::Produs(string nume, float pret, float cant, string unit) {
	denumire = nume;
	pretUnitate = pret;
	cantitate = cant;
	unitate = unit;
}

Produs::~Produs()
{
}

Produs::Produs(const Produs &p) {
	denumire = p.denumire;
	pretUnitate = p.pretUnitate;
	cantitate = p.cantitate;
	unitate = p.unitate;
}
void Produs::operator=(const Produs &p) {
	denumire = p.denumire;
	pretUnitate = p.pretUnitate;
	cantitate = p.cantitate;
	unitate = p.unitate;
}


//SETERS & GETERS
string Produs::getNume() {
	return denumire;
}
float Produs::getPret() {
	return pretUnitate;
}

float Produs::getCantitate() {
	return cantitate;
}

void Produs::setCantitate(float n) {
	cantitate = n;
}

string Produs::getUnitate() {
	return unitate;
}

// CIN & COUT OVERLOAD

ostream & operator << (ostream &out, const Produs &p){
	out << "Denumire: " << p.denumire << " | " << p.cantitate << " | " << p.pretUnitate << "/" << p.unitate << endl;
	return out;
}

istream & operator >> (istream &in, Produs &p){
	in >> p.denumire >> p.cantitate >> p.pretUnitate >> p.unitate;
	return in;
}