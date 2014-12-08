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


#define TRANSP  1           //字体显示的时候不带背景颜色
#define NORMAL  0           //字体显示的时候有背景颜色

//定义LCD的尺寸
#define LCD_W 240
#define LCD_H 320

//画笔颜色
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
#define BROWN 		 0XBC40 //棕色
#define BRRED 		 0XFC07 //棕红色
#define GRAY  		 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色

#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 		 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

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
void LCD_DrawPoint(uint x,uint y,uint POINT_COLOR);//画点
void LCD_DrawPoint_big(uint x,uint y,uint POINT_COLOR);//画一个大点
void LCD_Fill(uint xsta,uint ysta,uint xend,uint yend,uint color);//在指定区域内填充指定颜色
void Draw_Circle(uint x0,uint y0,uchar r, uint color);  //画圆
void LCD_DrawLine(uint x1, uint y1, uint x2, uint y2, uint color);//  划线
void LCD_DrawRectangle(uint x1, uint y1, uint x2, uint y2, uint color);//画矩形
void showhanzi(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor);
void showzifu(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor);
void showimage(uint x, uint y, uint w, uint h,const uchar *str); //显示40*40图片
void TestColorLine(void);



#endif



