#pragma once
#include<string>
#include"shape.h"


using namespace std; 

class Circle : public Shape
{
	float m_rad;
	string m_uniqueID   ;

public:
	void Set_radius(float radius) ;
	
	void set_id(string id) ;
	
	float Area() ;
	
	float Perimeter() ;
	
	friend void export();
	friend void editShape(string) ;
	friend void deleteShape(string const ) ;

};
