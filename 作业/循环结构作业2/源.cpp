#include<iostream>
using namespace std;
int main() {
	int n, k, min, i;
	cin >> n;
	cin >> k;
	min = k;

	for (i = 1; i <= n-1; i++) {
		cin >> k;
		if (k <= min)
			min = k;

	}
	cout << min << endl;
	return 0;

}