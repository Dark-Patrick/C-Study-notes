#include<iostream>
using namespace std;
class CException {
public:
	CException() {}
	virtual ~CException(){}//һ������ܻᱻ�̳У�������������ü���virtual����������ڴ�й©����
	void Reason() { cout << "CEexception" << endl; }
};
void funi() {
	throw CException();//�׳��쳣
}
double fun2(double a, double b) {
	if (b == 0)
		throw a;
	else
		return a / b;
}
int main() {
	double a, b;
	cin >> a >> b;
	try {
		cout << fun2(a, b) << endl;
		funi();
	}
	catch (CException & ce) {//�����쳣
		ce.Reason();
	}
	catch (double a) {
		cout << "error!b=0..." << endl;
	}
	
	return 0;
}
//ʵ����ʼ��