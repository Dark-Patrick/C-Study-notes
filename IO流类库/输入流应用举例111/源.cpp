#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main() {
	//��seekg��������λ��ָ��
	int values[] = { 3,7,0,9,6 };
	ofstream os("D:\\location\\integers", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char*>(values), sizeof(values));
	os.close();
	
	ifstream is("D:\\location\\integers", ios_base::in | ios_base::binary);
	if (is) {
		is.seekg(3 * sizeof(int));//�ƶ���ָ����ֽ�����������sizeof(int),Խ������int����
		int v;
		is.read(reinterpret_cast<char*>(&v), sizeof(int));
		cout << "The 4th integer in the file 'intergers' is " << v << endl;
	}
	else cout << "ERROR: Cannot open file 'intergers'" << endl;
	is.close();

	//��һ���ļ�����ʾ������0Ԫ�ص�λ��
	//cout << sizeof(int) << endl;
	ifstream file("D:\\location\\integers", ios_base::in | ios_base::binary);
	if (file) {
		while (file) {//�����ļ�βfileΪ0
			streampos here = file.tellg();
			int v;
			file.read(reinterpret_cast<char*>(&v), sizeof(int));
			//read�����ڶ�ȡ����ʱ���ƶ�ָ�룬�������ƶ�����
			if (file&&v == 0)//�ļ�û�н�������v==0
				cout << "Position " << here << " is 0" << endl;
		}
	}
	else cout << "ERROR: Cannot open file 'intergers'" << endl;
	file.close();
	return 10086;
}