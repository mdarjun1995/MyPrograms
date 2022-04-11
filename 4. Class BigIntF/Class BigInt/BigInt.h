#pragma once
#include "StdAfx.h"
#include<iostream>
#include<string>

using namespace std ; 


class BigInt
{

	string m_number;

public:

	BigInt() ; // default constructor
	
	BigInt(string number) ; // constructor
	
	BigInt operator+(BigInt& const secondNumber) ; 
	BigInt operator-(BigInt& const secondNumber) ; 
	BigInt operator*(BigInt& const secondNumber) ; 
	BigInt operator=(string someNumber) ; 
	
	friend istream& operator >>(istream& is, BigInt& carryInt) ;
	

	friend ostream& operator <<(ostream& out, BigInt& carryInt) ;

};

