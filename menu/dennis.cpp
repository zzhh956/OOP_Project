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
		up8_key=0x26;//�W 
		do8_key=0x28;//�U 
		le8_key=0x25;//�� 
		ri8_key=0x27;//�k 
		at8_key=0xBF;///
		sk8_key=0xBA;//;
		position_x=100;//����_�l��m 
		position_y=200;//����_�l��m 
	}
	else if(player==1){
		up8_key=0x57;//w
		do8_key=0x53;//s
		le8_key=0x41;//a
		ri8_key=0x44;//d
		at8_key=0x43;//c
		sk8_key=0x46;//f
		position_x=200;//����_�l��m 
		position_y=200;//����_�l��m  
	}
}
Dennis::Dennis(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//���ʹ��ɤ��μƾ�
	wa_d_a=800;ha_d_a=80;pn_d_a=10;wn_d_a=10;hn_d_a=1;bkcolor_d_a=15;//�����ޯ���ɤ��μƾ�
	wa_b_a=640;ha_b_a=80;pn_b_a=8;wn_b_a=8;hn_b_a=1;bkcolor_b_a=15;//���Y�y�ޯ���ɤ��μƾ�
	wa_b=328;ha_b=250;pn_b=12;wn_b=4;hn_b=3;bkcolor_b=15;//���Y�y�ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 
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
	direction[1]=4;//�Ϥ���l���A 
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A
	kick_right_action_count=0;//���k�����Ϥ���l���A
	kick_left_action_count=9;//���������Ϥ���l���A
	ball_right_action_count=0;//���k���Y�y�Ϥ���l���A
	ball_left_action_count=7;//�������Y�y�Ϥ���l���A
	ball_right_count=0;//�y�Ϥ���l���A
	ball_left_count=3;//�y�Ϥ���l���A
	ball_position_x=position_x+110;//���Y�y�_�l��m  
	ball_position_y=position_y+3;//���Y�y�_�l��m 
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_kick_action_right=0, flag_kick_action_left=0;//���������ʧ@�O�_��������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�������Y���Y�y�ʧ@�O�_��������l���A
}
void Dennis::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Dennis::control(){
	    if(GetAsyncKeyState(up8_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do8_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le8_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri8_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at8_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk8_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up8_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do8_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le8_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri8_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at8_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk8_key)!=0) button_down[5]=1;//�ޯ� 
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
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_kick_action_right==0)//�P�_�����X�۱��p 
			flag_kick_action_left=1;					
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_kick_action_left==0)//�P�_�����X�۱��p 
			flag_kick_action_right=1;
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_kick_action_right==0){//�P�_���Y�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//���Y�y�_�l��m  
			ball_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_kick_action_left==0){//�P�_���Y�y�X�۱��p 
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
        if(button_count==0&&direction[1]==4&&flag_kick_action_right==0&&flag_ball_action==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_kick_action_left==0&&flag_ball_action==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_kick();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------���ʫ��O
			if(flag_kick_action_left==0&&flag_kick_action_right==0&&flag_ball_action==0){
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
		if(button_count==2&&flag_kick_action_left==0&&flag_kick_action_right==0&&flag_ball_action==0){
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
void Dennis::print_kick(){
        if(flag_kick_action_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o�����ʧ@�A����L����|�L����)
			if(kick_right_action_count<=9){//�Y�ʧ@�٨S���� 
			   	position_x+=20;
				putimage(position_x,position_y-20, kick_right_action_picture[kick_right_action_count], OR_PUT);
				kick_right_action_count++;
				if(kick_right_action_count>9){
					kick_right_action_count=0;
					flag_kick_action_right=0;
				}
			}
		}
		if(flag_kick_action_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o�����ʧ@�A����L����|�L����)
			if(kick_left_action_count>=0){//�Y�ʧ@�٨S���� 
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
	if(flag_ball_action==1&&flag_ball_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o���Y�y�ʧ@�A����L����|�L����)
		if(ball_right_action_count<=7){//�Y�ʧ@�٨S���� 				
		   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
			ball_right_action_count++;
		}		
		else if(ball_right_action_count>7){//�Y�ʧ@����
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
	if(flag_ball_action==1&&flag_ball_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o���Y�y�ʧ@�A����L����|�L����)
		if(ball_left_action_count>=0){//�Y�ʧ@�٨S���� 
		   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
			ball_left_action_count--;
		}		
		else if(ball_left_action_count<0){//�Y�ʧ@����
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
