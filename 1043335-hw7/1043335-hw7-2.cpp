// Perform huge integer operations.
#include <iostream>
using namespace std;

enum sign{ plus, minus };
int enterChoice();// enable user to input menu choice

// enable user to input two positive huge integers from user
void inputTwoHugeInts(int *&hugeInt1, int *&hugeInt2, int &hugeInt1Size, int &hugeInt2Size);

// Returns true if and only if hugeInt == 0
bool isZero(int *hugeInt, int hugeIntSize);

// Returns true if and only if hugeInt1 < hugeInt2
bool less(int *hugeInt1, int *hugeInt2, int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 <= hugeInt2
bool lessEqual(int *hugeInt1, int *hugeInt2, int hugeInt1Size, int hugeInt2Size);

// sum = addend + adder
void addition(int *addend, int *adder, int *&sum, int addendSize, int adderSize, int &sumSize);

// difference = minuend - subtrahend
void subtraction(int *minuend, int *subtrahend, int *&difference,
	int &minuendSize, int subtrahendSize, int &differenceSize);

// product = multiplicand * multiplier
void multiplication(int *multiplicand, int *multiplier, int *&product,
	int multiplicandSize, int multiplierSize, int &productSize);

// quotient = dividend / divisor; remainder = dividend % divisor
void division(int *dividend, int *divisor, int *&quotient, int *&remainder,
	int dividendSize, int divisorSize, int &quotientSize, int &remainderSize);

void divideBy10(int *hugeInt, int &hugeIntSize); // hugeInt /= 10

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printArithmetic(int *hugeInt1, int *hugeInt2, int *hugeInt3, char op,
	int hugeInt1Size, int hugeInt2Size, int hugeInt3Size, sign resultSign);

const int arraySize = 80;

// function main begins program execution
int main()
{
	int *n1 = 0;
	int n1Size = 0;
	int *n2 = 0;
	int n2Size = 0;
	int *n3 = 0;
	int n3Size = 0;
	int *n4 = 0;
	int n4Size = 0;

	int choice = enterChoice();

	switch (choice)
	{
	case 1:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		addition(n1, n2, n3, n1Size, n2Size, n3Size); // n3 = n1 + n2
		printArithmetic(n1, n2, n3, '+', n1Size, n2Size, n3Size, sign::plus);
		break;
	case 2:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (::less(n1, n2, n1Size, n2Size))
		{
			subtraction(n2, n1, n3, n2Size, n1Size, n3Size); // n3 = n2 - n1
			printArithmetic(n1, n2, n3, '-', n1Size, n2Size, n3Size, sign::minus);
		}
		else
		{
			subtraction(n1, n2, n3, n1Size, n2Size, n3Size); // n3 = n1 - n2
			printArithmetic(n1, n2, n3, '-', n1Size, n2Size, n3Size, sign::plus);
		}
		break;
	case 3:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		multiplication(n1, n2, n3, n1Size, n2Size, n3Size); // n3 = n1 * n2
		printArithmetic(n1, n2, n3, '*', n1Size, n2Size, n3Size, sign::plus);
		break;
	case 4:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (isZero(n2, n2Size))
		{
			cout << "divide by zero!!\n\n";
			break;
		}
		division(n1, n2, n3, n4, n1Size, n2Size, n3Size, n4Size); // n3 = n1 / n2; n4 = n1 % n2
		printArithmetic(n1, n2, n3, '/', n1Size, n2Size, n3Size, sign::plus);
		printArithmetic(n1, n2, n4, '%', n1Size, n2Size, n4Size, sign::plus);
		break;
	default: // invalid value
		cout << "Program should never get here!";
	} // end switch

	delete[] n1;
	delete[] n2;
	delete[] n3;
	delete[] n4;

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
void inputTwoHugeInts(int *&hugeInt1, int *&hugeInt2, int &hugeInt1Size, int &hugeInt2Size)
{
	const int arraySize = 80;
	char string1[arraySize];
	char string2[arraySize];
	cout << "Enter two positive huge integers:\n";
	cin >> string1 >> string2;
	cout << endl;

	hugeInt1Size = strlen(string1);
	hugeInt1 = new int[hugeInt1Size];
	for (int i = 0; i < hugeInt1Size; ++i)
		hugeInt1[i] = string1[hugeInt1Size - i - 1] - '0';

	hugeInt2Size = strlen(string2);
	hugeInt2 = new int[hugeInt2Size];
	for (int i = 0; i < hugeInt2Size; ++i)
		hugeInt2[i] = string2[hugeInt2Size - i - 1] - '0';
}

bool isZero(int *hugeInt, int hugeIntSize)
{
	if (hugeIntSize == 0)
		return true;
	else
	{
		for (int i = 0; i < hugeIntSize; ++i)
		if (hugeInt[i] != 0)
			return false;
		return true;
	}
}

void divideBy10(int *hugeInt, int &hugeIntSize)
{
	for (int i = 1; i < hugeIntSize; ++i)
		hugeInt[i - 1] = hugeInt[i];

	--hugeIntSize;
	hugeInt[hugeIntSize] = 0;
}

// cout << hugeInt1 << op << hugeInt2 << " == " << hugeInt3 << endl << endl;
void printArithmetic(int *hugeInt1, int *hugeInt2, int *hugeInt3, char op,
	int hugeInt1Size, int hugeInt2Size, int hugeInt3Size, sign resultSign)
{
	for (int i = hugeInt1Size - 1; i >= 0; --i)
		cout << hugeInt1[i];

	cout << " " << op << " ";

	for (int i = hugeInt2Size - 1; i >= 0; --i)
		cout << hugeInt2[i];

	cout << " == ";

	if (resultSign == sign::minus)
		cout << '-';

	for (int i = hugeInt3Size - 1; i >= 0; i--)
		cout << hugeInt3[i];
	cout << endl << endl;
}
bool less(int *hugeInt1, int *hugeInt2, int hugeInt1Size, int hugeInt2Size)
{
	if (hugeInt1Size < hugeInt2Size)
	{
		return true;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
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

bool lessEqual(int *hugeInt1, int *hugeInt2, int hugeInt1Size, int hugeInt2Size)
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

void addition(int *addend, int *adder, int *&sum, int addendSize, int adderSize, int &sumSize)
{
	sumSize = (addendSize >= adderSize) ? addendSize + 1 : adderSize + 1;
	if (sum != 0)
		delete[] sum;
	sum = new int[sumSize];

	for (int i = 0; i < addendSize; ++i)
		sum[i] = addend[i];

	for (int i = addendSize; i < sumSize; ++i)
		sum[i] = 0;

	for (int i = 0; i < adderSize; ++i)
		sum[i] += adder[i];

	for (int i = 0; i < sumSize - 1; ++i)
	if (sum[i] > 9)
	{
		sum[i] -= 10;
		++sum[i + 1];
	}

	if (sum[sumSize - 1] == 0)
		--sumSize;
}

void subtraction(int *minuend, int *subtrahend, int *&difference,
	int &minuendSize, int subtrahendSize, int &differenceSize)
{
	int *sub2;
	sub2 = new int[minuendSize];
	differenceSize = minuendSize;
	difference = new int[minuendSize];        // 根據 minuendSize 大小來要記憶體

	for (int i = 0; i < differenceSize; i++)  // 在數字前補 0，使減數和被減數長度相同
	{
		if (i >= subtrahendSize)
			sub2[i] = 0;
		else
			sub2[i] = subtrahend[i];
	}

	for (int i = 0; i < differenceSize; ++i)   // 相減
	{
		difference[i] = minuend[i] - sub2[i];
	}
	for (int i = 0; i < differenceSize; ++i)   // 做整理 
	{
		if (difference[i] < 0)
		{
			difference[i + 1] -= 1;
			difference[i] += 10;
		}
	}
	while (difference[differenceSize - 1] == 0 && differenceSize != 1)  // 刪去數字前的 0 
		--differenceSize;

	delete[] sub2;         // 釋放記憶體

}

void multiplication(int *multiplicand, int *multiplier, int *&product,
	int multiplicandSize, int multiplierSize, int &productSize)
{
	// 判斷乘數與被乘數是否為 0
	if ((multiplicandSize == 1 && multiplicand[0] == 0) || (multiplierSize == 1 && multiplier[0] == 0))
	{
		if (product != 0)
			delete[] product;
		product = new int[1];      // 相乘的結果為 0
		product[0] = 0;
		productSize = 1;
	}
	else
	{
		if (product != 0)
			delete[] product;

		product = new int[arraySize];

		for (int i = 0; i < arraySize; i++)         // 初始化
			product[i] = 0;
		for (int i = 0; i < multiplicandSize; i++)  // 相乘
		{
			for (int j = 0; j < multiplierSize; j++)
			{
				product[i + j] += multiplicand[i] * multiplier[j];
				productSize++;
			}
		}
		int length = productSize * 2;                             // 預留進位位子

		for (int i = 0; i < length; i++)
		{
			while (product[i] > 9)                               // 進位
			{
				product[i] -= 10;
				product[i + 1]++;
			}
		}
		while (product[length - 1] == 0)                         // 整理
			length--;
		productSize = length;
	}
}

void division(int *dividend, int *divisor, int *&quotient, int *&remainder,
	int dividendSize, int divisorSize, int &quotientSize, int &remainderSize)
{
	int length = dividendSize - divisorSize;
	int i;
	int buffer[arraySize];
	int bufferSize = dividendSize;
	int temp[arraySize] = { 0 };
	int tempSize = 0;
	int *aprt = temp;
	remainderSize = dividendSize;
	quotientSize = length + 1;

	// 判斷是否有 0
	if ((dividend[0] == 0 && dividendSize == 1))
	{
		quotient = new int[1];
		quotient[0] = 0;
		quotientSize = 1;
		remainder = new int[divisorSize];
		remainderSize = divisorSize;
		for (i = 0; i < divisorSize; i++)
		{
			remainder[i] = divisor[i];
		}
	}
	// 判斷大除小或是小除大
	else if (::less(dividend, divisor, dividendSize, divisorSize))
	{
		remainder = new int[dividendSize];
		remainderSize = dividendSize;
		for (i = 0; i < dividendSize; i++)
		{
			remainder[i] = dividend[i];
		}
		quotient = new int[1];
		quotient[0] = 0;
		quotientSize = 1;
	}
	else
	{
		remainder = new int[80];
		quotient = new int[80];
		for (i = 0; i < 80; i++)
		{
			quotient[i] = 0;
			remainder[i] = 0;
		}
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
			if (::less(remainder, buffer, remainderSize, bufferSize))
			{
				divideBy10(buffer, bufferSize);
				quotientSize--;
			}
			else
			{
				subtraction(remainder, buffer, aprt, remainderSize, bufferSize, tempSize);
				quotient[quotientSize - 1]++;
				for (i = 0; i < tempSize; i++)
				{
					remainder[i] = aprt[i];
				}
				remainderSize = tempSize;
			}
		}
		// 重新設定 quotientSize
		quotientSize = length + 1;

		while (quotient[quotientSize - 1] == 0)   // 去掉 0
		{
			quotientSize--;
		}
	}
}