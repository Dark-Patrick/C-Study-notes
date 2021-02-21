#include<iostream>
#include<cmath>
using namespace std;
int fun(int a) {
	int b[100];
	int i = 0;
	int s = 0;
	while (a > 0) {
		b[i] = a % 8;
		a=a / 8;
		i++;
	}
	for (int j = i-1; j >= 0; j--) {
		s += b[j] * pow(10.0, j );
	}
	return s;
}
int main() {
	int a;
	cin >> a;
	cout << fun(a) << endl;
}