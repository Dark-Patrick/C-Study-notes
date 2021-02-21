#include<iostream>
#include<stack>
#include<iterator>
#include<string>
#include<queue>
#include<time.h>
using namespace std;
/*
int main() {
	stack<char> s;
	string str;
	cin >> str;
	for (string::iterator iter = str.begin(); iter != str.end(); iter++)
		s.push(*iter);
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}
*/
//模拟细胞分裂
const int SPLIT_TIME_MIN = 500;
const int SPLIT_TIME_MAX = 2000;
class Cell;
priority_queue<Cell> cellQueue;

class Cell {
private:
	static int count;
	int id;
	int time;
public:
	Cell(int brith) :id(count++) {
		time = brith + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
	}
	int getid()const { return id; }
	int getSplitTime()const { return time; }
	bool operator < (const Cell & s)const { return time > s.time; }
	void split()const {
		Cell child1(time), child2(time);
		cout << time << "s: cell# " << id << " splits to:" << child1.getid() << "and " << child2.getid() << endl;
		cellQueue.push(child1);
		cellQueue.push(child2);

	}
};
int Cell::count = 0;
int main() {
	srand(static_cast<unsigned>(time(0)));//取系统时间
	int t;
	cout << "Simulation time:";
	cin >> t;
	cellQueue.push(Cell(0));
	while (cellQueue.top().getSplitTime() <= t) {
		cellQueue.top().split();
		cellQueue.pop();
	}
	return 0;
}