#ifndef _JULIAN_H_
#define _JULIAN_H_
class Julian{
//-----------------------------------------------------------------------紀錄當前為哪一張圖片 
	int player;//紀錄當前是哪個玩家操控 
	int picture_right_count;//紀錄當前要秀哪一張移動圖片
	int picture_left_count;//紀錄當前要秀哪一張移動圖片 
	int attack_right_count;//紀錄當前要秀哪一張普通攻擊圖片
	int attack_left_count;//紀錄當前要秀哪一張普通攻擊圖片
	int ball_right_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_left_action_count;//紀錄當前要秀哪一張投擲球技能圖片
	int ball_right_count;//紀錄當前要秀哪一張球技能圖片
	int ball_left_count;//紀錄當前要秀哪一張球技能圖片
	int power_right_action_count;//紀錄當前要秀哪一張做出爆發技能圖片
	int power_left_action_count;//紀錄當前要秀哪一張做出爆發技能圖片
	int power_right_count;//紀錄當前要秀哪一張爆發技能圖片
	int power_left_count;//紀錄當前要秀哪一張爆發技能圖片
	int manyball_right_count;//紀錄當前要秀哪一張額外球技能圖片
	int manyball_left_count;//紀錄當前要秀哪一張額外球技能圖片
	int number_of_ball;//紀錄有幾顆球 
//-----------------------------------------------------------------------紀錄位置、方向、觸發旗標 
	int flag_right,flag_left;//紀錄動作是否有連續被按 
	int flag_ball_action,flag_ball_right,flag_ball_left;//按下投擲球時觸發為1，若投擲動作沒做完則為1，做完則為0
	int flag_power_action,flag_power_right,flag_power_left;//按下爆發技能時觸發為1，若爆發動作沒做完則為1，做完則為0
	int flag_ball_past;//記錄前一顆球的狀態，1為往左射，2為往右射 
	int flag_many_ball_remain;//記錄前一顆球是否依然存在，0為不存在，1為存在
	int direction[2];//紀錄角色當前方向 [0]:紀錄上下 [1]:紀錄左右
	int button_down[6];//紀錄按鍵是否有被按下
	int button_count;//紀錄按鍵被按個數
	int position_x;//角色目前位置 
	int position_y;//角色目前位置	
	int ball_position_x;//球技能目前位置 
	int ball_position_y;//球技能目前位置
	int manyball_position_x;//額外球技能目前位置 
	int manyball_position_y;//額外球技能目前位置
	int last_manyball_position_x;//額外球技能最終位置 
	int power_position_x;//爆發技能目前位置 
	int power_position_y;//爆發技能目前位置
//------------------------------------------------------------------------紀錄圖檔	
	int wa,ha,pn,wn,hn,bkcolor;//往右移動及普攻圖檔切割數據
	int wa_b_a,ha_b_a,pn_b_a,wn_b_a,hn_b_a,bkcolor_b_a;//往右投擲球技能圖檔切割數據
	int wa_b,ha_b,pn_b,wn_b,hn_b,bkcolor_b;//往右球技能圖檔切割數據
	int wa_p_a,ha_p_a,pn_p_a,wn_p_a,hn_p_a,bkcolor_p_a;//往右做出爆發技能圖檔切割數據
	int wa_p,ha_p,pn_p,wn_p,hn_p,bkcolor_p;//往右爆發技能圖檔切割數據
	char filename_right[100];//往右移動及普攻圖檔位置名稱 
	char filename_left[100];//往左移動及普攻圖檔位置名稱
	char filename_ball_right_action[100];//往右投擲球技能圖檔位置名稱
	char filename_ball_left_action[100];//往左投擲球技能圖檔位置名稱
	char filename_ball_right[100];//往右球技能圖檔位置名稱
	char filename_ball_left[100];//往左球技能圖檔位置名稱
	char filename_power_right_action[100];//往右做出爆發技能圖檔位置名稱
	char filename_power_left_action[100];//往左做出爆發技能圖檔位置名稱
	char filename_power_right[100];//往右爆發技能圖檔位置名稱
	char filename_power_left[100];//往左爆發技能圖檔位置名稱
	void **picture_right;//存往右移動及普攻圖檔 
	void **picture_left;//存往左移動及普攻圖檔
	void **ball_right_action_picture;//存往右投擲球技能圖檔
	void **ball_left_action_picture;//存往左投擲球技能圖檔
	void **ball_right_picture;//存往右球圖檔
	void **ball_left_picture;//存往左球圖檔
	void **power_right_action_picture;//存往右做出爆發技能圖檔
	void **power_left_action_picture;//存往左做出爆發技能圖檔
	void **power_right_picture;//存往右爆發技能圖檔
	void **power_left_picture;//存往左爆發技能圖檔
public:
	Julian();//初始時存取各圖檔資料
	void set(int);
	void control();
	void print();
	void print_ball();
	void print_power();
	void skills_record(int);//存取前一次的技能動畫，讓其可以連射
	void print_manyball(); 
	void recordimage();//存取分割圖檔
};
#endif 
