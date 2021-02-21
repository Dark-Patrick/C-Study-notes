#include<iostream>
using namespace std;
//int fun1(int& a, int& b) {
//	if (a >= b) {
//		for (int i = b; i > 0; i--) {
//			if (a % i == 0 && b % i == 0)
//				return i;
//		}
//	}
//	else {
//		for (int i = a; i > 0; i--) {
//			if (a % i == 0 && b % i == 0)
//				return i;
//		}
//	}
//}
//int fun2(int& a, int& b) {
//	int s = a * b;
//	for (int i = 1; i <=s; i++) {
//		if (i % a == 0 && i % b == 0)
//			return i;
//	}
//}
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << fun1(a, b) << " " << fun2(a, b) << endl;
//	return 0;
//}
//int main() {
//	double a, b, c,d, x1, x2;
//	cin >> a >> b >> c;
//	if (a == 0)
//		if (b == 0)
//			cout << "error" << endl;
//		else cout << "x=" << -1.0 *c / b << endl;
//		else {
//			d = b * b - 4 * a * c;
//			double s = sqrt(d);
//			if (d == 0) {
//				x1 = x2 = -1.0 * b / 2 * a;
//				cout << "x1=x2=" << x2 << endl;
//			}
//			else if (d > 0) {
//				x1 = (-1.0 * b + s) / 2 * a;
//				x2 = (-1.0 * b - s) / 2 * a;
//				cout << "x1=" << x1 <<" "<< "x2=" << x2 << endl;
//			}
//			else cout << "方程无实根" << endl;
//			
//		}
//	return 0;

//}
int main() {
	int a = 12;
	double b = (double)a/11;
	cout << b;


}