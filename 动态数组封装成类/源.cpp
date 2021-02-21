#include<iostream>
#include<cassert>
#include<vector>
using namespace std;
class point {
	
	int x;
	int y;
public:
	point(int a, int b) :x(a), y(b) {
		cout << "constructor called" << endl;
	}
	point():x(0),y(0){
		cout << "default constructor called" << endl;
	}
	void move(int a, int b) {
		x = a;
		y = b;
		cout << "move" << endl;
	}
	
	int getx()const { return x; }
	int gety()const { return y; }
};
class Arrayofpoints {
public:
	Arrayofpoints(int size) :size(size) {
		points = new point[size];
	}
	Arrayofpoints() :size(0) {
		points = new point[size];
	}
	~Arrayofpoints()
	{
		cout << "deleting..." << endl;
		delete[]points;
	}
	/*point* element(int index) {
		assert(index >= 0 && index < size);
		return &points[index];
	}
	point& element(int index) {
		assert(index >= 0 && index < size);
		return points[index];
	}*/
	Arrayofpoints(const Arrayofpoints& v) {
		size = v.size;
		points = new point[size];
		for (int i = 0; i < size; i++)
			points[i] = v.points[i];//对象的深层复制
	}
	point& operator [](int n) {
		assert(n >= 0 && n <= size);
		return points[n];
	}//重载[]常函数
private:
	point* points;
	int size;
};


//vector类例题
double average(const vector<double> &arr) {//了解常引用的意义
	double sum = 0;
	for (unsigned i = 0; i < arr.size(); i++)
		sum += arr[i];
	return sum / arr.size();
}


int main() {
	int count;
	cout << "enter count of points";
	cin >> count;
	Arrayofpoints points(count);
	//points.element(0).move(5, 10);
	//points.element(1)->move(12, 20);
	cout << points[0].getx() << endl;
	Arrayofpoints points2(points);//复制构造函数
	points2[0].move(12, 30);
	cout << points2[0].getx()<<"  "
		 << points2[1].gety() << endl;
	
	
	
	//vector类，与动态封装比较
	unsigned n;
	cout << "n=";
	cin >> n;
	vector<double>arr(n);
	cout << "Please input " << n << "real numbers:" << endl;
	for (unsigned i = 0; i < n; i++)
		cin >> arr[i];
	cout << average(arr) << endl;

	//基于范围的for循环配合auto举例
	vector<int>v = { 1,2,3 };
	for (auto i = v.begin(); i != v.end(); i++)//auto自动定义为指针类型
		cout << *i << endl;
	for (auto e : v)
		cout << e << endl;//auto自动定义为int类
	return 0;
}
