#include<iostream>
#include<cstring>
using namespace std;
int main() {
	char a[100], b[100];
	int i, j, k = 0, n, m;
	cin >> a;
	for (i = 0; a[i] == '*'; i++)
		b[i] = a[i];
	n = i;

	for (j = strlen(a) - 1; a[j] == '*'; j--);
	m = j;

	for (j = n; j<=m; j++) {
		if (a[j] != '*') {
			b[i] = a[j];
			i++;
		}
	}

	for (j = m + 1; a[j] != '\0'; j++) {
		b[i] = a[j];
		i++;
	}
	b[i] = '\0';
	cout << b << endl;
	return 0;

}