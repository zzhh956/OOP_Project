#include<iostream>
#include<graphics.h>
#include"printback.h"
using namespace std; 

void *imagec, *imagelf, *imageop_m1, *imageop_m2, *imagenopm1_1, *imagenopm1_2, *imagenopm2_1, *imagenopm2_2, *imagenopm2_3;

//background character
char *back[13] = {	".\\image\\background\\1.jpg", 
					".\\image\\background\\2.jpg",
					".\\image\\background\\3.jpg", 
					".\\image\\background\\4.jpg", 
					".\\image\\background\\5.jpg", 
					".\\image\\background\\6.jpg", 
					".\\image\\background\\7.jpg", 
					".\\image\\background\\8.jpg", 
					".\\image\\background\\9.jpg", 
					".\\image\\background\\10.jpg", 
					".\\image\\background\\11.jpg", 
					".\\image\\background\\12.jpg", 
					".\\image\\background\\13.jpg"  };
					
//size of background character					
int size[13][2] = { {357, 545} , 
					{358, 546} ,	
					{347, 546} ,
					{361, 546} ,
					{378, 546} ,
					{409, 549} ,
					{364, 546} ,
					{346, 546} ,
					{257, 541} ,
					{308, 546} ,
					{330, 546} ,
					{338, 546} ,
					{318, 546} };

void** getimage(char *filename, int wa, int ha, int pn, int wn, int hn, int bkcolor)
{	
	void **img = new void*[pn];
	int k=0, w=wa/wn, h=ha/hn;
		
	setbkcolor(bkcolor);
	cleardevice();
    readimagefile( filename, 0, 0, wa-1, ha-1);
	int size = imagesize(0, 0, w-1, h-1);
	for (int i=0; i<hn; i++) {
		for (int j=0; j<wn; j++) {			
  			img[k] = malloc(size);  //allocate space in memory
  			getimage(w*j, h*i, w*(j+1)-1, h*(i+1)-1, img[k]);
  			k++;
  			if (k==pn)
  				break;
		}
		if (k==pn)
  				break;
	}
	
	return img;
}

void* getimage(char *filename, int wa, int ha, int bkcolor)
{	
	void *img = malloc( imagesize(0, 0, wa-1, ha-1) );	
	setbkcolor(bkcolor);
	setactivepage(10);
	cleardevice();
    readimagefile(filename, 0, 0, wa-1, ha-1);
	getimage(0, 0, wa-1, ha-1, img);
	
	return img;
}

void getimgc(int pic)
{
	setactivepage(0);
	imagec = getimage(back[pic], size[pic][0], size[pic][1], 1);	
}

void getimglf()
{
	setactivepage(0);
	char *lf = ".\\image\\menu1\\1.jpg";
	imagelf = getimage(lf, 496, 80, 1);
}

void getimgop()
{
	setactivepage(0);
	char *op_m1 = ".\\image\\menu1\\2.jpg";
	imageop_m1 = getimage(op_m1, 282, 79, 1);
	char *op_m2 = ".\\image\\menu2\\1.jpg";
	imageop_m2 = getimage(op_m2, 305, 73, 1);
}

void getimgnop_m1()
{
	setactivepage(0);
	imagenopm1_1 = getimage(".\\image\\menu1\\3.jpg", 256, 26, 1);
	imagenopm1_2 = getimage(".\\image\\menu1\\4.jpg", 256, 29, 1);
}

void getimgnop_m2()
{
	setactivepage(0);
	imagenopm2_1 = getimage(".\\image\\menu2\\3.jpg", 210, 20, 1);
	imagenopm2_2 = getimage(".\\image\\menu2\\4.jpg", 238, 24, 1);
	imagenopm2_3 = getimage(".\\image\\menu2\\5.jpg", 164, 22, 1);
}

void printimg_m1(int i)
{
	setactivepage(i);
	setbkcolor(1);
	cleardevice();
	putimage(0, 0, imagec, 2);	
	putimage(150, 100, imagelf, 2);
	putimage(238, 275, imageop_m1, 2);
	if(i==0)
		putimage(252, 289, imagenopm1_1, 2);
	else
		putimage(252, 311, imagenopm1_2, 2);
	setvisualpage(i);
}

void printimg_m2(int i)
{
	setactivepage(i);
	setbkcolor(1);
	cleardevice();
	putimage(0, 0, imagec, 2);	
	putimage(150, 100, imagelf, 2);
	putimage(238, 275, imageop_m2, 2);
	if(i==0)
		putimage(285, 275, imagenopm2_1, 2);
	else if(i==1)
		putimage(268, 300, imagenopm2_2, 2);
	else
		putimage(306, 325, imagenopm2_3, 2);		
	setvisualpage(i);
}
