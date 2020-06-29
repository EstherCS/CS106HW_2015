// 99乘法輸出 ( 格式限定 )

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, j;

	for (i = 1; i < 10; i++)         // 輸出 2 ~ 5 的乘法表
	{
		for (j = 2; j < 6; j++)
		{
			cout << j << " " << "*" << " " << i << " " << "=" << " " << j * i;
			cout << "\t";
		}
		cout << endl;
	}

	cout << endl;

	for (i = 1; i < 10; i++)         // 輸出 6 ~ 9 的乘法表
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