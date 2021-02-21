#include<iostream>
using namespace std;
int fun(int n, int a[], int b[]) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 1; j <= a[i]; j++) {
			if (a[i] % j == 0)
				k++;
		}
		if (k == 2) {
			b[count] = a[i];
			count++;
		}
	}
	for(int ii=0;ii<count;ii++)
		for (int jj = 0; jj < count-1; jj++) {
			if (b[jj] > b[jj + 1]) {
				int temp = b[jj];
				b[jj] = b[jj + 1];
				b[jj + 1] = temp;
			}
		}
	return count;
}
int main() {
	int n, a[100], b[100];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int count=fun(n, a, b);
	for (int j = 0; j < count; j++)
		cout << b[j] << " ";
	cout << endl;
	return 0;
}