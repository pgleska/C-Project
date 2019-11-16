#pragma once
#include "Ksiazka.h"
class Popularnonaukowa :
	public Ksiazka
{
private:
	string temat;
protected:
	bool czyCiekawa;
public: 
	Popularnonaukowa(string, bool, string, string, int, string);
	void setTemat(string);
	string getTemat();
	void setCiekawa(bool);
	bool getCiekawa();
	void show();
	string zapisDoPliku();
	void update();
};

