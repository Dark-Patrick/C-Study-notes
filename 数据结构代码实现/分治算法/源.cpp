#include<iostream>
using namespace std;
#define Cutoff 100

//核心：有序子列归并
void Merge(int a[], int temp[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;//左边终点位置
	int Tmp = L;//存放结果数组的初始位置
	int NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] <= a[R])temp[Tmp++] = a[L++];
		else             temp[Tmp++] = a[R++];
	}
	while (L <= LeftEnd)
		temp[Tmp++] = a[L++];
	while (R <= RightEnd)
		temp[Tmp++] = a[R++];

	for (int i = 0; i < NumElements; i++, RightEnd--)
		a[RightEnd] = temp[RightEnd];
}
//归并递归
void Msort(int a[], int temp[], int L, int RightEnd) {
	int center;
	if (L<RightEnd) {
		center = (L + RightEnd) / 2;
		Msort(a, temp, L, center);
		Msort(a, temp, center + 1, RightEnd);
		Merge(a, temp, L, center + 1, RightEnd);
	}
}//T(N)=)(NlogN)
/////////////////////////////////////////////////////////////////////
//归并非递归
void Merge1(int a[], int temp[], int L, int R, int RightEnd) {
	int LeftEnd = R - 1;//左边终点位置
	int Tmp = L;//存放结果数组的初始位置
	int NumElements = RightEnd - L + 1;
	while (L <= LeftEnd && R <= RightEnd) {
		if (a[L] <= a[R])temp[Tmp++] = a[L++];
		else             temp[Tmp++] = a[R++];
	}
	while (L <= LeftEnd)
		temp[Tmp++] = a[L++];
	while (R <= RightEnd)
		temp[Tmp++] = a[R++];

	/*for (int i = 0; i < NumElements; i++, RightEnd--)
		a[RightEnd] = temp[RightEnd];*/
}
void Merge_pass(int a[], int temp[], int n, int length) {
	int i = 0;
	for (i=0; i <= n - 2 * length; i += 2 * length) 
		Merge1(a, temp, i, i + length, i + 2 * length - 1);
	if ( i + length < n)
		Merge1(a, temp, i, i + length, n - 1);
	else
		for (int j = i; j < n; j++)temp[j] = a[j];
}
//////////////////////////////////////////////////////////////////
//统一函数接口
void Merge_sort(int a[], int n) {
	int* temp = new int[n];//最开始分配内存，减少分配和释放次数。
	if (temp != NULL) {
		Msort(a, temp, 0, n - 1);
		delete[] temp;
	}
	else
		cout << "ERROR:空间不足" << endl;
}

void Merge_sort1(int a[], int n) {
	int length = 1;
	int* temp = new int[n];
	if (temp != NULL) {
		while (length<n) {
			Merge_pass(a, temp, n, length);
			length *= 2;
			Merge_pass(temp, a, n, length);
			length *= 2;
		}
		delete[] temp;
	}
	else
		cout << "ERROR:空间不足" << endl;
	//稳定
}
//归并排序适用于外排序


//快速排序
//选主元pivot
int Median3(int a[], int left, int right) {
	int center = (left + right) / 2;
	int temp;
	if (a[left] > a[center]) {
		temp = a[left];
		a[left] = a[center];
		a[center] = temp;
	}
	if (a[left] > a[right]) {
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
	}
	if (a[center] > a[right]) {
		temp = a[center];
		a[center] = a[right];
		a[right] = temp;
	}
	temp = a[center];
	a[center] = a[right-1];
	a[right-1] = temp;
	return a[right - 1];
}
void Quicksort(int a[], int left, int right) {
	if (Cutoff <= right - left) {
		int pivot = Median3(a, left, right);
		int i = left, j = right - 1;
		for (;;) {
			while (a[++i] < pivot) {}
			while (a[--j] > pivot) {}
			if (i < j) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else break;
		}
		int temp = a[i];
		a[i] = a[right - 1];
		a[right - 1] = temp;
		Quicksort(a, left, i - 1);
		Quicksort(a, i + 1, right);
	}
	else
	{ //调用插入排序，提高效率}

	}

}

int main() {
	
}