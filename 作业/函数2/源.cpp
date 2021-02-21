#include<iostream>
#include<cmath>
using namespace std;
int fun(int num) {
	int a[100];
	int i = 0;
	while (num > 0) {
		a[i] = num % 10;
		num /= 10;
		i++;
	}
	int s = 0;
	for (int j = 0; j < i - 1; j++) {
		s += a[j] * pow(10.0, j);
	}
	return s;
}
int main() {
	int a;
	cin >> a;
	cout << fun(a) << endl;
}