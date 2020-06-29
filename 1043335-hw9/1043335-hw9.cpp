#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct AvailableRooms
{
	char date[12];
	unsigned int singleDayAvailRooms[6];
	// singleDayAvailRooms[0]: not used
	// singleDayAvailRooms[1]: the number of available superior rooms
	// singleDayAvailRooms[2]: the number of available deluxe rooms
	// singleDayAvailRooms[3]: the number of available deluxe twin rooms
	// singleDayAvailRooms[4]: the number of available superior suites
	// singleDayAvailRooms[5]: the number of available deluxe suites
};

bool check(AvailableRooms availableRooms[], int numRecords, char *ComeDate, char *LeaveDate); // 檢查日期是否存在
void loadFromFile(AvailableRooms availableRooms[], int &numRecords);
void makeReservation(AvailableRooms availableRooms[], int numRecords);
void saveToFile(AvailableRooms availableRooms[], int numRecords);


int main()
{
	AvailableRooms availableRooms[200] = { { "", 0, 0, 0, 0, 0 } };

	int numRecords;

	loadFromFile(availableRooms, numRecords); // read all records of the file availableRooms.dat,
	// put them into the array availableRooms, and
	// disply them on the screen

	makeReservation(availableRooms, numRecords); // make a room reservation; the numbers of available rooms
	// of the reserved room type and dates shoule be adjust

	saveToFile(availableRooms, numRecords); // save the modified available rooms information into the file availableRooms.dat

	loadFromFile(availableRooms, numRecords);

	system("pause");
}

void loadFromFile(AvailableRooms availableRooms[], int &numRecords)
{
	ifstream inFile("availableRooms.dat", ios::binary);

	if (!inFile)                                         // 判斷檔案是否正常開啟
	{
		cout << "Open Error" << endl;                    // 檔案無法開啟
		system("pause");
		exit(1);
	}
	else
	{
		numRecords = 0;
		while (!inFile.eof())                            // 判斷檔案是否讀取到最後
		{
			inFile.read(reinterpret_cast< char * >(&availableRooms[numRecords]), sizeof(AvailableRooms));
			numRecords++;
		}
		for (int i = 0; i < numRecords - 1; i++)         // 印出資料
		{
			cout << left << setw(15) << availableRooms[i].date; 
			for (int j = 1; j < 6; j++)
			{
				cout << setw(3) << availableRooms[i].singleDayAvailRooms[j];
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	inFile.close();                                      // 關閉檔案 
}

void saveToFile(AvailableRooms availableRooms[], int numRecords)
{
	ofstream outFile("availableRooms.dat", ios::binary);

	if (!outFile)                                         // 檢查文件可否接收輸出
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < numRecords - 1; i++)          // 將資料寫入檔案
		{
			outFile.write(reinterpret_cast< const char * >(&availableRooms[i]), sizeof(AvailableRooms));
		}
	}
}

void makeReservation(AvailableRooms availableRooms[], int numRecords)
{
	int num;
	char ComeDate[80];   // 來的日期
	char LeaveDate[80];  // 離開日期


	cout << "Please input the arrival date (yyyy-mm-dd): ";
	cin.getline(ComeDate,80);

	cout << "Please input the departure date (yyyy-mm-dd):";
	cin.getline(LeaveDate, 80);
	cout << endl << endl;

	if (!check(availableRooms, numRecords, ComeDate, LeaveDate))  // 檢查日期是否存在
	{
		cout << "日期不存在" << endl << endl;
		system("pause");
		exit(1);
	}

	cout << "Select Room Type：\n";
	cout << "1. Superior Room \n";
	cout << "2. Deluxe Room \n";
	cout << "3. Deluxe Twin Room \n";
	cout << "4. Superior Suite \n";
	cout << "5. Deluxe Suite \n";
    int menuchoice;
	do
	{
		cout << "?";
		cin >> menuchoice;
	} while ((menuchoice < 1) || (menuchoice > 5));
	cout << endl << endl;

	switch (menuchoice)  // 定幾間房間
	{
		case 1 :
			do
			{
				cout << "How many rooms ? ( 不可超過 9 間 ) : ";
				cin >> num;
			} while ((num > 9) || (num < 1));
			break;
		case 2 :
			do
			{
				cout << "How many rooms ? ( 不可超過 5 間 ) : ";
				cin >> num;
			} while ((num > 5) || (num < 1));
			break;
		case 3:
			do
			{
				cout << "How many rooms ? ( 不可超過 3 間 ) : ";
				cin >> num;
			} while ((num > 3) || (num < 1));
			break;
		case 4:
			do
			{
				cout << "How many rooms ? ( 不可超過 5 間 ) : ";
				cin >> num;
			} while ((num > 5) || (num < 1));
			break;
		case 5:
			do
			{
				cout << "How many rooms ? ( 不可超過 4 間 ) : ";
				cin >> num;
			} while ((num > 4) || (num < 1));
			break;
	}
	cout << endl;

	for (int b = 0; b < numRecords; b++)
	{
		// 找到來的日期
		if (strcmp(availableRooms[b].date, ComeDate) == 0)  
		{
			int e = b + 1;

			// 若要訂 02-29 晚上的房間
			if (strcmp(LeaveDate, "2016-03-01") == 0)       
			{
				// 資料只到02-29
				while (strcmp(availableRooms[e].date, "2016-02-29") != 0)
					e++;
				for (int i = b; i <= e; i++)
				{
					availableRooms[i].singleDayAvailRooms[menuchoice] -= num;  // 減去被預訂的房間數
				}
			}
			else
			{
				while (strcmp(availableRooms[e].date, LeaveDate) != 0)         // 計算到來的日期到離開日期
					e++;
				for (int i = b; i < e; i++)
				{
					availableRooms[i].singleDayAvailRooms[menuchoice] -= num;  // 減去被預訂的房間數
				}
			}
		}
	}	
}

bool check(AvailableRooms availableRooms[], int numRecords, char *ComeDate, char *LeaveDate)
{
	for (int i = 0; i < numRecords; i++)
	{
		if (strcmp(availableRooms[i].date, ComeDate) == 0)  // 輸入日期存在則回傳 true
		{
			for (int j = 0; j < numRecords; j++)
			{
				if (strcmp(availableRooms[j].date, LeaveDate) == 0 || strcmp(LeaveDate, "2016-03-01") == 0)
					return true;
			}
		}
	}
	return false;
}