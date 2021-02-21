#include<iostream>
using namespace std;
double fun1(int n, double x) {
	double s = 1.0,r;
	for (int i = 1; i <= n; i++) {
		double a = 1.0,
		 y = 1.0,z=-1.0;
		for (int j = 1; j <= i; j++) {
			z *= -1;
			a *= x;
			y *= j;
            r = z*a / y;
		}
		
		s = s + r;
	}
	return s;
}
int main() {
	int n;
	double x;
	cin >> n >> x;
	cout << fun1(n, x) << endl;
	return 0;
}