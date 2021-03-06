#include"player.h"
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

void Player::set(int player)
{
	if(player==2){
		up1_key=0x26;//上 
		do1_key=0x28;//下 
		le1_key=0x25;//左 
		ri1_key=0x27;//右 
		at1_key=0xBF;///
		sk1_key=0xBA;//;
		position_x=500;//角色起始位置 
		position_y=200;//角色起始位置
		direction[1]=3;//圖片初始狀態 	
	}
	else if(player==1){
		up1_key=0x57;//w
		do1_key=0x53;//s
		le1_key=0x41;//a
		ri1_key=0x44;//d
		at1_key=0x43;//c
		sk1_key=0x46;//f
		position_x=200;//角色起始位置 
		position_y=200;//角色起始位置
		direction[1]=4;//圖片初始狀態 
	}
}
Player::Player(){
	wa_r=800;ha_r=560;pn_r=70;wn_r=10;hn_r=7;bkcolor_r=15;//往右移動圖檔切割數據
	wa_l=800;ha_l=560;pn_l=70;wn_l=10;hn_l=7;bkcolor_l=15;//往左移動圖檔切割數據
	
	wa_d_r_a=480;ha_d_r_a=80;pn_d_r_a=6;wn_d_r_a=6;hn_d_r_a=1;bkcolor_d_r_a=15;//往右投擲飛碟技能圖檔切割數據
	wa_d_l_a=480;ha_d_l_a=80;pn_d_l_a=6;wn_d_l_a=6;hn_d_l_a=1;bkcolor_d_l_a=15;//往左投擲飛碟技能圖檔切割數據

	wa_d_r=364;ha_d_r=64;pn_d_r=12;wn_d_r=4;hn_d_r=3;bkcolor_d_r=15;//往右飛碟技能圖檔切割數據
	wa_d_l=364;ha_d_l=64;pn_d_l=12;wn_d_l=4;hn_d_l=3;bkcolor_d_l=15;//往左飛碟技能圖檔切割數據	

	wa_b_r_a=440;ha_b_r_a=80;pn_b_r_a=4;wn_b_r_a=4;hn_b_r_a=1;bkcolor_b_r_a=15;//往右投擲球技能圖檔切割數據
	wa_b_l_a=440;ha_b_l_a=80;pn_b_l_a=4;wn_b_l_a=4;hn_b_l_a=1;bkcolor_b_l_a=15;//往左投擲球技能圖檔切割數據

	wa_b_r=324;ha_b_r=83;pn_b_r=4;wn_b_r=4;hn_b_r=1;bkcolor_b_r=15;//往右球技能圖檔切割數據
	wa_b_l=324;ha_b_l=83;pn_b_l=4;wn_b_l=4;hn_b_l=1;bkcolor_b_l=15;//往左球技能圖檔切割數據
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
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	down_right_count=30;//圖片初始狀態
	down_left_count=39;//圖片初始狀態
	defense_right_count=57;//圖片初始狀態
	defense_left_count=52;//圖片初始狀態
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
	position_x=100;//角色起始位置 
	position_y=500;//角色起始位置 
	disk_position_x=-1000;//飛碟起始位置  
	disk_position_y=-1000;//飛碟起始位置 
	ball_position_x=-1000;//球起始位置  
	ball_position_y=-1000;//球起始位置 
	manydisk_position_x=-1000;//飛碟起始位置  
	manydisk_position_y=-1000;//飛碟起始位置 
	manyball_position_x=-1000;//球起始位置  
	manyball_position_y=-1000;//球起始位置
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_down=0;//紀錄角色是否有被擊飛的初始狀態
	flag_defense=0;//紀錄角色是否有被揍的初始狀態
	flag_disk_action=0,flag_disk_right=0,flag_disk_left=0;//紀錄投擲飛碟動作是否做完的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲球動作是否做完的初始狀態 
	number_of_ball=0;//記錄球的個數 
	flag_manyball_remain=0;//紀錄前一顆球是否繼續存在 
	flag_ball_past=0;//球的左右狀態 
	flag_ball_record_receive=0;//記錄球是否被接收 
	number_of_disk=0;//記錄飛碟的個數 
	flag_manydisk_remain=0;//紀錄前一顆飛碟是否繼續存在 
	flag_disk_past=0;//飛碟的左右狀態 
	flag_disk_record_receive=0;//記錄飛碟是否被接收 
}
void Player::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Player::control(){
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
			
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_disk_right==0&&flag_ball_action==0&&number_of_disk<2
		&&flag_down==0&&flag_defense==0){//判斷飛碟出招情況 
			if(flag_manydisk_remain==1&&flag_disk_record_receive==0)
				skills_record();
			flag_disk_action=1;
			flag_disk_left=1;
			disk_position_x=disk_ori_position_x=position_x;//飛碟起始位置  
			disk_position_y=disk_ori_position_y=position_y-31;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_disk_left==0&&flag_ball_action==0&&number_of_disk<2
		&&flag_down==0&&flag_defense==0){//判斷飛碟出招情況 
			if(flag_manydisk_remain==1&&flag_disk_record_receive==0)
				skills_record();
			flag_disk_action=1;
			flag_disk_right=1;
			disk_position_x=disk_ori_position_x=position_x;//飛碟起始位置  
			disk_position_y=disk_ori_position_y=position_y-31;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_disk_action==0&&number_of_ball<2
		&&flag_down==0&&flag_defense==0){//判斷球出招情況 
			if(flag_manyball_remain==1&&flag_ball_record_receive==0)
				skills_record();
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=ball_ori_position_x=position_x-81+30;//球起始位置  
			ball_position_y=ball_ori_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_disk_action==0&&number_of_ball<2
		&&flag_down==0&&flag_defense==0){//判斷球出招情況 
			if(flag_manyball_remain==1&&flag_ball_record_receive==0)
				skills_record();
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=ball_ori_position_x=position_x+110-30;//球起始位置  
			ball_position_y=ball_ori_position_y=position_y+3;
			
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
void Player::recordimage(){
	picture_right=getimage2(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage2(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	disk_right_action_picture=getimage2(filename_disk_right_action,wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a);
	disk_left_action_picture=getimage2(filename_disk_left_action,wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a);
	disk_right_picture=getimage2(filename_disk_right,wa_d_r,ha_d_r,pn_d_r,wn_d_r,hn_d_r,bkcolor_d_r);
	disk_left_picture=getimage2(filename_disk_left,wa_d_l,ha_d_l,pn_d_l,wn_d_l,hn_d_l,bkcolor_d_l);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r);
	ball_left_picture=getimage2(filename_ball_left,wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l);
}
void Player::print(){
        if(button_count==0&&direction[1]==4&&flag_disk_action==0&&flag_ball_action==0&&flag_down==0&&flag_defense==0)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_disk_action==0&&flag_ball_action==0&&flag_down==0&&flag_defense==0)//沒有動作且方向為左時 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
        	
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_disk();
		print_manydisk();
		print_ball();
		print_manyball();
		if(flag_defense==0)
			print_down();
		if(flag_down==0)
			print_defense();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1&&flag_down==0&&flag_defense==0){
			
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
		if(button_count==2&&flag_disk_action==0&&flag_ball_action==0&&flag_down==0&&flag_defense==0){
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
		if(button_count==3&&flag_down==0&&flag_defense==0){
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
void Player::print_disk(){
        if(flag_disk_action==1&&flag_disk_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(disk_right_action_count<=5){//若動作還沒做完 
			   	putimage(position_x,position_y, disk_right_action_picture[disk_right_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
				disk_right_action_count++;
			}
			else if(disk_right_action_count>5){//若動作做完
				disk_right_action_count=0;
			   	flag_disk_action=0;
			   	number_of_disk++;
			}
		}
		else if(flag_disk_action==0&&flag_disk_right==1){
			disk_position_x+=40;
			putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
		}
			
		if(flag_disk_action==1&&flag_disk_left==1){//技能被按且方向為左(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(disk_left_action_count>=0){//若動作還沒做完 
			   	putimage(position_x,position_y, disk_left_action_picture[disk_left_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
				disk_left_action_count--;
			}
			else if(disk_left_action_count<0){//若動作做完
				disk_left_action_count=5;
			   	flag_disk_action=0;
			   	number_of_disk++;
			}
		}
		else if(flag_disk_action==0&&flag_disk_left==1){
			disk_position_x-=40;
			putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
		}
		if(flag_disk_action==0&&flag_disk_right==1){//飛碟向右飛時的 disk_right_count
			disk_right_count=(++disk_right_count)%12;
			flag_manydisk_remain=1;
			flag_disk_past=2;
			if(disk_position_x>=disk_ori_position_x+480){
				disk_right_count=0;
				flag_disk_right=0;
				flag_manydisk_remain=0;
				flag_disk_past=0;
				number_of_disk--;
				disk_position_x=-1000;
				disk_position_y=-1000;
			}
		}
		if(flag_disk_action==0&&flag_disk_left==1){//飛碟向左飛時的 disk_left_count
			disk_left_count--;
			if(disk_left_count==-1)
				disk_left_count=11;
			flag_manydisk_remain=1;
			flag_disk_past=1;
			if(disk_position_x<=disk_ori_position_x-480){
				disk_left_count=11;
				flag_disk_left=0;
				flag_manydisk_remain=0;
				flag_disk_past=0;
				number_of_disk--;
				disk_position_x=-1000;
				disk_position_y=-1000;
			}
		}
}
void Player::print_ball(){
        if(flag_ball_right==1){//技能被按且方向為右
			if(ball_right_action_count>=0&&flag_ball_action==1){//若動作還沒做完 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count--;
			}
			else if(ball_right_action_count<0){//若動作做完
				ball_right_action_count=3;
				flag_ball_action=0;
				number_of_ball++;
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
				number_of_ball++;
			}
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);	
		}
		if(flag_ball_right==1){//球向右飛時的 ball_right_count
			ball_right_count=(++ball_right_count)%4;
			flag_manyball_remain=1;
			flag_ball_past=2;
			if(ball_position_x>=ball_ori_position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
				flag_manyball_remain=0;
				flag_ball_past=0;
				number_of_ball--;
				ball_position_x=-1000;
				ball_position_y=-1000;
			}
		}
		if(flag_ball_left==1){//球向左飛時的 ball_left_count
			ball_left_count--;
			if(ball_left_count==-1)
				ball_left_count=3;
			flag_manyball_remain=1;
			flag_ball_past=1;
			if(ball_position_x<=ball_ori_position_x-480){
				ball_left_count=3;
				flag_ball_left=0;
				flag_manyball_remain=0;
				flag_ball_past=0;
				number_of_ball--;
				ball_position_x=-1000;
				ball_position_y=-1000;
			}
		}
}
void Player::skills_record(){
	if(number_of_ball>=1){
		if(flag_ball_past==1){
			manyball_left_count=ball_left_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;	
			last_manyball_position_x=ball_ori_position_x-480;
			flag_ball_record_receive=1;
		}
		if(flag_ball_past==2){
			manyball_right_count=ball_right_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;
			last_manyball_position_x=ball_ori_position_x+480;
			flag_ball_record_receive=1;
		}
	}
	
	if(number_of_disk>=1){
		if(flag_disk_past==1){
			manydisk_left_count=disk_left_count;
			manydisk_position_x=disk_position_x;
			manydisk_position_y=disk_position_y;	
			last_manydisk_position_x=disk_ori_position_x-480;
			flag_disk_record_receive=1;
		}
		if(flag_disk_past==2){
			manydisk_right_count=disk_right_count;
			manydisk_position_x=disk_position_x;
			manydisk_position_y=disk_position_y;
			last_manydisk_position_x=disk_ori_position_x+480;
			flag_disk_record_receive=1;
		}
	}
}
void Player::print_manyball(){
	if(flag_manyball_remain==1&&flag_ball_past==1&&number_of_ball>=1&&flag_ball_record_receive==1){
		if(manyball_position_x>=last_manyball_position_x){
			manyball_position_x-=30;
			putimage(manyball_position_x,manyball_position_y, ball_left_picture[manyball_left_count], OR_PUT);
			manyball_left_count--;
			if(manyball_left_count==-1){
				manyball_left_count=3;
			}
			if(manyball_position_x<last_manyball_position_x){//球向左飛時的 manyball_left_count
				flag_manyball_remain=0;
				number_of_ball--;
				flag_ball_record_receive=0;
				manyball_position_x=-1000;
				manyball_position_y=-1000;
			}			
		}
	} 
	if(flag_manyball_remain==1&&flag_ball_past==2&&number_of_ball>=1&&flag_ball_record_receive==1){
		if(manyball_position_x<=last_manyball_position_x){
			manyball_position_x+=30;
			putimage(manyball_position_x,manyball_position_y, ball_right_picture[manyball_right_count], OR_PUT);
			manyball_right_count=(++manyball_right_count)%4;
			if(manyball_position_x>last_manyball_position_x){//球向右飛時的 manyball_right_count
				flag_manyball_remain=0;
				number_of_ball--;
				flag_ball_record_receive=0;
				manyball_position_x=-1000;
				manyball_position_y=-1000;
			}			
		}
	}
	if(flag_manyball_remain==0)
		number_of_ball=0;
}
void Player::print_manydisk(){
	if(flag_manydisk_remain==1&&flag_disk_past==1&&number_of_disk>=1&&flag_disk_record_receive==1){
		if(manydisk_position_x>=last_manydisk_position_x){
			manydisk_position_x-=30;
			putimage(manydisk_position_x,manydisk_position_y, disk_left_picture[manydisk_left_count], OR_PUT);
			manydisk_left_count--;
			if(manydisk_left_count==-1){
				manydisk_left_count=11;
			}
			if(manydisk_position_x<last_manydisk_position_x){//球向左飛時的 manyball_left_count
				flag_manydisk_remain=0;
				number_of_disk--;
				flag_disk_record_receive=0;
				manydisk_position_x=-1000;
				manydisk_position_y=-1000;
			}			
		}	
	} 
	if(flag_manydisk_remain==1&&flag_disk_past==2&&number_of_disk>=1&&flag_disk_record_receive==1){
		if(manydisk_position_x<=last_manydisk_position_x){
			manydisk_position_x+=30;
			putimage(manydisk_position_x,manydisk_position_y, disk_right_picture[manydisk_right_count], OR_PUT);
			manydisk_right_count=(++manydisk_right_count)%12;
			if(manydisk_position_x>last_manydisk_position_x){//球向右飛時的 manyball_right_count
				flag_manydisk_remain=0;
				number_of_disk--;
				flag_disk_record_receive=0;
				manydisk_position_x=-1000;
				manydisk_position_y=-1000;
			}			
		}
	}
	if(flag_manydisk_remain==0)
		number_of_disk=0;
}
void Player::print_down(){
	if(flag_down==1&&direction[1]==4){//角色被擊倒且方向為右 
					position_x-=15;
			    	putimage(position_x,position_y, picture_right[down_right_count], OR_PUT);
			    	down_right_count++;
			    	if(down_right_count>35){
			    		down_right_count=30;
			    		flag_down=0;
					}
				}
	else if(flag_down==1&&direction[1]==3){//角色被擊倒且方向為左 
					position_x+=15;
			    	putimage(position_x,position_y, picture_left[down_left_count], OR_PUT);
			    	down_left_count--;
			    	if(down_left_count<34){
			    		down_left_count=39;
			    		flag_down=0;
					}
				}
}
void Player::print_defense(){
	if(flag_defense==1&&direction[1]==4){//角色被擊倒且方向為右 
					position_x-=5;
			    	putimage(position_x,position_y, picture_right[defense_right_count], OR_PUT);
			    	defense_right_count--;
			    	if(defense_right_count<53){
			    		defense_right_count=57;
			    		flag_defense=0;
					}
				}
	else if(flag_defense==1&&direction[1]==3){//角色被擊倒且方向為左 
					position_x+=5;
			    	putimage(position_x,position_y, picture_left[defense_left_count], OR_PUT);
			    	defense_left_count++;
			    	if(defense_left_count>56){
			    		defense_left_count=52;
			    		flag_defense=0;
					}
				}
}
void Player::getdata(int &p1_position_x,int &p1_position_y,int &p1_skill1_position_x,int &p1_skill1_position_y,int &p1_skill2_position_x,
int &p1_skill2_position_y,int &p1_manyskill1_position_x,int &p1_manyskill1_position_y,int &p1_manyskill2_position_x,int &p1_manyskill2_position_y,
int &p1_width,int &p1_height,int &p1_skill1_width,int &p1_skill1_height,int &p1_skill2_width,int &p1_skill2_height,
int &p1_button_down){
	p1_position_x=position_x;//角色目前位置 
	p1_position_y=position_y;//角色目前位置 
	p1_skill1_position_x=disk_position_x;//飛碟技能目前位置 
	p1_skill1_position_y=disk_position_y;//飛碟技能目前位置 
	p1_skill2_position_x=ball_position_x;//球技能目前位置 
	p1_skill2_position_y=ball_position_y;//球技能目前位置
	p1_manyskill1_position_x=manydisk_position_x;//額外飛碟技能目前位置 
	p1_manyskill1_position_y=manydisk_position_y;//額外飛碟技能目前位置
	p1_manyskill2_position_x=manyball_position_x;//額外球技能目前位置 
	p1_manyskill2_position_y=manyball_position_y;//額外球技能目前位置
	p1_width=wa_r/wn_r;p1_height=ha_r/hn_r;//角色長寬 
	p1_skill1_width=wa_d_r/wn_d_r;p1_skill1_height=ha_d_r/hn_d_r;//飛碟長寬 
	p1_skill2_width=wa_b_r/wn_b_r;p1_skill2_height=ha_b_r/hn_b_r;//球長寬 
	p1_button_down=button_down[4];
}
void Player::setdata(int down_switch,int defense_switch){
	if(down_switch==1)
		flag_down=1;
	if(defense_switch==1){
		flag_defense=1;
	}
}
