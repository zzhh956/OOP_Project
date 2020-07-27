#include<windows.h>
#include<iostream>
#include<conio.h>
#include"menucontroll.h"
#define W_KEY 0x57
#define S_KEY 0x53
#define A_KEY 0x41
#define D_KEY 0x44
#define C_KEY 0x43
#define F_KEY 0x46 
#define UP_KEY 0x26
#define DOWN_KEY 0x28
#define LEFT_KEY 0x25
#define RIGHT_KEY 0x27
#define a_KEY 0xBF
#define s_KEY 0xBA
 
using namespace std;

int Presskey_1()
{
    if(GetAsyncKeyState(W_KEY)!=0) return 0;
    else if(GetAsyncKeyState(S_KEY)!=0) return 1;
    else if(GetAsyncKeyState(A_KEY)!=0) return 2;
    else if(GetAsyncKeyState(D_KEY)!=0) return 3;
    else if(GetAsyncKeyState(C_KEY)!=0) return 4;
    else if(GetAsyncKeyState(F_KEY)!=0) return 5;
	else return 6;
}

int Presskey_2()
{
	if(GetAsyncKeyState(UP_KEY)!=0) return 7;
	else if(GetAsyncKeyState(DOWN_KEY)!=0) return 8;
	else if(GetAsyncKeyState(LEFT_KEY)!=0) return 9;
	else if(GetAsyncKeyState(RIGHT_KEY)!=0) return 10;
	else if(GetAsyncKeyState(a_KEY)!=0) return 11;
	else if(GetAsyncKeyState(s_KEY)!=0) return 12;
	else return 6;
}
