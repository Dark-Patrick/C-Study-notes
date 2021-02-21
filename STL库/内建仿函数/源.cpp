#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
//自行实现仿函数部分功能
class people {
public:
	int m_age;
	int m_height;
};

template<class T>
class total {
public:
	T operator()(const T &n,const T& m)const {
		return n + m;
	}
};

void text01() {
	total<int>t;
	cout << t(10, 20) << endl;
	people people01,people02;
	people01.m_age = 20;
	people02.m_age = 30;
	cout <<"自定义类型: "<< t(people01.m_age, people02.m_age) << endl;
	cout << endl << "-------------------------" << endl;
}
//直接用STL仿函数
void text02() {
	//一元算数仿函数
	negate<int>n;
	cout<<n(50)<<endl;//取反
}

void print(bool b) {
	cout << b << " ";
}

int newplus(int val) {
	return (val) +10;
}

void text03() {
	vector<bool>v,v2,v3;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	v2.resize(v.size());
	v3.resize(v.size());


	for_each(v.begin(), v.end(), print);//遍历算法其一
	cout << endl << "-------------------------" << endl;
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//遍历算法其二

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
		cout << *it << " ";
	cout << endl;
	cout<<binary_search(v.begin(), v.end(), true);
}

void text04() {
	cout << endl << "-------------------------" << endl;
	vector<int>v, v2;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	v2.resize(v.size());
	
	transform(v.begin(), v.end(), v2.begin(), newplus);
	for_each(v2.begin(), v2.end(), print);

}
int main() {
	text01();
	text02();
	text03();
	text04();
	return 0;
}