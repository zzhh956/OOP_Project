#ifndef _DENNIS_H_
#define _DENNIS_H_

class Dennis{
//-----------------------------------------------------------------------紀錄當前為哪一張圖片 
	int picture_right_count;//紀錄當前要秀哪一張移動圖片
	int picture_left_count;//紀錄當前要秀哪一張移動圖片 
	int attack_right_count;//紀錄當前要秀哪一張普通攻擊圖片
	int attack_left_count;//紀錄當前要秀哪一張普通攻擊圖片
	int down_right_count;//紀錄當前要秀哪一張被擊倒圖片
	int down_left_count;//紀錄當前要秀哪一張被擊倒圖片 
	int defense_right_count;//紀錄當前要秀哪一張被揍圖片
	int defense_left_count;//紀錄當前要秀哪一張被揍圖片
	int kick_right_action_count;//紀錄當前要秀哪一張踢擊技能圖片
	int kick_left_action_count;//紀錄當前要秀哪一張踢擊技能圖片
	int ball_right_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_left_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_right_count;//紀錄當前要秀哪一張球技能圖片
	int ball_left_count;//紀錄當前要秀哪一張球技能圖片
	int manyball_right_count;//紀錄當前要秀哪一張額外球技能圖片
	int manyball_left_count;//紀錄當前要秀哪一張額外球技能圖片
	int number_of_ball;//紀錄有幾顆球 
//-----------------------------------------------------------------------紀錄位置、方向、觸發旗標 
	int flag_right,flag_left;//紀錄動作是否有連續被按 
	int flag_kick_action_right,flag_kick_action_left;//按下踢擊技能時觸發為1，若投擲動作沒做完則為1，做完則為0
	int flag_ball_action,flag_ball_right,flag_ball_left;//按下投擲球技能時觸發為1，若投擲動作沒做完則為1，做完則為0 
	int flag_ball_past;//記錄前一顆球的狀態，1為往左射，2為往右射 
	int flag_manyball_remain;//記錄前一顆球是否依然存在，0為不存在，1為存在
	int flag_ball_record_receive;//記錄球是否被接收，0為尚未，1為接收了
	int flag_down;//紀錄角色是否要被撞飛，0為不用，1為撞飛 
	int flag_defense;//紀錄角色是否要被揍，0為不用，1為被揍 
	int direction[2];//紀錄角色當前方向 [0]:紀錄上下 [1]:紀錄左右
	int button_down[6];//紀錄按鍵是否有被按下
	int button_count;//紀錄按鍵被按個數 
	int speed;
	int position_x;//角色目前位置 
	int position_y;//角色目前位置 
	int ball_ori_position_x;//球技能一開始位置 
	int ball_ori_position_y;//球技能一開始位置
	int manyball_position_x;//額外球技能目前位置 
	int manyball_position_y;//額外球技能目前位置
	int last_manyball_position_x;//額外球技能最終位置 
	int ball_position_x;//投擲球技能目前位置 
	int ball_position_y;//投擲球技能目前位置
//------------------------------------------------------------------------紀錄圖檔 
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//往右移動及普攻圖檔切割數據
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//往左移動及普攻圖檔切割數據 
	int wa_d_r_a,ha_d_r_a,pn_d_r_a,wn_d_r_a,hn_d_r_a,bkcolor_d_r_a;//往右踢擊技能圖檔切割數據
	int wa_d_l_a,ha_d_l_a,pn_d_l_a,wn_d_l_a,hn_d_l_a,bkcolor_d_l_a;//往左踢擊技能圖檔切割數據
	int wa_b_r_a,ha_b_r_a,pn_b_r_a,wn_b_r_a,hn_b_r_a,bkcolor_b_r_a;//往右投擲球技能圖檔切割數據
	int wa_b_l_a,ha_b_l_a,pn_b_l_a,wn_b_l_a,hn_b_l_a,bkcolor_b_l_a;//往左投擲球技能圖檔切割數據
	int wa_b_r,ha_b_r,pn_b_r,wn_b_r,hn_b_r,bkcolor_b_r;//往右球技能圖檔切割數據
	int wa_b_l,ha_b_l,pn_b_l,wn_b_l,hn_b_l,bkcolor_b_l;//往左球技能圖檔切割數據
	char filename_right[100];//往右移動及普攻圖檔位置名稱 
	char filename_left[100];//往左移動及普攻圖檔位置名稱
	char filename_kick_right_action[100];//往右踢擊技能圖檔位置名稱
	char filename_kick_left_action[100];//往左踢擊技能圖檔位置名稱
	char filename_ball_right_action[100];//往右投擲球技能圖檔位置名稱
	char filename_ball_left_action[100];//往左投擲球技能圖檔位置名稱
	char filename_ball_right[100];//往右球技能圖檔位置名稱
	char filename_ball_left[100];//往左球技能圖檔位置名稱
	void **picture_right;//存往右移動及普攻圖檔 
	void **picture_left;//存往左移動及普攻圖檔
	void **kick_right_action_picture;//存往右踢擊技能圖檔
	void **kick_left_action_picture;//存往左踢擊技能圖檔
	void **ball_right_action_picture;//存往右投擲球技能圖檔
	void **ball_left_action_picture;//存往左投擲球技能圖檔
	void **ball_right_picture;//存往右球圖檔
	void **ball_left_picture;//存往左球圖檔
public:
	Dennis();//初始時存取各圖檔資料 
	void set(int);
	void setposition(int,int);
	void control();
	void print();
	void print_kick();
	void print_ball();
	void skills_record();//存取前一次的技能動畫，讓其可以連射
	void print_manyball(); 
	void print_down();//角色被擊倒畫面 
	void print_defense();//角色被揍畫面 
	void recordimage();//存取分割圖檔 
	void getdata(int &,int &,int &,int &,int &,int &,int &,int &,int &,
				int &,int &,int &,int &,int &,int &,int &,int &);//讀取角色當前資料 */ 
	void setdata(int,int);//改變角色當前資料 
};

#endif
