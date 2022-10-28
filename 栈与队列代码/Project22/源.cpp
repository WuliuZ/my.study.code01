#include <iostream>
#include<cstdlib>
#include "duilie.h"
#include "zhan.h"
#include "caidan.h"
using namespace std;

int main() {
	SQueue a;
	Zhan b;
	int select, Number,data,maxsize,size, enda,type;
	menu1();
	cout << "请输入菜单序号：" ;
	cin >> select;
	A:switch (select)
	{
	case 1:			//选择栈操作
		cout << "请输入顺序栈的最大空间：";
		cin >> maxsize;		//用户输入
		InitStack(b, maxsize);
		while (1) {
			system("CLS");//清屏操作
			menuZ();
			cout << "请输入菜单序号：" << endl;
			cin >> select;
			switch (select)
			{

			case 1://入栈
				
				cout << "请输入您需要存储数据的数目：";
				cin >> Number;
				for (int i = 0;i < Number;i++) {
					cout << "请输入您需要存储的第" << i + 1 << "个数据：";
					cin >> data;
					Push(b, data);
				}
				system("pause");//按任意键继续
				break;
			case 2://出栈
				Pop(b, data);
				system("pause");
				break;
			case 3://遍历
				ElZhan(b);
				system("pause");
				break;
			case 4://求长
				Length(b);
				system("pause");
				break;
			case 5://清空
				Clear(b);
				system("pause");
				break;
			case 6://销毁
				Destroy(b);
				system("pause");
				return 0;
				break;
			case 0:
				menu1();
				cin >> select;
				goto A;
			default:
				cout << "菜单序号输入有误！" << endl;
				system("pause");
				break;
			}
		}
		
		break;
	case 2:
		cout << "请输入您需要的队列大小：";
		cin >> size;
		InitSQueue(a, size);
		while (2) {
				system("CLS");//清屏操作
				menuD();
				cout << "请输入菜单序号：" << endl;
				cin >> select;
				switch (select)
				{
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
					cout << "长度为：" << -Length(a) << endl;
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
					cout << "取出元素为：" << Top(a) << endl;
					system("pause");
					return 0;
					break;
				case 0:
					menu1();
					cin >> select;
					goto A;
				default:
					cout << "菜单序号输入有误！" << endl;
					system("pause");
					break;
				}
				
		}
		
		break;
	default:
		break;
	}





	return 0;
}
