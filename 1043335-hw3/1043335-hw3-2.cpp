// 块┮Τ计㎝ (  )

#include <iostream>
using namespace std;

int g(int a);   // ㄧ计璸衡计

int main()
{
	int num;
	int result;

	cout << "Enter a positive integer : "; // 块计

	while (cin >> num)
	{
		if (num == 0)                      // 浪琩块计琌Τ计
		{
			cout << "Error";
			break;
		}
		else
		{
			result = g(num);               // ノㄧ计衡挡狦
			cout << result << endl;
		}
		break;
	}

	system("pause");
	return 0;
}

int g(int a)
{
	if (a < 10)                            // 秈ㄓ计 10穦肚计
	{
		return a;
	}

	int temp = a;                          // ﹚temp柑
	int sum = 0;                           // 羆 0

	while (temp > 0)                       // 秨﹍璸衡计
	{
		sum = sum + (temp % 10);
		temp = temp / 10;
	}
	return g(sum);                         // Ω秈ㄧ计羆㎝计
}