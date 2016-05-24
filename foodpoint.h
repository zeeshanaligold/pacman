#include "point.h"

#include<graphics.h>


class FoodPoint: public Point
{
	int foodSize;
	bool isEaten; 
	
	
	public:
	FoodPoint(int _x, int _y):Point(_x,_y),foodSize(2),isEaten(false)
	{		
	}
	
	void print()
	{
		setcolor(WHITE);
		circle(getX(),getY(),foodSize);
	}
	
	void setEaten(bool temp)
	{	
		isEaten = temp;
	}
	
	bool getEaten()
	{
		return isEaten;
	}
};



