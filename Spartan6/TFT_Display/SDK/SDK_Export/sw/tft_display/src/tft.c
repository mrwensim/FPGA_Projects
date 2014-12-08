#include "tft.h"
#include "font.h"


void Delays(void)
{
    int i,j;
    for(i=0;i<200;i++)
            for(j=0;j<1000;j++);
}
//=================================
void DelayNS(uint time)
{
    while(time--!=0);
}
//发送命令


//初始化LCD控制器
/*
Display Type:4
BPP setting:3
USB Speed:2
Bus Mode:1
Seg:240
Com:320
interval:0000
*/

void tft_9320_init(void)
{
    DelayNS(1000);

//*********************************************Start intial Sequence
    write_com(0x00e5,0x8000);
    write_com(0x0000,0x0001);
    DelayNS(1000);
    write_com(0x0001,0x0100);
    write_com(0x0002,0x0700);
    write_com(0x0003,0x1030);
    write_com(0x0004,0x0000);
    write_com(0x0008,0x0202);
    write_com(0x0009,0x0000);
    write_com(0x000a,0x0000);
    write_com(0x000c,0x0000);
    write_com(0x000d,0x0000);
    write_com(0x000f,0x0000);
//*********************************************Power On
    write_com(0x0010,0x0000);
    write_com(0x0011,0x0000);
    write_com(0x0012,0x0000);
    write_com(0x0013,0x0000);
    write_com(0x0010,0x17b0);
    write_com(0x0011,0x0037);
    write_com(0x0012,0x0138);
    write_com(0x0013,0x1700);
    write_com(0x0029,0x000d);
    write_com(0x0020,0x0000);
    write_com(0x0021,0x0000);
//*********************************************Set gamma
    write_com(0x0030,0x0001);
    write_com(0x0031,0x0606);
    write_com(0x0032,0x0304);
    write_com(0x0033,0x0202);
    write_com(0x0034,0x0202);
    write_com(0x0035,0x0103);
    write_com(0x0036,0x011d);
    write_com(0x0037,0x0404);
    write_com(0x0038,0x0404);
    write_com(0x0039,0x0404);
    write_com(0x003c,0x0700);
    write_com(0x003d,0x0a1f);
//**********************************************Set Gram aera
    write_com(0x0050,0x0000);
    write_com(0x0051,0x00ef);
    write_com(0x0052,0x0000);
    write_com(0x0053,0x013f);
    write_com(0x0060,0x2700);
    write_com(0x0061,0x0001);
    write_com(0x006a,0x0000);
//*********************************************Paratial display
    write_com(0x0090,0x0010);
    write_com(0x0092,0x0000);
    write_com(0x0093,0x0003);
    write_com(0x0095,0x0101);
    write_com(0x0097,0x0000);
    write_com(0x0098,0x0000);
//******************************************** Plan Control
    write_com(0x0007,0x0021);
    write_com(0x0007,0x0031);
    write_com(0x0007,0x0173);
    send_command(0x0022);
}

void tft_9325_init(void)
{

//调用一次这些函数，免得编译的时候提示警告

    write_com(0x0001,0x0100);
    write_com(0x0002,0x0700);
    write_com(0x0003,0x1030);
    write_com(0x0004,0x0000);
    write_com(0x0008,0x0207);
    write_com(0x0009,0x0000);
    write_com(0x000A,0x0000);
    write_com(0x000C,0x0000);
    write_com(0x000D,0x0000);
    write_com(0x000F,0x0000);
    //power on sequence VGHVGL
    write_com(0x0010,0x0000);
    write_com(0x0011,0x0007);
    write_com(0x0012,0x0000);
    write_com(0x0013,0x0000);
    //vgh
    write_com(0x0010,0x1290);
    write_com(0x0011,0x0227);
    //delayms(100);
    //vregiout
    write_com(0x0012,0x001d); //0x001b
    //delayms(100);
    //vom amplitude
    write_com(0x0013,0x1500);
    //delayms(100);
    //vom H
    write_com(0x0029,0x0018);
    write_com(0x002B,0x000D);

    //gamma
    write_com(0x0030,0x0004);
    write_com(0x0031,0x0307);
    write_com(0x0032,0x0002);// 0006
    write_com(0x0035,0x0206);
    write_com(0x0036,0x0408);
    write_com(0x0037,0x0507);
    write_com(0x0038,0x0204);//0200
    write_com(0x0039,0x0707);
    write_com(0x003C,0x0405);// 0504
    write_com(0x003D,0x0F02);
    //ram
    write_com(0x0050,0x0000);
    write_com(0x0051,0x00EF);
    write_com(0x0052,0x0000);
    write_com(0x0053,0x013F);
    write_com(0x0060,0xA700);
    write_com(0x0061,0x0001);
    write_com(0x006A,0x0000);
    //
    write_com(0x0080,0x0000);
    write_com(0x0081,0x0000);
    write_com(0x0082,0x0000);
    write_com(0x0083,0x0000);
    write_com(0x0084,0x0000);
    write_com(0x0085,0x0000);
    //
    write_com(0x0090,0x0010);
    write_com(0x0092,0x0600);
    write_com(0x0093,0x0003);
    write_com(0x0095,0x0110);
    write_com(0x0097,0x0000);
    write_com(0x0098,0x0000);
    write_com(0x0007,0x0133);
}

void ssd1289_init(void)
{

    write_com(0x0000,0x0001);    DelayNS(1000);  //打开晶振
    write_com(0x0003,0xA8A4);    DelayNS(1000);   //0xA8A4
    write_com(0x000C,0x0000);    DelayNS(1000);
    write_com(0x000D,0x080C);    DelayNS(1000);
    write_com(0x000E,0x2B00);    DelayNS(1000);
    write_com(0x001E,0x00B0);    DelayNS(1000);
    write_com(0x0001,0x2B3F);    DelayNS(1000);   //驱动输出控制320*240  0x6B3F
    write_com(0x0002,0x0600);    DelayNS(1000);
    write_com(0x0010,0x0000);    DelayNS(1000);
    write_com(0x0011,0x6070);    DelayNS(1000);        //0x4030           //定义数据格式  16位色
    write_com(0x0005,0x0000);    DelayNS(1000);
    write_com(0x0006,0x0000);    DelayNS(1000);
    write_com(0x0016,0xEF1C);    DelayNS(1000);
    write_com(0x0017,0x0003);    DelayNS(1000);
    write_com(0x0007,0x0233);    DelayNS(1000);        //0x0233
    write_com(0x000B,0x0000);    DelayNS(1000);
    write_com(0x000F,0x0000);    DelayNS(1000);        //扫描开始地址
    write_com(0x0041,0x0000);    DelayNS(1000);
    write_com(0x0042,0x0000);    DelayNS(1000);
    write_com(0x0048,0x0000);    DelayNS(1000);
    write_com(0x0049,0x013F);    DelayNS(1000);
    write_com(0x004A,0x0000);    DelayNS(1000);
    write_com(0x004B,0x0000);    DelayNS(1000);
    write_com(0x0044,0xEF00);    DelayNS(1000);
    write_com(0x0045,0x0000);    DelayNS(1000);
    write_com(0x0046,0x013F);    DelayNS(1000);
    write_com(0x0030,0x0707);    DelayNS(1000);
    write_com(0x0031,0x0204);    DelayNS(1000);
    write_com(0x0032,0x0204);    DelayNS(1000);
    write_com(0x0033,0x0502);    DelayNS(1000);
    write_com(0x0034,0x0507);    DelayNS(1000);
    write_com(0x0035,0x0204);    DelayNS(1000);
    write_com(0x0036,0x0204);    DelayNS(1000);
    write_com(0x0037,0x0502);    DelayNS(1000);
    write_com(0x003A,0x0302);    DelayNS(1000);
    write_com(0x003B,0x0302);    DelayNS(1000);
    write_com(0x0023,0x0000);    DelayNS(1000);
    write_com(0x0024,0x0000);    DelayNS(1000);
    write_com(0x0025,0x8000);    DelayNS(1000);
    write_com(0x004f,0);        //行首址0
    write_com(0x004e,0);        //列首址0
    send_command(0x22);
}


void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
    write_com(0x0020,x1);   //设置X坐标位置
    write_com(0x0021,y1);   //设置Y坐标位置
    write_com(0x0050,x1);   //开始X
    write_com(0x0052,y1);   //开始Y
    write_com(0x0051,x2);   //结束X
    write_com(0x0053,y2);   //结束Y
    send_command(0x0022);
}

//清屏函数
/**************************************************************************************
* 名    称: DispOneColor
* 功    能: 全屏显示某种颜色
* 参    数: Color   : 颜色值
* 返 回 值: 无
*
* 修改历史:
*   版本    日期     作者     改动内容和原因
*   ----------------------------------------------------
*   1.0   2007.6.13  lcf       基本的功能完成
**************************************************************************************/
void DispOneColor(unsigned int Color)
{
  unsigned int i,j;
  Address_set(0,0,LCD_W-1,LCD_H-1);
  for(i=0;i<LCD_W;i++)
   {
    for (j=0;j<LCD_H;j++)
          {
           send_data(Color);
      }
   }
}

/**************************************************************************************
* 名    称: DispClear
* 功    能: 清除显示屏的显示内容
* 参    数: 无
* 返 回 值: 无
*
* 修改历史:
*   版本    日期     作者     改动内容和原因
*   ----------------------------------------------------
*   1.0   2006.8.13  lcf       基本的功能完成
**************************************************************************************/
void DispClear(void)
{
    DispOneColor(WHITE);
}

//在指定位置显示一个字符

//num:要显示的字符:" "--->"~"
//mode:叠加方式(1)还是非叠加方式(0)
//在指定位置显示一个字符
//num:要显示的字符:" "--->"~"
//mode:叠加方式(1)还是非叠加方式(0)
void LCD_ShowChar(uint x,uint y, uchar num,uint LineColor, uint FillColor, uchar mode)
{
    unsigned char temp;
    unsigned char pos,t;
    unsigned int x0=x;
    unsigned int POINT_COLOR;

    if(x>LCD_W-16||y>LCD_H-16)return;
	//设置窗口
	num=num-' ';//得到偏移后的值
	Address_set(x,y,x+8-1,y+16-1);      //设置光标位置
	if(!mode) //非叠加方式
	{
          for(pos=0;pos<16;pos++)
          {
                  temp=asc2_1608[(uint)num*16+pos];		 //调用1608字体
                  for(t=0;t<8;t++)
                  {
                      if(temp&0x01)
                        POINT_COLOR=LineColor;
                      else
                        POINT_COLOR=FillColor;

                      send_data(POINT_COLOR);
                      temp>>=1;
                      x++;
                  }
                  x=x0;
                  y++;
          }
	}

        else//叠加方式
	{
                  temp=asc2_1608[(uint)num*16+pos];		 //调用1608字体
                  for(t=0;t<8;t++)
                  {
                      if(temp&0x01)
                        POINT_COLOR=LineColor;
                      else
                        POINT_COLOR=BLACK;

                      send_data(POINT_COLOR);
                      temp>>=1;
                      x++;
                  }
                  x=x0;
                  y++;
	}

}

//显示字符串
//x,y:起点坐标
//*p:字符串起始地址
//用16字体
void LCD_ShowString(uint x,uint y,uint LineColor, uint FillColor,const uchar *p, uchar mode)
{
    while(*p!='\0')
    {
        if(x>LCD_W-16)
          {x=0;y+=16;}
        if(y>LCD_H-16)
          {y=x=0;}

        LCD_ShowChar(x,y,*p,LineColor, FillColor,mode);
        x+=8;
        p++;
    }
}

//m^n函数
ulong mypow(uchar m,uchar n)
{
	ulong result=1;
	while(n--)result*=m;
	return result;
}
//显示2个数字
//x,y :起点坐标
//len :数字的位数
//color:颜色
//num:数值(0~4294967295);
void LCD_ShowNum(uint x,uint y,ulong num,uint LineColor, uint FillColor,uchar len)
{
	uchar t,temp;
	uchar enshow=0;
	num=(uint)num;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+8*t,y,' ',LineColor, FillColor,0);
				continue;
			}else enshow=1;

		}
	 	LCD_ShowChar(x+8*t,y,temp+48,LineColor, FillColor,0);
	}
}
//显示2个数字
//x,y:起点坐标
//num:数值(0~99);
void LCD_Show2Num(uint x,uint y,uint num,uint LineColor, uint FillColor,uchar len)
{
	uchar t,temp;
	for(t=0;t<len;t++)
	{
		temp=(num/mypow(10,len-t-1))%10;
	 	LCD_ShowChar(x+8*t,y,temp+'0',LineColor, FillColor,0);
	}
}


//画点
//POINT_COLOR:此点的颜色
void LCD_DrawPoint(uint x,uint y,uint POINT_COLOR)
{
	Address_set(x,y,x,y);//设置光标位置
	send_data(POINT_COLOR);
}
//画一个大点
//POINT_COLOR:此点的颜色
void LCD_DrawPoint_big(uint x,uint y,uint POINT_COLOR)
{
	LCD_Fill(x-1,y-1,x+1,y+1,POINT_COLOR);
}
//在指定区域内填充指定颜色
//区域大小:
//  (xend-xsta)*(yend-ysta)
void LCD_Fill(uint xsta,uint ysta,uint xend,uint yend,uint color)
{
	uint i,j;
	Address_set(xsta,ysta,xend,yend);      //设置光标位置
	for(i=ysta;i<=yend;i++)
	{
		for(j=xsta;j<=xend;j++)   //设置光标位置
                  send_data(color);
	}
}
//画线
//x1,y1:起点坐标
//x2,y2:终点坐标
void LCD_DrawLine(uint x1, uint y1, uint x2, uint y2, uint color)
{
	uint t;
	int xerr=0,yerr=0,delta_x,delta_y,distance;
	int incx,incy,uRow,uCol;

	delta_x=x2-x1; //计算坐标增量
	delta_y=y2-y1;
	uRow=x1;
	uCol=y1;
	if(delta_x>0)incx=1; //设置单步方向
	else if(delta_x==0)incx=0;//垂直线
	else {incx=-1;delta_x=-delta_x;}
	if(delta_y>0)incy=1;
	else if(delta_y==0)incy=0;//水平线
	else{incy=-1;delta_y=-delta_y;}
	if( delta_x>delta_y)distance=delta_x; //选取基本增量坐标轴
	else distance=delta_y;
	for(t=0;t<=distance+1;t++ )//画线输出
	{
		LCD_DrawPoint(uRow,uCol,color);//画点
		xerr+=delta_x ;
		yerr+=delta_y ;
		if(xerr>distance)
		{
			xerr-=distance;
			uRow+=incx;
		}
		if(yerr>distance)
		{
			yerr-=distance;
			uCol+=incy;
		}
	}
}
//画矩形
void LCD_DrawRectangle(uint x1, uint y1, uint x2, uint y2, uint color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
//在指定位置画一个指定大小的圆
//(x,y):中心点
//r    :半径
void Draw_Circle(uint x0,uint y0,uchar r, uint color)
{
	int a,b;
	int di;
	a=0;b=r;
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0-b,y0-a,color);             //3
		LCD_DrawPoint(x0+b,y0-a,color);             //0
		LCD_DrawPoint(x0-a,y0+b,color);             //1
		LCD_DrawPoint(x0-b,y0-a,color);             //7
		LCD_DrawPoint(x0-a,y0-b,color);             //2
		LCD_DrawPoint(x0+b,y0+a,color);             //4
		LCD_DrawPoint(x0+a,y0-b,color);             //5
		LCD_DrawPoint(x0+a,y0+b,color);             //6
		LCD_DrawPoint(x0-b,y0+a,color);
		a++;
		//使用Bresenham算法画圆
		if(di<0)di +=4*a+6;
		else
		{
			di+=10+4*(a-b);
			b--;
		}
		LCD_DrawPoint(x0+a,y0+b,color);
	}
}


//在指定位置显示一个汉字(32*33大小)
//dcolor为内容颜色，gbcolor为背静颜色
void showhanzi(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor)
{
    unsigned char i,j;
    Address_set(x,y,x+31,y+31); //设置区域
    for(j=0;j<128;j++)
    {
        for(i=0;i<8;i++)
        {
                if((*str&(1<<i))!=0)
                {
                        send_data(LineColor);
                }
                else
                {
                        send_data(FillColor);
                }
        }
        str++;
    }
}

void showzifu(unsigned int x,unsigned int y,const uchar *str,uint LineColor, uint FillColor)
{
    unsigned char i,j;
    Address_set(x,y,x+15,y+31); //设置区域
    for(j=0;j<64;j++)
    {
        for(i=0;i<8;i++)
        {
                if((*str&(1<<i))!=0)
                {
                        send_data(LineColor);
                }
                else
                {
                        send_data(FillColor);
                }
        }
        str++;
    }
}

void  showimage(uint x, uint y, uint w, uint h,const uchar *str) //显示40*40图片
{
  	int i,temp;
//	DispOneColor(WHITE); //清屏
        LCD_Fill(x,y,w,h,WHITE);
        Address_set(x,y,x+w-1,y+h-1);		//坐标设置
        for(i=0;i<1600;i++)
          {
            temp=str[i*2+1]<<8;     //低位在前
            temp|=str[i*2];
            send_data(temp);
          }

}

void TestColorLine(void)
{
    uchar R_data=0;
    uchar G_data=0;
    uchar B_data=0;
    uchar i;
    uint j;

    /*红色渐强条*/
    R_data=0;
    G_data=0;
    B_data=0;
    for(j=0;j<20;j++)
    {
        Address_set(0,j+320,240,19);
        for(i=0;i<240;i++)
        {
            R_data=i/8;
            send_data(R_data<<11|G_data<<5|B_data);
        }
    }

    R_data=0x1f;
    G_data=0x3f;
    B_data=0x1f;
    for(j=0;j<20;j++)
    {
        Address_set(0,j+300,240,39);
        for(i=0;i<240;i++)
        {
			G_data=0x3f-(i/4);
			B_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);
        }
	}
    /*绿色渐强条*/
    R_data=0;
    G_data=0;
    B_data=0;
    for(j=0;j<20;j++)
	{
        Address_set(0,j+280,240,59);
        for(i=0;i<240;i++)
        {
          G_data=i/4;
          send_data(R_data<<11|G_data<<5|B_data);
        }
	}


    R_data=0x1f;
    G_data=0x3f;
    B_data=0x1f;
    for(j=0;j<20;j++)
	{
        Address_set(0,j+260,240,79);
        for(i=0;i<240;i++)
        {
			R_data=0x1f-(i/8);
			B_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);
        }
	}
    /*蓝色渐强条*/
    R_data=0;
    G_data=0;
    B_data=0;
    for(j=0;j<20;j++)
	{
        Address_set(0,j+240,240,99);
        for(i=0;i<240;i++)
        {
          B_data=i/8;
          send_data(R_data<<11|G_data<<5|B_data);
        }
	}

    R_data=0x1f;
    G_data=0x3f;
    B_data=0x1f;
    for(j=0;j<20;j++)
	{
        Address_set(0,j+220,240,119);
        for(i=0;i<240;i++)
        {
			G_data=0x3f-(i/4);
			R_data=0x1f-(i/8);
			send_data(R_data<<11|G_data<<5|B_data);
        }
	}
}



