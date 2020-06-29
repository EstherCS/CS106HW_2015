// 1043335-hw1-1
// 找 Max 和 Min

#include <iostream>
using namespace std;

int main()
{
	// 設定變數
	int num1, num2, num3, num4, num5;
	int Max, Min;

	//輸入五個數字
	cout << "enter five intergers : ";
	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	Max = num1; // 設第一個數字為 Max
	Min = num1; // 設第一個數字為 Min

	// 判別接下來的 num2 ~ num5 是否大於 Max 或小於 Min
	if (num2 > Max)
	{
		Max = num2;
	}
	else if (num2 < Min)
	{
		Min = num2;
	}

	if (num3 > Max)
	{
		Max = num3;
	}
	else if (num3 < Min)
	{
		Min = num3;
	}

	if (num4 > Max)
	{
		Max = num4;
	}
	else if (num4 < Min)
	{
		Min = num4;
	}

	if (num5 > Max)
	{
		Max = num5;
	}
	else if (num5 < Min)
	{
		Min = num5;
	}

	// 印出 Max 和 Min
	cout << "Largest is " << Max << endl;
	cout << "smallest is " << Min << endl;

	system("pause");
	return 0;
}