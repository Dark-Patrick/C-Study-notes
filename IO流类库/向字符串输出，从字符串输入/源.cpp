#include<iostream>
#include<sstream>
#include<string>
using namespace std;
//向字符串输出
template<class T>
inline string tostring(const T& v) {
	ostringstream os;//创建字符串输出流
	os << v;//将变量v的值写入字符串流
	return os.str();//返回输出流生成的字符串
}//此函数模板可以将各种支持“<<“插入符的类型对象转换为字符串

//从字符串输入
template<class T>
inline T fromString(const string& str) {
	istringstream is(str);//创建字符串输入流
	T v;
	is >> v;//从字符串输入流中读取变量v
	return v;//返回变量v
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