#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
void DrawGraph(int xc,int yc,int x,int y)
{
    putpixel(x+xc,y+yc,YELLOW);
    putpixel(y+xc,x+xc,YELLOW);
    putpixel(-x+xc,y+yc,YELLOW);
    putpixel(-y+xc,x+yc,YELLOW);
    putpixel(x+xc,-y+yc,YELLOW);
    putpixel(y+xc,-x+xc,YELLOW);
    putpixel(-x+xc,-y+yc,YELLOW);
    putpixel(-y+xc,-x+xc,YELLOW);
}
int main()
{
int gdriver=DETECT,gmode,i;
char data[] = "C:\\MinGW\\lib\\libbgi.a";
initgraph(&gdriver,&gmode,data);
int xc,yc,x,y,r,p;
printf("Enter the coordinates of the center of the circle\n");
scanf("%d%d",&xc,&yc);
printf("Enter the radius of the circle\n");
scanf("%d",&r);
p=1-r;  
x=0;
y=r;
DrawGraph(xc,yc,x,y);
while (x <= y) {
    x++; // Increment x

    if (p < 0) {
        p = p + 2 * x + 3;
    } else {
        y--; // Decrement y
        p = p + 2 * x - 2 * y + 5;
    }

    // Draw the new points
    DrawGraph(xc, yc, x, y);
}
getch();
closegraph();
return 0;
}