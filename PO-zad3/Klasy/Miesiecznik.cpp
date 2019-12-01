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
	string param;
	cout << "Podaj parametry oddzielone spacjami (miesiac wydania, temat, czy jest kolorowy [T/N], rok wydania, numer ISBN, nazwa), jesli nie chcesz edytowac podaj 0" << endl;
	cin >> param;
	if (param != "0") {
		setMiesiacWydania(param);
	}
	cin >> param;
	if (param != "0") {
		setTemat(param);
	}
	cin >> param;
	if (param != "0") {
		if (param == "T") {
			setKolorowe(true);
		}
		else {
			setKolorowe(false);
		}
	}
	cin >> param;
	if (param != "0") {
		setRokWydania(param);
	}
	cin >> param;
	if (param != "0") {
		setNumerISBN(stoi(param));
	}
	cin >> param;
	if (param != "0") {
		setNazwa(param);
	}

	cout << "Modyfikowanie zakonczone" << endl;
}