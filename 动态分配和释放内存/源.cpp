#include<iostream>
using namespace std;
class point {
	int x;
	int y;
public:
	point(int a, int b) :x(a), y(b) {
		cout << "constructor called" << endl;
	}
	point() :x(0), y(0) {
		cout << "default constructor called" <<endl;
	}
	void move(int a, int b) {
		x = a;
		y = b;
	}
	int getx()const { return x; }
	int gety()const { return y; }
};
int main() {

	point* ptr = new point[2];
	ptr[0].move(5, 10);
	ptr[1].move(12, 20);
	cout << ptr[1].getx()<< endl;
	cout << (ptr+1)->getx()<< endl;
	cout << "deleting..." << endl;
	delete[]ptr;
	//动态多维数组
	int (*cp)[9][8] = new int[7][9][8];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 8; k++)
				*(*(*(cp + i) + j) + k) = (i * 100 + j * 10 + k);
			
		}
	}
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 8; k++)
				cout << cp[i][j][k] << "  ";
			cout << endl;
		}
		cout << endl;
	}
	delete[]cp;
	return 0;
}