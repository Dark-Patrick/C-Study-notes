#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
/*
-��˾��Ƹʮ��Ա����ABCDEFGHIJ)��ʮ��Ա�����빫˾����ָ��Ա�����ĸ����Ź���
-Ա����Ϣ�У�����   ���ʣ����ŷ�Ϊ���߻����������з�
-�����Ա�����䲿�ź͹���
-ͨ��multimap������Ϣ�Ĳ���  key�����ű�ţ� value��Ա����
-�ֲ�����ʾԱ����Ϣ
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
		string name = "Ա��";
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
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::iterator pos = m.find(1);
	int count = m.count(1);
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) 
		cout << setiosflags(ios_base::left) << setw(5) << "������" 
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name 
		<< setiosflags(ios_base::left) << setw(5) <<"���ʣ�"
		<< setiosflags(ios_base::left) << setw(10) << pos->second.m_salary << endl;
	cout << "-----------------------------------" << endl;

	cout << "�������ţ�" << endl;
     pos = m.find(2);
	 count = m.count(2);
	 index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << setiosflags(ios_base::left) << setw(5) << "������"
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name
		<< setiosflags(ios_base::left) << setw(5) << "���ʣ�"
		<< setiosflags(ios_base::left) << setw(10) << pos->second.m_salary << endl;
	cout << "-----------------------------------" << endl;

	cout << "�з����ţ�" << endl;
	 pos = m.find(3);
	 count = m.count(3);
	 index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
		cout << setiosflags(ios_base::left) << setw(5) << "������"
		<< setiosflags(ios_base::left) << setw(10) << (*pos).second.m_name
		<< setiosflags(ios_base::left) << setw(5) << "���ʣ�"
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