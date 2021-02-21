#include<iostream>
using namespace std;
class point {
public:
	point(int newx, int newy) {
		x = newx;
		y = newy;
		output();
	};
	point();
	int add(int newx, int newy);
	void output();
	point(const point& p);
private:
	int x, y;
};
int point::add(int newx, int newy) {

	return x + y;
}
void point::output() {
	cout << add(x, y) << endl;
}
/*point::point(int newx, int newy) :x(newx), y(newy) {
	output();
}*/
point::point():x(0),y(0){}


point::point(const point& p) {
	x = p.y;
	y = p.x;
	cout << x <<"  "<<y;
	cout << "calling the copy constructer" << endl;
}
point fun2() {
	point a;
	return a;//函数的返回值是类的对象，函数返回时，调用复制
}
int main() {
	int a, b;
	cin >> a >> b;
	point mypoint(a, b);
	
	//mypoint.output();
	point mypoint2(mypoint);//情况1
	mypoint2.output();
	mypoint2 = fun2();
}
