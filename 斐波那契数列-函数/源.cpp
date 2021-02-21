#include<iostream>
using namespace std;
int fb(int a) {
	if (a <= 2)
		return 1;
	else
		return fb(a - 1) + fb(a - 2);
}
int main() {
	int a ;
	cin >> a;
	int s = 0;
	for (int i = 1; i <= a; i++)
		s += fb(i);
	cout << s << endl;
}
//int main() {
//	int a[100];
//	
//	for (int i = 0; i < 9; i++)
//	cin >> a[i];
//	for (int i = 0; i < 9; i++) {
//		int max = i;
//		int j = 0;
//		for (j = i; j < 9; j++) {
//			if (a[i] < a[j]) {
//				max = j;
//			}
//		}
//		int temp = a[i];
//		a[i] = a[max];
//		a[max] = temp;
//	}
//}
