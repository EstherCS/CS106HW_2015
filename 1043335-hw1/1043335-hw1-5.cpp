// 1043335-hw1-5
// �P�_���~�|�~

#include <iostream>
using namespace std;

int main()
{
	// �]�w�ܼ�
	int year;
	int IsLeap;

	// ��J�~��
	cout << "Enter a year ( 1583 - 3000 ) : ";
	cin >> year;

	// �]�w��l���_
	IsLeap = 0;

	// (1) ��Q 4 �㰣�H�Τ���Q 100 �㰣
	// (2) ��Q 400 �㰣

	if ((year % 4 == 0 && year % 100 != 0) ||   // (1)
		(year % 400 == 0))                      // (2)
	{
		IsLeap = 1;
	}

	// �P�_�O�_���|�~
	if (IsLeap)
	{
		cout << year << " is a leap year." << endl;
	}
	else
	{
		cout << year << " is a common year." << endl;
	}

	system("pause");
	return 0;
}