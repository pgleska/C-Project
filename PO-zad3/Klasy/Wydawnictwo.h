#pragma once
#include <string>
using namespace std;

class Wydawnictwo
{
private:
	int numerISBN;
protected:
	string nazwa;

public:
	Wydawnictwo();
	Wydawnictwo(int, string);
	~Wydawnictwo();
	void setNumerISBN(int);
	int getNumerISBN();
	void setNazwa(string);
	string getNazwa();
	virtual void show();
	Wydawnictwo& operator++();
	virtual string zapisDoPliku() = 0;
	virtual void update() = 0;
};

