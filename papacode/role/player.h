#ifndef _PLAYER_H_
#define _PLATER_H_

class Player{
	int picture_right_count;//������e�n�q���@�i�Ϥ�
	int picture_left_count;//������e�n�q���@�i�Ϥ� 
	int attack_right_count;//������e�n�q���@�i�����Ϥ�
	int attack_left_count;//������e�n�q���@�i�����Ϥ�
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int direction[2];//���������e��V [0]:�����W�U [1]:�������k
	int cur_page=0;
	int button_down[5];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ� 
	int speed;
	int position_x;
	int position_y;
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//���k���ʹ��ɤ��μƾ�
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//�������ʹ��ɤ��μƾ� 
	char filename_right[100];//���k���ʹ��ɦ�m�W�� 
	char filename_left[100];//�������ʹ��ɦ�m�W��
	void **picture_right;//�s���k���� 
	void **picture_left;//�s��������
public:
	Player(char*,char*,int,int,int,int,int,int,int,int,int,int,int,int);//��l�ɦs���U���ɸ�� 
	void setposition(int,int);
	void control();
	void print();
	friend void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//���ι��� 
	void recordimage();//�s�����ι��� 
};
void playerset();
#endif 
