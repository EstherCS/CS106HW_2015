// Compute all positive factors of a positive integer
// for

#include <iostream>
using namespace std;

int main()
{
	int num;  // ��J���Ʀr
	int i;    // �ܼ�

	cout << "Enter a positive integer : ";  // ��J�Ʀr
	cin >> num;


	cout << "The positive factors of " << num << endl;
	for (i = 1; i <= num; i++)
	{
		if (num % i == 0)        	// �p��O�_���]��
		{
			cout << i << endl;      // �L�X���G
		}
	}

	system("pause");
	return 0;
}