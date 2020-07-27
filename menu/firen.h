#ifndef _balln_H_
#define _balln_H_

class Firen{
//-----------------------------------------------------------------------������e�����@�i�Ϥ� 
	int picture_right_count;//������e�n�q���@�i���ʹϤ�
	int picture_left_count;//������e�n�q���@�i���ʹϤ� 
	int attack_right_count;//������e�n�q���@�i���q�����Ϥ�
	int attack_left_count;//������e�n�q���@�i���q�����Ϥ�
	int power_right_action_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int power_left_action_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int power_right_count;//������e�n�q���@�i�z���ޯ�Ϥ�
	int power_left_count;//������e�n�q���@�i�z���ޯ�Ϥ�
	int ball_right_action_count;//������e�n�q���@�i�R���K�ޯ�Ϥ�
	int ball_left_action_count;//������e�n�q���@�i�R���K�ޯ�Ϥ�
	int ball_right_count;//������e�n�q���@�i���K�ޯ�Ϥ�
	int ball_left_count;//������e�n�q���@�i���K�ޯ�Ϥ�
//-----------------------------------------------------------------------������m�B��V�BĲ�o�X�� 
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int flag_power_action,flag_power_right,flag_power_left;//���U�z�o��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0
	int flag_ball_action,flag_ball_right,flag_ball_left;//���U�R���K��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0 
	int direction[2];//���������e��V [0]:�����W�U [1]:�������k
	int button_down[6];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ� 
	int speed;
	int position_x;//����ثe��m 
	int position_y;//����ثe��m 
	int power_position_x;//�z���ޯ�ثe��m 
	int power_position_y;//�z���ޯ�ثe��m 
	int ball_position_x;//�y�ޯ�ثe��m 
	int ball_position_y;//�y�ޯ�ثe��m
//------------------------------------------------------------------------�������� 
	int wa,ha,pn,wn,hn,bkcolor;//���k���ʤδ�����ɤ��μƾ�
	int wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a;//���k�z�o�ޯ���ɤ��μƾ�
	int wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d;//���k�z���ޯ���ɤ��μƾ�
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//���k�R���K�ޯ���ɤ��μƾ�
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//���k���K�ޯ���ɤ��μƾ�
	char filename_right[100];//���k���ʤδ�����ɦ�m�W�� 
	char filename_left[100];//�������ʤδ�����ɦ�m�W��
	char filename_power_right_action[100];//���k�z�o�ޯ���ɦ�m�W��
	char filename_power_left_action[100];//�����z�o�ޯ���ɦ�m�W��
	char filename_power_right[100];//���k�z���ޯ���ɦ�m�W��
	char filename_power_left[100];//�����z���ޯ���ɦ�m�W��
	char filename_ball_right_action[100];//���k�R���K�ޯ���ɦ�m�W��
	char filename_ball_left_action[100];//�����R���K�ޯ���ɦ�m�W��
	char filename_ball_right[100];//���k���K�ޯ���ɦ�m�W��
	char filename_ball_left[100];//�������K�ޯ���ɦ�m�W��
	void **picture_right;//�s���k���ʤδ������ 
	void **picture_left;//�s�������ʤδ������
	void **power_right_action_picture;//�s���k�z�o�ޯ����
	void **power_left_action_picture;//�s�����z�o�ޯ����
	void **power_right_picture;//�s���k�z������
	void **power_left_picture;//�s�����z������
	void **ball_right_action_picture;//�s���k�R���K�ޯ����
	void **ball_left_action_picture;//�s�����R���K�ޯ����
	void **ball_right_picture;//�s���k���K����
	void **ball_left_picture;//�s�������K����
public:
	Firen();//��l�ɦs���U���ɸ�� 
	void set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_power();
	void print_ball();
	friend void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//���ι��� 
	void recordimage();//�s�����ι��� 
};
#endif 
