#include <windows.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include "information.h"
using namespace std; 

void *imagebar_b, *imagebar_r, *imagecol;

void* getimage(char *filename, int wa, int ha, int bkcolor)
{	
	void *img = malloc( imagesize(0, 0, wa-1, ha-1) );	
	setbkcolor(bkcolor);
	cleardevice();
    readimagefile(filename, 0, 0, wa-1, ha-1);
	getimage(0, 0, wa-1, ha-1, img);
	cleardevice();
	
	return img;
}

void getimgbar()
{
	setactivepage(0);
	char *bar_b = ".\\image\\3.jpg";
	char *bar_r = ".\\image\\5.jpg";
	imagebar_b = getimage(bar_b, 125, 10, 0);
	imagebar_r = getimage(bar_r, 125, 10, 0);
}

void getimgcol()
{
	setactivepage(0);
	char *col = ".\\image\\2.jpg";
	imagecol = getimage(col, 198, 54, 0);
}

void printimg_info()
{
	setactivepage(0);
	setbkcolor(0);
	cleardevice();
	
	for(int i=0; i<2; i++){
		for(int j=0; j<4; j++){
			putimage(198*j, 54*i, imagecol, 0);
		}
		putimage(56+198*i, 16, imagebar_r, 0);
		putimage(56+198*i, 36, imagebar_b, 0);
	}
	setvisualpage(0);
}
