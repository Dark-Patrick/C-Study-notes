#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
//int main() {
//	char a[100], b;
//	bool text=false;
//	cin >> a >> b;
//	int n = strlen(a);
//	for (int i = 0; i < n; i++) {
//		if (a[i] == b) {
//			cout << i << endl;
//			text = true;
//			break;
//		}
//	}
//	if (text == false)
//		cout << "no" << endl;
//	return 0;
//}


//int main() {
//	char a[100], b[100];
//	cin >> a >> b;
//	int i = 0, count=0;
//	while (a[i] != '\0'||b[i]!='\0') {
//		if (a[i] != b[i]) {
//			cout <<fabs( a[i] - b[i]) << endl;
//			count++;
//			break;
//		}
//		i++;
//	}
//	if (count == 0)
//		cout << 0 << endl;
//}

//int fun(int num, int k) {
//	num = num / pow(10.0, k - 1);
//	k = num % 10;
//	return k;
//
//}
//int main() {
//	int num, k;
//	cin >> num >> k;
//	cout << fun(num, k);
//}

//int fun(int a, int b) {
//	b *= 10;
//	int k1 = a % 10;
//	a /= 10;
//	int k2 = a % 10;
//	int sum = k2 * 1000 + b + k1;
//	return sum;
//}
//int main() {
//	int a, b;
//	cin >> a >> b;
//	cout << fun(a, b) << endl;
//}
int main()
{
	int i, n, s;
	cin >> n;
	s = 0;
	
	for (i = 1; i <= n; i++){
		if (i % 7 != 0) {
			int temp = i;
			bool text = false;
			while (temp > 0) {
				int k = temp % 10;
				temp /= 10;
				if (k == 7) {
					text = true;
					break;
				}
			}
            if (text == false)
			s += i * i;
		}
           
	}
	cout << s;
}
