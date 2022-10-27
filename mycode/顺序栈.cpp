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


int InitStack(Zhan &S,int MAXSIZE) { 
	S.base = new  int(MAXSIZE);  //Ϊ˳��ջ��̬���ִ洢�ռ�
	if (!S.base) {
		cout << "�����ڴ�ʧ�ܣ�";
	}
	S.top = S.base;	//top��ʼ��Ϊbase
	S.stacksize = MAXSIZE;
	return 0;
}
//˳��ջ��ʼ��


int Push(Zhan &S,int e) {
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


void ElZhan(Zhan &S) {
	int* a = S.top-1;
	cout << "���ϵ�������Ϊ��";
	while (a>=S.base) {
		cout << *a<<"  ";
		a--;
	}

}
//����


int Length(Zhan&S){
	if (Pankong(S)) { cout << "�գ�"; }
	cout<< S.top - S.base;
	return 0;
}
//��


int Clear(Zhan&S) {
	S.top = S.base;
	return 0;
}
//���


void Destroy(Zhan&S) {
	free (S.base);
	S.top = NULL;
	S.base = NULL;
	S.stacksize = 0;
}
//����

void menu()
{
	cout << "1����ջ  2����ջ  3������  4����  5�����  6������  0���˳�**" << endl;
}
//�˵�



int main() {
	int maxsize,Number;
	Zhan a;
	
	cout << "������˳��ջ�����ռ䣺";
	cin >> maxsize;		//�û�����
	InitStack(a, maxsize);

	int select;
	int data;
	int flag = 1;
	while (flag)
	{
		system("CLS");//��������
		menu();
		cout << "������˵���ţ�" << endl;
		cin >> select;
		switch (select)
		{
		case 0:
			flag = 0;
			break;

		case 1://��ջ
			cout << "����������Ҫ�洢���ݵ���Ŀ��";
			cin >> Number;
			for (int i = 0;i < Number;i++) {
				cout << "����������Ҫ�洢�ĵ�" << i + 1 << "�����ݣ�";
				cin >> data;
				Push(a, data);
			}
			system("pause");//�����������
			break;
		case 2://��ջ
			Pop(a, data);
			system("pause");
			break;
		case 3://����
			ElZhan(a);
			system("pause");
			break;
		case 4://��
			Length(a);
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
		default:
			cout << "�˵������������" << endl;
			system("pause");
			break;
		}
	}
	
	




	return 0;
}
