#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include "Wydawnictwo.h"
#include "Ksiazka.h"
#include "Czasopismo.h"
#include "Popularnonaukowa.h"
#include "Beletrystyka.h"
#include "Miesiecznik.h"
#include "Tygodnik.h"
#include "Dziennik.h"
#include "Artykul.h"
using namespace std;

class Wezel
{
private:
	map<string, Wydawnictwo*> obiekty;
	vector<Wezel*> podwezly;
	int id;
	bool czyBiezacy;
	string nazwaWezla;

public:
	Wezel();
	Wezel(int, string);
	int getId();
	void setBiezacy(bool);
	bool getBiezacy();
	void setNazwaWezla(string);
	string getNazwaWezla();
	void setPodWezly(Wezel*);
	void nowyObiekt(string);
	void usunObiekt();
	void pokazListe(int);
	void modyfikujObiekt();
	bool sprawdzCzyIstnieje(string);
	void pokazObiekt();
	string zapisPlik();
	void wczytajObiekt(vector<string>);
};