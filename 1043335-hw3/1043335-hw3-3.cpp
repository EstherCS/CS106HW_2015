// �Ʀr��Ѧ��ⳡ�������謰���Ʀr���� ( 30 + 25 )^2 = 3025 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int digit;
	int num = 1;
	int i;
	int power;

	cout << "Enter the number of digits (taken from 2, 4, 6, 8 ) : "; // ��J��ơA�̦h��K���
	cin >> digit;

	for (i = 0; i < digit / 2; i++)                                   // �̦h�K��ơA�S�O��������ơA�̦h10000�� ( 9999 + 9999 = 19998 && 9999 * 9999���̤j�K��� )
	{
		num = num * 10;                                               // ����J��ƪ��̤j����
	}
	
	for (i = 0; i < num; i++)
	{
		power = i * i;                                                // �M�䧹������� 

		if ((power / num) + (power % num) == i)                       // ��������ƫe�b���� + ��b���� = ���Ʀr����
		{
			cout << setw(digit) << setfill('0') << power << endl;     // �ھڿ�J����ƨӦL�X���׻P�� 0
		}
	}

	system("pause");
	return 0;
}