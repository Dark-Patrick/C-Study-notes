/*问题描述】编写程序，输入字符串，统计英文字母、数字字符及其他字符的个数。

【输入形式】一个字符串

【输出形式】三个数，之间用空格隔开

【样例输入】abc129++* ABC

【样例输出】6 3 3

【样例说明】字符串“abc129++ * ABC”中英文字母的个数是6，数字字符的个数是3，其他字符的个数是3。*/

#include<iostream>
using namespace std;
int main() {
	char a[100];
	cin >> a;
	int i = 0;	int ax = 0, b = 0, c = 0;
	while (a[i]!='\0') {
		
	
		if ('0' <= a[i] && a[i] <= '9')
			ax++;
		else if (a[i] >= 'A' && a[i] <= 'Z' || a[i]>= 'a' && a[i] <= 'z')
			b++;
		else
			c++;
		i++;
	}
	cout << b << " " << ax<< " " << c << endl;
}