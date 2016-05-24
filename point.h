#pragma once

#include <iostream>

class Point
{

	public:
		int x,y;		

		Point(int & _x,int &_y):x(_x),y(_y)
		{}

		void setX(const int & _x)
		{
			x=_x;
		}
		void setY(const int & _y)
		{
			y=_y;
		}
		int getX()
		{
			return x;
		}	
		int getY()
		{
			return y;
		}
};
