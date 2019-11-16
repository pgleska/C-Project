#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Klasy/Wydawnictwo.h"
#include "Klasy/Ksiazka.h"
#include "Klasy/Czasopismo.h"
#include "Klasy/Popularnonaukowa.h"
#include "Klasy/Beletrystyka.h"
#include "Klasy/Miesiecznik.h"
#include "Klasy/Tygodnik.h"
#include "Klasy/Dziennik.h"
#include "Klasy/Artykul.h"
#include "Klasy/Wezel.h"
using namespace std;

ostream& operator<< (ostream& outs, Wydawnictwo& obj) {
	return outs << obj.getNazwa();
}

string pierwszeSlowo(string temp) {
	string pierwsze = "";
	for (string::size_type i = 0; i < temp.size(); i++) {
		if (temp[i] != ' ') {
			pierwsze += temp[i];
		}
		else {
			break;
		}
	}
	return pierwsze;
}

string resztaSlow(string temp) {
	bool pierwsze = true;
	string wynik = "";
	for (string::size_type i = 0; i < temp.size(); i++) {
		if (pierwsze && (temp[i] == ' ')) {
			pierwsze = false;
		}
		else if (!pierwsze){
			wynik += temp[i];
		}
	}
	wynik += '\n';
	return wynik;
}

vector<string> arguments(string src) {
	string temp = "";
	vector<string> wynik;
	for (string::size_type i = 0; i < src.size(); i++) {
		if ((src[i] != ' ') && (src[i] != '\n')) {
			temp += src[i];
		}
		else {
			wynik.push_back(temp);
			temp = "";
		}
	}
	return wynik;
}

int main() {
	string komenda, plik, temp, pierwSlowo, args;
	int typ;
	vector<string> argumenty;

	Wezel W1(1, "Wydawnictwo");
	Wezel W2(2, "Ksiazka");
	Wezel W3(3, "Czasopismo");
	Wezel W4(4, "Dziennik");
	Wezel W5(5, "Tygodnik");
	Wezel W6(6, "Popularnonaukowa");
	Wezel W7(7, "Beletrystyka");
	Wezel W8(8, "Miesiecznik");
	Wezel W9(9, "Artykul");

	W1.setPodWezly(&W2);
	W1.setPodWezly(&W3);
	W2.setPodWezly(&W6);
	W2.setPodWezly(&W7);
	W3.setPodWezly(&W8);
	W3.setPodWezly(&W4);
	W3.setPodWezly(&W5);
	W4.setPodWezly(&W9);
	W5.setPodWezly(&W9);

	map<string, Wezel*> mapa;
	mapa.insert(pair<string, Wezel*>("Wydawnictwo", &W1));
	mapa.insert(pair<string, Wezel*>("Ksiazka", &W2));
	mapa.insert(pair<string, Wezel*>("Czasopismo", &W3));
	mapa.insert(pair<string, Wezel*>("Dziennik", &W4));
	mapa.insert(pair<string, Wezel*>("Tygodnik", &W5));
	mapa.insert(pair<string, Wezel*>("Popularnonaukowa", &W6));
	mapa.insert(pair<string, Wezel*>("Beletrystyka", &W7));
	mapa.insert(pair<string, Wezel*>("Miesiecznik", &W8));
	mapa.insert(pair<string, Wezel*>("Artykul", &W9));
	
	Wezel* biezacyWezel = &W1;

	std::cout << "Jestes w wezle " << biezacyWezel->getNazwaWezla() << endl;

	while (true) {
		cin >> komenda;
		if (komenda == "EXIT") {
			break;
		}
		else if (komenda == "MO") {
			biezacyWezel->nowyObiekt("");
		}
		else if (komenda == "CD") {
			std::cout << "Podaj nazwe wezla (Wydawnictwo, Ksiazka, Czasopismo, Dziennik, Tygodnik, Popularnonaukowa, Beletrystyka, Miesiecznik, Artykul" << endl;
			cin >> komenda;
			if (mapa.find(komenda) != mapa.end()) {
				biezacyWezel = mapa[komenda];
				std::cout << "Jestes w wezle " << biezacyWezel->getNazwaWezla() << endl;
			}
			else {
				std::cout << "Podano bledna nazwe wezla" << endl;
			}
		}
		else if (komenda == "DO") {
			biezacyWezel->usunObiekt();
		}
		else if (komenda == "DIR") {
			biezacyWezel->pokazListe(0);
		}
		else if (komenda == "TREE") {
			ifstream wejscie("txt/schemat.txt");
			while (getline(wejscie, temp)) {
				cout << temp << endl;
			}
			wejscie.close();
		}
		else if (komenda == "SHOW") {
			biezacyWezel->pokazObiekt();
		}
		else if (komenda == "MDO") {
			biezacyWezel->modyfikujObiekt();
		}
		else if (komenda == "SAVE") {
			std::cout << "Podaj nazwe pliku do zapisu" << endl;
			cin >> plik;
			ofstream wyjscie("txt/" + plik);
			wyjscie << W1.zapisPlik();
			wyjscie.close();
			std::cout << "Zapis zakonczony" << endl;
		}
		else if (komenda == "READ") {
			std::cout << "Podaj nazwe pliku do wczytania" << endl;
			cin >> plik;
			ifstream wejscie("txt/" + plik);
			while (getline(wejscie, temp) ) {
				pierwSlowo = pierwszeSlowo(temp);
				args = resztaSlow(temp);
				argumenty = arguments(args);
				mapa.at(pierwSlowo)->wczytajObiekt(argumenty);
			}
			wejscie.close();
			std::cout << "Zakonczono wczytywanie" << endl;
		}
		else {
			std::cout << "Nieznana komenda" << endl;
		}
	}
	
	std::cout << "Do zobaczenia wkrotce" << endl;

	return 0;
}