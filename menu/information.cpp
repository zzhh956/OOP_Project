#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include"information.h"
#include"printback.h"
using namespace std; 

void *imagebar_b, *imagebar_r, *imagecol;

void getimgbar()
{
	setactivepage(0);
	char *bar_b = ".\\image_screen\\3.jpg";
	char *bar_r = ".\\image_screen\\5.jpg";
	imagebar_b = getimage(bar_b, 125, 10, 0);
	imagebar_r = getimage(bar_r, 125, 10, 0);
}

void getimgcol()
{
	setactivepage(0);
	char *col = ".\\image_screen\\2.jpg";
	imagecol = getimage(col, 198, 54, 0);
}

void printimg_info()
{
	for(int i=0; i<2; i++){
		putimage(198*i, 0, imagecol, 0);
		putimage(56+198*i, 16, imagebar_r, 0);
		putimage(56+198*i, 36, imagebar_b, 0);
	}
}
