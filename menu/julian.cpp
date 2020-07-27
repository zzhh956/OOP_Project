#include"john.h"
#include"julian.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up2_key;
int do2_key;
int le2_key;
int ri2_key;
int at2_key;
int sk2_key;

void Julian::set(int player){
	if(player==2){
		up2_key=0x26;//上 
		do2_key=0x28;//下 
		le2_key=0x25;//左 
		ri2_key=0x27;//右 
		at2_key=0xBF;///
		sk2_key=0xBA;//;
		position_x=500;//角色起始位置 
		position_y=200;//角色起始位置 
	}
	else if(player==1){
		up2_key=0x57;//w
		do2_key=0x53;//s
		le2_key=0x41;//a
		ri2_key=0x44;//d
		at2_key=0x43;//c
		sk2_key=0x46;//f
		position_x=200;//角色起始位置 
		position_y=200;//角色起始位置 	
	}
}
Julian::Julian(){
	wa=800;ha=500;pn=50;wn=10;hn=5;bkcolor=15;//移動圖檔切割數據
	wa_b_a=480;ha_b_a=100;pn_b_a=6;wn_b_a=6;hn_b_a=1;bkcolor_b_a=15;//投擲球技能圖檔切割數據
	wa_b=218;ha_b=99;pn_b=2;wn_b=2;hn_b=1;bkcolor_b=15;//球技能圖檔切割數據
	wa_p_a=240;ha_p_a=100;pn_p_a=3;wn_p_a=3;hn_p_a=1;bkcolor_p_a=15;//做出爆發技能圖檔切割數據
	wa_p=800;ha_p=405;pn_p=4;wn_p=4;hn_p=1;bkcolor_p=15;//爆發技能圖檔切割數據
//--------------------------------------------------------------------------------------存圖檔名稱 	
	strcpy(filename_right,".\\roles_picture\\Julian\\julian_0.bmp");
	filename_right[strlen(".\\roles_picture\\Julian\\julian_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\Julian\\julian_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\Julian\\julian_0_mirror.bmp")]='\0';
//	
	strcpy(filename_ball_right_action,".\\roles_picture\\Julian\\qi_1.bmp");
	filename_ball_right_action[strlen(".\\roles_picture\\Julian\\qi_1.bmp")]='\0';

	strcpy(filename_ball_left_action,".\\roles_picture\\Julian\\qi_1_mirror.bmp");
	filename_ball_left_action[strlen(".\\roles_picture\\Julian\\qi_1_mirror.bmp")]='\0';	
//
	strcpy(filename_ball_right,".\\roles_picture\\Julian\\julian_ball2_1.bmp");
	filename_ball_right[strlen(".\\roles_picture\\Julian\\julian_ball2_1.bmp")]='\0';	

	strcpy(filename_ball_left,".\\roles_picture\\Julian\\julian_ball2_mirror_1.bmp");
	filename_ball_left[strlen(".\\roles_picture\\Julian\\julian_ball2_mirror_1.bmp")]='\0';
//		
	strcpy(filename_power_right_action,".\\roles_picture\\Julian\\qi_2.bmp");
	filename_power_right_action[strlen(".\\roles_picture\\Julian\\qi_2.bmp")]='\0';

	strcpy(filename_power_left_action,".\\roles_picture\\Julian\\qi_2_mirror.bmp");
	filename_power_left_action[strlen(".\\roles_picture\\Julian\\qi_2_mirror.bmp")]='\0';	
//
	strcpy(filename_power_right,".\\roles_picture\\Julian\\julian_col.bmp");
	filename_power_right[strlen(".\\roles_picture\\Julian\\julian_col.bmp")]='\0';	

	strcpy(filename_power_left,".\\roles_picture\\Julian\\julian_col_mirror.bmp");
	filename_power_left[strlen(".\\roles_picture\\Julian\\julian_col_mirror.bmp")]='\0';	
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
	ball_position_x=position_x+80;//球起始位置  
	ball_position_y=position_y+10;//球起始位置
	power_position_x=position_x-60;//爆發技能起始位置  
	power_position_y=position_y-305;//爆發技能起始位置
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲球動作是否做完的初始狀態 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//紀錄爆發技能動作是否做完的初始狀態
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
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	ball_left_picture=getimage2(filename_ball_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	power_right_action_picture=getimage2(filename_power_right_action,wa_p_a,ha_p_a,pn_p_a,wn_p_a,hn_p_a,bkcolor_p_a);
	power_left_action_picture=getimage2(filename_power_left_action,wa_p_a,ha_p_a,pn_p_a,wn_p_a,hn_p_a,bkcolor_p_a);
	power_right_picture=getimage2(filename_power_right,wa_p,ha_p,pn_p,wn_p,hn_p,bkcolor_p);
	power_left_picture=getimage2(filename_power_left,wa_p,ha_p,pn_p,wn_p,hn_p,bkcolor_p);
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
