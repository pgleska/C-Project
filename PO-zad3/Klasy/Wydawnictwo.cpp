#include "Wydawnictwo.h"
#include <iostream>
using namespace std;

Wydawnictwo::Wydawnictwo() {

}

Wydawnictwo::Wydawnictwo(int isbn, string name) {
	numerISBN = isbn;
	nazwa = name;
}

Wydawnictwo::~Wydawnictwo() {

}

void Wydawnictwo::setNumerISBN(int isbn) {
	numerISBN = isbn;
}

int Wydawnictwo::getNumerISBN() {
	return numerISBN;
}

void Wydawnictwo::setNazwa(string name) {
	nazwa = name;
}

string Wydawnictwo::getNazwa() {

	return nazwa;
}

void Wydawnictwo::show() {
	cout << "Nazwa dziela to: " << nazwa << " a jego numer ISBN to: " << numerISBN << endl;
}


Wydawnictwo& Wydawnictwo::operator++() {
	numerISBN++;
	return *this;
}