// amicable pair EX : 220 因數總和為 284，284 因數總和為 220

#include <iostream>
#include <cmath>
using namespace std;

int summingFactors(int i);   // 計算因數總和
void display(int n, int m);  // 顯示結果

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
		sm = summingFactors(m);      // 計算 m 的因數總和
		for (n = 1; n < m; n++)
		{
			sn = summingFactors(n);  // 計算 n 的因數總和
			if (m == sn && n == sm)  // 比較總和和原本數字是否相等
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
	for (j = 2; j * j < i; j++)       // 因數找到 i 的根號節省時間
	{
		if (i % j == 0)
		{
			sum = sum + j + (i / j);  // 因只找到 i 的根號，所以要加上 ( i / j )
		}
	}
	return sum;
}

void display(int n, int m)
{
	int i;

	cout << n << " = 1";
	for (i = 2; i * i < m; i++)       // 印出前半 
	{
		if (m % i == 0)
		{
			cout << " + " << i;
		}
	}
    for (i = sqrt(m); i > 1; i--)     // 印出後半
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