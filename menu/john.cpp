#include"john.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
int up1_key;
int do1_key;
int le1_key;
int ri1_key;
int at1_key;
int sk1_key;

void John::set(int John){
	if(John==2){
		up1_key=0x26;//�W 
		do1_key=0x28;//�U 
		le1_key=0x25;//�� 
		ri1_key=0x27;//�k 
		at1_key=0xBF;///
		sk1_key=0xBA;//;
		position_x=100;//����_�l��m 
		position_y=200;//����_�l��m 
	}
	else if(John==1){
		up1_key=0x57;//w
		do1_key=0x53;//s
		le1_key=0x41;//a
		ri1_key=0x44;//d
		at1_key=0x43;//c
		sk1_key=0x46;//f
		position_x=200;//����_�l��m 
		position_y=200;//����_�l��m 
	}
}
John::John(){
	wa=800;ha=560;pn=70;wn=10;hn=7;bkcolor=15;//���ʹ��ɤ��μƾ�
	wa_d_a=480;ha_d_a=80;pn_d_a=6;wn_d_a=6;hn_d_a=1;bkcolor_d_a=15;//���Y���Чޯ���ɤ��μƾ�
	wa_d=364;ha_d=64;pn_d=12;wn_d=4;hn_d=3;bkcolor_d=15;//���Чޯ���ɤ��μƾ�
	wa_b_a=440;ha_b_a=80;pn_b_a=4;wn_b_a=4;hn_b_a=1;bkcolor_b_a=15;//���Y�y�ޯ���ɤ��μƾ�
	wa_b=324;ha_b=83;pn_b=4;wn_b=4;hn_b=1;bkcolor_b=15;//�y�ޯ���ɤ��μƾ�
//--------------------------------------------------------------------------------------�s���ɦW�� 
	strcpy(filename_right,".\\roles_picture\\John\\john_0.bmp");
	filename_right[strlen(".\\roles_picture\\John\\john_0.bmp")]='\0';

	strcpy(filename_left,".\\roles_picture\\John\\john_0_mirror.bmp");
	filename_left[strlen(".\\roles_picture\\John\\john_0_mirror.bmp")]='\0';
//		
	strcpy(filename_disk_right_action,".\\roles_picture\\John\\john_3_1_1.bmp");
	filename_disk_right_action[strlen(".\\roles_picture\\John\\john_3_1_1.bmp")]='\0';

	strcpy(filename_disk_left_action,".\\roles_picture\\John\\john_3_mirror_1_1.bmp");
	filename_disk_left_action[strlen(".\\roles_picture\\John\\john_3_mirror_1_1.bmp")]='\0';	
//
	strcpy(filename_disk_right,".\\roles_picture\\John\\john_biscuit.bmp");
	filename_disk_right[strlen(".\\roles_picture\\John\\john_biscuit.bmp")]='\0';	

	strcpy(filename_disk_left,".\\roles_picture\\John\\john_biscuit_mirror.bmp");
	filename_disk_left[strlen(".\\roles_picture\\John\\john_biscuit_mirror.bmp")]='\0';
//		
	strcpy(filename_ball_right_action,".\\roles_picture\\John\\john_2_1.bmp");
	filename_ball_right_action[strlen(".\\roles_picture\\John\\john_2_1.bmp")]='\0';

	strcpy(filename_ball_left_action,".\\roles_picture\\John\\john_2_mirror_1.bmp");
	filename_ball_left_action[strlen(".\\roles_picture\\John\\john_2_mirror_1.bmp")]='\0';	
//
	strcpy(filename_ball_right,".\\roles_picture\\John\\john_ball_1.bmp");
	filename_ball_right[strlen(".\\roles_picture\\John\\john_ball_1.bmp")]='\0';	

	strcpy(filename_ball_left,".\\roles_picture\\John\\john_ball_mirror_1.bmp");
	filename_ball_left[strlen(".\\roles_picture\\John\\john_ball_mirror_1.bmp")]='\0';	
//-----------------------------------------------------------------------------------------
	direction[1]=4;//�Ϥ���l���A 
	picture_right_count=0;//�Ϥ���l���A 
	picture_left_count=9;//�Ϥ���l���A
	attack_right_count=10;//�Ϥ���l���A
	attack_left_count=19;//�Ϥ���l���A
	disk_right_action_count=0;//���k���Y���йϤ���l���A
	disk_left_action_count=5;//�������Y���йϤ���l���A
	disk_right_count=0;//���йϤ���l���A
	disk_left_count=11;//���йϤ���l���A
	ball_right_action_count=3;//���k���Y�y�Ϥ���l���A
	ball_left_action_count=0;//�������Y�y�Ϥ���l���A
	ball_right_count=0;//�y�Ϥ���l���A
	ball_left_count=3;//�y�Ϥ���l���A
	disk_position_x=position_x;//���а_�l��m  
	disk_position_y=position_y-21;//���а_�l��m 
	ball_position_x=position_x+110;//�y�_�l��m  
	ball_position_y=position_y+3;//�y�_�l��m 
	flag_right=0;flag_left=0;//�����ʧ@�O�_���s��Q������l���A 
	flag_disk_action=0,flag_disk_right=0,flag_disk_left=0;//�������Y���аʧ@�O�_��������l���A 
	flag_ball_action=0,flag_ball_right=0,flag_ball_left=0;//�������Y�y�ʧ@�O�_��������l���A
}
void John::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void John::control(){
	    if(GetAsyncKeyState(up1_key)==0) button_down[0]=0;//�W 
        if(GetAsyncKeyState(do1_key)==0) button_down[1]=0;//�U 
        if(GetAsyncKeyState(le1_key)==0) button_down[2]=0;//�� 
        if(GetAsyncKeyState(ri1_key)==0) button_down[3]=0;//�k 
        if(GetAsyncKeyState(at1_key)==0) button_down[4]=0;//�� 
        if(GetAsyncKeyState(sk1_key)==0) button_down[5]=0;//�ޯ� 
        
        if(GetAsyncKeyState(up1_key)!=0) button_down[0]=1;//�W 
        if(GetAsyncKeyState(do1_key)!=0) button_down[1]=1;//�U 
        if(GetAsyncKeyState(le1_key)!=0) button_down[2]=1;//�� 
        if(GetAsyncKeyState(ri1_key)!=0) button_down[3]=1;//�k 
        if(GetAsyncKeyState(at1_key)!=0) button_down[4]=1;//�� 
        if(GetAsyncKeyState(sk1_key)!=0) button_down[5]=1;//�ޯ� 
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
			
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==3&&flag_disk_right==0&&flag_ball_action==0){//�P�_���ХX�۱��p 
			flag_disk_action=1;
			flag_disk_left=1;
		}						
		if(button_down[5]==1&&button_down[0]==1&&direction[1]==4&&flag_disk_left==0&&flag_ball_action==0){//�P�_���ХX�۱��p 
			flag_disk_action=1;
			flag_disk_right=1;
		}
		
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==3&&flag_ball_right==0&&flag_disk_action==0){//�P�_�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_left=1;
			ball_position_x=position_x-81+30;//�y�_�l��m  
			ball_position_y=position_y+3;
		}						
		if(button_down[5]==1&&button_down[1]==1&&direction[1]==4&&flag_ball_left==0&&flag_disk_action==0){//�P�_�y�X�۱��p 
			flag_ball_action=1;
			flag_ball_right=1;
			ball_position_x=position_x+110-30;//�y�_�l��m  
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
void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor){	
	void **img = new void*[pn];
	int k=0, w=wa/wn, h=ha/hn;	
	setbkcolor(bkcolor);
	cleardevice();
    readimagefile( filename, 0, 0, wa-1, ha-1);
	int size = imagesize(0, 0, w-1, h-1);
	for (int i=0; i<hn; i++) {
		for (int j=0; j<wn; j++) {			
  			img[k] = malloc(size);  //allocate space in memory
  			getimage(w*j, h*i, w*(j+1)-1, h*(i+1)-1, img[k]);
  			k++;
  			if (k==pn)
  				break;
		}
		if (k==pn)
  				break;
	}
	return img;
}
void John::recordimage(){
	picture_right=getimage2(filename_right,wa,ha,pn,wn,hn,bkcolor);
	picture_left=getimage2(filename_left,wa,ha,pn,wn,hn,bkcolor);
	disk_right_action_picture=getimage2(filename_disk_right_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	disk_left_action_picture=getimage2(filename_disk_left_action,wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a);
	disk_right_picture=getimage2(filename_disk_right,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	disk_left_picture=getimage2(filename_disk_left,wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d);
	ball_right_action_picture=getimage2(filename_ball_right_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_left_action_picture=getimage2(filename_ball_left_action,wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a);
	ball_right_picture=getimage2(filename_ball_right,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
	ball_left_picture=getimage2(filename_ball_left,wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b);
}
void John::print(){
        if(button_count==0&&direction[1]==4&&flag_disk_action==0&&flag_ball_action==0)//�S���ʧ@�B��V���k�� 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3&&flag_disk_action==0&&flag_ball_action==0)//�S���ʧ@�B��V������ 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
//-----------------------------------------------------------------------------------------------//�S��ޯ�        	
		print_disk();
		print_ball();
//------------------------------------------------------------------------------------------------   	
		if(button_count==1){
//------------------------------------------------------------------------------------���ʫ��O
			if(flag_disk_action==0&&flag_ball_action==0){
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
		if(button_count==2&&flag_disk_action==0&&flag_ball_action==0){
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
void John::print_disk(){
        if(flag_disk_action==1&&flag_disk_right==1){//�ޯ�Q���B��V���k(�ʧ@����)(����u�|���o���Y�ʧ@�A����L����|�L����)
			if(disk_right_action_count<=5){//�Y�ʧ@�٨S���� 
				disk_right_count=0;
				disk_position_x=position_x;
				disk_position_y=position_y-21;
			   	putimage(position_x,position_y, disk_right_action_picture[disk_right_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
				disk_right_action_count++;
			}
			else if(disk_right_action_count>5){//�Y�ʧ@����
				disk_right_action_count=0;
			   	flag_disk_action=0;
			}
		}
		else if(flag_disk_action==0&&flag_disk_right==1){
			disk_position_x+=40;
			putimage(disk_position_x,disk_position_y, disk_right_picture[disk_right_count], OR_PUT);
		}
			
		if(flag_disk_action==1&&flag_disk_left==1){//�ޯ�Q���B��V����(�ʧ@����)(����u�|���o���Y�ʧ@�A����L����|�L����)
			if(disk_left_action_count>=0){//�Y�ʧ@�٨S���� 
				disk_left_count=11;
				disk_position_x=position_x;
				disk_position_y=position_y-21;
			   	putimage(position_x,position_y, disk_left_action_picture[disk_left_action_count], OR_PUT);
				putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
				disk_left_action_count--;
			}
			else if(disk_left_action_count<0){//�Y�ʧ@����
				disk_left_action_count=5;
			   	flag_disk_action=0;
			}
		}
		else if(flag_disk_action==0&&flag_disk_left==1){
			disk_position_x-=40;
			putimage(disk_position_x,disk_position_y, disk_left_picture[disk_left_count], OR_PUT);
		}
		if(flag_disk_action==0&&flag_disk_right==1){//���ЦV�k���ɪ� disk_right_count
			disk_right_count=(++disk_right_count)%12;
			if(disk_right_count==0){
				disk_right_count=0;
				flag_disk_right=0;
			}
		}
		if(flag_disk_action==0&&flag_disk_left==1){//���ЦV�����ɪ� disk_left_count
			disk_left_count--;
			if(disk_left_count==-1){
				disk_left_count=11;
				flag_disk_left=0;
			}
		}
}
void John::print_ball(){
        if(flag_ball_right==1){//�ޯ�Q���B��V���k
			if(ball_right_action_count>=0&&flag_ball_action==1){//�Y�ʧ@�٨S���� 				
			   	putimage(position_x,position_y, ball_right_action_picture[ball_right_action_count], OR_PUT);
				ball_right_action_count--;
			}
			else if(ball_right_action_count<0){//�Y�ʧ@����
				ball_right_action_count=3;
				flag_ball_action=0;
			}
			ball_position_x+=30;
			putimage(ball_position_x,ball_position_y, ball_right_picture[ball_right_count], OR_PUT);		
		}
		
			
		if(flag_ball_left==1){//�ޯ�Q���B��V���� 
			if(ball_left_action_count<=3&&flag_ball_action==1){//�Y�ʧ@�٨S����			
			   	putimage(position_x-30/*��30���F�����Ϥ�*/,position_y, ball_left_action_picture[ball_left_action_count], OR_PUT);
				ball_left_action_count++;
			}
			else if(ball_left_action_count>3){//�Y�ʧ@����
				ball_left_action_count=0;
				flag_ball_action=0;
			}
			ball_position_x-=30;
			putimage(ball_position_x,ball_position_y, ball_left_picture[ball_left_count], OR_PUT);	
		}
		
		if(flag_ball_right==1){//�y�V�k���ɪ� ball_right_count
			ball_right_count=(++ball_right_count)%4;
			if(ball_position_x>=position_x+480){
				ball_right_count=0;
				flag_ball_right=0;
			}
		}
		if(flag_ball_left==1){//�y�V�����ɪ� ball_left_count
			ball_left_count--;
			if(ball_left_count==-1)
				ball_left_count=3;
			if(ball_position_x<=position_x-480){
				ball_left_count=3;
				flag_ball_left=0;
			}
		}
}
