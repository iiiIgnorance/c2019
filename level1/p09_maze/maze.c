#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define LENGTH 25
void print();
void place();
int move();
int Up();
int Down();
int Right();
int Left();

int x,y;
int map[LENGTH][LENGTH] ={	   
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{3,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0},
	{0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0},
	{0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0},
	{0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0},
	{0,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,0},
	{0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0},
	{0,1,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0},
	{0,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0},
	{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
	{0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,0},
	{0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0},
	{0,1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
	{0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,1,1,0},
	{0,0,0,1,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0},
	{0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,1,1,0,1,1,1,0},
	{0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0},
	{0,1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0},
	{0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0},
	{0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,4},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
int main()
{
	
	int p = 0;
	while(1)
	{
		p = move();
		if(p == 1)
			return 0;
	}	
	return 0;
}
void place()
{
	
	int i= 0,j = 0;
	for(i = 0;i < LENGTH;i++)
	{
		for(j = 0;j < LENGTH;j++)
		{
			if(map[i][j] == 3)
			{
				x = i;
				y = j;
				break;
			}
		}
	}
}
int move()
{
	int p = 0;
	while(1)
	{
		p = 0;
		place();
		print();
		printf("操作提示：上 下 左 右 控制人物移动，按Esc退出游戏\n");
		switch(getch())
		{
		case 72:p = Up();break;
		case 75:p = Left();break;
		case 80:p = Down();break;
		case 77:p = Right();break;
		case 27:return 1;
		}
		if(p == 1)
		{
			MessageBox(0,TEXT("恭喜过关"),TEXT("恭喜"),NULL);
			return 1;
		}
	}
}
void print()
{
	int i= 0,j = 0;
	system("cls");
	for(i = 0;i < LENGTH;i++)
	{
		for(j = 0;j < LENGTH;j++)
		{
			if(map[i][j] == 0)
				printf("■");
			else if(map[i][j] == 1)
				printf("  ");
			else if(map[i][j] == 3)
				printf("⊙");
			else if(map[i][j] == 4)
				printf("☆");
		}
		printf("\n");
	}
}
int Up()
{
	if(x != 0)
	{
		if(map[x-1][y] == 1)
		{
			map[x-1][y] = 3;
			map[x][y] = 1;
		}
		else if(map[x-1][y] == 4)
		{
			return 1;
		}
	}
	return 0;
}
int Down()
{
	if(x != LENGTH-1)
	{
		if(map[x+1][y] == 1)
		{
			map[x+1][y] = 3;
			map[x][y] = 1;
		}
		else if(map[x+1][y] == 4)
		{
			return 1;
		}
	}
	return 0;
}
int Right()
{
	if(y != LENGTH-1)
	{
		if(map[x][y+1] == 1)
		{
			map[x][y+1] = 3;
			map[x][y] = 1;
		}
		else if(map[x][y+1] == 4)
		{
			return 1;
		}
	}
	return 0;
}
int Left()
{
	if(y != 0)
	{
		if(map[x][y-1] == 1)
		{
			map[x][y-1] = 3;
			map[x][y] = 1;
		}
		else if(map[x][y-1] == 4)
		{
			return 1;
		}
	}
	return 0;
}
