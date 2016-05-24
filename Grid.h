#ifndef GRID_H
#define GRID_H


#include<graphics.h>
#include"foodpoint.h"

class Grid
{
	private:
		const int WALL_WIDTH ;
		FoodPoint *foodArr[36]; //total food point are 36
		
		void printRectangle(int startX, int startY, int endX, int endY, int color = BLUE)
		{
			setcolor(color);
			setlinestyle(SOLID_LINE, 0, WALL_WIDTH);
			rectangle(startX,startY,endX,endY);	
		}
		
		void printLine(int startX, int startY, int endX, int endY, int color=BLUE)
		{
			setcolor(color);
			setlinestyle(SOLID_LINE, 0, WALL_WIDTH);
			line(startX,startY,endX,endY);
		}

	public:
		Grid():WALL_WIDTH(3)
		{
			int foodPointsIndex = 0;
			for(int f=255;f<=560;f+=38)
			{
				foodArr[foodPointsIndex++]=new FoodPoint(150,f);
				foodArr[foodPointsIndex++]=new FoodPoint(635,f-10);
				foodArr[foodPointsIndex++]=new FoodPoint(875,f-35);
				foodArr[foodPointsIndex++]=new FoodPoint(f-25,310);
			}
			
		
			foodArr[4]->setEaten(true);
		}

		void EatFood(int _x,int _y, int radius = 1)
		{
			for(int i = 0; i<36 ; i++)
			{
				if(foodArr[i]->getEaten()==false )
				{
				
					int xDiff = foodArr[i]->getX() - _x;
					int yDiff =foodArr[i]->getY() - _y;
					if(xDiff <0)
						xDiff*=-1;
					if(yDiff <0)
						yDiff*=-1;		
					if(xDiff <radius && yDiff < radius)
					{
						foodArr[i]->setEaten(true);
			
						break;
					}
				}
			}
			this->printFood();	
		}

		void printFood()
		{
		
			for(int i = 0; i<36 ; i++)
			{
		
				if(foodArr[i]->getEaten() == false)
				{
					foodArr[i]->print();
				}
			}
		}
		
		bool checkFoodOverlapping(int _x, int _y)
		{
			for(int i = 0; i<36 ; i++)
			{
				if(foodArr[i]->getEaten()== false && foodArr[i]->getX() == _x && foodArr[i]->getY() == _y)
				{
				
				}
			}
			return false;
		}
		
		void print()
		{
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5);
			outtextxy(365,100,"Pac man");
		    
			printRectangle(100,180,920,600);
			
		    //outside wall
		    for(int j=115;j<=905;j+=790)
		    {
		    	printLine(j,195,j,585);
		    }
			for(int k=195;k<=905;k+=390)
			{
				printLine(115,k,335,k);
				printLine(352,k,665,k);
				printLine(682,k,905,k);
			}
			for(int g=335;g<=350;g+=15)
			{
				printLine(g,195,g,275);
				printLine(g+330,195,g+330,275);
				printLine(g,500,g,585);
				printLine(g+330,500,g+330,585);				
			}
			//center design
			printRectangle(415,260,600,275);
			printRectangle(415,500,600,515);
			printRectangle(415,340,600,440);
			printRectangle(430,355,585,425);
			//hori center
			for(int d=340;d<=440;d+=85)
			{
				printRectangle(260,d,350,d+15);
				printRectangle(665,d,755,d+15);
			}
			//left l 
			for(int n=180;n<=840;n+=660)
			{
				printLine(n,260,n,355);
				printLine(n,425,n,515);
			}
			for(int b=195;b<=825;b+=630)
			{
				printLine(b,275,b,355);
				printLine(b,425,b,500);
			}
			for(int c=260;c<=515;c+=255)
			{
				printLine(180,c,270,c);
			}
			for(int z=260;z<=515;z+=255)
			{
				printLine(745,z,840,z);
			}
			printLine(195,275,270,275);
			printLine(195,500,270,500);
			printLine(745,275,825,275);
			printLine(745,500,825,500);	
			

			for(int i=0; i<36 ; i++)
			{
				foodArr[i]->print();
			}
			
		}

		char pointInformation(int req_x,int req_y, int radius=1)
		{
			
			//food point .
			//wall w
			//space 

			//most outer boundary
			if(req_x<=140 || req_x>=880 || req_y<=220|| req_y>=563)
			{
				//outer boundary is checked
				return 'w';
			}else if((req_y>=238 && req_y<302) && ((req_x > 156 && req_x<292 ) || (req_x > 388 && req_x<628) || (req_x > 716 && req_x<852) ))
			{
				return 'w';
			}else if((req_y>=478 && req_y<542) && ((req_x > 156 && req_x<292 ) || (req_x > 388 && req_x<628) || (req_x > 716 && req_x<852) ))
			{
				return 'w';
			}
			else if((req_y>=318 && req_y<=382) && ((req_x>=244 && req_x<=374) || (req_x>=414 && req_x<=606) || (req_x>=642 && req_x<=780)))
			{
				return 'w';
			}
			//hori rect
			else if((req_y>=398 && req_y<=462) && ((req_x>=244 && req_x<=374) || (req_x>=400 && req_x<=606) || (req_x>=642 && req_x<=780)))
			{
				return 'w';
			}
			//center rec left and right
			else if((req_x>=383&&req_x<=628) &&(req_y>=318 && req_y<=458))
			{
				return 'w';
			}
			
			else if ((req_x>=158 && req_x<=220) && ((req_y>=246 && req_y<=374) || (req_y>=398 && req_y<=542)))
			{
				return 'w';
			}
			else if ((req_x>=796 && req_x<=868) && ((req_y>=246 && req_y<=374) || (req_y>=398 && req_y<=542)))
			{
				return 'w';
			}
			else if((req_x>=308  && req_x<=372) && ((req_y<=302)||(req_y>=478)))
			{
				return 'w';
			}
			else if((req_x>=644  && req_x<=708) && ((req_y<=302)||(req_y>=486)))
			{
				return 'w';
			}
			for(int i = 0; i<36 ; i ++)
			{
				if(foodArr[i]->getEaten()==false )
				{
					int xDiff = foodArr[i]->getX() - req_x;
					int yDiff =foodArr[i]->getY() - req_y;
				  	if(xDiff <0)
						xDiff*=-1;
					if(yDiff <0)
						yDiff*=-1;
			
					if(xDiff <radius && yDiff < radius)
					{
					
						return '.';
					}
				}
			}
			return ' ';
		}
};

#endif
