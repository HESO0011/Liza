#pragma once
#include<numeric>
#include <iostream>
using namespace std;
class Cfrac
{
public:
	Cfrac(int p, int q);
	Cfrac();
	~Cfrac();
	int get_p();
	int get_q();
	double fraction_in_number();
	Cfrac simplifying();
	void inputPQ();
	Cfrac operator +(const Cfrac& other);
	Cfrac operator -(const Cfrac& other);
	Cfrac operator *(const Cfrac& other);
	Cfrac operator /(const Cfrac& other);

private:
	int p;
	int q;
};
