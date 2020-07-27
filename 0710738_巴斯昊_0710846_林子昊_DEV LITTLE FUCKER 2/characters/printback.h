#ifndef _PRINTBACK_H_
#define _PRINTBACK_H_

#include<iostream>
#include<graphics.h>
using namespace std;

void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);	//get image

void* getimage(char *filename, int wa, int ha, int bkcolor); 	//get image

void getimg_menu1(int pic);	//get pictures of menu1

void getimg_menu2(int pic);	//get pictures of menu2

void printimg_m1(int nop); 	//print menu_1

void printimg_m2(int nop); 	//print menu_2

#endif
