#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
using namespace std;
//将来自输入迭代器的n个T类型的数值排序，结果通过输出迭代器result输出
template<class T,class InputIterator,class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	vector<T> s;
	for (; first != last; ++first)
		s.push_back(*first);
	//对s进行排序，sort函数的参数必须是随机访问迭代器
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);//将s序列通过输出迭代器输出
}

double square(double x) {
	return x * x;
}
int main() {
	double a[5] = { 1.2,2.4,0.3,5.6,4.7 };
	mySort<double>(a, a + 5, ostream_iterator<double>(cout, "\t"));
	cout << endl;
	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, "   "));
	//cout << endl;

	transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, "\t"),square);
	cout << endl;
	return 0;
}