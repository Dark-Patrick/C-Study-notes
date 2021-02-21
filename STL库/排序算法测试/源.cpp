#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class myplus {
public:
	int& operator()(int& val) {
		val *= 10;
		return val;
	}
};
void Myprint(int val) {
	cout << val <<" ";
}


void text() {
	vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myplus());
	for_each(v.begin(), v.end(), Myprint);
	cout << endl;
}
int main() {
	text();
}