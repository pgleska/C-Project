#include "Miesiecznik.h"
#include <iostream>
using namespace std;

Miesiecznik::Miesiecznik(string mies, string topic, bool kol, string rok, int isbn, string nam) :Czasopismo(kol, rok, isbn, nam) {
	miesiacWydania = mies;
	temat = topic;
}

void Miesiecznik::setMiesiacWydania(string mies) {
	miesiacWydania = mies;
}

string Miesiecznik::getMiesiacWydania() {
	return miesiacWydania;
}

void Miesiecznik::setTemat(string topic) {
	temat = topic;
}

string Miesiecznik::getTemat() {
	return temat;
}

void Miesiecznik::show() {
	cout << "Czasopismo zostalo wydane w miesiacu: " << miesiacWydania << ", a jego tematem jest/sa: " << temat << endl;
	cout << "Czy czasopismo jest kolorowe: " << getKolorowe() << " i zostalo wydane Anno Domini: " << getRokWydania() << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

string Miesiecznik::zapisDoPliku() {
	string wynik;
	string kolorowe;
	if (getKolorowe()) {
		kolorowe = "T";
	}
	else {
		kolorowe = "N";
	}
	wynik = miesiacWydania + " " + temat + " " + kolorowe + " " + getRokWydania() + " " + to_string(getNumerISBN()) + " " + getNazwa();
	return wynik;
}

void Miesiecznik::update() {

}