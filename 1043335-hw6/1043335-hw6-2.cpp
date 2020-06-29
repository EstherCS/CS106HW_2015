// Check if a positive integer is a Palindrome

#include <iostream>
using namespace std;

bool isPalindrome(int number, int factor);

int main()
{
	int number; // a positive integer
	cout << "Enter a positive integer: ";
	cin >> number;

	// puts 10^(numDigits-1) (i.e., the smallest numDigits-digit positive integer) into factor
	int temp = number;
	int factor = 1; // power of ten
	while (temp > 9)
	{
		temp /= 10;
		factor *= 10;
	}

	// print whether the number is a palindrome
	if (isPalindrome(number, factor))
		cout << endl << number << " is a palindrome." << endl << endl;
	else
		cout << endl << number << " is not a palindrome." << endl << endl;

	system("pause");
}

bool isPalindrome(int number, int factor)
{
	// �p�� 0 ���~
	if (number < 0)
		return false;

	while (number > 0)
	{
		int left = number / factor;        // �̥��䪺�Ʀr
		int right = number % 10;           // �̥k�䪺�Ʀr

		if (left != right)
			return false;
		number = (number % factor) / 10;  // ���h�̥��M�̥k
		factor = factor / 100;            // �ֱ����ƩҥH�� 100
	}
	return true;
}