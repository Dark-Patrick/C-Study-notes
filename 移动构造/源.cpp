#include<iostream>
using namespace std;
class intnum {
	int* xptr;
public:
	intnum(int x = 0) :xptr(new int (x) ){
		cout << "calling constructor..." << endl;
	}
	intnum(const intnum& n) :xptr(new int(*n.xptr)) {
		cout << "calling copy constructor..." << endl;
	}
	intnum(intnum&& n) :xptr(n.xptr) {
		n.xptr = nullptr;
		cout << "calling move constructor..." << endl;//ÒÆ¶¯¹¹Ôì
	}
	~intnum()
	{
		delete xptr;
		cout << "destructing" << endl;
	}
	int getint() {
		return *xptr;
	}
};
intnum getnum() {
	intnum a;
	return a;
}
int main() {
	cout << getnum().getint() << endl;
	return 0;
}