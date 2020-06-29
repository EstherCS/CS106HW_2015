// Convert a binary number to its decimal equivalent.
// for

#include <iostream>
using namespace std;

int main()
{
	const int Max = 100;    // 將 Max 設為 100
	char num[Max];          // 設一個 array
	int len;                // 計算 array 長度
	int i;                  // 變數
	bool Check = 1;         // 檢查輸入

	cout << "Enter a positive binary integer : ";  //  輸入二進位
	cin >> num;

	len = strlen(num);                             // 計算 array 長度
	
	// 檢查輸入是否為二進位
	for (i = 0; i < len; i++)
	{
		if (num[i] != '0' && num[i] != '1')
		{
			cout << "Error!" << endl;
			Check = 0;
		}
	}
	
	if (Check == 1)
	{
		int power2 = 1;         // 計算 2 的平方、次方....  初始為 2^0 = 1
		int sum = 0;            // 總和

		for (i = len - 1; i >= 0; i--)
		{
			sum = sum + (num[i] - '0') * power2;   // 計算總和
			power2 = power2 * 2;                   // 2 的連乘
		}

		cout << "The decimal equivalent of " << num << " is " << sum << endl;  // 輸出結果
	}

	system("pause");
	return 0;
}