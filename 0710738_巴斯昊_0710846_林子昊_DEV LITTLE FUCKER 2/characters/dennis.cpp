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
		position_x=500;//����_�l��m 
		position_y=200;//����_�l��m 
		direction[1]=3;//�Ϥ���l���A 
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
		direction[1]=4;//�Ϥ���l���A 
	}
}

Dennis::Dennis(){
	wa_r=800;ha_r=560;pn_r=70;wn_r=10;hn_r=7;bkcolor_r=15;//���k���ʹ��ɤ��μƾ�
	wa_l=800;ha_l=560;pn_l=70;wn_l=10;hn_l=7;bkcolor_l=15;//�������ʹ��ɤ��μƾ�
	
	wa_d_r_a=800;ha_d_r_a=80;pn_d_r_a=10;wn_d_r_a=10;hn_d_r_a=1;bkcolor_d_r_a=15;//���k�����ޯ���ɤ��μƾ�
	wa_d_l_a=800;ha_d_l_a=80;pn_d_l_a=10;wn_d_l_a=10;hn_d_l_a=1;bkcolor_d_l_a=15;//���������ޯ���ɤ��μƾ�

	wa_b_r_a=640;ha_b_r_a=80;pn_b_r_a=8;wn_b_r_a=8;hn_b_r_a=1;bkcolor_b_r_a=15;//���k���Y�y�ޯ���ɤ��μƾ�
	wa_b_l_a=640;ha_b_l_a=80;pn_b_l_a=8;wn_b_l_a=8;hn_b_l_a=1;bkcolor_b_l_a=15;//�������Y�y�ޯ���ɤ��μƾ�

	wa_b_r=328;ha_b_r=250;pn_b_r=12;wn_b_r=4;hn_b_r=3;bkcolor_b_r=15;//���k���Y�y�ޯ���ɤ��μƾ�
	wa_b_l=328;ha_b_l=250;pn_b_l=12;wn_b_l=4;hn_b_l=3;bkcolor_b_l=15;//�������Y�y�ޯ���ɤ��μƾ�
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
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A
	down_right_count=30;//�Ϥ���l���A
	down_left_count=39;//�Ϥ���l���A
	defense_right_count=57;//�Ϥ���l���A
	defense_left_count=52;//�Ϥ���l���A
	kick_right_action_count=0;//���k�����Ϥ���l���A
	kick_left_action_count=9;//���������Ϥ���l���A
	ball_right_action_count=0;//���k���Y�y�Ϥ���l���A
	ball_left_action_count=7;//�������Y�y�Ϥ���l���A
	ball_right_count=0;//�y�Ϥ���l���A
	ball_left_count=3;//�y�Ϥ���l���A
	ball_position_x=-1000;//���Y�y�_�l��m  
	ball_position_y=-1000;//���Y�y�_�l��m 
	manyball_position_x=-1000;//���Y�y�_�l��m  
	manyball_position_y=-1000;//���Y�y�_�l��m 
	manyball_position_x=-1000;
	manyball_position_y=-1000;
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_down=0;//��������O�_���Q��������l���A
	flag_defense=0;//��������O�_���Q�~����l���A
	flag_kick_action_right=0, flag_kick_action_left=0;//���������ʧ@�O�_��������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�������Y���Y�y�ʧ@�O�_��������l���A
	number_of_ball=0;//�O���y���Ӽ� 
	flag_manyball_remain=0;//�����e�@���y�O�_�~��s�b 
	flag_ball_past=0;//�y�����k���A 
	flag_ball_record_receive=0;//�O���y�O�_�Q���� 
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
		
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_kick_action_right==0
		&&flag_down==0&&flag_defense==0)//�P�_�����X�۱��p 
			flag_kick_action_left=1;					
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_kick_action_left==0
		&&flag_down==0&&flag_defense==0)//�P�_�����X�۱��p 
			flag_kick_action_right=1;
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_kick_action_right==0
		&&number_of_ball<2&&flag_down==0&&flag_defense==0){//�P�_���Y�y�X�۱��p 
			if(flag_manyball_remain==1&&flag_ball_record_receive==0){
				skills_record();
			}
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=ball_ori_position_x=position_x-81+30;//���Y�y�_�l��m  
			ball_position_y=ball_ori_position_y=position_y+3;	
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_kick_action_left==0
		&&number_of_ball<2&&flag_down==0&&flag_defense==0){//�P�_���Y�y�X�۱��p 
			if(flag_manyball_remain==1&&flag_ball_record_receive==0){
				skills_record();
			}
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=ball_ori_position_x=position_x+110-30;//���Y�y�_�l��m  
			ball_position_y=ball_ori_position_y=position_y+3;
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
	picture_right=getimage2(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage2(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	kick_right_action_picture=getimage2(filename_kick_right_action,wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a);
	kick_left_action_picture=getimage2(filename_kick_left_action,wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r);
	ball_left_picture=getimage2(filename_ball_left,wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l);
}
void Dennis::print(){
        if(button_count==0&&direction[1]==4&&flag_kick_action_right==0&&flag_ball_action==0&&flag_down==0&&flag_defense==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_kick_action_left==0&&flag_ball_action==0&&flag_down==0&&flag_defense==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_kick();
		print_ball();
		print_manyball();
		if(flag_defense==0)
			print_down();
		if(flag_down==0)
			print_defense();
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
void Dennis::skills_record(){
	if(number_of_ball>=1){
		if(flag_ball_past==1){
			manyball_left_count=ball_left_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;	
			last_manyball_position_x=ball_ori_position_x-480;
			flag_ball_record_receive=1;
		}
		if(flag_ball_past==2){
			manyball_right_count=ball_right_count;
			manyball_position_x=ball_position_x;
			manyball_position_y=ball_position_y;
			last_manyball_position_x=ball_ori_position_x+480;
			flag_ball_record_receive=1;
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
			number_of_ball++;
			ball_right_action_count=0;
			flag_ball_action=0;
		}
	}
	else if(flag_ball_action==0&&flag_ball_right==1){
		ball_position_x+=30+v_dennis;
		putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);
		v_dennis+=4;
	}
	if(flag_ball_action==1&&flag_ball_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o���Y�y�ʧ@�A����L����|�L����)
		if(ball_left_action_count>=0){//�Y�ʧ@�٨S���� 
		   	putimage(position_x,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
			ball_left_action_count--;
		}		
		else if(ball_left_action_count<0){//�Y�ʧ@����
			number_of_ball++;
			ball_left_action_count=7;
			flag_ball_action=0;
		}
	}
	else if(flag_ball_action==0&&flag_ball_left==1){
		ball_position_x-=30+v_dennis;
		putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);
		v_dennis+=4;
	}
		if(flag_ball_right==1){//�y�V�k���ɪ� ball_right_count
			ball_right_count++;
			if(ball_right_count==4)
				ball_right_count=8;
			if(ball_right_count==12){
				ball_right_count=0;
				v_dennis=0;
			}
			flag_manyball_remain=1;
			flag_ball_past=2;
			if(ball_position_x>=ball_ori_position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
				flag_manyball_remain=0;
				flag_ball_past=0;
				number_of_ball--;
				ball_position_x=-1000;
				ball_position_y=-1000;
			}
		}
		if(flag_ball_left==1){//�y�V�����ɪ� ball_left_count
			ball_left_count--;
			if(ball_left_count==-1)
				ball_left_count=11;
			if(ball_left_count==7){
				ball_left_count=3;
				v_dennis=0;
			}
			flag_manyball_remain=1;
			flag_ball_past=1;
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
void Dennis::print_manyball(){
	if(flag_manyball_remain==1&&flag_ball_past==1&&number_of_ball>=1&&flag_ball_record_receive==1){
		if(manyball_position_x>=last_manyball_position_x){
			manyball_position_x-=30;
			putimage(manyball_position_x,manyball_position_y, ball_left_picture[manyball_left_count], OR_PUT);
			manyball_left_count--;
			if(manyball_left_count==-1)
				manyball_left_count=11;
			if(manyball_left_count==7){
				manyball_left_count=3;
			}
			if(manyball_position_x<last_manyball_position_x){//�y�V�����ɪ� manyball_left_count
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
			manyball_position_x+=30;
			putimage(manyball_position_x,manyball_position_y, ball_right_picture[manyball_right_count], OR_PUT);
			manyball_right_count++;
			if(manyball_right_count==4)
				manyball_right_count=8;
			if(manyball_right_count==12){
				manyball_right_count=0;
			}
			if(manyball_position_x>last_manyball_position_x){//�y�V�k���ɪ� manyball_right_count
				flag_manyball_remain=0;
				number_of_ball--;
				flag_ball_record_receive=0;
				manyball_position_x=-1000;
				manyball_position_y=-1000;
			}			
		}
	}
	if(flag_manyball_remain==0)
		number_of_ball=0;
}
void Dennis::print_down(){
	if(flag_down==1&&direction[1]==4){//����Q���˥B��V���k 
					position_x-=15;
			    	putimage(position_x,position_y, picture_right[down_right_count], OR_PUT);
			    	down_right_count++;
			    	if(down_right_count>35){
			    		down_right_count=30;
			    		flag_down=0;
					}
				}
	else if(flag_down==1&&direction[1]==3){//����Q���˥B��V���� 
					position_x+=15;
			    	putimage(position_x,position_y, picture_left[down_left_count], OR_PUT);
			    	down_left_count--;
			    	if(down_left_count<34){
			    		down_left_count=39;
			    		flag_down=0;
					}
				}
}
void Dennis::print_defense(){
	if(flag_defense==1&&direction[1]==4){//����Q�~�B��V���k 
					position_x-=5;
			    	putimage(position_x,position_y, picture_right[defense_right_count], OR_PUT);
			    	defense_right_count--;
			    	if(defense_right_count<53){
			    		defense_right_count=57;
			    		flag_defense=0;
					}
				}
	else if(flag_defense==1&&direction[1]==3){//����Q�~�B��V���� 
					position_x+=5;
			    	putimage(position_x,position_y, picture_left[defense_left_count], OR_PUT);
			    	defense_left_count++;
			    	if(defense_left_count>56){
			    		defense_left_count=52;
			    		flag_defense=0;
					}
				}
}
void Dennis::getdata(int &p2_position_x,int &p2_position_y,int &p2_skill1_position_x,int &p2_skill1_position_y,int &p2_skill2_position_x,
int &p2_skill2_position_y,int &p2_manyskill1_position_x,int &p2_manyskill1_position_y,int &p2_manyskill2_position_x,int &p2_manyskill2_position_y,
int &p2_width,int &p2_height,int &p2_skill1_width,int &p2_skill1_height,int &p2_skill2_width,int &p2_skill2_height,
int &p2_button_down){
	p2_position_x=position_x;//����ثe��m 
	p2_position_y=position_y;//����ثe��m 
	if(flag_kick_action_right==1||flag_kick_action_left==1){
		p2_skill1_position_x=position_x;//�z�o�ޯ�ثe��m 
		p2_skill1_position_y=position_y;//�z�o�ޯ�ثe��m 
	}
	else{
		p2_skill1_position_x=-1000;//�z�o�ޯ�ثe��m 
		p2_skill1_position_y=-1000;//�z�o�ޯ�ثe��m
	}
	p2_skill2_position_x=ball_position_x;//�y�ޯ�ثe��m 
	p2_skill2_position_y=ball_position_y;//�y�ޯ�ثe��m
	p2_manyskill1_position_x=-1000;
	p2_manyskill1_position_y=-1000;
	p2_manyskill2_position_x=manyball_position_x;//�B�~�y�ޯ�ثe��m 
	p2_manyskill2_position_y=manyball_position_y;//�B�~�y�ޯ�ثe��m
	p2_width=wa_r/wn_r;p2_height=ha_r/hn_r;//������e 
	p2_skill1_width=wa_r/wn_r;p2_skill1_height=ha_r/hn_r;//�z�o���e 
	p2_skill2_width=wa_b_r/wn_b_r;p2_skill2_height=ha_b_r/hn_b_r;//�y���e 
	p2_button_down=button_down[4];
}
void Dennis::setdata(int down_switch,int defense_switch){
	if(down_switch==1)
		flag_down=1;
	if(defense_switch==1)
		flag_defense=1;
}
