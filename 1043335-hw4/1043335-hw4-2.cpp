// Perform huge integer operations.
#include <iostream>
using namespace std;

// enable user to input menu choice
int enterChoice();

// enable user to input two positive huge integers from user
void inputTwoHugeInts(int hugeInt1[], int hugeInt2[], int &hugeInt1Size, int &hugeInt2Size);

// Returns true if and only if hugeInt1 == hugeInt2
bool equal(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 != hugeInt2
bool notEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 < hugeInt2
bool lesson(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 > hugeInt2
bool greater(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 <= hugeInt2
bool lessEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// Returns true if and only if hugeInt1 >= hugeInt2
bool greaterEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize);

// difference = minuend - subtrahend
void subtraction(int minuend[], int subtrahend[], int difference[],
	int minuendSize, int subtrahendSize, int &differenceSize);

// product = multiplicand * multiplier
void multiplication(int multiplicand[], int multiplier[], int product[],
	int multiplicandSize, int multiplierSize, int &productSize);

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

	int choice = enterChoice();

	switch (choice)  // �ھڨϥΪ̻ݨD�Ӱ��B�z
	{
	case 1:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (equal(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, "==");
		break;
	case 2:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (notEqual(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, "!=");
		break;
	case 3:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (lesson(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, "<");
		break;
	case 4:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (greater(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, ">");
		break;
	case 5:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (lessEqual(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, "<=");
		break;
	case 6:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (greaterEqual(n1, n2, n1Size, n2Size))
			printRelational(n1, n2, n1Size, n2Size, ">=");
		break;
	case 7:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		addition(n1, n2, n3, n1Size, n2Size, n3Size);
		printArithmetic(n1, n2, n3, '+', n1Size, n2Size, n3Size);
		break;
	case 8:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		if (greaterEqual(n1, n2, n1Size, n2Size))
		{
			subtraction(n1, n2, n3, n1Size, n2Size, n3Size);
			printArithmetic(n1, n2, n3, '-', n1Size, n2Size, n3Size);
		}
		break;
	case 9:
		inputTwoHugeInts(n1, n2, n1Size, n2Size);
		multiplication(n1, n2, n3, n1Size, n2Size, n3Size);
		printArithmetic(n1, n2, n3, '*', n1Size, n2Size, n3Size);
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
		<< " 1 - test equal\n"
		<< " 2 - test notEqual\n"
		<< " 3 - test less\n"
		<< " 4 - test greater\n"
		<< " 5 - test lessEqual\n"
		<< " 6 - test greaterEqual\n"
		<< " 7 - test add\n"
		<< " 8 - test subtract\n"
		<< " 9 - test multiply\n";

	int menuChoice;
	do {
		cout << "? ";
		cin >> menuChoice; // input menu selection from user
	} while ((menuChoice < 1) || (menuChoice > 9));
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

// �ˬd��ӼƦr�O�_�۵��A�Y "�۵�" �h�Ǧ^
bool equal(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	bool check = 1;
	if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (hugeInt1[i] != hugeInt2[i])
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}

	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �ˬd��ӼƦr�O�_�۵��A�Y "���۵�" �h�Ǧ^
bool notEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	bool check = 1;
	if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (hugeInt1[i] != hugeInt2[i])
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}

	if (check == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// �ˬd h1 �O�_ < h2 �A�Y�O�h�Ǧ^
bool lesson(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	int sum[arraySize];
	bool check = 1;
	int count = 0;

	if (hugeInt1Size < hugeInt2Size)
	{
		check = 1;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (hugeInt1[i] == hugeInt2[i])
			{
				count++;
			}
		}
		if (count == hugeInt1Size)
		{
			check = 0;
		}
		for (int i = 0; i < hugeInt2Size; i++)
		{
			sum[i] = hugeInt2[i] - hugeInt1[i];
		}
		for (int i = 0; i < hugeInt2Size-1; i++)             // ���t���ܥ�
		{
			if (sum[i] < 0)
			{
				sum[i] += 10;
				sum[i + 1]--;
			}
		}
		for (int i = 0; i < hugeInt2Size; i++)
		{
			if (sum[i] < 0)
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}

	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �ˬd h1 �O�_ > h2 �A�Y�O�h�Ǧ^
bool greater(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	int sum[arraySize] ;
	bool check = 1;
	int count = 0;

	if (hugeInt1Size > hugeInt2Size)
	{
		check = 1;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (hugeInt1[i] == hugeInt2[i])
			{
				count++;
			}
		}
		if (count == hugeInt1Size)
		{
			check = 0;
		}
		for (int i = 0; i < hugeInt1Size; i++)
		{
			sum[i] = hugeInt1[i] - hugeInt2[i];
		}
		for (int i = 0; i < hugeInt1Size - 1; i++)             // ���t���ܥ�
		{
			if (sum[i] < 0)
			{
				sum[i] += 10;
				sum[i + 1]--;
			}
		}
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (sum[i] < 0)
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}

	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �ˬd h1 �O�_ <= h2 �A�Y�O�h�Ǧ^
bool lessEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	int sum[arraySize];
	bool check = 1;

	if (hugeInt1Size < hugeInt2Size)
	{
		check = 1;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt2Size; i++)
		{
			sum[i] = hugeInt2[i] - hugeInt1[i];
		}
		for (int i = 0; i < hugeInt2Size - 1; i++)             // ���t���ܥ�
		{
			if (sum[i] < 0)
			{
				sum[i] += 10;
				sum[i + 1]--;
			}
		}
		for (int i = 0; i < hugeInt2Size; i++)
		{
			if (sum[i] < 0)
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}

	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �ˬd h1 �O�_ >= h2 �A�Y�O�h�Ǧ^
bool greaterEqual(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	int sum[arraySize];
	bool check = 1;

	if (hugeInt1Size > hugeInt2Size)
	{
		check = 1;
	}
	else if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			sum[i] = hugeInt1[i] - hugeInt2[i];
		}
		for (int i = 0; i < hugeInt1Size - 1; i++)             // ���t���ܥ�
		{
			if (sum[i] < 0)
			{
				sum[i] += 10;
				sum[i + 1]--;
			}
		}
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (sum[i] < 0)
			{
				check = 0;
			}
		}
	}
	else
	{
		check = 0;
	}
	if (check == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// �p���Ƭۥ[
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize)
{
	int i;
	
	if (addendSize >= adderSize)
	{
		sumSize = addendSize + 1;   // �O�d�i��n����l
	}
	else
	{
		sumSize = adderSize + 1;
	}

	for (i = 0; i < sumSize; i++)
	{
		sum[i] = 0;                              // ��l sum �}�C�� 0
	}

	if (addendSize <= adderSize)
	{
		for (i = 0; i < addendSize; i++)         // �̸��֪���ƥ��ۥ[
		{
			sum[i] = addend[i] + adder[i];
		}
		for (i = addendSize; i < adderSize; i++) // �h�X�Ӫ���ƪ�����U��
		{
			sum[i] = adder[i];
		}
	}
	else
	{
		for (i = 0; i < adderSize; i++)
		{
			sum[i] = addend[i] + adder[i];
		}
		for (i = adderSize; i < addendSize; i++)
		{
			sum[i] = addend[i];
		}		
	}

	for (i = 0; i < sumSize - 1; i++)            // �Y�O�W�L�E�h�i��
	{
		if (sum[i] > 9)
		{
			sum[i] -= 10;
			sum[i + 1]++;
		}
		if (sum[sumSize - 1] == 0)               // �O�d���ļƦr
			sumSize--;
	}
}

// �p���Ƭ۴�
void subtraction(int minuend[], int subtrahend[], int difference[], int minuendSize, int subtrahendSize, int &differenceSize)
{
	int i;

	if (minuendSize >= subtrahendSize)
	{
		differenceSize = minuendSize;
	}
	else
	{
		differenceSize = subtrahendSize;
	}

	for (i = 0; i < differenceSize; i++)
	{
		difference[i] = 0;
	}

	if (minuendSize <= subtrahendSize)
	{
		for (i = 0; i < minuendSize; i++)
		{
			difference[i] = minuend[i] - subtrahend[i];  // �̦�Ƥp�����۴� 
		}
		for (i = minuendSize; i < subtrahendSize; i++)
		{
			difference[i] = subtrahend[i];               // �h�l����Ʃ��U��
		}
	}
	else
	{
		for (i = 0; i < subtrahendSize; i++)
		{
			difference[i] = minuend[i] - subtrahend[i];
		}
		for (i = subtrahendSize; i < minuendSize; i++)
		{
			difference[i] = minuend[i];
		}
	}

	for (i = 0; i < differenceSize - 1; i++)             // ���t���ܥ�
	{
		if (difference[i] < 0)
		{
			difference[i] += 10;
			difference[i + 1]--;
		}
		while (difference[differenceSize - 1] == 0)
			differenceSize--;
	}
}

// �p���Ƭۭ�
void multiplication(int multiplicand[], int multiplier[], int product[], int multiplicandSize, int multiplierSize, int &productSize)
{
	int i;
	int j;
	int k;
	int temp[arraySize];

	if (multiplicandSize >= multiplierSize)
	{
		productSize = multiplicandSize + multiplicandSize;   // �O�d���k�i���һݪ���l
	}
	else
	{
		productSize = multiplierSize + multiplierSize;
	}

	for (i = 0; i < productSize; i++)
	{
		product[i] = 0;
		temp[i] = 0;
	}

	if (multiplicandSize >= multiplierSize)
	{
		for (j = 0; j < multiplierSize; j++)                 // �q��Ƥ֪��}�l��
		{
			for (i = j, k = 0; k < productSize; i++, k++)
			{
				temp[i] = multiplicand[k] * multiplier[j];   // temp�C�����@�`���A�n�V�����@��
			}
			for (i = 0; i < productSize; i++)
			{
				product[i] = product[i] + temp[i];
				temp[i] = 0;                                 // temp �ݲM���קK���Ƭۥ[
			}
		}
	}
	else
	{
		for (j = 0; j < multiplicandSize; j++)
		{
			for (i = j, k = 0; k < multiplierSize; i++, k++)
			{
				temp[i] = multiplicand[j] * multiplier[k];
			}
			for (i = 0; i < productSize; i++)
			{
				product[i] = product[i] + temp[i];
				temp[i] = 0;
			}
		}
	}

	for (i = 0; i < productSize - 1; i++)
	{
		while (product[i] > 9)                               // �i��
		{
			product[i] -= 10;
			product[i + 1]++;
		}
		if (product[productSize - 1] == 0)
			productSize--;
	}
}