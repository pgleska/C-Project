#pragma once
#include "Wydawnictwo.h"
class Ksiazka :
	public Wydawnictwo
{
private:
	string oprawa;
protected:
	string autor;

public:
	Ksiazka(string, string, int, string);
	void setOprawa(string);
	string getOprawa();
	void setAutor(string);
	string getAutor();
	void show();
	void update();
};

