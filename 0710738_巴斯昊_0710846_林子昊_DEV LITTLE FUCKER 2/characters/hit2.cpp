#include"julian.h"
#include"john.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include"hit2.h"

int bar_detect(int *down_switch_1,int *defense_switch_1,int *down_switch_2,int *defense_switch_2, int *bar_1, int *bar_2)
{
	if((*down_switch_1))
		(*bar_1) -= 20;
	if((*defense_switch_1))
		(*bar_1) -= 5;
	if((*down_switch_2))
		(*bar_2) -= 20;
	if((*defense_switch_2))
		(*bar_2) -= 5;
	
	if((*bar_1) < 0) 
		(*bar_1) = 0;
	else if((*bar_2) < 0)
		(*bar_2) = 0;
		
	if((*bar_1) > 0 && (*bar_2) > 0)
		return 1;
	else
		return 0;
}

int mode3(int p1_position_x,int p1_position_y,int p1_skill1_position_x,int p1_skill1_position_y,int p1_skill2_position_x,//圖檔座標 
int p1_skill2_position_y,int p1_manyskill1_position_x,int p1_manyskill1_position_y,int p1_manyskill2_position_x,int p1_manyskill2_position_y,
int p2_position_x,int p2_position_y,int p2_skill1_position_x,int p2_skill1_position_y,int p2_skill2_position_x,int p2_skill2_position_y,
int p2_manyskill1_position_x,int p2_manyskill1_position_y,int p2_manyskill2_position_x,int p2_manyskill2_position_y,
int p1_width,int p1_height,int p1_skill1_width,int p1_skill1_height,int p1_skill2_width,int p1_skill2_height,//圖檔長寬 
int p2_width,int p2_height,int p2_skill1_width,int p2_skill1_height,int p2_skill2_width,int p2_skill2_height,
int p1_button_down,int p2_button_down,//普攻按鍵參數 
int *p1_skill1_switch,int *p1_skill2_switch,int *p2_skill1_switch,int *p2_skill2_switch,//決定是否繼續顯示圖片，0為否，1為是
int *p1_manyskill1_switch,int *p1_manyskill2_switch,int *p2_manyskill1_switch,int *p2_manyskill2_switch,
int *p1_down_switch,int *p1_defense_switch,int *p2_down_switch,int *p2_defense_switch, int keep1, int keep2,
int *bar1, int *bar2){
//--------------------------------------------------------------------------------------考慮p1是否被打到的情形

	//                 被disk打到時 
	if((p2_skill1_position_x-p1_position_x<=p1_width&&p2_skill1_position_x-p1_position_x>=0&&//招式相對於角色在右上方 
		p1_position_y-p2_skill1_position_y<=p2_skill1_height&&p1_position_y-p2_skill1_position_y>=0)|| 
		(p2_skill1_position_x-p1_position_x<=p1_width&&p2_skill1_position_x-p1_position_x>=0&&//招式相對於角色在右下方 
		p2_skill1_position_y-p1_position_y<=p1_height&&p2_skill1_position_y-p1_position_y>=0)||
		(p1_position_x-p2_skill1_position_x<=p2_skill1_width&&p1_position_x-p2_skill1_position_x>=0&&//招式相對於角色在左上方 
		p1_position_y-p2_skill1_position_y<=p2_skill1_height&&p1_position_y-p2_skill1_position_y>=0)|| 
		(p1_position_x-p2_skill1_position_x<=p2_skill1_width&&p1_position_x-p2_skill1_position_x>=0&&//招式相對於角色在左下方 
		p2_skill1_position_y-p1_position_y<=p1_height&&p2_skill1_position_y-p1_position_y>=0)
		){
		(*p1_down_switch)=1;
	}
	//                 被manydisk打到時 
	else if((p2_manyskill1_position_x-p1_position_x<=p1_width&&p2_manyskill1_position_x-p1_position_x>=0&&//招式相對於角色在右上方 
		p1_position_y-p2_manyskill1_position_y<=p2_skill1_height&&p1_position_y-p2_manyskill1_position_y>=0)|| 
		(p2_manyskill1_position_x-p1_position_x<=p1_width&&p2_manyskill1_position_x-p1_position_x>=0&&//招式相對於角色在右下方 
		p2_manyskill1_position_y-p1_position_y<=p1_height&&p2_manyskill1_position_y-p1_position_y>=0)||
		(p1_position_x-p2_manyskill1_position_x<=p2_skill1_width&&p1_position_x-p2_manyskill1_position_x>=0&&//招式相對於角色在左上方 
		p1_position_y-p2_manyskill1_position_y<=p2_skill1_height&&p1_position_y-p2_manyskill1_position_y>=0)|| 
		(p1_position_x-p2_manyskill1_position_x<=p2_skill1_width&&p1_position_x-p2_manyskill1_position_x>=0&&//招式相對於角色在左下方 
		p2_manyskill1_position_y-p1_position_y<=p1_height&&p2_manyskill1_position_y-p1_position_y>=0))
		{
		(*p1_down_switch)=1;
	}
//                 被ball打到時 
	else if((p2_skill2_position_x-p1_position_x<=p1_width&&p2_skill2_position_x-p1_position_x>=0&&//招式相對於角色在右上方 
		p1_position_y-p2_skill2_position_y<=p2_skill2_height&&p1_position_y-p2_skill2_position_y>=0)|| 
		(p2_skill2_position_x-p1_position_x<=p1_width&&p2_skill2_position_x-p1_position_x>=0&&//招式相對於角色在右下方 
		p2_skill2_position_y-p1_position_y<=p1_height&&p2_skill2_position_y-p1_position_y>=0)||
		(p1_position_x-p2_skill2_position_x<=p2_skill2_width&&p1_position_x-p2_skill2_position_x>=0&&//招式相對於角色在左上方 
		p1_position_y-p2_skill2_position_y<=p2_skill2_height&&p1_position_y-p2_skill2_position_y>=0)|| 
		(p1_position_x-p2_skill2_position_x<=p2_skill2_width&&p1_position_x-p2_skill2_position_x>=0&&//招式相對於角色在左下方 
		p2_skill2_position_y-p1_position_y<=p1_height&&p2_skill2_position_y-p1_position_y>=0)
		){
		(*p1_down_switch)=1;
	}
//                 被manyball打到時 
	else if((p2_manyskill2_position_x-p1_position_x<=p1_width&&p2_manyskill2_position_x-p1_position_x>=0&&//招式相對於角色在右上方 
		p1_position_y-p2_manyskill2_position_y<=p2_skill2_height&&p1_position_y-p2_manyskill2_position_y>=0)|| 
		(p2_manyskill2_position_x-p1_position_x<=p1_width&&p2_manyskill2_position_x-p1_position_x>=0&&//招式相對於角色在右下方 
		p2_manyskill2_position_y-p1_position_y<=p1_height&&p2_manyskill2_position_y-p1_position_y>=0)||
		(p1_position_x-p2_manyskill2_position_x<=p2_skill2_width&&p1_position_x-p2_manyskill2_position_x>=0&&//招式相對於角色在左上方 
		p1_position_y-p2_manyskill2_position_y<=p2_skill2_height&&p1_position_y-p2_manyskill2_position_y>=0)|| 
		(p1_position_x-p2_manyskill2_position_x<=p2_skill2_width&&p1_position_x-p2_manyskill2_position_x>=0&&//招式相對於角色在左下方 
		p2_manyskill2_position_y-p1_position_y<=p1_height&&p2_manyskill2_position_y-p1_position_y>=0)){
		(*p1_down_switch)=1;
	}
	else
		(*p1_down_switch)=0;
//                 被普攻打到時
	if(p2_button_down==1){
		if((p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//招式相對於角色在右上方 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)|| 
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//招式相對於角色在右下方 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)||
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//招式相對於角色在左上方 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)|| 
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//招式相對於角色在左下方 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)
			){
			(*p1_defense_switch)=1;
			//printf("*\n");
		}
	}
	else
		(*p1_defense_switch)=0;
		
//--------------------------------------------------------------------------------------考慮p2是否被打到的情形
	//                 被disk打到時 
	if((p1_skill1_position_x-p2_position_x<=p2_width&&p1_skill1_position_x-p2_position_x>=0&&//招式相對於角色在右上方 
		p2_position_y-p1_skill1_position_y<=p1_skill1_height&&p2_position_y-p1_skill1_position_y>=0)|| 
		(p1_skill1_position_x-p2_position_x<=p2_width&&p1_skill1_position_x-p2_position_x>=0&&//招式相對於角色在右下方 
		p1_skill1_position_y-p2_position_y<=p2_height&&p1_skill1_position_y-p2_position_y>=0)||
		(p2_position_x-p1_skill1_position_x<=p1_skill1_width&&p2_position_x-p1_skill1_position_x>=0&&//招式相對於角色在左上方 
		p2_position_y-p1_skill1_position_y<=p1_skill1_height&&p2_position_y-p1_skill1_position_y>=0)|| 
		(p2_position_x-p1_skill1_position_x<=p1_skill1_width&&p2_position_x-p1_skill1_position_x>=0&&//招式相對於角色在左下方 
		p1_skill1_position_y-p2_position_y<=p2_height&&p1_skill1_position_y-p2_position_y>=0)
		){
		(*p2_down_switch)=1;
	}
	//                 被manydisk打到時 
	else if((p1_manyskill1_position_x-p2_position_x<=p2_width&&p1_manyskill1_position_x-p2_position_x>=0&&//招式相對於角色在右上方 
		p2_position_y-p1_manyskill1_position_y<=p1_skill1_height&&p2_position_y-p1_manyskill1_position_y>=0)|| 
		(p1_manyskill1_position_x-p2_position_x<=p2_width&&p1_manyskill1_position_x-p2_position_x>=0&&//招式相對於角色在右下方 
		p1_manyskill1_position_y-p2_position_y<=p2_height&&p1_manyskill1_position_y-p2_position_y>=0)||
		(p2_position_x-p1_manyskill1_position_x<=p1_skill1_width&&p2_position_x-p1_manyskill1_position_x>=0&&//招式相對於角色在左上方 
		p2_position_y-p1_manyskill1_position_y<=p1_skill1_height&&p2_position_y-p1_manyskill1_position_y>=0)|| 
		(p2_position_x-p1_manyskill1_position_x<=p1_skill1_width&&p2_position_x-p1_manyskill1_position_x>=0&&//招式相對於角色在左下方 
		p1_manyskill1_position_y-p2_position_y<=p2_height&&p1_manyskill1_position_y-p2_position_y>=0))
		{
		(*p2_down_switch)=1;
	}
//                 被ball打到時 
	else if((p1_skill2_position_x-p2_position_x<=p2_width&&p1_skill2_position_x-p2_position_x>=0&&//招式相對於角色在右上方 
		p2_position_y-p1_skill2_position_y<=p1_skill2_height&&p2_position_y-p1_skill2_position_y>=0)|| 
		(p1_skill2_position_x-p2_position_x<=p2_width&&p1_skill2_position_x-p2_position_x>=0&&//招式相對於角色在右下方 
		p1_skill2_position_y-p2_position_y<=p2_height&&p1_skill2_position_y-p2_position_y>=0)||
		(p2_position_x-p1_skill2_position_x<=p1_skill2_width&&p2_position_x-p1_skill2_position_x>=0&&//招式相對於角色在左上方 
		p2_position_y-p1_skill2_position_y<=p1_skill2_height&&p2_position_y-p1_skill2_position_y>=0)|| 
		(p2_position_x-p1_skill2_position_x<=p1_skill2_width&&p2_position_x-p1_skill2_position_x>=0&&//招式相對於角色在左下方 
		p1_skill2_position_y-p2_position_y<=p2_height&&p1_skill2_position_y-p2_position_y>=0)
		){
		(*p2_down_switch)=1;
	}
//                 被manyball打到時 
	else if((p1_manyskill2_position_x-p2_position_x<=p2_width&&p1_manyskill2_position_x-p2_position_x>=0&&//招式相對於角色在右上方 
		p2_position_y-p1_manyskill2_position_y<=p1_skill2_height&&p2_position_y-p1_manyskill2_position_y>=0)|| 
		(p1_manyskill2_position_x-p2_position_x<=p2_width&&p1_manyskill2_position_x-p2_position_x>=0&&//招式相對於角色在右下方 
		p1_manyskill2_position_y-p2_position_y<=p2_height&&p1_manyskill2_position_y-p2_position_y>=0)||
		(p2_position_x-p1_manyskill2_position_x<=p1_skill2_width&&p2_position_x-p1_manyskill2_position_x>=0&&//招式相對於角色在左上方 
		p2_position_y-p1_manyskill2_position_y<=p1_skill2_height&&p2_position_y-p1_manyskill2_position_y>=0)|| 
		(p2_position_x-p1_manyskill2_position_x<=p1_skill2_width&&p2_position_x-p1_manyskill2_position_x>=0&&//招式相對於角色在左下方 
		p1_manyskill2_position_y-p2_position_y<=p2_height&&p1_manyskill2_position_y-p2_position_y>=0)){
		(*p2_down_switch)=1;
	}
	else
		(*p2_down_switch)=0;
//                 被普攻打到時
	if(p1_button_down==1){
		if((p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//招式相對於角色在右上方 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)|| 
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//招式相對於角色在右下方 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)||
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//招式相對於角色在左上方 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)|| 
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//招式相對於角色在左下方 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)
			){
			(*p2_defense_switch)=1;
		}
	}
	else
		(*p2_defense_switch)=0;
		
	if(keep1){
		*(p1_down_switch) = 0;
		*(p1_defense_switch) = 0;
	}
	if(keep2){
		*(p2_down_switch) = 0;
		*(p2_defense_switch) = 0;
	}
	
	if(*(p1_down_switch) == 1 || *(p1_defense_switch) == 1 || *(p2_down_switch) == 1 || *(p2_defense_switch) == 1)
		return bar_detect(p1_down_switch, p1_defense_switch, p2_down_switch, p2_defense_switch, bar1, bar2);
	else
		return 1;
}
