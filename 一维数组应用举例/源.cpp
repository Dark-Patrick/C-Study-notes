#include<iostream>
using namespace std;
int main() {
	const char key[] = { 'a','c','b','a','d' };
	const int NUM_QUES = 5;
	char c;
	int ques = 0, numcorrect = 0;
	cout << "enter the" << NUM_QUES << "questions tests" << endl;
	while (cin.get(c)) {
		if (c != '\n') {
			if (c == key[ques]) {
				numcorrect++;
				cout << "T";
			}
			else
				cout << "F";
			ques++;
		}
		else{
			cout << "Score" << double(numcorrect) / NUM_QUES * 100 << "%" << endl;
			ques = 0, numcorrect = 0;

		}
	}
	return 0;
}