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

int mode3(int p1_position_x,int p1_position_y,int p1_skill1_position_x,int p1_skill1_position_y,int p1_skill2_position_x,//���ɮy�� 
int p1_skill2_position_y,int p1_manyskill1_position_x,int p1_manyskill1_position_y,int p1_manyskill2_position_x,int p1_manyskill2_position_y,
int p2_position_x,int p2_position_y,int p2_skill1_position_x,int p2_skill1_position_y,int p2_skill2_position_x,int p2_skill2_position_y,
int p2_manyskill1_position_x,int p2_manyskill1_position_y,int p2_manyskill2_position_x,int p2_manyskill2_position_y,
int p1_width,int p1_height,int p1_skill1_width,int p1_skill1_height,int p1_skill2_width,int p1_skill2_height,//���ɪ��e 
int p2_width,int p2_height,int p2_skill1_width,int p2_skill1_height,int p2_skill2_width,int p2_skill2_height,
int p1_button_down,int p2_button_down,//�������Ѽ� 
int *p1_skill1_switch,int *p1_skill2_switch,int *p2_skill1_switch,int *p2_skill2_switch,//�M�w�O�_�~����ܹϤ��A0���_�A1���O
int *p1_manyskill1_switch,int *p1_manyskill2_switch,int *p2_manyskill1_switch,int *p2_manyskill2_switch,
int *p1_down_switch,int *p1_defense_switch,int *p2_down_switch,int *p2_defense_switch, int keep1, int keep2,
int *bar1, int *bar2){
//--------------------------------------------------------------------------------------�Ҽ{p1�O�_�Q���쪺����

	//                 �Qdisk����� 
	if((p2_skill1_position_x-p1_position_x<=p1_width&&p2_skill1_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p1_position_y-p2_skill1_position_y<=p2_skill1_height&&p1_position_y-p2_skill1_position_y>=0)|| 
		(p2_skill1_position_x-p1_position_x<=p1_width&&p2_skill1_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p2_skill1_position_y-p1_position_y<=p1_height&&p2_skill1_position_y-p1_position_y>=0)||
		(p1_position_x-p2_skill1_position_x<=p2_skill1_width&&p1_position_x-p2_skill1_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p1_position_y-p2_skill1_position_y<=p2_skill1_height&&p1_position_y-p2_skill1_position_y>=0)|| 
		(p1_position_x-p2_skill1_position_x<=p2_skill1_width&&p1_position_x-p2_skill1_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p2_skill1_position_y-p1_position_y<=p1_height&&p2_skill1_position_y-p1_position_y>=0)
		){
		(*p1_down_switch)=1;
	}
	//                 �Qmanydisk����� 
	else if((p2_manyskill1_position_x-p1_position_x<=p1_width&&p2_manyskill1_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p1_position_y-p2_manyskill1_position_y<=p2_skill1_height&&p1_position_y-p2_manyskill1_position_y>=0)|| 
		(p2_manyskill1_position_x-p1_position_x<=p1_width&&p2_manyskill1_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p2_manyskill1_position_y-p1_position_y<=p1_height&&p2_manyskill1_position_y-p1_position_y>=0)||
		(p1_position_x-p2_manyskill1_position_x<=p2_skill1_width&&p1_position_x-p2_manyskill1_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p1_position_y-p2_manyskill1_position_y<=p2_skill1_height&&p1_position_y-p2_manyskill1_position_y>=0)|| 
		(p1_position_x-p2_manyskill1_position_x<=p2_skill1_width&&p1_position_x-p2_manyskill1_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p2_manyskill1_position_y-p1_position_y<=p1_height&&p2_manyskill1_position_y-p1_position_y>=0))
		{
		(*p1_down_switch)=1;
	}
//                 �Qball����� 
	else if((p2_skill2_position_x-p1_position_x<=p1_width&&p2_skill2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p1_position_y-p2_skill2_position_y<=p2_skill2_height&&p1_position_y-p2_skill2_position_y>=0)|| 
		(p2_skill2_position_x-p1_position_x<=p1_width&&p2_skill2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p2_skill2_position_y-p1_position_y<=p1_height&&p2_skill2_position_y-p1_position_y>=0)||
		(p1_position_x-p2_skill2_position_x<=p2_skill2_width&&p1_position_x-p2_skill2_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p1_position_y-p2_skill2_position_y<=p2_skill2_height&&p1_position_y-p2_skill2_position_y>=0)|| 
		(p1_position_x-p2_skill2_position_x<=p2_skill2_width&&p1_position_x-p2_skill2_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p2_skill2_position_y-p1_position_y<=p1_height&&p2_skill2_position_y-p1_position_y>=0)
		){
		(*p1_down_switch)=1;
	}
//                 �Qmanyball����� 
	else if((p2_manyskill2_position_x-p1_position_x<=p1_width&&p2_manyskill2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p1_position_y-p2_manyskill2_position_y<=p2_skill2_height&&p1_position_y-p2_manyskill2_position_y>=0)|| 
		(p2_manyskill2_position_x-p1_position_x<=p1_width&&p2_manyskill2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p2_manyskill2_position_y-p1_position_y<=p1_height&&p2_manyskill2_position_y-p1_position_y>=0)||
		(p1_position_x-p2_manyskill2_position_x<=p2_skill2_width&&p1_position_x-p2_manyskill2_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p1_position_y-p2_manyskill2_position_y<=p2_skill2_height&&p1_position_y-p2_manyskill2_position_y>=0)|| 
		(p1_position_x-p2_manyskill2_position_x<=p2_skill2_width&&p1_position_x-p2_manyskill2_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p2_manyskill2_position_y-p1_position_y<=p1_height&&p2_manyskill2_position_y-p1_position_y>=0)){
		(*p1_down_switch)=1;
	}
	else
		(*p1_down_switch)=0;
//                 �Q���𥴨��
	if(p2_button_down==1){
		if((p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)|| 
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)||
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)|| 
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)
			){
			(*p1_defense_switch)=1;
			//printf("*\n");
		}
	}
	else
		(*p1_defense_switch)=0;
		
//--------------------------------------------------------------------------------------�Ҽ{p2�O�_�Q���쪺����
	//                 �Qdisk����� 
	if((p1_skill1_position_x-p2_position_x<=p2_width&&p1_skill1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p2_position_y-p1_skill1_position_y<=p1_skill1_height&&p2_position_y-p1_skill1_position_y>=0)|| 
		(p1_skill1_position_x-p2_position_x<=p2_width&&p1_skill1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p1_skill1_position_y-p2_position_y<=p2_height&&p1_skill1_position_y-p2_position_y>=0)||
		(p2_position_x-p1_skill1_position_x<=p1_skill1_width&&p2_position_x-p1_skill1_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p2_position_y-p1_skill1_position_y<=p1_skill1_height&&p2_position_y-p1_skill1_position_y>=0)|| 
		(p2_position_x-p1_skill1_position_x<=p1_skill1_width&&p2_position_x-p1_skill1_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p1_skill1_position_y-p2_position_y<=p2_height&&p1_skill1_position_y-p2_position_y>=0)
		){
		(*p2_down_switch)=1;
	}
	//                 �Qmanydisk����� 
	else if((p1_manyskill1_position_x-p2_position_x<=p2_width&&p1_manyskill1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p2_position_y-p1_manyskill1_position_y<=p1_skill1_height&&p2_position_y-p1_manyskill1_position_y>=0)|| 
		(p1_manyskill1_position_x-p2_position_x<=p2_width&&p1_manyskill1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p1_manyskill1_position_y-p2_position_y<=p2_height&&p1_manyskill1_position_y-p2_position_y>=0)||
		(p2_position_x-p1_manyskill1_position_x<=p1_skill1_width&&p2_position_x-p1_manyskill1_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p2_position_y-p1_manyskill1_position_y<=p1_skill1_height&&p2_position_y-p1_manyskill1_position_y>=0)|| 
		(p2_position_x-p1_manyskill1_position_x<=p1_skill1_width&&p2_position_x-p1_manyskill1_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p1_manyskill1_position_y-p2_position_y<=p2_height&&p1_manyskill1_position_y-p2_position_y>=0))
		{
		(*p2_down_switch)=1;
	}
//                 �Qball����� 
	else if((p1_skill2_position_x-p2_position_x<=p2_width&&p1_skill2_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p2_position_y-p1_skill2_position_y<=p1_skill2_height&&p2_position_y-p1_skill2_position_y>=0)|| 
		(p1_skill2_position_x-p2_position_x<=p2_width&&p1_skill2_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p1_skill2_position_y-p2_position_y<=p2_height&&p1_skill2_position_y-p2_position_y>=0)||
		(p2_position_x-p1_skill2_position_x<=p1_skill2_width&&p2_position_x-p1_skill2_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p2_position_y-p1_skill2_position_y<=p1_skill2_height&&p2_position_y-p1_skill2_position_y>=0)|| 
		(p2_position_x-p1_skill2_position_x<=p1_skill2_width&&p2_position_x-p1_skill2_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p1_skill2_position_y-p2_position_y<=p2_height&&p1_skill2_position_y-p2_position_y>=0)
		){
		(*p2_down_switch)=1;
	}
//                 �Qmanyball����� 
	else if((p1_manyskill2_position_x-p2_position_x<=p2_width&&p1_manyskill2_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
		p2_position_y-p1_manyskill2_position_y<=p1_skill2_height&&p2_position_y-p1_manyskill2_position_y>=0)|| 
		(p1_manyskill2_position_x-p2_position_x<=p2_width&&p1_manyskill2_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
		p1_manyskill2_position_y-p2_position_y<=p2_height&&p1_manyskill2_position_y-p2_position_y>=0)||
		(p2_position_x-p1_manyskill2_position_x<=p1_skill2_width&&p2_position_x-p1_manyskill2_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
		p2_position_y-p1_manyskill2_position_y<=p1_skill2_height&&p2_position_y-p1_manyskill2_position_y>=0)|| 
		(p2_position_x-p1_manyskill2_position_x<=p1_skill2_width&&p2_position_x-p1_manyskill2_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
		p1_manyskill2_position_y-p2_position_y<=p2_height&&p1_manyskill2_position_y-p2_position_y>=0)){
		(*p2_down_switch)=1;
	}
	else
		(*p2_down_switch)=0;
//                 �Q���𥴨��
	if(p1_button_down==1){
		if((p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�W�� 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)|| 
			(p1_position_x-p2_position_x<=p2_width&&p1_position_x-p2_position_x>=0&&//�ۦ��۹�󨤦�b�k�U�� 
			p1_position_y-p2_position_y<=p2_height&&p1_position_y-p2_position_y>=0)||
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b���W�� 
			p2_position_y-p1_position_y<=p1_height&&p2_position_y-p1_position_y>=0)|| 
			(p2_position_x-p1_position_x<=p1_width&&p2_position_x-p1_position_x>=0&&//�ۦ��۹�󨤦�b���U�� 
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
