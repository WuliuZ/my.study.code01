#pragma once
#include <iostream>
using namespace std;

struct Zhan {
	int* top;  //ջ��ָ��
	int* base; //ջ��ָ��
	int stacksize; //ջ���õ��������
};

bool Pankong(Zhan& S) {
	return S.top == S.base;
}
//�п� 0ΪF 1ΪT


int InitStack(Zhan& S, int MAXSIZE) {
	S.base = new  int(MAXSIZE);  //Ϊ˳��ջ��̬���ִ洢�ռ�
	if (!S.base) {
		cout << "�����ڴ�ʧ�ܣ�";
	}
	S.top = S.base;	//top��ʼ��Ϊbase
	S.stacksize = MAXSIZE;
	return 0;
}
//˳��ջ��ʼ��


int Push(Zhan& S, int e) {
	if (S.top - S.base == S.stacksize) {
		return 0;		//�ж�ջ��
	}
	*S.top++ = e;
	return 0;
}
//��ջ


int Pop(Zhan& S, int e) {
	if (Pankong(S)) { cout << "ջΪ��"; };
	e = *--S.top;
	return 0;
}
//��ջ


void ElZhan(Zhan& S) {
	int* a = S.top - 1;
	cout << "���ϵ�������Ϊ��";
	while (a >= S.base) {
		cout << *a << "  ";
		a--;
	}

}
//����


int Length(Zhan& S) {
	if (Pankong(S)) { cout << "�գ�"; }
	cout << S.top - S.base;
	return 0;
}
//��


int Clear(Zhan& S) {
	S.top = S.base;
	return 0;
}
//���


void Destroy(Zhan& S) {
	free(S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//����