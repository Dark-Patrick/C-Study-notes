#include<iostream>
#include<fstream>
using namespace std;
#define D(a) T<<#a<<endl; a
ofstream T("D:\\location\\output.put");
int main() {
	D(int i = 53;)
	D(double f = 4700113.154956;)
	char* s =(char*) "Is there any more?";
	D(T.setf(ios::unitbuf);)
	D(T.setf(ios::showbase);)
	D(T.setf(ios::uppercase);)
	D(T.setf(ios::showpos);)
	D(T << i << endl;)
	D(T.setf(ios::hex, ios::basefield);)
	D(T << i << endl;)
	D(T.unsetf(ios::uppercase);)
	D(T.setf(ios::oct, ios::basefield);)
	D(T << i << endl;)
	D(T.unsetf(ios::showbase);)
	D(T.setf(ios::dec, ios::basefield);)
	D(T.setf(ios::left, ios::adjustfield);)
	D(T.fill('0');)
	D(T << "fill char:" << T.fill() << endl;)
	D(T.width(8);)
	T << i << endl;
	D(T.setf(ios::right, ios::adjustfield);)
	D(T.width(8);)
	T << i << endl;
	D(T.setf(ios::internal, ios::adjustfield);)
	D(T.width(8);)
	T << i << endl;
	D(T << i << endl;)

	D(T.setf(ios::scientific, ios::floatfield);)
	D(T << endl << f << endl;)
	D(T.setf(ios::fixed, ios::floatfield);)
	D(T << f << endl;)
	D(T.setf(0, ios::floatfield);)
	D(T << f << endl;)

	D(T.width(8);)
	T << s << endl;
	D(T.width(36);)
	T << s << endl;
	D(T.setf(ios::left, ios::adjustfield);)
	D(T.width(36);)
	T << s << endl;
	D(T << "text text" << '/n' << "change line text" << endl;)
	D(T.unsetf(ios::showpoint);)
	D(T.unsetf(ios::unitbuf);)
	T.close();
	return 0;
}