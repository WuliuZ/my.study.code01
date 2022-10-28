#pragma once
#include <iostream>
using namespace std;

struct SQueue {
	int front;		//����Ԫ��
	int rear;	//β��Ԫ��
	int* base;//�洢��ַ

};
//���нṹ����

int InitSQueue(SQueue& S, int size) {
	S.base = new int[size];				//��̬����ռ䲢�����ַ
	if (!S.base) { cout << "�����ڴ�ʧ��"; }		//�ж��Ƿ����ɹ�
	S.front = 0;
	S.rear = 0;
	return 0;
}
//��ʼ��ѭ������

bool Empty(SQueue& S) {
	return S.front == S.rear;
}
//�п�

int Enter(SQueue& S, int e) {

	S.base[S.rear] = e;
	S.rear++;
	cout << "��ӳɹ���";
	return 0;
}
//���

int Out(SQueue& S, int e) {
	if (Empty(S)) { cout << "�ѿ�"; }
	e = S.base[S.front];		//����ͷԪ��
	S.front++;
	cout << e << "�ѳɹ�����";		//���ͷԪ��
	return 0;
}
//����

void RunSQ(SQueue& S) {
	if (Empty(S)) { cout << "����Ϊ��"; }
	int a = S.front;
	while (a <= (S.rear - 1)) {
		cout << S.base[a] << ",";
		a++;
	}
}
//����


int Length(SQueue& S) {
	if (Empty(S)) { cout << "����Ϊ0��"; }		//�п�
	return S.front - S.rear;
}
//��

void Clear(SQueue& S)
{
	S.rear = S.front;
	cout << "��ճɹ�" << endl;
}
//��ն���

void Destroy(SQueue& S)
{
	free(S.base);
	S.front = S.rear = 0;
	cout << "���ٳɹ�" << endl;
}
//���ٶ���

int Top(SQueue& S) {
	if (!Empty(S)) {
		return S.base[S.front];
	}
	return 0;
	//�ж϶��зǿգ�����ͷԪ��
}
//ȡͷԪ��