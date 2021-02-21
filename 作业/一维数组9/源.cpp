#include<iostream>
using namespace std;
int main() {
	int n, a[100],k;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cin >> k;
	int i=0;
	for (i = 0; i < n; i++) {
		if (k <= a[i]) {
			for (int j = n - 1; j >=i; j--)
				a[j + 1] = a[j];
			break;
		}
			
	}
	a[i] = k;
	for (int i = 0; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}