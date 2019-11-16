#include "Popularnonaukowa.h"
#include <iostream>
using namespace std;

Popularnonaukowa::Popularnonaukowa(string topic, bool intres, string opr, string aut, int isbn, string name) :Ksiazka(opr, aut, isbn, name) {
	temat = topic;
	czyCiekawa = intres;
}

void Popularnonaukowa::setTemat(string topic) {
	temat = topic;
}

string Popularnonaukowa::getTemat() {
	return temat;
}

void Popularnonaukowa::setCiekawa(bool intres) {
	czyCiekawa = intres;
}

bool Popularnonaukowa::getCiekawa() {
	return czyCiekawa;
}

void Popularnonaukowa::show() {
	cout << "Tematem ksiazki jest: " << temat << " i czy jest ciekawa: " << czyCiekawa << endl;
	cout << "Autorem jest: " << getAutor() << " i ksiazka ma oprawe typu: " << getOprawa() << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

string Popularnonaukowa::zapisDoPliku() {
	string wynik;
	string ciekawa;
	if (czyCiekawa) {
		ciekawa = "T";
	}
	else {
		ciekawa = "N";
	}
	wynik = temat + " " + ciekawa + " " + getOprawa() + " " + getAutor() + " " + to_string(getNumerISBN()) + " " + getNazwa();
	return wynik;
}

void Popularnonaukowa::update() {

}