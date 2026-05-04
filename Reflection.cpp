#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>
int main()
{
  int gd= DETECT,gm;
  initgraph(&gd,&gm,"");
  line(320,0,320,480);
  line(0,240,640,240);
  float x1=100,y1=100,x2=200,y2=100,x3=150,y3=200;
  line(x1,y1,x2,y2);
  line(x2,y2,x3,y3);
  line(x3,y3,x1,y1);
  y1=y1-240;
  y2=y2-240;
  y3=y3-240;
  y1=-y1;
  y2=-y2;
  y3=-y3;
  y1=y1+240;
  y2=y2+240;
  y3=y3+240;
  line(x1,y1,x2,y2);
  line(x2,y2,x3,y3);
  line(x3,y3,x1,y1);
  getch();
  closegraph();
  return 0;
  }
