// 1043335-hw1-5
// 判斷平年閏年

#include <iostream>
using namespace std;

int main()
{
	// 設定變數
	int year;
	int IsLeap;

	// 輸入年份
	cout << "Enter a year ( 1583 - 3000 ) : ";
	cin >> year;

	// 設定初始為否
	IsLeap = 0;

	// (1) 能被 4 整除以及不能被 100 整除
	// (2) 能被 400 整除

	if ((year % 4 == 0 && year % 100 != 0) ||   // (1)
		(year % 400 == 0))                      // (2)
	{
		IsLeap = 1;
	}

	// 判斷是否為閏年
	if (IsLeap)
	{
		cout << year << " is a leap year." << endl;
	}
	else
	{
		cout << year << " is a common year." << endl;
	}

	system("pause");
	return 0;
}