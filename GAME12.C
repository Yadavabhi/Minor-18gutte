	#include<dos.h>
	#include<stdio.h>
	#include<conio.h>
	#include<graphics.h>
	main()
	{
	 union REGS i,o;
	 int a=DETECT,b;
         int button;
	  clrscr();
	 i.x.ax=0;
	initgraph(&a,&b,"C:\\TURBOC3\\BGI");




	line(160,120,160,360);   //Square
	line(480,120,480,360);
	line(160,120,480,120);
	line(160,360,480,360);

	line(240,120,240,360);    //Vertical Mid lines
	line(400,120,400,360);
	line(320,120,320,360);

	line(160,120,480,360);  //Diagonals
	line(160,360,480,120);

	line(160,240,480,240);  //Horizontal Mid lines
	line(160,180,480,180);
	line(160,300,480,300);

	line(160,240,320,360); //Inter joining of mid point
	line(480,240,320,360);
	line(160,240,320,120);
	line(480,240,320,120);

	line(7,240,160,240); //Mid line of right triangle
	line(80,180,80,300);


	line(7,120,160,240);  //Right triangle
	line(7,360,160,240);
	line(7,120,7,360);

	line(480,240,630,240); //Mid line of left triangle
	line(555,180,555,300);

	line(630,120,480,240); //Left Triangle
	line(630,360,480,240);
	line(630,120,630,360);
	setcolor(RED);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	outtextxy(160,120,"X");
	outtextxy(160,180,"X");
	outtextxy(160,240,"X");
	outtextxy(160,300,"X");
	outtextxy(160,300,"X");
	outtextxy(160,360,"X");
	outtextxy(7,120,"X");
	outtextxy(7,240,"X");
	outtextxy(7,360,"X");
	outtextxy(80,180,"X");
	outtextxy(80,300,"X");
	outtextxy(80,240,"X");
	outtextxy(240,120,"X");
	outtextxy(240,360,"X");
	outtextxy(240,180,"X");
	outtextxy(240,240,"X");
	outtextxy(240,300,"X");
	outtextxy(320,360,"X");
	outtextxy(320,300,"X");
	setcolor(GREEN);
	outtextxy(320,120,"O");
	outtextxy(320,180,"O");
	outtextxy(400,120,"O");
	outtextxy(400,180,"O");
	outtextxy(400,240,"O");
	outtextxy(400,300,"O");
	outtextxy(400,360,"O");
	outtextxy(480,360,"O");
	outtextxy(480,300,"O");
	outtextxy(480,240,"O");
	outtextxy(480,180,"O");
	outtextxy(480,120,"O");
	outtextxy(630,120,"O");
	outtextxy(630,240,"O");
	outtextxy(630,360,"O");
	outtextxy(555,180,"O");
	outtextxy(555,240,"O");
	outtextxy(555,300,"O");

       outtextxy(80,400,"PLAYER1");
       outtextxy(560,400,"PLAYER2");




int86(0x33,&i,&o);
if(o.x.ax==0)
{
printf("mouse not available");
 exit(0);
 }
i.x.ax=1;
int86(0x33,&i,&o);

gotoxy(35,4);
printf("press any key to exit");

while(!kbhit())
  {
  i.x.ax=3;
  int86(0x33,&i,&o);
  gotoxy(2,2);
  printf("x coordinate=%d\n y coordinate=%d",o.x.cx,o.x.dx);
  button=o.x.bx&7;
  gotoxy(30,25);
  switch(button)
	{
	  case 1:
	printf("Left button pressed");
	  break;

	  case 2:
	   printf("Right button pressed");
           break;
        
	  default:
	printf("No button pressed....");
	}
      }
i.x.ax=2;
int86(0x33,&i,&o);

closegraph();
return 0;
getch();
}
