#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
// #define ROUND(a) ((int)(a+0.5))
int ROUND(float a)
{
  a=a+0.5;
  return (int) a;
}
int main()
{
int gdriver=DETECT,gmode,i;
char data[] = "C:\\MinGW\\lib\\libbgi.a";
initgraph(&gdriver,&gmode,data);
float x1,y1,x2,y2,dx,dy,xin,yin;
int step;
printf("Enter the coordinates of two points in the form of (x1,y1) and (x2,y2)\n");
scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
{
    step=abs(dx);
}
else
{
    step=abs(dy);
}
xin=dx/(float)step;
yin=dy/(float)step;
for(i=0;i<=step;i++)
{
  putpixel(ROUND(x1),ROUND(y1),YELLOW);
  x1=x1+xin;
  y1=y1+yin;
}
getch();
closegraph();
return 0;
}