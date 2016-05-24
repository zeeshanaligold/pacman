#pragma once

#include "point.h"


class MovingObject:public Point
{
	public:
	MovingObject(int initialX,int initialY):Point(initialX,initialY)
	{
	}

};

