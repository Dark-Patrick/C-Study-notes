#include<iostream>
using namespace std;
int main() {
	int x;
	cin >> x;
	int** sqare;
	sqare = new int* [2*x - 1];
	 
	for (int i = 0; i < 2 * x - 1; i++) 
		sqare[i] = new int[2 * x - 1];
	for (int c = 0; c < 2 *x -1; c++) {
		for (int i = c; i < 2 * x - 1-c; i++) {
			for (int j = c; j < 2 * x - 1-c; j++) {
				sqare[i][j] = c + 1;
			}
		}
	}
	for (int i = 0; i < 2 * x - 1; i++) {
		for (int j = 0; j < 2 * x - 1; j++) {
			cout << sqare[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


//void fun(int** a,int x) {
//	system("cls");
//	for (int i = 1; i < 2 * x; i++)
//	{
//		for (int j = 1; j < 2 * x; j++)
//			cout << a[i][j] << " ";
//		cout << endl;
//	}
//}
//
//int main()
//{
//	int x;
//	cin >> x;
//	int i, j, k;
//	int** cube;
//	cube = new int* [2 * x];
//	for (i = 0; i < 2 * x; i++)
//		cube[i] = new int[2 * x];
//	for (i = 1; i <= x; i++)
//	{
//		for (j = 1, k = 1; j <= x; j++)
//		{
//			cube[i][j] = k;
//			cube[i][2 * x - j] = k;
//			cube[2 * x - i][j] = k;
//			cube[2 * x - i][2 * x - j] = k;
//			if (k < i)
//				k++;
//		}
//		fun(cube,x);
//	}
//	for (i = 1; i < 2 * x; i++)
//	{
//		for (j = 1; j < 2 * x; j++)
//			cout << cube[i][j] << " ";
//		cout << endl;
//	}
//	return 0;
//}