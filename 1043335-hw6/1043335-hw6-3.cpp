// Perform huge integer operations.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum sign{ plus, minus };
int enterChoice(); // enable user to input menu choice
void inputTwoHugeInts(vector< int > &hugeInt1, vector< int > &hugeInt2);
bool isZero(vector< int > hugeInt);
bool lesson(vector< int > leftOperand, vector< int > rightOperand);
bool lessEqual(vector< int > leftOperand, vector< int > rightOperand);
vector< int > addition(vector< int > addend, vector< int > adder);
vector< int > subtraction(vector< int > minuend, vector< int > subtrahend);
vector< int > multiplication(vector< int > multiplicand, vector< int > multiplier);
vector< int > compQuotient(vector< int > dividend, vector< int > divisor);
vector< int > compRemainder(vector< int > dividend, vector< int > divisor);
void divideBy10(vector< int > &leftOperand);
void printArithmetic(vector< int > operand1, vector< int > operand2,
	vector< int > result, char op, sign resultSign);

int main()
{
	vector< int > leftOperand;
	vector< int > rightOperand;
	vector< int > result;

	int choice = enterChoice();

	switch (choice)
	{
	case 1:
		inputTwoHugeInts(leftOperand, rightOperand);
		result = addition(leftOperand, rightOperand);
		printArithmetic(leftOperand, rightOperand, result, '+', sign::plus);
		break;
	case 2:
		inputTwoHugeInts(leftOperand, rightOperand);
		if (::lesson(leftOperand, rightOperand))
		{
			result = subtraction(rightOperand, leftOperand);
			printArithmetic(leftOperand, rightOperand, result, '-', sign::minus);
		}
		else
		{
			result = subtraction(leftOperand, rightOperand);
			printArithmetic(leftOperand, rightOperand, result, '-', sign::plus);
		}
		break;
	case 3:
		inputTwoHugeInts(leftOperand, rightOperand);
		result = multiplication(leftOperand, rightOperand);
		printArithmetic(leftOperand, rightOperand, result, '*', sign::plus);
		break;
	case 4:
		inputTwoHugeInts(leftOperand, rightOperand);
		if (isZero(rightOperand))
		{
			cout << "divide by zero!!\n\n";
			break;
		}
		result = compQuotient(leftOperand, rightOperand);
		printArithmetic(leftOperand, rightOperand, result, '/', sign::plus);
		result = compRemainder(leftOperand, rightOperand);
		printArithmetic(leftOperand, rightOperand, result, '%', sign::plus);
		break;
	default: // invalid value
		cout << "Program should never get here!";
	} // end switch

	system("pause");
}

// enable user to input menu choice
int enterChoice()
{
	// display available options
	cout << "Enter your choice\n"
		<< " 1 - test addition\n"
		<< " 2 - test subtracttion\n"
		<< " 3 - test multiplication\n"
		<< " 4 - test dividsion\n";

	int menuChoice;
	do {
		cout << "? ";
		cin >> menuChoice; // input menu selection from user
	} while ((menuChoice < 1) || (menuChoice > 4));
	cout << endl;

	return menuChoice;
} // end function enterChoice

// enable user to input two positive huge integers from user
void inputTwoHugeInts(vector< int > &hugeInt1, vector< int > &hugeInt2)
{
	string s1;
	string s2;
	cout << "Enter two positive huge integers:\n";
	cin >> s1 >> s2;
	cout << endl;

	unsigned hugeInt1Size = s1.size();
	for (int i = hugeInt1Size - 1; i >= 0; --i)
		hugeInt1.push_back(s1[i] - '0');

	unsigned hugeInt2Size = s2.size();
	for (int i = hugeInt2Size - 1; i >= 0; --i)
		hugeInt2.push_back(s2[i] - '0');
}

bool isZero(vector< int > hugeInt)
{
	unsigned size = hugeInt.size();
	if (size == 0)
		return true;
	else
	{
		for (int i = 0; i < size; ++i)
		if (hugeInt[i] != 0)
			return false;
		return true;
	}
}

vector< int > addition(vector< int > addend, vector< int > adder)
{
	int addendSize = addend.size();
	int adderSize = adder.size();
	int sumSize = (addendSize >= adderSize) ? addendSize + 1 : adderSize + 1;

	vector< int > sum(sumSize);

	for (int i = 0; i < addendSize; ++i)
		sum[i] = addend[i];

	for (int i = 0; i < adderSize; ++i)
		sum[i] += adder[i];

	for (int i = 0; i < sumSize - 1; ++i)
	if (sum[i] > 9)
	{
		sum[i] -= 10;
		++sum[i + 1];
	}

	if (sum[sumSize - 1] == 0)
		sum.resize(sumSize - 1);

	return sum;
}

void divideBy10(vector< int > &leftOperand)
{
	int size = leftOperand.size();
	for (int i = 1; i < size; ++i)
		leftOperand[i - 1] = leftOperand[i];

	leftOperand.resize(size - 1);
}

void printArithmetic(vector< int > leftOperand, vector< int > rightOperand,
	vector< int > result, char op, sign resultSign)
{
	for (int i = leftOperand.size() - 1; i >= 0; --i)
		cout << leftOperand[i];

	cout << " " << op << " ";

	for (int i = rightOperand.size() - 1; i >= 0; --i)
		cout << rightOperand[i];

	cout << " == ";

	if (resultSign == sign::minus)
		cout << '-';

	for (int i = result.size() - 1; i >= 0; --i)
		cout << result[i];
	cout << endl << endl;
}

// h1 < h2
bool lesson(vector< int > leftOperand, vector< int > rightOperand)
{
	if (leftOperand.size() < rightOperand.size())
		return true;
	else if (leftOperand.size() == rightOperand.size())
	{
		for (int i = leftOperand.size() - 1; i >= 0; i--)
		{
			if (leftOperand[i] < rightOperand[i])
				return true;
			if (leftOperand[i] > rightOperand[i])
				return false;
		}
	}
	return false;
}

vector< int > subtraction(vector< int > minuend, vector< int > subtrahend)
{
	int sumSize = minuend.size() ;

	vector< int > sum(sumSize);

	if (minuend != subtrahend)
	{
			subtrahend.resize(minuend.size());
	}

	for (int i = 0; i < sumSize; ++i)
	{
		sum[i] = minuend[i] - subtrahend[i];
	}

	for (int i = 0; i < sumSize; ++i)
	{
		if (sum[i] < 0)
		{
			sum[i] += 10;
			--sum[i + 1];
		}
	}

	while (sum[sumSize - 1] == 0 && sumSize != 1)
	{
		sumSize--;
	}

	sum.resize(sumSize);
	return sum;
}

vector< int > multiplication(vector< int > multiplicand, vector< int > multiplier)
{
	int sumSize = (multiplicand.size() >= multiplier.size()) ? multiplicand.size() * 2 : multiplier.size() * 2;
	int i;

	vector< int > sum(sumSize);

	for (i = 0; i < multiplicand.size(); i++)
	{
		for (int j = 0; j < multiplier.size(); j++)
		{
			sum[i + j] += multiplicand[i] * multiplier[j];
		}
	}

	for (i = 0; i < sumSize; i++)
	{
		while (sum[i] > 9)                               // 進位
		{
			sum[i] -= 10;
			sum[i + 1]++;
		}
	}

	while (sum[sumSize - 1] == 0 && sumSize != 1)
	{
		sumSize--;
	}

	sum.resize(sumSize);

	return sum;
}

vector< int > compQuotient(vector< int > dividend, vector< int > divisor)
{
	int i;
	int length = dividend.size() - divisor.size();
	int bufferSize = dividend.size();
	int quotientSize = length + 1;
	int tempSize = 0;
	int remainderSize = dividend.size();

	vector< int > buffer(bufferSize);
	vector< int > quotient(quotientSize);
	vector< int > temp(tempSize);
	vector< int > remainder(remainderSize);

	// 0 為被除數
	if (dividend[dividend.size() - 1] == 0)
	{
		if (dividend[0] == 0)
		{
			quotient.resize(1);
			quotient[0] = 0;
			remainder.resize(1);
			remainder[0] = 0;
		}
	}
	// 小除大
	else if (lesson(dividend, divisor))
	{
		for (i = 0; i < dividend.size(); i++)
		{
			remainder[i] = dividend[i];
		}
		quotient.resize(1);
		quotient[0] = 0;
	}
	else
	{
		for (i = 0; i < dividend.size(); i++)
		{
			remainder[i] = dividend[i];
		}
		// 讓除數、被除數位數一樣
		for (i = 0; i < dividend.size(); i++)
		{
			if (i < divisor.size())
				buffer[i + length] = divisor[i];
			else
				buffer[i - divisor.size()] = 0;
		}

		// 被除數長度小於除數長度、答案陣列長度不為 0
		while (divisor.size() <= remainderSize && quotientSize != 0)
		{
			if (lesson(remainder, buffer))
			{
				divideBy10(buffer);
				quotientSize--;
			}
			else
			{
				remainder = subtraction(remainder, buffer);
				quotient[quotientSize - 1]++;
			}
		}

		// 重設 quotientSize
		quotientSize = length + 1;

		while (quotient[quotientSize - 1] == 0 && quotientSize != 1)  // 整理
		{
			quotientSize--;
		}

		quotient.resize(quotientSize);
	}

	return quotient;
}

vector< int > compRemainder(vector< int > dividend, vector< int > divisor)
{
	int i;
	int length = dividend.size() - divisor.size();
	int bufferSize = dividend.size();
	int quotientSize = length + 1;
	int tempSize = 0;
	int remainderSize = dividend.size();

	vector< int > buffer(bufferSize);
	vector< int > quotient(quotientSize);
	vector< int > temp(tempSize);
	vector< int > remainder(remainderSize);

	// 0 為被除數
	if (dividend[dividend.size() - 1] == 0)
	{
		if (dividend[0] == 0)
		{
			quotient.resize(1);
			quotient[0] = 0;
			remainder.resize(1);
			remainder[0] = 0;
		}
	}
	// 小除大
	else if (lesson(dividend, divisor))
	{
		for (i = 0; i < dividend.size(); i++)
		{
			remainder[i] = dividend[i];
		}
		quotient.resize(1);
		quotient[0] = 0;
	}
	else
	{
		for (i = 0; i < dividend.size(); i++)
		{
			remainder[i] = dividend[i];
		}
		// 讓除數、被除數位數一樣
		for (i = 0; i < dividend.size(); i++)
		{
			if (i < divisor.size())
				buffer[i + length] = divisor[i];
			else
				buffer[i - divisor.size()] = 0;
		}

		// 被除數長度小於除數長度、答案陣列長度不為 0
		while (divisor.size() <= remainderSize && quotientSize != 0)
		{
			if (lesson(remainder, buffer))
			{
				divideBy10(buffer);
				quotientSize--;
			}
			else
			{
				remainder = subtraction(remainder, buffer);
				quotient[quotientSize - 1]++;
			}
		}
	}
	return remainder;
}