#include<iostream>
using namespace std;
//void fun(int num) {
//	int a1 = 0, a2 = 0, a3 = 0;
//	int x;
//	while (num > 0) {
//		x = num % 10;
//		num /= 10;
//		switch (x) {
//		case 1:
//			a1++;
//			break;
//		case 2:
//			a2++;
//			break;
//		case 3:
//			a3++;
//			break;
//
//		}
//	}
//	cout << a1 << " " << a2 << " " << a3 << endl;
//}
//int main() {
//	int a;
//	cin >> a;
//	fun(a);
//	return 0;
//}


//int fun(int num) {
//	int b = 0;
//	int sum = 0;
//	for (int i = 1; i < num; i++) {
//		if (num % i == 0) {
//			b += i;
//		}
//	}
//	for (int j = 1; j < b; j++) {
//		if (b % j == 0) {
//			sum += j;
//		}
//	}
//	if (sum == num)
//		return b;
//	else
//		return -1;
//}
//int main() {
//	int a;
//	cin >> a;
//	int text = fun(a);
//	if (text != -1)
//		cout << text << endl;
//	else
//		cout << "no" << endl;
//}

double fun(int k) {
	double z = -1.0;
	double s = 0;
	for (  int i = 1; i <= k; i++) {
		z *= -1.0;
		s += z / ((double)i * ((double)i + 1));
	}
	return s;
}
int main() {
	int k;
	cin >> k;
	cout << fun(k) << endl;
}