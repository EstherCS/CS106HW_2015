// Compute all positive factors of a positive integer
//while

#include <iostream>
using namespace std;

int main()
{
	int num;      // 輸入的數字
	int i = 1;    // 變數

	cout << "Enter a positive integer : ";  // 輸入數字
	cin >> num;


	cout << "The positive factors of " << num << endl;

	while (i <= num)
	{
		if (num % i == 0)        	// 計算是否為因數
		{
			cout << i << endl;      // 印出結果
		}
		i++;
	}
	

	system("pause");
	return 0;
}