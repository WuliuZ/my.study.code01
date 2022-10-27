
#include<iostream>
using namespace std;
#define ElemType int

//************************单链表的存储结构********************
typedef struct LNode
{
	ElemType data;//结点的数据域
	struct LNode* next;//结点的指针域
}LNode, * LinkList;//LinkList为指向结构体LNode的指针类型

//***********************单链表的基本操作函数******************

//单链表的初始化
void InitList(LinkList& L)
{
	//构造一个空的单链表
	L = new LNode;
	L->next = NULL;
}
//单链表的创建
void CreateList_H(LinkList& L)//前插法创建单链表
{
	//创建一个长度为n的单链表L,逆序位插入
	int n;
	LNode* p;
	cout << "请输入创建的单链表长度：" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		p = new LNode;
		cout << "请输入插入的第" << i + 1 << "个数据值" << endl;
		cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}

//单链表的位置i插入
bool ListInsert(LinkList& L, int i, ElemType e)
{
	//在带头结点的单链表L的第i个结点前插入新结点
	LinkList p = L;
	LNode* s;
	int j = 0;
	while (p && j < i - 1)//p指向第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!p || i < 1)//i大于表长+1或小于1，插入位置不合法
	{
		return false;
	}
	s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//单链表位置i的删除
bool ListDelete(LinkList& L, int i, ElemType& e)
{
	//将单链表的第i个结点删除
	LinkList p = L;
	LNode* q;
	int j = 0;
	while (p->next && j < i - 1)//p指向第i-1个结点
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || i < 1)//i大于表长或小于1，删除位置不合法
	{
		return false;
	}
	q = p->next;//临时保存被删结点的地址以备释放
	p->next = q->next;
	e = q->data;//保存被删结点的数据
	delete q;//释放被删结点的空间
	return true;
}
//单链表按值查找
bool LocateElem(LinkList L, LNode*& p, ElemType e)
{
	//在单链表中查找第一个数据为e的结点
	p = L->next;//p指向首元结点
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
	int j;  // 用来找到 i位置的值
	if (i < 0) return NULL;
	p = L;
	j = 0;
	while ((p->next != NULL) && (j < i)) {
		p = p->next;
		j++;
	}
	if (i == j) {
		cout << "链表中第" << j << "个位置的值是" << p->data;
		return p;
	}
	else {
		return NULL;
	}
}

//*********************************单链表的基本功能函数******************************

//1、插入
void ListInsert(LinkList& L)
{

	ElemType e;
	int i;
	bool flag;
	cout << "请输入要插入的数据：" << endl;
	cin >> e;
	cout << "请输入要插入的位置：" << endl;
	cin >> i;
	flag = ListInsert(L, i, e);
	if (flag)
		cout << "插入成功!" << endl;
	else
		cout << "位置不对，插入失败！" << endl;
}

//2、删除
void ListDelete(LinkList& L)
{
	ElemType e;
	int i;
	bool flag;
	cout << "请输入要删除数据的位置：" << endl;
	cin >> i;
	flag = ListDelete(L, i, e);
	if (flag)
		cout << "删除成功，删除的数据为：" << e << endl;
	else
		cout << "位置不对，删除失败！" << endl;
}
//4、按值查找
void finde(LinkList L)
{
	ElemType e;
	LNode* p = NULL;
	bool flag;
	cout << "请输入要查找的数据：" << endl;
	cin >> e;
	flag = LocateElem(L, p, e);
	if (flag)
		cout << "查找成功，该数据的地址为：" << p << endl;
	else
		cout << "查找失败！" << endl;
}
//5、按位置查找
void findi(LinkList L)
{
	ElemType e;
	LNode* p = NULL;
	bool flag;
	cout << "请输入要查找的位置：" << endl;
	cin >> e;
	flag = serchIndex(L, p, e);
	if (flag)
		cout << "查找成功，该数据的地址为：" << p << endl;
	else
		cout << "查找失败！" << endl;
}

//6、判空
void ListEmpty(LinkList L)
{
	if (L->next)
		cout << "链表不为空！" << endl;
	else
		cout << "链表为空！" << endl;
}

//7、求长
void ListLength(LinkList L)
{
	LinkList p = L->next;//p指向第一个结点
	int i = 0;
	while (p)//遍历单链表，统计结点数
	{
		i++;
		p = p->next;
	}
	cout << "链表的长度为：" << i << endl;
}
//8、销毁
void DestroyList(LinkList& L)
{
	LNode* p;
	while (L)//从头结点开始依次删除
	{
		p = L;
		L = L->next;
		delete p;
	}
}

//9、遍历打印
void PrintList(LinkList L)
{
	LinkList p = L->next;//p指向第一个结点
	int i = 0;
	while (p)//遍历单链表
	{
		i++;
		cout << "链表第" << i << "个数据为：" << p->data << endl;
		p = p->next;
	}
}

//菜单
void menu()
{
	cout << "1、求长**2、按值查找**3、按位置查找**4、位置i插入**5、位置i删除**6、遍历打印**7、销毁**0、退出**" << endl;
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
		system("CLS");//清屏操作
		menu();
		cout << "请输入菜单序号：" << endl;
		cin >> select;
		switch (select)
		{
		case 1://求单链表的长度
			ListLength(L);
			system("pause");
			break;
		case 2://按值查找
			finde(L);
			system("pause");
			break;
		case 3://按位置查找
			findi(L);
			system("pause");
			break;
		case 4://位置i插入
			ListInsert(L);
			system("pause");//按任意键继续
			break;
		case 5://位置i删除
			ListDelete(L);
			system("pause");
			break;
		case 6://遍历打印
			PrintList(L);
			system("pause");
			break;
		case 7://销毁
			DestroyList(L);
			system("pause");
			return 0;
			break;
		default:
			cout << "菜单序号输入有误！" << endl;
			system("pause");
			break;
		}
	}
	system("pause");
	return 0;
}
