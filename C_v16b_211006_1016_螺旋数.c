#include <stdio.h>
//#include "C_v15_point.h"
#define MAXSIZE 10

int spiralNumber[MAXSIZE*MAXSIZE]={};

void show_military_thisCityWall( int,int,int,int );
void show_spiralNumber( int );
void show_military_everyCityWall( int,int );


void show_military_thisCityWall(int sizeThisLayer,int startpoint,int way,int sizeZeroLayer)
{
	getborder(sizeThisLayer,startpoint);
	int *cityWall[3]={};
	
	int side=0;
	int *legion,soldier;
	int limit_side;
	int footstep,limit_legion,unoccupied;
	
	
	*cityWall=top;
	switch (sizeThisLayer)
	{
		case 1:
			limit_side=1;
			break;
		case 2:
			*(cityWall+1)=bottom;
			limit_side=2;
			break;
		default:
			*(cityWall+1)=middle;
			*(cityWall+2)=bottom;
			limit_side=3;
			break;
	}
	
	while (1)
	{
		if (side>limit_side-1) break;
		legion=*(cityWall+side);
		
		//--- top or bottom ---
		//if (*legion==top[0]||*legion==bottom[0])
		//if (side==0||side==2||(limit_side==2 && side==1))
		if (legion==top||legion==bottom)
		{
			limit_legion=sizeThisLayer;
			
			//--- top point or bottom point ---
			for (footstep=0;footstep<limit_legion;footstep++)
			{
				soldier=*(legion+footstep);
				//printf("%d\t",soldier);
				way++;
				*(spiralNumber+way)=soldier;
			}
			//go to the next line
			//putchar(10);
			if (!side)
			{
				way+=sizeZeroLayer-sizeThisLayer;
				//"way" must be changed after that whenever going to the next line
			}
			
			//go to the next "side" of "cityWall"
			side++;
			continue;
		}
		
		//--- middle ---
		//if (sizeThisLayer>2 && *legion==middle[0])
		//if (limit_side==3 && side==1)
		if (legion==middle)
		{
			limit_legion=(sizeThisLayer-2)*2;
			
			//--- left point or right point ---
			//when reach [0] [2] [4] ... is left point
			//means that even number
			//when reach [1] [3] [5] ... is right point
			//means that odd number
			for (footstep=0;footstep<limit_legion;footstep++)
			{
				soldier=*(legion+footstep);
				//printf("%d\t",soldier);
				way++;
				*(spiralNumber+way)=soldier;
				
				//--- if it's right point ---
				if ((footstep+1)%2==0)
				{
					//go to the next line
					//putchar(10);
					way+=sizeZeroLayer-sizeThisLayer;
					continue;
				}
				
				//--- null point ---
				for (unoccupied=0;unoccupied<sizeThisLayer-2;unoccupied++)
				{
					way++;
					//printf("[%d]\t",way);
				}
			}
			
			//go to the next "side" of "cityWall"
			side++;
			continue;
		}
	}
}


void show_spiralNumber(int sizeZeroLayer)
{
	printf("--- the spiral number for %d whole ---\n\n",sizeZeroLayer);
	
	for (int i=0;i<sizeZeroLayer*sizeZeroLayer;i++)
	{
		printf("%d\t",*(spiralNumber+i));
		if ( (i+1)%sizeZeroLayer==0 )
		{
			putchar(10);
		}
	}
}


void show_military_everyCityWall(int sizeZeroLayer,int startpoint)
{
	int sizeThisLayer=sizeZeroLayer;
	int way=-1;
		
	while (1)
	{
		if (sizeThisLayer<1) break;
		show_military_thisCityWall(sizeThisLayer,startpoint,way,sizeZeroLayer);
		startpoint+=sizeThisLayer*4-4;
		//probably you will alter "sizeThisLayer" before others like "startpoint",don't do that
		way+=sizeZeroLayer+1;
		sizeThisLayer-=2;
		//putchar(10);
	}
}


/*void main()
{
	int sizeZeroLayer=6,startpoint=1;
	
	show_military_everyCityWall(sizeZeroLayer,startpoint);
	show_spiralNumber(sizeZeroLayer);
}*/



//updated:2021.10.16 11:05~
//《C_v16_211006_1016_螺旋数.c》
//改版为 边框转螺旋数的同时（这时候已经在一边转螺旋数一边可以输出整图中所有位置上非空或为空的点）把位置得出
//而不用单独地另外地像得出点那样得出位置

//updated:2021.10.16 17:26~
//完成