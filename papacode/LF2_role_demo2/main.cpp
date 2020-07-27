#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include"player.h"
#include"julian.h"
#include"deep.h"
#include"firen.h"
#include"freeze.h"
#include"woody.h"
#include"davis.h"
#include"dennis.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int cur_page=0;
	srand(time(NULL));
    initwindow(1000,1000);
	class Player john(
	".\\roles_picture\\John\\john_0.bmp",".\\roles_picture\\John\\john_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\John\\john_3_1_1.bmp",".\\roles_picture\\John\\john_3_mirror_1_1.bmp",480,80,6,6,1,15,480,80,6,6,1,15,
	".\\roles_picture\\John\\john_biscuit.bmp",".\\roles_picture\\John\\john_biscuit_mirror.bmp",364,64,12,4,3,15,364,64,12,4,3,15,
	".\\roles_picture\\John\\john_2_1.bmp",".\\roles_picture\\John\\john_2_mirror_1.bmp",440,80,4,4,1,15,440,80,4,4,1,15,
	".\\roles_picture\\John\\john_ball_1.bmp",".\\roles_picture\\John\\john_ball_mirror_1.bmp",324,83,4,4,1,15,324,83,4,4,1,15
	);
	//John.setposition(100,500);john_2_mirror_1.bmp
	class Julian julian(
	".\\roles_picture\\Julian\\julian_0.bmp",".\\roles_picture\\Julian\\julian_0_mirror.bmp",800,500,50,10,5,15,800,500,50,10,5,15,
	".\\roles_picture\\Julian\\qi_1.bmp",".\\roles_picture\\Julian\\qi_1_mirror.bmp",480,100,6,6,1,15,480,100,6,6,1,15,
	".\\roles_picture\\Julian\\julian_ball2_1.bmp",".\\roles_picture\\Julian\\julian_ball2_mirror_1.bmp",218,99,2,2,1,15,218,99,2,2,1,15,
	".\\roles_picture\\Julian\\qi_2.bmp",".\\roles_picture\\Julian\\qi_2_mirror.bmp",240,100,3,3,1,15,240,100,3,3,1,15,
	".\\roles_picture\\Julian\\julian_col.bmp",".\\roles_picture\\Julian\\julian_col_mirror.bmp",800,405,4,4,1,15,800,405,4,4,1,15
	);
	class Deep deep(
	".\\roles_picture\\Deep\\deep_0.bmp",".\\roles_picture\\Deep\\deep_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Deep\\deep_2-1.bmp",".\\roles_picture\\Deep\\deep_2_mirror-1.bmp",800,160,20,10,2,15,800,160,20,10,2,15,
	".\\roles_picture\\Deep\\deep_3.bmp",".\\roles_picture\\Deep\\deep_3_mirror.bmp",400,80,5,5,1,15,400,80,5,5,1,15,
	".\\roles_picture\\Deep\\deep_ball.bmp",".\\roles_picture\\Deep\\deep_ball_mirror.bmp",320,160,8,4,2,15,320,160,8,4,2,15
	);
	class Firen firen(
	".\\roles_picture\\Firen\\firen_0.bmp",".\\roles_picture\\Firen\\firen_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Firen\\exp.bmp",".\\roles_picture\\Firen\\exp_mirror.bmp",400,160,10,5,2,15,400,160,10,5,2,15,
	".\\roles_picture\\Firen\\firen_exp.bmp",".\\roles_picture\\Firen\\firen_exp_mirror.bmp",800,480,15,5,3,15,800,480,15,5,3,15,
	".\\roles_picture\\Firen\\throw_ball.bmp",".\\roles_picture\\Firen\\throw_ball_mirror.bmp",400,80,5,5,1,15,400,80,5,5,1,15,
	".\\roles_picture\\Firen\\firen_ball.bmp",".\\roles_picture\\Firen\\firen_ball_mirror.bmp",328,249,12,4,3,15,328,249,12,4,3,15
	);
	class Freeze freeze(
	".\\roles_picture\\Freeze\\freeze_0.bmp",".\\roles_picture\\Freeze\\freeze_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Freeze\\wind.bmp",".\\roles_picture\\Freeze\\wind_mirror.bmp",720,80,9,9,1,15,720,80,9,9,1,15,
	".\\roles_picture\\Freeze\\freeze_ww.bmp",".\\roles_picture\\Freeze\\freeze_ww_mirror.bmp",800,320,10,5,2,15,800,320,10,5,2,15,
	".\\roles_picture\\Freeze\\throw_ball.bmp",".\\roles_picture\\Freeze\\throw_ball_mirror.bmp",480,80,6,6,1,15,480,80,6,6,1,15,
	".\\roles_picture\\Freeze\\freeze_ball.bmp",".\\roles_picture\\Freeze\\freeze_ball_mirror.bmp",328,249,12,4,3,15,328,249,12,4,3,15
	);
	class Woody woody(
	".\\roles_picture\\Woody\\woody_0.bmp",".\\roles_picture\\Woody\\woody_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Woody\\kick.bmp",".\\roles_picture\\Woody\\kick_mirror.bmp",800,80,10,10,1,15,800,80,10,10,1,15,
	".\\roles_picture\\Woody\\throw_ball.bmp",".\\roles_picture\\Woody\\throw_ball_mirror.bmp",800,80,10,10,1,15,800,80,10,10,1,15,
	".\\roles_picture\\Woody\\woody_ball.bmp",".\\roles_picture\\Woody\\woody_ball_mirror.bmp",328,249,12,4,3,15,328,249,12,4,3,15
	);
	class Davis davis(
	".\\roles_picture\\Davis\\davis_0.bmp",".\\roles_picture\\Davis\\davis_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Davis\\holly.bmp",".\\roles_picture\\Davis\\holly_mirror.bmp",640,80,8,8,1,15,640,80,8,8,1,15,
	".\\roles_picture\\Davis\\throw_ball.bmp",".\\roles_picture\\Davis\\throw_ball_mirror.bmp",400,80,5,5,1,15,400,80,5,5,1,15,
	".\\roles_picture\\Davis\\davis_ball.bmp",".\\roles_picture\\Davis\\davis_ball_mirror.bmp",328,141,12,4,3,15,328,141,12,4,3,15
	);
	class Dennis dennis(
	".\\roles_picture\\Dennis\\dennis_0.bmp",".\\roles_picture\\Dennis\\dennis_0_mirror.bmp",800,560,70,10,7,15,800,560,70,10,7,15,
	".\\roles_picture\\Dennis\\kick.bmp",".\\roles_picture\\Dennis\\kick_mirror.bmp",800,80,10,10,1,15,800,80,10,10,1,15,
	".\\roles_picture\\Dennis\\throw_chase.bmp",".\\roles_picture\\Dennis\\throw_chase_mirror.bmp",640,80,8,8,1,15,640,80,8,8,1,15,
	".\\roles_picture\\Dennis\\dennis_chase.bmp",".\\roles_picture\\Dennis\\dennis_chase_mirror.bmp",328,250,12,4,3,15,328,250,12,4,3,15
	);
	void **background=getimage2(".\\roles_picture\\John\\107003824.jpg",1000,1000,1,1,1,15);
	julian.recordimage();
	john.recordimage();
	deep.recordimage();
	firen.recordimage();
	freeze.recordimage();
	woody.recordimage();
	davis.recordimage();
	dennis.recordimage();
	while(1){
		john.control();
		julian.control();
		deep.control();
		firen.control();
		freeze.control();
		woody.control();
		davis.control();
		dennis.control();
		//printf("*\n");
		setvisualpage(cur_page);//  0 1	      
        cur_page = -cur_page + 1;    
        setactivepage(cur_page);//  1 0
        setbkcolor(BLACK);
        cleardevice();
        putimage(0,0, background[0], OR_PUT);
        
		john.print();
		julian.print();
		deep.print();
		firen.print();
		freeze.print();
		woody.print();
		davis.print();
		dennis.print();
		delay(70);
	}
	//getch();
	return 0;
}
