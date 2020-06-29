#include <iostream>
using namespace std;

int main()
{
	int num;
	int i;
	int sum = 0;

	cout << "輸入二進位數字 : ";
	cin >> num;

	for (i = 1; num > 0; i++)
	{
		sum = sum + (num % 10) * pow(2, i - 1);
		num = num / 10;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}