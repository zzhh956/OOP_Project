#include"player.h"
#include<iostream>
#include<stdio.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
//#define W_KEY 0x57
//#define S_KEY 0x53
//#define A_KEY 0x41
//#define D_KEY 0x44
//#define C_KEY 0x43
int w,s,a,d,c;
void playerset(){
	w=0x57;
	s=0x53;
	a=0x41;
	d=0x44;
	c=0x43;
}
Player::Player(char *receive_file_right,char *receive_file_left,int wa_R,int ha_R,int pn_R,
int wn_R,int hn_R,int bkcolor_R,int wa_L,int ha_L,int pn_L,int wn_L,int hn_L,int bkcolor_L){
	wa_r=wa_R;ha_r=ha_R;pn_r=pn_R;wn_r=wn_R;hn_r=hn_R;bkcolor_r=bkcolor_R;//往右移動圖檔切割數據
	wa_l=wa_L;ha_l=ha_L;pn_l=pn_L;wn_l=wn_L;hn_l=hn_L;bkcolor_l=bkcolor_L;//往左移動圖檔切割數據
	//printf("%d %d %d %d %d %d",wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	for(int i=0;i<100;i++)
		if(receive_file_right[i]!='\0')
			filename_right[i]=receive_file_right[i];
		else{
			filename_right[i]='\0';
			break;	
		}
	for(int i=0;i<100;i++)
		if(receive_file_left[i]!='\0')
			filename_left[i]=receive_file_left[i];
		else{
			filename_left[i]='\0';
			break;
		}
	
	direction[1]=4;//圖片初始狀態 
	picture_right_count=0;//圖片初始狀態 
	picture_left_count=9;//圖片初始狀態
	attack_right_count=10;//圖片初始狀態
	attack_left_count=19;//圖片初始狀態
	position_x=100;//角色起始位置 
	position_y=500;//角色起始位置 
	flag_right=0;flag_left=0;//紀錄動作是否有連續被按的初始狀態 
}
void Player::setposition(int x,int y){
	position_x=x;
	position_y=y;
}
void Player::control(){
	    if(GetAsyncKeyState(w)==0) button_down[0]=0;//上 
        if(GetAsyncKeyState(s)==0) button_down[1]=0;//下 
        if(GetAsyncKeyState(a)==0) button_down[2]=0;//左 
        if(GetAsyncKeyState(d)==0) button_down[3]=0;//右 
        if(GetAsyncKeyState(c)==0) button_down[4]=0;//攻 
        
        if(GetAsyncKeyState(w)!=0){ button_down[0]=1;
		//printf("*\n");
		}//上 
        if(GetAsyncKeyState(s)!=0) button_down[1]=1;//下 
        if(GetAsyncKeyState(a)!=0) button_down[2]=1;//左 
        if(GetAsyncKeyState(d)!=0) button_down[3]=1;//右 
        if(GetAsyncKeyState(c)!=0) button_down[4]=1;//攻 

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
        
	    button_count=0;
	    for(int i=0;i<5;i++)
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
	   }
}
void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor)
{	
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
	//printf("*");
	return img;
}
void Player::recordimage(){

	//printf("%d %d %d %d %d %d",wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_right=getimage(filename_right,wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r);
	picture_left=getimage(filename_left,wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l);
	//getch();
	//cleardevice();
	//putimage(100,100, picture_right[3], COPY_PUT);
}
void Player::print(){
	    setvisualpage(cur_page);//  0 1
		      
        cur_page = -cur_page + 1;    
        setactivepage(cur_page);//  1 0
        setbkcolor(BLACK);
        cleardevice();
        //readimagefile(".\\roles_picture\\John\\XgcK0Ub.jpg", 0, 0, 900, 500);
        //printf("%d\n",button_count);

        if(button_count==0&&direction[1]==4)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_right[picture_right_count], OR_PUT);
        else if(button_count==0&&direction[1]==3)//沒有動作且方向為右時 
        	putimage(position_x,position_y, picture_left[picture_left_count], OR_PUT);
        	
		if(button_count==1){
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
//---------------------------------------------------------------------------------------			
		}
		if(button_count==2){
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
        //k=(++k)%pn;
}
