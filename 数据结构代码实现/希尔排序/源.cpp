#include<iostream>
using namespace std;

//ԭʼϣ������
void Shell_sort_origin(int a[], int n) {
	int D;
	for (D = n / 2; D > 0; D /= 2) {//ϣ����������
		for (int p = D; p < n; p++) {//��������
			int Temp = a[p];
			for (int i = p; i >= D && a[i - D] > Temp; i -= D)
				a[i] = a[i - D];
			a[i] = Temp;
		}
	}
}//����Ԫ�ز����ʣ���С�������ܸ�����������
//Hibbard�������У�Dk=2^k-1
//Sedgewick��������{1��5��19��41��109��.....}
//9*4^i-9*2^i+1 or 4^i-3*2^i+1

int main() {
	 
}