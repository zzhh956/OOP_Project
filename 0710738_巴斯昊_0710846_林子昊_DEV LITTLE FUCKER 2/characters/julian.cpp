#include"julian.h"
#include"john.h"
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

void Julian::set(int player)
{
	if(player==2){
		up2_key=0x26;//上 
		do2_key=0x28;//下 
		le2_key=0x25;//左 
		ri2_key=0x27;//右 
		at2_key=0xBF;///
		sk2_key=0xBA;//;
		position_x=500;//角色起始位置 
		position_y=200;//角色起始位置 
		direction[1]=3;//圖片初始狀態
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
		direction[1]=4;//圖片初始狀態	
	}
}
Julian::Julian(){
	wa_r=800;ha_r=500;pn_r=50;wn_r=10;hn_r=5;bkcolor_r=15;//往右移動圖檔切割數據
	wa_l=800;ha_l=500;pn_l=50;wn_l=10;hn_l=5;bkcolor_l=15;//往左移動圖檔切割數據
	
	wa_b_r_a=480;ha_b_r_a=100;pn_b_r_a=6;wn_b_r_a=6;hn_b_r_a=1;bkcolor_b_r_a=15;//往右投擲球技能圖檔切割數據
	wa_b_l_a=480;ha_b_l_a=100;pn_b_l_a=6;wn_b_l_a=6;hn_b_l_a=1;bkcolor_b_l_a=15;//往左投擲球技能圖檔切割數據
	 
	wa_b_r=218;ha_b_r=99;pn_b_r=2;wn_b_r=2;hn_b_r=1;bkcolor_b_r=15;//往右球技能圖檔切割數據
	wa_b_l=218;ha_b_l=99;pn_b_l=2;wn_b_l=2;hn_b_l=1;bkcolor_b_l=15;//往左球技能圖檔切割數據
	
	wa_p_r_a=240;ha_p_r_a=100;pn_p_r_a=3;wn_p_r_a=3;hn_p_r_a=1;bkcolor_p_r_a=15;//往右做出爆發技能圖檔切割數據
	wa_p_l_a=240;ha_p_l_a=100;pn_p_l_a=3;wn_p_l_a=3;hn_p_l_a=1;bkcolor_p_l_a=15;//往左做出爆發技能圖檔切割數據

	wa_p_r=800;ha_p_r=405;pn_p_r=4;wn_p_r=4;hn_p_r=1;bkcolor_p_r=15;//往右爆發技能圖檔切割數據
	wa_p_l=800;ha_p_l=405;pn_p_l=4;wn_p_l=4;hn_p_l=1;bkcolor_p_l=15;//往左爆發技能圖檔切割數據	
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
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	down_right_count=46;//圖片初始狀態
	down_left_count=43;//圖片初始狀態
	defense_right_count=46;//圖片初始狀態
	defense_left_count=43;//圖片初始狀態
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
	position_x=820;//角色起始位置 
	position_y=500;//角色起始位置 
	ball_position_x=-1000;//球起始位置  
	ball_position_y=-1000;//球起始位置
	manyball_position_x=-1000;
	manyball_position_y=-1000;
	power_position_x=-1000;//爆發技能起始位置  
	power_position_y=-1000;//爆發技能起始位置
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態
	flag_down=0;//紀錄角色是否有被擊飛的初始狀態
	flag_defense=0;//紀錄角色是否有被揍的初始狀態
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//紀錄投擲球動作是否做完的初始狀態 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//紀錄爆發技能動作是否做完的初始狀態	
	number_of_ball=0;//記錄球的個數 
	flag_manyball_remain=0;//紀錄前一顆球是否繼續存在 
	flag_ball_past=0;//球的左右狀態 
	flag_ball_record_receive=0;//記錄球是否被接收 
}
void Julian::control(){
		if(GetAsyncKeyState(up2_key)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(do2_key)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(le2_key)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(ri2_key)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(at2_key)==0) button_down[4]=0;//攻 
        if(GetAsyncKeyState(sk2_key)==0) button_down[5]=0;//技能 
        
        if(GetAsyncKeyState(up2_key)!=0) button_down[0]=1;
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
		(button_down[4]==1&&direction[1]==4)){//判斷flag情形
			flag_right=1;
			//printf("*\n");
		}
		else
			flag_right=0;
			
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_power_action==0&&number_of_ball<2
		&&flag_down==0&&flag_defense==0){//判斷球出招情況 
			//printf("*\n");
			if(flag_manyball_remain==1&&flag_ball_record_receive==0){
				skills_record();
				//printf("*\n");
			}
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=ball_ori_position_x=position_x-109+30;//球起始位置  
			ball_position_y=ball_ori_position_y=position_y+10;
			//printf("%d %d\n",position_x,ball_position_x);
			//printf("*\n");	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_power_action==0&&number_of_ball<2
		&&flag_down==0&&flag_defense==0){//判斷球出招情況 
			
			if(flag_manyball_remain==1&&flag_ball_record_receive==0){
				skills_record();
				//printf("*\n");
			}
			
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=ball_ori_position_x=position_x+80-30;//球起始位置  
			ball_position_y=ball_ori_position_y=position_y+10;
			
		}
		
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_power_right==0&&flag_ball_action==0&&flag_down==0
		&&flag_defense==0){//判斷爆發技能出招情況 
			//printf("*\n");
			flag_power_action=1;
			flag_power_left=1;
			power_position_x=position_x-60;//爆發技能起始位置  
			power_position_y=position_y-305+15;
			//printf("%d %d\n",position_x,ball_position_x);
			//printf("*\n");	
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_power_left==0&&flag_ball_action==0&&flag_down==0
		&&flag_defense==0){//判斷爆發技能出招情況 
			//printf("*\n");
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
	
		//printf("%d\n",button_count);
		
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
		if(button_count==0&&direction[1]==4&&flag_ball_action==0&&flag_power_action==0&&flag_down==0&&flag_defense==0)//沒有動作且方向為右時 
        		putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
    	else if(button_count==0&&direction[1]==3&&flag_ball_action==0&&flag_power_action==0&&flag_down==0&&flag_defense==0){//沒有動作且方向為左時 
        		putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
    	}
        		
//-----------------------------------------------------------------------------------------------//特殊技能        	
		print_ball();
		print_manyball();
		//printf("%d\n",number_of_ball);
		print_power();
		if(flag_defense==0)
			print_down();
		if(flag_down==0)
			print_defense();
		 
		//printf("%d\n",flag_manyball_remain);
		//printf("%d\n",number_of_ball);
		//printf("*%d\n",ball_position_y);
		//printf("%d\n",manyball_position_y);
//------------------------------------------------------------------------------------------------   	
		if(button_count==1&&flag_ball_action==0&&flag_power_action==0&&flag_down==0&&flag_defense==0){
			//printf("*\n");
			//printf("%d\n",direction[1]);
			//printf("%d\n",button_down[0]);
			
//------------------------------------------------------------------------------------移動指令

			if(button_down[0]==1&&direction[1]==4){//上被按且方向為右 
				position_y-=10;
				putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
				//printf("*\n");
				//printf("%d\n",position_y);
				//printf("%d\n",picture_right_count);
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
		if(button_count==2&&flag_ball_action==0&&flag_power_action==0&&flag_down==0&&flag_defense==0){
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
		if(flag_right==1&&button_down[4]==0){//沒按攻擊時的 picture_right_count
			//printf("*\n");
			picture_right_count=(++picture_right_count)%8;
			//printf("%d\n",picture_right_count);
		}
		else{
			picture_right_count=0;
			//printf("%d\n",picture_right_count);
		}
			
		if(flag_left==1&&button_down[4]==0){//沒按攻擊時的 picture_left_count
			picture_left_count--;
			//printf("%d\n",picture_left_count);
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
void Julian::print_ball(){
        if(flag_ball_action==1&&flag_ball_right==1){//技能被按且方向為右(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			if(ball_right_action_count<=5){//若動作還沒做完 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count++;
			}
			else if(ball_right_action_count>5){//若動作做完
				number_of_ball++;
				ball_right_action_count=0;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_right==1){
			
			ball_position_x+=30;
			putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		}
			
		if(flag_ball_action==1&&flag_ball_left==1){//技能被按且方向為左(動作部分)(角色只會做這投擲動作，按其他按鍵會無反應)
			//printf("*\n");
			if(ball_left_action_count>=0){//若動作還沒做完 
				//printf("*%d\n",disk_left_action_count);
			   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
				ball_left_action_count--;
			}
			else if(ball_left_action_count<0){//若動作做完
				number_of_ball++;
				ball_left_action_count=5;
			   	flag_ball_action=0;
			   	//printf("*%d\n",number_of_ball);
			   	//printf("*%d %d\n",flag_ball_action,flag_ball_left);
			}
		}
		else if(flag_ball_action==0&&flag_ball_left==1){
			//printf("*\n");
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
			//disk_position_y;
		}
		if(flag_ball_right==1){//球向右飛時的 ball_right_count
			ball_right_count=(++ball_right_count)%2;
			flag_manyball_remain=1;
			flag_ball_past=2;
			if(ball_position_x>=ball_ori_position_x+480){
				//printf("*\n");
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
			//printf("*\n");
			ball_left_count--;
			if(ball_left_count==-1){
				//printf("*\n");
				ball_left_count=1;
			}
			flag_manyball_remain=1;
			flag_ball_past=1;
			//printf("*%d\n",flag_ball_past);
			if(ball_position_x<=ball_ori_position_x-480){
				ball_left_count=1;
				flag_ball_left=0;
				flag_manyball_remain=0;
				flag_ball_past=0;
				number_of_ball--;
				ball_position_x=-1000;
				ball_position_y=-1000;
			}
		}
}
void Julian::print_power(){
		if(flag_power_right==1){//技能被按且方向為右
			if(power_right_action_count<=2){//若動作還沒做完 				
			   	putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				power_right_action_count++;
				//printf("*%d\n",ball_right_action_count);
			}
			if(power_right_action_count>2){			
				putimage(power_position_x,power_position_y, power_right_picture[power_right_count], OR_PUT);
				//printf("%d %d\n",position_x,ball_position_x);		
			}
		}
		
			
		if(flag_power_left==1){//技能被按且方向為左 
			//printf("*\n");
			if(power_left_action_count>=0){//若動作還沒做完			
			   	putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				power_left_action_count--;
			}
			if(power_left_action_count<0){
			putimage(power_position_x,power_position_y, power_left_picture[power_left_count], OR_PUT);
			//printf("%d %d\n",position_x,ball_position_x);
			}
		}
		
		if(flag_power_right==1&&power_right_action_count>2){//爆發技能向右時的 power_right_count
			power_right_count=(++power_right_count)%4;
			if(power_right_count==0){
				//printf("*\n");
				flag_power_right=0;
				flag_power_action=0;
				power_right_action_count=0;
				power_position_x=-1000;
				power_position_y=-1000;
			}
		}
		if(flag_power_left==1&&power_left_action_count<0){//爆發技能向左時的 power_left_count
			power_left_count--;
			if(power_left_count==-1){
				//printf("*\n");
				power_left_count=3;
			}
			if(power_left_count==3){
				flag_power_left=0;
				flag_power_action=0;
				power_left_action_count=2;
				power_position_x=-1000;
				power_position_y=-1000;
			}
		}
}
void Julian::skills_record(){
	if(number_of_ball>=1){
		if(flag_ball_past==1){
			manyball_left_count=ball_left_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;	
			last_manyball_position_x=ball_ori_position_x-480;
			flag_ball_record_receive=1;
		}
		//printf("%d\n",flag_ball_past);
		if(flag_ball_past==2){
			//printf("%d\n",flag_ball_past);
			manyball_right_count=ball_right_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;
			last_manyball_position_x=ball_ori_position_x+480;
			flag_ball_record_receive=1;
		}
	}
}
void Julian::print_manyball(){
	if(flag_manyball_remain==1&&flag_ball_past==1&&number_of_ball>=1&&flag_ball_record_receive==1){
		//printf("*\n");
		if(manyball_position_x>=last_manyball_position_x){
			//printf("*\n");
			manyball_position_x-=30;
			putimage(manyball_position_x,manyball_position_y, ball_left_picture[manyball_left_count], OR_PUT);
			//printf("*\n");
			manyball_left_count--;
			if(manyball_left_count==-1){
				manyball_left_count=1;
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
			//printf("&\n");
			manyball_position_x+=30;
			putimage(manyball_position_x,manyball_position_y, ball_right_picture[manyball_right_count], OR_PUT);
			manyball_right_count=(++manyball_right_count)%2;
			if(manyball_position_x>last_manyball_position_x){//球向右飛時的 manyball_right_count
				flag_manyball_remain=0;
				number_of_ball--;
				flag_ball_record_receive=0;
				manyball_position_x=-100;
				manyball_position_y=-100;
			}			
		}
	}
	if(flag_manyball_remain==0)
		number_of_ball=0;
}
void Julian::print_down(){
	if(flag_down==1&&direction[1]==4){//角色被擊倒且方向為右 
					position_x-=15;
			    	putimage(position_x,position_y, picture_right[down_right_count], OR_PUT);
			    	down_right_count++;
			    	if(down_right_count>48){
			    		down_right_count=46;
			    		flag_down=0;
					}
				}
	else if(flag_down==1&&direction[1]==3){//角色被擊倒且方向為左 
					position_x+=15;
			    	putimage(position_x,position_y, picture_left[down_left_count], OR_PUT);
			    	down_left_count--;
			    	if(down_left_count<41){
			    		down_left_count=43;
			    		flag_down=0;
					}
				}
}
void Julian::print_defense(){
	if(flag_defense==1&&direction[1]==4){//角色被揍且方向為右 
					position_x-=5;
			    	putimage(position_x,position_y, picture_right[defense_right_count], OR_PUT);
			    	defense_right_count++;
			    	if(defense_right_count>48){
			    		defense_right_count=46;
			    		flag_defense=0;
					}
				}
	else if(flag_defense==1&&direction[1]==3){//角色被揍且方向為左 
					position_x+=5;
			    	putimage(position_x,position_y, picture_left[defense_left_count], OR_PUT);
			    	defense_left_count--;
			    	if(defense_left_count<41){
			    		defense_left_count=43;
			    		flag_defense=0;
					}
				}
}
/*void Julian::getdata(int &p2_position_x,int &p2_position_y,int &p2_power_position_x,int &p2_power_position_y,int &p2_ball_position_x,int &p2_ball_position_y,
int &p2_manyball_position_x,int &p2_manyball_position_y,
int &p2_width,int &p2_height,int &p2_ball_width,int &p2_ball_height,int &p2_power_width,int &p2_power_height,
int &p2_button_down){
	p2_position_x=position_x;//角色目前位置 
	p2_position_y=position_y;//角色目前位置  
	p2_power_position_x=power_position_x;//爆發技能目前位置 
	p2_power_position_y=power_position_y;//爆發技能目前位置 
	p2_ball_position_x=ball_position_x;//球技能目前位置 
	p2_ball_position_y=ball_position_y;//球技能目前位置
	p2_manyball_position_x=manyball_position_x;//額外球技能目前位置 
	p2_manyball_position_y=manyball_position_y;//額外球技能目前位置
	p2_width=wa_r/wn_r;p2_height=ha_r/hn_r;//角色長寬 
	p2_ball_width=wa_b_r/wn_b_r;p2_ball_height=ha_b_r/hn_b_r;//球長寬 
	p2_power_width=wa_p_r/wn_p_r;p2_power_height=ha_p_r/hn_p_r;//飛碟長寬 
	p2_button_down=button_down[4];
}*/
void Julian::getdata(int &p2_position_x,int &p2_position_y,int &p2_skill1_position_x,int &p2_skill1_position_y,int &p2_skill2_position_x,
int &p2_skill2_position_y,int &p2_manyskill1_position_x,int &p2_manyskill1_position_y,int &p2_manyskill2_position_x,int &p2_manyskill2_position_y,
int &p2_width,int &p2_height,int &p2_skill1_width,int &p2_skill1_height,int &p2_skill2_width,int &p2_skill2_height,
int &p2_button_down){
	p2_position_x=position_x;//角色目前位置 
	p2_position_y=position_y;//角色目前位置  
	p2_skill1_position_x=power_position_x;//爆發技能目前位置 
	p2_skill1_position_y=power_position_y;//爆發技能目前位置 
	p2_skill2_position_x=ball_position_x;//球技能目前位置 
	p2_skill2_position_y=ball_position_y;//球技能目前位置
	p2_manyskill1_position_x=-1000;
	p2_manyskill1_position_y=-1000;
	p2_manyskill2_position_x=manyball_position_x;//額外球技能目前位置 
	p2_manyskill2_position_y=manyball_position_y;//額外球技能目前位置
	p2_width=wa_r/wn_r;p2_height=ha_r/hn_r;//角色長寬 
	p2_skill1_width=wa_p_r/wn_p_r;p2_skill1_height=ha_p_r/hn_p_r;//爆發長寬 
	p2_skill2_width=wa_b_r/wn_b_r;p2_skill2_height=ha_b_r/hn_b_r;//球長寬 
	p2_button_down=button_down[4];
}
void Julian::setdata(int down_switch,int defense_switch){
	if(down_switch==1)
		flag_down=1;
	if(defense_switch==1)
		flag_defense=1;
}
