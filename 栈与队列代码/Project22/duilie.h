#pragma once
#include <iostream>
using namespace std;

struct SQueue {
	int front;		//顶部元素
	int rear;	//尾部元素
	int* base;//存储地址

};
//队列结构定义

int InitSQueue(SQueue& S, int size) {
	S.base = new int[size];				//动态分配空间并赋予地址
	if (!S.base) { cout << "分配内存失败"; }		//判断是否分配成功
	S.front = 0;
	S.rear = 0;
	return 0;
}
//初始化循环队列

bool Empty(SQueue& S) {
	return S.front == S.rear;
}
//判空

int Enter(SQueue& S, int e) {

	S.base[S.rear] = e;
	S.rear++;
	cout << "入队成功！";
	return 0;
}
//入队

int Out(SQueue& S, int e) {
	if (Empty(S)) { cout << "已空"; }
	e = S.base[S.front];		//保存头元素
	S.front++;
	cout << e << "已成功出列";		//输出头元素
	return 0;
}
//出队

void RunSQ(SQueue& S) {
	if (Empty(S)) { cout << "队列为空"; }
	int a = S.front;
	while (a <= (S.rear - 1)) {
		cout << S.base[a] << ",";
		a++;
	}
}
//遍历


int Length(SQueue& S) {
	if (Empty(S)) { cout << "长度为0！"; }		//判空
	return S.front - S.rear;
}
//求长

void Clear(SQueue& S)
{
	S.rear = S.front;
	cout << "清空成功" << endl;
}
//清空队列

void Destroy(SQueue& S)
{
	free(S.base);
	S.front = S.rear = 0;
	cout << "销毁成功" << endl;
}
//销毁队列

int Top(SQueue& S) {
	if (!Empty(S)) {
		return S.base[S.front];
	}
	return 0;
	//判断队列非空，返回头元素
}
//取头元素