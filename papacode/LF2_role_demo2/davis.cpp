#include"player.h"
#include"davis.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>

void Davis::Davis_set(int player)
{
	if(player==1){
		int up7_key=0x26;//�W 
		int do7_key=0x28;//�U 
		int le7_key=0x25;//�� 
		int ri7_key=0x27;//�k 
		int at7_key=0xBF;///
		int sk7_key=0xBA;//;
	}
	else if(player==2){
		int	up7_key=0x57;//w
		int	do7_key=0x53;//s
		int	le7_key=0x41;//a
		int	ri7_key=0x44;//d
		int	at7_key=0x43;//c
		int	sk7_key=0x46;//f
	}
}

Davis::Davis(
char *receive_file_right,char *receive_file_left,int wa_R,int ha_R,int pn_R,
int wn_R,int hn_R,int bkcolor_R,int wa_L,int ha_L,int pn_L,int wn_L,int hn_L,int bkcolor_L,

char *receive_file_holly_right_action_picture,char *receive_file_holly_left_action_picture,int wa_D_R_A,int ha_D_R_A,int pn_D_R_A,
int wn_D_R_A,int hn_D_R_A,int bkcolor_D_R_A,int wa_D_L_A,int ha_D_L_A,int pn_D_L_A,int wn_D_L_A,int hn_D_L_A,int bkcolor_D_L_A,

char *receive_file_ball_right_action_picture,char *receive_file_ball_left_action_picture,int wa_B_R_A,int ha_B_R_A,int pn_B_R_A,
int wn_B_R_A,int hn_B_R_A,int bkcolor_B_R_A,int wa_B_L_A,int ha_B_L_A,int pn_B_L_A,int wn_B_L_A,int hn_B_L_A,int bkcolor_B_L_A,

char *receive_file_ball_right_picture,char *receive_file_ball_left_picture,int wa_B_R,int ha_B_R,int pn_B_R,
int wn_B_R,int hn_B_R,int bkcolor_B_R,int wa_B_L,int ha_B_L,int pn_B_L,int wn_B_L,int hn_B_L,int bkcolor_B_L
, int player
){
	wa_r=wa_R;ha_r=ha_R;pn_r=pn_R;wn_r=wn_R;hn_r=hn_R;bkcolor_r=bkcolor_R;//���k���ʹ��ɤ��μƾ�
	wa_l=wa_L;ha_l=ha_L;pn_l=pn_L;wn_l=wn_L;hn_l=hn_L;bkcolor_l=bkcolor_L;//�������ʹ��ɤ��μƾ�
	
	wa_d_r_a=wa_D_R_A;ha_d_r_a=ha_D_R_A;pn_d_r_a=pn_D_R_A;wn_d_r_a=wn_D_R_A;hn_d_r_a=hn_D_R_A;bkcolor_d_r_a=bkcolor_D_R_A;//���k�W�_���ޯ���ɤ��μƾ�
	wa_d_l_a=wa_D_L_A;ha_d_l_a=ha_D_L_A;pn_d_l_a=pn_D_L_A;wn_d_l_a=wn_D_L_A;hn_d_l_a=hn_D_L_A;bkcolor_d_l_a=bkcolor_D_L_A;//�����W�_���ޯ���ɤ��μƾ�

	wa_b_r_a=wa_B_R_A;ha_b_r_a=ha_B_R_A;pn_b_r_a=pn_B_R_A;wn_b_r_a=wn_B_R_A;hn_b_r_a=hn_B_R_A;bkcolor_b_r_a=bkcolor_B_R_A;//���k���Y�y�ޯ���ɤ��μƾ�
	wa_b_l_a=wa_B_L_A;ha_b_l_a=ha_B_L_A;pn_b_l_a=pn_B_L_A;wn_b_l_a=wn_B_L_A;hn_b_l_a=hn_B_L_A;bkcolor_b_l_a=bkcolor_B_L_A;//�������Y�y�ޯ���ɤ��μƾ�

	wa_b_r=wa_B_R;ha_b_r=ha_B_R;pn_b_r=pn_B_R;wn_b_r=wn_B_R;hn_b_r=hn_B_R;bkcolor_b_r=bkcolor_B_R;//���k���Y�y�ޯ���ɤ��μƾ�
	wa_b_l=wa_B_L;ha_b_l=ha_B_L;pn_b_l=pn_B_L;wn_b_l=wn_B_L;hn_b_l=hn_B_L;bkcolor_b_l=bkcolor_B_L;//�������Y�y�ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 
	strcpy(filename_right,receive_file_right);
	filename_right[strlen(receive_file_right)]='\0';

	strcpy(filename_left,receive_file_left);
	filename_left[strlen(receive_file_left)]='\0';
//		
	strcpy(filename_holly_right_action,receive_file_holly_right_action_picture);
	filename_holly_right_action[strlen(receive_file_holly_right_action_picture)]='\0';

	strcpy(filename_holly_left_action,receive_file_holly_left_action_picture);
	filename_holly_left_action[strlen(receive_file_holly_left_action_picture)]='\0';	
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
	holly_right_action_count=0;//���k�W�_���Ϥ���l���A
	holly_left_action_count=7;//�����W�_���Ϥ���l���A
	ball_right_action_count=0;//���k���Y�y�Ϥ���l���A
	ball_left_action_count=4;//�������Y�y�Ϥ���l���A
	ball_right_count=0;//�y�Ϥ���l���A
	ball_left_count=3;//�y�Ϥ���l���A
	if(player==1)
		position_x=100;//����_�l��m 
		position_y=500;//����_�l��m 
	else if(player==2)
		position_x=500;//����_�l��m 
		position_y=500;//����_�l��m 
	ball_position_x=position_x+110;//���Y�y�_�l��m  
	ball_position_y=position_y+3;//���Y�y�_�l��m 
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_holly_action_right=0, flag_holly_action_left=0;//�����W�_���ʧ@�O�_��������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�������Y���Y�y�ʧ@�O�_��������l���A
	Davis_set(player);
}
void Davis::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Davis::control(){
	    if(GetAsyncKeyState(up7_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do7_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le7_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri7_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at7_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk7_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up7_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do7_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le7_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri7_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at7_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk7_key)!=0) button_down[5]=1;//�ޯ� 
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
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_holly_action_right==0)//�P�_�W�_���X�۱��p 
			flag_holly_action_left=1;					
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_holly_action_left==0)//�P�_�W�_���X�۱��p 
			flag_holly_action_right=1;
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_holly_action_right==0){//�P�_���Y�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//���Y�y�_�l��m  
			ball_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_holly_action_left==0){//�P�_���Y�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//���Y�y�_�l��m  
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
void Davis::recordimage(){
	picture_right=getimage2(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage2(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	holly_right_action_picture=getimage2(filename_holly_right_action,wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a);
	holly_left_action_picture=getimage2(filename_holly_left_action,wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r);
	ball_left_picture=getimage2(filename_ball_left,wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l);
}
void Davis::print(){
        if(button_count==0&&direction[1]==4&&flag_holly_action_right==0&&flag_ball_action==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_holly_action_left==0&&flag_ball_action==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_holly();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------���ʫ��O
			if(flag_holly_action_left==0&&flag_holly_action_right==0&&flag_ball_action==0){
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
//-------------------------------------------------------------------------------------			
		}
		if(button_count==2&&flag_holly_action_left==0&&flag_holly_action_right==0&&flag_ball_action==0){
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
void Davis::print_holly(){
        if(flag_holly_action_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o�W�_���ʧ@�A����L����|�L����)
			if(holly_right_action_count<=7){//�Y�ʧ@�٨S���� 
			   	position_x+=20;
			   	if(holly_right_action_count>=1 && holly_right_action_count<=3)
			   		position_y-=20;
			   	else if(holly_right_action_count>=4 && holly_right_action_count<=6)
			   		position_y+=20;
				putimage(position_x,position_y, holly_right_action_picture[holly_right_action_count], OR_PUT);
				holly_right_action_count++;
				if(holly_right_action_count>7){
					holly_right_action_count=0;
					flag_holly_action_right=0;
				}
			}
		}
		if(flag_holly_action_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o�W�_���ʧ@�A����L����|�L����)
			if(holly_left_action_count>=0){//�Y�ʧ@�٨S���� 
				position_x-=20;
				if(holly_left_action_count>=1 && holly_left_action_count<=3)
			   		position_y+=20;
			   	else if(holly_left_action_count>=4 && holly_left_action_count<=6)
			   		position_y-=20;
			   	putimage(position_x,position_y, holly_left_action_picture[holly_left_action_count], OR_PUT);
				holly_left_action_count--;
				if(holly_left_action_count<0){
					holly_left_action_count=7;
					flag_holly_action_left=0;
				}
			}
		} 
}
int v_davis=0;
void Davis::print_ball(){
	if(flag_ball_action==1&&flag_ball_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o���Y�y�ʧ@�A����L����|�L����)
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
		ball_position_x+=30+v_davis;
		putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		ball_right_count++;
		if(ball_right_count==4)
			ball_right_count=8;
		if(ball_right_count==10){
			flag_ball_right=0;
			ball_right_count=0;
			v_davis=0;
		}
		v_davis+=7;
	}
	if(flag_ball_action==1&&flag_ball_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o���Y�y�ʧ@�A����L����|�L����)
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
		ball_position_x-=30+v_davis;
		putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		ball_left_count--;
		if(ball_left_count==-1)
			ball_left_count=11;
		if(ball_left_count==9){
			ball_left_count=3;
			flag_ball_left=0;
			v_davis=0;
		}
		v_davis+=7;
	}
}
