/*【问题描述】编写程序，将一个字符串逆序存放，并与原字符串连接后输出。

【输入形式】一个字符串

【输出形式】处理后的字符串

【样例输入】china

【样例输出】chinaanihc
*/

#include<iostream>
using namespace std;



int main() {
	/*char a[100],b[100]="0";
	int x;
	cin >> a;
	x = strlen(a);
	for (int j = 0; j <= (x - 1); j++) {
		b[j] = a[j];
	}
	for (int i = 0; i <= (x - 1) / 2; i++) {
		char c = a[i];
		a[i] = a[x - 1 - i];
		a[x - 1 - i] = c;
	}
	int i = 0;
	
	for (int p = x; p<= 2 * x - 1; p++) {
		b[p] = a[i];
		i++;
	}
	cout << b << endl;*/
	char a[100];
	a[1] = 'q';
	a[2] = 'q';
	a[3] =0;
	cout << a;

	
}