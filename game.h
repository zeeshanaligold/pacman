#pragma once

#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<fstream>
#include<dos.h>
#include<stdio.h>
#include "ghost.h"
#include "pacman.h"
#include "menu.h"
#include "grid.h"
using namespace std;
class Game
{
	
		
	public:
		Game(){}
	
		void start()
		{
			Menu menu(500,200);
			menu.animation();
			cleardevice();
		
			menu.print();
			menu.select();
			//user has selected to play game by pressing S
			
			cleardevice();

			Grid grid;
			grid.print();

			Pacman pacman;
			pacman.print();

			char ch;
			Ghost ghost;
			ghost.print();
			
			int count = 0;
			int score = 0;
			while(true)
			{	
				if(ghost.getX() == pacman.getX() && ghost.getY()==pacman.getY())
				{
					PlaySound("pacman_death.wav",NULL, SND_ASYNC);
					cleardevice();
					outtextxy(300,300,"Game over");
					break;
				}
				else if(score == 35)
				{
					cleardevice();
					outtextxy(300,300,"You Win!!!");
					break;
				}
				count++;
				if(count >= 600000)
				{	
					bool isGhostMoved = false;
					count = 0;
					char temp;
					if(ghost.getX()>pacman.getX())
					{
						temp = grid.pointInformation(ghost.getX()-1,ghost.getY(),5);
						if(temp !='w') 
						{
							grid.printFood();
							ghost.setPrevious(temp);							
							ghost.moveleft();
							isGhostMoved = true;
						}
					}
			        if(isGhostMoved==false && ghost.getX()<pacman.getX())
					{
						temp = grid.pointInformation(ghost.getX()+1,ghost.getY(),5 );
						if( temp !='w')
						{
							grid.printFood();
							ghost.setPrevious(temp);
							ghost.moveright();
							isGhostMoved = true;
						}
					}
					if(isGhostMoved== false && ghost.getY()<pacman.getY())
					{
						temp = grid.pointInformation(ghost.getX(),ghost.getY()+1 ,5);
						if( temp !='w')
						{
							grid.printFood();
							ghost.setPrevious(temp);							
							isGhostMoved = true;
							ghost.movedown();
						}
					}
					if(isGhostMoved== false && ghost.getY()>pacman.getY())
					{
						temp = grid.pointInformation(ghost.getX(),ghost.getY()-1,5) ;
						if(temp !='w')
						{
							grid.printFood();
							ghost.setPrevious(temp);
							isGhostMoved = true;						
							ghost.moveup();
						}
						
					}
				}
			
			
				if(kbhit())
			    {
				    
					ch=getch();
					char temp;
					if(ch==77)                           //move right
					{
						temp = grid.pointInformation(pacman.getX() + 8, pacman.getY(), 10);
						if(temp != 'w')
						{
							pacman.moveRight();

							if(temp == '.')
							{
								PlaySound("pacman_chomp.wav",NULL, SND_ASYNC);
								grid.EatFood(pacman.getX(),pacman.getY(), 10);
								score++;
							}
						}
					}
					else if(ch == 75) //move left
					{
						temp = grid.pointInformation(pacman.getX() - 8, pacman.getY(), 10);
					
						if(temp != 'w')
						{
							pacman.moveLeft();
							if(temp == '.')
							{
								PlaySound("pacman_chomp.wav",NULL, SND_ASYNC);
								grid.EatFood(pacman.getX(),pacman.getY(), 10);
								score++;	
							}
						}

					}
					else if(ch == 80) // downward
					{
						temp = grid.pointInformation(pacman.getX(), pacman.getY() + 8, 10);
						if(temp != 'w')
						{
							pacman.moveDown();

							if(temp == '.')
							{
								PlaySound("pacman_chomp.wav",NULL, SND_ASYNC);
								grid.EatFood(pacman.getX(),pacman.getY(), 10);
								score++;
							}

						}
						
					}
					else if(ch == 72) // up
					{
						temp = grid.pointInformation(pacman.getX() , pacman.getY()-8, 10);
						if(temp != 'w')
						{
							if(temp == '.')
							{
								PlaySound("pacman_chomp.wav",NULL, SND_ASYNC);
								grid.EatFood(pacman.getX(),pacman.getY()-8, 10);
								score++;	
							}
							pacman.moveUp();
						} 
					}
					char *t;   
					setcolor(GREEN);
					sprintf(t,"%d",score); 
					outtextxy(560,620,"Score: ");
			        outtextxy(830,620,t);   
					
				}		
			}
			//for saving score in file player.text 
			ofstream scor;
			scor.open("Player.text",ios::app);
			scor<<"Score : "<<score<<endl;
			scor<<"-------------------------------------"<<endl;
			scor.close();
		}
};
