#include "Ksiazka.h"
#include <iostream>
using namespace std;

Ksiazka::Ksiazka(string opr, string aut, int isbn, string nam):Wydawnictwo(isbn, nam) {
	oprawa = opr;
	autor = aut;
}

void Ksiazka::setOprawa(string opr) {
	oprawa = opr;
}

string Ksiazka::getOprawa() {
	return oprawa;
}

void Ksiazka::setAutor(string aut) {
	autor = aut;
}

string Ksiazka::getAutor() {
	return autor;
}

void Ksiazka::show() {
	cout << "Autorem jest: " << autor << " i ksiazka ma oprawe typu: " << oprawa << endl;
	cout << "Nazwa dziela to: " << getNazwa() << " a jego numer ISBN to: " << getNumerISBN() << endl;
}

void Ksiazka::update() {

}
