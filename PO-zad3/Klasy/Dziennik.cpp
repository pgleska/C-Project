#include "Dziennik.h"
#include <iostream>
using namespace std;

Dziennik::Dziennik() {

}

Dziennik::Dziennik(string date, bool intres, bool kol, string rok, int isbn, string nam) :Czasopismo(kol, rok, isbn, nam) {
	dataWydania = date;
	czyCiekawa = intres;
}

void Dziennik::setDataWydania(string date) {
	dataWydania = date;
}

string Dziennik::getDataWydania() {
	return dataWydania;
}

void Dziennik::setCiekawa(bool intres) {
	czyCiekawa = intres;
}

bool Dziennik::getCiekawa() {
	return czyCiekawa;
}

void Dziennik::show() {
	cout << "Czasopismo zostalo wydanie w dniu: " << dataWydania << " i czy jest ciekawa: " << czyCiekawa << endl;
	cout << "Czy czasopismo jest kolorowe: " << getKolorowe() << " i zostalo wydane Anno Domini: " << getRokWydania() << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

string Dziennik::zapisDoPliku() {
	return "";
}

void Dziennik::update() {

}
