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
		up2_key=0x26;//�W 
		do2_key=0x28;//�U 
		le2_key=0x25;//�� 
		ri2_key=0x27;//�k 
		at2_key=0xBF;///
		sk2_key=0xBA;//;
		position_x=500;//����_�l��m 
		position_y=200;//����_�l��m 
	}
	else if(player==1){
		up2_key=0x57;//w
		do2_key=0x53;//s
		le2_key=0x41;//a
		ri2_key=0x44;//d
		at2_key=0x43;//c
		sk2_key=0x46;//f
		position_x=200;//����_�l��m 
		position_y=200;//����_�l��m 	
	}
}
Julian::Julian(){
	wa=800;ha=500;pn=50;wn=10;hn=5;bkcolor=15;//���ʹ��ɤ��μƾ�
	wa_b_a=480;ha_b_a=100;pn_b_a=6;wn_b_a=6;hn_b_a=1;bkcolor_b_a=15;//���Y�y�ޯ���ɤ��μƾ�
	wa_b=218;ha_b=99;pn_b=2;wn_b=2;hn_b=1;bkcolor_b=15;//�y�ޯ���ɤ��μƾ�
	wa_p_a=240;ha_p_a=100;pn_p_a=3;wn_p_a=3;hn_p_a=1;bkcolor_p_a=15;//���X�z�o�ޯ���ɤ��μƾ�
	wa_p=800;ha_p=405;pn_p=4;wn_p=4;hn_p=1;bkcolor_p=15;//�z�o�ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 	
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
	direction[1]=3;//�Ϥ���l���A
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A	
	ball_right_action_count=0;//���k���Y�y�Ϥ���l���A
	ball_left_action_count=5;//�������Y�y�Ϥ���l���A
	ball_right_count=0;//�y�Ϥ���l���A
	ball_left_count=1;//�y�Ϥ���l���A
	power_right_action_count=0;//���k���X�z�o�ޯ�Ϥ���l���A
	power_left_action_count=2;//�������X�z�o�ޯ�Ϥ���l���A
	power_right_count=0;//�z�o�ޯ�Ϥ���l���A
	power_left_count=3;//�z�o�ޯ�Ϥ���l���A
	ball_position_x=position_x+80;//�y�_�l��m  
	ball_position_y=position_y+10;//�y�_�l��m
	power_position_x=position_x-60;//�z�o�ޯ�_�l��m  
	power_position_y=position_y-305;//�z�o�ޯ�_�l��m
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�������Y�y�ʧ@�O�_��������l���A 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//�����z�o�ޯ�ʧ@�O�_��������l���A
}
void Julian::control(){
		if(GetAsyncKeyState(up2_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do2_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le2_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri2_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at2_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk2_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up2_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do2_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le2_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri2_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at2_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk2_key)!=0){ button_down[5]=1;}//�ޯ� 
        
//------------------------------------------------------------------------------------------------�U��flag 
		if(button_down[2]==1||(button_down[0]==1&&direction[1]==3)||(button_down[1]==1&&direction[1]==3)||
		(button_down[4]==1&&direction[1]==3))//�P�_flag���� 
			flag_left=1;
		else
			flag_left=0;
				
		if(button_down[3]==1||(button_down[0]==1&&direction[1]==4)||(button_down[1]==1&&direction[1]==4)||
		(button_down[4]==1&&direction[1]==4))//�P�_flag����
			flag_right=1;
		else
			flag_right=0;
			
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_power_action==0){//�P�_�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-109+30;//�y�_�l��m  
			ball_position_y=position_y+10;
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_power_action==0){//�P�_�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+80-30;//�y�_�l��m  
			ball_position_y=position_y+10;
		}
		
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_power_right==0&&flag_ball_action==0){//�P�_�z�o�ޯ�X�۱��p 
			flag_power_action=1;
			flag_power_left=1;
			power_position_x=position_x-60;//�z�o�ޯ�_�l��m  
			power_position_y=position_y-305+15;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_power_left==0&&flag_ball_action==0){//�P�_�z�o�ޯ�X�۱��p 
			flag_power_action=1;
			flag_power_right=1;
			power_position_x=position_x-60;//�z�o�ޯ�_�l��m  
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
		if(button_count==0&&direction[1]==4&&flag_ball_action==0&&flag_power_action==0)//�S���ʧ@�B��V���k�� 
        		putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
    	else if(button_count==0&&direction[1]==3&&flag_ball_action==0&&flag_power_action==0){//�S���ʧ@�B��V������ 
        		putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
    	}
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_ball();
		print_power(); 
//------------------------------------------------------------------------------------------------   	
		if(button_count==1&&flag_ball_action==0&&flag_power_action==0){
//------------------------------------------------------------------------------------���ʫ��O
			if(button_down[0]==1&&direction[1]==4){//�W�Q���B��V���k 
				position_y-=10;
				putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
			else if(button_down[0]==1&&direction[1]==3){//�W�Q���B��V���� 
				position_y-=10;
				putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&direction[1]==4){//�U�Q���B��V���k 
				position_y+=10;
				putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&direction[1]==3){//�U�Q���B��V����
				position_y+=10;
				putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[2]==1){//���Q��
				position_x-=10;
				putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[3]==1){//�k�Q�� 
				position_x+=10;
				putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
//--------------------------------------------------------------------------------------�������O			
			if(button_down[4]==1&&direction[1]==4){//�����Q���B��V���k 
				putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[4]==1&&direction[1]==3){//�����Q���B��V���� 
				putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
		}
		if(button_count==2&&flag_ball_action==0&&flag_power_action==0){
//------------------------------------------------------------------------------------���ʫ��O 	
			if(button_down[0]==1&&button_down[2]==1){//�P�ɫ��W�� 
				position_x-=7;
				position_y-=7;
			    putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[3]==1){//�P�ɫ��W�k 
				position_x+=7;
				position_y-=7;
			    putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[2]==1){//�P�ɫ��U�� 
				position_x-=7;
				position_y+=7;
			    putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[3]==1){//�P�ɫ��U�k 
				position_x+=7;
				position_y+=7;
			    putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
			}
//--------------------------------------------------------------------------------------�������O
			if(button_down[0]==1&&button_down[4]==1&&direction[1]==3){//�P�ɫ��W��B��V����
				position_y-=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[4]==1&&direction[1]==4){//�P�ɫ��W��B��V���k 
				position_y-=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&direction[1]==3){//�P�ɫ��U��B��V����
				position_y+=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&direction[1]==4){//�P�ɫ��U��B��V���k 
				position_y+=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[2]==1&&button_down[4]==1){//�P�ɫ����� 
				position_x-=10;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[3]==1&&button_down[4]==1){//�P�ɫ��k�� 
				position_x+=10;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
		}
		if(button_count==3){
			if(button_down[0]==1&&button_down[4]==1&&button_down[2]==1){//�P�ɫ��W��
				position_y-=7;
				position_x-=7;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[0]==1&&button_down[4]==1&&button_down[3]==1){//�P�ɫ��W��k 
				position_y-=7;
				position_x+=7;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&button_down[2]==1){//�P�ɫ��U��
				position_y+=7;
				position_x-=7;
			    putimage(position_x,position_y, picture_left[attack_left_count], OR_PUT);
			}
			else if(button_down[1]==1&&button_down[4]==1&&button_down[3]==1){//�P�ɫ��U��k 
				position_y+=7;
				position_x+=7;
			    putimage(position_x,position_y, picture_right[attack_right_count], OR_PUT);
			}
		}
//-------------------------------------------------------------------------------------------		
		if(flag_right==1&&button_down[4]==0)//�S�������ɪ� picture_right_count
			picture_right_count=(++picture_right_count)%8;
		else
			picture_right_count=0;
			
		if(flag_left==1&&button_down[4]==0){//�S�������ɪ� picture_left_count
			picture_left_count--;
			if(picture_left_count<2)
				picture_left_count=9;
		}
		else
			picture_left_count=9;
//---------------------------------------------------------------------------------------------
		if(flag_right==1&&button_down[4]==1){//���������ɪ� attack_right_count
			attack_right_count++;
			if(attack_right_count>13)
				attack_right_count=10;
		}
		else
			attack_right_count=10;
			
		if(flag_left==1&&button_down[4]==1){//���������ɪ� attack_left_count
			attack_left_count--;
			if(attack_left_count<16)
				attack_left_count=19;
		}
		else
			attack_left_count=19;				 
}
void Julian::print_ball(){
        if(flag_ball_action==1&&flag_ball_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o���Y�ʧ@�A����L����|�L����)
			if(ball_right_action_count<=5){//�Y�ʧ@�٨S���� 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count++;
			}
			else if(ball_right_action_count>5){//�Y�ʧ@����
				ball_right_action_count=0;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_right==1){
			ball_position_x+=30;
			putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		}
			
		if(flag_ball_action==1&&flag_ball_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o���Y�ʧ@�A����L����|�L����)
			if(ball_left_action_count>=0){//�Y�ʧ@�٨S���� 
			   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
				ball_left_action_count--;
			}
			else if(ball_left_action_count<0){//�Y�ʧ@����
				ball_left_action_count=5;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_left==1){
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		}
		if(flag_ball_right==1){//�y�V�k���ɪ� ball_right_count
			ball_right_count=(++ball_right_count)%2;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//�y�V�����ɪ� ball_left_count
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
		if(flag_power_right==1){//�ޯ�Q���B��V���k
			if(power_right_action_count<=2){//�Y�ʧ@�٨S���� 				
			   	putimage(position_x,position_y, power_right_action_picture[power_right_action_count], OR_PUT);
				power_right_action_count++;
			}
			if(power_right_action_count>2)		
				putimage(power_position_x,power_position_y, power_right_picture[power_right_count], OR_PUT);	
		}	
		if(flag_power_left==1){//�ޯ�Q���B��V���� 
			if(power_left_action_count>=0){//�Y�ʧ@�٨S����			
			   	putimage(position_x,position_y, power_left_action_picture[power_left_action_count], OR_PUT);
				power_left_action_count--;
			}
			if(power_left_action_count<0)
				putimage(power_position_x,power_position_y, power_left_picture[power_left_count], OR_PUT);
		}
		
		if(flag_power_right==1&&power_right_action_count>2){//�z�o�ޯ�V�k�ɪ� power_right_count
			power_right_count=(++power_right_count)%4;
			if(power_right_count==0){
				flag_power_right=0;
				flag_power_action=0;
				power_right_action_count=0;
			}
		}
		if(flag_power_left==1&&power_left_action_count<0){//�z�o�ޯ�V���ɪ� power_left_count
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
