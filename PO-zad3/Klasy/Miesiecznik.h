#pragma once
#include "Czasopismo.h"
class Miesiecznik :
	public Czasopismo
{
private:
	string miesiacWydania;
protected:
	string temat;
public:
	Miesiecznik(string, string, bool, string, int, string);
	void setMiesiacWydania(string);
	string getMiesiacWydania();
	void setTemat(string);
	string getTemat();
	void show();
	string zapisDoPliku();
	void update();
};

