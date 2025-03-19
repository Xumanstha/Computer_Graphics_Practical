#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>
// #define ROUND(a) ((int)(a+0.5))
void x_basis(float x, float y, float dy, float dx, int step)
{
  float m1, m2;
  m1 = dx > 0 ? 1 : -1;
  m2 = dy > 0 ? 1 : -1;
  float p = 2 * abs(dy) - abs(dx);
  for (int i = 0; i < step; i++)
  {
    if (p < 0)
    {
      x = x + m1;
      p = p + 2 * abs(dy);
      putpixel(x, y, YELLOW);
    }
    else if (p >= 0)
    {
      y = y + m2;
      p = p + 2 * abs(dy) - 2 * abs(dx);
      x = x + m1;
      putpixel(x, y, YELLOW);
    }
  }
}
void y_basis(float x, float y, float dy, float dx, int step)
{

  float m1, m2;
  m1 = dx > 0 ? 1 : -1;
  m2 = dy > 0 ? 1 : -1;
  float p = 2 * abs(dx) - abs(dy);
  for (int i = 0; i < step; i++)
  {
    if (p < 0)
    {
      y = y + m2;
      p = p + 2 * abs(dx);
      putpixel(x, y, YELLOW);
    }
    else if (p >= 0)
    {
      y = y + m2;
      p = p + 2 * abs(dx) - 2 * abs(dy);
      x = x + m1;
      putpixel(x, y, YELLOW);
    }
  }
}
int main()
{
  int gdriver = DETECT, gmode;
  char data[] = "C:\\MinGW\\lib\\libbgi.a";
  initgraph(&gdriver, &gmode, data);
  float x1, y1, x2, y2, dy, dx, m;
  int step;
  printf("Enter the coordinates of two points in line in (x1,y1) and (x2,y2)\n");
  scanf("%f%f%f%f", &x1, &y1, &x2, &y2);

  dx = x2 - x1;
  dy = y2 - y1;
  m = dy / dx;
  if (dy > dx)
  {
    step = abs(dy);
  }
  else
  {
    step = abs(dx);
  }
  if (abs(m) < 1)
  {
    x_basis(x1, y1, dy, dx, step);
  }
  else
  {
    y_basis(x1, y1, dy, dx, step);
  }
  getch();
  closegraph();
  return 0;
}
