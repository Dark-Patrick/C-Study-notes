#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#define SIZE 25 //定义地图大小
using namespace std;
void init(int&, int&, int[SIZE][SIZE]);
int getCommand(int);
int move(int, int*, int[SIZE][SIZE]);
void draw(int[SIZE][SIZE]);

int main(){
	cout << "*****************************************" << '\n'
		<< "*********press:WASD to move**************" << '\n'
		<< "*********press:space to stop*************" << '\n'
		<< "**********press:Q to quit****************" << '\n'
		<< "*****************************************" << endl;
	system("pause");

	int map[SIZE][SIZE] = { 0 };
	int command, result, length = 0; //length表示蛇的长度
	init(command, length, map); //初始化游戏
	while (1)
	{
		command = getCommand(command); //获取玩家输入的命令
		result = move(command, &length, map); //根据命令移动蛇
		if (result == 1) //分析移动的结果
		{
			break;
		}
		else
		{
			draw(map); //将蛇画到控制台
		}
		Sleep(200);
	}
	cout << "you lose!" << '\n' << '\n';
	system("pause");
}


void init(int& command, int& length, int map[SIZE][SIZE])
{
	//初始化初始命令
	command = 2; //初始命令向下
	//初始化蛇的长度
	length = 3;
	//初始化蛇的位置
	map[2][1] = 1;
	map[1][1] = 2;
	map[0][1] = 3;
	//初始化食物的位置
	map[3][3] = -1;
}

int getCommand(int command)
{
	int temp = -1;
	if (_kbhit()) //如果有键盘输入
	{
		switch (_getch())
		{
		case 'A': case 'a': temp = 3; break; //表示向左
		case 'S': case 's': temp = 2; break; //表示向下
		case 'D': case 'd': temp = 1; break; //表示向右
		case 'W': case 'w': temp = 0; break; //表示向上
		case' ':system("pause"); 
			break;//暂停游戏
		case'q':case'Q':
			cout << "游戏结束" << endl;
			system("pause");
			exit(0);
			break;
		}
		if (temp != -1 && abs(command - temp) != 2) //蛇不能反向
		{
			command = temp;
		}
	}
	return command;
}

int move(int command, int* length, int map[SIZE][SIZE])
{
	int i, j, head_i, head_j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (map[i][j] == *length) //如果是蛇的最后一节身体
			{
				map[i][j] = 0;
			}
			else if (map[i][j] > 1) //如果是蛇中间节的身体
			{
				map[i][j] += 1;
			}
			else if (map[i][j] == 1) //如果是蛇头
			{
				map[i][j] += 1;
				//确定蛇头新的位置head_i和head_j
				switch (command)
				{
				case 0: head_i = i - 1, head_j = j; break;
				case 1: head_i = i, head_j = j + 1; break;
				case 2: head_i = i + 1, head_j = j; break;
				case 3: head_i = i, head_j = j - 1; break; 
				}
			}
		}
	}
	if (map[head_i][head_j] == -1) //如果吃到了食物
	{
		map[head_i][head_j] = 1;
		*length = *length + 1; //蛇的长度加一
		//重新生成食物
		while (1)
		{
			i = rand() % SIZE, j = rand() % SIZE;
			if (map[i][j] == 0)
			{
				map[i][j] = -1;
				break;
			}
		}
	}
	//如果撞到了自己或者撞到了墙
	else if (map[head_i][head_j] >0 || head_i < 0 || head_i == SIZE || head_j < 0 || head_j == SIZE)
	{
		return 1;
	}
	/*else
	{
		map[head_i][head_j] = 1;
	}*/
	map[head_i][head_j] = 1;//都可以！
	return 0;
}

void draw(int map[SIZE][SIZE])
{
	int i, j;
	system("cls"); //清除屏幕
	for (i = 0; i <= SIZE; i++) //输出上边框
	{
		if (i == 0)
		{
			cout << "┏";
		}
		else if (i == SIZE)
		{
		cout<<" ━━ ┓";
		}
		else
		{
			std::cout<<" ━";
		}
	}
	cout << endl;
	
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j == 0) //输出左边框
			{
				cout<<"丨 ";
			}
			if (map[i][j] == 1) //输出蛇头
			{
				cout<<"○";
			}
			else if (map[i][j] > 1) //输出蛇身
			{
				cout<<"●";
			}
			else if (map[i][j] == -1) //输出食物
			{
				cout<<"★";
			}
			else
			{
				cout<<"  ";
			}
			if (j == SIZE - 1) //输出右边框
			{
				cout<<"丨";
			}
		}
		cout<<endl;
	}
	for (i = 0; i <= SIZE; i++) //输出下边框
	{
		if (i == 0)
		{
			cout << "┗";
		}
		else if (i == SIZE)
		{
			cout << " ━━ ┛";
		}/*
		else if (i == 2)
		{
			cout << "蛇";
		}
		else if (i == 3) {
			cout << "皮";
		}
		else if (i == 4) {
			cout << "走";
		}
		else if (i == 5) {
			cout << "位";
		}
		else if (i == 6) {
			cout << "模";
		}
		else if (i == 7) {
			cout << "拟";
		}
		else if (i == 8) {
			cout << "器";
		}*/
		else
			cout << " ━";
			
	}
	cout<<endl;
}