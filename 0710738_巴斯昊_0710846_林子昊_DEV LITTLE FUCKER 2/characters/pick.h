#ifndef PICK_H_
#define PICK_H_

#include<iostream>
#include<graphics.h>
using namespace std;

void getimg_menu3();	//get pictures of menu3

void printimg_m3(int player_1, int player_2, int*pick, int cur_page, int com, int *com_role); 	//print

void printnop_m3(int op);	//show now option

void printnum(int j);	//show number

void printplayer(int player_1, int player_2, int check_1, int check_2);	//show player number

#endif
