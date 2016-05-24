#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include "game.h"
int main()
{
	int gd=DETECT,gm;
	initwindow(1360,700);
	initgraph(&gd,&gm,"");
	Game game;
	game.start();
	getch();
	return 0;
}
