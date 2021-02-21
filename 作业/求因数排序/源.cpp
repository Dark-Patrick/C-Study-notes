#include<iostream>
using namespace std;

//int main() {
//	int n, num[100], a[100], count,i, j, mincount, p, temp, k;
//	cin >> n;
//	for (i = 0; i < n; i++)
//		cin >> num[i];
//	for (i = 0; i < n; i++) {
//		count = 0;
//		for (j = 1; j < num[i]; j++) {
//			if (num[i] % j == 0)
//				count++;
//		}
//		a[i] = count;
//	}
//	for (j = 0; j < n; j++) {
//		p = j;
//		mincount = a[j];
//		for (k = j + 1; k < n; k++) {
//			if (a[k] < mincount) {
//				mincount = a[k];
//				p = k;
//			}
//			else if(a[k]==mincount)
//				if (num[p] < num[k]) {
//					mincount = a[k];
//					p = k;
//				}
//		}
//		temp = a[p];
//		a[p] = a[j];
//		a[j] = temp;
//		temp = num[j];
//		num[j] = num[p];
//		num[p] = temp;
//
//
//
//
//	}
//	for (i = 0; i < n; i++)
//		cout << num[i] << " ";
//	return 0;
//}
int fun(int num) {
	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0)
			count++;
	}
	return count;
}
int main() {
	int num[100];
	int n, i, j;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++) {
		int min = i;
		for ( j = i + 1; j < n; j++) {
			if (fun(num[min]) > fun(num[j])) {
				min = j;
			}
			else if (fun(num[min]) == fun(num[j])) {
				if (num[min] < num[j])
					min = j;
			}
		}
		int temp = num[min];
		num[min] = num[i];
		num[i] = temp;
	}
	for (i = 0; i < n; i++)
		cout << num[i] << " ";
	return 0;

}