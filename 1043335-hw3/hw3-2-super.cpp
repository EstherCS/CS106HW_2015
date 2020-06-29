#include <iostream>
using namespace std;

int main()
{
	int num;
	int temp;
	int add;
	int sum = 0;

	cout << "Enter a positive integer : ";
	cin >> num;

	while (num >= 0)
	{
		temp = num;

		while (temp >= 10)
		{
			add = temp % 10;
			temp = temp / 10;
			sum = sum + add;
		}
		sum = sum + temp;
		
		if (sum >= 10)
		{
			num = sum;
			sum = 0;
		}
		else
		{
			cout << sum << endl;
			break;
		}
	}

	system("pause");
	return 0;
}