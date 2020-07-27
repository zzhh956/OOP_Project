#ifndef INFO_H_
#define INFO_H_

#include <iostream>
#include <graphics.h>
using namespace std;

void* getimage(char *filename, int wa, int ha, int bkcolor); 	//get image

void getimgbar();	 //get bar

void getimgcol();	 //get column

void printimg_info(); 	//print information

#endif 
