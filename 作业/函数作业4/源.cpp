/*【问题描述】哥德巴赫猜想指出：任何一个不小于6的偶数都可以表示为两个素数之和。例如：6 = 3 + 3 8 = 3 + 5 … 50 = 3 + 47。从键盘输入n（n >= 6且为偶数），输出对应的表达式，编写函数判断一个数是否为素数。要求输入输出均在主函数中完成。

【输入形式】一个数

【输出形式】这个数等于两素数之和的形式，并且这两素数是第一对满足条件的素数（表达式中间不包含空格）。

【样例输入】8

【样例输出】8 = 3 + 5
*/
#include<iostream>
using namespace std;
int fun(int& a) {
	int b[100], count = 0;
	if (a >= 6 && a % 2 == 0) {
		for (int i = 2; i <= a; i++) {
			int k = 0;
			for (int j = 1; j <= i; j++) {
				if (i % j == 0) {
					k++;
				}
			}
			if (k == 2)
				b[count] = i;
			count++;
		}
		for (int x = 0; x < count; x++) {
			int s = 0;
			for (int y=0; y < count; y++) {
				s = b[x] + b[y];
				if (a == s) {
					cout << a << "=" << b[x] << "+" << b[y] << endl;
					return 1;
				}
			}
		}
		return 0;



	}
	else cout << "Error!" << endl;
}
int main() {
	int a;
	cin >> a;
	fun(a);
	return 0;

}
