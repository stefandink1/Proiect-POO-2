#include "pch.h"
#include "Magazin.h"

int main()
{
	Magazin m("inputMagazin.txt");
	cout << "Bine ati venit!" << endl;

	while (true) {
		cout << "Avem client? (y/n)";
		char choice;
		cin >> choice;
		if (tolower(choice) != 'y') break;
		cout << m << endl;
		cout << "Introduceti lista de cumparaturi: " << endl;
		listaCumparaturi lista;
		cin >> lista;
		vector<Produs*> tmpList = m.checkList(lista.getList());
		float pret = m.calculeazaPret(tmpList);
		cout << "Pretul listei este: " << pret << endl;
		cout << "Doriti sa achizitionati? (y/n)" << endl;
		cin >> choice;
		if (tolower(choice) == 'y') {
			m.tranzactie(pret, tmpList);
			cout << "Multumim pentru achizitie, va mai asteptam pe la noi!" << endl;
		}
		else {
			cout << "Nici o problema, va mai asteptam pe la noi!" << endl;
		}
	}
	m.finalZi();
}
