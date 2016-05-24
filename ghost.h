
#include "movingobject.h"

class Ghost: public MovingObject
{ 
	private:
	char prevChar;
	int foodSize ;
  	public:
	
	Ghost() : MovingObject(142,222)
	{
		prevChar = ' ';
		foodSize =5;
	}
	void setPrevious(char _previous)
	{
	
		prevChar = _previous;
	}

	void clearpervious()
	{
		if(prevChar == '.')
		{
			setcolor(WHITE);
			circle(this->getX(),this->getY(),foodSize);
		}else if(prevChar == ' ')
		{
			setcolor(BLACK);
			setfillstyle(SOLID_FILL,BLACK);
			circle(getX(),getY(),19);
			floodfill(getX(),getY(),BLACK);
		}
	}

	void moveleft()
	{
		clearpervious();
	    setX(getX()-1) ;
		print();		
	}
	void moveright()
	{
		clearpervious();
		setX(getX()+1) ;
		print();
	}
	void moveup()
	{
//		printf("\nMOVE UPPPP  %d,%d",getX(),getY());
		clearpervious();
		setY(getY()-1) ;

		print();
	}

	void movedown()
	{
		clearpervious(); 

		setY(getY()+1) ;

		print();
	}
	void print()
	{
		setcolor(RED);
		setfillstyle(SOLID_FILL,RED);
		circle(getX(),getY(),10);
		floodfill(getX(),getY(),RED);
	}
};
