// 1043335-hw1-2
// �P�_�_��

#include <iostream>
using namespace std;

int main()
{
	// �]�w�ܼ�
	int num;

	// ��J�Ʀr
	cout << "Enter an interger :";
	cin >> num;

	// �P�_�Ʀr�O�_�� 2 ������
	if (num % 2 == 0)
	{
		cout << "The interger " << num << " is even." << endl;
	}
	else
	{
		cout << "The interger " << num << " is odd." << endl;
	}

	system("pause");
	return 0;
}