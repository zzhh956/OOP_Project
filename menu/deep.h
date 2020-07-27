#ifndef _DEEP_H_
#define _DEEP_H_

class Deep{
//-----------------------------------------------------------------------������e�����@�i�Ϥ� 
	int picture_right_count;//������e�n�q���@�i���ʹϤ�
	int picture_left_count;//������e�n�q���@�i���ʹϤ� 
	int attack_right_count;//������e�n�q���@�i���q�����Ϥ�
	int attack_left_count;//������e�n�q���@�i���q�����Ϥ�
	int slash_right_action_count;//������e�n�q���@�i�����ޯ�Ϥ�
	int slash_left_action_count;//������e�n�q���@�i�����ޯ�Ϥ�
	int wave_right_action_count;//������e�n�q���@�i�C��ޯ�Ϥ�
	int wave_left_action_count;//������e�n�q���@�i�C��ޯ�Ϥ�
	int wave_right_count;//������e�n�q���@�i�C��ޯ�Ϥ�
	int wave_left_count;//������e�n�q���@�i�C��ޯ�Ϥ�
//-----------------------------------------------------------------------������m�B��V�BĲ�o�X�� 
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int flag_slash_action_right,flag_slash_action_left;//���U�����ޯ��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0
	int flag_wave_action,flag_wave_right,flag_wave_left;//���U�C��ޯ��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0 
	int direction[2];//���������e��V [0]:�����W�U [1]:�������k
	int button_down[6];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ� 
	int speed;
	int position_x;//����ثe��m 
	int position_y;//����ثe��m 
	int wave_position_x;//�C��ޯ�ثe��m 
	int wave_position_y;//�C��ޯ�ثe��m
//------------------------------------------------------------------------�������� 
	int wa,ha,pn,wn,hn,bkcolor;//���ʤδ�����ɤ��μƾ�
	int wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a;//�����ޯ���ɤ��μƾ�
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//�C��ޯ���ɤ��μƾ�
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//�C��ޯ���ɤ��μƾ�
	char filename_right[100];//���k���ʤδ�����ɦ�m�W�� 
	char filename_left[100];//�������ʤδ�����ɦ�m�W��
	char filename_slash_right_action[100];//���k�����ޯ���ɦ�m�W��
	char filename_slash_left_action[100];//���������ޯ���ɦ�m�W��
	char filename_wave_right_action[100];//���k�C��ޯ���ɦ�m�W��
	char filename_wave_left_action[100];//�����C��ޯ���ɦ�m�W��
	char filename_wave_right[100];//���k�C��ޯ���ɦ�m�W��
	char filename_wave_left[100];//�����C��ޯ���ɦ�m�W��
	void **picture_right;//�s���k���ʤδ������ 
	void **picture_left;//�s�������ʤδ������
	void **slash_right_action_picture;//�s���k�����ޯ����
	void **slash_left_action_picture;//�s���������ޯ����
	void **wave_right_action_picture;//�s���k�C��ޯ����
	void **wave_left_action_picture;//�s�����C��ޯ����
	void **wave_right_picture;//�s���k�C�����
	void **wave_left_picture;//�s�����C�����
public:
	Deep();//��l�ɦs���U���ɸ�� 
	void set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_slash();
	void print_wave();
	void recordimage();//�s�����ι��� 
};
#endif 
