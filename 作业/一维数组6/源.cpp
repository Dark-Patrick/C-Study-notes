#include<iostream>
using namespace std;
int main() {
	int a[100], n, key, count=1,b=0;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cin >> key;
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == a[mid]) {
			b = mid;
			cout << mid << '\n' << count << endl;
			break;
		}
		else if (key < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
		count++;
	}
	if (b == 0)
		cout << "no" << '\n' << count-1 << endl;
	return 0;
}
//ÉýÐòÊý×é²éÕÒ