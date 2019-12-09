#include "pch.h"
#include "listaCumparaturi.h"

listaCumparaturi::listaCumparaturi() {

}
listaCumparaturi::listaCumparaturi(string nume, vector<pair<string, float>> l) {
	numeLista = nume;
	for (auto x : l) {
		produse.push_back(x);
	}
}
listaCumparaturi::listaCumparaturi(vector<pair<string, float>> l) {
	numeLista = "Lista Nedenumita";
	for (auto x : l) {
		produse.push_back(x);
	}
}
listaCumparaturi::listaCumparaturi(const listaCumparaturi& l) {
	numeLista = l.numeLista;
	produse = l.produse;
}
listaCumparaturi::listaCumparaturi(string fileName) {
	ifstream fin(fileName);
	fin >> numeLista;
	while (true) {
		string n;
		float c;
		fin >> n >> c;
		produse.push_back(make_pair(n, c));
		if (fin.eof()) break;
	}
	fin.close();
}
listaCumparaturi::~listaCumparaturi() {

}

string listaCumparaturi::getName() {
	return numeLista;
}
vector<pair<string, float>> listaCumparaturi::getList() {
	return produse;
}
void listaCumparaturi::setList(vector<pair<string, float>> p) {
	produse = p;
}
ostream & operator << (ostream &out, const listaCumparaturi &l) {
	out << l.numeLista << endl;
	for (auto x : l.produse) {
		out << x.first << " | " << x.second << endl;
	}
	return out;
}

istream & operator >> (istream &in, listaCumparaturi &l) {
	cout << "Introduceti numele listei: ";
	in >> l.numeLista;
	cout << "Introduceti numarul de produse de pe lista: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string n;
		float c;
		in >> n >> c;
		l.produse.push_back(make_pair(n, c));
	}
	return in;
}
