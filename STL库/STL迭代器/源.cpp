#include<algorithm>
#include<iterator>
#include<vector>
#include<iostream>
using namespace std;
//�����������������n��T���͵���ֵ���򣬽��ͨ�����������result���
template<class T,class InputIterator,class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
	vector<T> s;
	for (; first != last; ++first)
		s.push_back(*first);
	//��s��������sort�����Ĳ���������������ʵ�����
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);//��s����ͨ��������������
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