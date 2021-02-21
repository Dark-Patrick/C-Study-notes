#include<iostream>
using namespace std;
int fun(int a[100], int n) {
	int max = 0, min = 0;
	int s = 0;
	for (int j = 0; j < n; j++) {
		if (a[max] < a[j])
			max = j;
		if (a[min] > a[j])
			min = j;
	}
	int x = a[min];
	a[min] = a[max];
	a[max] = x;
	for (int k = 0; k < n; k++) {
		s += a[k];
	}
	return s;
}
int main() {
	int a[50], n, i, sum;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sum = fun(a, n);
	for (i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl << sum << endl;
	return 0;
}