//  Finds the two largest values among several integers

#include <iostream>
using namespace std;

int main()
{
	int num[100];      // array
	int first;         // �έp���X�ӼƦr
	int i;             // �ܼ�
	int Max, Sec;      // �̤j�ȤβĤG�j��

	cout << "Enter the number of integers to be processed followed by the integers : ";  
	cout << endl;
	cin >> first;   // ��J�@���X�ӼƦr

	// ��J�Ʀr
	for (i = 0; i < first; i++)
	{
		cin >> num[i];
	}

	

	Max = 0;    // �]�w��l�Ȭ� 0
	Sec = 0;    // �]�w��l�Ȭ� 0

	
	// �ϥ� array �ӴM��̤j��
	for(i = 0; i < first; i++)
	{
		if (num[i] > Max)
		{
			Max = num[i];
		}
	}

	// �ϥ� array �ӧ�X�ĤG�j����
	for(i = 0; i < first; i++)
	{
		if (num[i] != Max)     // ���h�̤j�ȥH�~���Ʀr�����
		{
			if (num[i] > Sec)
			{
				Sec = num[i];
			}
		}
	}

	cout << "Largest is " << Max << endl;           // ��X�̤j��
	cout << "Second largest is " << Sec << endl;    // ��X�ĤG�j��



	system("pause");
	return 0;

}