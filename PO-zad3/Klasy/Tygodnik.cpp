#include "Tygodnik.h"
#include <iostream>
using namespace std;

Tygodnik::Tygodnik() {

}

Tygodnik::Tygodnik(string tyg, string author, bool kol, string rok, int isbn, string nam) :Czasopismo(kol, rok, isbn, nam) {
	tydzienWydania = tyg;
	autor = author;
}

void Tygodnik::setTydzienWydania(string tyg) {
	tydzienWydania = tyg;
}

string Tygodnik::getTydzienWydania() {
	return tydzienWydania;
}

void Tygodnik::setAutor(string author) {
	autor = author;
}

string Tygodnik::getAutor() {
	return autor;
}

void Tygodnik::show() {
	cout << "Czasopismo zostalo wydane w tygodniu: " << tydzienWydania << ", a jego autorem jest: " << autor << endl;
	cout << "Czy czasopismo jest kolorowe: " << getKolorowe() << " i zostalo wydane Anno Domini: " << getRokWydania() << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

string Tygodnik::zapisDoPliku() {
	return "";
}

void Tygodnik::update() {

}