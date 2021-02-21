#include<iostream>//骰子问题！
#include<cstdlib>
using namespace std;
enum class gamestatus{win,lose,playing};
int main() {
	int sum, mypoint;
	gamestatus status;
	unsigned seed;
	int rolldice();
	cout << "please enter an unsigend integer:";
	cin >> seed;
	srand(seed);
	sum = rolldice();
	switch(sum) {
	case(7):
	case(11):
		status = gamestatus::win;
		break;
	case(2):
	case(3):
	case(12):
		status = gamestatus::lose;
		break;
	default:
		status = gamestatus::playing;
		mypoint = sum;
		cout << "my point is " << mypoint << endl;
		break;
	}
	while (status == gamestatus::playing) {
		sum = rolldice();
		if (sum == mypoint)
			status = gamestatus::win;
		if (sum == 7)
			status = gamestatus::lose;
	}
	if (status == gamestatus::win)
		cout << "YOU WIN" << endl;
	else
		cout << "YOU LOSE" << endl;

	return 0;
}
int rolldice() {
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	int sum = die1 + die2;
	cout << "玩家骰出" << die1 << "+" << die2 << "=" << sum << endl;
	return sum;
}