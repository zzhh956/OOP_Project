#ifndef _PRINTBACK_H_
#define _PRINTBACK_H_

#include<iostream>
#include<graphics.h>
using namespace std;

void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);	//get image

void* getimage(char *filename, int wa, int ha, int bkcolor); 	//get image

void getimgc(int pic);	 //get background character

void getimglf();	 //get little fighter 2

void getimgop();	 //get option

void getimgnop_m1();	//get now option

void getimgnop_m2();	//get now option

void printimg_m1(int i); 	//print menu_1

void printimg_m2(int i); 	//print menu_2

#endif
