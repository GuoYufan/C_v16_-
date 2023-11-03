#include <stdio.h>
#define MAXSIZE 10

int top_endpoint,bottom_startpoint,bottom_endpoint,middle_leftpoint,middle_rightpoint;

int border_endpoint;

int top[MAXSIZE]={};
int bottom[MAXSIZE]={};
int middle[(MAXSIZE-2)*2]={};
int left[MAXSIZE-2]={};
int right[MAXSIZE-2]={};


void getflagpoint(int size,int startpoint)
{
	top_endpoint=startpoint+size-1;
	bottom_startpoint=startpoint+size*2-2;
	bottom_endpoint=startpoint+size*3-3;
	middle_leftpoint=startpoint+size*4-5;
	middle_rightpoint=startpoint+size;
	border_endpoint=middle_leftpoint;
}


void geteverypoint(int size,int startpoint)
{
	int  i=0,pt;
	
	for (i=0,pt=startpoint;pt<=top_endpoint;pt++,i++)
	{
		top[i]=pt;
	}
	
	for (i=0,pt=bottom_endpoint;pt>=bottom_startpoint;pt--,i++)
	{
		bottom[i]=pt;
	}
	
	for (i=0;i<size-2;i++)
	{
		middle[0+2*i]=middle_leftpoint-i;
		middle[0+2*i+1]=middle_rightpoint+i;
		left[i]=middle_leftpoint-i;
		right[i]=middle_rightpoint+i;
	}
}


void getborder(int size,int startpoint)
{
	getflagpoint(size,startpoint);
	geteverypoint(size,startpoint);
}


/*void view_point(int size)
{
	printf("--- point in %d border ---\n\n",size);
	
	int i=0;

	printf("top:");
	for (i=0;i<size;i++)
	{
		printf("%d ",*(top+i));
	}
	printf("\n");
	
	printf("bottom:");
	for (i=0;i<size;i++)
	{
		printf("%d ",*(bottom+i));
	}
	putchar(10);
	
	printf("middle:");
	for (i=0;i<(size-2)*2;i++)
	{
		printf("%d ",*(middle+i));
	}
	puts("");
	
	printf("left:");
	for (i=0;i<size-2;i++)
	{
		printf("%d ",*(left+i));
		
	}
	putchar(10);
	
	printf("right:");
	for (i=0;i<size-2;i++)
	{
		printf("%d ",*(right+i));
		
	}
	puts("\n");
}


void geteveryborder(int size,int startpoint)
{
	for (;size>=1;size-=2)
	{
		getborder(size,startpoint);
		view_point(size);
		startpoint=border_endpoint+1;
	}
}


void samples()
{
	printf("1 2 3\n8 9 4\n7 6 5\n\n");
	printf("1  2  3  4\n12 13 14 5\n"
	       "11 16 15 6\n10 9  8  7\n\n");
	getchar();
}


void main()
{
	//samples();
	
	int size=5,startpoint=1;
	
	for (;size>=1;size--)
	{
		printf("---every border in %d whole---\n\n",size);
		geteveryborder(size,startpoint);
		getchar();
	}
}*/



//updated:2021.10.7 2:33~
//《C_211006_螺旋数.c》
//写到现在 暂时还行吧

//updated:2021.10.9 14:13~
//进度更新