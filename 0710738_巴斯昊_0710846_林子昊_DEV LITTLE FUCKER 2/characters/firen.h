#ifndef _balln_H_
#define _balln_H_

class Firen{
//-----------------------------------------------------------------------������e�����@�i�Ϥ� 
	int picture_right_count;//������e�n�q���@�i���ʹϤ�
	int picture_left_count;//������e�n�q���@�i���ʹϤ� 
	int attack_right_count;//������e�n�q���@�i���q�����Ϥ�
	int attack_left_count;//������e�n�q���@�i���q�����Ϥ�
	int down_right_count;//������e�n�q���@�i�Q���˹Ϥ�
	int down_left_count;//������e�n�q���@�i�Q���˹Ϥ� 
	int defense_right_count;//������e�n�q���@�i�Q�~�Ϥ�
	int defense_left_count;//������e�n�q���@�i�Q�~�Ϥ�
	int power_right_action_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int power_left_action_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int power_right_count;//������e�n�q���@�i�z���ޯ�Ϥ�
	int power_left_count;//������e�n�q���@�i�z���ޯ�Ϥ�
	int ball_right_action_count;//������e�n�q���@�i�R���K�ޯ�Ϥ�
	int ball_left_action_count;//������e�n�q���@�i�R���K�ޯ�Ϥ�
	int ball_right_count;//������e�n�q���@�i���K�ޯ�Ϥ�
	int ball_left_count;//������e�n�q���@�i���K�ޯ�Ϥ�
	int manyball_right_count;//������e�n�q���@�i�B�~�R���K�ޯ�Ϥ�
	int manyball_left_count;//������e�n�q���@�i�B�~�R���K�ޯ�Ϥ�
	int number_of_ball;//�������X�����K
//-----------------------------------------------------------------------������m�B��V�BĲ�o�X�� 
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int flag_power_action,flag_power_right,flag_power_left;//���U�z�o��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0
	int flag_ball_action,flag_ball_right,flag_ball_left;//���U�R���K��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0 
	int flag_ball_past;//�O���e�@���R���K�����A�A1�������g�A2�����k�g 
	int flag_manyball_remain;//�O���e�@�����K�O�_�̵M�s�b�A0�����s�b�A1���s�b
	int flag_ball_record_receive;//�O�����K�O�_�Q�����A0���|���A1�������F
	int flag_down;//��������O�_�n�Q�����A0�����ΡA1������ 
	int flag_defense;//��������O�_�n�Q�~�A0�����ΡA1���Q�~ 
	int direction[2];//���������e��V [0]:�����W�U [1]:�������k
	int button_down[6];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ� 
	int speed;
	int position_x;//����ثe��m 
	int position_y;//����ثe��m 
	int power_position_x;//�z���ޯ�ثe��m 
	int power_position_y;//�z���ޯ�ثe��m 
	int ball_ori_position_x;//�y�ޯ�@�}�l�ثe��m 
	int ball_ori_position_y;//�y�ޯ�@�}�l�ثe��m	
	int ball_position_x;//�y�ޯ�ثe��m 
	int ball_position_y;//�y�ޯ�ثe��m
	int manyball_position_x;//�B�~�y�ޯ�ثe��m 
	int manyball_position_y;//�B�~�y�ޯ�ثe��m
	int last_manyball_position_x;//�B�~�y�ޯ�̲צ�m 
//------------------------------------------------------------------------�������� 
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//���k���ʤδ�����ɤ��μƾ�
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//�������ʤδ�����ɤ��μƾ� 
	int wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a;//���k�z�o�ޯ���ɤ��μƾ�
	int wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a;//�����z�o�ޯ���ɤ��μƾ�
	int wa_d_r,ha_d_r,pn_d_r,wn_d_r,hn_d_r,bkcolor_d_r;//���k�z���ޯ���ɤ��μƾ�
	int wa_d_l,ha_d_l,pn_d_l,wn_d_l,hn_d_l,bkcolor_d_l;//�����z���ޯ���ɤ��μƾ�
	int wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a;//���k�R���K�ޯ���ɤ��μƾ�
	int wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a;//�����R���K�ޯ���ɤ��μƾ�
	int wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r;//���k���K�ޯ���ɤ��μƾ�
	int wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l;//�������K�ޯ���ɤ��μƾ�
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
	void print_down();//����Q���˵e�� 
	void print_defense();//����Q�~�e��
	void skills_record();//�s���e�@�����ޯ�ʵe�A����i�H�s�g
	void print_manyball();
	void getdata(int &,int &,int &,int &,int &,int &,int &,int &,int &,
				int &,int &,int &,int &,int &,int &,int &,int &);//Ū�������e��� */ 
	void setdata(int,int);//���ܨ����e��� 
	friend void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//���ι��� 
	void recordimage();//�s�����ι��� 
};
#endif 
