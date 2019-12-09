#include "pch.h"
#include "Magazin.h"

// CONSTRUCTORS & DESTRUCTOR
Magazin::Magazin() {

}
Magazin::Magazin(vector<Produs*> produse) {
	totalBani = 0;
	for (Produs* p : produse) {
		produseAccesibile.push_back(p);
	}
}

Magazin::Magazin(string fileName) {
	ifstream fin(fileName);
	string line;
	while (true) {
		string d, u;
		float p, c;
		fin >> d;
		fin >> c;
		fin >> p;
		fin >> u;
		produseAccesibile.push_back(new Produs(d, p, c, u));
		if (fin.eof()) break;
	}
	fin.close();
}

Magazin::~Magazin()
{
}

// SHOP FUNCTIONALITY

void Magazin::tranzactie(float pret, vector<Produs*> produse) {
	totalBani += pret;
	produseVandute.push_back(make_pair(pret, produse));
}

float Magazin::calculeazaPret(vector<Produs*> lista) {
	float currentPrice = 0;
	for (auto p : lista) {
		currentPrice += p->getPret()*p->getCantitate();
		for (auto x : produseAccesibile) {
			if (x->getNume().find(p->getNume()) != string::npos) {
				x->setCantitate(x->getCantitate() - p->getCantitate());
			}
		}
	}
	return currentPrice;
}

vector<Produs*> cautaProdus(string nume, vector<Produs*> produse) {
	vector<Produs*> tmp;
	for (auto x : produse) {
		string a = x->getNume(), b = nume;
		transform(a.begin(), a.end(), a.begin(), ::toupper);
		transform(b.begin(), b.end(), b.begin(), ::toupper);
		if (a.find(b) != string::npos) {
			tmp.push_back(x);
		}
	}
	return tmp;
}

vector<Produs*> Magazin::checkList(vector<pair<string, float>> lista) {
	vector<Produs*> tmp;
	for (auto x : lista) {
		vector<Produs*> produs = cautaProdus(x.first, produseAccesibile);
		if (produs.size() == 0) {
			cout << "Nu avem " << x.first << endl;
		}
		else if (produs.size() == 1 && x.second <= produs[0]->getCantitate()) {
			tmp.push_back(new Produs(produs[0]->getNume(), produs[0]->getPret(), x.second, produs[0]->getUnitate()));
		}
		else if (produs.size() == 1 && x.second > produs[0]->getCantitate()) {
			cout << "Nu avem cantitatea dorita pentru " << produs[0]->getNume() << ", doriti sa va dam ce ne-a ramas pe stoc? (y/n)" << endl;
			char choice;
			cin >> choice;
			if (tolower(choice) == 'y') {
				tmp.push_back(new Produs(produs[0]->getNume(), produs[0]->getPret(), produs[0]->getCantitate(), produs[0]->getUnitate()));
			}
			cout << "Ok." << endl;
		}
		else if (produs.size() > 1) {
			cout << "In loc de " << x.first << " avem:" << endl;
			int i = 0;
			for (i; i < produs.size(); i++) {
				cout << i << ". " << produs[i]->getNume() << endl;
			}
			cout << "Doriti unul din produsele listate? (indexul/-1)" << endl;
			int choice;
			cin >> choice;

			if (choice != -1) {
				i = choice;
				if (x.second <= produs[i]->getCantitate()) {
					tmp.push_back(new Produs(produs[i]->getNume(), produs[i]->getPret(), x.second, produs[i]->getUnitate()));
				}
				else {
					cout << "Nu avem cantitatea dorita pentru "<< produs[i]->getNume() <<", doriti sa va dam ce ne-a ramas pe stoc? (y/n)" << endl;
					char choice2;
					cin >> choice2;
					if (tolower(choice) == 'y') {
						tmp.push_back(new Produs(produs[i]->getNume(), produs[i]->getPret(), produs[i]->getCantitate(), produs[i]->getUnitate()));
					}
				}
			}
			cout << "Ok." << endl;
		}
	}
	return tmp;
}

void Magazin::finalZi() {
	cout << endl << "Inventarul magazinului: " << endl;
	cout << "Total bani: " << totalBani << endl;
	for (int i = 0; i < produseVandute.size(); i++) {
		cout << endl << "Clientul " << i + 1 << endl << "Suma bani: " << produseVandute[i].first << endl << "Produse achizitionate: " << endl;
		for (Produs* x : produseVandute[i].second) {
			cout << *x;
		}
	}
}
// SHOP IN & OUT

ostream & operator << (ostream &out, const Magazin &m) {
	out << "Produse in stoc: " << endl;
	for (Produs* p : m.produseAccesibile) {
		out << *p;
	}
	return out;
}

istream & operator >> (istream &in, Magazin &m) {
	cout << "Introduceti numarul de produse in stoc: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Produs p;
		in >> p;
		m.produseAccesibile.push_back(new Produs(p));
	}
	return in;
}