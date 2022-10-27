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


int InitStack(Zhan &S,int MAXSIZE) { 
	S.base = new  int(MAXSIZE);  //为顺序栈动态划分存储空间
	if (!S.base) {
		cout << "分配内存失败！";
	}
	S.top = S.base;	//top初始化为base
	S.stacksize = MAXSIZE;
	return 0;
}
//顺序栈初始化


int Push(Zhan &S,int e) {
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


void ElZhan(Zhan &S) {
	int* a = S.top-1;
	cout << "从上到下依次为：";
	while (a>=S.base) {
		cout << *a<<"  ";
		a--;
	}

}
//遍历


int Length(Zhan&S){
	if (Pankong(S)) { cout << "空！"; }
	cout<< S.top - S.base;
	return 0;
}
//求长


int Clear(Zhan&S) {
	S.top = S.base;
	return 0;
}
//清空


void Destroy(Zhan&S) {
	free (S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//销毁

void menu()
{
	cout << "1、入栈  2、出栈  3、遍历  4、求长  5、清空  6、销毁  0、退出**" << endl;
}
//菜单



int main() {
	int maxsize,Number;
	Zhan a;
	
	cout << "请输入顺序栈的最大空间：";
	cin >> maxsize;		//用户输入
	InitStack(a, maxsize);

	int select;
	int data;
	int flag = 1;
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

		case 1://入栈
			cout << "请输入您需要存储数据的数目：";
			cin >> Number;
			for (int i = 0;i < Number;i++) {
				cout << "请输入您需要存储的第" << i + 1 << "个数据：";
				cin >> data;
				Push(a, data);
			}
			system("pause");//按任意键继续
			break;
		case 2://出栈
			Pop(a, data);
			system("pause");
			break;
		case 3://遍历
			ElZhan(a);
			system("pause");
			break;
		case 4://求长
			Length(a);
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
		default:
			cout << "菜单序号输入有误！" << endl;
			system("pause");
			break;
		}
	}
	
	




	return 0;
}
