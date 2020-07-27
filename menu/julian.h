#ifndef _JULIAN_H_
#define _JULIAN_H_
class Julian{
//-----------------------------------------------------------------------������e�����@�i�Ϥ� 
	int player;//������e�O���Ӫ��a�ޱ� 
	int picture_right_count;//������e�n�q���@�i���ʹϤ�
	int picture_left_count;//������e�n�q���@�i���ʹϤ� 
	int attack_right_count;//������e�n�q���@�i���q�����Ϥ�
	int attack_left_count;//������e�n�q���@�i���q�����Ϥ�
	int ball_right_action_count;//������e�n�q���@�i���Y�y�ޯ�Ϥ�
	int ball_left_action_count;//������e�n�q���@�i���Y�y�ޯ�Ϥ�
	int ball_right_count;//������e�n�q���@�i�y�ޯ�Ϥ�
	int ball_left_count;//������e�n�q���@�i�y�ޯ�Ϥ�
	int power_right_action_count;//������e�n�q���@�i���X�z�o�ޯ�Ϥ�
	int power_left_action_count;//������e�n�q���@�i���X�z�o�ޯ�Ϥ�
	int power_right_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int power_left_count;//������e�n�q���@�i�z�o�ޯ�Ϥ�
	int manyball_right_count;//������e�n�q���@�i�B�~�y�ޯ�Ϥ�
	int manyball_left_count;//������e�n�q���@�i�B�~�y�ޯ�Ϥ�
	int number_of_ball;//�������X���y 
//-----------------------------------------------------------------------������m�B��V�BĲ�o�X�� 
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int flag_ball_action,flag_ball_right,flag_ball_left;//���U���Y�y��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0
	int flag_power_action,flag_power_right,flag_power_left;//���U�z�o�ޯ��Ĳ�o��1�A�Y�z�o�ʧ@�S�����h��1�A�����h��0
	int flag_ball_past;//�O���e�@���y�����A�A1�������g�A2�����k�g 
	int flag_many_ball_remain;//�O���e�@���y�O�_�̵M�s�b�A0�����s�b�A1���s�b
	int direction[2];//���������e��V [0]:�����W�U [1]:�������k
	int button_down[6];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ�
	int position_x;//����ثe��m 
	int position_y;//����ثe��m	
	int ball_position_x;//�y�ޯ�ثe��m 
	int ball_position_y;//�y�ޯ�ثe��m
	int manyball_position_x;//�B�~�y�ޯ�ثe��m 
	int manyball_position_y;//�B�~�y�ޯ�ثe��m
	int last_manyball_position_x;//�B�~�y�ޯ�̲צ�m 
	int power_position_x;//�z�o�ޯ�ثe��m 
	int power_position_y;//�z�o�ޯ�ثe��m
//------------------------------------------------------------------------��������	
	int wa,ha,pn,wn,hn,bkcolor;//���k���ʤδ�����ɤ��μƾ�
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//���k���Y�y�ޯ���ɤ��μƾ�
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//���k�y�ޯ���ɤ��μƾ�
	int wa_p_a,ha_p_a,pn_p_a,wn_p_a,hn_p_a,bkcolor_p_a;//���k���X�z�o�ޯ���ɤ��μƾ�
	int wa_p,ha_p,pn_p,wn_p,hn_p,bkcolor_p;//���k�z�o�ޯ���ɤ��μƾ�
	char filename_right[100];//���k���ʤδ�����ɦ�m�W�� 
	char filename_left[100];//�������ʤδ�����ɦ�m�W��
	char filename_ball_right_action[100];//���k���Y�y�ޯ���ɦ�m�W��
	char filename_ball_left_action[100];//�������Y�y�ޯ���ɦ�m�W��
	char filename_ball_right[100];//���k�y�ޯ���ɦ�m�W��
	char filename_ball_left[100];//�����y�ޯ���ɦ�m�W��
	char filename_power_right_action[100];//���k���X�z�o�ޯ���ɦ�m�W��
	char filename_power_left_action[100];//�������X�z�o�ޯ���ɦ�m�W��
	char filename_power_right[100];//���k�z�o�ޯ���ɦ�m�W��
	char filename_power_left[100];//�����z�o�ޯ���ɦ�m�W��
	void **picture_right;//�s���k���ʤδ������ 
	void **picture_left;//�s�������ʤδ������
	void **ball_right_action_picture;//�s���k���Y�y�ޯ����
	void **ball_left_action_picture;//�s�������Y�y�ޯ����
	void **ball_right_picture;//�s���k�y����
	void **ball_left_picture;//�s�����y����
	void **power_right_action_picture;//�s���k���X�z�o�ޯ����
	void **power_left_action_picture;//�s�������X�z�o�ޯ����
	void **power_right_picture;//�s���k�z�o�ޯ����
	void **power_left_picture;//�s�����z�o�ޯ����
public:
	Julian();//��l�ɦs���U���ɸ��
	void set(int);
	void control();
	void print();
	void print_ball();
	void print_power();
	void skills_record(int);//�s���e�@�����ޯ�ʵe�A����i�H�s�g
	void print_manyball(); 
	void recordimage();//�s�����ι���
};
#endif 
