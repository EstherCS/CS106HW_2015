// 1043335-hw1-1
// �� Max �M Min

#include <iostream>
using namespace std;

int main()
{
	// �]�w�ܼ�
	int num1, num2, num3, num4, num5;
	int Max, Min;

	//��J���ӼƦr
	cout << "enter five intergers : ";
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	Max = num1; // �]�Ĥ@�ӼƦr�� Max
	Min = num1; // �]�Ĥ@�ӼƦr�� Min

	// �P�O���U�Ӫ� num2 ~ num5 �O�_�j�� Max �Τp�� Min
	if (num2 > Max)
	{
		Max = num2;
	}
	else if (num2 < Min)
	{
		Min = num2;
	}

	if (num3 > Max)
	{
		Max = num3;
	}
	else if (num3 < Min)
	{
		Min = num3;
	}

	if (num4 > Max)
	{
		Max = num4;
	}
	else if (num4 < Min)
	{
		Min = num4;
	}

	if (num5 > Max)
	{
		Max = num5;
	}
	else if (num5 < Min)
	{
		Min = num5;
	}

	// �L�X Max �M Min
	cout << "Largest is " << Max << endl;
	cout << "smallest is " << Min << endl;

	system("pause");
	return 0;
}