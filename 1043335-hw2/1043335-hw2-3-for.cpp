// Reverse the digits of a positive integer
// for

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // �N Max �]�� 100
	char num[Max];          // �]�@�� array
	int i = 0;              // ��l�ܼ� i �� 0
	int len;                // �p�� array ����

	cout << "Enter a positive integer : ";  // ��J�Ʀr
	cin >> num;

	len = strlen(num);                      // �p�� array ����

	for (i = len - 1; i >= 0; i--)
	{
		cout << num[i];                     // �q�̫᭱�}�l�˵ۿ�X
	}

	cout << endl;


	system("pause");
	return 0;
}


/*

for (i = 0; i < Max; i++)
{
str[i] = 0;
}

len = strlen(num);

for (i = 0; i < len; i++)
{
str[i] = num[i] ;
}

for (i = len - 1; i >= 0; i--)
{
cout << str[i];
}

cout << endl;
*/