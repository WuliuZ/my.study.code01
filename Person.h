/***********************************************************************
 * Module:  Person.h
 * Author:  热心网友
 * Modified: 2022年10月27日 10:39:45
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