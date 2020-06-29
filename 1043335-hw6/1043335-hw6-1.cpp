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

	// �p�� 10 �����L�X
	if (number < 10)
	{
		cout << number;
	}
	else
	{
		temp = number / factor;      // ���L�X�̥��䪺�Ʀr 
		cout << temp;
		cout << "  ";
		number = number % factor;    // �O�d�S�L�L���Ʀr
		factor = factor / 10;        
		
		digits(number, factor);
	}
}