#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main() {
	//用seekg函数设置位置指针
	int values[] = { 3,7,0,9,6 };
	ofstream os("D:\\location\\integers", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char*>(values), sizeof(values));
	os.close();
	
	ifstream is("D:\\location\\integers", ios_base::in | ios_base::binary);
	if (is) {
		is.seekg(3 * sizeof(int));//移动读指针的字节数，三倍的sizeof(int),越过三个int数据
		int v;
		is.read(reinterpret_cast<char*>(&v), sizeof(int));
		cout << "The 4th integer in the file 'intergers' is " << v << endl;
	}
	else cout << "ERROR: Cannot open file 'intergers'" << endl;
	is.close();

	//读一个文件并显示出其中0元素的位置
	//cout << sizeof(int) << endl;
	ifstream file("D:\\location\\integers", ios_base::in | ios_base::binary);
	if (file) {
		while (file) {//读到文件尾file为0
			streampos here = file.tellg();
			int v;
			file.read(reinterpret_cast<char*>(&v), sizeof(int));
			//read函数在读取数据时会移动指针，读多书移动多少
			if (file&&v == 0)//文件没有结束并且v==0
				cout << "Position " << here << " is 0" << endl;
		}
	}
	else cout << "ERROR: Cannot open file 'intergers'" << endl;
	file.close();
	return 10086;
}