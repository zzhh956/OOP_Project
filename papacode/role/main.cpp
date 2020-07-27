#include<iostream>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include"player.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	playerset();
	srand(time(NULL));
    initwindow(1000,1000);
	class Player John(".\\roles_picture\\John\\john_0.bmp",".\\roles_picture\\John\\john_0_mirror.bmp",
	800,560,70,10,7,15,800,560,70,10,7,15);
	//John.setposition(100,500);
	John.recordimage();
	while(1){
		John.control();
		John.print();
		delay(70);
	}
	return 0;
}
