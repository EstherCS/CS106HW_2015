// recursive function  ex : 34567 -> 3  4  5  6  7

#include <iostream>
using namespace std;

void digits(int number, int factor);

int main()
{
	int number;            
	cout << "Enter a positive integer: ";
	cin >> number;

	int factor = 1;        // power of ten
	int temp = number;
	while (temp > 9)
	{
		temp /= 10;
		factor *= 10;
	}

	cout << "\nThe digits: ";

	digits(number, factor);

	cout << endl << endl;

	system("pause");
} 

void digits(int number, int factor)
{
	int temp;

	// 小於 10 直接印出
	if (number < 10)
	{
		cout << number;
	}
	else
	{
		temp = number / factor;      // 先印出最左邊的數字 
		cout << temp;
		cout << "  ";
		number = number % factor;    // 保留沒印過的數字
		factor = factor / 10;        
		
		digits(number, factor);
	}
}