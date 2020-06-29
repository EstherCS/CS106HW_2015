// 1043335-hw1-3
// 盢き计だ秨

#include <iostream>
using namespace std;

int main()
{
	// 砞﹚跑计
	int num;
	int one, two, three, four, five;

	//块き计
	cout << "Enter a five-digit integer :";
	cin >> num;

	// 盢き计╊Θ计
	one = num / 10000;
	two = num / 1000 % 10;
	three = num / 100 % 10;
	four = num / 10 % 10;
	five = num % 10;

	// 计
	cout << one;
	cout << "   " << two;
	cout << "   " << three;
	cout << "   " << four;
	cout << "   " << five << endl;

	system("pause");
	return 0;
}
