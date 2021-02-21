#include<iostream>
using namespace std;
int main() {
	int n, i, a = 1, b = 2, d;
	double c, s = 0;
	cin >> n;
	c = b / a;
	for (i = 1; i <= n; i++) {
		s += c;
		d = a, a = b, b = b + d, c = b * 1.0 / a;
	}
	cout << s << endl;
}

