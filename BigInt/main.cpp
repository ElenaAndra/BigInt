#include <iostream>
#include "BigInt.h"

using namespace std;

int main()
{
	BigInt a(4),b(2);
	cin >> a>>b;
	
	a = a + b;
	cout << a;
	
	
}

