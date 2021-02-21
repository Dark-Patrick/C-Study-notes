#include<iostream>__msvc_all_public_headers.hpp
#include"client.h"
using namespace std;
int main() {
	Employee e("wang dachui", "haidian", "beijing", "100084");
	e.display();
	e.change_name("Li San");
	e.display();
	Employee a[5], * emp = 0;
	a[1].setaddress("beijing");
	a[1].display();
	emp = new Employee("Wang dachui", "hengshui","hebei", "10086");
	a[2] = *emp;
	delete[]emp;
	a[2].display();
	return 0;
}