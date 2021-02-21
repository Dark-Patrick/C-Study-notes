#include<iostream>
using namespace std;
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
int main() {
	int a[3][3];
	cout << "输入9个整数作为矩阵元素值" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> a[i][j];
	cout << "初始矩阵" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << a[i][j] << "  ";
		cout << endl;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < i; j++)
			swap(a[i][j], a[j][i]);
	cout << "转秩" << endl;
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++) 
			cout << a[i][j] << "  ";
			cout << endl;
		}

	int(*p)[3];
	p = new int[3][3];
	cout << "输入9个整数作为矩阵元素值" << endl;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> p[i][j];
	cout << "初始矩阵" << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			cout << p[i][j] << "  ";
		cout << endl;
	}
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < i; j++)
				swap(p[i][j], p[j][i]);
		cout << "转秩" << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << p[i][j] << "  ";
			cout << endl;
		}
		delete[] p;
}