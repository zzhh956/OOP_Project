#include"john.h"
#include"firen.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up4_key;
int do4_key;
int le4_key;
int ri4_key;
int at4_key;
int sk4_key;

void Firen::set(int player){
	if(player==2){
		up4_key=0x26;//上 
		do4_key=0x28;//下 
		le4_key=0x25;//左 
		ri4_key=0x27;//右 
		at4_key=0xBF;///
		sk4_key=0xBA;//;
		position_x=100;//角色起始位置 
		position_y=200;//角色起始位置 
	}
	else if(player==1){
		up4_key=0x57;//w
		do4_key=0x53;//s
		le4_key=0x41;//a
		ri4_key=0x44;//d
		at4_key=0x43;//c
		sk4_key=0x46;//f
		position_x=200;//角色起始位置 
		position_y=200;//角色起始位置 
	}
}
Firen::Firen(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//往右移動圖檔切割數據	
	wa_d_a=400;ha_d_a=160;pn_d_a=10;wn_d_a=5;hn_d_a=2;bkcolor_d_a=15;//往右爆發技能圖檔切割數據
	wa_d=800;ha_d=480;pn_d=15;wn_d=5;hn_d=3;bkcolor_d=15;//往右爆炸技能圖檔切割數據
	wa_b_a=400;ha_b_a=80;pn_b_a=5;wn_b_a=5;hn_b_a=1;bkcolor_b_a=15;//往右吐火焰技能圖檔切割數據
	wa_b=328;ha_b=249;pn_b=12;wn_b=4;hn_b=3;bkcolor_b=15;//往右火焰技能圖檔切割數據
//--------------------------------------------------------------------------------------存圖檔名稱 
	strcpy(filename_right,".\\roles_picture\\Firen\\firen_0.bmp");
	filename_right[strlen(".\\roles_picture\\Firen\\firen_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\Firen\\firen_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\Firen\\firen_0_mirror.bmp")]='\0';
//		
	strcpy(filename_power_right_action,".\\roles_picture\\Firen\\exp.bmp");
	filename_power_right_action[strlen(".\\roles_picture\\Firen\\exp.bmp")]='\0';

	strcpy(filename_power_left_action,".\\roles_picture\\Firen\\exp_mirror.bmp");
	filename_power_left_action[strlen(".\\roles_picture\\Firen\\exp_mirror.bmp")]='\0';	
//
	strcpy(filename_power_right,".\\roles_picture\\Firen\\firen_exp.bmp");
	filename_power_right[strlen(".\\roles_picture\\Firen\\firen_exp.bmp")]='\0';	

	strcpy(filename_power_left,".\\roles_picture\\Firen\\firen_exp_mirror.bmp");
	filename_power_left[strlen(".\\roles_picture\\Firen\\firen_exp_mirror.bmp")]='\0';
//		
	strcpy(filename_ball_right_action,".\\roles_picture\\Firen\\throw_ball.bmp");
	filename_ball_right_action[strlen(".\\roles_picture\\Firen\\throw_ball.bmp")]='\0';

	strcpy(filename_ball_left_action,".\\roles_picture\\Firen\\throw_ball_mirror.bmp");
	filename_ball_left_action[strlen(".\\roles_picture\\Firen\\throw_ball_mirror.bmp")]='\0';	
//
	strcpy(filename_ball_right,".\\roles_picture\\Firen\\firen_ball.bmp");
	filename_ball_right[strlen(".\\roles_picture\\Firen\\firen_ball.bmp")]='\0';	

	strcpy(filename_ball_left,".\\roles_picture\\Firen\\firen_ball_mirror.bmp");
	filename_ball_left[strlen(".\\roles_picture\\Firen\\firen_ball_mirror.bmp")]='\0';	
//-----------------------------------------------------------------------------------------
	direction[1]=4;//圖片初始狀態 
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	attack_right_count=10;//圖片初始狀態
	attack_left_count=19;//圖片初始狀態
	power_right_action_count=0;//往右爆發圖片初始狀態
	power_left_action_count=4;//往左爆發圖片初始狀態
	power_right_count=0;//爆炸圖片初始狀態
	power_left_count=4;//爆炸圖片初始狀態
	ball_right_action_count=0;//往右吐火焰圖片初始狀態
	ball_left_action_count=4;//往左吐火焰圖片初始狀態
	ball_right_count=0;//火焰圖片初始狀態
	ball_left_count=3;//火焰圖片初始狀態
	power_position_x=position_x;//爆炸起始位置  
	power_position_y=position_y-21;//爆炸起始位置 
	ball_position_x=position_x+110;//火焰起始位置  
	ball_position_y=position_y+3;//火焰起始位置 
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//紀錄爆發動作是否做完的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄吐火焰動作是否做完的初始狀態
}
void Firen::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Firen::control(){
	    if(GetAsyncKeyState(up4_key)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(do4_key)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(le4_key)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(ri4_key)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(at4_key)==0) button_down[4]=0;//攻 
        if(GetAsyncKeyState(sk4_key)==0) button_down[5]=0;//技能 
        
        if(GetAsyncKeyState(up4_key)!=0) button_down[0]=1;//上 
        if(GetAsyncKeyState(do4_key)!=0) button_down[1]=1;//下 
        if(GetAsyncKeyState(le4_key)!=0) button_down[2]=1;//左 
        if(GetAsyncKeyState(ri4_key)!=0) button_down[3]=1;//右 
        if(GetAsyncKeyState(at4_key)!=0) button_down[4]=1;//攻 
        if(GetAsyncKeyState(sk4_key)!=0) button_down[5]=1;//技能 
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
			
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_power_right==0&&flag_ball_action==0){//判斷爆炸出招情況 
			flag_power_action=1;
			flag_power_left=1;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_power_left==0&&flag_ball_action==0){//判斷爆炸出招情況 
			flag_power_action=1;
			flag_power_right=1;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_power_action==0){//判斷火焰出招情況 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//火焰起始位置  
			ball_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_power_action==0){//判斷火焰出招情況 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//火焰起始位置  
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
void Firen::recordimage(){
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	power_right_action_picture=getimage2(filename_power_right_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	power_left_action_picture=getimage2(filename_power_left_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	power_right_picture=getimage2(filename_power_right,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	power_left_picture=getimage2(filename_power_left,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	ball_left_picture=getimage2(filename_ball_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
}
void Firen::print(){
        if(button_count==0&&direction[1]==4&&flag_power_action==0&&flag_ball_action==0)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_power_action==0&&flag_ball_action==0)//沒有動作且方向為左時 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_power();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------移動指令
			if(flag_power_action==0&&flag_ball_action==0){
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
		if(button_count==2&&flag_power_action==0&&flag_ball_action==0){
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
int right = 0, left = 0;

void Firen::print_power(){
		if(flag_power_right==1){//技能被按且方向為右
			if(right==1){
				power_right_action_count=9;
				right = 0;
			}
			if(power_right_action_count<4){//若動作還沒做完 				
				putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				power_right_action_count++;
			}
			else if(power_right_action_count==4){
				putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				putimage(position_x-33,position_y-70, power_right_picture[power_right_count], OR_PUT);
				power_right_count++;
				if(power_right_count==11)
					right = 1;
			}
			else if(power_right_action_count<=9 && power_right_action_count>7){
				putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				power_right_action_count--;
			}
			else{
				flag_power_right=0;
				flag_power_action=0;
				power_right_action_count=0;
				power_right_count=0;
			}
		}
		if(flag_power_left==1){//技能被按且方向為左 
			if(left==1){
				power_left_action_count=5;
				left = 0;
			}
			if(power_left_action_count<5 && power_left_action_count>0){//若動作還沒做完			
				putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				power_left_action_count--;
			}
			else if(power_left_action_count==0){
				putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				if(power_left_count<0)
					power_left_count=9;
				if(power_left_count==5)
					power_left_count=14;
				putimage(position_x-33,position_y-70, power_left_picture[power_left_count], OR_PUT);
				power_left_count--;
				if(power_left_count==13)
					left = 1;
			}
			else if(power_left_action_count>=5 && power_left_action_count<7){
				putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				power_left_action_count++;
			}
			else{
				flag_power_left=0;
				flag_power_action=0;
				power_left_action_count=4;
				power_left_count=4;
			}
		}
}
void Firen::print_ball(){
    if(flag_ball_action==1&&flag_ball_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(ball_right_action_count<=4){//若動作還沒做完 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count++;
			}
			else if(ball_right_action_count>4){//若動作做完
				ball_right_action_count=0;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_right==1){
			ball_position_x+=30;
			putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		}
			
		if(flag_ball_action==1&&flag_ball_left==1){//技能被按且方向為左(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(ball_left_action_count>=0){//若動作還沒做完 
			   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
				ball_left_action_count--;
			}
			else if(ball_left_action_count<0){//若動作做完
				ball_left_action_count=4;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_left==1){
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		}
		if(flag_ball_right==1){//球向右飛時的 ball_right_count
			ball_right_count=(++ball_right_count)%6;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//球向左飛時的 ball_left_count
			ball_left_count--;
			if(ball_left_count==-1)
				ball_left_count=7;
			if(ball_left_count==5)
				ball_left_count=3;
			if(ball_position_x<=position_x-480){
				ball_left_count=3;
				flag_ball_left=0;
			}
		}
}
