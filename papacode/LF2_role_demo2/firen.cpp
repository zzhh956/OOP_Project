#include"player.h"
#include"firen.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void Firen::Firen_set(int player)
{
	if(player==1){
		int up4_key=0x26;//�W 
		int do4_key=0x28;//�U 
		int le4_key=0x25;//�� 
		int ri4_key=0x27;//�k 
		int at4_key=0xBF;///
		int sk4_key=0xBA;//;
	}
	else if(player==2){
		int	up4_key=0x57;//w
		int	do4_key=0x53;//s
		int	le4_key=0x41;//a
		int	ri4_key=0x44;//d
		int	at4_key=0x43;//c
		int	sk4_key=0x46;//f
	}
}

Firen::Firen(
char *receive_file_right,char *receive_file_left,int wa_R,int ha_R,int pn_R,
int wn_R,int hn_R,int bkcolor_R,int wa_L,int ha_L,int pn_L,int wn_L,int hn_L,int bkcolor_L,

char *receive_file_power_right_action_picture,char *receive_file_power_left_action_picture,int wa_D_R_A,int ha_D_R_A,int pn_D_R_A,
int wn_D_R_A,int hn_D_R_A,int bkcolor_D_R_A,int wa_D_L_A,int ha_D_L_A,int pn_D_L_A,int wn_D_L_A,int hn_D_L_A,int bkcolor_D_L_A,

char *receive_file_power_right_picture,char *receive_file_power_left_picture,int wa_D_R,int ha_D_R,int pn_D_R,
int wn_D_R,int hn_D_R,int bkcolor_D_R,int wa_D_L,int ha_D_L,int pn_D_L,int wn_D_L,int hn_D_L,int bkcolor_D_L,

char *receive_file_ball_right_action_picture,char *receive_file_ball_left_action_picture,int wa_B_R_A,int ha_B_R_A,int pn_B_R_A,
int wn_B_R_A,int hn_B_R_A,int bkcolor_B_R_A,int wa_B_L_A,int ha_B_L_A,int pn_B_L_A,int wn_B_L_A,int hn_B_L_A,int bkcolor_B_L_A,

char *receive_file_ball_right_picture,char *receive_file_ball_left_picture,int wa_B_R,int ha_B_R,int pn_B_R,
int wn_B_R,int hn_B_R,int bkcolor_B_R,int wa_B_L,int ha_B_L,int pn_B_L,int wn_B_L,int hn_B_L,int bkcolor_B_L
, int player
){
	
	wa_r=wa_R;ha_r=ha_R;pn_r=pn_R;wn_r=wn_R;hn_r=hn_R;bkcolor_r=bkcolor_R;//���k���ʹ��ɤ��μƾ�
	wa_l=wa_L;ha_l=ha_L;pn_l=pn_L;wn_l=wn_L;hn_l=hn_L;bkcolor_l=bkcolor_L;//�������ʹ��ɤ��μƾ�
	
	wa_d_r_a=wa_D_R_A;ha_d_r_a=ha_D_R_A;pn_d_r_a=pn_D_R_A;wn_d_r_a=wn_D_R_A;hn_d_r_a=hn_D_R_A;bkcolor_d_r_a=bkcolor_D_R_A;//���k�z�o�ޯ���ɤ��μƾ�
	wa_d_l_a=wa_D_L_A;ha_d_l_a=ha_D_L_A;pn_d_l_a=pn_D_L_A;wn_d_l_a=wn_D_L_A;hn_d_l_a=hn_D_L_A;bkcolor_d_l_a=bkcolor_D_L_A;//�����z�o�ޯ���ɤ��μƾ�
	wa_d_r=wa_D_R;ha_d_r=ha_D_R;pn_d_r=pn_D_R;wn_d_r=wn_D_R;hn_d_r=hn_D_R;bkcolor_d_r=bkcolor_D_R;//���k�z���ޯ���ɤ��μƾ�
	wa_d_l=wa_D_L;ha_d_l=ha_D_L;pn_d_l=pn_D_L;wn_d_l=wn_D_L;hn_d_l=hn_D_L;bkcolor_d_l=bkcolor_D_L;//�����z���ޯ���ɤ��μƾ�	
	wa_b_r_a=wa_B_R_A;ha_b_r_a=ha_B_R_A;pn_b_r_a=pn_B_R_A;wn_b_r_a=wn_B_R_A;hn_b_r_a=hn_B_R_A;bkcolor_b_r_a=bkcolor_B_R_A;//���k�R���K�ޯ���ɤ��μƾ�
	wa_b_l_a=wa_B_L_A;ha_b_l_a=ha_B_L_A;pn_b_l_a=pn_B_L_A;wn_b_l_a=wn_B_L_A;hn_b_l_a=hn_B_L_A;bkcolor_b_l_a=bkcolor_B_L_A;//�����R���K�ޯ���ɤ��μƾ�
	wa_b_r=wa_B_R;ha_b_r=ha_B_R;pn_b_r=pn_B_R;wn_b_r=wn_B_R;hn_b_r=hn_B_R;bkcolor_b_r=bkcolor_B_R;//���k���K�ޯ���ɤ��μƾ�
	wa_b_l=wa_B_L;ha_b_l=ha_B_L;pn_b_l=pn_B_L;wn_b_l=wn_B_L;hn_b_l=hn_B_L;bkcolor_b_l=bkcolor_B_L;//�������K�ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 
	strcpy(filename_right,receive_file_right);
	filename_right[strlen(receive_file_right)]='\0';

	strcpy(filename_left,receive_file_left);
	filename_left[strlen(receive_file_left)]='\0';
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
//-----------------------------------------------------------------------------------------
	direction[1]=4;//�Ϥ���l���A 
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A
	power_right_action_count=0;//���k�z�o�Ϥ���l���A
	power_left_action_count=4;//�����z�o�Ϥ���l���A
	power_right_count=0;//�z���Ϥ���l���A
	power_left_count=4;//�z���Ϥ���l���A
	ball_right_action_count=0;//���k�R���K�Ϥ���l���A
	ball_left_action_count=4;//�����R���K�Ϥ���l���A
	ball_right_count=0;//���K�Ϥ���l���A
	ball_left_count=3;//���K�Ϥ���l���A
	if(player==1)
		position_x=100;//����_�l��m 
		position_y=500;//����_�l��m 
	else if(player==2)
		position_x=500;//����_�l��m 
		position_y=500;//����_�l��m 
	power_position_x=position_x;//�z���_�l��m  
	power_position_y=position_y-21;//�z���_�l��m 
	ball_position_x=position_x+110;//���K�_�l��m  
	ball_position_y=position_y+3;//���K�_�l��m 
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_power_action=0,flag_power_right=0,flag_power_left=0;//�����z�o�ʧ@�O�_��������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�����R���K�ʧ@�O�_��������l���A
	Firen_set(player);
}
void Firen::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Firen::control(){
	    if(GetAsyncKeyState(up4_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do4_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le4_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri4_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at4_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk4_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up4_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do4_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le4_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri4_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at4_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk4_key)!=0) button_down[5]=1;//�ޯ� 
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
			
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_power_right==0&&flag_ball_action==0){//�P�_�z���X�۱��p 
			flag_power_action=1;
			flag_power_left=1;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_power_left==0&&flag_ball_action==0){//�P�_�z���X�۱��p 
			flag_power_action=1;
			flag_power_right=1;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_power_action==0){//�P�_���K�X�۱��p 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//���K�_�l��m  
			ball_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_power_action==0){//�P�_���K�X�۱��p 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//���K�_�l��m  
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
	picture_right=getimage2(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage2(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	power_right_action_picture=getimage2(filename_power_right_action,wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a);
	power_left_action_picture=getimage2(filename_power_left_action,wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a);
	power_right_picture=getimage2(filename_power_right,wa_d_r,ha_d_r,pn_d_r,wn_d_r,hn_d_r,bkcolor_d_r);
	power_left_picture=getimage2(filename_power_left,wa_d_l,ha_d_l,pn_d_l,wn_d_l,hn_d_l,bkcolor_d_l);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r);
	ball_left_picture=getimage2(filename_ball_left,wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l);
}
void Firen::print(){
        if(button_count==0&&direction[1]==4&&flag_power_action==0&&flag_ball_action==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_power_action==0&&flag_ball_action==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_power();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------���ʫ��O
			if(flag_power_action==0&&flag_ball_action==0){
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
//---------------------------------------------------------------------------------------			
		}
		if(button_count==2&&flag_power_action==0&&flag_ball_action==0){
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
		else{
			attack_right_count=10;
		}
		if(flag_left==1&&button_down[4]==1){//���������ɪ� attack_left_count
			attack_left_count--;
			if(attack_left_count<16)
				attack_left_count=19;
		}
		else
			attack_left_count=19;
}
int right = 0, left = 0;

void Firen::print_power(){
		if(flag_power_right==1){//�ޯ�Q���B��V���k
			if(right==1){
				power_right_action_count=9;
				right = 0;
			}
			if(power_right_action_count<4){//�Y�ʧ@�٨S���� 				
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
		if(flag_power_left==1){//�ޯ�Q���B��V���� 
			if(left==1){
				power_left_action_count=5;
				left = 0;
			}
			if(power_left_action_count<5 && power_left_action_count>0){//�Y�ʧ@�٨S����			
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
    if(flag_ball_action==1&&flag_ball_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o���Y�ʧ@�A����L����|�L����)
			if(ball_right_action_count<=4){//�Y�ʧ@�٨S���� 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count++;
			}
			else if(ball_right_action_count>4){//�Y�ʧ@����
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
				ball_left_action_count=4;
			   	flag_ball_action=0;
			}
		}
		else if(flag_ball_action==0&&flag_ball_left==1){
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		}
		if(flag_ball_right==1){//�y�V�k���ɪ� ball_right_count
			ball_right_count=(++ball_right_count)%6;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//�y�V�����ɪ� ball_left_count
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
