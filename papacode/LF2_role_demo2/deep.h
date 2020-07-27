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
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//���k���ʤδ�����ɤ��μƾ�
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//�������ʤδ�����ɤ��μƾ� 
	int wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a;//���k�����ޯ���ɤ��μƾ�
	int wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a;//���������ޯ���ɤ��μƾ�
	int wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a;//���k�C��ޯ���ɤ��μƾ�
	int wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a;//�����C��ޯ���ɤ��μƾ�
	int wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r;//���k�C��ޯ���ɤ��μƾ�
	int wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l;//�����C��ޯ���ɤ��μƾ�
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
	Deep(char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//���ʤδ�����ɸ��
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//�����ޯ���ɸ��
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//�C��ʧ@�ޯ���ɸ��
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//�C��ޯ���ɸ��
		,int/*�T�{���a*/
	);//��l�ɦs���U���ɸ�� 
	void Deep_set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_slash();
	void print_wave();
	void recordimage();//�s�����ι��� 
};
#endif 
