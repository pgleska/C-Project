#pragma once
#include "Ksiazka.h"
class Beletrystyka :
	public Ksiazka
{
private:
	string wojna;
protected:
	string lata;
public:
	Beletrystyka(string, string, string, string, int, string);
	void setWojna(string);
	string getWojna();
	void setLata(string);
	string getLata();
	void show();
	string zapisDoPliku();
	void update();
};

