#include"stdafx.h"
#include "Circle.h"


void Circle:: Set_radius(float radius)
	{
		m_rad = radius;
		m_type = "  Circle   "; 
	}

void Circle:: set_id(string id)
	{

		m_uniqueID = id; 

	}


float Circle:: Area()
	{
		m_area = 3.14 * m_rad * m_rad;
		return m_area;
	}

float Circle:: Perimeter()
	{
		m_perimeter = 2 * 3.14 * m_rad;
		return  m_perimeter;
	}
