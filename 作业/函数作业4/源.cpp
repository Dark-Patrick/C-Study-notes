/*��������������°ͺղ���ָ�����κ�һ����С��6��ż�������Ա�ʾΪ��������֮�͡����磺6 = 3 + 3 8 = 3 + 5 �� 50 = 3 + 47���Ӽ�������n��n >= 6��Ϊż�����������Ӧ�ı��ʽ����д�����ж�һ�����Ƿ�Ϊ������Ҫ�����������������������ɡ�

��������ʽ��һ����

�������ʽ�����������������֮�͵���ʽ���������������ǵ�һ���������������������ʽ�м䲻�����ո񣩡�

���������롿8

�����������8 = 3 + 5
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
