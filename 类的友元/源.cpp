#include<iostream>
#include<cmath>
using namespace std;
class point {
public:
	point(int x, int y): x(x), y(y) {}
	int getx() { return x; }
	int gety() { return y; }
	friend double dist( const point& a, const point& b);//&的作用：传参数，不传值
private:
	int x, y;

};
double dist(const point& a, const point& b) {
	//a.x = 10;
	//b.x = 10;const 不可改变参数
	double x = a.x - b.x;
	double y = a.y - b.y;
	
	return sqrt(x * x + y * y);
}
int main() {
	point p1(1, 1), p2(4, 5);
	cout << "The distance is ";
	cout << dist(p1, p2) << endl;
	cout << p1.getx << endl;
	return 0;
}