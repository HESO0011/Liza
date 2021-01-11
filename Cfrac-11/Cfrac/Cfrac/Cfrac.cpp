#include "Cfrac.h"

Cfrac::Cfrac(int p, int q)
{
	this->p = p;
	this->q = q;
}

Cfrac::Cfrac()
{
	this->p = 0;
	this->q = 1;
}

Cfrac::~Cfrac()
{
}

int Cfrac::get_p()
{
	return p;
}

int Cfrac::get_q()
{
	return q;
}

double Cfrac::fraction_in_number()
{
	return static_cast<double>(p) / q;
}

Cfrac Cfrac::simplifying()
{
	return Cfrac((p / gcd(p, q)), (q / gcd(p, q)));
}

void Cfrac::inputPQ()
{
	cout << "\nEnter P->";
	cin >> this->p;
	while (true)
	{
		cout << "\nEnter Q->";
		cin >> this->q;
		if (this->q != 0)
			break;
		else 
		cout << "\nError!! The denominator is 0. Enter again\n";////

	}
}

Cfrac Cfrac::operator+(const Cfrac& other)
{
	int  Nok = this->q * other.q / gcd(this->q, other.q);

	return Cfrac(((this->p * (Nok / this->q)) + (other.p * (Nok / other.q))), Nok);
}

Cfrac Cfrac::operator-(const Cfrac& other)
{
	int  Nok = this->q * other.q / gcd(this->q, other.q);

	return Cfrac(((this->p * (Nok / this->q)) - (other.p * (Nok / other.q))), Nok);
}

Cfrac Cfrac::operator*(const Cfrac& other)
{
	return Cfrac((this->p * other.p), (this->q * other.q));
}

Cfrac Cfrac::operator/(const Cfrac& other)
{
	if (other.p == 0)
		throw exception("Error!!\n Division by zero no.");

	return Cfrac((this->p * other.q), (this->q * other.p));
}
