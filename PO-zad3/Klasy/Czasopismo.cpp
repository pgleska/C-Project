#include "Czasopismo.h"
#include <iostream>
using namespace std;

Czasopismo::Czasopismo() {

}

Czasopismo::Czasopismo(bool kol, string rok, int isbn, string nam) :Wydawnictwo(isbn, nam) {
	czyKolorowe = kol;
	rokWydania = rok;
}

void Czasopismo::setKolorowe(bool kol) {
	czyKolorowe = kol;
}

bool Czasopismo::getKolorowe() {
	return czyKolorowe;
}

void Czasopismo::setRokWydania(string rok) {
	rokWydania = rok;
}

string Czasopismo::getRokWydania() {
	return rokWydania;
}

void Czasopismo::show() {
	cout << "Czy czasopismo jest kolorowe: " << czyKolorowe << " i zostalo wydane Anno Domini: " << rokWydania << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

void Czasopismo::update() {

}