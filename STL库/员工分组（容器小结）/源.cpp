#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
/*
-公司招聘十名员工（ABCDEFGHIJ)。十名员工进入公司后，需指派员工在哪个部门工作
-员工信息有：姓名   工资；部门分为：策划，美术，研发
-随机给员工分配部门和工资
-通过multimap进行信息的插入  key（部门编号） value（员工）
-分部门显示员工信息
*/

class Worker {
public:
	string m_name;
	int m_salary;

	Worker(string name, int salary) :m_name(name), m_salary(salary) {}

};

void CrateWorker(vector<Worker>& v) {
	srand((unsigned int)time(NULL));
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		string name = "员工";
		name += nameseed[i];
		int salary = rand() % 10000 + 10000;
		Worker worker(name, salary);
		v.push_back(worker);
	}
}

void setGroup(vector<Worker>& v,multimap<int,Worker>&m ){
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++) {
		int dept = rand() % 3 + 1;
		m.insert(make_pair(dept, *it));
	}
}
void showWorker(multimap<int, Worker>& m) {
	cout << "策划部门：" << endl;
	multimap<int, Worker>::iterator pos = m.find(1);
	int count = m.count(1);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) 
		cout << setiosflags(ios_base::left) << setw(5) << "姓名：" 
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name 
		<< setiosflags(ios_base::left) << setw(5) <<"工资："
		<< setiosflags(ios_base::left) << setw(10) << pos->second.m_salary << endl;
	cout << "-----------------------------------" << endl;

	cout << "美术部门：" << endl;
     pos = m.find(2);
	 count = m.count(2);
	 index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << setiosflags(ios_base::left) << setw(5) << "姓名："
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name
		<< setiosflags(ios_base::left) << setw(5) << "工资："
		<< setiosflags(ios_base::left) << setw(10) << pos->second.m_salary << endl;
	cout << "-----------------------------------" << endl;

	cout << "研发部门：" << endl;
	 pos = m.find(3);
	 count = m.count(3);
	 index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << setiosflags(ios_base::left) << setw(5) << "姓名："
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name
		<< setiosflags(ios_base::left) << setw(5) << "工资："
		<< setiosflags(ios_base::left) << setw(10) << pos->second.m_salary << endl;
}
int main() {
	vector<Worker>vWorker;
	CrateWorker(vWorker);

	multimap<int, Worker>mWorker;
	setGroup(vWorker,mWorker);
	showWorker(mWorker);
	return 0;

}