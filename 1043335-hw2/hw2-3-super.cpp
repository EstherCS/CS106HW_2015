#include <iostream>
using namespace std;

int main()
{
	int num;
	int i;
	int counter;

	cout << "¿é¤J¼Æ¦r : ";
	cin >> num;

	for (i = 1; num > 0; i++)
	{
		counter = num % 10;
		num = num / 10;

		cout << counter;
	}
	cout << endl;

	system("pause");
	return 0;
}
