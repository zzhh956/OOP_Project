#include<windows.h>
#include<iostream>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include"printback.h"
#include"menucontroll.h"
#include"pick.h"
#include"john.h"
#include"julian.h"
#include"deep.h"
#include"firen.h"
#include"freeze.h"
#include"woody.h"
#include"davis.h"
#include"dennis.h"
#include"information.h"
using namespace std;

void play_game(int pick_1, int pick_2)
{
	int cur_page=0;
	srand(time(NULL));
	initwindow(1000, 700);
    setbkcolor(BLACK);
	cleardevice();
	class John john;
	class Julian julian;
	class Deep deep;
	class Firen firen;
	class Freeze freeze;
	class Woody woody;
	class Davis davis;
	class Dennis dennis;
	getimgbar();
	getimgcol();
	void **background=getimage2(".\\roles_picture\\John\\107003824.jpg",1000,1000,1,1,1,15);
	
	switch(pick_1){
		case 1:	davis.recordimage();	davis.set(1);		break;
		case 2:	woody.recordimage();	woody.set(1);		break;
		case 3:	dennis.recordimage();	dennis.set(1);		break;
		case 4:	freeze.recordimage();	freeze.set(1);		break;
		case 5:	firen.recordimage();	firen.set(1);		break;
		case 6:	john.recordimage();		john.set(1);		break;
		case 7:	deep.recordimage();		deep.set(1);		break;
		case 8:	julian.recordimage();	julian.set(1);		break;
	}
	switch(pick_2){
		case 1:	davis.recordimage();	davis.set(2);		break;
		case 2:	woody.recordimage();	woody.set(2);		break;
		case 3:	dennis.recordimage();	dennis.set(2);		break;
		case 4:	freeze.recordimage();	freeze.set(2);		break;
		case 5:	firen.recordimage();	firen.set(2);		break;
		case 6:	john.recordimage();		john.set(2);		break;
		case 7:	deep.recordimage();		deep.set(2);		break;
		case 8:	julian.recordimage();	julian.set(2);		break;
	}
	while(1){
		switch(pick_1){
			case 1:	davis.control();	break;
			case 2:	woody.control();	break;
			case 3:	dennis.control();	break;
			case 4:	freeze.control();	break;
			case 5:	firen.control();	break;
			case 6:	john.control();		break;
			case 7:	deep.control();		break;
			case 8:	julian.control();	break;
		}
		switch(pick_2){
			case 1:	davis.control();	break;
			case 2:	woody.control();	break;
			case 3:	dennis.control();	break;
			case 4:	freeze.control();	break;
			case 5:	firen.control();	break;
			case 6:	john.control();		break;
			case 7:	deep.control();		break;
			case 8:	julian.control();	break;
		}
		setvisualpage(cur_page);//  0 1	      
        cur_page = -cur_page + 1;    
        setactivepage(cur_page);//  1 0
        setbkcolor(BLACK);
        cleardevice();
        putimage(0,0, background[0], OR_PUT);
		printimg_info();
		switch(pick_1){
			case 1:	davis.print();	break;
			case 2:	woody.print();	break;
			case 3:	dennis.print();	break;
			case 4:	freeze.print();	break;
			case 5:	firen.print();	break;
			case 6:	john.print();	break;
			case 7:	deep.print();	break;
			case 8:	julian.print();	break;
		}
		switch(pick_2){
			case 1:	davis.print();	break;
			case 2:	woody.print();	break;
			case 3:	dennis.print();	break;
			case 4:	freeze.print();	break;
			case 5:	firen.print();	break;
			case 6:	john.print();	break;
			case 7:	deep.print();	break;
			case 8:	julian.print();	break;
		}
		delay(70);
	}
	//getch();
}

int main(void) 
{		
	int ran, ctr_1 = 0, ctr_2 = 0, keepctr_1 = 6, keepctr_2 = 6, cur_page = 0, player_1 = 0, player_2 = 0;
	bool play = false, mode = false;
	int pick[2] = {0};
	
	initwindow(796, 551);
	setbkcolor(BLUE);
	cleardevice();
	srand( time(NULL) );
	
	//get image of menu 1
	ran = rand()%13;
	getimgc(ran);
	getimglf();
	getimgop();
	getimgnop_m1();
	
	//get image of menu 2
	getimgc(ran);	
	getimgnop_m2();
	
	//get image of menu 3
	getimgfr();
	getimgatt();
	getimgran();
	getimgcom();
	getimgaft();
	getimgnop_m3();
	getimgword();
	getimgchr();
	
	//print menu 1
	while(1){
		if(keepctr_1 != ctr_1)
			if(ctr_1 < 2){
				cur_page = ctr_1;
				printimg_m1(cur_page);
			}
		if(ctr_1 == 4 && cur_page == 0)	break;	
		keepctr_1 = ctr_1;
		ctr_1 = Presskey_1();
	}
	
	while(!play){
		//print menu 2
		delay(100);
		cur_page = 0;
		ran = rand() % 13;
		getimgc(ran);
		keepctr_1 = 6;
		ctr_1 = 5;
		
		while(1){
			if(keepctr_1 != ctr_1){
				if(ctr_1 == 1){
					cur_page++;
					if(cur_page > 2)
						cur_page = 2;
				}
				else if(ctr_1 == 0) {
					cur_page--;
					if(cur_page < 0)
						cur_page = 0;
				}
				printimg_m2(cur_page);
			}
			if(ctr_1 == 4 && cur_page == 0){
				mode = false;
				break;
			}	
			//exit
			else if(ctr_1 == 4 && cur_page == 2)
				return 0;
				
			keepctr_1 = ctr_1;
			ctr_1 = Presskey_1();
		}
	
		//print menu 3
		int com_role[7] = {0};
		int count = 0; // count how many time that press player 1's attack key
		int check_1 = 0;	// check if player 1 finish picking
		int check_2 = 0;	// check if player 2 finish picking
		player_1 = 0;
		player_2 = 0;
		keepctr_1 = 6;
		keepctr_2 = 6;
		cur_page = 0;
		setbkcolor(BLUE);
		cleardevice();
		ctr_1 = 5;
		ctr_2 = 12;
		delay(100);
		
		while(!mode && !play){
			if(count > 0){
				ctr_1 = 6;
				ctr_2 = 6;
				//print pick role
				while(count == 1){
					cur_page = 1;
					printimg_m3(player_1, player_2, pick, cur_page, count, 0, com_role);
					printplayer(cur_page, player_1, player_2, check_1, check_2);
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
					//finish pick role
					if(player_1 == 1 && player_2 == 1)
						if(check_1 == 1 && check_2 == 1)
							count = 2;	
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();
					delay(100);
				}
				//print after pick role  
				int com = 0;
				ctr_1 = 6;
				ctr_2 = 6;
				cur_page = 2;		
				printimg_m3(player_1, player_2, pick, cur_page, count, com, com_role);
				printplayer(cur_page, player_1, player_2, check_1, check_2);
				printnum(cur_page, 0);
				while(count == 2){
					if(keepctr_1 != ctr_1){
						printimg_m3(player_1, player_2, pick, cur_page, count, 0, com_role);
						printplayer(cur_page, player_1, player_2, check_1, check_2);
						printnum(cur_page, com);
						if(ctr_1 == 2){
							com--;
							if(player_2 == 0)
								if(com < 1)
									com = 1;
							if(player_2 == 1)
								if(com < 0)
									com = 0;
						}
						else if(ctr_1 == 3){
							com++;
							if(player_2 == 0)
								if(com > 7){
									com = 7;
								}
							if(player_2 == 1)
								if(com > 6){
									com = 6;
								}
						}
						else if(ctr_1 == 4){
							count = 3;
						}
					}
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();
				}			
				//print after pick number of com
				delay(200);
				int op = 0;
				int	role[8] = {0};
				ctr_1 = 6;
				ctr_2 = 6;			
				keepctr_1 = ctr_1;
				keepctr_2 = ctr_2;
				cur_page = 1;
				for(int i = 0; i < player_1 + player_2; i++){
					if(pick[i] > 0)
						role[pick[i]-1] = 1;
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
				//get the random role
				if(pick[0] == 0)
					pick[0] = rand() % 8 + 1;
				if(pick[1] == 0)
					pick[1] = rand() % 8 + 1;

				printimg_m3(player_1, player_2, pick, cur_page, count, com, com_role);
				printplayer(cur_page, player_1, player_2, check_1, check_2);
				printnop_m3(op, cur_page);
				while(count == 3){
					if(keepctr_1 != ctr_1){
						if(ctr_1 == 0){
							op--;
							if(op < 0)
								op = 0;
						}
						else if(ctr_1 == 1){
							op++;
							if(op > 3)
								op = 3;
						}
						printimg_m3(player_1, player_2, pick, cur_page, count, com, com_role);
						printplayer(cur_page, player_1, player_2, check_1, check_2);
						printnop_m3(op, cur_page);
					}
					if(op == 0 && ctr_1 == 4){
						play = true;
						count=0;
						break;
					}
					else if(op == 1 && ctr_1 == 4){
						count = 0;
						player_1 = 0;
						player_2 = 0;
						check_1 = 0;
						check_2 = 0;
						ctr_1 = 6;
						ctr_2 = 6;
						delay(200);
					}
					else if(op == 2 && ctr_1 == 4){
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
					}
					else if(op == 3 && ctr_1 == 4){
						mode = true;
						break;
					}
					keepctr_1 = ctr_1;
					keepctr_2 = ctr_2;
					ctr_1 = Presskey_1();
					ctr_2 = Presskey_2();	
				}
			}
			if(count == 0 && !play){
				player_1 = 0;
				player_2 = 0;
				check_1 = 0;
				check_2 = 0;
				pick[0] = 0;
				pick[1] = 0;
				cur_page = 0;
				for(int i = 0; i < 7; i++)
					com_role[i] = 0;
				printimg_m3(player_1, player_2, pick, cur_page, count, 0, com_role);
			}
			if(ctr_1 == 4){
				count = 1;
				player_1 = 1;
			}
			if(ctr_2 == 11){
				count = 1;
				player_2 = 1;
			}
			ctr_1 = Presskey_1();
			ctr_2 = Presskey_2();
			delay(100);
		}
	}
	
	play_game(pick[0], pick[1]);

	closegraph();
}
