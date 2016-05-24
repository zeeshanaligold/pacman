#pragma once

#include "movingobject.h"


class Pacman:public MovingObject
{
	
private: 

	const int STEP_SIZE;
	void clearPreviousPacman()
	{
		setcolor(BLACK);
        sector(x,y,0,360,21,21);
	}
public:
	Pacman():STEP_SIZE(8),MovingObject(302,390) //initial position of pacman
	{
	}

	void print()
	{
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);//color set
		sector(x,y,135,45,20,20);//circle set
	}
	
	void moveLeft()
	{
		clearPreviousPacman();
		x-=STEP_SIZE;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);//color set
		sector(x,y,225,135,20,20);
	}
	
	void moveRight()
	{
		clearPreviousPacman();
		x+=STEP_SIZE;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);//color set
		sector(x,y,45,315,20,20);              //sector function
	}
	
	void moveUp()
	{
		clearPreviousPacman();
		y-=STEP_SIZE;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);//color set
		sector(x,y,135,45,20,20);
	}
	
	void moveDown()
	{
		clearPreviousPacman();
		y+=STEP_SIZE;
		setcolor(YELLOW);
		setfillstyle(SOLID_FILL,YELLOW);//color set
		sector(x,y,315,225,20,20);//circle set
	}

};
