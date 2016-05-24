#pragma once

#include<iostream>
#include<fstream>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
using namespace std;

class Menu
{
	private:
		int x,y;
		char s[15];
	public:
		Menu(int _x,int _y){x=_x,y=_y;}   //parmetrized constracter of menu class
		~Menu(){}                                     //Distracter

		void print()											//print function uses for print the menu
		{
			setcolor(1);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5); 
			cleardevice();
			setcolor(BLUE);
			outtextxy(x,y,"Menu");
			outtextxy(x,y+40,"S: Start Game");
			outtextxy(x,y+80,"H: Help");
			outtextxy(x,y+120,"A: About");

		}
		void animation()				//this member function uses for animation
		{
			for(int l=370;l<=900;l+=18)		//food
			{
				setcolor(WHITE);
				circle(l,300,5);
				floodfill(l,300,WHITE);
			}
			PlaySound("pacman_ringtone.wav",NULL, SND_ASYNC);
			delay(0);
			for(int i=365;i<=900;i+=8)		//pacman
			{
				setcolor(YELLOW);
				setfillstyle(SOLID_FILL, YELLOW);
				sector(i,300,45,315,20,20);              //sector function
				delay(30);
				setfillstyle(SOLID_FILL, YELLOW);
				pieslice(i,300,22,45,20);              //sector function
				delay(30);
				setfillstyle(SOLID_FILL, YELLOW);
				pieslice(i,300,315,337,20);              //sector function
				delay(30);
				setfillstyle(SOLID_FILL, YELLOW);
				pieslice(i,300,337,22,20);              //sector function
				delay(5);
				setcolor(BLACK);
				sector(i,300,0,360,21,21);
			}
			//for loding and input user name
			{																
				
				settextstyle(SOLID_FILL,0,5);
				setcolor(GREEN);
				outtextxy(500,200,"Pacman Game");
				settextstyle(SOLID_FILL,HORIZ_DIR,1);
				outtextxy(500,300,"Enter your name : ");
				rectangle(500,320,850,350);
				cout<<"Enter your name : ";
				
				ofstream player;		//file writting
				player.open("Player.text",ios::app);
				cin.getline(s,15);
				player<<"Name : "<<s<<endl;
				player.close();
				
				settextstyle(SOLID_FILL,HORIZ_DIR,2);
				outtextxy(510,325,s);
				getch();
				rectangle(550,400, 840,430);
				for(int i=570;i<=820;i+=8)
				{
					setlinestyle(SOLID_FILL,0,20);
					line(570,415,i,415);
					delay(400);
					
				}
			}
			
			cleardevice();
			delay(2500);
			setcolor(WHITE);
			settextstyle(DEFAULT_FONT,HORIZ_DIR,5); 
			outtextxy(x,y,"Ready for Game!");
			delay(1000);
		}
		
	    void select()			//uses for select the menue
	    {
	    	int ch;
			while(true)								//infinte loop
			{
				
				if(kbhit())
				{
					ch=getch();
					if(ch==115) //S
					{
						//go back to main and start game
						return ;
					}
					else if(ch==97) //a
					{
						cleardevice();
						settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
						outtextxy(400,235,"About This Game:");
						setcolor(WHITE);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
						outtextxy(400,300,"Pac-Man is Arcade game developed  by Zeeshan Ali ");
						outtextxy(400,320,"from GC university Bscs 2nd Semester Sec B (Eve)");
						outtextxy(400,340,"AND Released in 12 May 2016");
						setcolor(RED);
						outtextxy(400,400,"Press B: For Back");
					}
					else if(ch==104) //h
					{
						cleardevice();
						settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
						outtextxy(400,235,"Help :");
						setcolor(WHITE);
						settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
						outtextxy(400,300,"Up Arrow : move up  ");
						outtextxy(400,320,"Down Arrow : move down ");
						outtextxy(400,340,"Left Arrow : move left ");
						outtextxy(400,360,"Right Arrow : move right ");
						setcolor(RED);
						outtextxy(400,400,"Press B: For Back ");
					}
					else if(ch==98) //b
					{
						cleardevice();
						Menu m(500,y);
						m.print();
					}
				}
			}
		}
};

