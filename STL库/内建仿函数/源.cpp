#include<iostream>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
//����ʵ�ַº������ֹ���
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
	cout <<"�Զ�������: "<< t(people01.m_age, people02.m_age) << endl;
	cout << endl << "-------------------------" << endl;
}
//ֱ����STL�º���
void text02() {
	//һԪ�����º���
	negate<int>n;
	cout<<n(50)<<endl;//ȡ��
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


	for_each(v.begin(), v.end(), print);//�����㷨��һ
	cout << endl << "-------------------------" << endl;
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//�����㷨���

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