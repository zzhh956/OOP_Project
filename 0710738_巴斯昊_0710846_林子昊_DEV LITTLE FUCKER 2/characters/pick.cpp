#include<iostream>
#include<graphics.h>
#include"pick.h"
#include"printback.h"
using namespace std; 

void *imagefr, *imageatt_1, *imageatt_2, *imageran, *imagecou_1, *imagecou_2, *imagecou_3, *imagecou_4, *imagecou_5
	, *imagecom, *imageaft, *imagenopm3_1, *imagenopm3_2, *imagenopm3_3, *imagenopm3_4;

void **imageword_w, **imageword_b;

void **imagechr_player = new void *[9];

void **imagechr_com = new void *[9];

char *chr[9] = {	".\\image\\menu3\\random_f.bmp",
					".\\image\\menu3\\davis_f.bmp",
					".\\image\\menu3\\woody_f.bmp",
					".\\image\\menu3\\dennis_f.bmp",
					".\\image\\menu3\\freeze_f.bmp",
					".\\image\\menu3\\firen_f.bmp",
					".\\image\\menu3\\john_f.bmp",
					".\\image\\menu3\\deep_f.bmp",
					".\\image\\menu3\\julian_f.bmp"	};

void getimg_menu3()
{
	setactivepage(0);
	imagefr = getimage(".\\image\\menu3\\1.jpg", 705, 487, 1);
	imageatt_1 = getimage(".\\image\\menu3\\2.jpg", 120, 66, 1);
	imageatt_2 = getimage(".\\image\\menu3\\3.jpg", 120, 66, 1);
	imagecou_1 = getimage(".\\image\\menu3\\5.jpg", 51, 58, 1);
	imagecou_2 = getimage(".\\image\\menu3\\6.jpg", 51, 58, 1);
	imagecou_3 = getimage(".\\image\\menu3\\7.jpg", 51, 58, 1);
	imagecou_4 = getimage(".\\image\\menu3\\8.jpg", 51, 58, 1);
	imagecou_5 = getimage(".\\image\\menu3\\9.jpg", 51, 58, 1);
	imagecom = getimage(".\\image\\menu3\\10.jpg", 365, 111, 1);
	imageaft = getimage(".\\image\\menu3\\11.jpg", 304, 116, 1);
	imagenopm3_1 = getimage(".\\image\\menu3\\12.jpg", 124, 19, 1);
	imagenopm3_2 = getimage(".\\image\\menu3\\13.jpg", 184, 19, 1);
	imagenopm3_3 = getimage(".\\image\\menu3\\14.jpg", 234, 19, 1);
	imagenopm3_4 = getimage(".\\image\\menu3\\15.jpg", 110, 18, 1);
	for(int i=0; i<9; i++){
		imagechr_player[i] = malloc(imagesize(0, 0, 120, 120));
		imagechr_player[i] = getimage(chr[i], 120, 120, 1);
		imagechr_com[i] = malloc(imagesize(0, 0, 120, 120));
		imagechr_com[i] = getimage(chr[i], 120, 120, 1);
	}
	imageword_w = getimage(".\\image\\words\\1.jpg", 251, 257, 256, 16, 16, 1);
	imageword_b = getimage(".\\image\\words\\2.jpg", 251, 257, 256, 16, 16, 1);
}

void printimg_m3(int player_1, int player_2, int *pick, int count, int com, int *com_role)
{
	setbkcolor(0);
	cleardevice();
	putimage(45, 30, imagefr, 0);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 4; j++){
			if(i == 0 && j == 0){
				if(player_1)
					putimage(152, 91, imagechr_player[pick[0]], 0);
				else
					putimage(152+153*j, 130+210*i, imageatt_1, 0);
			}
			else if(i ==0 && j == 1){
				if(player_2)
					putimage(305, 91, imagechr_player[pick[1]], 0);
				else
					putimage(152+153*j, 130+210*i, imageatt_1, 0);
			}
			else{
				if(com > 0){
					putimage(152+153*j, 91+210*i, imagechr_com[com_role[com-1]+1], 0);
					com--;
				}
				else
					putimage(152+153*j, 130+210*i, imageatt_1, 0);
			}
		}
	}
	if(count == 4)
		putimage(200, 240, imagecom, 0);
	else if(count == 5)
		putimage(0, 0, imageaft, 0);
}

void printnop_m3(int op)
{
	if(op==0)
		putimage(90, 14, imagenopm3_1, 2);
	else if(op==1)
		putimage(62, 37, imagenopm3_2, 2);
	else if(op==2)
		putimage(38, 62, imagenopm3_3, 2);
	else
		putimage(98, 84, imagenopm3_4, 2);
}

void printnum(int com)
{
	for(int i=0; i<8; i++){
		if(i!=com)
			putimage(250+35*i, 315, imageword_w[48+i], 2);
	}
	putimage(250+35*com, 315, imageword_b[48+com], 2);
}

void printplayer(int player_1, int player_2, int check_1, int check_2)
{
	if(player_1){
		if(check_1 == 0)
			putimage(207, 215, imageword_b[49], 2);
		else
			putimage(207, 215, imageword_w[49], 2);
	}	
	if(player_2){
		if(check_2 == 0)
			putimage(360, 215, imageword_b[50], 2);
		else
			putimage(360, 215, imageword_w[50], 2);
	}
}
