#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//һԪν��
//�º���
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};
void text01() {
	vector<int>v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	vector<int>::iterator it=find_if(v.begin(), v.end(), GreaterFive());//�����ĺ�������GreaterFive����
	if (it != v.end())
		cout << "�ҵ��˴���5�����֣� " << *it << endl;
	else cout << "δ�ҵ������������" << endl;
}


//��Ԫν��
class Mycompare {
public:
	bool operator()(int val1, int val2) {
		return val1 > val2;
	}
};
void text02() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		srand(i);
		int temp = rand()%100+1;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(),Mycompare());
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
		cout << *it << " ";
	cout << endl;
}
int main() {
	text01();
	text02();
	return 0;
}
