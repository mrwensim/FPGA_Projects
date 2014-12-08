/*
 * lcd.h
 *
 *  Created on: 2013-9-6
 *      Author: tjy
 */
#include "xparameters.h"
#include "stdio.h"
#include "xbasic_types.h"
#include "mb_interface.h"

#ifndef TFT_H_
#define TFT_H_

#define write_com( reg,da){send_command(reg);send_data(da);}
#define send_command(reg) microblaze_bwrite_cntlfsl(reg, 0)
#define send_data(da) microblaze_bwrite_datafsl(da , 0)

typedef  unsigned char uchar;
typedef  unsigned int  uint;
typedef  unsigned long int ulong;


#define TRANSP  1           //������ʾ��ʱ�򲻴�������ɫ
#define NORMAL  0           //������ʾ��ʱ���б�����ɫ

//����LCD�ĳߴ�
#define LCD_W 240
#define LCD_H 320

//������ɫ
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 		 0XFFE0
#define GBLUE		 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 		 0XBC40 //��ɫ
#define BRRED 		 0XFC07 //�غ�ɫ
#define GRAY  		 0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ

#define LIGHTGREEN     	 0X841F //ǳ��ɫ
#define LGRAY 		 0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

void Init_IO(void);
void DelayNS(unsigned int time);
unsigned int rece_data(void);
void ssd1289_init(void);
void tft_9325_init(void);
void tft_9320_init(void);
void DispOneColor(unsigned int Color);
void DispClear(void);
void Set_ramaddr(unsigned int x,unsigned int y);
void DrawSingleAscii(unsigned int x, unsigned int y, unsigned char *pAscii, unsigned int LineColor,unsigned int FillColor, unsigned char Mod);
//void DrawSingleHz(unsigned int x, unsigned int y, unsigned char *pHz, unsigned int LineColor,unsigned int FillColor, unsigned char Mod);
void DrawString(unsigned int x, unsigned int y, unsigned char *pStr, unsigned int LineColor,unsigned int FillColor, unsigned char Mod);
void DispNum(unsigned int x, unsigned int y, unsigned short num);
void DispSmallPic(unsigned int x, unsigned int y, unsigned int w, unsigned int h, const unsigned char *str);

void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void LCD_ShowChar(uint x,uint y, uchar num,uint LineColor, uint FillColor, uchar mode);
void LCD_ShowString(uint x,uint y,uint LineColor, uint FillColor,const uchar *p, uchar mode);
void LCD_ShowNum(uint x,uint y,ulong num,uint LineColor, uint FillColor,uchar len);
void LCD_Show2Num(uint x,uint y,uint num,uint LineColor, uint FillColor,uchar len);
void LCD_DrawPoint(uint x,uint y,uint POINT_COLOR);//����
void LCD_DrawPoint_big(uint x,uint y,uint POINT_COLOR);//��һ�����
void LCD_Fill(uint xsta,uint ysta,uint xend,uint yend,uint color);//��ָ�����������ָ����ɫ
void Draw_Circle(uint x0,uint y0,uchar r, uint color);  //��Բ
void LCD_DrawLine(uint x1, uint y1, uint x2, uint y2, uint color);//  ����
void LCD_DrawRectangle(uint x1, uint y1, uint x2, uint y2, uint color);//������
void showhanzi(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor);
void showzifu(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor);
void showimage(uint x, uint y, uint w, uint h,const uchar *str); //��ʾ40*40ͼƬ
void TestColorLine(void);



#endif



