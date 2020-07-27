#include"john.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up1_key;
int do1_key;
int le1_key;
int ri1_key;
int at1_key;
int sk1_key;

void John::set(int John){
	if(John==2){
		up1_key=0x26;//上 
		do1_key=0x28;//下 
		le1_key=0x25;//左 
		ri1_key=0x27;//右 
		at1_key=0xBF;///
		sk1_key=0xBA;//;
		position_x=100;//角色起始位置 
		position_y=200;//角色起始位置 
	}
	else if(John==1){
		up1_key=0x57;//w
		do1_key=0x53;//s
		le1_key=0x41;//a
		ri1_key=0x44;//d
		at1_key=0x43;//c
		sk1_key=0x46;//f
		position_x=200;//角色起始位置 
		position_y=200;//角色起始位置 
	}
}
John::John(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//移動圖檔切割數據
	wa_d_a=480;ha_d_a=80;pn_d_a=6;wn_d_a=6;hn_d_a=1;bkcolor_d_a=15;//投擲飛碟技能圖檔切割數據
	wa_d=364;ha_d=64;pn_d=12;wn_d=4;hn_d=3;bkcolor_d=15;//飛碟技能圖檔切割數據
	wa_b_a=440;ha_b_a=80;pn_b_a=4;wn_b_a=4;hn_b_a=1;bkcolor_b_a=15;//投擲球技能圖檔切割數據
	wa_b=324;ha_b=83;pn_b=4;wn_b=4;hn_b=1;bkcolor_b=15;//球技能圖檔切割數據
//--------------------------------------------------------------------------------------存圖檔名稱 
	strcpy(filename_right,".\\roles_picture\\John\\john_0.bmp");
	filename_right[strlen(".\\roles_picture\\John\\john_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\John\\john_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\John\\john_0_mirror.bmp")]='\0';
//		
	strcpy(filename_disk_right_action,".\\roles_picture\\John\\john_3_1_1.bmp");
	filename_disk_right_action[strlen(".\\roles_picture\\John\\john_3_1_1.bmp")]='\0';

	strcpy(filename_disk_left_action,".\\roles_picture\\John\\john_3_mirror_1_1.bmp");
	filename_disk_left_action[strlen(".\\roles_picture\\John\\john_3_mirror_1_1.bmp")]='\0';	
//
	strcpy(filename_disk_right,".\\roles_picture\\John\\john_biscuit.bmp");
	filename_disk_right[strlen(".\\roles_picture\\John\\john_biscuit.bmp")]='\0';	

	strcpy(filename_disk_left,".\\roles_picture\\John\\john_biscuit_mirror.bmp");
	filename_disk_left[strlen(".\\roles_picture\\John\\john_biscuit_mirror.bmp")]='\0';
//		
	strcpy(filename_ball_right_action,".\\roles_picture\\John\\john_2_1.bmp");
	filename_ball_right_action[strlen(".\\roles_picture\\John\\john_2_1.bmp")]='\0';

	strcpy(filename_ball_left_action,".\\roles_picture\\John\\john_2_mirror_1.bmp");
	filename_ball_left_action[strlen(".\\roles_picture\\John\\john_2_mirror_1.bmp")]='\0';	
//
	strcpy(filename_ball_right,".\\roles_picture\\John\\john_ball_1.bmp");
	filename_ball_right[strlen(".\\roles_picture\\John\\john_ball_1.bmp")]='\0';	

	strcpy(filename_ball_left,".\\roles_picture\\John\\john_ball_mirror_1.bmp");
	filename_ball_left[strlen(".\\roles_picture\\John\\john_ball_mirror_1.bmp")]='\0';	
//-----------------------------------------------------------------------------------------
	direction[1]=4;//圖片初始狀態 
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	attack_right_count=10;//圖片初始狀態
	attack_left_count=19;//圖片初始狀態
	disk_right_action_count=0;//往右投擲飛碟圖片初始狀態
	disk_left_action_count=5;//往左投擲飛碟圖片初始狀態
	disk_right_count=0;//飛碟圖片初始狀態
	disk_left_count=11;//飛碟圖片初始狀態
	ball_right_action_count=3;//往右投擲球圖片初始狀態
	ball_left_action_count=0;//往左投擲球圖片初始狀態
	ball_right_count=0;//球圖片初始狀態
	ball_left_count=3;//球圖片初始狀態
	disk_position_x=position_x;//飛碟起始位置  
	disk_position_y=position_y-21;//飛碟起始位置 
	ball_position_x=position_x+110;//球起始位置  
	ball_position_y=position_y+3;//球起始位置 
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_disk_action=0,flag_disk_right=0,flag_disk_left=0;//紀錄投擲飛碟動作是否做完的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲球動作是否做完的初始狀態
}
void John::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void John::control(){
	    if(GetAsyncKeyState(up1_key)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(do1_key)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(le1_key)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(ri1_key)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(at1_key)==0) button_down[4]=0;//攻 
        if(GetAsyncKeyState(sk1_key)==0) button_down[5]=0;//技能 
        
        if(GetAsyncKeyState(up1_key)!=0) button_down[0]=1;//上 
        if(GetAsyncKeyState(do1_key)!=0) button_down[1]=1;//下 
        if(GetAsyncKeyState(le1_key)!=0) button_down[2]=1;//左 
        if(GetAsyncKeyState(ri1_key)!=0) button_down[3]=1;//右 
        if(GetAsyncKeyState(at1_key)!=0) button_down[4]=1;//攻 
        if(GetAsyncKeyState(sk1_key)!=0) button_down[5]=1;//技能 
//------------------------------------------------------------------------------------------------各種flag 
		if(button_down[2]==1||(button_down[0]==1&&direction[1]==3)||(button_down[1]==1&&direction[1]==3)||
		(button_down[4]==1&&direction[1]==3))//判斷flag情形 
			flag_left=1;
		else
			flag_left=0;
				
		if(button_down[3]==1||(button_down[0]==1&&direction[1]==4)||(button_down[1]==1&&direction[1]==4)||
		(button_down[4]==1&&direction[1]==4))//判斷flag情形
			flag_right=1;
		else
			flag_right=0;
			
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_disk_right==0&&flag_ball_action==0){//判斷飛碟出招情況 
			flag_disk_action=1;
			flag_disk_left=1;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_disk_left==0&&flag_ball_action==0){//判斷飛碟出招情況 
			flag_disk_action=1;
			flag_disk_right=1;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_disk_action==0){//判斷球出招情況 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//球起始位置  
			ball_position_y=position_y+3;
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_disk_action==0){//判斷球出招情況 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//球起始位置  
			ball_position_y=position_y+3;
		}
//---------------------------------------------------------------------------------------------------------        
	    button_count=0;
	    for(int i=0;i<6;i++)
	      if(button_down[i]!=0)
	        button_count++;
		
	    if(button_count==1){
	      if(button_down[0]==1)      // up
		    direction[0]=1;
	      else if(button_down[1]==1) // down
		    direction[0]=2;
	      else if(button_down[2]==1) // left
		    direction[1]=3;
	      else if(button_down[3]==1)          // right
		    direction[1]=4;
	   }
	   else if(button_count==2)
	   {
	      if(button_down[0]==1 && button_down[3]==1)      //up & right
		    direction[0]=1,direction[1]=4;
	      else if(button_down[0]==1 && button_down[2]==1) //up & left
		    direction[0]=1,direction[1]=3;
	      else if(button_down[1]==1 && button_down[2]==1) //down & left
		    direction[0]=2,direction[1]=3;
	      else if(button_down[1]==1 && button_down[3]==1) //down & right
		    direction[0]=2,direction[1]=4;
		  else if(button_down[3]==1 && button_down[4]==1) //attack & right
		    direction[1]=4;
		  else if(button_down[2]==1 && button_down[4]==1) //attack & left
		    direction[1]=3;
	   }
}
void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor){	
	void **img = new void*[pn];
	int k=0, w=wa/wn, h=ha/hn;	
	setbkcolor(bkcolor);
	cleardevice();
    readimagefile( filename, 0, 0, wa-1, ha-1);
	int size = imagesize(0, 0, w-1, h-1);
	for (int i=0; i<hn; i++) {
		for (int j=0; j<wn; j++) {			
  			img[k] = malloc(size);  //allocate space in memory
  			getimage(w*j, h*i, w*(j+1)-1, h*(i+1)-1, img[k]);
  			k++;
  			if (k==pn)
  				break;
		}
		if (k==pn)
  				break;
	}
	return img;
}
void John::recordimage(){
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	disk_right_action_picture=getimage2(filename_disk_right_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	disk_left_action_picture=getimage2(filename_disk_left_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	disk_right_picture=getimage2(filename_disk_right,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	disk_left_picture=getimage2(filename_disk_left,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	ball_left_picture=getimage2(filename_ball_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
}
void John::print(){
        if(button_count==0&&direction[1]==4&&flag_disk_action==0&&flag_ball_action==0)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_disk_action==0&&flag_ball_action==0)//沒有動作且方向為左時 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_disk();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------移動指令
			if(flag_disk_action==0&&flag_ball_action==0){
				if(button_down[0]==1&&direction[1]==4){//上被按且方向為右 
					position_y-=10;
			    	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
				}
				else if(button_down[0]==1&&direction[1]==3){//上被按且方向為左 
					position_y-=10;
			    	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
				}
				else if(button_down[1]==1&&direction[1]==4){//下被按且方向為右 
					position_y+=10;
			    	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
				}
				else if(button_down[1]==1&&direction[1]==3){//下被按且方向為左
					position_y+=10;
			    	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
				}
				else if(button_down[2]==1){//左被按
					position_x-=10;
			    	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
				}
				else if(button_down[3]==1){//右被按 
					position_x+=10;
			    	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
				}
//--------------------------------------------------------------------------------------攻擊指令			
				if(button_down[4]==1&&direction[1]==4){//攻擊被按且方向為右 
			 	   putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
				}
				else if(button_down[4]==1&&direction[1]==3){//攻擊被按且方向為左 
				    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
				}
			} 			
//---------------------------------------------------------------------------------------			
		}
		if(button_count==2&&flag_disk_action==0&&flag_ball_action==0){
//------------------------------------------------------------------------------------移動指令 	
			if(button_down[0]==1&&button_down[2]==1){//同時按上左 
				position_x-=7;
				position_y-=7;
			    putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[3]==1){//同時按上右 
				position_x+=7;
				position_y-=7;
			    putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[2]==1){//同時按下左 
				position_x-=7;
				position_y+=7;
			    putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[3]==1){//同時按下右 
				position_x+=7;
				position_y+=7;
			    putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
//--------------------------------------------------------------------------------------攻擊指令
			if(button_down[0]==1&&button_down[4]==1&&direction[1]==3){//同時按上攻且方向為左
				position_y-=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[4]==1&&direction[1]==4){//同時按上攻且方向為右 
				position_y-=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&direction[1]==3){//同時按下攻且方向為左
				position_y+=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&direction[1]==4){//同時按下攻且方向為右 
				position_y+=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[2]==1&&button_down[4]==1){//同時按左攻 
				position_x-=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[3]==1&&button_down[4]==1){//同時按右攻 
				position_x+=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}

		}
		if(button_count==3){
			if(button_down[0]==1&&button_down[4]==1&&button_down[2]==1){//同時按上攻左
				position_y-=7;
				position_x-=7;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[4]==1&&button_down[3]==1){//同時按上攻右 
				position_y-=7;
				position_x+=7;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&button_down[2]==1){//同時按下攻左
				position_y+=7;
				position_x-=7;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&button_down[3]==1){//同時按下攻右 
				position_y+=7;
				position_x+=7;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
		}
//-------------------------------------------------------------------------------------------		
		if(flag_right==1&&button_down[4]==0)//沒按攻擊時的 picture_right_count
			picture_right_count=(++picture_right_count)%8;
		else
			picture_right_count=0;
			
		if(flag_left==1&&button_down[4]==0){//沒按攻擊時的 picture_left_count
			picture_left_count--;
			if(picture_left_count<2)
				picture_left_count=9;
		}
		else
			picture_left_count=9;
//---------------------------------------------------------------------------------------------
		if(flag_right==1&&button_down[4]==1){//有按攻擊時的 attack_right_count
			attack_right_count++;
			if(attack_right_count>13)
				attack_right_count=10;
		}
		else{
			attack_right_count=10;
		}
			
		if(flag_left==1&&button_down[4]==1){//有按攻擊時的 attack_left_count
			attack_left_count--;
			if(attack_left_count<16)
				attack_left_count=19;
		}
		else
			attack_left_count=19;
}
void John::print_disk(){
        if(flag_disk_action==1&&flag_disk_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(disk_right_action_count<=5){//若動作還沒做完 
				disk_right_count=0;
				disk_position_x=position_x;
				disk_position_y=position_y-21;
			   	putimage(position_x,position_y, disk_right_action_picture[disk_right_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
				disk_right_action_count++;
			}
			else if(disk_right_action_count>5){//若動作做完
				disk_right_action_count=0;
			   	flag_disk_action=0;
			}
		}
		else if(flag_disk_action==0&&flag_disk_right==1){
			disk_position_x+=40;
			putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
		}
			
		if(flag_disk_action==1&&flag_disk_left==1){//技能被按且方向為左(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(disk_left_action_count>=0){//若動作還沒做完 
				disk_left_count=11;
				disk_position_x=position_x;
				disk_position_y=position_y-21;
			   	putimage(position_x,position_y, disk_left_action_picture[disk_left_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
				disk_left_action_count--;
			}
			else if(disk_left_action_count<0){//若動作做完
				disk_left_action_count=5;
			   	flag_disk_action=0;
			}
		}
		else if(flag_disk_action==0&&flag_disk_left==1){
			disk_position_x-=40;
			putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
		}
		if(flag_disk_action==0&&flag_disk_right==1){//飛碟向右飛時的 disk_right_count
			disk_right_count=(++disk_right_count)%12;
			if(disk_right_count==0){
				disk_right_count=0;
				flag_disk_right=0;
			}
		}
		if(flag_disk_action==0&&flag_disk_left==1){//飛碟向左飛時的 disk_left_count
			disk_left_count--;
			if(disk_left_count==-1){
				disk_left_count=11;
				flag_disk_left=0;
			}
		}
}
void John::print_ball(){
        if(flag_ball_right==1){//技能被按且方向為右
			if(ball_right_action_count>=0&&flag_ball_action==1){//若動作還沒做完 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count--;
			}
			else if(ball_right_action_count<0){//若動作做完
				ball_right_action_count=3;
				flag_ball_action=0;
			}
			ball_position_x+=30;
			putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);		
		}
		
			
		if(flag_ball_left==1){//技能被按且方向為左 
			if(ball_left_action_count<=3&&flag_ball_action==1){//若動作還沒做完			
			   	putimage(position_x-30/*減30為了平移圖片*/,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
				ball_left_action_count++;
			}
			else if(ball_left_action_count>3){//若動作做完
				ball_left_action_count=0;
				flag_ball_action=0;
			}
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);	
		}
		
		if(flag_ball_right==1){//球向右飛時的 ball_right_count
			ball_right_count=(++ball_right_count)%4;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//球向左飛時的 ball_left_count
			ball_left_count--;
			if(ball_left_count==-1)
				ball_left_count=3;
			if(ball_position_x<=position_x-480){
				ball_left_count=3;
				flag_ball_left=0;
			}
		}
}
