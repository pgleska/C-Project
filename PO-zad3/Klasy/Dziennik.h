#pragma once
#include "Czasopismo.h"
class Dziennik :
	public Czasopismo
{
private:
	string dataWydania;
protected:
	bool czyCiekawa;
public:
	Dziennik();
	Dziennik(string, bool, bool, string, int, string);
	void setDataWydania(string);
	string getDataWydania();
	void setCiekawa(bool);
	bool getCiekawa();
	void show();
	string zapisDoPliku();
	void update();
};

