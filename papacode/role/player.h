#ifndef _PLAYER_H_
#define _PLATER_H_

class Player{
	int picture_right_count;//紀錄當前要秀哪一張圖片
	int picture_left_count;//紀錄當前要秀哪一張圖片 
	int attack_right_count;//紀錄當前要秀哪一張攻擊圖片
	int attack_left_count;//紀錄當前要秀哪一張攻擊圖片
	int flag_right,flag_left;//紀錄動作是否有連續被按 
	int direction[2];//紀錄角色當前方向 [0]:紀錄上下 [1]:紀錄左右
	int cur_page=0;
	int button_down[5];//紀錄按鍵是否有被按下
	int button_count;//紀錄按鍵被按個數 
	int speed;
	int position_x;
	int position_y;
	int wa_r,ha_r,pn_r,wn_r,hn_r,bkcolor_r;//往右移動圖檔切割數據
	int wa_l,ha_l,pn_l,wn_l,hn_l,bkcolor_l;//往左移動圖檔切割數據 
	char filename_right[100];//往右移動圖檔位置名稱 
	char filename_left[100];//往左移動圖檔位置名稱
	void **picture_right;//存往右圖檔 
	void **picture_left;//存往左圖檔
public:
	Player(char*,char*,int,int,int,int,int,int,int,int,int,int,int,int);//初始時存取各圖檔資料 
	void setposition(int,int);
	void control();
	void print();
	friend void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor);//分割圖檔 
	void recordimage();//存取分割圖檔 
};
void playerset();
#endif 
