#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
using namespace::std;

struct Date
{
	int year;
	int month;
	int day;
	int hour;
};

struct MemberRecord
{
	char accountNumber[24]; // account number
	char password[24];      // password
	char IDNumber[12];      // ID number
	char name[8];           // name
};

struct ReservationRecord
{
	char accountNumber[24]; // account number
	int branchCode;           // branch code
	Date date;                // reservation date
	int hour;                 // reservation hour
	int boxTypeCode;          // box type code
	int numCustomers;         // number of customers
};

char brancheNames[16][24] = { "", "Taipei Dunhua South", "Taipei SOGO", "Taipei Songjiang",
"Taipei Nanjing", "Taipei Linsen", "Taipei Zhonghua New",
"Banqiao Guanqian", "Yonghe Lehua", "Taoyuan Zhonghua",
"Zhongli Zhongyang", "Hsinchu Beida", "Taichung Ziyou",
"Chiayi Ren'ai", "Tainan Ximen", "Kaohsiung Zhonghua New" };

// input memberDetails from the file Members.dat
void loadMemberDetails(MemberRecord memberDetails[], int &numMembers);

// input reservations from the file Reservations.dat
void loadReservations(ReservationRecord reservations[], int &numReservations);

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end);

// login and display the submenu
void login(MemberRecord memberDetails[], int numMembers, ReservationRecord reservations[], int &numReservations);

// there exists a member with specified accountNumber and password
bool legal(char accountNumber[], char password[], MemberRecord memberDetails[], int &numMembers);

// add a new reservation for the member with specified account number
void reservation(char accountNumber[], ReservationRecord reservations[], int &numReservations);

// compute the current date
void compCurrentDate(Date &currentDate);

// compute 7 dates which is starting from the current date
void compAvailableDates(Date currentDate, Date availableDates[]);

// display all fields of reservation
void output(ReservationRecord reservation);

// display all reservations for the member with specified account number,
// then let the member to choose one of them to delete
void queryDelete(char accountNumber[], ReservationRecord reservations[], int &numReservations);

// add a new member
void registration(MemberRecord memberDetails[], int &numMembers);

// return true if IDNumber belongs to memberDetails
bool existingID(char IDNumber[], MemberRecord memberDetails[], int &numMembers);

// return true if accountNumber belongs to memberDetails
bool existingAccount(char accountNumber[], MemberRecord memberDetails[], int &numMembers);

// output all memberDetails into the file Members.dat
void saveMemberDetails(MemberRecord memberDetails[], int numMembers);

// output all reservations into the file Reservations.dat
void saveReservations(ReservationRecord reservations[], int numReservations);

int main()
{
	MemberRecord memberDetails[100] = {};     // member details for all members
	ReservationRecord reservations[100] = {}; // all reservations
	int numMembers = 0;      // number of members
	int numReservations = 0; // number of reservations 

	loadMemberDetails(memberDetails, numMembers);
	loadReservations(reservations, numReservations);

	cout << "Welcome to the Cashbox Party World!\n\n";

	int choice;

	while (true)
	{
		cout << "1 - Login\n";
		cout << "2 - Registration\n";
		cout << "3 - End\n";

		do cout << "\nEnter your choice (1~3): ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice)
		{
		case 1:
			login(memberDetails, numMembers, reservations, numReservations);
			break;

		case 2:
			registration(memberDetails, numMembers);
			break;

		case 3:
			saveMemberDetails(memberDetails, numMembers);
			cout << "Thank you! Goodbye!\n\n";
			system("pause");
			return 0;

		default:
			cout << "\nIncorrect choice!\n";
			break;
		}
	}

	system("pause");
}

void login(MemberRecord memberDetails[], int numMembers, ReservationRecord reservations[], int &numReservations)
{
	char accountNumber[24] = "";
	char password[24] = "";

	do {
		cout << "Please enter your account number: ";
		cin >> accountNumber;
		cout << "Enter your password: ";
		cin >> password;

	} while (!legal(accountNumber, password, memberDetails, numMembers));

	cin.ignore();

	int choice;

	while (true)
	{
		cout << "\n1 - Make Reservation\n";
		cout << "2 - Reservation Enquiry/Canceling\n";
		cout << "3 - End\n";

		do cout << "\nEnter your choice (1~3): ";
		while ((choice = inputAnInteger(1, 3)) == -1);
		cout << endl;

		switch (choice)
		{
		case 1:
			reservation(accountNumber, reservations, numReservations);
			break;

		case 2:
			queryDelete(accountNumber, reservations, numReservations);
			break;

		case 3:
			return;

		default:
			cout << "\nIncorrect choice!\n";
			break;
		}
	}
}

bool legal(char accountNumber[], char password[], MemberRecord memberDetails[], int &numMembers)
{
	for (int i = 0; i < numMembers; i++)
	if (strcmp(accountNumber, memberDetails[i].accountNumber) == 0 &&
		strcmp(password, memberDetails[i].password) == 0)
		return true;

	cout << "\nInvalid account number or password. Please try again.\n\n";
	return false;
}

/*
void compCurrentDate( Date &currentDate )
{
currentDate.year = 2015;
currentDate.month = 12;
currentDate.day = 28;
currentDate.hour = 12;
}*/
/*
void compCurrentDate(Date &currentDate)
{
	currentDate.year = 2016;
	currentDate.month = 2;
	currentDate.day = 26;
	currentDate.hour = 23;
}

void compCurrentDate( Date &currentDate )
{
currentDate.year = 2015;
currentDate.month = 2;
currentDate.day = 26;
currentDate.hour = 23;
}

*/
void compCurrentDate(Date &currentDate)
{
tm structuredTime;
time_t rawTime = time(0);
localtime_s(&structuredTime, &rawTime);

currentDate.year = structuredTime.tm_year + 1900;
currentDate.month = structuredTime.tm_mon + 1;
currentDate.day = structuredTime.tm_mday;
currentDate.hour = structuredTime.tm_hour;
}

void output(ReservationRecord reservation)
{
	char boxTypes[3][16] = { "", "Standard", "Party" };

	cout << setw(17) << reservation.accountNumber
		<< setw(26) << brancheNames[reservation.branchCode]
		<< setw(8) << reservation.date.year << '-'
		<< setw(2) << setfill('0') << reservation.date.month << '-'
		<< setw(2) << setfill('0') << reservation.date.day
		<< setw(8) << setfill(' ') << reservation.hour
		<< setw(13) << boxTypes[reservation.boxTypeCode]
		<< setw(19) << reservation.numCustomers << endl;
}

bool existingID(char IDNumber[], MemberRecord memberDetails[], int &numMembers)
{
	for (int i = 0; i < numMembers; i++)
	if (strcmp(IDNumber, memberDetails[i].IDNumber) == 0)
		return true;
	return false;
}

bool existingAccount(char accountNumber[], MemberRecord memberDetails[], int &numMembers)
{
	for (int i = 0; i < numMembers; i++)
	if (strcmp(accountNumber, memberDetails[i].accountNumber) == 0)
		return true;
	return false;
}

// 讀檔 Members.dat
void loadMemberDetails(MemberRecord memberDetails[], int &numMembers)
{
	ifstream infile("Members.dat", ios::binary);

	if (!infile)
	{
		cerr << "Open Members.dat Error !";
		system("pause");
		exit(1);
	}
	else
	{
		while (!infile.eof())
		{

			infile.read(reinterpret_cast <char *>(&memberDetails[numMembers]), sizeof(MemberRecord));
			numMembers++;
		}
	}
	infile.close();
}

// 讀檔 Reservations.dat
void loadReservations(ReservationRecord reservations[], int &numReservations)
{
	ifstream infile("Reservations.dat", ios::binary);

	if (!infile)
	{
		cerr << "Open Reservations.dat Error !";
		system("pause");
		exit(1);
	}
	else
	{
		while (!infile.eof())
		{
			infile.read(reinterpret_cast <char *>(&reservations[numReservations]), sizeof(ReservationRecord));
			numReservations++;
		}
	}
	infile.close();
}

// input an integer in the range [ begin, end ]
int inputAnInteger(int begin, int end)
{
	char choise[200];
	cin >> choise;
	int len = strlen(choise);
	for (int i = 0; i < len; i++)
	{
		if (isalnum(choise[i] - '0') != 0) // 若不是數字則錯誤
			return -1;
	}
	int number = atoi(choise);             // 轉成 int 型態
	if (number >= begin && number <= end)
		return number;
	else
		return -1;
}

// add a new reservation for the member with specified account number
// 會員訂位
void reservation(char accountNumber[], ReservationRecord reservations[], int &numReservations)
{
	strcpy_s(reservations[numReservations].accountNumber, accountNumber); // 放入結構中

	for (int i = 1; i < 16; i++)   // 印出店名
	{
		cout << i << ". " << brancheNames[i] << endl;
	}
	do
	{
		cout << endl << "Enter your choice (0 to end): ";
	} while ((reservations[numReservations].branchCode = inputAnInteger(0, 15)) == -1);
	cout << endl << endl;
	if (reservations[numReservations].branchCode == 0)
		return;
	else
	{
		Date currentDate = {};
		compCurrentDate(currentDate); // 印現在的日期時間
		cout << "The current hour is " << currentDate.year << "/" << currentDate.month << "/" << currentDate.day << "/" << currentDate.hour << endl << endl;
		Date availableDates[8];
		compAvailableDates(currentDate, availableDates);

		int day;
		do  // 輸入要哪一天
		{
			cout << endl << "Enter your choice (0 to end):";
		} while ((day = inputAnInteger(0, 7)) == -1);
		if (day == 0)
			return;
		reservations[numReservations].date.year = availableDates[day].year;
		reservations[numReservations].date.month = availableDates[day].month;
		reservations[numReservations].date.day = availableDates[day].day;
		cout << endl << endl;
		if (day == 1 && currentDate.day == reservations[numReservations].date.day) // 如果是選項一 && 是預定當天 
		{                                                                          // 若當天為 23 時，選項一為下一天
			do
			{
				cout << "Enter hour ( " << currentDate.hour + 1 << " ~ 23 ) : ";
			} while ((reservations[numReservations].hour = inputAnInteger(currentDate.hour + 1, 23)) == -1);
		}
		else
		{
			do
			{
				cout << "Enter hour ( 0 ~ 23 ) : ";
			} while ((reservations[numReservations].hour = inputAnInteger(0, 23)) == -1);
		}

		cout << endl << endl;
		do // 輸入人數
		{
			cout << "Enter the number of customers (1~30, 0 to end): ";
		} while ((reservations[numReservations].numCustomers = inputAnInteger(0, 30)) == -1);
		if (reservations[numReservations].numCustomers == 0)
			return;
		cout << endl << endl;
		cout << "1. Standard Room" << endl;
		cout << "2. Party Room" << endl << endl;
		do
		{
			cout << " Enter your choice (0 to end):";
		} while ((reservations[numReservations].boxTypeCode = inputAnInteger(0, 2)) == -1);
		if (reservations[numReservations].accountNumber == 0)
			return;
		cout << endl << endl;
		cout << "      Account Number                    Branch          Date    Hour    Room Type    No of Customers" << endl;
		cout << "   ";
		output(reservations[numReservations]);
		cout << endl << "Reservation Completed!" << endl << endl;
		saveReservations(reservations, numReservations);
		numReservations++;
	}
}

// compute 7 dates which is starting from the current date
// 顯示七天
void compAvailableDates(Date currentDate, Date availableDates[])
{
	char leap[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char normal[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	for (int i = 1; i < 8; i++)
	{
		availableDates[i] = currentDate;
	}
	if (currentDate.hour == 23) // 若為 23 時
	{
		for (int i = 1; i < 8; i++)
		{
			availableDates[i].day = currentDate.day + i;
			if (((currentDate.year % 4 == 0) && (currentDate.year % 100) != 0) || currentDate.year % 400 == 0) // 判斷潤平年
			{
				while (availableDates[i].day > leap[availableDates[i].month] || availableDates[i].month > 12)
				{
					if (availableDates[i].day > leap[availableDates[i].month])
					{
						availableDates[i].day -= leap[availableDates[i].month];
						availableDates[i].month++;
					}
					if (availableDates[i].month > 12)
					{
						availableDates[i].month -= 12;
						availableDates[i].year++;
					}
				}
			}
			else
			{
				while (availableDates[i].day > normal[availableDates[i].month] || availableDates[i].month > 12)
				{
					if (availableDates[i].day > normal[availableDates[i].month])
					{
						availableDates[i].day -= normal[availableDates[i].month];
						availableDates[i].month++;
					}
					if (availableDates[i].month > 12)
					{
						availableDates[i].month -= 12;
						availableDates[i].year++;
					}
				}
			}
		}
		for (int i = 1; i < 8; i++)
		{
			cout << i << ". " << availableDates[i].year << "/" << availableDates[i].month << "/" << availableDates[i].day << endl;
		}
	}
	else // 非 23 時
	{
		for (int i = 1; i < 8; i++)
		{
			availableDates[i].day = currentDate.day + i - 1;
			if (((currentDate.year % 4 == 0) && (currentDate.year % 100) != 0) || currentDate.year % 400 == 0) // 判斷潤平年
			{
				while (availableDates[i].day > leap[availableDates[i].month] || availableDates[i].month > 12)
				{
					if (availableDates[i].day > leap[availableDates[i].month])
					{
						availableDates[i].day -= leap[availableDates[i].month];
						availableDates[i].month++;
					}
					if (availableDates[i].month > 12)
					{
						availableDates[i].month -= 12;
						availableDates[i].year++;
					}
				}
			}
			else
			{
				while (availableDates[i].day > normal[availableDates[i].month] || availableDates[i].month > 12)
				{
					if (availableDates[i].day > normal[availableDates[i].month])
					{
						availableDates[i].day -= normal[availableDates[i].month];
						availableDates[i].month++;
					}
					if (availableDates[i].month > 12)
					{
						availableDates[i].month -= 12;
						availableDates[i].year++;
					}
				}
			}
		}
		for (int i = 1; i < 8; i++)
		{
			cout << i << ". " << availableDates[i].year << "/" << availableDates[i].month << "/" << availableDates[i].day << endl;
		}
	}
}

// display all reservations for the member with specified account number,
// then let the member to choose one of them to delete
// 顯示所有訂單 & 可刪除訂單
void queryDelete(char accountNumber[], ReservationRecord reservations[], int &numReservations)
{
	ifstream infile("Reservations.dat", ios::binary);

	if (!infile)
	{
		cerr << "Open Error!";
		system("pause");
		exit(1);
	}
	else
	{
		int temp[200] = { 0 };
		int j = 1;
		int num = 0;
		while (infile.read(reinterpret_cast <char *>(&reservations[num]), sizeof(ReservationRecord)))
		{
			num++;
		}
		for (int i = 0; i < num; i++)
		{
			if (strcmp(accountNumber, reservations[i].accountNumber) == 0)
			{
				temp[j] = i;
				//cout << temp[j] << " , " << i << endl;;
				cout << "      Account Number                    Branch          Date    Hour    Room Type    No of Customers" << endl;
				cout << j << ". ";
				output(reservations[i]);
				j++;
			}
		}
		int numCancle;
		do
		{
			cout << "Choose a reservation to cancel (0: keep all reservations): ";
		} while ((numCancle = inputAnInteger(0, j)) == -1);
		if (numCancle == 0)
			return;
		else
		{
			for (int i = numCancle; i < num; i++) // 刪除選擇的訂單
			{
				reservations[temp[i]] = reservations[temp[i + 1]];
			}
			num--;
			ofstream out("Reservations.dat", ios::binary); // 存檔
			if (!out)
			{
				cerr << "Error!";
				system("pause");
				exit(1);
			}
			else
			{
				for (int i = 0; i < num; i++)
				{
					out.write(reinterpret_cast <const char *>(&reservations[i]), sizeof(ReservationRecord));
				}
			}
		}
	}
}

// 新增帳號
void registration(MemberRecord memberDetails[], int &numMembers)
{
	cout << "Input your ID Number: ";
	cin >> memberDetails[numMembers].IDNumber;
	int idCheck;
	idCheck = existingID(memberDetails[numMembers].IDNumber, memberDetails, numMembers);
	if (idCheck == true)
	{
		cout << endl << "You are already a member!" << endl << endl;
		return;
	}
	else
	{
		cout << "Input your Name: ";
		cin >> memberDetails[numMembers].name;
		cout << "Choose an account number: ";
		cin >> memberDetails[numMembers].accountNumber;
		int checkACC;
		checkACC = existingAccount(memberDetails[numMembers].accountNumber, memberDetails, numMembers);
		if (checkACC == true)
		{
			cout << endl << "Account number \"" << memberDetails[numMembers].accountNumber << " \"has been used!" << endl << endl;
			return;
		}
		else
		{
			cout << "Choose a password: ";
			cin >> memberDetails[numMembers].password;
			cout << endl << "Registration Completed!" << endl << endl;
		}
		numMembers++;
	}
}

// 存檔 Members.dat
void saveMemberDetails(MemberRecord memberDetails[], int numMembers)
{
	ofstream outfile("Members.dat", ios::app | ios::out | ios::binary);

	if (!outfile)
	{
		ofstream OutFile("Members.dat", ios::binary);
		if (!OutFile)
		{
			cerr << "OutFile Error";
			system("pause");
			exit(1);
		}
		else
			OutFile.write(reinterpret_cast <const char *>(&memberDetails), sizeof(MemberRecord));
	}
	else
	{
		for (int i = 0; i < numMembers; i++) // add
		{
			outfile.clear();
//			outfile.write(reinterpret_cast <const char *>(&memberDetails), sizeof(MemberRecord));    // delete
			outfile.write(reinterpret_cast <const char *>(&memberDetails[i]), sizeof(MemberRecord)); // add
		}
	}
	outfile.close();
}

// 存檔 Reservations.dat
void saveReservations(ReservationRecord reservations[], int numReservations)
{
	ofstream outfile("Reservations.dat", ios::app | ios::out | ios::binary);

	if (!outfile)
	{
		ofstream OutFile("Reservations.dat", ios::binary);
		if (!OutFile)
		{
			cerr << "OutFile Error";
			system("pause");
			exit(1);
		}
		else
			OutFile.write(reinterpret_cast <const char *>(&reservations[numReservations]), sizeof(ReservationRecord));
	}
	else
	{
		outfile.clear();
		outfile.write(reinterpret_cast <const char *>(&reservations[numReservations]), sizeof(ReservationRecord));
	}
	outfile.close();
}
