// Reverse the digits of a positive integer
// while

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // �N Max �]�� 100
	char num[Max];          // �]�@�� array
	int i = 0;              // ��l�ܼ� i �� 0
	int len;                // �p�� array ����

	cout << "Enter a positive integer : ";   // ��J�Ʀr
	cin >> num;

	len = strlen(num);                       // �p�� array ����

	i = len-1;

	while (i >= 0)
	{
		cout << num[i];                      //�q�̫᭱�}�l�˵ۿ�X
		i--;
	}

	cout << endl;

	system("pause");
	return 0;
}