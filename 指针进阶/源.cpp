#include<iostream>
using namespace std;
/*int main() {
	int* function();
	int* ptr = function();
	*ptr = 5;
	return 0;
}
int* function() {
    int local = 0;�Ǿ�̬
	return &local;-->����ķ���ֵ
}
���������*/



//ָ�����͵ĺ���
/*int main() {
	int array[10];//���������������
	int* search(int* a, int num);
	for (int i = 0; i < 10; i++)
		cin >> array[i];
	int* zeroptr = search(array, 10);//����������������׵�ַ�����Ӻ���
	return 0;
}
int* search(int* a, int num){//ָ��aָ���������ж��������
	for (int i = 0; i < num; i++)
		if (a[i] == 0)
			return &a[i];//���صĵ�ַָ���Ԫ��ʵ���������ж����
}*/

//ָ������ָ��
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


	//ָ����Ϊ��������
	void fun1(double x, int* str1, double* str2);
	void fun2(double x, int& A, double& B);
	//ָ����Ϊ���������������õĶԱ�
	double x, y, p, t;
	int a, b;
	cin >> x >> p;
	fun1(x, &a, &y);
	cout << a << " " << y << endl;
	fun2(p, b, t);
	cout << b << " " << t;
	//��ࡣ������Ŀǰ��
}


void fun1(double x, int* str1, double* str2) {
	*str1 = int(x);
	*str2 = x - *str1;
}
void fun2(double x, int& A, double& B) {
	A = int(x);
	B = x - A;
}
