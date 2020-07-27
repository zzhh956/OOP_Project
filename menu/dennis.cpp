#include"john.h"
#include"dennis.h"
#include"davis.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up8_key;
int do8_key;
int le8_key;
int ri8_key;
int at8_key;
int sk8_key;

void Dennis::set(int player)
{
	if(player==2){
		up8_key=0x26;//上 
		do8_key=0x28;//下 
		le8_key=0x25;//左 
		ri8_key=0x27;//右 
		at8_key=0xBF;///
		sk8_key=0xBA;//;
		position_x=100;//角色起始位置 
		position_y=200;//角色起始位置 
	}
	else if(player==1){
		up8_key=0x57;//w
		do8_key=0x53;//s
		le8_key=0x41;//a
		ri8_key=0x44;//d
		at8_key=0x43;//c
		sk8_key=0x46;//f
		position_x=200;//角色起始位置 
		position_y=200;//角色起始位置  
	}
}
Dennis::Dennis(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//移動圖檔切割數據
	wa_d_a=800;ha_d_a=80;pn_d_a=10;wn_d_a=10;hn_d_a=1;bkcolor_d_a=15;//踢擊技能圖檔切割數據
	wa_b_a=640;ha_b_a=80;pn_b_a=8;wn_b_a=8;hn_b_a=1;bkcolor_b_a=15;//投擲球技能圖檔切割數據
	wa_b=328;ha_b=250;pn_b=12;wn_b=4;hn_b=3;bkcolor_b=15;//投擲球技能圖檔切割數據
//--------------------------------------------------------------------------------------存圖檔名稱 
	strcpy(filename_right,".\\roles_picture\\Dennis\\dennis_0.bmp");
	filename_right[strlen(".\\roles_picture\\Dennis\\dennis_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\Dennis\\dennis_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\Dennis\\dennis_0_mirror.bmp")]='\0';
//		
	strcpy(filename_kick_right_action,".\\roles_picture\\Dennis\\kick.bmp");
	filename_kick_right_action[strlen(".\\roles_picture\\Dennis\\kick.bmp")]='\0';

	strcpy(filename_kick_left_action,".\\roles_picture\\Dennis\\kick_mirror.bmp");
	filename_kick_left_action[strlen(".\\roles_picture\\Dennis\\kick_mirror.bmp")]='\0';	
//		
	strcpy(filename_ball_right_action,".\\roles_picture\\Dennis\\throw_chase.bmp");
	filename_ball_right_action[strlen(".\\roles_picture\\Dennis\\throw_chase.bmp")]='\0';

	strcpy(filename_ball_left_action,".\\roles_picture\\Dennis\\throw_chase_mirror.bmp");
	filename_ball_left_action[strlen(".\\roles_picture\\Dennis\\throw_chase_mirror.bmp")]='\0';	
//
	strcpy(filename_ball_right,".\\roles_picture\\Dennis\\dennis_chase.bmp");
	filename_ball_right[strlen(".\\roles_picture\\Dennis\\dennis_chase.bmp")]='\0';	

	strcpy(filename_ball_left,".\\roles_picture\\Dennis\\dennis_chase_mirror.bmp");
	filename_ball_left[strlen(".\\roles_picture\\Dennis\\dennis_chase_mirror.bmp")]='\0';	
//-----------------------------------------------------------------------------------------
	direction[1]=4;//圖片初始狀態 
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	attack_right_count=10;//圖片初始狀態
	attack_left_count=19;//圖片初始狀態
	kick_right_action_count=0;//往右踢擊圖片初始狀態
	kick_left_action_count=9;//往左踢擊圖片初始狀態
	ball_right_action_count=0;//往右投擲球圖片初始狀態
	ball_left_action_count=7;//往左投擲球圖片初始狀態
	ball_right_count=0;//球圖片初始狀態
	ball_left_count=3;//球圖片初始狀態
	ball_position_x=position_x+110;//投擲球起始位置  
	ball_position_y=position_y+3;//投擲球起始位置 
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_kick_action_right=0, flag_kick_action_left=0;//紀錄踢擊動作是否做完的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲投擲球動作是否做完的初始狀態
}
void Dennis::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Dennis::control(){
	    if(GetAsyncKeyState(up8_key)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(do8_key)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(le8_key)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(ri8_key)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(at8_key)==0) button_down[4]=0;//攻 
        if(GetAsyncKeyState(sk8_key)==0) button_down[5]=0;//技能 
        
        if(GetAsyncKeyState(up8_key)!=0) button_down[0]=1;//上 
        if(GetAsyncKeyState(do8_key)!=0) button_down[1]=1;//下 
        if(GetAsyncKeyState(le8_key)!=0) button_down[2]=1;//左 
        if(GetAsyncKeyState(ri8_key)!=0) button_down[3]=1;//右 
        if(GetAsyncKeyState(at8_key)!=0) button_down[4]=1;//攻 
        if(GetAsyncKeyState(sk8_key)!=0) button_down[5]=1;//技能 
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
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_kick_action_right==0)//判斷踢擊出招情況 
			flag_kick_action_left=1;					
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_kick_action_left==0)//判斷踢擊出招情況 
			flag_kick_action_right=1;
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_kick_action_right==0){//判斷投擲球出招情況 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//投擲球起始位置  
			ball_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_kick_action_left==0){//判斷投擲球出招情況 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//投擲球起始位置  
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
void Dennis::recordimage(){
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	kick_right_action_picture=getimage2(filename_kick_right_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	kick_left_action_picture=getimage2(filename_kick_left_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	ball_left_picture=getimage2(filename_ball_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
}
void Dennis::print(){
        if(button_count==0&&direction[1]==4&&flag_kick_action_right==0&&flag_ball_action==0)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_kick_action_left==0&&flag_ball_action==0)//沒有動作且方向為左時 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_kick();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------移動指令
			if(flag_kick_action_left==0&&flag_kick_action_right==0&&flag_ball_action==0){
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
//-------------------------------------------------------------------------------------			
		}
		if(button_count==2&&flag_kick_action_left==0&&flag_kick_action_right==0&&flag_ball_action==0){
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
		else
			attack_right_count=10;
			
		if(flag_left==1&&button_down[4]==1){//有按攻擊時的 attack_left_count
			attack_left_count--;
			if(attack_left_count<16)
				attack_left_count=19;
		}
		else
			attack_left_count=19;
}
void Dennis::print_kick(){
        if(flag_kick_action_right==1){//技能被按且方向為右(動作部分)(角色只會做這踢擊動作，按其他按鍵會無反應)
			if(kick_right_action_count<=9){//若動作還沒做完 
			   	position_x+=20;
				putimage(position_x,position_y-20, kick_right_action_picture[kick_right_action_count], OR_PUT);
				kick_right_action_count++;
				if(kick_right_action_count>9){
					kick_right_action_count=0;
					flag_kick_action_right=0;
				}
			}
		}
		if(flag_kick_action_left==1){//技能被按且方向為左(動作部分)(角色只會做這踢擊動作，按其他按鍵會無反應)
			if(kick_left_action_count>=0){//若動作還沒做完 
				position_x-=20;
			   	putimage(position_x,position_y-20, kick_left_action_picture[kick_left_action_count], OR_PUT);
				kick_left_action_count--;
				if(kick_left_action_count<0){
					kick_left_action_count=9;
					flag_kick_action_left=0;
				}
			}
		} 
}
int v_dennis=0;
void Dennis::print_ball(){
	if(flag_ball_action==1&&flag_ball_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲球動作，按其他按鍵會無反應)
		if(ball_right_action_count<=7){//若動作還沒做完 				
		   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
			ball_right_action_count++;
		}		
		else if(ball_right_action_count>7){//若動作做完
			ball_right_action_count=0;
			flag_ball_action=0;
		}
	}
	else if(flag_ball_action==0&&flag_ball_right==1){
		ball_position_x+=30+v_dennis;
		putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		ball_right_count++;
		if(ball_right_count==4)
			ball_right_count=8;
		if(ball_right_count==12){
			flag_ball_right=0;
			ball_right_count=0;
			v_dennis=0;
		}
		v_dennis+=4;
	}
	if(flag_ball_action==1&&flag_ball_left==1){//技能被按且方向為左(動作部分)(角色只會做這投擲球動作，按其他按鍵會無反應)
		if(ball_left_action_count>=0){//若動作還沒做完 
		   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
			ball_left_action_count--;
		}		
		else if(ball_left_action_count<0){//若動作做完
			ball_left_action_count=7;
			flag_ball_action=0;
		}
	}
	else if(flag_ball_action==0&&flag_ball_left==1){
		ball_position_x-=30+v_dennis;
		putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		ball_left_count--;
		if(ball_left_count==-1)
			ball_left_count=11;
		if(ball_left_count==7){
			ball_left_count=3;
			flag_ball_left=0;
			v_dennis=0;
		}
		v_dennis+=4;
	}
}
