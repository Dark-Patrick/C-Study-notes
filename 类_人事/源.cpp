#include<iostream>
#include<vector>
using namespace std;
enum class SEX:char{male,famle};
class date {
	int year;
	int month;
	int day;
public:
	date(int a, int b, int c) :year(a), month(b), day(c) {
		cout << "calling constructor-date" << endl;
	}
	date() :year(100), month(1), day(1) {
		cout << "calling default constructor-date" << endl;
	}
	inline void show() {
		cout << year << "/" << month << "/" << day << endl;
	}
	date(const date& d) {
		year = d.year;
		month = d.month;
		day = d.day;
		cout << "copy comstructor" << endl;
	}
	~date()
	{
		cout << "date-deleting..." << endl;
	}
};

class people {
	 char* name;
	char* number;
	SEX sex;
	date birthday;
	const char* id;
public:
	people( char* n,  char* nu, SEX sex, date a, char* id) :name(n), number(nu), sex(sex), birthday(a), id(id) {
		cout << "calling constructor-people" << endl;
	}
	people() {
		cout << "calling default constructor-people" << endl;
	}
	inline void output() {
		cout << name << "  " << number << "  " << id << "  " << static_cast<underlying_type<SEX>::type>(sex) << "  ";
			birthday.show();
	}
	people(const people& p) {
		name = p.name;
		number = p.number;
		sex = p.sex;
		birthday = p.birthday;
		id = p.id;
		cout << "copy comstructor" << endl;
	}
	~people()
	{
		cout << "people-deleting..." << endl;
	}
};
int main() {
	 int count;
	cout << "please enter the number of employees" << endl;
	cin >> count;
	vector<people>arr(count);
	for (int i = 0; i < arr.size(); i++) {
		int a, b, c;
		SEX s;
		people* ptr = 0;
		char name[7] = "Dachui", number[17] = "", id[17] = "";
		cout << "输入员工信息-姓名-  编号-  身份证号- 出生日期- 性别" << endl;
		cin >> name >> number >> id >> a >> b >> c ;
		date d(a, b, c);
		ptr = new people(name, number, SEX::male, d, id);
		arr[i] = *ptr;
		delete ptr;
	}
	arr[0].output();
}