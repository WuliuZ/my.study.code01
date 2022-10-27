
#include<iostream>
using namespace std;
#define ElemType int

//************************������Ĵ洢�ṹ********************
typedef struct LNode
{
	ElemType data;//����������
	struct LNode* next;//����ָ����
}LNode, * LinkList;//LinkListΪָ��ṹ��LNode��ָ������

//***********************������Ļ�����������******************

//������ĳ�ʼ��
void InitList(LinkList& L)
{
	//����һ���յĵ�����
	L = new LNode;
	L->next = NULL;
}
//������Ĵ���
void CreateList_H(LinkList& L)//ǰ�巨����������
{
	//����һ������Ϊn�ĵ�����L,����λ����
	int n;
	LNode* p;
	cout << "�����봴���ĵ������ȣ�" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cout << "���������ĵ�" << i + 1 << "������ֵ" << endl;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//�������λ��i����
bool ListInsert(LinkList& L, int i, ElemType e)
{
	//�ڴ�ͷ���ĵ�����L�ĵ�i�����ǰ�����½��
	LinkList p = L;
	LNode* s;
	int j = 0;
	while (p && j < i - 1)//pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (!p || i < 1)//i���ڱ�+1��С��1������λ�ò��Ϸ�
	{
		return false;
	}
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//������λ��i��ɾ��
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	//��������ĵ�i�����ɾ��
	LinkList p = L;
	LNode* q;
	int j = 0;
	while (p->next && j < i - 1)//pָ���i-1�����
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1)//i���ڱ���С��1��ɾ��λ�ò��Ϸ�
	{
		return false;
	}
	q = p->next;//��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ�
	p->next = q->next;
	e = q->data;//���汻ɾ��������
	delete q;//�ͷű�ɾ���Ŀռ�
	return true;
}
//������ֵ����
bool LocateElem(LinkList L, LNode*& p, ElemType e)
{
	//�ڵ������в��ҵ�һ������Ϊe�Ľ��
	p = L->next;//pָ����Ԫ���
	while (p && p->data != e)
	{
		p = p->next;
	}
	if (p)
	{
		return true;
	}
	return false;
}
void* serchIndex(LinkList L, LNode*& p, int i) {
	int j;  // �����ҵ� iλ�õ�ֵ
	if (i < 0) return NULL;
	p = L;
	j = 0;
	while ((p->next != NULL) && (j < i)) {
		p = p->next;
		j++;
	}
	if (i == j) {
		cout << "�����е�" << j << "��λ�õ�ֵ��" << p->data;
		return p;
	}
	else {
		return NULL;
	}
}

//*********************************������Ļ������ܺ���******************************

//1������
void ListInsert(LinkList& L)
{

	ElemType e;
	int i;
	bool flag;
	cout << "������Ҫ��������ݣ�" << endl;
	cin >> e;
	cout << "������Ҫ�����λ�ã�" << endl;
	cin >> i;
	flag = ListInsert(L, i, e);
	if (flag)
		cout << "����ɹ�!" << endl;
	else
		cout << "λ�ò��ԣ�����ʧ�ܣ�" << endl;
}

//2��ɾ��
void ListDelete(LinkList& L)
{
	ElemType e;
	int i;
	bool flag;
	cout << "������Ҫɾ�����ݵ�λ�ã�" << endl;
	cin >> i;
	flag = ListDelete(L, i, e);
	if (flag)
		cout << "ɾ���ɹ���ɾ��������Ϊ��" << e << endl;
	else
		cout << "λ�ò��ԣ�ɾ��ʧ�ܣ�" << endl;
}
//4����ֵ����
void finde(LinkList L)
{
	ElemType e;
	LNode* p = NULL;
	bool flag;
	cout << "������Ҫ���ҵ����ݣ�" << endl;
	cin >> e;
	flag = LocateElem(L, p, e);
	if (flag)
		cout << "���ҳɹ��������ݵĵ�ַΪ��" << p << endl;
	else
		cout << "����ʧ�ܣ�" << endl;
}
//5����λ�ò���
void findi(LinkList L)
{
	ElemType e;
	LNode* p = NULL;
	bool flag;
	cout << "������Ҫ���ҵ�λ�ã�" << endl;
	cin >> e;
	flag = serchIndex(L, p, e);
	if (flag)
		cout << "���ҳɹ��������ݵĵ�ַΪ��" << p << endl;
	else
		cout << "����ʧ�ܣ�" << endl;
}

//6���п�
void ListEmpty(LinkList L)
{
	if (L->next)
		cout << "����Ϊ�գ�" << endl;
	else
		cout << "����Ϊ�գ�" << endl;
}

//7����
void ListLength(LinkList L)
{
	LinkList p = L->next;//pָ���һ�����
	int i = 0;
	while (p)//����������ͳ�ƽ����
	{
		i++;
		p = p->next;
	}
	cout << "����ĳ���Ϊ��" << i << endl;
}
//8������
void DestroyList(LinkList& L)
{
	LNode* p;
	while (L)//��ͷ��㿪ʼ����ɾ��
	{
		p = L;
		L = L->next;
		delete p;
	}
}

//9��������ӡ
void PrintList(LinkList L)
{
	LinkList p = L->next;//pָ���һ�����
	int i = 0;
	while (p)//����������
	{
		i++;
		cout << "�����" << i << "������Ϊ��" << p->data << endl;
		p = p->next;
	}
}

//�˵�
void menu()
{
	cout << "1����**2����ֵ����**3����λ�ò���**4��λ��i����**5��λ��iɾ��**6��������ӡ**7������**0���˳�**" << endl;
}

int main()
{
	LinkList L;
	InitList(L);
	int select;
	CreateList_H(L);
	ListEmpty(L);
	while (1)
	{
		system("CLS");//��������
		menu();
		cout << "������˵���ţ�" << endl;
		cin >> select;
		switch (select)
		{
		case 1://������ĳ���
			ListLength(L);
			system("pause");
			break;
		case 2://��ֵ����
			finde(L);
			system("pause");
			break;
		case 3://��λ�ò���
			findi(L);
			system("pause");
			break;
		case 4://λ��i����
			ListInsert(L);
			system("pause");//�����������
			break;
		case 5://λ��iɾ��
			ListDelete(L);
			system("pause");
			break;
		case 6://������ӡ
			PrintList(L);
			system("pause");
			break;
		case 7://����
			DestroyList(L);
			system("pause");
			return 0;
			break;
		default:
			cout << "�˵������������" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}
