// Class_ShapeF.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle1.h"
#include"functions.h"


vector<Circle> myCircleObj;
vector<Square> mySquareObj;
vector<Rectangle1> myRectangleObj;
vector<Triangle> myTriangleObj;

 

int main()
{
	int a = 10; 
	string id_shape ; 
	while (a > 0)
	{
		cout << "\nChoose below option...\n";
		cout << "1. To Add  shape   " << endl;
		cout << "2. To Edit shape   " << endl;
		cout << "3. To Delete Shape" << endl;
		cout << "0. To exit " <<endl<<endl;

		cin >> a;

		switch (a)
		{
		case 1:
			addShape(); 
			export(); 
			break;
		case 2:
			cout<<"Enter the ID of the shape to edit =  " ;
			cin>> id_shape ; 
			editShape(id_shape) ; 
			export();
			break ;
		case 3:
			cout<<"Enter the ID of the shape to edit =  " ;
			cin>> id_shape ; 
			deleteShape(id_shape) ; 
			export();
			break;
		default:
			cout << "Enter Right choice....\n";

		}
	}

	return 0;
}






