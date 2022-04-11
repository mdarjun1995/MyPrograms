#include "StdAfx.h"
#include "BigInt.h"
#include<string>



BigInt:: BigInt() // constructor
	{
		m_number = "";
	}

BigInt::BigInt(string number) // constructor
	{
		m_number = number;
	}

	BigInt BigInt::operator+(BigInt& const secondNumber)
	{
		BigInt addnResult;

		int length_FirstNumber;
		int length_secondNmber;
		int maxLength;
		string carryInstring;
		int carry = 0;


		length_FirstNumber = m_number.length();
		length_secondNmber = secondNumber.m_number.length();

		maxLength = max(length_FirstNumber, length_secondNmber);

		if (length_FirstNumber < length_secondNmber)
		{
			swap(m_number, secondNumber.m_number);
		}

		for (int i = 0; i < abs(length_FirstNumber - length_secondNmber); i++)
		{
			secondNumber.m_number = "0" + secondNumber.m_number;
		}

		int* tempArray = new int[maxLength];

		for (int i = maxLength - 1; i >= 0; i--)
		{

			tempArray[i] = (m_number[i] - '0') + (secondNumber.m_number[i] - '0') + carry;
			carry = tempArray[i] / 10;
			tempArray[i] = tempArray[i] % 10;

		}

		carryInstring = carry + '0';

		for (int j = 0; j < maxLength; j++)
		{
			addnResult.m_number.push_back(tempArray[j] + '0');
		}


		return addnResult;
	}

	BigInt BigInt:: operator-(BigInt& const secondNumber)
	{
		BigInt subResult;
		string temp;
		int length_FirstNumber;
		int length_secondNmber;
		int maxLength;
		string carryInstring;
		int x = 0, carry = 0;

		 string FirstNum, SecondNum ;

		 FirstNum =   m_number ; 
		 SecondNum = secondNumber.m_number ; 


		length_FirstNumber = FirstNum.length();
		length_secondNmber =  SecondNum.length() ; 

		maxLength = max(length_FirstNumber, length_secondNmber);

		if (length_FirstNumber < length_secondNmber)
		{
			swap(FirstNum, SecondNum);
			x = 1 ; 
		}

		for (int i = 0; i < abs(length_FirstNumber - length_secondNmber); i++)
		{
			SecondNum = "0" + SecondNum;
		}

		for (int i = 0; i < maxLength; i++)
		{

			if ((FirstNum[i] - '0') == (SecondNum[i] - '0'))
			{

				continue;

			}

			else if ((FirstNum[i] - '0') > (SecondNum[i] - '0'))
			{
				break;
			}
			else
			{
				swap(FirstNum, SecondNum);
				x = 1;
			}
		}

		int* tempArray = new int[maxLength];

		for (int i = maxLength - 1; i >= 0; i--)
		{
			if (FirstNum[i] - SecondNum[i] < 0)
			{
				tempArray[i] = (10 + (FirstNum[i] - '0') - carry) - (SecondNum[i] - '0');
				carry = 1;
				tempArray[i] = tempArray[i] % 10;
			}
			else
			{
				tempArray[i] = ((FirstNum[i] - '0') - carry) - (SecondNum[i] - '0');

				if (tempArray[i] < 0)
				{
					tempArray[i] = (10 + (FirstNum[i] - '0') - carry) - (SecondNum[i] - '0');
					carry = 1;
				}
				else
					carry = 0;
			}
		}


		for (int j = 0; j < maxLength; j++)
		{

			temp.push_back(tempArray[j] + '0');

		}

		int catchIndex ; 

		for(int i = 0 ; i < temp.length() ; i++)
		{
			if(temp[i] == '0' )
				continue ; 
			else 
				catchIndex = i ; 
				break ; 
		}
		for(int j = catchIndex ; j < temp.length() ; j++)
		{
			subResult.m_number.push_back(temp[j]) ; 
		}


		if(x==1)
		{
			subResult.m_number = "-" + subResult.m_number ; 
		}

		
		return subResult;
	}

	BigInt BigInt::operator*(BigInt& const secondNumber)
	{
		int mult, c = 0;
		int length_firstNumber, length_secondNumber, counter = 0;
		char temp, carry;
		
		length_firstNumber = m_number.length();
		length_secondNumber = secondNumber.m_number.length();

		BigInt multesult , str1 , str2 ;

		if (length_firstNumber < length_secondNumber)
		{
			swap(m_number, secondNumber.m_number);
		}

		for (int j = length_secondNumber - 1; j >= 0; j--)  // j belongs to second number 
		{
			for (int i = length_firstNumber - 1; i >= 0; i--) // i belongs to first number 
			{
				mult = (secondNumber.m_number[j] - '0') * (m_number[i] - '0') + c;
				c = mult / 10;
				mult = mult % 10;
				temp = mult + '0';
				str1.m_number = temp + str1.m_number;
			}

			carry = c + '0';
			str1.m_number = carry + str1.m_number + std::string(counter, '0');
			str2 = str1 + str2 ;

			str1.m_number.clear();

			counter++;
		}

		int catchIndex ; 

		for(int i = 0 ; i < str2.m_number.length() ; i++)
		{
			if(str2.m_number[i] == '0' )
				continue ; 
			else 
				catchIndex = i ; 
				break ; 
		}
 
		for(int j = catchIndex ; j < str2.m_number.length() ; j++)
		{
			multesult.m_number.push_back(str2.m_number[j]) ; 
		}

		return multesult ; //return str2;
		

	}

	BigInt BigInt::operator=(string someNumber)
	{
		m_number = someNumber;
		return *this ;
	}

	istream& operator >>(istream& is, BigInt& _number)
	{

		is >> _number.m_number;
		
		return is;

	}

	ostream& operator <<(ostream& out, BigInt& carryInt)
	{

		out << carryInt.m_number;

		return out;

	}