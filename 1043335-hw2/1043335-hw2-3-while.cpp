// Reverse the digits of a positive integer
// while

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // 將 Max 設為 100
	char num[Max];          // 設一個 array
	int i = 0;              // 初始變數 i 為 0
	int len;                // 計算 array 長度

	cout << "Enter a positive integer : ";   // 輸入數字
	cin >> num;

	len = strlen(num);                       // 計算 array 長度

	i = len-1;

	while (i >= 0)
	{
		cout << num[i];                      //從最後面開始倒著輸出
		i--;
	}

	cout << endl;

	system("pause");
	return 0;
}