#ifndef _JOHN_H_
#define _JOHN_H_

class John{
//-----------------------------------------------------------------------紀錄當前為哪一張圖片 
	int picture_right_count;//紀錄當前要秀哪一張移動圖片
	int picture_left_count;//紀錄當前要秀哪一張移動圖片 
	int attack_right_count;//紀錄當前要秀哪一張普通攻擊圖片
	int attack_left_count;//紀錄當前要秀哪一張普通攻擊圖片
	int disk_right_action_count;//紀錄當前要秀哪一張投擲飛碟技能圖片
	int disk_left_action_count;//紀錄當前要秀哪一張投擲飛碟技能圖片
	int disk_right_count;//紀錄當前要秀哪一張飛碟技能圖片
	int disk_left_count;//紀錄當前要秀哪一張飛碟技能圖片
	int ball_right_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_left_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_right_count;//紀錄當前要秀哪一張球技能圖片
	int ball_left_count;//紀錄當前要秀哪一張球技能圖片
//-----------------------------------------------------------------------紀錄位置、方向、觸發旗標 
	int flag_right,flag_left;//紀錄動作是否有連續被按 
	int flag_disk_action,flag_disk_right,flag_disk_left;//按下投擲飛碟時觸發為1，若投擲動作沒做完則為1，做完則為0
	int flag_ball_action,flag_ball_right,flag_ball_left;//按下投擲球時觸發為1，若投擲動作沒做完則為1，做完則為0 
	int direction[2];//紀錄角色當前方向 [0]:紀錄上下 [1]:紀錄左右
	int button_down[6];//紀錄按鍵是否有被按下
	int button_count;//紀錄按鍵被按個數 
	int speed;
	int position_x;//角色目前位置 
	int position_y;//角色目前位置 
	int disk_position_x;//飛碟技能目前位置 
	int disk_position_y;//飛碟技能目前位置 
	int ball_position_x;//球技能目前位置 
	int ball_position_y;//球技能目前位置
//------------------------------------------------------------------------紀錄圖檔 
	int wa,ha,pn,wn,hn,bkcolor;//往右移動及普攻圖檔切割數據
	int wa_d_a,ha_d_a,pn_d_a,wn_d_a,hn_d_a,bkcolor_d_a;//往右投擲飛碟技能圖檔切割數據
	int wa_d,ha_d,pn_d,wn_d,hn_d,bkcolor_d;//往右飛碟技能圖檔切割數據
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//往右投擲球技能圖檔切割數據
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//往右球技能圖檔切割數據
	char filename_right[100];//往右移動及普攻圖檔位置名稱 
	char filename_left[100];//往左移動及普攻圖檔位置名稱
	char filename_disk_right_action[100];//往右投擲飛碟技能圖檔位置名稱
	char filename_disk_left_action[100];//往左投擲飛碟技能圖檔位置名稱
	char filename_disk_right[100];//往右飛碟技能圖檔位置名稱
	char filename_disk_left[100];//往左飛碟技能圖檔位置名稱
	char filename_ball_right_action[100];//往右投擲球技能圖檔位置名稱
	char filename_ball_left_action[100];//往左投擲球技能圖檔位置名稱
	char filename_ball_right[100];//往右球技能圖檔位置名稱
	char filename_ball_left[100];//往左球技能圖檔位置名稱
	void **picture_right;//存往右移動及普攻圖檔 
	void **picture_left;//存往左移動及普攻圖檔
	void **disk_right_action_picture;//存往右投擲飛碟技能圖檔
	void **disk_left_action_picture;//存往左投擲飛碟技能圖檔
	void **disk_right_picture;//存往右飛碟圖檔
	void **disk_left_picture;//存往左飛碟圖檔
	void **ball_right_action_picture;//存往右投擲球技能圖檔
	void **ball_left_action_picture;//存往左投擲球技能圖檔
	void **ball_right_picture;//存往右球圖檔
	void **ball_left_picture;//存往左球圖檔
public:
	John();//初始時存取各圖檔資料 
	void set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_disk();
	void print_ball();
	friend void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//分割圖檔 
	void recordimage();//存取分割圖檔 
};
void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);
#endif 
