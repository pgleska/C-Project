#include "Wezel.h"

Wezel::Wezel() {

}

Wezel::Wezel(int i, string nazwa) {
	id = i;
	czyBiezacy = false;
	nazwaWezla = nazwa;
}

int Wezel::getId() {
	return id;
}

void Wezel::setBiezacy(bool bl) {
	czyBiezacy = bl;
}

bool Wezel::getBiezacy() {
	return czyBiezacy;
}

void Wezel::setNazwaWezla(string nazwa) {
	nazwaWezla = nazwa;
}

string Wezel::getNazwaWezla() {
	return nazwaWezla;
}

void Wezel::setPodWezly(Wezel* W) {
	podwezly.push_back(W);
}

void Wezel::nowyObiekt(string opis) {
	string param1, param2, param3, param4, param5, param6, param7, param8, param9, typ;
	bool boolean1 = false, istnieje = false, boolean2 = false;

	if (id == 6) {
		cout << "Podaj parametry oddzielone spacjami: Temat, czy jest ciekawa [T/N] (inny wybor oznacza N), rodzaj oprawy, autor, numerISBN (mniejszy od 32000), nazwe dziela:" << endl;
		cin >> param1;
		cin >> param2;
		if (param2 == "T") {
			boolean1 = true;
		}
		cin >> param3;
		cin >> param4;
		cin >> param5;
		cin >> param6;

		istnieje = sprawdzCzyIstnieje(param6);

		if (!istnieje) {
			Popularnonaukowa* p1 = new Popularnonaukowa(param1, boolean1, param3, param4, stoi(param5), param6);
			obiekty.insert(pair<string, Wydawnictwo*>(param6, p1));
			cout << "Tworze obiekt typu Popularnonaukowa o nazwie: " << p1->getNazwa() << endl;
		}
		else {
			cout << "Obiekt o podanej nazwie juz istnieje, podaj inna, wywolaj jeszcze raz polecenie 'MO'" << endl;
		}

	}
	else if (id == 7) {
		cout << "Podaj parametry oddzielone spacjami: Wojna, lata, rodzaj oprawy, autor, numerISBN (mniejszy od 32000), nazwe dziela:" << endl;
		cin >> param1;
		cin >> param2;
		cin >> param3;
		cin >> param4;
		cin >> param5;
		cin >> param6;

		istnieje = sprawdzCzyIstnieje(param6);

		if (!istnieje) {
			Beletrystyka* b1 = new Beletrystyka(param1, param2, param3, param4, stoi(param5), param6);
			obiekty.insert(pair<string, Wydawnictwo*>(param6, b1));
			cout << "Tworze obiekt typu Beletrystyka o nazwie: " << b1->getNazwa() << endl;
		}
	}
	else if (id == 8) {
		cout << "Podaj parametry oddzielone spacjami: miesiac wydania, temat, czy jest to kolorowe czasopismo [T/N] (inny wybor oznacza N), rok wydania, numerISBN (mniejszy od 32000), nazwe dziela:" << endl;
		cin >> param1;
		cin >> param2;
		cin >> param3;
		cin >> param4;
		cin >> param5;
		cin >> param6;

		istnieje = sprawdzCzyIstnieje(param6);

		if (param3 == "T") {
			boolean1 = true;
		}

		if (!istnieje) {
			Miesiecznik* m1 = new Miesiecznik(param1, param2, boolean1, param4, stoi(param5), param6);
			obiekty.insert(pair<string, Wydawnictwo*>(param6, m1));
			cout << "Tworze obiekt typu Miesiecznik o nazwie: " << m1->getNazwa() << endl;
		}
		else {
			cout << "Obiekt o podanej nazwie juz istnieje, podaj inna, wywolaj jeszcze raz polecenie 'MO'" << endl;
		}
	}
	else if (id == 9) {
		cout << "Skad ma pochodzic artykul: Dziennik czy Tygodnik [D/T]?" << endl;
		cin >> typ;
		if (typ == "T") {
			cout << "Podaj parametry oddzielone spacjami: nazwa artykulu, numer ISBN artykulu, dlugosc, tydzien wydania, autor, czy jest to kolorowe czasopismo [T/N] (inny wybor oznacza N), rok wydania, numerISBN (mniejszy od 32000), nazwe pochodzenia:" << endl;
			cin >> param1;
			cin >> param9;
			cin >> param2;
			cin >> param3;
			cin >> param4;
			cin >> param5;
			cin >> param6;
			cin >> param7;
			cin >> param8;

			istnieje = sprawdzCzyIstnieje(param1);



			if (param5 == "T") {
				boolean1 = true;
			}

			if (!istnieje) {
				Artykul<Tygodnik>* a1 = new Artykul<Tygodnik>(new Tygodnik(param3, param4, boolean1, param6, stoi(param7), param8), stoi(param2), param1, stoi(param9));
				obiekty.insert(pair<string, Wydawnictwo*>(param1, a1));
				cout << "Tworze obiekt typu Artykul z Dziennika o nazwie: " << a1->getNazwa() << endl;
			}
			else {
				cout << "Obiekt o podanej nazwie juz istnieje, podaj inna, wywolaj jeszcze raz polecenie 'MO'" << endl;
			}
		}
		else if (typ == "D") {
			cout << "Podaj parametry oddzielone spacjami: nazwa artykulu, numer ISBN artykulu, dlugosc, data wydania, czy jest to ciekawe [T/N] (inny wybor oznacza N), czy jest to kolorowe czasopismo [T/N] (inny wybor oznacza N), rok wydania, numerISBN (mniejszy od 32000), nazwe pochodzenia:" << endl;
			cin >> param1;
			cin >> param9;
			cin >> param2;
			cin >> param3;
			cin >> param4;
			cin >> param5;
			cin >> param6;
			cin >> param7;
			cin >> param8;

			istnieje = sprawdzCzyIstnieje(param1);

			if (param4 == "T") {
				boolean1 = true;
			}

			if (param5 == "T") {
				boolean2 = true;
			}

			if (!istnieje) {
				Artykul<Dziennik>* a1 = new Artykul<Dziennik>(new Dziennik(param3, boolean1, boolean2, param6, stoi(param7), param8), stoi(param2), param1, stoi(param9));
				obiekty.insert(pair<string, Wydawnictwo*>(param1, a1));
				cout << "Tworze obiekt typu Artykul z Dziennika o nazwie: " << a1->getNazwa() << endl;
			}
			else {
				cout << "Obiekt o podanej nazwie juz istnieje, podaj inna, wywolaj jeszcze raz polecenie 'MO'" << endl;
			}
		}
		else {
			cout << "Podano bledne pochodzenie, artykul nie zostal stworzony" << endl;
		}
	}
	else {
		cout << "Nie mozna utworzyc obiektu w tym wezle" << endl;
	}
}

void Wezel::usunObiekt() {
	string nazwaDoUsuniecia;
	cout << "Podaj nazwe obiektu do usuniecia" << endl;
	cin >> nazwaDoUsuniecia;
	for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
		if (it->first == nazwaDoUsuniecia) {
			delete it->second;
			obiekty.erase(it);
			cout << "Obiekt zostal usuniety o nazwie " << nazwaDoUsuniecia << " zostal usuniety" << endl;
			break;
		}
		else {
			cout << "Obiekt jest prawdopodobnie w innym wezle" << endl;
		}
	}
}

void Wezel::pokazListe(int shift) {
	int i = 0;

	for (i = 0; i < shift - 3; i++) {
		cout << " ";
	}
	for (i = shift - 3; (i >= 0) && (i < shift); i++) {
		cout << "-";
	}
	cout << getNazwaWezla() << endl;
	for (i = 0; i < shift; i++) {
		cout << " ";
	}
	if (!podwezly.empty()) {
		shift += 3;
	}
	if (id >= 6) {
		cout << "|" << endl;
		for (i = 0; i < shift; i++) {
			cout << " ";
		}
		cout << "---";
		for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
			cout << it->second->getNazwa() << " ";
		}
	}
	cout << endl;
	if (!podwezly.empty()) {
		for (auto wsk : podwezly) {
			for (i = 0; i < shift - 3; i++) {
				cout << " ";
			}
			cout << "|" << endl;
			wsk->pokazListe(shift);
		}
	}
}

void Wezel::modyfikujObiekt() {
	string nazwaDoEdycji, czyZwiekszyc;
	bool zmodyfikowany = false;
	cout << "Podaj nazwe obiektu do edycji numeru ISBN" << endl;
	cin >> nazwaDoEdycji;
	for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
		if (it->first == nazwaDoEdycji) {
			cout << "Czy tylko zwiekszyc numer ISBN? [T/N] W przeciwnym razie mozna zeedytowac wszystkie atrybuty" << endl;
			cin >> czyZwiekszyc;
			if (czyZwiekszyc == "T") {
				++*(it->second);
				cout << "Numer ISBN zostal zwiekszony i wynosi teraz " << it->second->getNumerISBN() << endl;
			}
			else {
				it->second->update();
				if (it->first != it->second->getNazwa()) {
					obiekty.insert(pair<string, Wydawnictwo*>(it->second->getNazwa(), it->second));
					obiekty.erase(it->first);
				}
			}
			zmodyfikowany = true;
			break;
		}
	}
	if (!zmodyfikowany) {
		cout << "Obiekt o nazwie: " << nazwaDoEdycji << " nie istnieje lub jest w innym wezle" << endl;
	}
}

bool Wezel::sprawdzCzyIstnieje(string nazwa) {
	bool istnieje = false;
	for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
		if (it->first == nazwa) {
			istnieje = true;
			break;
		}
	}
	return istnieje;
}

void Wezel::pokazObiekt() {
	string nazwaDoPokazania;
	bool pokazany = false;
	cout << "Podaj nazwe obiektu do pokazania" << endl;
	cin >> nazwaDoPokazania;
	for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
		if (it->first == nazwaDoPokazania) {
			pokazany = true;
			it->second->show();
			break;
		}
	}
	if (!pokazany) {
		cout << "Obiekt o nazwie: " << nazwaDoPokazania << " nie istnieje lub jest w innym wezle" << endl;
	}
}

string Wezel::zapisPlik() {
	string wynik;
	for (map<string, Wydawnictwo*>::iterator it = obiekty.begin(); it != obiekty.end(); it++) {
		wynik += nazwaWezla + " " + it->second->zapisDoPliku() + "\n";
	}
	if (!podwezly.empty()) {
		for (auto wsk : podwezly) {
			wynik += wsk->zapisPlik();
		}
	}
	return wynik;
}

void Wezel::wczytajObiekt(vector<string> args) {
	bool istnieje = false, boolean1 = false, boolean2 = false;
	if (id == 6) {
		if (args[1] == "T") {
			boolean1 = true;
		}
		istnieje = sprawdzCzyIstnieje(args[5]);

		if (!istnieje) {
			Popularnonaukowa* p1 = new Popularnonaukowa(args[0], boolean1, args[2], args[3], stoi(args[4]), args[5]);
			obiekty.insert(pair<string, Wydawnictwo*>(args[5], p1));
			cout << "Tworze obiekt typu Popularnonaukowa o nazwie: " << p1->getNazwa() << endl;
		}
	}
	else if (id == 7) {
		istnieje = sprawdzCzyIstnieje(args[5]);

		if (!istnieje) {
			Beletrystyka* b1 = new Beletrystyka(args[0], args[1], args[2], args[3], stoi(args[4]), args[5]);
			obiekty.insert(pair<string, Wydawnictwo*>(args[5], b1));
			cout << "Tworze obiekt typu Beletrystyka o nazwie: " << b1->getNazwa() << endl;
		}
	}
	else if (id == 8) {
		istnieje = sprawdzCzyIstnieje(args[5]);

		if (args[2] == "T") {
			boolean1 = true;
		}

		if (!istnieje) {
			Miesiecznik* m1 = new Miesiecznik(args[0], args[1], boolean1, args[3], stoi(args[4]), args[5]);
			obiekty.insert(pair<string, Wydawnictwo*>(args[5], m1));
			cout << "Tworze obiekt typu Miesiecznik o nazwie: " << m1->getNazwa() << endl;
		}
		else {
			cout << "Obiekt o podanej nazwie juz istnieje, podaj inna, wywolaj jeszcze raz polecenie 'MO'" << endl;
		}
	}
	else if (id == 9) {
		if (args[0] == "T") {

			istnieje = sprawdzCzyIstnieje(args[1]);


			if (args[6] == "T") {
				boolean1 = true;
			}

			if (!istnieje) {
				Artykul<Tygodnik>* a1 = new Artykul<Tygodnik>(new Tygodnik(args[4], args[5], boolean1, args[7], stoi(args[8]), args[9]), stoi(args[3]), args[1], stoi(args[2]));
				obiekty.insert(pair<string, Wydawnictwo*>(args[1], a1));
				cout << "Tworze obiekt typu Artykul z Tygodnika o nazwie: " << a1->getNazwa() << endl;
			}
		}
		else if (args[0] == "D") {

			istnieje = sprawdzCzyIstnieje(args[1]);

			if (args[6] == "T") {
				boolean1 = true;
			}

			if (args[7] == "T") {
				boolean2 = true;
			}

			if (!istnieje) {
				Artykul<Dziennik>* a1 = new Artykul<Dziennik>(new Dziennik(args[4], boolean2, boolean1, args[5], stoi(args[8]), args[9]), stoi(args[3]), args[1], stoi(args[2]));
				obiekty.insert(pair<string, Wydawnictwo*>(args[1], a1));
				cout << "Tworze obiekt typu Artykul z Dziennika o nazwie: " << a1->getNazwa() << endl;
			}
		}
	}
}