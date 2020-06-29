//  Finds the two largest values among several integers

#include <iostream>
using namespace std;

int main()
{
	int num[100];      // array
	int first;         // 参璸Τ碭计
	int i;             // 跑计
	int Max, Sec;      // 程の材

	cout << "Enter the number of integers to be processed followed by the integers : ";  
	cout << endl;
	cin >> first;   // 块Τ碭计

	// 块计
	for (i = 0; i < first; i++)
	{
		cin >> num[i];
	}

	

	Max = 0;    // 砞﹚﹍ 0
	Sec = 0;    // 砞﹚﹍ 0

	
	// ㄏノ array ㄓ碝т程
	for(i = 0; i < first; i++)
	{
		if (num[i] > Max)
		{
			Max = num[i];
		}
	}

	// ㄏノ array ㄓт材
	for(i = 0; i < first; i++)
	{
		if (num[i] != Max)     // 埃程计暗ゑ耕
		{
			if (num[i] > Sec)
			{
				Sec = num[i];
			}
		}
	}

	cout << "Largest is " << Max << endl;           // 块程
	cout << "Second largest is " << Sec << endl;    // 块材



	system("pause");
	return 0;

}