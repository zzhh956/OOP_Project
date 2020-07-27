#ifndef PICK_H_
#define PICK_H_

#include<iostream>
#include<graphics.h>
using namespace std;

void getimgfr();	 	//get frame

void getimgatt();	 	//get image of attack to pick

void getimgran();		//get image of random

void getimgcom();		//get image of select computer

void getimgaft();		//get image of after selection

void getimgnop_m3();		//get image of now option

void getimgchr();	//get image of characters

void getimgword();		//get image of words

void printimg_m3(int player_1, int player_2, int*pick, int cur_page, int count, int com, int *com_role); 	//print

void printpick(int x, int y, int player, int cur_page); 	//show pick

void printaftpick(int cur_page);	//show after pick

void printaft(int cur_page);	//show after com

void printnop_m3(int op, int cur_pag);	//show now option

void printnum(int cur_page, int j);	//show number

void printplayer(int cur_page, int player_1, int player_2, int check_1, int check_2);	//show player number

#endif
