#pragma once
#include <iostream>

using namespace std;

class BigInt {

private:
	int* v;
	int n;
public:
	BigInt();
	BigInt(int nr);
	void inserare_f(int val);
	friend istream& operator>>(istream& in, BigInt& a);
	friend ostream& operator<<(ostream& out, const BigInt& b);
	void operator=(const BigInt& a);
	BigInt operator+(BigInt& a);
	void impartire10();
	void inmultire10();


};


/*
	tema:
	operatia de scadere intre doua numere mari;
	operatia de impartire la 10 a unui numar mare(stergerea ultimului element)
	operatia de inmultire cu 10 a unui numar mare(adaugarea unui 0 la final)


*/


