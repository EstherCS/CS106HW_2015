#include<iostream>
using namespace std;

int summingFactors(int i); // return the sum of all proper factors of i.
void display(int n, int m); // if n = 220, m = 284, then prints  220 = 1 + 2 + 4 + 71 + 142
bool check(int i, int ap[]);

int main() {
	int x, ap[1000] = { 0 };
	cout << "Enter a positive integer: ";
	cin >> x;
	cout << "Amicable pairs between 1 and " << x << ":\n";

	for (int i = 2, k = 0; i < x; i++)
	{
		if (check(i, ap) == true)
		{
			continue;
		}
		if ((summingFactors(i) != summingFactors(summingFactors(i))) && (i == summingFactors(summingFactors(i))))
		{
			ap[k] = summingFactors(i);
			k++;
			display(i, summingFactors(i));
		}
	}
	system("pause");
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

bool check(int i, int ap[])
{
	for (int j = 0; ap[j] != 0; j++)
	{
		if (i == ap[j])
		{
			return true;
		}
	}
	return false;
}