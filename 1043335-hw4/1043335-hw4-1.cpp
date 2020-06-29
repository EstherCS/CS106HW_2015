// amicable pair EX : 220 �]���`�M�� 284�A284 �]���`�M�� 220

#include <iostream>
#include <cmath>
using namespace std;

int summingFactors(int i);   // �p��]���`�M
void display(int n, int m);  // ��ܵ��G

int main()
{	
	int input;
	int n, sn;
	int m, sm;

	cout << "Enter a positive integer : ";
	cin >> input;

	cout << endl << "Amicable pairs between 1 and " << input << " : " << endl;

	for (m = 1; m <= input; m++)
	{
		sm = summingFactors(m);      // �p�� m ���]���`�M
		for (n = 1; n < m; n++)
		{
			sn = summingFactors(n);  // �p�� n ���]���`�M
			if (m == sn && n == sm)  // ����`�M�M�쥻�Ʀr�O�_�۵�
			{
				display(n, m);
			}
		}
	}

	system("pause");
	return 0;

}

int summingFactors(int i)
{
	int sum = 1;
	int j;

	if (i == 1)
	{
		return 0;
	}
	for (j = 2; j * j < i; j++)       // �]�Ƨ�� i ���ڸ��`�ٮɶ�
	{
		if (i % j == 0)
		{
			sum = sum + j + (i / j);  // �]�u��� i ���ڸ��A�ҥH�n�[�W ( i / j )
		}
	}
	return sum;
}

void display(int n, int m)
{
	int i;

	cout << n << " = 1";
	for (i = 2; i * i < m; i++)       // �L�X�e�b 
	{
		if (m % i == 0)
		{
			cout << " + " << i;
		}
	}
    for (i = sqrt(m); i > 1; i--)     // �L�X��b
	{
		if (m % i == 0)
		{
			cout << " + " << m / i;
		}
	}

	cout << endl;

	cout << m << " = 1";
	for (i = 2; i * i < n; i++)
	{
		if (n % i == 0)
		{
			cout << " + " << i;
		}
	}
	for (i = sqrt(n); i > 1; i--)
	{
		if (n % i == 0)
		{
			cout << " + " << n / i;
		}
	}

	cout << endl << endl;
}