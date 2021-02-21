#include<iostream>
using namespace std;
int main() {
	int a[100], b[100], c[100];
	int n, m, count = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++) {
		int sgin = 0;
		for (int j = 0; j < m; j++)
			if (a[i] == b[j]) {

				for (int x = 0; x < count; x++)
					if (a[i] == c[x])
						sgin = 1;
				if (sgin == 0)
				{
					c[count] = a[i];
					count++;
				}

			}
	}
	for (int i = 0; i < count; i++)
		cout << c[i] << " ";
	cout << endl;
	return 0;
}