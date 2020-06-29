// Convert a binary value to its decimal equivalent.
#include <iostream>
using namespace std;

int decimal(int binary);

int main()
{
	int binary; // binary value

	// prompt for and read in a binary number
	cout << "Enter a positive binary integer: ";
	cin >> binary;

	cout << "The decimal equivalent of " << binary << " is " << decimal(binary) << endl;

	system("pause");
} // end main

int decimal(int binary)
{
	if (binary > 0)
	{
		return (binary % 10 * 1 + decimal(binary / 10) * 2);
	}
	else
	{
		return binary;
	}
}