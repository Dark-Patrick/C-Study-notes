#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//���ַ������
template<class T>
inline string tostring(const T& v) {
	ostringstream os;//�����ַ��������
	os << v;//������v��ֵд���ַ�����
	return os.str();//������������ɵ��ַ���
}//�˺���ģ����Խ�����֧�֡�<<������������Ͷ���ת��Ϊ�ַ���

//���ַ�������
template<class T>
inline T fromString(const string& str) {
	istringstream is(str);//�����ַ���������
	T v;
	is >> v;//���ַ����������ж�ȡ����v
	return v;//���ر���v
}
int main() {
	string str1 = tostring(5);
	cout << str1 << endl;
	string str2 = tostring(1.1);
	cout << str2 << endl;


	int v1 = fromString<int>("5");
	double v2 = fromString<double>("1.2");
	cout << v1 << " " << v2 << endl;
	return 0;
}