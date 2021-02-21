#include<iostream>
using namespace std;
/*int main() {
	int* function();
	int* ptr = function();
	*ptr = 5;
	return 0;
}
int* function() {
    int local = 0;非静态
	return &local;-->错误的返回值
}
错误的例子*/



//指针类型的函数
/*int main() {
	int array[10];//主函数定义的数组
	int* search(int* a, int num);
	for (int i = 0; i < 10; i++)
		cin >> array[i];
	int* zeroptr = search(array, 10);//将主函数中数组的首地址传给子函数
	return 0;
}
int* search(int* a, int num){//指针a指向主函数中定义的数组
	for (int i = 0; i < num; i++)
		if (a[i] == 0)
			return &a[i];//返回的地址指向的元素实在主函数中定义的
}*/

//指向函数的指针
int compute(int a, int b, int (*fun)(int , int )) {
	return fun(a, b);
	}
int max(int a, int b) {
	return((a > b) ? a : b);
}
int min(int a, int b) {
	return((a < b) ? a : b);
}
int sum(int a, int b) {
	return a + b;
}
int main() {
	int a, b, result;
	cin >> a >> b;
	result = compute(a, b, &max);
	cout << result << "  ";
	result = compute(a, b, &min);
	cout << result<<"  ";
	result = compute(a, b, &sum);
	cout << result;


	//指针做为函数参数
	void fun1(double x, int* str1, double* str2);
	void fun2(double x, int& A, double& B);
	//指针作为函数参数，与引用的对比
	double x, y, p, t;
	int a, b;
	cin >> x >> p;
	fun1(x, &a, &y);
	cout << a << " " << y << endl;
	fun2(p, b, t);
	cout << b << " " << t;
	//差不多。。。。目前。
}


void fun1(double x, int* str1, double* str2) {
	*str1 = int(x);
	*str2 = x - *str1;
}
void fun2(double x, int& A, double& B) {
	A = int(x);
	B = x - A;
}
