// perfect number ( 计セō┮Τ计埃癬ㄓ羆 )

#include <iostream>
using namespace std;

int main()
{
	int digit;
	int num;
	int i, j;
	int sum;

	cout << "Enter a positive integer : ";  // 块计ㄓ﹚絛瞅
	cin >> digit;

	cout << "Perfect numbers between 1 and " << digit << " : " << endl;

	for (num = 1; num <= digit; num++)
	{
		sum = 0;                           // sum –Ω常ゲ斗耴 0 
		for (i = 1; i < num; i++)          // т絛瞅ず–计计の璸衡羆
		{
			if (num % i == 0)             
			{
				sum = sum + i;
			}
		}
		if (sum == num)                   // 璝计羆计セō玥块
		{
			cout << num << " = 1";
			for (i = 2; i < num; i++)
			{
				if (num % i == 0)
				{
					cout << " + ";
					cout << i;
				}
				
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}