#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include"information.h"
#include"printback.h"
using namespace std; 

void *imagecol;
void **imgrole = new void*[8];

char *role[8] = {".\\roles_picture\\Davis\\davis_s.bmp",
				 ".\\roles_picture\\Woody\\woody_s.bmp",
				 ".\\roles_picture\\Dennis\\dennis_s.bmp",
				 ".\\roles_picture\\Freeze\\freeze_s.bmp",
				 ".\\roles_picture\\Firen\\firen_s.bmp",
				 ".\\roles_picture\\John\\john_s.bmp",
				 ".\\roles_picture\\Deep\\deep_s.bmp",
				 ".\\roles_picture\\Julian\\julian_s.bmp"	};

void getimg_info()
{
	setactivepage(0);
	for(int i=0; i<8; i++){
		imgrole[i] = malloc(imagesize(0, 0, 40, 45));
		imgrole[i] = getimage(role[i], 40, 45, 1);
	}
	imagecol = getimage(".\\image_screen\\2.jpg", 198, 54, 0);
}

void print_bar(int bar1, int bar2)
{
	setfillstyle(SOLID_FILL,0x0000dd);
	bar(56, 16, 56+bar1, 26);
	bar(254, 16, 254+bar2, 26);
	setfillstyle(SOLID_FILL,0xe30000);
	bar(56, 36, 181, 46);
	bar(254, 36, 379, 46);
}

void printimg_info(int p1, int p2)
{
	for(int i=0; i<2; i++)
		for(int j=0; j<4; j++)
			putimage(198*j, 54*i, imagecol, 0);
	putimage(10, 6, imgrole[p1-1], 0);
	putimage(205, 6, imgrole[p2-1], 0);
}
