// ��J�Ҧ��Ʀr���M ( �Ӧ� )

#include <iostream>
using namespace std;

int g(int a);   // ��ơA�p��Ʀr�ۥ[

int main()
{
	int num;
	int result;

	cout << "Enter a positive integer : "; // ��J�Ʀr

	while (cin >> num)
	{
		if (num == 0)                      // �ˬd��J�Ʀr�O�_�����ļƦr
		{
			cout << "Error";
			break;
		}
		else
		{
			result = g(num);               // �Q�Ψ�ƺ�X���G
			cout << result << endl;
		}
		break;
	}

	system("pause");
	return 0;
}

int g(int a)
{
	if (a < 10)                            // �i�Ӫ��Ʀr�p�� 10�A�|�Ǧ^���Ʀr
	{
		return a;
	}

	int temp = a;                          // ���w��temp��
	int sum = 0;                           // �`�X�� 0

	while (temp > 0)                       // �}�l�p��Ʀr�ۥ[
	{
		sum = sum + (temp % 10);
		temp = temp / 10;
	}
	return g(sum);                         // �A���i�J����ƪ����`�M���Ӧ��
}