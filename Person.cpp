/***********************************************************************
 * Module:  Person.cpp
 * Author:  ��������
 * Modified: 2022��10��27�� 10:39:45
 * Purpose: Implementation of the class Person
 ***********************************************************************/

#include <iostream>
#include <string.h>
#include "Person.h"
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Person::Person(char nameV[], bool sexV, int ageV, float heightV, float weightV)
// Purpose:    Implementation of Person::Person()
// Parameters:
// - nameV[]
// - sexV
// - ageV
// - heightV
// - weightV
// Return:     
////////////////////////////////////////////////////////////////////////

Person::Person(char nameV[], bool sexV, int ageV, float heightV, float weightV)
{
	cout << "我知道怎么设置人的属性，我已完成！" << endl;
		strncpy_s(name, nameV, sizeof(name)); //姓名
		sex = sexV; //性别
		age = ageV; //年龄
		height = heightV; //身高
		weight = weightV; //体重
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::~Person()
// Purpose:    Implementation of Person::~Person()
// Return:     
////////////////////////////////////////////////////////////////////////

Person::~Person()
{
	cout << "析构：" << name << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::Person(const Person& oldPerson)
// Purpose:    Implementation of Person::Person()
// Parameters:
// - oldPerson
// Return:     
////////////////////////////////////////////////////////////////////////

Person::Person(const Person& oldPerson)
{
   name[20] = oldPerson.name[20];
   sex = oldPerson.sex;
   age = oldPerson.age;
   weight = oldPerson.weight;
   height = oldPerson.height;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::eat(char obj[])
// Purpose:    Implementation of Person::eat()
// Parameters:
// - obj[]
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::eat(char obj[])
{
	cout << "我是一个人" << name << "，但我还没有学会怎么吃。" << obj << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::sleep()
// Purpose:    Implementation of Person::sleep()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Person::sleep(void)
{
	cout << "我是一个人" << name << "，我会睡觉，但还说不清楚是怎么睡觉的。" << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Person::print()
// Purpose:    Implementation of Person::print()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Person::print(void)
{
	cout << "我是一个人，我的属性值为：" << name << "," << sex << "," << age << "," << height
				<< endl;
}
