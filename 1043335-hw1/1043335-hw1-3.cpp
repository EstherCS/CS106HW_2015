// 1043335-hw1-3
// �N����Ƥ��}

#include <iostream>
using namespace std;

int main()
{
	// �]�w�ܼ�
	int num;
	int one, two, three, four, five;

	//��J�@�Ӥ����
	cout << "Enter a five-digit integer :";
	cin >> num;

	// �N����Ʃ�ӧO�Ʀr
	one = num / 10000;
	two = num / 1000 % 10;
	three = num / 100 % 10;
	four = num / 10 % 10;
	five = num % 10;

	// �L�X�ӧO�Ʀr
	cout << one;
	cout << "   " << two;
	cout << "   " << three;
	cout << "   " << four;
	cout << "   " << five << endl;

	system("pause");
	return 0;
}
