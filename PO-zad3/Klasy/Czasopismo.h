#pragma once
#include "Wydawnictwo.h"
class Czasopismo :
	public Wydawnictwo
{
private:
	bool czyKolorowe;
protected:
	string rokWydania;

public:
	Czasopismo();
	Czasopismo(bool, string, int, string);
	void setKolorowe(bool);
	bool getKolorowe();
	void setRokWydania(string);
	string getRokWydania();
	void show();
	void update();
};

