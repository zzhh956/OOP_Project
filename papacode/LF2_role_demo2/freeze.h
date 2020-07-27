#ifndef _FREEZE_H_
#define _FREEZE_H_

class Freeze{
//-----------------------------------------------------------------------紀錄當前為哪一張圖片 
	int picture_right_count;//紀錄當前要秀哪一張移動圖片
	int picture_left_count;//紀錄當前要秀哪一張移動圖片 
	int attack_right_count;//紀錄當前要秀哪一張普通攻擊圖片
	int attack_left_count;//紀錄當前要秀哪一張普通攻擊圖片
	int wind_right_action_count;//紀錄當前要秀哪一張捲風技能圖片
	int wind_left_action_count;//紀錄當前要秀哪一張捲風技能圖片
	int wind_right_count;//紀錄當前要秀哪一張風技能圖片
	int wind_left_count;//紀錄當前要秀哪一張風技能圖片
	int ball_right_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_left_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_right_count;//紀錄當前要秀哪一張球技能圖片
	int ball_left_count;//紀錄當前要秀哪一張球技能圖片
//-----------------------------------------------------------------------紀錄位置、方向、觸發旗標 
	int flag_right,flag_left;//紀錄動作是否有連續被按 
	int flag_wind_action,flag_wind_right,flag_wind_left;//按下捲風時觸發為1，若投擲動作沒做完則為1，做完則為0
	int flag_ball_action,flag_ball_right,flag_ball_left;//按下投擲球時觸發為1，若投擲動作沒做完則為1，做完則為0 
	int direction[2];//紀錄角色當前方向 [0]:紀錄上下 [1]:紀錄左右
	int button_down[6];//紀錄按鍵是否有被按下
	int button_count;//紀錄按鍵被按個數 
	int speed;
	int position_x;//角色目前位置 
	int position_y;//角色目前位置 
	int wind_position_x;//風技能目前位置 
	int wind_position_y;//風技能目前位置 
	int ball_position_x;//球技能目前位置 
	int ball_position_y;//球技能目前位置
//------------------------------------------------------------------------紀錄圖檔 
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//往右移動及普攻圖檔切割數據
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//往左移動及普攻圖檔切割數據 
	int wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a;//往右捲風技能圖檔切割數據
	int wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a;//往左捲風技能圖檔切割數據
	int wa_d_r,ha_d_r,pn_d_r,wn_d_r,hn_d_r,bkcolor_d_r;//往右風技能圖檔切割數據
	int wa_d_l,ha_d_l,pn_d_l,wn_d_l,hn_d_l,bkcolor_d_l;//往左風技能圖檔切割數據
	int wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a;//往右投擲球技能圖檔切割數據
	int wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a;//往左投擲球技能圖檔切割數據
	int wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r;//往右球技能圖檔切割數據
	int wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l;//往左球技能圖檔切割數據
	char filename_right[100];//往右移動及普攻圖檔位置名稱 
	char filename_left[100];//往左移動及普攻圖檔位置名稱
	char filename_wind_right_action[100];//往右捲風技能圖檔位置名稱
	char filename_wind_left_action[100];//往左捲風技能圖檔位置名稱
	char filename_wind_right[100];//往右風技能圖檔位置名稱
	char filename_wind_left[100];//往左風技能圖檔位置名稱
	char filename_ball_right_action[100];//往右投擲球技能圖檔位置名稱
	char filename_ball_left_action[100];//往左投擲球技能圖檔位置名稱
	char filename_ball_right[100];//往右球技能圖檔位置名稱
	char filename_ball_left[100];//往左球技能圖檔位置名稱
	void **picture_right;//存往右移動及普攻圖檔 
	void **picture_left;//存往左移動及普攻圖檔
	void **wind_right_action_picture;//存往右捲風技能圖檔
	void **wind_left_action_picture;//存往左捲風技能圖檔
	void **wind_right_picture;//存往右風圖檔
	void **wind_left_picture;//存往左風圖檔
	void **ball_right_action_picture;//存往右投擲球技能圖檔
	void **ball_left_action_picture;//存往左投擲球技能圖檔
	void **ball_right_picture;//存往右球圖檔
	void **ball_left_picture;//存往左球圖檔
public:
	Freeze(char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//移動及普攻圖檔資料
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//捲風技能圖檔資料
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//風技能圖檔資料
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//投擲球技能圖檔資料
		,char*,char*,int,int,int,int,int,int,int,int,int,int,int,int//球技能圖檔資料
		,int/*確認玩家*/
	);//初始時存取各圖檔資料 
	void Freeze_set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_wind();
	void print_ball();
	friend void** getimage2(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//分割圖檔 
	void recordimage();//存取分割圖檔 
};
#endif 
