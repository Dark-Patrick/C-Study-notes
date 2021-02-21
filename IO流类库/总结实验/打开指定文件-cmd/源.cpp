#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char*argv[]) {
	ifstream in;
	in.open(argv[1], ios::binary);
	if (!in) {
		cout << "Cannot open file." << endl;
		return 1;
	}
	const int bsz = 1024;
	char buf[bsz];
	int line = 0;
	while (in.getline(buf, bsz)) {//buf字符数组（缓冲），bsz缓冲的大小/getiline一次所能读到的最大字符数
		cout << ++line << ":" << buf << endl;

	}
	return 0;
}