#include"john.h"
#include"deep.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up3_key;
int do3_key;
int le3_key;
int ri3_key;
int at3_key;
int sk3_key;

void Deep::set(int player)
{
	if(player==2){
		up3_key=0x26;//�W 
		do3_key=0x28;//�U 
		le3_key=0x25;//�� 
		ri3_key=0x27;//�k 
		at3_key=0xBF;///
		sk3_key=0xBA;//;
		position_x=100;//����_�l��m 
		position_y=200;//����_�l��m 
	}
	else if(player==1){
		up3_key=0x57;//w
		do3_key=0x53;//s
		le3_key=0x41;//a
		ri3_key=0x44;//d
		at3_key=0x43;//c
		sk3_key=0x46;//f
		position_x=200;//����_�l��m 
		position_y=200;//����_�l��m 
	}
}
Deep::Deep(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//���ʹ��ɤ��μƾ�	
	wa_d_a=800;ha_d_a=160;pn_d_a=20;wn_d_a=10;hn_d_a=2;bkcolor_d_a=15;//�����ޯ���ɤ��μƾ�
	wa_b_a=400;ha_b_a=80;pn_b_a=5;wn_b_a=5;hn_b_a=1;bkcolor_b_a=15;//�C��ޯ���ɤ��μƾ�
	wa_b=320;ha_b=160;pn_b=8;wn_b=4;hn_b=2;bkcolor_b=15;//�C��ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 
	strcpy(filename_right,".\\roles_picture\\Deep\\deep_0.bmp");
	filename_right[strlen(".\\roles_picture\\Deep\\deep_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\Deep\\deep_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\Deep\\deep_0_mirror.bmp")]='\0';
//		
	strcpy(filename_slash_right_action,".\\roles_picture\\Deep\\deep_2-1.bmp");
	filename_slash_right_action[strlen(".\\roles_picture\\Deep\\deep_2-1.bmp")]='\0';

	strcpy(filename_slash_left_action,".\\roles_picture\\Deep\\deep_2_mirror-1.bmp");
	filename_slash_left_action[strlen(".\\roles_picture\\Deep\\deep_2_mirror-1.bmp")]='\0';	
//		
	strcpy(filename_wave_right_action,".\\roles_picture\\Deep\\deep_3.bmp");
	filename_wave_right_action[strlen(".\\roles_picture\\Deep\\deep_3.bmp")]='\0';

	strcpy(filename_wave_left_action,".\\roles_picture\\Deep\\deep_3_mirror.bmp");
	filename_wave_left_action[strlen(".\\roles_picture\\Deep\\deep_3_mirror.bmp")]='\0';	
//
	strcpy(filename_wave_right,".\\roles_picture\\Deep\\deep_ball.bmp");
	filename_wave_right[strlen(".\\roles_picture\\Deep\\deep_ball.bmp")]='\0';	

	strcpy(filename_wave_left,".\\roles_picture\\Deep\\deep_ball_mirror.bmp");
	filename_wave_left[strlen(".\\roles_picture\\Deep\\deep_ball_mirror.bmp")]='\0';	
//-----------------------------------------------------------------------------------------
	direction[1]=4;//�Ϥ���l���A 
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A
	slash_right_action_count=0;//���k�����Ϥ���l���A
	slash_left_action_count=9;//���������Ϥ���l���A
	wave_right_action_count=0;//���k�C��Ϥ���l���A
	wave_left_action_count=4;//�����C��Ϥ���l���A
	wave_right_count=0;//�C��Ϥ���l���A
	wave_left_count=3;//�C��Ϥ���l���A
	wave_position_x=position_x+110;//�C��_�l��m  
	wave_position_y=position_y+3;//�C��_�l��m 
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_slash_action_right=0, flag_slash_action_left=0;//���������ʧ@�O�_��������l���A 
	flag_wave_action=0,flag_wave_right=0,flag_wave_left=0;//�������Y�C��ʧ@�O�_��������l���A
}
void Deep::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Deep::control(){
	    if(GetAsyncKeyState(up3_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do3_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le3_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri3_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at3_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk3_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up3_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do3_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le3_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri3_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at3_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk3_key)!=0) button_down[5]=1;//�ޯ� 
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
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_slash_action_right==0){//�P�_�����X�۱��p 
			flag_slash_action_left=1;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_slash_action_left==0){//�P�_�����X�۱��p 
			flag_slash_action_right=1;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_wave_right==0&&flag_slash_action_right==0){//�P�_�C��X�۱��p 
			flag_wave_action=1;
			flag_wave_left=1;
			wave_position_x=position_x-81+30;//�C��_�l��m  
			wave_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_wave_left==0&&flag_slash_action_left==0){//�P�_�C��X�۱��p 
			flag_wave_action=1;
			flag_wave_right=1;
			wave_position_x=position_x+110-30;//�C��_�l��m  
			wave_position_y=position_y+3;
			
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
void Deep::recordimage(){
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	slash_right_action_picture=getimage2(filename_slash_right_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	slash_left_action_picture=getimage2(filename_slash_left_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	wave_right_action_picture=getimage2(filename_wave_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	wave_left_action_picture=getimage2(filename_wave_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	wave_right_picture=getimage2(filename_wave_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	wave_left_picture=getimage2(filename_wave_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
}
void Deep::print(){
        if(button_count==0&&direction[1]==4&&flag_slash_action_right==0&&flag_wave_action==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_slash_action_left==0&&flag_wave_action==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_slash();
		print_wave();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------���ʫ��O
			if(flag_slash_action_left==0&&flag_slash_action_right==0&&flag_wave_action==0){
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
		if(button_count==2&&flag_slash_action_left==0&&flag_slash_action_right==0&&flag_wave_action==0){
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

void Deep::print_slash(){
        if(flag_slash_action_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o�����ʧ@�A����L����|�L����)
			if(slash_right_action_count<=9){//�Y�ʧ@�٨S���� 
			   	position_x += 10;
				putimage(position_x,position_y, slash_right_action_picture[slash_right_action_count], OR_PUT);
				slash_right_action_count++;
				if(slash_right_action_count>9)	//�Y�ʧ@����@�b 
					slash_right_action_count=19;
			}
			if(slash_right_action_count<=19 && slash_right_action_count>9){
				position_x += 10;
			   	putimage(position_x,position_y, slash_right_action_picture[slash_right_action_count], OR_PUT);
				slash_right_action_count--;
				if(slash_right_action_count==9){
					slash_right_action_count=0;
					flag_slash_action_right=0;
				}
			}
		}
		if(flag_slash_action_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o�����ʧ@�A����L����|�L����)
			if(slash_left_action_count>=0 && slash_left_action_count<=9){//�Y�ʧ@�٨S���� 
				position_x -= 10;
			   	putimage(position_x,position_y, slash_left_action_picture[slash_left_action_count], OR_PUT);
				slash_left_action_count--;
				if(slash_left_action_count<0)	//�Y�ʧ@����@�b
					slash_left_action_count=10;
			}
			if(slash_left_action_count<=19 && slash_left_action_count>9){
				position_x -= 10;
			   	putimage(position_x,position_y, slash_left_action_picture[slash_left_action_count], OR_PUT);
				slash_left_action_count++;
				if(slash_left_action_count>19){
					slash_left_action_count=9;
					flag_slash_action_left=0;
				}
			}	
		} 
}

void Deep::print_wave(){
        if(flag_wave_action==1&&flag_wave_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o�C��ʧ@�A����L����|�L����)
			if(wave_right_action_count<=4){//�Y�ʧ@�٨S���� 				
			   	putimage(position_x,position_y, wave_right_action_picture[wave_right_action_count], OR_PUT);
				wave_right_action_count++;
			}
			else if(wave_right_action_count>4){//�Y�ʧ@����
				wave_right_action_count=0;
			   	flag_wave_action=0;
			}
		}
		else if(flag_wave_action==0&&flag_wave_right==1){
			wave_position_x+=30;
			putimage(wave_position_x,wave_position_y, wave_right_picture[wave_right_count], OR_PUT);
			wave_right_count=(++wave_right_count)%8;
			if(wave_position_x>=position_x+300){;
				wave_right_count=0;
				flag_wave_right=0;
			}
		}
	
		if(flag_wave_action==1&&flag_wave_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o�C��ʧ@�A����L����|�L����)
			if(wave_left_action_count>=0){//�Y�ʧ@�٨S���� 
			   	putimage(position_x,position_y, wave_left_action_picture[wave_left_action_count], OR_PUT);
				wave_left_action_count--;
			}
			else if(wave_left_action_count<0){//�Y�ʧ@����
				wave_left_action_count=4;
			   	flag_wave_action=0;
			}
		}
		else if(flag_wave_action==0&&flag_wave_left==1){
			wave_position_x-=30;
			putimage(wave_position_x,wave_position_y, wave_left_picture[wave_left_count], OR_PUT);
			wave_left_count--;
			if(wave_left_count==-1)
				wave_left_count=7;
			if(wave_position_x<=position_x-300){
				wave_left_count=4;
				flag_wave_left=0;
			}
		}
}
