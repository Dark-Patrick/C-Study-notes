#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
using namespace std;
class Person {
public:
	Person(){}
	Person(string name,int age):m_name(name),m_age(age){}
	string m_name;
	int m_age;

	
};
bool Age(Person p1) {
	return p1.m_age == 20;
}

void text() {
	vector<Person>v;
	Person people1("aaa", 20);
	Person people2("bbb", 30);
	Person people3("ccc", 20);
	Person people4("ddd", 40);
	Person people5("eee", 10);
	Person people6("fff", 20);
	v.push_back(people1);
	v.push_back(people2);
	v.push_back(people3);
	v.push_back(people4);
	v.push_back(people5);
	v.push_back(people6);
	cout<<count_if(v.begin(), v.end(), Age);//error
}
int main() {
	text();
}