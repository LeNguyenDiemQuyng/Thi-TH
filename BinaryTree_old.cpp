#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct TNode
{
	int data;
	struct TNode* pLeft;
	struct TNode* pRight;
}TNode;

typedef TNode* TREE;

void CreateTree(TREE& T)
{
	T = NULL;
}

int InsertTNode(TREE& T, int x)
{
	if (T == NULL)
	{
		TNode* p = new TNode;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		T = p;
	}
	else
	{
		if (T->data > x)
			return InsertTNode(T->pLeft, x);
		else
			return InsertTNode(T->pRight, x);
	}
}

void NLR(TREE T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}

void NRL(TREE T)
{
	if (T != NULL)
	{
		cout << T->data << " ";
		NRL(T->pRight);
		NRL(T->pLeft);
	}
}

void LNR(TREE T)
{
	if (T != NULL)
	{
		LNR(T->pLeft);
		cout << T->data << " ";
		LNR(T->pRight);
	}
}



bool SearchTNode(TREE t, int ms)
{
	if (t)
	{
		if (t->data == ms)
			return 1;
		else if (t->data > ms)
			return SearchTNode(t->pLeft, ms);
		else
			return SearchTNode(t->pRight, ms);
	}
	return 0;
}


void RNL(TREE T)
{
	if (T != NULL)
	{
		RNL(T->pRight);
		cout << T->data << " ";
		RNL(T->pLeft);
	}
}

void LRN(TREE T)
{
	if (T != NULL)
	{
		LRN(T->pLeft);
		LRN(T->pRight);
		cout << T->data << "  ";
	}
}


void RLN(TREE T)
{
	if (T != NULL)
	{
		RLN(T->pRight);
		RLN(T->pLeft);
		cout << T->data << "  ";
	}
}

int DemSoNut(TREE T)
{
	if (T == NULL)
		return 0;
	else
		return 1 + DemSoNut(T->pLeft) + DemSoNut(T->pRight);
}

int DemSoNut2Con(TREE T)
{
	if (T == NULL)
		return 0;
	if (T->pLeft != NULL && T->pRight != NULL)
		return 1 + DemSoNut2Con(T->pLeft) + DemSoNut2Con(T->pRight);
	else
		return DemSoNut2Con(T->pLeft) + DemSoNut2Con(T->pRight);
}

int DemSoLa(TREE T)
{
	if (T == NULL)
		return 0;
	if (T->pLeft == NULL && T->pRight == NULL)
		return 1 + DemSoLa(T->pLeft) + DemSoLa(T->pRight);
	else
		return DemSoLa(T->pLeft) + DemSoLa(T->pRight);
}

int ChieuCao(TREE T)
{
	if (T == NULL)
		return 0;
	else
		return max(ChieuCao(T->pLeft), ChieuCao(T->pRight)) + 1;
}

void ThayThe(TREE& p, TREE& q)
{
	if (q->pLeft != NULL)
	{
		ThayThe(p, q->pLeft);
	}
	else
	{
		p->data = q->data;
		p = q;
		q = q->pRight;
	}
}

void DeleteNode(TREE& T, int x)
{
	if (T == NULL)
		return;
	else if (T->data > x)
		DeleteNode(T->pLeft, x);
	else if (T->data < x)
		DeleteNode(T->pRight, x);
	else
	{
		TNode* p = T;
		if (T->pLeft == NULL)
			T = T->pRight;
		else if (T->pRight == NULL)
			T = T->pLeft;
		else
		{
			TNode* q = T->pRight;
			ThayThe(p, q);
		}
		delete p;
	}
}

bool SNT(int x)
{
	if (x < 2)
		return false;
	else if (x == 2 || x == 3)
		return true;
	else
	{
		for (int i = 2; i <= x; i++)
		{
			if (x % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

void DeleteSNT(TREE& T)
{
	if (T != NULL)
	{
		if (SNT(T->data) == true)
		{
			DeleteNode(T, T->data);
		}
		DeleteSNT(T->pLeft);
		DeleteSNT(T->pRight);
	}
}

int OddSum(TREE T)
{
	if (T == NULL)
		return 0;
	else
	{
		if (T->data % 2 == 1)
			return T->data + OddSum(T->pLeft) + OddSum(T->pRight);
		else
			return OddSum(T->pLeft) + OddSum(T->pRight);
	}
}

int EvenLeaf(TREE T)
{
	if (T == NULL)
		return 0;
	if (T->pLeft == NULL && T->pRight == NULL && T->data % 2 == 0)
		return 1 + DemSoLa(T->pLeft) + DemSoLa(T->pRight);
	else
		return DemSoLa(T->pLeft) + DemSoLa(T->pRight);
}

int Sum(TREE T)
{
	if (T == NULL)
		return 0;
	else
		return T->data + Sum(T->pLeft) + Sum(T->pRight);
}

void CountNodes(TREE T, int k)
{
	if (T == NULL)
		return;
	else
	{
		CountNodes(T->pLeft, k);
		if (T->data > k)
		{
			cout << T->data << " ";
		}
		CountNodes(T->pRight, k);
	}
}

void Menu()
{
	cout << "----------||  MENU   ||----------------------------\n";
	cout << "0. Thoat\n";
	cout << "1. Them node vao cay\n";
	cout << "2. Duyet cay LEFT -> NODE -> RIGHT\n";
	cout << "3. Duyet cay LEFT -> RIGHT -> NODE\n";
	cout << "4. Duyet cay RIGHT -> NODE -> LEFT\n";
	cout << "5. Duyet cay RIGHT -> LEFT -> NODE\n";
	cout << "6. Duyet cay NODE -> LEFT -> RIGHT\n";
	cout << "7. Duyet cay NODE -> RIGHT -> LEFT\n";
	cout << "8. Dem so nut\n";
	cout << "9. Dem so nut co 2 con\n";
	cout << "10. Dem so nut la\n";
	cout << "11. Tim kiem nut co gia tri nguyen duong\n";
	cout << "12. Tinh chieu cao cua cay\n";
	cout << "13. Xoa nut co gia tri nguyen duong\n";
	cout << "14. Xoa nut la so nguyen to dau tien\n";
	cout << "15. Tinh tong so le trong cay\n";
	cout << "16. Tinh tong cac gia tri trong cay\n";
	cout << "17. Tinh tong so luong nut la la so chan";
	cout << "18. Tinh tong so luong nut co gia tri lon hon k\n";
	cout << "---------------------------------------------------\n";
}

void Chon(TREE a)
{
	Menu();
	int chon;
	do
	{
		cout << "Chon thao tac: ";
		cin >> chon;
		cout << "----  ||   ||  ---------------------\n";
		switch (chon)
		{
		case 0:
		{
			cout << "dang thoat.....\n";
			break;
		}
		case 1:
		{
			int x;
			cout << "Nhap gia tri muon them: ";
			cin >> x;
			InsertTNode(a, x);
			cout << "\nDa them :>";
			break;
		}
		case 2:
		{
			cout << "Cay duoc duyet theo LEFT -> NODE -> RIGHT:\n";
			LNR(a);
			break;
		}
		case 3:
		{
			cout << "Cay duoc duyet theo LEFT -> RIGHT -> NODE:\n";
			LRN(a);
			break;
		}
		case 4:
		{
			cout << "Cay duoc duyet theo RIGHT -> NODE -> LEFT:\n";
			RNL(a);
			break;
		}
		case 5:
		{
			cout << "Cay duoc duyet theo RIGHT -> LEFT -> NODE:\n";
			RLN(a);
			break;
		}
		case 6:
		{
			cout << "Cay duoc duyet theo NODE -> LEFT -> RIGHT:\n";
			NLR(a);
			break;
		}
		case 7:
		{
			cout << "Cay duoc duyet theo NODE -> RIGHT -> LEFT:\n";
			NLR(a);
			break;
		}
		case 8:
		{
			cout << "Cay co " << DemSoNut(a) << " nut";
			break;
		}
		case 9:
		{
			cout << "Cay co " << DemSoNut2Con(a) << " nut co 2 con";
			break;
		}
		case 10:
		{
			cout << "Cay co " << DemSoLa(a) << " nut la";
			break;
		}
		case 11:
		{
			int x;
			cout << "Nhap gia tri nguyen duong can tim: ";
			cin >> x;
			if (SearchTNode(a, x))
				cout << "Ton tai\n";
			else
				cout << "Khong ton tai\n";
			break;
		}
		case 12:
		{
			cout << "Cay co chieu cao la: " << ChieuCao(a);
			break;
		}
		case 13:
		{
			int x;
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			DeleteNode(a, x);
			LNR(a);
			cout << "\nDa xoa " << x;
			break;
		}
		case 14:
		{
			cout << "Em noi that la em co code o tren nhung ma no khong co chay :((";
			break;
		}
		case 15:
		{
			cout << "So le trong cay la: " << OddSum(a) << endl;
			break;
		}
		case 16:
		{
			cout << "Tong so le trong cay la: " << Sum(a) << endl;
			break;
		}
		case 17:
		{
			cout << "Tong so luong nut trong cay la so chan: " << EvenLeaf(a) << endl;
			break;
		}
		case 18:
		{
			int k;
			cout << "Nhap k: ";
			cin >> k;
			cout << "So nut co truong lon hon " << k << endl;
			CountNodes(a, k);
			cout << endl;
			break;
		}
		default:
		{
			cout << "Sai roi vui long nhap lai ^^\n";
			break;
		}
		}
		cout << "\n-------------------------------------------\n";
	} while (chon != 0);
}

int main()
{
	TREE a;
	CreateTree(a);
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		InsertTNode(a, rand() % 100 + 1);
	}
	Chon(a);
	return 0;
}