// Compute all positive factors of a positive integer
//while

#include <iostream>
using namespace std;

int main()
{
	int num;      // ��J���Ʀr
	int i = 1;    // �ܼ�

	cout << "Enter a positive integer : ";  // ��J�Ʀr
	cin >> num;


	cout << "The positive factors of " << num << endl;

	while (i <= num)
	{
		if (num % i == 0)        	// �p��O�_���]��
		{
			cout << i << endl;      // �L�X���G
		}
		i++;
	}
	

	system("pause");
	return 0;
}