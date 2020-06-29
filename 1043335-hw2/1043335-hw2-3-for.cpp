// Reverse the digits of a positive integer
// for

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // 將 Max 設為 100
	char num[Max];          // 設一個 array
	int i = 0;              // 初始變數 i 為 0
	int len;                // 計算 array 長度

	cout << "Enter a positive integer : ";  // 輸入數字
	cin >> num;

	len = strlen(num);                      // 計算 array 長度

	for (i = len - 1; i >= 0; i--)
	{
		cout << num[i];                     // 從最後面開始倒著輸出
	}

	cout << endl;


	system("pause");
	return 0;
}


/*

for (i = 0; i < Max; i++)
{
str[i] = 0;
}

len = strlen(num);

for (i = 0; i < len; i++)
{
str[i] = num[i] ;
}

for (i = len - 1; i >= 0; i--)
{
cout << str[i];
}

cout << endl;
*/