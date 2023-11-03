#include <stdio.h>
#include "CSpiral.h"
#include <time.h>

int* 问()
{
	int sizeZeroLayer=5,startpoint=1;
	char* 问边长="◾️️请输入边长:";
	static int 答[2]={};
	
	while (1)
	{
		printf(问边长);
		scanf("%d",&sizeZeroLayer);
		if (getchar()!='\n')
		{
			while (getchar()!=10){}
			continue;
		}
		else if (sizeZeroLayer<1 || sizeZeroLayer>10) continue;
		else break;
	}
	
	for (putchar(10);!0;)
	{
		printf("◾️请输入起点:");
		scanf("%d",&startpoint);
		if (getchar()==10) break;
		else
		{
			scanf("%*[^\n]%*c");
			continue;
		}
	}
	putchar(10);
	
	答[0]=sizeZeroLayer;
	*(答+1)=startpoint;
	
	return 答;
}


void 果()
{
	int *设置=问();
	
	time_t begin,end;
	double ticks,runtime;
	begin=clock();
	
	int 最外层边长=设置[0];
	int 起始值=设置[1];
	
	//for (int i=0;i<10;i++)
	{
	示整图每层边框(最外层边长,起始值);
	示螺旋数(最外层边长);
	putchar(10);
	}
	
	end=clock();
	ticks=( double )(end-begin);
	runtime=ticks/CLOCKS_PER_SEC;
	printf("machine ticks:%lf ticks",ticks);
	printf("(runtime:%lf s)\n\n",runtime);
}


void main()
{
	for (;1;) 果();
}



//updated:2021.10.7 2:33~
//写到现在 暂时还行吧

//updated:2021.10.9 14:13~
//进度更新

//created:2021.10.9 14:30
//我们先看常规的 再看特殊的
//本身数值就是横向输出的 这是我们习以为常
//螺旋数却打破了我们的习惯
//那么我认为可以先从我们的习惯入手
//既然我们习惯了数值的横向输出
//那么我们先来看看数值的横向输出是什么样的
//而数值的螺旋向输出与之不同之处又在哪
//就在于把同一个数值放到了别的位置
//所以其根本在于：数值的放置
//考虑什么样的数值被放置在了什么样的位置
//反过来考虑什么样的位置出现什么样的数值
//就会发现什么样的数值一定被放置在了什么位置
//同样 什么位置一定出现什么样的数值
//再转螺旋向输出

//updated:2021.10.12 11.31~
//进度更新

//updated:2021.10.12 17:23~
//进度更新

//updated:2021.10.12 18:22~
//大进展
//完成left right

//updated:2021.10.12 18:59~
//又有大进展
//完成top

//updated:2021.10.12 20:16~
//大进展
//完成bottom 从而一条边框的四条边全部完成

//updated:2021.10.12 21:09~
//实现输出螺旋数

//updated:2021.10.12 22:13~
//完成

//updated:2021.10.13 9:13~
//修复了边长大于5时的问题
//问题由于left/right的增量错误 不应为+=size 而应为+=sizeZeroLayer
//该错误在边长小于等于5的情况下是隐蔽的

//updated:2021.10.13 23:57~
//添加isin功能

//updated:2021.10.16 11:05~
//《C_v16_211006_1016_螺旋数.c》
//改版为 边框转螺旋数的同时（这时候已经在一边转螺旋数一边可以输出整图中所有位置上非空或为空的点）把位置得出
//而不用单独地另外地像得出点那样得出位置

//updated:2021.10.16 17:26~
//完成