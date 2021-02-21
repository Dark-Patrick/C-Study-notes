#include<iostream>
using namespace std;

//原始希尔排序
void Shell_sort_origin(int a[], int n) {
	int D;
	for (D = n / 2; D > 0; D /= 2) {//希尔增量序列
		for (int p = D; p < n; p++) {//插入序列
			int Temp = a[p];
			for (int i = p; i >= D && a[i - D] > Temp; i -= D)
				a[i] = a[i - D];
			a[i] = Temp;
		}
	}
}//增量元素不互质，则小增量可能根本不起作用
//Hibbard增量序列：Dk=2^k-1
//Sedgewick增量序列{1，5，19，41，109，.....}
//9*4^i-9*2^i+1 or 4^i-3*2^i+1

int main() {
	 
}