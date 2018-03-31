#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
int mutex=1,full=0,empty=5,x=0,i=10,a=0;
	  char msg[100];
int main()
{
 int gd,i,gm;
  int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);

gd=DETECT;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
//background
setcolor(GREEN);
rectangle(0,0,1000,1000);
setfillstyle(1,GREEN);
floodfill(1,1,GREEN);
//buffer
setcolor(WHITE);
rectangle(200,80,650,130);
setfillstyle(1,BLUE);
floodfill(201,101,WHITE);

settextstyle(3,0,5);
outtextxy(150,0,"SIMULATION");
settextstyle(2,0,6);
outtextxy(400,10,"BUFFER SIZE is 5");
outtextxy(400,30,"(RED-producer");
outtextxy(400,50,"YELLOW-consumer)");
    printf("\n\n\n1.Producer\t2.Consumer\t3.Exit");

    while(1)
    {
	printf("\nEnter your choice:");
	scanf("\t%d",&n);
	switch(n)
	{
	    case 1:    if((mutex==1)&&(empty!=0))
			producer();
		    else
		    printf("buffer is full");

		    break;
	    case 2:    if((mutex==1)&&(full!=0))
			consumer();
		    else
		    printf("buffer is empty");

		    break;
	    case 3:
		    exit(0);
		    break;
	}
    }

    return 0;
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return(++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);
    itoa(x,msg,10);
    i=i+50;
    settextstyle(2,0,5);
    outtextxy(a=181+i,101,msg);

    setcolor(BLACK);
    circle(181+i,101,20);
    setfillstyle(1,RED);

   floodfill(180+i,102,BLACK);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;

    setcolor(BLACK);

     circle(a,101,20);
    setfillstyle(1,YELLOW);

   floodfill(a-1,102,BLACK);
     a=a-50;
    mutex=signal(mutex);
}
