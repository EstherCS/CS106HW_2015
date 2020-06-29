#include <iostream>
using namespace std;

int main()
{
	int num;
	int sum = 0;

	cout << "Enter a positive integer : ";
	cin >> num;

	while (num > 0)
	{
		while (num > 0)
		{
			sum = sum + num % 10;
			num = num / 10;
		}

		if (sum >= 10)
		{
			num = sum;
			sum = 0;
		}
		else
		{
			cout << sum << endl;
		} 
	}


	system("pause");
	return 0;
}