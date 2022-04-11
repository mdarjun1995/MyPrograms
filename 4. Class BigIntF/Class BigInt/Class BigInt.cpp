#include "stdafx.h" 
#include "BigInt.h" 


int main()
{
	
	BigInt a, b, x, y,z;
	
	cout << "Enter a first  big integer = " << endl;
	cin >> a;

	cout << "Enter a second big integer = " << endl;
	cin >> b;

	y = a - b;
	x = a + b;
	z = a * b; 
	
	cout << "\n      Addition  = "<< x ;
	cout << "\n  Substraction  = "<< y  ;
	cout << "\nMultiplication  = "<< z ;
	cout << endl;

	return 0;
}