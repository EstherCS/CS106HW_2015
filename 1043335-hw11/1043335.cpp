#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace std;

struct Date
{
	int year;
	int month;
	int day;
};

struct ReservationInfo
{
	char id[12];
	char name[12];
	char mobile[12];
	int roomType;
	int numRooms;
	Date checkInDate;
	Date checkOutDate;
};

struct AvailableRooms
{
	Date date;
	int availableRooms[6]; // number of available rooms
};

int roomRate[6] = { 0, 5390, 6270, 6270, 6820, 8470 };
int numRooms[6] = { 0, 9, 5, 3, 5, 4 };
char roomTypeName[6][20] = { "", "Superior Room", "Deluxe Room", "Deluxe Twin Room", "Superior Suite", "Deluxe Suite" };
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int enterChoice();
void makeReservation();
void display(ReservationInfo reservation, time_t numNights);
void computeCurrentDate(Date &currentDate);
void inputDates(Date currentDate, Date &checkInDate, Date &checkOutDate);
void loadAvailableRooms(AvailableRooms availableRooms[], int &numRecords);
void initializeAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords);
void adjustAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords);
int compareDates(Date date1, Date date2);
void displayDate(Date date);
bool legal(char id[]);
void saveReservationInfo(ReservationInfo reservation);
void saveAvailableRooms(AvailableRooms availableRooms[], int numRecords);
void ReservationInquiry();

int main()
{
	cout << "Evergreen Laurel Hotel Online Reservation System\n";

	int choice;

	while ((choice = enterChoice()) != 3)
	{
		switch (choice)
		{
		case 1:
			makeReservation();
			break;
		case 2:
			ReservationInquiry();
			break;
		default:
			cerr << "\nInput Error!" << endl;
		}
	}

	cout << endl;

	system("pause");
}

int enterChoice()
{
	cout << "\nInput your choice：\n"
		<< "1. Making Reservation\n"
		<< "2. Reservation Inquiry\n"
		<< "3. end program\n? ";

	int menuChoice;
	cin >> menuChoice;
	return menuChoice;
}

void makeReservation()                              // 訂房
{
	Date currentDate = {};
	computeCurrentDate(currentDate);                // 印出現在時間

	AvailableRooms availableRooms[184] = {};
	int numRecords = 0;

	loadAvailableRooms(availableRooms, numRecords); // 讀取檔案

	ReservationInfo reservation;
	inputDates(currentDate, reservation.checkInDate, reservation.checkOutDate); // 輸入入住和離開時間

	cout << endl << endl;
	cout << "Check in date : " << reservation.checkInDate.year << "-" << setw(2) << setfill('0') << reservation.checkInDate.month << "-" << setw(2) << reservation.checkInDate.day << endl;
	cout << "Check out date : " << reservation.checkOutDate.year << "-" << setw(2) << setfill('0') << reservation.checkOutDate.month << "-" << setw(2) << reservation.checkOutDate.day << endl;
	cout << endl << endl;

	// 將日期第一天調整為入住這天
	if (numRecords == 0 || compareDates(availableRooms[numRecords - 2].date, reservation.checkOutDate) == -1)
		initializeAvailableRooms(availableRooms, reservation.checkInDate, numRecords);
	else if (compareDates(availableRooms[1].date, reservation.checkInDate) == -1)
		adjustAvailableRooms(availableRooms, reservation.checkInDate, numRecords);

	int InNum = 0;
	for (int i = 0; i < numRecords; i++)            // 計算 checkInDate 為第幾筆
	{
		if (availableRooms[i].date.year < reservation.checkInDate.year)
			InNum++;
		else if (availableRooms[i].date.year == reservation.checkInDate.year)
		{
			if (availableRooms[i].date.month < reservation.checkInDate.month)
				InNum++;
			else if (availableRooms[i].date.month == reservation.checkInDate.month)
			{
				if (availableRooms[i].date.day < reservation.checkInDate.day)
					InNum++;
			}
		}
	}

	int OutNum = 0;
	for (int i = 0; i < numRecords; i++)             // 計算 checkOutDate 為第幾筆
	{
		if (availableRooms[i].date.year < reservation.checkOutDate.year)
			OutNum++;
		else if (availableRooms[i].date.year == reservation.checkOutDate.year)
		{
			if (availableRooms[i].date.month < reservation.checkOutDate.month)
				OutNum++;
			else if (availableRooms[i].date.month == reservation.checkOutDate.month)
			{
				if (availableRooms[i].date.day < reservation.checkOutDate.day)
					OutNum++;
			}
		}
	}
	// -------------------------------------------- 印出房型
	cout << "The number of available rooms of each room type:\n\n";
	cout << "      Date   Superior Room   Deluxe Room   Deluxe Twin Room   Superior Suite   Deluxe Suite\n";

	struct tm time1;                                 // 計算 1900 到入住那天的秒數
	time1.tm_mday = reservation.checkInDate.day;
	time1.tm_mon = reservation.checkInDate.month;
	time1.tm_year = reservation.checkInDate.year - 1900;
	time1.tm_hour = 0;
	time1.tm_min = 0;
	time1.tm_sec = 0;
	time_t numDays1 = mktime(&time1) / (24 * 3600);  // 利用秒數算天數

	struct tm time2;                                 // 計算 1900 到離開那天的秒數
	time2.tm_mday = reservation.checkOutDate.day;
	time2.tm_mon = reservation.checkOutDate.month;
	time2.tm_year = reservation.checkOutDate.year - 1900;
	time2.tm_hour = 0;
	time2.tm_min = 0;
	time2.tm_sec = 0;
	time_t numDays2 = mktime(&time2) / (24 * 3600);


	for (int i = InNum; i < OutNum; i++)
		cout << availableRooms[i].date.year << "-" << setw(2) << setfill('0') << availableRooms[i].date.month << "-" << setw(2) << availableRooms[i].date.day
		<< setw(16) << setfill(' ') << availableRooms[i].availableRooms[1]
		<< setw(14) << availableRooms[i].availableRooms[2]
		<< setw(19) << availableRooms[i].availableRooms[3]
		<< setw(17) << availableRooms[i].availableRooms[4]
		<< setw(15) << availableRooms[i].availableRooms[5] << "\n";

	cout << endl << endl;
	cout << "Select Room Type：\n";
	cout << "1. Superior Room \n";
	cout << "2. Deluxe Room \n";
	cout << "3. Deluxe Twin Room \n";
	cout << "4. Superior Suite \n";
	cout << "5. Deluxe Suite \n";
	do   // 選擇房型
	{
		cout << "?";
		cin >> reservation.roomType;
	} while ((reservation.roomType < 1) || (reservation.roomType > 5));
	cout << endl << endl;
	do   // 選擇幾間                                            
	{
		cout << "Number of rooms ( " << availableRooms[InNum].availableRooms[reservation.roomType] << " rooms available ): ";
		cin >> reservation.numRooms;
	} while (reservation.numRooms > availableRooms[InNum].availableRooms[reservation.roomType] || reservation.numRooms < 1);

	for (int i = InNum; i < OutNum; i++)              // 減去被預訂的房間數
	{
		availableRooms[i].availableRooms[reservation.roomType] -= reservation.numRooms;
	}

	do   // 輸入身分證字號
	{
		cout << " ID Number：";
		cin >> reservation.id;
	} while (legal(reservation.id) == false);
	cout << endl << endl;

	cout << " Name：";                                // 輸入名字
	cin.ignore();                                     // 要刪去緩存區的東西
	cin.getline(reservation.name, 12);
	cout << endl << endl;

	do   // 輸入手機號碼
	{
		cout << "Mobile Phone：";
		cin >> reservation.mobile;
		cout << endl << endl;
	} while (strlen(reservation.mobile) != 10);

	time_t numNights = numDays2 - numDays1;           // 總共住幾天
	display(reservation, numNights);
	saveReservationInfo(reservation);
	saveAvailableRooms(availableRooms, numRecords);
}

void display(ReservationInfo reservation, time_t numNights) // 印出訂單
{
	cout << "Your reservations:" << endl << endl;
	cout << "      Name      Fare        Mobile        Room type    Number of rooms   Check in date   Check out date\n";
	cout << setw(10) << setfill(' ') << reservation.name
		<< setw(10) << setfill(' ') << roomRate[reservation.roomType] * reservation.numRooms * numNights
		<< setw(14) << setfill(' ') << reservation.mobile
		<< setw(17) << setfill(' ') << roomTypeName[reservation.roomType]
		<< setw(19) << setfill(' ') << reservation.numRooms
		<< setw(10) << setfill(' ') << reservation.checkInDate.year << "-"
		<< setw(2) << setfill('0') << reservation.checkInDate.month << "-"
		<< setw(2) << reservation.checkInDate.day
		<< setw(11) << setfill(' ') << reservation.checkOutDate.year << "-"
		<< setw(2) << setfill('0') << reservation.checkOutDate.month << "-"
		<< setw(2) << reservation.checkOutDate.day
		<< "\n";
}

void computeCurrentDate(Date &currentDate)  // 印出現在日期
{
	tm structuredTime;
	time_t rawTime = time(0);
	localtime_s(&structuredTime, &rawTime);

	currentDate.year = structuredTime.tm_year + 1900;
	currentDate.month = structuredTime.tm_mon + 1;
	currentDate.day = structuredTime.tm_mday;

	cout << "The current date is " << currentDate.year << "-"
		<< setw(2) << setfill('0') << currentDate.month << "-"
		<< setw(2) << currentDate.day << endl << endl;
}

void inputDates(Date currentDate, Date &checkInDate, Date &checkOutDate) // 選擇入住和離開時間
{
	cout << "Please Input Check In Date";
	cout << endl << endl;
	int y[7];                             // 設定年
	y[1] = currentDate.year;
	for (int i = 2; i < 7; i++)
	{
		y[i] = currentDate.year;          // 全部先設定為當前年分
	}
	int m[7];                             // 設定月和進位
	m[1] = currentDate.month;
	for (int i = 2; i < 7; i++)
	{
		m[i] = currentDate.month + i - 1;
		if (m[i] > 12)
		{
			m[i] -= 12;
			y[i]++;
		}
	}
	int checkIn;                          // 印出入住選單
	do
	{
		cout << "Month：" << endl;
		for (int i = 1; i < 7; i++)
		{
			cout << i << ". " << y[i] << " - " << m[i] << endl;
		}
		cout << endl << "?";
		cin >> checkIn;
	} while (checkIn > 6 || checkIn < 1);

	checkInDate.year = y[checkIn];
	checkInDate.month = m[checkIn];

	int day1;                             // 印出當月日期範圍
	if (checkIn == 1)                     // 選項一為當月
	{
		do
		{
			cout << "Day ( " << currentDate.day << " ~ " << days[currentDate.month] << " ) :";
			cin >> day1;
		} while (day1 > days[currentDate.month] || day1 < currentDate.day);
	}
	else
	{
		do                                // 印出一號到該月最後一天
		{
			cout << "Day ( 1 " << " ~ " << days[m[checkIn]] << " ) :";
			cin >> day1;
		} while (day1 > days[m[checkIn]] || day1 < 1);
	}
	int mon = m[checkIn];
	checkInDate.day = day1;

	int checkOut;                                  // 印出離開選單
	cout << endl;
	if (day1 != days[m[checkIn]] && checkIn == 1)  // 日期不是當月最後一天且為選單第一個月
	{
		do
		{
			cout << "Month：" << endl;
			for (int i = 1; i < 7; i++)
			{
				cout << i << ". " << y[i] << " - " << m[i] << endl;
			}
			cout << endl << "?";
			cin >> checkOut;
		} while (checkOut > 6 || checkOut < 1);
	}
	else if (day1 == days[m[checkIn]])              // 日期為當月最後一天 
	{
		m[1] = m[checkIn] + 1;                     // 選項從下個月開始
		if (m[1] > 12)
		{
			m[1] -= 12;
			y[1]++;
		}
		for (int i = 2; i < 7; i++)                // 進位
		{
			m[i] = m[1] + i - 1;
			if (m[i] > 12)
			{
				m[i] -= 12;
				y[i]++;
			}
		}
		do                                         // 印出
		{
			cout << "Month：" << endl;
			for (int i = 1; i < 7; i++)
			{
				cout << i << ". " << y[i] << " - " << m[i] << endl;
			}
			cout << endl << "?";
			cin >> checkOut;
		} while (checkOut > 6 || checkOut < 1);
	}
	else                                           // 日期不為當月最後一天 且不是選單第一個月
	{                                              // 此月份前的都去掉
		m[1] = m[checkIn];
		y[1] = y[checkIn];
		if (m[1] > 12)
		{
			m[1] -= 12;
			y[1]++;
		}
		for (int i = 2; i < 7; i++)
		{
			m[i] = m[1] + i - 1;
			if (m[i] > 12)
			{
				m[i] -= 12;
				y[i]++;
			}
		}
		do
		{
			cout << "Month：" << endl;
			for (int i = 1; i < 7; i++)
			{
				cout << i << ". " << y[i] << " - " << m[i] << endl;
			}
			cout << endl << "?";
			cin >> checkOut;
		} while (checkOut > 6 || checkOut < 1);
	}
	checkOutDate.year = y[checkOut];
	checkOutDate.month = m[checkOut];

	int day2;
	if (mon == m[checkOut])                       // 印出當月日期範圍 ( 入住和離開同月份 )
	{
		if (day1 + 1 > days[m[checkIn]])
			day1 -= days[m[checkIn]];
		do
		{
			cout << "Day ( " << day1 + 1 << " ~ " << days[currentDate.month] << " ) :";
			cin >> day2;
		} while (day2 > days[currentDate.month] || day2 < day1 + 1);
	}
	else
	{
		do
		{
			cout << "Day ( 1 " << " ~ " << days[m[checkOut]] << " ) :";
			cin >> day2;
		} while (day2 > days[m[checkOut]] || day2 <  1);
	}
	checkOutDate.day = day2;
}

void loadAvailableRooms(AvailableRooms availableRooms[], int &numRecords)   // 讀檔案
{
	ifstream inFile("Available Rooms.dat", ios::binary);

	if (!inFile)
	{
		ofstream inFile("Available Rooms.dat", ios::binary);
		if (!inFile)
		{
			cerr << "Error" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			fstream inFile("Available Rooms.dat", ios::in | ios::out | ios::binary);
			numRecords = 0;
			while (!inFile.eof())                                           // 判斷檔案是否讀取到最後
			{
				inFile.read(reinterpret_cast< char * >(&availableRooms[numRecords]), sizeof(AvailableRooms));
				numRecords++;
			}
		}

	}
	else
	{
		numRecords = 0;
		while (!inFile.eof())
		{
			inFile.read(reinterpret_cast<char *>(&availableRooms[numRecords]), sizeof(AvailableRooms));
			numRecords++;
		}
		inFile.close();                                                      // 關閉檔案
	}
}

void initializeAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords)  // 初始化過期資料
{
	availableRooms[0].date = currentDate;                     // 第一天為入住日期
	for (int j = 1; j < 6; j++)
		availableRooms[0].availableRooms[j] = numRooms[j];

	for (int i = 1; i <= numRecords; i++)                     // 將過期資料取代 
	{
		availableRooms[i].date = currentDate;
		for (int j = 1; j < 6; j++)
			availableRooms[i].availableRooms[j] = numRooms[j];

		availableRooms[i].date.day += i;

		// 將年月日進位
		// 若日大於本月天數 & 月份大於十二月
		while (availableRooms[i].date.day > days[availableRooms[i].date.month] || availableRooms[i].date.month > 12)
		{
			if (availableRooms[i].date.month > 12)
			{
				availableRooms[i].date.month -= 12;
				availableRooms[i].date.year++;
			}
			if (availableRooms[i].date.day > days[availableRooms[i].date.month])
			{
				availableRooms[i].date.day -= days[availableRooms[i].date.month];
				availableRooms[i].date.month++;
			}
		}
	}
}

void adjustAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords)  // 第一天調整為入住日期
{
	int num = 0;
	for (int i = 0; i < numRecords; i++)                      // 計算有幾天過期
	{
		if (availableRooms[i].date.year < currentDate.year)
			num++;
		else if (availableRooms[i].date.year == currentDate.year)
		{
			if (availableRooms[i].date.month < currentDate.month)
				num++;
			else if (availableRooms[i].date.month == currentDate.month)
			{
				if (availableRooms[i].date.day < currentDate.day)
					num++;
			}
		}
	}
	for (int i = 0; i < numRecords; i++)                      // 將過期資料取代 
	{
		availableRooms[i] = availableRooms[i + num - 1];
	}
}

int compareDates(Date date1, Date date2)  // 比較日期是否過期
{
	if (date1.year > date2.year)
		return 1;
	if (date1.year < date2.year)
		return -1;
	if (date1.month > date2.year)
		return 1;
	if (date1.month < date2.year)
		return -1;
	if (date1.day > date2.day)
		return 1;
	if (date1.day < date2.day)
		return -1;
	if (date1.day == date2.day)
		return 0;
}

bool legal(char id[])                       // 判斷身分證是否違法
{
	if (isalpha(id[0] - '0') != 0)          // 檢查英文
		return false;
	if (strlen(id) != 10)
		return false;
	int check[26] = { 10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33 };
	int area;
	int sum = 0;

	if (id[0] >= 'A' && id[0] <= 'Z')
		area = id[0] - 'A';                 // 為 ASCII 
	else if (id[0] >= 'a' && id[0] <= 'z')
		area = id[0] - 'a';

	sum += (check[area] % 10) * 9 + (check[area] / 10);
	int j = 8;
	for (int i = 1; i < 9; i++, j--)
		sum += (id[i] - '0') * j;

	sum = sum % 10;
	if ((10 - sum) == id[9] - '0')
		return true;
	else
		return false;
}

void saveReservationInfo(ReservationInfo reservation)   // 儲存訂單
{
	ofstream inFile("Reservations.dat", ios::out | ios::app | ios::binary);

	if (!inFile)
	{
		ofstream inFile("Reservations.dat", ios::binary);
		if (!inFile)
		{
			cerr << "Error" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			inFile.write(reinterpret_cast< const char * >(&reservation), sizeof(ReservationInfo));
		}
	}
	else
	{
		inFile.clear();
		inFile.write(reinterpret_cast< const char * >(&reservation), sizeof(ReservationInfo));
	}
	inFile.close();
}

void saveAvailableRooms(AvailableRooms availableRooms[], int numRecords) // 儲存房間數
{
	ofstream outFile("Available Rooms.dat", ios::binary);
	if (!outFile)                                                         // 檢查文件可否接收輸出
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < numRecords - 1; i++)                         // 將資料寫入檔案
		{
			outFile.write(reinterpret_cast< const char * >(&availableRooms[i]), sizeof(AvailableRooms));
		}
	}
}

void ReservationInquiry()     // 重新顯示訂單
{
	char id[12];
	cout << endl;
	cout << "Enter Your ID Number：";
	cin >> id;

	ifstream inFile("Reservations.dat", ios::binary);

	if (!inFile)
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		ReservationInfo reservation[200] = { "", "", "", 0, 0, 0, 0, 0 };
		int numRecords = 0;

		while (inFile.read(reinterpret_cast<char *>(&reservation[numRecords]), sizeof(ReservationInfo)))
		{
			numRecords++;
		}
		inFile.close();        // 關閉檔案

		for (int i = 0; i < numRecords; i++)
		{
			if (strcmp(reservation[i].id, id) == 0)
			{
				struct tm time1;
				time1.tm_mday = reservation[i].checkInDate.day;
				time1.tm_mon = reservation[i].checkInDate.month;
				time1.tm_year = reservation[i].checkInDate.year - 1900;
				time1.tm_hour = 0;
				time1.tm_min = 0;
				time1.tm_sec = 0;
				time_t numDays1 = mktime(&time1) / (24 * 3600);

				struct tm time2;
				time2.tm_mday = reservation[i].checkOutDate.day;
				time2.tm_mon = reservation[i].checkOutDate.month;
				time2.tm_year = reservation[i].checkOutDate.year - 1900;
				time2.tm_hour = 0;
				time2.tm_min = 0;
				time2.tm_sec = 0;
				time_t numDays2 = mktime(&time2) / (24 * 3600);
				time_t numNights = numDays2 - numDays1;
				display(reservation[i], numNights);
			}
		}
	}
}