/***********************************************************************
 * Module:  Person.h
 * Author:  ��������
 * Modified: 2022��10��27�� 10:39:45
 * Purpose: Declaration of the class Person
 ***********************************************************************/

#if !defined(__ObjectOrientedModel_1_Person_h)
#define __ObjectOrientedModel_1_Person_h

class Person
{
public:
   Person(char nameV[], bool sexV, int ageV, float heightV, float weightV);
   ~Person();
   Person(const Person& oldPerson);
   void eat(char obj[]);
   void sleep(void);
   int print(void);

protected:
private:
   char name[20];
   bool sex;
   int age;
   float weight;
   double height;


};

#endif