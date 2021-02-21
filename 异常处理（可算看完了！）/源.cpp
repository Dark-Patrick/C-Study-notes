#include<iostream>
using namespace std;
class CException {
public:
	CException() {}
	virtual ~CException(){}//一个类可能会被继承，其析构函数最好加上virtual，避免出现内存泄漏问题
	void Reason() { cout << "CEexception" << endl; }
};
void funi() {
	throw CException();//抛出异常
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
	catch (CException & ce) {//捕获异常
		ce.Reason();
	}
	catch (double a) {
		cout << "error!b=0..." << endl;
	}
	
	return 0;
}
//实践开始！