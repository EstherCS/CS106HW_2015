// 计╊秆Θㄢ场だキよ计セō ( 30 + 25 )^2 = 3025 

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int digit;
	int num = 1;
	int i;
	int power;

	cout << "Enter the number of digits (taken from 2, 4, 6, 8 ) : "; // 块计程计
	cin >> digit;

	for (i = 0; i < digit / 2; i++)                                   // 程计琌Чキよ计程10000 ( 9999 + 9999 = 19998 && 9999 * 9999程计 )
	{
		num = num * 10;                                               // т块计程伐
	}
	
	for (i = 0; i < num; i++)
	{
		power = i * i;                                                // 碝тЧキよ计 

		if ((power / num) + (power % num) == i)                       // Чキよ计玡キよ + キよ = 计セō
		{
			cout << setw(digit) << setfill('0') << power << endl;     // 沮块计ㄓ氮籔干 0
		}
	}

	system("pause");
	return 0;
}