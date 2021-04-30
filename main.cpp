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
	printf("\t\t  欢迎使用四则运算习题生成器\t\n");
}

void Set_parameter(void)
{
	printf("请设置题目数量，输入正整数（例如想生成十道题，则输入10）\n");
	cin >> questionnum;
	while (questionnum <= 0)
	{
		printf("请重新设置题目数量（输入正整数）\n");
		cin >> questionnum;
	}
	printf("请设置要使用的运算符种类数，运算符包括“+”，“-”，“*”，“/”(例如想使用+-，则输入2）\n");
	cin >> symbolnum;
	while ((symbolnum < 1) || (symbolnum > 4))
	{
		printf("请重新设置运算符种类数，种类数为1-4\n");
		cin >> symbolnum;
	}
	printf("请输入要使用的运算符（在“+”，“-”，“*”，“/”中选择输入，符号连续输入）\n");
	cin >> symboltype;
	printf("请设置最大数,请输入正整数（例如想控制在十以内，则输入10）\n");
	cin >> maxnum;
	while (maxnum <= 0)
	{
		printf("请重新设置最大数（输入正整数）\n");
		cin >> maxnum;
	}
	printf("请选择是否有小数（0表示没有小数，1表示有小数）\n");
	cin >> smallnumber_exist;
	printf("请选择是否有括号（0表示没有括号，1表示有括号）\n");
	cin >> bracket_exist;

	printf("请选择输出方式（0表示输出到屏幕，1表示输出到文件）\n");
	cin >> printstyle;
}

void Produce_random_number(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (smallnumber_exist == 0)
		{
			number[i] = rand() % (maxnum)+1;//rand()%M这个函数是随机产生0到M-1的随机数

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
	int bracket_place;  //括号位置
	FILE* fp = nullptr;//文件指针
	errno_t err = 0;
	err = fopen_s(&fp, "Text.txt", "w");
	int question_each;//每个题目有几个数字组成
	printf("请选择每个题目所包含的数字数量\n");
	cin >> question_each;
	for (int m = 0; m < questionnum; m++)
	{

		Produce_random_number(question_each);  //随机产生数字
		Produce_random_symbol(question_each - 1);  //随机产生符号
		if (smallnumber_exist == 0)  //算式中没有小数
		{
			if (printstyle == 0)//输出到屏幕
			{
				if (bracket_exist == 0)//算式中没有括号
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
				else//算式中有括号
				{
					bracket_place = rand() % 2;
					if (bracket_place == 0)//括号在第一个数和第二个数上
					{
						printf("\n（ %.0f %c %.0f ） %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
					if (bracket_place == 1)//括号在第二个数和第三个数上
					{
						printf("\n%.0f %c ( %.0f %c %.0f ) =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
				}
			}
			else //输出到文件
			{
				if (bracket_exist == 0)//算式中没有括号
				{
					fprintf(fp, "%.0f %c %.0f %c %.0f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
				}
			}
		}
		else//是小数
		{
			if (printstyle == 0)//输出到屏幕
			{
				if (bracket_exist == 0)//算式中没有括号
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
				else//算式中有括号
				{
					bracket_place = rand() % 2;
					if (bracket_place == 0)//括号在第一个数和第二个数上
					{
						printf("\n（%.2f %c %.2f ） %c %.2f %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
					if (bracket_place == 1)//括号在第二个数和第三个数上
					{
						printf("\n%.2f %c ( %.2f %c %.2f ) %c %.2f =\n", number[0], symbol[0], number[1], symbol[1], number[2]);
					}
				}
			}
			else
			{
				if (bracket_exist == 0)//算式中没有括号
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
	printf("\n\t\t使用结束\t\t");
}
int main()
{
	Menu_start();
	Set_parameter();
	srand((int)time(0));
	Print();
	Menu_end();
}