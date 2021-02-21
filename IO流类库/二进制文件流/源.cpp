#include<fstream>
using namespace std;
struct Date {
	int mon,day, year;
};
int main() {
	Date dt{ 6,12,20 };
	ofstream file("D:\\location\\date.dat", ios_base::binary);
	file.write(reinterpret_cast<char*>(&dt), sizeof(dt));
	file << 12 << endl;
	file.close();
	return 0;
}