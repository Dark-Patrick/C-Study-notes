#include<iostream>
#include<string>
using namespace std;

inline void test(const char* title, bool value) {
	cout << title << "  "<<"rerurns"
		<< (value ? "true" : "false") << endl;
}


char* link( char* a,  char* b) {
	int m=0, n=0;
	while (a[m] != '\0')
		m++;
	while (b[n] != '\0')
		n++;
	char* c = new char[n + m + 1];
	for (int i = 0; i < m; i++)
		c[i] = a[i];
	for (int j = m; j < m + n; j++)
		c[j] = b[j - m];
	//c[m + n] = '\0';
	return c;
}
int main() {
	string s1 = "DEF";
	cout << "s1 is" << s1 << endl;
	string s2;
	cout << "Please enter s2:";
	cin >> s2;
	cout << "length of s2 :" << s2.length() << endl;
	test("s1<=\"DEF\"", s1 <= "ABC");
	test("\"DEF\"<=s1", "EDF" <= s1);
	s2 += s1;
	cout << "s2=s2+s1" << s2 << endl;
	cout << "length of s2" <<"  "<< s2.length() << endl;


	char a[] = "adecd";
	char b[] = "adfeadg";
	cout << link(a, b) << endl;
	//cout<<link("adfa","afda")  函数形参是const char时的用法
}