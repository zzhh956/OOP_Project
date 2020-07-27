#include"julian.h"
#include"player.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void Julian::Julian_set(int player)
{
	if(player==1){
		int up2_key=0x26;//上 
		int do2_key=0x28;//下 
		int le2_key=0x25;//左 
		int ri2_key=0x27;//右 
		int at2_key=0xBF;///
		int sk2_key=0xBA;//;
	}
	else if(player==2){
		int	up2_key=0x57;//w
		int	do2_key=0x53;//s
		int	le2_key=0x41;//a
		int	ri2_key=0x44;//d
		int	at2_key=0x43;//c
		int	sk2_key=0x46;//f
	}
}

Julian::Julian(
char *receive_file_right,char *receive_file_left,int wa_R,int ha_R,int pn_R,
int wn_R,int hn_R,int bkcolor_R,int wa_L,int ha_L,int pn_L,int wn_L,int hn_L,int bkcolor_L,

char *receive_file_ball_right_action_picture,char *receive_file_ball_left_action_picture,int wa_B_R_A,int ha_B_R_A,int pn_B_R_A,
int wn_B_R_A,int hn_B_R_A,int bkcolor_B_R_A,int wa_B_L_A,int ha_B_L_A,int pn_B_L_A,int wn_B_L_A,int hn_B_L_A,int bkcolor_B_L_A,

char *receive_file_ball_right_picture,char *receive_file_ball_left_picture,int wa_B_R,int ha_B_R,int pn_B_R,
int wn_B_R,int hn_B_R,int bkcolor_B_R,int wa_B_L,int ha_B_L,int pn_B_L,int wn_B_L,int hn_B_L,int bkcolor_B_L,

char *receive_file_power_right_action_picture,char *receive_file_power_left_action_picture,int wa_P_R_A,int ha_P_R_A,int pn_P_R_A,
int wn_P_R_A,int hn_P_R_A,int bkcolor_P_R_A,int wa_P_L_A,int ha_P_L_A,int pn_P_L_A,int wn_P_L_A,int hn_P_L_A,int bkcolor_P_L_A,

char *receive_file_power_right_picture,char *receive_file_power_left_picture,int wa_P_R,int ha_P_R,int pn_P_R,
int wn_P_R,int hn_P_R,int bkcolor_P_R,int wa_P_L,int ha_P_L,int pn_P_L,int wn_P_L,int hn_P_L,int bkcolor_P_L
,int player
){
	wa_r=wa_R;ha_r=ha_R;pn_r=pn_R;wn_r=wn_R;hn_r=hn_R;bkcolor_r=bkcolor_R;//往右移動圖檔切割數據
	wa_l=wa_L;ha_l=ha_L;pn_l=pn_L;wn_l=wn_L;hn_l=hn_L;bkcolor_l=bkcolor_L;//往左移動圖檔切割數據
	
	wa_b_r_a=wa_B_R_A;ha_b_r_a=ha_B_R_A;pn_b_r_a=pn_B_R_A;wn_b_r_a=wn_B_R_A;hn_b_r_a=hn_B_R_A;bkcolor_b_r_a=bkcolor_B_R_A;//往右投擲球技能圖檔切割數據
	wa_b_l_a=wa_B_L_A;ha_b_l_a=ha_B_L_A;pn_b_l_a=pn_B_L_A;wn_b_l_a=wn_B_L_A;hn_b_l_a=hn_B_L_A;bkcolor_b_l_a=bkcolor_B_L_A;//往左投擲球技能圖檔切割數據

	wa_b_r=wa_B_R;ha_b_r=ha_B_R;pn_b_r=pn_B_R;wn_b_r=wn_B_R;hn_b_r=hn_B_R;bkcolor_b_r=bkcolor_B_R;//往右球技能圖檔切割數據
	wa_b_l=wa_B_L;ha_b_l=ha_B_L;pn_b_l=pn_B_L;wn_b_l=wn_B_L;hn_b_l=hn_B_L;bkcolor_b_l=bkcolor_B_L;//往左球技能圖檔切割數據
	
	wa_p_r_a=wa_P_R_A;ha_p_r_a=ha_P_R_A;pn_p_r_a=pn_P_R_A;wn_p_r_a=wn_P_R_A;hn_p_r_a=hn_P_R_A;bkcolor_p_r_a=bkcolor_P_R_A;//往右做出爆發技能圖檔切割數據
	wa_p_l_a=wa_P_L_A;ha_p_l_a=ha_P_L_A;pn_p_l_a=pn_P_L_A;wn_p_l_a=wn_P_L_A;hn_p_l_a=hn_P_L_A;bkcolor_p_l_a=bkcolor_P_L_A;//往左做出爆發技能圖檔切割數據

	wa_p_r=wa_P_R;ha_p_r=ha_P_R;pn_p_r=pn_P_R;wn_p_r=wn_P_R;hn_p_r=hn_P_R;bkcolor_p_r=bkcolor_P_R;//往右爆發技能圖檔切割數據
	wa_p_l=wa_P_L;ha_p_l=ha_P_L;pn_p_l=pn_P_L;wn_p_l=wn_P_L;hn_p_l=hn_P_L;bkcolor_p_l=bkcolor_P_L;//往左爆發技能圖檔切割數據	
//--------------------------------------------------------------------------------------存圖檔名稱 	
	strcpy(filename_right,receive_file_right);
	filename_right[strlen(receive_file_right)]='\0';

	strcpy(filename_left,receive_file_left);
	filename_left[strlen(receive_file_left)]='\0';
//	
	strcpy(filename_ball_right_action,receive_file_ball_right_action_picture);
	filename_ball_right_action[strlen(receive_file_ball_right_action_picture)]='\0';

	strcpy(filename_ball_left_action,receive_file_ball_left_action_picture);
	filename_ball_left_action[strlen(receive_file_ball_left_action_picture)]='\0';	
//
	strcpy(filename_ball_right,receive_file_ball_right_picture);
	filename_ball_right[strlen(receive_file_ball_right_picture)]='\0';	

	strcpy(filename_ball_left,receive_file_ball_left_picture);
	filename_ball_left[strlen(receive_file_ball_left_picture)]='\0';
//		
	strcpy(filename_power_right_action,receive_file_power_right_action_picture);
	filename_power_right_action[strlen(receive_file_power_right_action_picture)]='\0';

	strcpy(filename_power_left_action,receive_file_power_left_action_picture);
	filename_power_left_action[strlen(receive_file_power_left_action_picture)]='\0';	
//
	strcpy(filename_power_right,receive_file_power_right_picture);
	filename_power_right[strlen(receive_file_power_right_picture)]='\0';	

	strcpy(filename_power_left,receive_file_power_left_picture);
	filename_power_left[strlen(receive_file_power_left_picture)]='\0';	
//----------------------------------------------------------------------------------------------
	direction[1]=3;//圖片初始狀態
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	attack_right_count=10;//圖片初始狀態
	attack_left_count=19;//圖片初始狀態	
	ball_right_action_count=0;//往右投擲球圖片初始狀態
	ball_left_action_count=5;//往左投擲球圖片初始狀態
	ball_right_count=0;//球圖片初始狀態
	ball_left_count=1;//球圖片初始狀態
	power_right_action_count=0;//往右做出爆發技能圖片初始狀態
	power_left_action_count=2;//往左做出爆發技能圖片初始狀態
	power_right_count=0;//爆發技能圖片初始狀態
	power_left_count=3;//爆發技能圖片初始狀態
	if(player==1)
		position_x=100;//角色起始位置 
		position_y=500;//角色起始位置 
	else if(player==2)
		position_x=500;//角色起始位置 
		position_y=500;//角色起始位置 
	ball_position_x=position_x+80;//球起始位置  
	ball_position_y=position_y+10;//球起始位置
	power_position_x=position_x-60;//爆發技能起始位置  
	power_position_y=position_y-305;//爆發技能起始位置
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲球動作是否做完的初始狀態 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//紀錄爆發技能動作是否做完的初始狀態
	Julian_set(player);
}
void Julian::control(){
		if(GetAsyncKeyState(up2_key)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(do2_key)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(le2_key)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(ri2_key)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(at2_key)==0) button_down[4]=0;//攻 
        if(GetAsyncKeyState(sk2_key)==0) button_down[5]=0;//技能 
        
        if(GetAsyncKeyState(up2_key)!=0) button_down[0]=1;//上 
        if(GetAsyncKeyState(do2_key)!=0) button_down[1]=1;//下 
        if(GetAsyncKeyState(le2_key)!=0) button_down[2]=1;//左 
        if(GetAsyncKeyState(ri2_key)!=0) button_down[3]=1;//右 
        if(GetAsyncKeyState(at2_key)!=0) button_down[4]=1;//攻 
        if(GetAsyncKeyState(sk2_key)!=0){ button_down[5]=1;}//技能 
        
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
			
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_power_action==0){//判斷球出招情況 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-109+30;//球起始位置  
			ball_position_y=position_y+10;
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_power_action==0){//判斷球出招情況 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+80-30;//球起始位置  
			ball_position_y=position_y+10;
		}
		
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_power_right==0&&flag_ball_action==0){//判斷爆發技能出招情況 
			flag_power_action=1;
			flag_power_left=1;
			power_position_x=position_x-60;//爆發技能起始位置  
			power_position_y=position_y-305+15;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_power_left==0&&flag_ball_action==0){//判斷爆發技能出招情況 
			flag_power_action=1;
			flag_power_right=1;
			power_position_x=position_x-60;//爆發技能起始位置  
			power_position_y=position_y-305+15;
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
void Julian::recordimage(){
	picture_right=getimage2(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage2(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r);
	ball_left_picture=getimage2(filename_ball_left,wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l);
	power_right_action_picture=getimage2(filename_power_right_action,wa_p_r_a,ha_p_r_a,pn_p_r_a,wn_p_r_a,hn_p_r_a,bkcolor_p_r_a);
	power_left_action_picture=getimage2(filename_power_left_action,wa_p_l_a,ha_p_l_a,pn_p_l_a,wn_p_l_a,hn_p_l_a,bkcolor_p_l_a);
	power_right_picture=getimage2(filename_power_right,wa_p_r,ha_p_r,pn_p_r,wn_p_r,hn_p_r,bkcolor_p_r);
	power_left_picture=getimage2(filename_power_left,wa_p_l,ha_p_l,pn_p_l,wn_p_l,hn_p_l,bkcolor_p_l);
}
void Julian::print(){
		if(button_count==0&&direction[1]==4&&flag_ball_action==0&&flag_power_action==0)//沒有動作且方向為右時 
        		putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
    	else if(button_count==0&&direction[1]==3&&flag_ball_action==0&&flag_power_action==0){//沒有動作且方向為左時 
        		putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
    	}
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_ball();
		print_power(); 
//------------------------------------------------------------------------------------------------   	
		if(button_count==1&&flag_ball_action==0&&flag_power_action==0){
//------------------------------------------------------------------------------------移動指令
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
		if(button_count==2&&flag_ball_action==0&&flag_power_action==0){
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
void Julian::print_ball(){
        if(flag_ball_action==1&&flag_ball_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(ball_right_action_count<=5){//若動作還沒做完 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count++;
			}
			else if(ball_right_action_count>5){//若動作做完
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
				ball_left_action_count=5;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_left==1){
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		}
		if(flag_ball_right==1){//球向右飛時的 ball_right_count
			ball_right_count=(++ball_right_count)%2;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//球向左飛時的 ball_left_count
			ball_left_count--;
			if(ball_left_count==-1){
				ball_left_count=1;
			}
			if(ball_position_x<=position_x-480){
				ball_left_count=1;
				flag_ball_left=0;
			}
		}
}
void Julian::print_power(){
		if(flag_power_right==1){//技能被按且方向為右
			if(power_right_action_count<=2){//若動作還沒做完 				
			   	putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				power_right_action_count++;
			}
			if(power_right_action_count>2)		
				putimage(power_position_x,power_position_y, power_right_picture[power_right_count], OR_PUT);	
		}	
		if(flag_power_left==1){//技能被按且方向為左 
			if(power_left_action_count>=0){//若動作還沒做完			
			   	putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				power_left_action_count--;
			}
			if(power_left_action_count<0)
				putimage(power_position_x,power_position_y, power_left_picture[power_left_count], OR_PUT);
		}
		
		if(flag_power_right==1&&power_right_action_count>2){//爆發技能向右時的 power_right_count
			power_right_count=(++power_right_count)%4;
			if(power_right_count==0){
				flag_power_right=0;
				flag_power_action=0;
				power_right_action_count=0;
			}
		}
		if(flag_power_left==1&&power_left_action_count<0){//爆發技能向左時的 power_left_count
			power_left_count--;
			if(power_left_count==-1)
				power_left_count=3;
			if(power_left_count==3){
				flag_power_left=0;
				flag_power_action=0;
				power_left_action_count=2;
			}
		}
}
void Julian::skills_record(int number_of_ball){
	if(number_of_ball>1){
		if(flag_ball_past==1){
			manyball_left_count=ball_left_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;	
		}
		if(flag_ball_left==2){
			manyball_right_count=ball_right_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;
		}
	}
}
void Julian::print_manyball(){
	if(flag_many_ball_remain==1&&flag_ball_past==1);
	if(flag_many_ball_remain==1&&flag_ball_past==2);
}
