#include<iostream>
#include"基类.h"
#include"派生类.h"
using namespace std;
int main() {
	motorcycle a(1000, 2.4, 2, 4);
	/*protected派生，不可访问
	a.Run();
	a.Stop();*/
	a.show();
}