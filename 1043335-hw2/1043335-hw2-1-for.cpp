// Convert a binary number to its decimal equivalent.
// for

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // �N Max �]�� 100
	char num[Max];          // �]�@�� array
	int len;                // �p�� array ����
	int i;                  // �ܼ�
	bool Check = 1;         // �ˬd��J

	cout << "Enter a positive binary integer : ";  //  ��J�G�i��
	cin >> num;

	len = strlen(num);                             // �p�� array ����
	
	// �ˬd��J�O�_���G�i��
	for (i = 0; i < len; i++)
	{
		if (num[i] != '0' && num[i] != '1')
		{
			cout << "Error!" << endl;
			Check = 0;
		}
	}
	
	if (Check == 1)
	{
		int power2 = 1;         // �p�� 2 ������B����....  ��l�� 2^0 = 1
		int sum = 0;            // �`�M

		for (i = len - 1; i >= 0; i--)
		{
			sum = sum + (num[i] - '0') * power2;   // �p���`�M
			power2 = power2 * 2;                   // 2 ���s��
		}

		cout << "The decimal equivalent of " << num << " is " << sum << endl;  // ��X���G
	}

	system("pause");
	return 0;
}