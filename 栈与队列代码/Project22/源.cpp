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
	cout << "������˵���ţ�" ;
	cin >> select;
	A:switch (select)
	{
	case 1:			//ѡ��ջ����
		cout << "������˳��ջ�����ռ䣺";
		cin >> maxsize;		//�û�����
		InitStack(b, maxsize);
		while (1) {
			system("CLS");//��������
			menuZ();
			cout << "������˵���ţ�" << endl;
			cin >> select;
			switch (select)
			{

			case 1://��ջ
				
				cout << "����������Ҫ�洢���ݵ���Ŀ��";
				cin >> Number;
				for (int i = 0;i < Number;i++) {
					cout << "����������Ҫ�洢�ĵ�" << i + 1 << "�����ݣ�";
					cin >> data;
					Push(b, data);
				}
				system("pause");//�����������
				break;
			case 2://��ջ
				Pop(b, data);
				system("pause");
				break;
			case 3://����
				ElZhan(b);
				system("pause");
				break;
			case 4://��
				Length(b);
				system("pause");
				break;
			case 5://���
				Clear(b);
				system("pause");
				break;
			case 6://����
				Destroy(b);
				system("pause");
				return 0;
				break;
			case 0:
				menu1();
				cin >> select;
				goto A;
			default:
				cout << "�˵������������" << endl;
				system("pause");
				break;
			}
		}
		
		break;
	case 2:
		cout << "����������Ҫ�Ķ��д�С��";
		cin >> size;
		InitSQueue(a, size);
		while (2) {
				system("CLS");//��������
				menuD();
				cout << "������˵���ţ�" << endl;
				cin >> select;
				switch (select)
				{
				case 1://���
					for (int i = 0;i < size;i++) {
						cout << "����������Ҫ�洢�ĵ�" << i + 1 << "�����ݣ�";
						cin >> data;
						Enter(a, data);
					}
					system("pause");//�����������
					break;
				case 2://����
					for (int i = 0;i < size;i++) {
						cout << "����������Ҫȡ���ĵ�" << i + 1 << "�����ݣ�";
						cin >> data;
						Out(a, data);
					}
					cout << endl;
					system("pause");
					break;
				case 3://����
					RunSQ(a);
					system("pause");
					break;
				case 4://��
					cout << "����Ϊ��" << -Length(a) << endl;
					system("pause");
					break;
				case 5://���
					Clear(a);
					system("pause");
					break;
				case 6://����
					Destroy(a);
					system("pause");
					return 0;
					break;
				case 7://ȡͷԪ��
					cout << "ȡ��Ԫ��Ϊ��" << Top(a) << endl;
					system("pause");
					return 0;
					break;
				case 0:
					menu1();
					cin >> select;
					goto A;
				default:
					cout << "�˵������������" << endl;
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
