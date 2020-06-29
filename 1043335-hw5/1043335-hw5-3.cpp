#include <iostream>
using namespace std;

// enable user to input menu choice
int enterChoice();

// enable user to input two positive huge integers from user
void inputTwoHugeInts(int hugeInt1[], int hugeInt2[], int &hugeInt1Size, int &hugeInt2Size);

// Returns true if and only if hugeInt1 < hugeInt2
bool lesson(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 <= hugeInt2
bool lessEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize);

// difference = minuend - subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
	int &minuendSize, int subtrahendSize, int &differenceSize);

// product = multiplicand * multiplier
void multiplication(int multiplicand[], int multiplier[], int product[],
	int multiplicandSize, int multiplierSize, int &productSize);

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int &quotientSize, int &remainderSize);

// hugeInt /= 10
void divideBy10(int hugeInt[], int &hugeIntSize);

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void printRelational(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char string[]);

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printArithmetic(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
	int hugeInt1Size, int hugeInt2Size, int hugeInt3Size);

const int arraySize = 80;

// function main begins program execution
int main()
{
	int n1[arraySize] = { 0 };
	int n1Size = 0;
	int n2[arraySize] = { 0 };
	int n2Size = 0;
	int n3[arraySize] = { 0 };
	int n3Size = 0;
	int n4[arraySize] = { 0 };
	int n4Size = 0;

	int choice = enterChoice();

	switch (choice)
	{
	case 1:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		addition(n1, n2, n3, n1Size, n2Size, n3Size);
		printArithmetic(n1, n2, n3, '+', n1Size, n2Size, n3Size);
		break;
	case 2:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (lessEqual(n2, n1, n2Size, n1Size))
		{
			subtraction(n1, n2, n3, n1Size, n2Size, n3Size);
			printArithmetic(n1, n2, n3, '-', n1Size, n2Size, n3Size);
		}
		break;
	case 3:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		multiplication(n1, n2, n3, n1Size, n2Size, n3Size);
		printArithmetic(n1, n2, n3, '*', n1Size, n2Size, n3Size);
		break;
	case 4:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		division(n1, n2, n3, n4, n1Size, n2Size, n3Size, n4Size);
		printArithmetic(n1, n2, n3, '/', n1Size, n2Size, n3Size);
		printArithmetic(n1, n2, n4, '%', n1Size, n2Size, n4Size);
		break;
	default: // invalid value
		cout << "Program should never get here!";
	} // end switch

	system("pause");
} // end function main

// enable user to input menu choice
int enterChoice()
{
	// display available options
	cout << "Enter your choice\n"
		<< " 1 - test add\n"
		<< " 2 - test subtract\n"
		<< " 3 - test multiply\n"
		<< " 4 - test divide\n";

	int menuChoice;
	do {
		cout << "? ";
		cin >> menuChoice; // input menu selection from user
	} while ((menuChoice < 1) || (menuChoice > 4));
	cout << endl;

	return menuChoice;
} // end function enterChoice

// enable user to input two positive huge integers from user
void inputTwoHugeInts(int hugeInt1[], int hugeInt2[], int &hugeInt1Size, int &hugeInt2Size)
{
	char string1[arraySize];
	char string2[arraySize];
	cout << "Enter two positive huge integers:\n";
	cin >> string1 >> string2;
	cout << endl;

	hugeInt1Size = strlen(string1);
	for (int i = 0; i < hugeInt1Size; ++i)
		hugeInt1[i] = string1[hugeInt1Size - i - 1] - '0';

	hugeInt2Size = strlen(string2);
	for (int i = 0; i < hugeInt2Size; ++i)
		hugeInt2[i] = string2[hugeInt2Size - i - 1] - '0';
}

// h1 < h2
bool lessEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	if (hugeInt1Size > hugeInt2Size)
	{
		return false;
	}
	if (hugeInt1Size < hugeInt2Size)
	{
		return true;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = hugeInt1Size - 1; i >= 0; i--)
		{
			if (hugeInt1[i] > hugeInt2[i])
				return false;
			if (hugeInt1[i] < hugeInt2[i])
				return true;
		}
	}
	return true;
}

void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize)
{
	sumSize = (addendSize >= adderSize) ? addendSize + 1 : adderSize + 1;

	for (int i = 0; i < addendSize; i++)
	{
		sum[i] = addend[i];
	}
	for (int i = addendSize; i < sumSize; i++)
	{
		sum[i] = 0;
	}
	for (int i = 0; i < adderSize; i++)
	{
		sum[i] += adder[i];
	}
	for (int i = 0; i < sumSize - 1; i++)
	{
		if (sum[i] > 9)
		{
			sum[i] -= 10;
			sum[i + 1]++;
		}
	}
	if (sum[sumSize - 1] == 0)
	{
		sumSize--;
	}
}

// cout << hugeInt1 << string << hugeInt2 << endl << endl;
void printRelational(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size, char string[])
{
	for (int i = hugeInt1Size - 1; i >= 0; i--)
		cout << hugeInt1[i];

	cout << " " << string << " ";

	for (int i = hugeInt2Size - 1; i >= 0; i--)
		cout << hugeInt2[i];
	cout << endl << endl;
}

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printArithmetic(int hugeInt1[], int hugeInt2[], int hugeInt3[], char op,
	int hugeInt1Size, int hugeInt2Size, int hugeInt3Size)
{
	for (int i = hugeInt1Size - 1; i >= 0; i--)
		cout << hugeInt1[i];

	cout << " " << op << " ";
	for (int i = hugeInt2Size - 1; i >= 0; i--)
		cout << hugeInt2[i];

	cout << " == ";
	for (int i = hugeInt3Size - 1; i >= 0; i--)
		cout << hugeInt3[i];
	cout << endl << endl;
}

void subtraction(int minuend[], int subtrahend[], int difference[], int &minuendSize, int subtrahendSize, int &differenceSize)
{

	if (minuendSize >= subtrahendSize)
	{
		differenceSize = minuendSize;
	}
	else
	{
		differenceSize = subtrahendSize;
	}

	for (int i = 0; i < differenceSize; i++)
	{
		difference[i] = minuend[i] - subtrahend[i];
	}
	for (int i = 0; i < differenceSize; i++)
	{
		if (difference[i] < 0)
		{
			difference[i + 1] -= 1;
			difference[i] += 10;
		}

	}
	while (difference[differenceSize - 1] == 0 && differenceSize != 1)
		differenceSize--;

}

void multiplication(int multiplicand[], int multiplier[], int product[], int multiplicandSize, int multiplierSize, int &productSize)
{
	for (int i = 0; i < multiplicandSize; i++)
	{
		for (int j = 0; j < multiplierSize; j++)
		{
			product[i + j] += multiplicand[i] * multiplier[j];
			productSize++;
		}
	}

	int length = productSize * 2;
	for (int i = 0; i < length; i++)
	{
		while (product[i] > 9)                               // 進位
		{
			product[i] -= 10;
			product[i + 1]++;
		}
	}
	while (product[length - 1] == 0)
		length--;
	productSize = length;
}

void division(int dividend[], int divisor[], int quotient[], int remainder[],
	int dividendSize, int divisorSize, int &quotientSize, int &remainderSize)
{
	int length = dividendSize - divisorSize;
	int i;
	int buffer[arraySize];
	int bufferSize = dividendSize;
	int temp[arraySize] = { 0 };
	int tempSize = 0;
	remainderSize = dividendSize;
	quotientSize = length + 1;


	// 判斷是否有 0
	if (divisor[divisorSize - 1] == 0 || dividend[dividendSize - 1] == 0)
	{
		if (divisor[0] == 0)
		{
			quotient[0] = 0;
			quotientSize = 1;
			for (i = 0; i < dividendSize; i++)
			{
				remainder[i] = dividend[i];
			}
		}
		else
		{
			quotient[0] = 0;
			quotientSize = 1;
			remainder[0] = 0;
		}
	}
	// 判斷大除小或是小除大
	else if (lesson(dividend, divisor, dividendSize, divisorSize))
	{
		for (i = 0; i < dividendSize; i++)
		{
			remainder[i] = dividend[i];
		}
		quotientSize = 1;
		quotient[0] = { 0 };
	}
	else
	{
		// 把 dividend 放到 remainder
		for (i = 0; i < dividendSize; i++)
		{
			remainder[i] = dividend[i];
		}
		// 讓除數、被除數位數一樣
		for (i = 0; i < dividendSize; i++)
		{
			if (i < divisorSize)
				buffer[i + length] = divisor[i];
			else
				buffer[i - divisorSize] = 0;
		}

		// 被除數長度小於除數長度、答案陣列長度不為 0
		while (divisorSize <= remainderSize && quotientSize != 0)
		{
			if (lesson(remainder, buffer, remainderSize, bufferSize))
			{
				divideBy10(buffer, bufferSize);
				quotientSize--;
			}
			else
			{
				subtraction(remainder, buffer, temp, remainderSize, quotientSize, tempSize);
				quotient[quotientSize - 1]++;
				for (i = 0; i < remainderSize; i++)
				{
					remainder[i] = temp[i];
				}
				remainderSize = tempSize;
			}
		}
		// 重新設定 quotientSize
		quotientSize = length + 1;

		// 去掉 0
		while (quotient[quotientSize - 1] == 0)
		{
			quotientSize--;
		}
	}
}

// 讓陣列右移
void divideBy10(int hugeInt[], int &hugeIntSize)
{
	for (int i = 1; i < hugeIntSize; i++)
		hugeInt[i - 1] = hugeInt[i];

	hugeIntSize--;
	hugeInt[hugeIntSize] = 0;
}

// 判斷大小
bool lesson(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	if (hugeInt1Size < hugeInt2Size)
	{
		return true;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		//  for (int i = hugeInt2Size - 1; i > 0; i--)
		for (int i = hugeInt2Size - 1; i >= 0; i--)
		{
			if (hugeInt2[i] > hugeInt1[i])
			{
				return true;
			}
			if (hugeInt2[i] < hugeInt1[i])
			{
				return false;
			}
		}
	}
	return false;
}