#include <iostream>
using namespace std;

struct SQueue {
	int front;		//顶部元素
	int rear;	//尾部元素
	int* base;//存储地址
	
};
//队列结构定义

int InitSQueue(SQueue& S,int size) {
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


void menu()
{
	cout << "1、入队  2、出队  3、遍历  4、求长  5、清空  6、销毁 7、取头元素  0、退出" << endl;
}
//菜单

int main() {
	SQueue a;
	int size;
	cout << "请输入您需要的队列大小：";
	cin >> size;
	InitSQueue(a, size);
	int select; //菜单选项
	int data;//入队元素
	int flag = 1;//用于弹出
	while (flag)
	{
		system("CLS");//清屏操作
		menu();
		cout << "请输入菜单序号：" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			flag = 0;
			break;

		case 1://入队
			for (int i = 0;i < size;i++) {
				cout << "请输入您需要存储的第" << i + 1 << "个数据：";
				cin >> data;
				Enter(a, data);
			}
			system("pause");//按任意键继续
			break;
		case 2://出队
			for (int i = 0;i < size;i++) {
				cout << "请输入您需要取出的第" << i + 1 << "个数据：";
				cin >> data;
				Out(a, data);
			}
			cout << endl;
			system("pause");
			break;
		case 3://遍历
			RunSQ(a);
			system("pause");
			break;
		case 4://求长
			cout <<"长度为："<< -Length(a)<<endl;
			system("pause");
			break;
		case 5://清空
			Clear(a);
			system("pause");
			break;
		case 6://销毁
			Destroy(a);
			system("pause");
			return 0;
			break;
		case 7://取头元素
			cout<<"取出元素为："<<Top(a)<<endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "菜单序号输入有误！" << endl;
			system("pause");
			break;
		}
	}






	return 0;
}