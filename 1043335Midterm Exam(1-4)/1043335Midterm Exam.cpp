// 1043335
// Midterm Exam

#include <iostream>
using namespace std;

// enable user to input a positive huge integer from user
void inputHugeInt(int hugeInt1[], int &hugeInt1Size);

// return true if and only if hugeInt is a quirksome number
bool quirksome(int hugeInt[], int hugeIntSize);

// return true if and only if hugeInt1 == hugeInt2
bool equal(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size);

// sum = addend + adder
void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize);

// square = hugeInt * hugeInt
void computeSquare(int hugeInt[], int square[], int hugeIntSize, int &squareSize);

const int arraySize = 80;

// function main begins program execution
int main()
{
	int hugeInt[arraySize] = {};
	int hugeIntSize = 0;
	inputHugeInt(hugeInt, hugeIntSize);

	for (int i = hugeIntSize - 1; i >= 0; --i)
		cout << hugeInt[i];
	if (quirksome(hugeInt, hugeIntSize))
		cout << " is a quirksome number\n\n";
	else
		cout << " is not a quirksome number\n\n";

	system("pause");
} // end function main

// enable user to input a positive huge integer from user
void inputHugeInt(int hugeInt[], int &hugeIntSize)
{
	char string[arraySize];
	cout << "Enter a positive integer of 10 or 12 digits: ";
	cin >> string;
	cout << endl;

	hugeIntSize = strlen(string);
	for (int i = 0; i < hugeIntSize; ++i)
		hugeInt[i] = string[hugeIntSize - i - 1] - '0';
}

bool quirksome(int hugeInt[], int hugeIntSize)
{
	int leng = hugeIntSize / 2;
	int num1[6] = { 0 };
	int num2[6] = { 0 };
	int num3[6] = { 0 };
	int square[12] = { 0 };
	int num1Size = 0;
	int num2Size = 0;
	int temp = 0;
	int squareSize = 0;

	// 將輸入數字的後半放到 num1，並計算長度
	for (int i = 0; i < leng; i++)
	{
		num1[i] = hugeInt[i];
		num1Size++;
	}

	// 將輸入數字的前半放到 num2，並計算長度
	int j = 0;
	for (int i = leng; i < hugeIntSize; i++)
	{
		num2[j] = hugeInt[i];
		j++;
		num2Size++;
	}

	// 若位數不夠則要補 0
	if (hugeIntSize == 10)
	{
		num1[5] = 0;
		num2[5] = 0;
	}

	addition(num1, num2, num3, num1Size, num2Size, temp);
	computeSquare(num3, square, temp, squareSize);
	if (equal(hugeInt, square, hugeIntSize, squareSize))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool equal(int hugeInt1[], int hugeInt2[], int hugeInt1Size, int hugeInt2Size)
{
	if (hugeInt1Size == hugeInt2Size)
	{
		for (int i = 0; i < hugeInt1Size; i++)
		{
			if (hugeInt1[i] != hugeInt2[i])     // 若有不一樣的，則回傳 false
			{
				return false;                   // 皆一樣，回傳true
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void addition(int addend[], int adder[], int sum[], int addendSize, int adderSize, int &sumSize)
{
	sumSize = (addendSize >= adderSize) ? addendSize : adderSize; // 判斷長度

	// 前半 + 後半
	for (int i = 0; i < addendSize; i++)
	{
		sum[i] = addend[i];
	}
	for (int i = 0; i < adderSize; i++)
	{
		sum[i] += adder[i];
	}
}

void computeSquare(int hugeInt[], int square[], int hugeIntSize, int &squareSize)
{
	int count;
	squareSize = hugeIntSize * 2;                              // 最後乘完的長度
	for (int i = 0; i < hugeIntSize; i++)
	{
		count = 0;
		for (int j = 0; j < hugeIntSize; j++)
		{
			square[i + j] += hugeInt[i] * hugeInt[j];          // 乘法
			count = i + j + 1;                                 // 計算 square 陣列總長度
		}

	}
	if (count != squareSize)                                   // 若 square 長度不符合最後乘完的長度，則補0
	{                                                          // ex : 00001 * 00001 = 000000001 ( 少一位 )
		for (int i = squareSize - 1; i > squareSize - 2; i--)
		{
			square[i] = 0;                                     // 補缺少的一位
		}
	}
	for (int i = 0; i < squareSize; i++)                       // 整理進位
	{
		while (square[i] > 9)
		{
			square[i] -= 10;
			square[i + 1]++;
		}
	}
}