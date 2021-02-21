#include<iostream>
#include<cstdlib>
using namespace std;
struct Student {
	int id;
	float gpa;
};
template <class T>
class Store {//��ģ�壺ʵ�ֶ������������ݽ��д�ȡ
	T item;
	bool havevalue;
public:
	Store();
	T getElem();
	void putElem(const T& x);

};
template<class T>
Store<T>::Store():havevalue(false){}

template<class T>
T  Store<T>::getElem() {
	if (!havevalue) {
		cout << "No item present!" << endl;
		exit(1);//ʹ������ȫ�˳������ص�����ϵͳ
	}
	return item;
}
template<class T>
void Store<T>::putElem(const T& x) {

	havevalue = true;
	item = x;
}
int main() {
	Store<int>s1, s2;
	s1.putElem(3);
	s2.putElem(-7);
	cout << s1.getElem() << "  " << s2.getElem() << endl;

	Student g = { 1000,23 };
	Store<Student>s3;
	s3.putElem(g);
	cout << s3.getElem().id << endl;

}