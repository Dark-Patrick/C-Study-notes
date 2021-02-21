#include<iostream>
#include<list>
#include<deque>
#include<iterator>
using namespace std;
template<class T>
void printcontanier(const char* msg, const T& s) {
	cout << msg << "  ";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, "  "));
		cout << endl;
}
int main() {
	deque<int>s;//˫�˶���
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);//�������룬�Ƚ����
	}

	printcontanier("deque at first", s);
	list<int>l(s.rbegin(), s.rend());//��s���������ݵ��������б�����
	printcontanier("list at first", l);
	list<int>::iterator iter = l.begin();
	while (iter != l.end()) {
		int v = *iter;
		iter = l.erase(iter);
		cout << *iter << endl;
		l.insert(++iter, v);
	}
	printcontanier("list at last", l);
	s.assign(l.begin(), l.end());
	printcontanier("deque at last", s);
	return 0;
}
/*1.1 insert����
c.insert(p, t) �ڵ�����p��ָ���Ԫ��ǰ�����ֵΪt����Ԫ�ء�����ָ�������Ԫ�صĵ�����
Ϊʲô����ǰ�濴������Ϊ����������ָ�򳬳�ĩ�˵���һλ�ã�������ڸõ������ĺ������Ԫ�أ������δ�������Ϊ��������ڵ�������ǰ�����Ԫ�ء�

1.2 erase����
c.erase��ɾ��������p��ָ���Ԫ�أ�����һ������������ָ��ɾ��Ԫ�غ����Ԫ��*/
	