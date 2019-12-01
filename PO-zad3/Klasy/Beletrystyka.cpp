#include "Beletrystyka.h"
#include <iostream>
#include <string>
using namespace std;

Beletrystyka::Beletrystyka(string war, string years, string opr, string aut, int isbn, string name) :Ksiazka(opr, aut, isbn, name) {
	wojna = war;
	lata = years;
}

void Beletrystyka::setWojna(string war) {
	wojna = war;
}

string Beletrystyka::getWojna() {
	return wojna;
}

void Beletrystyka::setLata(string years) {
	lata = years;
}

string Beletrystyka::getLata() {
	return lata;
}

void Beletrystyka::show() {
	cout << "W ksiazce opisana wojna jest: " << wojna << ", ktora miala miejsce w latach: " << lata << endl;
	cout << "Autorem jest: " << getAutor() << " i ksiazka ma oprawe typu: " << getOprawa() << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

string Beletrystyka::zapisDoPliku() {
	string wynik;
	wynik = wojna + " " + lata + " " + getOprawa() + " " + getAutor() + " " + to_string(getNumerISBN()) + " " + getNazwa();
	return wynik;
}

void Beletrystyka::update() {
	string param;
	cout << "Podaj parametry oddzielone spacjami (wojna, lata, oprawa, autor, numer ISBN, nazwa), jesli nie chcesz edytowac podaj 0" << endl;
	cin >> param;
	if (param != "0") {
		setWojna(param);
	}
	cin >> param;
	if (param != "0") {
		setLata(param);
	}
	cin >> param;
	if (param != "0") {
		setOprawa(param);
	}
	cin >> param;
	if (param != "0") {
		setAutor(param);
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
