#include<iostream>
using namespace std;
int main() {
	char a[100];
	cin >> a;
	
	int i = 0;
	while (a[i]!='\0') {
		if (a[i] >= 65 && a[i] <= 86 || a[i] >= 97 && a[i] <= 118)
			a[i] += 4;
		else if (a[i] >= 87 && a[i] <= 90 || a[i] >= 119 && a[i] <= 122)
			a[i] -= 22;
		i++;
	}
	 cout << a << endl;
	 return 0;
}