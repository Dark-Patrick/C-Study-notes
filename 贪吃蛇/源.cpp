#include<stdio.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#define SIZE 25 //�����ͼ��С
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
	int command, result, length = 0; //length��ʾ�ߵĳ���
	init(command, length, map); //��ʼ����Ϸ
	while (1)
	{
		command = getCommand(command); //��ȡ������������
		result = move(command, &length, map); //���������ƶ���
		if (result == 1) //�����ƶ��Ľ��
		{
			break;
		}
		else
		{
			draw(map); //���߻�������̨
		}
		Sleep(200);
	}
	cout << "you lose!" << '\n' << '\n';
	system("pause");
}


void init(int& command, int& length, int map[SIZE][SIZE])
{
	//��ʼ����ʼ����
	command = 2; //��ʼ��������
	//��ʼ���ߵĳ���
	length = 3;
	//��ʼ���ߵ�λ��
	map[2][1] = 1;
	map[1][1] = 2;
	map[0][1] = 3;
	//��ʼ��ʳ���λ��
	map[3][3] = -1;
}

int getCommand(int command)
{
	int temp = -1;
	if (_kbhit()) //����м�������
	{
		switch (_getch())
		{
		case 'A': case 'a': temp = 3; break; //��ʾ����
		case 'S': case 's': temp = 2; break; //��ʾ����
		case 'D': case 'd': temp = 1; break; //��ʾ����
		case 'W': case 'w': temp = 0; break; //��ʾ����
		case' ':system("pause"); 
			break;//��ͣ��Ϸ
		case'q':case'Q':
			cout << "��Ϸ����" << endl;
			system("pause");
			exit(0);
			break;
		}
		if (temp != -1 && abs(command - temp) != 2) //�߲��ܷ���
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
			if (map[i][j] == *length) //������ߵ����һ������
			{
				map[i][j] = 0;
			}
			else if (map[i][j] > 1) //��������м�ڵ�����
			{
				map[i][j] += 1;
			}
			else if (map[i][j] == 1) //�������ͷ
			{
				map[i][j] += 1;
				//ȷ����ͷ�µ�λ��head_i��head_j
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
	if (map[head_i][head_j] == -1) //����Ե���ʳ��
	{
		map[head_i][head_j] = 1;
		*length = *length + 1; //�ߵĳ��ȼ�һ
		//��������ʳ��
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
	//���ײ�����Լ�����ײ����ǽ
	else if (map[head_i][head_j] >0 || head_i < 0 || head_i == SIZE || head_j < 0 || head_j == SIZE)
	{
		return 1;
	}
	/*else
	{
		map[head_i][head_j] = 1;
	}*/
	map[head_i][head_j] = 1;//�����ԣ�
	return 0;
}

void draw(int map[SIZE][SIZE])
{
	int i, j;
	system("cls"); //�����Ļ
	for (i = 0; i <= SIZE; i++) //����ϱ߿�
	{
		if (i == 0)
		{
			cout << "��";
		}
		else if (i == SIZE)
		{
		cout<<" ���� ��";
		}
		else
		{
			std::cout<<" ��";
		}
	}
	cout << endl;
	
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (j == 0) //�����߿�
			{
				cout<<"ح ";
			}
			if (map[i][j] == 1) //�����ͷ
			{
				cout<<"��";
			}
			else if (map[i][j] > 1) //�������
			{
				cout<<"��";
			}
			else if (map[i][j] == -1) //���ʳ��
			{
				cout<<"��";
			}
			else
			{
				cout<<"  ";
			}
			if (j == SIZE - 1) //����ұ߿�
			{
				cout<<"ح";
			}
		}
		cout<<endl;
	}
	for (i = 0; i <= SIZE; i++) //����±߿�
	{
		if (i == 0)
		{
			cout << "��";
		}
		else if (i == SIZE)
		{
			cout << " ���� ��";
		}/*
		else if (i == 2)
		{
			cout << "��";
		}
		else if (i == 3) {
			cout << "Ƥ";
		}
		else if (i == 4) {
			cout << "��";
		}
		else if (i == 5) {
			cout << "λ";
		}
		else if (i == 6) {
			cout << "ģ";
		}
		else if (i == 7) {
			cout << "��";
		}
		else if (i == 8) {
			cout << "��";
		}*/
		else
			cout << " ��";
			
	}
	cout<<endl;
}