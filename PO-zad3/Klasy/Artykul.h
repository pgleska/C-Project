#pragma once
#include "Dziennik.h"
#include "Tygodnik.h"
#include <string>
using namespace std;

template <class T>
class Artykul
{
private:
	T pochodzenie;
protected:
	int dlugosc;
public:
	Artykul(T klasa, int length) {
		pochodzenie = klasa;
		dlugosc = length;
	}
	void setPochodzenie(T klasa) {
		pochodzenie = klasa;
	}
	void show() {
		cout << "Artykul pochodzi z: " << pochodzenie << " i jest dlugosci: " << dlugosc << endl;
	}

	void update() {

	}
};

template<>
class Artykul<Dziennik> :
	public Dziennik 
{
private:
	Dziennik* pochodzenie;
protected:
	int dlugosc;
public:
	Artykul(Dziennik* klasa, int length, string name, int isbn) {
		pochodzenie = klasa;
		dlugosc = length;
		setNazwa(name);
		setNumerISBN(isbn);
	}

	~Artykul() {
		delete &pochodzenie;
	}

	void setPochodzenie(Dziennik* d) {
		pochodzenie = d;
	}

	Dziennik* getPochodzenie() {
		return pochodzenie;
	}

	void setDlugosc(int i) {
		dlugosc = i;
	}

	int getDlugosc() {
		return dlugosc;
	}

	void show() {
		cout << "Nazwa artykulu to: " + getNazwa() + " a jego numer ISBN: " << getNumerISBN() << endl;
		cout << "Artykul pochodzi z: " << pochodzenie->getNazwa() << " i jest dlugosci: " << dlugosc << endl;
		cout << "Czasopismo, z ktorego pochodzi, zostalo wydane w dniu: " << pochodzenie->getDataWydania() << " i czy jest ciekawa: " << pochodzenie->getCiekawa() << endl;
		cout << "Czy czasopismo jest kolorowe: " << pochodzenie->getKolorowe() << " i zostalo wydane Anno Domini: " << pochodzenie->getRokWydania() << endl;
		cout << "Nazwa wydawnictwa pochodzenia to: " << pochodzenie->getNazwa() << " a jego numer ISBN to: " << pochodzenie->getNumerISBN() << endl;
	}

	string zapisDoPliku() {
		string wynik;
		string ciekawa, kolorowe;
		if (pochodzenie->getCiekawa()) {
			ciekawa = "T";
		}
		else {
			ciekawa = "N";
		}
		if (pochodzenie->getKolorowe()) {
			kolorowe = "T";
		}
		else {
			kolorowe = "N";
		}
		wynik = "D " + getNazwa() + " " + to_string(getNumerISBN()) + " " + to_string(dlugosc) + " " + pochodzenie->getDataWydania() + " " + ciekawa + " " + kolorowe + " " + pochodzenie->getRokWydania() + " " + to_string(pochodzenie->getNumerISBN()) + " " + pochodzenie->getNazwa();
		return wynik;
	}

	void update() {

	}
};

template<>
class Artykul<Tygodnik> :
	public Tygodnik
{
private:
	Tygodnik* pochodzenie;
protected:
	int dlugosc;
public:
	Artykul(Tygodnik* klasa, int length, string name, int isbn) {
		pochodzenie = klasa;
		dlugosc = length;
		setNazwa(name);
		setNumerISBN(isbn);
	}

	~Artykul() {
		delete &pochodzenie;
	}

	void setPochodzenie(Tygodnik* t) {
		pochodzenie = t;
	}

	Tygodnik* getPochodzenie() {
		return pochodzenie;
	}

	void setDlugosc(int i) {
		dlugosc = i;
	}

	int getDlugosc() {
		return dlugosc;
	}

	void show() {
		cout << "Nazwa artykulu to: " + getNazwa() + " a jego numer ISBN: " << getNumerISBN() << endl;
		cout << "Artykul pochodzi z: " << pochodzenie->getNazwa() << " i jest dlugosci: " << dlugosc << endl;
		cout << "Czasopismo, z ktorego pochodzi, zostalo wydane w tygodniu: " << pochodzenie->getTydzienWydania() << " i jest autora: " << pochodzenie->getAutor() << endl;
		cout << "Czy czasopismo jest kolorowe: " << pochodzenie->getKolorowe() << " i zostalo wydane Anno Domini: " << pochodzenie->getRokWydania() << endl;
		cout << "Nazwa wydawnictwa pochodzenia to: " << pochodzenie->getNazwa() << " a jego numer ISBN to: " << pochodzenie->getNumerISBN() << endl;
	}

	string zapisDoPliku() {
		string wynik;
		string kolorowe;
		if (pochodzenie->getKolorowe()) {
			kolorowe = "T";
		}
		else {
			kolorowe = "N";
		}
		wynik = "T " + getNazwa() + " " + to_string(getNumerISBN()) + " " + to_string(dlugosc) + " " + pochodzenie->getTydzienWydania() + " " + pochodzenie->getAutor() + " " + kolorowe + " " + pochodzenie->getRokWydania() + " " + to_string(pochodzenie->getNumerISBN()) + " " + pochodzenie->getNazwa();
		return wynik;
	}

	void update() {

	}
};