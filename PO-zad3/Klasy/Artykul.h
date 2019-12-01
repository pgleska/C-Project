#pragma once
#include "Dziennik.h"
#include "Tygodnik.h"
#include <string>
#include <typeinfo>
using namespace std;

template <class T>
class Artykul : public Czasopismo
{
private:
	T* pochodzenie;
protected:
	int dlugosc;
public:
	Artykul(T* klasa, int length, string name, int isbn) {
		pochodzenie = klasa;
		dlugosc = length;
		setNazwa(name);
		setNumerISBN(isbn);
	}

	~Artykul() {
		delete& pochodzenie;
	}

	void setPochodzenie(T* klasa) {
		pochodzenie = klasa;
	}

	T* getPochodzenie() {
		return pochodzenie;
	}
		
	void setDlugosc(int i) {
		dlugosc = i;
	}
		
	int getDlugosc() {
		return dlugosc;
	}

	void show() {
		if (typeid(*pochodzenie) == typeid(Dziennik)) {
			Dziennik* ptr = dynamic_cast<Dziennik*>(pochodzenie);
			cout << "Nazwa artykulu to: " + getNazwa() + " a jego numer ISBN: " << getNumerISBN() << endl;
			cout << "Artykul pochodzi z: " << ptr->getNazwa() << " i jest dlugosci: " << dlugosc << endl;
			cout << "Czasopismo, z ktorego pochodzi, zostalo wydane w dniu: " << ptr->getDataWydania() << " i czy jest ciekawa: " << ptr->getCiekawa() << endl;
			cout << "Czy czasopismo jest kolorowe: " << ptr->getKolorowe() << " i zostalo wydane Anno Domini: " << ptr->getRokWydania() << endl;
			cout << "Nazwa wydawnictwa pochodzenia to: " << ptr->getNazwa() << " a jego numer ISBN to: " << ptr->getNumerISBN() << endl;
		}
		else if (typeid(*pochodzenie) == typeid(Tygodnik)) {
			Tygodnik* ptr = dynamic_cast<Tygodnik*>(pochodzenie);
			cout << "Nazwa artykulu to: " + getNazwa() + " a jego numer ISBN: " << getNumerISBN() << endl;
			cout << "Artykul pochodzi z: " << ptr->getNazwa() << " i jest dlugosci: " << dlugosc << endl;
			cout << "Czasopismo, z ktorego pochodzi, zostalo wydane w tygodniu: " << ptr->getTydzienWydania() << " i jest autora: " << ptr->getAutor() << endl;
			cout << "Czy czasopismo jest kolorowe: " << ptr->getKolorowe() << " i zostalo wydane Anno Domini: " << ptr->getRokWydania() << endl;
			cout << "Nazwa wydawnictwa pochodzenia to: " << ptr->getNazwa() << " a jego numer ISBN to: " << ptr->getNumerISBN() << endl;
		}
	}
 
	void update() {
		string param;
		if (typeid(*pochodzenie) == typeid(Dziennik)) {
			cout << "Podajparametry oddzielone spacjami (nazwa artykulu, numer ISBN artykulu, dlugosc, data wydania, czy jest to ciekawe [T/N], czy jest to kolorowe czasopismo [T/N], rok wydania, numerISBN, nazwe pochodzenia), jesli nie chcesz edytowac podaj 0" << endl;
			Dziennik* ptr = dynamic_cast<Dziennik*>(pochodzenie);
			cin >> param;
			if (param != "0") {
				setNazwa(param);
			}
			cin >> param;
			if (param != "0") {
				setNumerISBN(stoi(param));
			}
			cin >> param;
			if (param != "0") {
				setDlugosc(stoi(param));
			}
			cin >> param;
			if (param != "0") {
				ptr->setDataWydania(param);
			}
			cin >> param;
			if (param != "0") {
				if (param == "T") {
					ptr->setCiekawa(true);
				}
				else {
					ptr->setCiekawa(false);
				}
			}
			cin >> param;
			if (param != "0") {
				if (param == "T") {
					ptr->setKolorowe(true);
				}
				else {
					ptr->setKolorowe(false);
				}
			}
			cin >> param;
			if (param != "0") {
				ptr->setRokWydania(param);
			}
			cin >> param;
			if (param != "0") {
				ptr->setNumerISBN(stoi(param));

			}
			cin >> param;
			if (param != "0") {
				ptr->setNazwa(param);
			}
		} 
		else if (typeid(*pochodzenie) == typeid(Tygodnik)) {
			cout << "Podajparametry oddzielone spacjami (nazwa artykulu, numer ISBN artykulu, dlugosc, tydzien wydania, autor, czy jest to kolorowe czasopismo [T/N], rok wydania, numerISBN, nazwe pochodzenia), jesli nie chcesz edytowac podaj 0" << endl;
			Tygodnik* ptr = dynamic_cast<Tygodnik*>(pochodzenie);
			cin >> param;
			if (param != "0") {
				setNazwa(param);
			}
			cin >> param;
			if (param != "0") {
				setNumerISBN(stoi(param));
			}
			cin >> param;
			if (param != "0") {
				setDlugosc(stoi(param));
			}
			cin >> param;
			if (param != "0") {
				ptr->setTydzienWydania(param);
			}
			cin >> param;
			if (param != "0") {
				ptr->setAutor(param);
			}
			cin >> param;
			if (param != "0") {
				if (param == "T") {
					ptr->setKolorowe(true);
				}
				else {
					ptr->setKolorowe(false);
				}
			}
			cin >> param;
			if (param != "0") {
				ptr->setRokWydania(param);
			}
			cin >> param;
			if (param != "0") {
				ptr->setNumerISBN(stoi(param));

			}
			cin >> param;
			if (param != "0") {
				ptr->setNazwa(param);
			}
		}
	}

	string zapisDoPliku() {
		string wynik;
		string ciekawa, kolorowe;
		if (typeid(*pochodzenie) == typeid(Dziennik)) {
			Dziennik* ptr = dynamic_cast<Dziennik*>(pochodzenie);
			if (ptr->getCiekawa()) {
				ciekawa = "T";
			}
			else {
				ciekawa = "N";
			}
			if (ptr->getKolorowe()) {
				kolorowe = "T";
			}
			else {
				kolorowe = "N";
			}
			wynik = "D " + getNazwa() + " " + to_string(getNumerISBN()) + " " + to_string(dlugosc) + " " + ptr->getDataWydania() + " " + ciekawa + " " + kolorowe + " " + ptr->getRokWydania() + " " + to_string(ptr->getNumerISBN()) + " " + ptr->getNazwa();
		}
		else if (typeid(*pochodzenie) == typeid(Tygodnik)) {
			Tygodnik* ptr = dynamic_cast<Tygodnik*>(pochodzenie);
			if (ptr->getKolorowe()) {
				kolorowe = "T";
			}
			else {
				kolorowe = "N";
			}
			wynik = "T " + getNazwa() + " " + to_string(getNumerISBN()) + " " + to_string(dlugosc) + " " + ptr->getTydzienWydania() + " " + ptr->getAutor() + " " + kolorowe + " " + ptr->getRokWydania() + " " + to_string(ptr->getNumerISBN()) + " " + ptr->getNazwa();
		}
		
		return wynik;
	}
};