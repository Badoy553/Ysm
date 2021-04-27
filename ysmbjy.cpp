#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

//出生的
class Birthday
{
private:
	int year, mon, day;
public:
	Birthday() :year(0), mon(0), day(0) {}
	Birthday(int y, int m, int d)
	{
		year = y;
		mon = m;
		day = d;
	}

};

//老师的属性
class Teacher
{
private:
	char name[20];
	int salary;
public:
	Teacher()
	{
		strcpy(name, "wumingshi");
		salary = 5000;
	}
	void pTeacher(char nam[10], int sa)
	{
		salary = sa;
		strcpy(name, nam);
	}
	int  getSalary()
	{
		return salary;
	}
	string getname()
	{
		return name;
	}
	void show()
	{
		printf("%s %d\n", name, salary);
	}
};

//教授
class Professor :Teacher
{
private:
	Birthday birh;
	int typeNum;
	int *revenue;
public:

	Professor(char na[20], int sal, Birthday bt, int *rev, int nu)
	{
		pTeacher(na, sal);
		birh = bt;
		revenue = rev;
		typeNum = nu;
	}
	void getTotal()
	{
		int zh = 0;
		for (int i = 0; i < typeNum; i++)
			zh = zh + revenue[i];
		zh = zh + Teacher::getSalary();
		printf("%d", zh);
	}
	void show()
	{
		cout << Teacher::getname() << " " << Teacher::getSalary() << endl;
	}

};

int main()
{
	char name[20];
	int salary;
	Teacher t1;
	cin >> name >> salary;
	Teacher t2;
	t2.pTeacher(name, salary);
	int year, month, day, num, *revenue;
	cin >> name >> salary >> year >> month >> day >> num;
	Birthday b(year, month, day);
	revenue = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> revenue[i];
	}
	Professor p1(name, salary, b, revenue, num);

	t1.show();

	t2.show();

	p1.show();

	p1.getTotal();

	system("pause");
	return 1;
}