//============================================================================
// Name        : text.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "Person.h"
using namespace std;



int main(){
	Person p1("张三", 0, 18, 180.5, 65.3);//张三
	p1.print();
	cout << endl;
	Person p2("李四", 1, 16, 165, 46.5);//李四
	p2.print();
}

