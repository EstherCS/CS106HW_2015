// perfect number ( �Ʀr�������Ҧ��]�ư��h�ۤv�[�_�Ӫ��`�X )

#include <iostream>
using namespace std;

int main()
{
	int digit;
	int num;
	int i, j;
	int sum;

	cout << "Enter a positive integer : ";  // ��J�@�ӼƦr�ӭ��w�d��
	cin >> digit;

	cout << "Perfect numbers between 1 and " << digit << " : " << endl;

	for (num = 1; num <= digit; num++)
	{
		sum = 0;                           // sum �C���������k 0 
		for (i = 1; i < num; i++)          // ���d�򤺨C�@�Ʀr���]�ƥH�έp���`�X
		{
			if (num % i == 0)             
			{
				sum = sum + i;
			}
		}
		if (sum == num)                   // �Y�]���`�X���Ʀr�����A�h��X
		{
			cout << num << " = 1";
			for (i = 2; i < num; i++)
			{
				if (num % i == 0)
				{
					cout << " + ";
					cout << i;
				}
				
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}