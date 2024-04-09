#include "BigInt.h"
using namespace std;

BigInt::BigInt(){}

BigInt::BigInt(int nr) {
	this->n = nr;
	this->v = new int[this->n];
}

istream& operator>>(istream& in, BigInt& a) {

	for (int i = 0; i < a.n; i++) {
		in >> a.v[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const BigInt& b) {

	for (int i = b.n - 1; i >=0; i--) {
		out << b.v[i];
	}
	return out;
}

void BigInt::operator=(const BigInt& a) {

	this->n = a.n;
	this->v = new int[this->n];

	for (int i = 0; i < a.n; i++) {
		this->v[i] = a.v[i];
	}
}
void BigInt::inserare_f(int val)
{
	BigInt temp(this->n + 1);
	temp.v = new int[temp.n];
	for (int i = 0;i < this->n;i++)
	{
		temp.v[i] = this->v[i];
	}
	temp.v[this->n] = val;
	delete this->v;
	this->n = temp.n;
	this->v = new int[temp.n];
	for (int i = 0;i < this->n;i++)
	{
		 this->v[i] = temp.v[i];
	}
	delete temp.v;
}
BigInt BigInt::operator+(BigInt& a) {

	BigInt rez;
	rez.n = max(a.n, this->n);
	rez.v = new int[rez.n];
	int k=0;
	for (int i = 0;i < rez.n;i++)
	{
		if (i < this->n && i < a.n)
		{
			rez.v[i] = (a.v[i] + this->v[i] + k) % 10 ;
			k = (a.v[i] + this->v[i] + k) / 10;
		}
		else
		{
			if (i >= this->n)
			{
				rez.v[i] = (a.v[i] + k) % 10;
				k = (a.v[i] + k) / 10;
			}
			else
			{
				rez.v[i] = (this->v[i] + k) % 10;
				k = (this->v[i] + k) / 10;
			}
		}
	}
	if (k > 0)
		rez.inserare_f(k);
	return rez;
}


void BigInt::inmultire10() {

	BigInt temp;
	temp.n = this->n + 1;
	temp.v = new int[temp.n];

	for (int i = 1; i < temp.n; i++) {
		temp.v[i] = this->v[i-1];
	}
	temp.v[0] = 0;
	
	delete this->v;
	this->n = temp.n;
	this->v = new int[temp.n];

	for (int i = this->n-1; i >= 0; i--) {
		this->v[i] = temp.v[i];  
	
	}

	delete temp.v;
	
}

void BigInt::impartire10() {

	BigInt temp;
	temp.n = this->n -1;
	temp.v = new int[temp.n];

	for (int i = 1; i < this->n; i++) {
		temp.v[i-1] = this->v[i];
	}

	delete this->v;
	this->n = temp.n;
	this->v = new int[temp.n];

	for (int i = this->n - 1; i >= 0; i--) {
		this->v[i] = temp.v[i];
	}

	delete temp.v;
}
