// 99���k��X ( �榡���w )

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j;

	for (i = 1; i < 10; i++)         // ��X 2 ~ 5 �����k��
	{
		for (j = 2; j < 6; j++)
		{
			cout << j << " " << "*" << " " << i << " " << "=" << " " << j * i;
			cout << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for (i = 1; i < 10; i++)         // ��X 6 ~ 9 �����k��
	{
		for (j = 6; j < 10; j++)
		{
			cout << j << " " << "*" << " " << i << " " << "=" << " " << j * i;
			cout << "\t";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}