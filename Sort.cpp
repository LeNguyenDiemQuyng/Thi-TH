#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define MAX 101

void Create(int a[], int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = rand() % (100 - 1 + 1) + 1;
}

void Xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void SelectionSort(int a[], int n) {
	int min;
	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[min], a[i]);
	}
}

void InsertionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int x = a[i], pos = i - 1;
		while (pos >= 0 && a[pos] > x) {
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

void InterchangeSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j])
				swap(a[i], a[j]);
		}
}

void BubbleSort(int a[], int n) {
	bool haveSwap = false;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				swap(a[i], a[j]);
				haveSwap = true;
			}
		}
		if (haveSwap == false)
			break;
	}
}

void QuickSort(int a[], int left, int right) {
	int x = a[(left + right) / 2];
	int i = left, j = right;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (left <= j)
		QuickSort(a, left, j);
	if (i <= right)
		QuickSort(a, i, right);
}

void CountingSort(int a[], int n, int c[])
{
	int b[MAX] = { 0 };
	for (int i = 0; i < n; i++)
		b[a[i]]++;
	for (int i = 1; i < MAX; i++)
		b[i] += b[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		b[a[i]]--;
		c[b[a[i]]] = a[i];
	}
}

int Max(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void CountSort(int a[], int n, int exp)
{
	int* output = new int[n];
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--) {
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		a[i] = output[i];
}

void RadixSort(int a[], int n)
{
	int m = Max(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		CountSort(a, n, exp);
}

void Merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int a[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);
		Merge(a, l, m, r);
	}
}

void Heapify(int a[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i)
	{
		swap(a[i], a[largest]);

		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);
	for (int i = n - 1; i > 0; i--)

	{
		swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}

void ShakerSort(int a[], int n)
{
	int Left = 0;
	int Right = n - 1;
	int k = 0;
	while (Left < Right)
	{
		for (int i = Left; i < Right; i++)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				k = i;
			}
		}
		Right = k;
		for (int i = Right; i > Left; i--)
		{
			if (a[i] < a[i - 1])
			{
				swap(a[i], a[i - 1]);
				k = i;
			}
		}
		Left = k;
	}
}

int ShellSort(int a[], int n)
{
	for (int h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			int temp = a[i];
			int j;
			for (j = i; j >= h && a[j - h] > temp; j -= h)
				a[j] = a[j - h];
			a[j] = temp;
		}
	}
	return 0;
}

void menu()
{
	cout << "\n-----------MENU------------------\n";
	cout << "1.Selection Sort\n";
	cout << "2.Insertion Sort\n";
	cout << "3.Interchange Sort\n";
	cout << "4.Quick Sort\n";
	cout << "5.Merge Sort\n";
	cout << "6.Counting Sort\n";
	cout << "7.Radix Sort\n";
	cout << "8.Bubble Sort\n";
	cout << "9.Heap Sort\n";
	cout << "10.Shaker Sort\n";
	cout << "11.Shell Sort\n";
	cout << "0.Thoat";
}

int main() {
	int n, a[100], chon, x;
	do {
		do
		{
			cout << "Nhap so luong phan tu (0<n<99): ";
			cin >> n;
		} while (n < 0 || n>99);
		Create(a, n);
		Xuat(a, n);
		menu();
		cout << "\n--------------------------------\n";
		cout << "chon:  "; cin >> chon;
		switch (chon) {
		case 0:
		{
			cout << "Dang thoat...\n";
			break;
		}
		case 1:
		{
			SelectionSort(a, n);
			cout << "Day so duoc sap xep theo SelectionSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 2:
		{
			InsertionSort(a, n);
			cout << "Day so duoc sap xep theo InsertionSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 3:
		{
			InterchangeSort(a, n);
			cout << "Day so duoc sap xep theo InterchangeSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 4:
		{
			QuickSort(a, 0, n - 1);
			cout << "Day so duoc sap xep theo QuickSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 5:
		{
			MergeSort(a, 0, n - 1);
			cout << "Day so duoc sap xep theo MergeSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 6:
		{
			int* c = new int[n];
			CountingSort(a, n, c);
			cout << "Day so duoc sap xep theo CountingSort thanh:\n";
			Xuat(c, n);
			break;
		}
		case 7:
		{
			RadixSort(a, n);
			cout << "Day so duoc sap xep theo RadixSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 8:
		{
			BubbleSort(a, n);
			cout << "Day so duoc sap xep theo BubbleSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 9:
		{
			HeapSort(a, n);
			cout << "Day so duoc sap xep theo HeapSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 10:
		{
			ShakerSort(a, n);
			cout << "Day so duoc sap xep theo ShakerSort thanh:\n";
			Xuat(a, n);
			break;
		}
		case 11:
		{
			ShellSort(a, n);
			cout << "Day so duoc sap xep theo ShakerSort thanh:\n";
			Xuat(a, n);
			break;
		}
		default:
		{
cout << "Vui long nhap lai!!! ";
		}
		}
		cout << "\n--------------------------------\n";
	} while (chon != 0);
	return 0;
}