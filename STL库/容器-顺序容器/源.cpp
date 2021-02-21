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
	deque<int>s;//双端队列
	for (int i = 0; i < 10; i++) {
		int x;
		cin >> x;
		s.push_front(x);//逆向输入，先进后出
	}

	printcontanier("deque at first", s);
	list<int>l(s.rbegin(), s.rend());//用s容器的内容的逆序构造列表容器
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
/*1.1 insert操作
c.insert(p, t) 在迭代器p所指向的元素前面插入值为t的新元素。返回指向新添加元素的迭代器
为什么是在前面看，是因为迭代器可以指向超出末端的下一位置，如果是在该迭代器的后面插入元素，则出现未定义的行为，因此是在迭代器的前面插入元素。

1.2 erase操作
c.erase§删除迭代器p所指向的元素，返回一个迭代器，它指向被删除元素后面的元素*/
	