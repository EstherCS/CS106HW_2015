// Convert a binary value to its decimal equivalent. 
#include <iostream> 
using namespace std;

int decimal(int binary);
int sum = 0;
int i = 0;

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
	while (binary > 0){
		sum = sum + (binary % 10)*pow(2, i);
		i = i + 1;
		decimal(binary / 10);
		return sum;
	}

}