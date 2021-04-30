#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;

int questionnum = 1;
int symbolnum = 1;
char symboltype[4] = { 0 };
int maxnum = 1;
int bracket_exist = 0;
int smallnumber_exist = 0;
int printstyle = 0;
float number[3] = { 0 };
char symbol[4] = { 0 };

void Menu_start()
{
	printf("\t\t  ��ӭʹ����������ϰ��������\t\n");
}

void Set_parameter(void)
{
	printf("��������Ŀ����������������������������ʮ���⣬������10��\n");
	cin >> questionnum;
	while (questionnum <= 0)
	{
		printf("������������Ŀ������������������\n");
		cin >> questionnum;
	}
	printf("������Ҫʹ�õ�������������������������+������-������*������/��(������ʹ��+-��������2��\n");
	cin >> symbolnum;
	while ((symbolnum < 1) || (symbolnum > 4))
	{
		printf("�����������������������������Ϊ1-4\n");
		cin >> symbolnum;
	}
	printf("������Ҫʹ�õ���������ڡ�+������-������*������/����ѡ�����룬�����������룩\n");
	cin >> symboltype;
	printf("�����������,�������������������������ʮ���ڣ�������10��\n");
	cin >> maxnum;
	while (maxnum <= 0)
	{
		printf("�����������������������������\n");
		cin >> maxnum;
	}
	printf("��ѡ���Ƿ���С����0��ʾû��С����1��ʾ��С����\n");
	cin >> smallnumber_exist;
	printf("��ѡ���Ƿ������ţ�0��ʾû�����ţ�1��ʾ�����ţ�\n");
	cin >> bracket_exist;

	printf("��ѡ�������ʽ��0��ʾ�������Ļ��1��ʾ������ļ���\n");
	cin >> printstyle;
}

void Produce_random_number(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (smallnumber_exist == 0)
		{
			number[i] = rand() % (maxnum)+1;//rand()%M����������������0��M-1�������

		}
		else
		{
			number[i] = rand() % maxnum;
			number[i] = number[i] + rand() % 100 * 0.01;
		}
	}
}

void Produce_random_symbol(int n)
{
	for (int i = 0; i < n; i++)
	{
		symbol[i] = symboltype[rand() % symbolnum];
	}
}

void Print(void)
{
	int bracket_place;  //����λ��
	FILE* fp = nullptr;//�ļ�ָ��
	errno_t err = 0;
	err = fopen_s(&fp, "Text.txt", "w");
	int question_each;//ÿ����Ŀ�м����������
	printf("��ѡ��ÿ����Ŀ����������������\n");
	cin >> question_each;
	for (int m = 0; m < questionnum; m++)
	{

		Produce_random_number(question_each);  //�����������
		Produce_random_symbol(question_each - 1);  //�����������
		if (smallnumber_exist == 0)  //��ʽ��û��С��
		{
			if (printstyle == 0)//�������Ļ
			{
				if (bracket_exist == 0)//��ʽ��û������
				{
					printf("\n");
					for (int i = 0; i < question_each - 1; i++)
					{
						printf(" %.0f %c ", number[i], symbol[i]);
					}
					printf("%.0f =", number[question_each - 1]);
					printf("\n");
					//printf("\n%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
				}
				else//��ʽ��������
				{
					bracket_place = rand() % 2;
					if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
					{
						printf("\n�� %.0f %c %.0f �� %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
					if (bracket_place == 1)//�����ڵڶ������͵���������
					{
						printf("\n%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
				}
			}
			else //������ļ�
			{
				if (bracket_exist == 0)//��ʽ��û������
				{
					fprintf(fp, "%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
				}
			}
		}
		else//��С��
		{
			if (printstyle == 0)//�������Ļ
			{
				if (bracket_exist == 0)//��ʽ��û������
				{
					printf("\n");
					for (int i = 0; i < question_each - 1; i++)
					{
						printf(" %.2f %c ", number[i], symbol[i]);
					}
					printf("%.2f =", number[question_each - 1]);
					printf("\n");
					//printf("\n%.2f %c %.2f %c %.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2]);
				}
				else//��ʽ��������
				{
					bracket_place = rand() % 2;
					if (bracket_place == 0)//�����ڵ�һ�����͵ڶ�������
					{
						printf("\n��%.2f %c %.2f �� %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
					if (bracket_place == 1)//�����ڵڶ������͵���������
					{
						printf("\n%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
				}
			}
			else
			{
				if (bracket_exist == 0)//��ʽ��û������
				{
					fprintf(fp, "%.2f %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
				}
			}

		}
	}
	fclose(fp);
}
void Menu_end()
{
	printf("\n\t\tʹ�ý���\t\t");
}
int main()
{
	Menu_start();
	Set_parameter();
	srand((int)time(0));
	Print();
	Menu_end();
}