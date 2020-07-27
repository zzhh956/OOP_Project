#include <windows.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
#include "information.h"
using namespace std;

int main(void) 
{
	initwindow(796, 551);
	setbkcolor(0);
	cleardevice();
	srand( time(NULL) );
	
	getimgbar();
	getimgcol();
	printimg_info();
	
	getch();
}
