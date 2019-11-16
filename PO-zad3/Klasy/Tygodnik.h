#pragma once
#include "Czasopismo.h"
class Tygodnik :
	public Czasopismo
{
private:
	string tydzienWydania;
protected:
	string autor;
public:
	Tygodnik();
	Tygodnik(string, string, bool, string, int, string);
	void setTydzienWydania(string);
	string getTydzienWydania();
	void setAutor(string);
	string getAutor();
	void show();
	string zapisDoPliku();
	void update();
};

