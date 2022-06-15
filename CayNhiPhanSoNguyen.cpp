#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* pLeft;
	Node* pRight;
};

typedef Node* Tree;

void CreateTree(Tree& t)
{
	t = 0;
}

Node* CreateNode(int x)
{
	Node* p = new Node;
	if (!p)
		exit(1);
	else
	{
		p->data = x;
		p->pLeft = p->pRight = 0;
	}
	return p;
}

int InsertNode(Tree& t, Node* p)
{
	if (t != 0)
	{
		if (t->data == p->data)
			return 0;
		else
		{
			if (t->data > p->data)
				return InsertNode(t->pLeft, p);
			else
				return InsertNode(t->pRight, p);
		}
	}
	t = p;
	return 1;
}

void LNR(Tree t)
{
	if (t != 0)
	{
		LNR(t->pLeft);
		cout << t->data << " ";
		LNR(t->pRight);
	}
}

bool SearchNode(Tree t, int x)
{
	if (t)
	{
		if (t->data == x)
			return true;
		else
		{
			if (t->data > x)
				return SearchNode(t->pLeft, x);
			else
				return SearchNode(t->pRight, x);
		}
	}
	return 0;
}

int DemLa(Tree t)
{
	if (t == 0)
		return 0;
	if (t->pLeft == 0 && t->pRight == 0)
		return 1 + DemLa(t->pLeft) + DemLa(t->pRight);
	else
		return DemLa(t->pLeft) + DemLa(t->pRight);
}

void TheMang(Tree& p, Tree& q)
{
	if (q->pLeft)
		TheMang(p->pLeft, q);
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}

void DeleteNode(Tree& t, int x)
{
	if (!t)
		return;
	else if (t->data > x)
		DeleteNode(t->pLeft, x);
	else if (t->data < x)
		DeleteNode(t->pRight, x);
	else
	{
		Node* p = t;
		if (t->pLeft == NULL)
			t = t->pRight;
		else if (t->pRight == NULL)
			t = t->pLeft;
		else
		{
			Node* q = t->pRight;
			TheMang(p, q);
		}
		delete p;
	}
}

void main()
{
	Tree a;
	int n;
	cout << "Nhap so luong: ";
	cin >> n;
	int x;
	CreateTree(a);
	for (int i = 0; i < n; i++)
	{
		Node* p = new Node();
		cout << "Nhap: ";
		cin >> x;
		p = CreateNode(x);
		InsertNode(a, p);
	}
	LNR(a);
	cout << DemLa(a);
	cout << "\n";
	cin >> n;
	DeleteNode(a, n);
	LNR(a);
	Node *p = CreateNode(n);
	InsertNode(a, p);
	LNR(a);
}