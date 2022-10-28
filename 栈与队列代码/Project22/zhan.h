#pragma once
#include <iostream>
using namespace std;

struct Zhan {
	int* top;  //栈顶指针
	int* base; //栈底指针
	int stacksize; //栈可用的最大容量
};

bool Pankong(Zhan& S) {
	return S.top == S.base;
}
//判空 0为F 1为T


int InitStack(Zhan& S, int MAXSIZE) {
	S.base = new  int(MAXSIZE);  //为顺序栈动态划分存储空间
	if (!S.base) {
		cout << "分配内存失败！";
	}
	S.top = S.base;	//top初始化为base
	S.stacksize = MAXSIZE;
	return 0;
}
//顺序栈初始化


int Push(Zhan& S, int e) {
	if (S.top - S.base == S.stacksize) {
		return 0;		//判断栈满
	}
	*S.top++ = e;
	return 0;
}
//入栈


int Pop(Zhan& S, int e) {
	if (Pankong(S)) { cout << "栈为空"; };
	e = *--S.top;
	return 0;
}
//出栈


void ElZhan(Zhan& S) {
	int* a = S.top - 1;
	cout << "从上到下依次为：";
	while (a >= S.base) {
		cout << *a << "  ";
		a--;
	}

}
//遍历


int Length(Zhan& S) {
	if (Pankong(S)) { cout << "空！"; }
	cout << S.top - S.base;
	return 0;
}
//求长


int Clear(Zhan& S) {
	S.top = S.base;
	return 0;
}
//清空


void Destroy(Zhan& S) {
	free(S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//销毁