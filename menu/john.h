#ifndef _JOHN_H_
#define _JOHN_H_

class John{
//-----------------------------------------------------------------------�������e�����@�i�Ϥ� 
	int picture_right_count;//�������e�n�q���@�i���ʹϤ�
	int picture_left_count;//�������e�n�q���@�i���ʹϤ� 
	int attack_right_count;//�������e�n�q���@�i���q�����Ϥ�
	int attack_left_count;//�������e�n�q���@�i���q�����Ϥ�
	int disk_right_action_count;//�������e�n�q���@�i���Y���Чޯ�Ϥ�
	int disk_left_action_count;//�������e�n�q���@�i���Y���Чޯ�Ϥ�
	int disk_right_count;//�������e�n�q���@�i���Чޯ�Ϥ�
	int disk_left_count;//�������e�n�q���@�i���Чޯ�Ϥ�
	int ball_right_action_count;//�������e�n�q���@�i���Y�y�ޯ�Ϥ�
	int ball_left_action_count;//�������e�n�q���@�i���Y�y�ޯ�Ϥ�
	int ball_right_count;//�������e�n�q���@�i�y�ޯ�Ϥ�
	int ball_left_count;//�������e�n�q���@�i�y�ޯ�Ϥ�
//-----------------------------------------------------------------------������m�B��V�BĲ�o�X�� 
	int flag_right,flag_left;//�����ʧ@�O�_���s��Q�� 
	int flag_disk_action,flag_disk_right,flag_disk_left;//���U���Y���Ю�Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0
	int flag_ball_action,flag_ball_right,flag_ball_left;//���U���Y�y��Ĳ�o��1�A�Y���Y�ʧ@�S�����h��1�A�����h��0 
	int direction[2];//����������e��V [0]:�����W�U [1]:�������k
	int button_down[6];//��������O�_���Q���U
	int button_count;//��������Q���Ӽ� 
	int speed;
	int position_x;//����ثe��m 
	int position_y;//����ثe��m 
	int disk_position_x;//���Чޯ�ثe��m 
	int disk_position_y;//���Чޯ�ثe��m 
	int ball_position_x;//�y�ޯ�ثe��m 
	int ball_position_y;//�y�ޯ�ثe��m
//------------------------------------------------------------------------�������� 
	int wa,ha,pn,wn,hn,bkcolor;//���k���ʤδ�����ɤ��μƾ�
	int wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a;//���k���Y���Чޯ���ɤ��μƾ�
	int wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d;//���k���Чޯ���ɤ��μƾ�
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//���k���Y�y�ޯ���ɤ��μƾ�
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//���k�y�ޯ���ɤ��μƾ�
	char filename_right[100];//���k���ʤδ�����ɦ�m�W�� 
	char filename_left[100];//�������ʤδ�����ɦ�m�W��
	char filename_disk_right_action[100];//���k���Y���Чޯ���ɦ�m�W��
	char filename_disk_left_action[100];//�������Y���Чޯ���ɦ�m�W��
	char filename_disk_right[100];//���k���Чޯ���ɦ�m�W��
	char filename_disk_left[100];//�������Чޯ���ɦ�m�W��
	char filename_ball_right_action[100];//���k���Y�y�ޯ���ɦ�m�W��
	char filename_ball_left_action[100];//�������Y�y�ޯ���ɦ�m�W��
	char filename_ball_right[100];//���k�y�ޯ���ɦ�m�W��
	char filename_ball_left[100];//�����y�ޯ���ɦ�m�W��
	void **picture_right;//�s���k���ʤδ������ 
	void **picture_left;//�s�������ʤδ������
	void **disk_right_action_picture;//�s���k���Y���Чޯ����
	void **disk_left_action_picture;//�s�������Y���Чޯ����
	void **disk_right_picture;//�s���k���й���
	void **disk_left_picture;//�s�������й���
	void **ball_right_action_picture;//�s���k���Y�y�ޯ����
	void **ball_left_action_picture;//�s�������Y�y�ޯ����
	void **ball_right_picture;//�s���k�y����
	void **ball_left_picture;//�s�����y����
public:
	John();//��l�ɦs���U���ɸ�� 
	void set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_disk();
	void print_ball();
	friend void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//���ι��� 
	void recordimage();//�s�����ι��� 
};
void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);
#endif 