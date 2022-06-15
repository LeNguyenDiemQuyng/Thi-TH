#include <iostream>
#include <string>
using namespace std;

struct key
{
	int MSSV;
	string ten;
};

struct TNode
{
	key data;
	TNode* pRight;
	TNode* pLeft;
};

typedef TNode* Tree;

void CreateTree(Tree& t)
{
	t = 0;
}

TNode* CreateTNode(key x)
{
	TNode* p = new TNode;
	if (!p)
	{
		cout << "Khong du bo nho!!";
		exit(1);
	}
	else
	{
		p->data = x;
		p->pRight = p->pLeft = 0;
	}
	return p;
}

int InsertTNode(Tree& t, TNode* p)
{
	if (t != NULL)
	{
		if (t->data.MSSV == p->data.MSSV)
			return 0;
		else
			if (t->data.MSSV > p->data.MSSV)
				return InsertTNode(t->pLeft, p);
			else
				return InsertTNode(t->pRight, p);
	}
	t = p;
	return 1;
}

void LNR(Tree t)
{
	if (t != NULL)
	{
		LNR(t->pLeft);
		cout << t->data.MSSV << " ";
		LNR(t->pRight);
	}
}

bool SearchTNode(Tree t, int ms)
{
	if (t)
	{
		if (t->data.MSSV == ms)
			return 1;
		else if (t->data.MSSV > ms)
			return SearchTNode(t->pLeft, ms);
		else
			return SearchTNode(t->pRight, ms);
	}
	return 0;
}

void TheMang(Tree& p, Tree& q)
{
	if (q->pLeft)
		return TheMang(p, q->pLeft);
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}

void DeleteTNode(Tree& t, int ms)
{
	if (!t)
		return;
	else if (t->data.MSSV > ms)
		return DeleteTNode(t->pLeft, ms);
	else if (t->data.MSSV < ms)
		return DeleteTNode(t->pRight, ms);
	else
	{
		TNode* p = t;
		if (!t->pLeft)
			t = t->pRight;
		else if (!t->pRight)
			t = t->pLeft;
		else
		{
			TNode *q = t->pLeft;
			TheMang(q, p);
		}
		delete p;
	}
}

int DemChieuCao(Tree t)
{
	if (!t)
		return 0;
	else
		return max(DemChieuCao(t->pLeft), DemChieuCao(t->pRight)) + 1;
}

void main()
{
	Tree a;
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	key data;
	CreateTree(a);
	for (int i = 0; i < n; i++)
	{
		TNode* p = new TNode();
		cout << "Nhap MSSV:";
		cin >> data.MSSV;
		while (SearchTNode(a, data.MSSV)==true)
		{
			cout << "Ma so da ton tai, nhap ma so khac: ";
			cin >> data.MSSV;
		}
		cout << "Nhap ten: ";
		cin.ignore();
		getline(cin, data.ten);
		p = CreateTNode(data);
		InsertTNode(a, p);
		cout << "----------------------\n";
	}
	cout << "LNR: "; LNR(a);
	cout << "\nchieu cao: " << DemChieuCao(a);
}