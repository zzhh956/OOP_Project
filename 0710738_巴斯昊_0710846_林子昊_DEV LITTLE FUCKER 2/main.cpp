#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include".\\characters\\printback.h"
#include".\\characters\\menucontroll.h"
#include".\\characters\\pick.h"
#include".\\characters\\john.h"
#include".\\characters\\julian.h"
#include".\\characters\\deep.h"
#include".\\characters\\firen.h"
#include".\\characters\\freeze.h"
#include".\\characters\\woody.h"
#include".\\characters\\davis.h"
#include".\\characters\\dennis.h"
#include".\\characters\\information.h"
#include".\\characters\\hit2.h"
using namespace std; 

void play_game(int pick_1, int pick_2)
{
	//---------------------------------------------------------------------------------------------------
	int p1_position_x;//角色目前位置 
	int p1_position_y;//角色目前位置 
	int p1_skill1_position_x;//技能1目前位置 
	int p1_skill1_position_y;//技能1目前位置 
	int p1_skill2_position_x;//技能2目前位置 
	int p1_skill2_position_y;//技能2目前位置
	int p1_manyskill1_position_x;//額外技能1目前位置 
	int p1_manyskill1_position_y;//額外技能1目前位置
	int p1_manyskill2_position_x;//額外技能2目前位置 
	int p1_manyskill2_position_y;//額外技能2目前位置
	int p2_position_x;//角色目前位置 
	int p2_position_y;//角色目前位置 
	int p2_skill1_position_x;//技能1目前位置 
	int p2_skill1_position_y;//技能1目前位置 
	int p2_skill2_position_x;//技能2目前位置 
	int p2_skill2_position_y;//技能2目前位置
	int p2_manyskill1_position_x;//額外技能1目前位置 
	int p2_manyskill1_position_y;//額外技能1目前位置
	int p2_manyskill2_position_x;//額外技能2目前位置 
	int p2_manyskill2_position_y;//額外技能2目前位置
	int p1_width,p1_height,p2_width,p2_height;//角色長寬 
	int p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height;//角色1的技能1與技能2長寬
	int p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height;//角色2的技能1與技能2長寬 
	int p1_skill1_switch;//決定是否繼續顯示圖片，0為否，1為是 
	int p1_skill2_switch;
	int p1_manyskill1_switch;
	int p1_manyskill2_switch;
	int p1_down_switch;
	int p1_defense_switch;
	int p2_skill1_switch;
	int p2_skill2_switch;
	int p2_manyskill1_switch;
	int p2_manyskill2_switch;
	int p2_down_switch;
	int p2_defense_switch;
	int p1_button_down,p2_button_down;
	//---------------------------------------------------------------------------------------------------
	int cur_page=0;
	int keep_p1 = 0;
	int keep_p2 = 0;
	int timer_1 = 0;
	int timer_2 = 0;
	int timer_3 = 0;
	int bar_1 = 125;
	int bar_2 = 125;
	bool end = false, died = false;
	
	srand(time(NULL));
	cleardevice();
	class John john;
	class Julian julian;
	class Deep deep;
	class Firen firen;
	class Freeze freeze;
	class Woody woody;
	class Davis davis;
	class Dennis dennis;
	getimg_info();
	print_bar(bar_1, bar_2);
	void **background=getimage2("roles_picture\\John\\107003824.jpg",1000,1000,1,1,1,15);
	switch(pick_1){
		case 1:	davis.recordimage();	davis.set(1);	break;
		case 2:	woody.recordimage();	woody.set(1);	break;
		case 3:	dennis.recordimage();	dennis.set(1);	break;
		case 4:	freeze.recordimage();	freeze.set(1);	break;
		case 5:	firen.recordimage();	firen.set(1);	break;
		case 6:	john.recordimage();		john.set(1);	break;
		case 7:	deep.recordimage();		deep.set(1);	break;
		case 8:	julian.recordimage();	julian.set(1);	break;
	}
	switch(pick_2){
		case 1:	davis.recordimage();	davis.set(2);	break;
		case 2:	woody.recordimage();	woody.set(2);	break;
		case 3:	dennis.recordimage();	dennis.set(2);	break;
		case 4:	freeze.recordimage();	freeze.set(2);	break;
		case 5:	firen.recordimage();	firen.set(2);	break;
		case 6:	john.recordimage();		john.set(2);	break;
		case 7:	deep.recordimage();		deep.set(2);	break;
		case 8:	julian.recordimage();	julian.set(2);	break;
	}
	
	while(!end){
		if(!died){
			switch(pick_1){
				case 1:	
						davis.control();
						davis.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);	
						break;
				case 2:	
						woody.control();
						woody.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);	
						break;
				case 3:	dennis.control();
						dennis.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);	
						break;
				case 4:	
						freeze.control();
						freeze.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);
						break;
				case 5:	
						firen.control();
						firen.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);
						break;
				case 6:	
						john.control();
						john.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);		
						break;
				case 7:	
						deep.control();	
						deep.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);	
						break;
				case 8:	
						julian.control();	
						julian.getdata(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,
						p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
						p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,
						p1_button_down);
						break;
			}
			switch(pick_2){
				case 1:	
						davis.control();
						davis.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
				case 2:	
						woody.control();
						woody.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);	
						break;
				case 3:	dennis.control();
						dennis.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
				case 4:	
						freeze.control();
						freeze.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
				case 5:	
						firen.control();
						firen.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
				case 6:	
						john.control();
						john.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);	
						break;
				case 7:	
						deep.control();	
						deep.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
				case 8:	
						julian.control();
						julian.getdata(p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,
						p2_skill2_position_y,p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
						p2_width,p2_height,p2_skill1_width,p2_skill1_height,p2_skill2_width,p2_skill2_height,
						p2_button_down);
						break;
			}
		}
		setvisualpage(cur_page);//  0 1	      
        cur_page = -cur_page + 1;    
        setactivepage(cur_page);//  1 0
        setbkcolor(BLACK);
        cleardevice();
        putimage(0,0, background[0], OR_PUT);
        printimg_info(pick_1, pick_2);
		print_bar(bar_1, bar_2);		
		
		if(!mode3(p1_position_x,p1_position_y,p1_skill1_position_x,p1_skill1_position_y,p1_skill2_position_x,//圖檔座標 
		p1_skill2_position_y,p1_manyskill1_position_x,p1_manyskill1_position_y,p1_manyskill2_position_x,p1_manyskill2_position_y,
		p2_position_x,p2_position_y,p2_skill1_position_x,p2_skill1_position_y,p2_skill2_position_x,p2_skill2_position_y,
		p2_manyskill1_position_x,p2_manyskill1_position_y,p2_manyskill2_position_x,p2_manyskill2_position_y,
		p1_width,p1_height,p1_skill1_width,p1_skill1_height,p1_skill2_width,p1_skill2_height,//圖檔長寬 
		p2_width,p2_height,p2_skill2_width,p2_skill2_height,p2_skill2_width,p2_skill2_height,
		p1_button_down,p2_button_down,//普攻按鍵參數 
		&p1_skill1_switch,&p1_skill2_switch,&p2_skill1_switch,&p2_skill2_switch,//決定是否繼續顯示圖片，0為否，1為是
		&p1_manyskill1_switch,&p1_manyskill2_switch,&p2_manyskill1_switch,&p2_manyskill2_switch,
		&p1_down_switch,&p1_defense_switch,&p2_down_switch,&p2_defense_switch, keep_p1, keep_p2, &bar_1, &bar_2))
			died = true;
		else{
			if(p1_down_switch || p1_defense_switch)
				keep_p1 = 1;
			if(p2_down_switch || p2_defense_switch)
				keep_p2 = 1;
		}		
	
		if(keep_p1){
			timer_1++;
			if(timer_1 == 20){
				keep_p1 = 0;
				timer_1 = 0;
			}
		}
		if(keep_p2){
			timer_2++;
			if(timer_2 == 20){
				keep_p2 = 0;
				timer_2 = 0;
			}
		}
		if(timer_3<15){
			switch(pick_1){
				case 1:	
						davis.setdata(p1_down_switch,p1_defense_switch);
						davis.print();	
						break;
				case 2:	
						woody.setdata(p1_down_switch,p1_defense_switch);
						woody.print();	
						break;
				case 3:	
						dennis.setdata(p1_down_switch,p1_defense_switch);
						dennis.print();	
						break;
				case 4:	
						freeze.setdata(p1_down_switch,p1_defense_switch);
						freeze.print();
						break;
				case 5:	
						firen.setdata(p1_down_switch,p1_defense_switch);
						firen.print();
						break;
				case 6:	
						john.setdata(p1_down_switch,p1_defense_switch);
						john.print();	
						break;
				case 7:	
						deep.setdata(p1_down_switch,p1_defense_switch);
						deep.print();	
						break;
				case 8:
						julian.setdata(p1_down_switch,p1_defense_switch);
						julian.print();
						break;
			}
			switch(pick_2){
				case 1:	
						davis.setdata(p2_down_switch,p2_defense_switch);
						davis.print();	
						break;
				case 2:	
						woody.setdata(p2_down_switch,p2_defense_switch);
						woody.print();
						break;
				case 3:	
						dennis.setdata(p2_down_switch,p2_defense_switch);
						dennis.print();
						break;
				case 4:	
						freeze.setdata(p2_down_switch,p2_defense_switch);
						freeze.print();
						break;
				case 5:	
						firen.setdata(p2_down_switch,p2_defense_switch);
						firen.print();
						break;
				case 6:	
						john.setdata(p2_down_switch,p2_defense_switch);
						john.print();
						break;
				case 7:	
						deep.setdata(p2_down_switch,p2_defense_switch);
						deep.print();
						break;
				case 8:
						julian.setdata(p2_down_switch,p2_defense_switch);
						julian.print();	
						break;
			}
		}
		if(died){
			timer_3++;
		}
		if(timer_3 == 10)
			end = true;
		
		delay(70);
	}
}

int main(void) 
{		
	int ran, ctr_1 = 0, ctr_2 = 0, keepctr_1 = 6, keepctr_2 = 6, cur_page = 0, player_1 = 0, player_2 = 0;
	int count = 0; // count how many time that press player 1's attack key
	int choose = 0;	// choose option
	int pick[2] = {0};
	
	initwindow(796, 551);
	setbkcolor(0x790000);
	cleardevice();
	srand( time(NULL) );
	
	//get image of menu 1
	ran = rand()%13;
	getimg_menu1(ran);
	
	//get image of menu 2	
	getimg_menu2(ran);
	
	//get image of menu 3
	getimg_menu3();
	
	//print menu 1
	setactivepage(cur_page);
	printimg_m1(choose);
	
	while(count == 0){	
		if(ctr_1 < 2){	
			choose = ctr_1;
			setvisualpage(cur_page);//  0 1	      
       		cur_page = -cur_page + 1;    
       		setactivepage(cur_page);//  1 0
			printimg_m1(choose);
		}
		if(ctr_1 == 4 && choose == 0)	count = 1;	
		keepctr_1 = ctr_1;
		ctr_1 = Presskey_1();
	}
	
	while(count != -1){
		//print menu 2
		delay(100);
		choose = 0;
		ran = rand() % 13;
		getimg_menu2(ran);
		keepctr_1 = 6;
		ctr_1 = 5;
		
		while(count == 1){
			if(keepctr_1 != ctr_1){
				if(ctr_1 == 1){
					choose++;
					if(choose > 2)
						choose = 2;
				}
				else if(ctr_1 == 0) {
					choose--;
					if(choose < 0)
						choose = 0;
				}
				setvisualpage(cur_page);//  0 1	      
       			cur_page = -cur_page + 1;    
       			setactivepage(cur_page);//  1 0
				printimg_m2(choose);
			}
			if(ctr_1 == 4 && choose == 0)
				count = 2;
			//exit
			else if(ctr_1 == 4 && choose == 2)
				count = -1;
			keepctr_1 = ctr_1;
			ctr_1 = Presskey_1();
		}
	
		//print menu 3
		int com_role[7] = {0};
		int check_1 = 0;	// check if player 1 finish picking
		int check_2 = 0;	// check if player 2 finish picking
		choose = 0;
		player_1 = 0;
		player_2 = 0;
		keepctr_1 = 6;
		keepctr_2 = 6;
		ctr_1 = 6;
		ctr_2 = 6;
		delay(100);
		
		while(count >= 2 && count != -1){
			if(count >= 3){
				ctr_1 = 6;
				ctr_2 = 6;
				//print pick role
				while(count == 3){
					if(player_1 == 1){
						if(check_1 != 1){
							if(ctr_1 == 2){
								pick[0]--;
								if(pick[0] < 0)
									pick[0] = 8;
							}
							else if(ctr_1 == 3){
								pick[0]++;
								if(pick[0] > 8)
									pick[0] = 0;
							}
						}
						else{
							if(ctr_1 == 5){
								check_1 = 0;
								ctr_1 = 6;
							}
						}
						if(ctr_1 == 4 && (pick[0] != pick[1] || check_2 == 0))
							check_1 = 1;
						else if(ctr_1 == 4 && pick[0] == 0)
							check_1 = 1;
						else if(ctr_1 == 5){
							player_1 = 0;
							pick[0] = 0;
						}
					}
					else{
						if(ctr_1 == 4){
							player_1 = 1;
							ctr_1 = 6;
						}
					}
					if(player_2 == 1){
						if(check_2 != 1){
							if(ctr_2 == 9){
								pick[1]--;
								if(pick[1] < 0)
									pick[1] = 8;
							}
							else if(ctr_2 == 10){
								pick[1]++;
								if(pick[1] > 8)
									pick[1] = 0;
							}		
						}
						else{
							if(ctr_2 == 12){
								check_2 = 0;
								ctr_2 = 6;
							}
						}
						if(ctr_2 == 11 && (pick[0] != pick[1] || check_1 == 0))
							check_2 = 1;
						else if(ctr_2 == 11 && pick[1] == 0)
							check_2 = 1;
						else if(ctr_2 == 12){
							player_2 = 0;
							pick[1] = 0;
						}
					}
					else{
						if(ctr_2 == 11){
							player_2 = 1;
							ctr_2 = 6;
						}
					}
					setvisualpage(cur_page);//  0 1	      
       				cur_page = -cur_page + 1;    
       				setactivepage(cur_page);//  1 0
					printimg_m3(player_1, player_2, pick, count, 0, com_role);
					printplayer(player_1, player_2, check_1, check_2);
					//finish pick role
					if(check_1 == 1 && check_2 == 1)
						count = 4;	
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();
					delay(70);
				}
				//print after pick role  
				int com = 0;
				ctr_1 = 6;
				ctr_2 = 6;
				setvisualpage(cur_page);//  0 1	      
       			cur_page = -cur_page + 1;    
       			setactivepage(cur_page);//  1 0	
				printimg_m3(player_1, player_2, pick, count, com, com_role);
				printplayer(player_1, player_2, check_1, check_2);
				printnum(0);
				
				while(count == 4){
					setvisualpage(cur_page);//  0 1	      
       				cur_page = -cur_page + 1;    
       				setactivepage(cur_page);//  1 0
					printimg_m3(player_1, player_2, pick, count, 0, com_role);
					printplayer(player_1, player_2, check_1, check_2);
					printnum(com);
					if(keepctr_1 != ctr_1){
						if(ctr_1 == 2){
							com--;
							if(com < 0)
								com = 0;
						}
						else if(ctr_1 == 3){
							com++;
							if(com > 6){
								com = 6;
							}
						}
						else if(ctr_1 == 4){
							count = 5;
						}
					}
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();
				}			
				//print after pick number of com
				delay(100);
				int	role[8] = {0};
				ctr_1 = 6;
				ctr_2 = 6;		
				keepctr_1 = ctr_1;
				keepctr_2 = ctr_2;
				if(pick[0] != 0)
					role[pick[0]-1] = 1;
				if(pick[1] != 0)
					role[pick[1]-1] = 1; 
				
				for(int i = 0; i < player_1 + player_2; i++){
					if(pick[i] > 0)
						role[pick[i]-1] = 1;
					else{
						pick[i] = rand() % 8 + 1;
						while(role[pick[i]-1]==1)
							pick[i] = rand() % 8 + 1;
						role[pick[i]-1] = 1;
					}
				}
				//get computer role
				for(int i = 0; i < com; i++){
					ran = rand() % 8;
					if(role[ran] == 0){
						com_role[i] = ran;
						role[ran] = 1;
					}
					else
						i--;
				}
				choose = 0;
				ctr_1 = 6;
				setvisualpage(cur_page);//  0 1	      
       			cur_page = -cur_page + 1;    
       			setactivepage(cur_page);//  1 0
				printimg_m3(player_1, player_2, pick, count, com, com_role);
				printplayer(player_1, player_2, check_1, check_2);
				printnop_m3(choose);
				
				while(count == 5){
					if(keepctr_1 != ctr_1){
						if(ctr_1 == 0){
							choose--;
							if(choose < 0)
								choose = 0;
						}
						else if(ctr_1 == 1){
							choose++;
							if(choose > 3)
								choose = 3;
						}
					}
					if(choose == 0 && ctr_1 == 4){
						play_game(pick[0], pick[1]);
						count = 1;
						break;
					}
					else if(choose == 1 && ctr_1 == 4){
						count = 2;
						player_1 = 0;
						player_2 = 0;
						check_1 = 0;
						check_2 = 0;
						pick[0] = 0;
						pick[1] = 0;
						ctr_1 = 6;
						ctr_2 = 6;
						break;
					}
					else if(choose == 2 && ctr_1 == 4){
						for(int i = 0; i < 8; i++)
							if(i != pick[0] - 1 && i != pick[1] - 1)
								role[i] = 0;
						for(int i = 0; i < com; i++){
							ran = rand() % 8;
							if(role[ran] == 0){
								com_role[i] = ran;
								role[ran] = 1;
							}
							else
								i--;
						}
						delay(30);
					}
					else if(choose == 3 && ctr_1 == 4){
						count = 1;
						player_1 = 0;
						player_2 = 0;
						check_1 = 0;
						check_2 = 0;
						pick[0] = 0;
						pick[1] = 0;
						ctr_1 = 6;
						ctr_2 = 6;
						break;
					}
					
					setvisualpage(cur_page);//  0 1	      
       				cur_page = -cur_page + 1;    
       				setactivepage(cur_page);//  1 0
					printimg_m3(player_1, player_2, pick, count, com, com_role);
					printplayer(player_1, player_2, check_1, check_2);
					printnop_m3(choose);		
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();
					delay(30);
				}
			}
			else if(count == 2){
				player_1 = 0;
				player_2 = 0;
				check_1 = 0;
				check_2 = 0;
				pick[0] = 0;
				pick[1] = 0;
				for(int i = 0; i < 7; i++)
					com_role[i] = 0;
				setvisualpage(cur_page);//  0 1	      
       			cur_page = -cur_page + 1;    
       			setactivepage(cur_page);//  1 0
				printimg_m3(player_1, player_2, pick, count, 0, com_role);
			}
			if(ctr_1 == 4){
				count = 3;
				player_1 = 1;
			}
			if(ctr_2 == 11){
				count = 3;
				player_2 = 1;
			}
			ctr_1 = Presskey_1();
			ctr_2 = Presskey_2();
			delay(100);
		}
	}

	closegraph();
}
