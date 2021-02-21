#include<iostream>
using namespace std;
//Ë®ÏÉ»¨
//int main() {
//	int a, x, y, z;
//	cin >> a;
//	if (a >= 100 && a <= 999) {
//		for (int i = 100; i <= a; i++) {
//			x = i % 10;
//			y = (i / 10) % 10;
//			z = i / 100;
//			int sum = x * x*x + y * y*y + z * z*z;
//			if (i == sum)
//				cout << i << " ";
//		}
//		cout << endl;
//	}
//	else
//		cout << "out of range!" << endl;
//	return 0;
//}

//Ñ­»·×óÒÆ
//int main() {
//	int a[100], n;
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int temp = a[0];
//	for (int j =0; j <n; j++)
//		a[j] = a[j + 1];
//	a[n-1] = temp;
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//}
//ÄæÐòÅÅÁÐ
//int main() {
//	int n, a[100];
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	for (int j = 0; j < n / 2; j++) {
//		int temp = a[j];
//		a[j] = a[n - 1 - j];
//		a[n - 1 - j] = temp;
//	}
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//	cout << endl;
//}
//½×³ËºÍ
//int main() {
//	double n, s = 1;
//	cin >> n;
//	double sum = 0;
//	for (int i = 1; i <= n; i++) {
//		s *= i;
//		sum += s;
//
//	}
//	cout << sum << endl;
//
//}

int main() {
	int a, k,s=0;
	cin >> a;
	int memory = a;
	while (a > 0) {
		k = a % 10;
		int j = 1;
		for (int t = 1; t <= k; t++) {
			j *= t;
		}
		s += j;
		a /= 10;
	}
	if (s == memory)
		cout << s << '\n' << "yes" << endl;
	else 
		cout << s << '\n' << "no" << endl;
}