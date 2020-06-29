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

struct AvailableRooms
{
	Date date;
	int availableRooms[6]; // number of available rooms
};

int numRooms[6] = { 0, 9, 5, 3, 5, 4 };
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void computeCurrentDate(Date &currentDate);

void loadAvailableRooms(AvailableRooms availableRooms[], int &numRecords);

void initializeAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords);

void adjustAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords);

// returns a value of 0, -1 or 1 if date1 is equal to, less than or greater than date2, respectively.
int compareDates(Date date1, Date date2);

void saveAvailableRooms(AvailableRooms availableRooms[], int numRecords);

int main()
{
	Date currentDate = {};

	computeCurrentDate(currentDate);

	AvailableRooms availableRooms[184] = {};
	int numRecords = 0;

	loadAvailableRooms(availableRooms, numRecords);

	if (numRecords == 0 || compareDates(availableRooms[numRecords-1].date, currentDate) == -1)
		initializeAvailableRooms(availableRooms, currentDate, numRecords);
	else if (compareDates(availableRooms[1].date, currentDate) == -1)
		adjustAvailableRooms(availableRooms, currentDate, numRecords);

	cout << "The number of available rooms of each room type:\n\n";
	cout << "      Date   Superior Room   Deluxe Room   Deluxe Twin Room   Superior Suite   Deluxe Suite\n";
	for (int i = 1; i <= numRecords; i++)
		cout << availableRooms[i].date.year << "-"
		<< setw(2) << setfill('0') << availableRooms[i].date.month << "-"
		<< setw(2) << availableRooms[i].date.day
		<< setw(16) << setfill(' ') << availableRooms[i].availableRooms[1]
		<< setw(14) << availableRooms[i].availableRooms[2]
		<< setw(19) << availableRooms[i].availableRooms[3]
		<< setw(17) << availableRooms[i].availableRooms[4]
		<< setw(15) << availableRooms[i].availableRooms[5] << "\n";

	saveAvailableRooms(availableRooms, numRecords);

	system("pause");
}

// �p�⤵�Ѥ��
void computeCurrentDate(Date &currentDate)
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

void loadAvailableRooms(AvailableRooms availableRooms[], int &numRecords)
{
	int num;
	cout << "�п�ܭnŪ���ɮ�" << endl;
	cout << "1 -- Available Rooms 1.dat" << endl;
	cout << "2 -- Available Rooms 2.dat" << endl;
	cin >> num;

	// Ū���ɮ�
	if (num == 1)
	{
		ifstream inFile("Available Rooms 1.dat", ios::binary);
		numRecords = 0;
		while (inFile.read(reinterpret_cast<char *>(&availableRooms[numRecords]), sizeof(AvailableRooms)))
		{
			numRecords++;
		}
		inFile.close();                                        // �����ɮ�
	}
	else if (num == 2)
	{
		ifstream inFile("Available Rooms 2.dat", ios::binary);
		numRecords = 0;
		while (inFile.read(reinterpret_cast<char *>(&availableRooms[numRecords]), sizeof(AvailableRooms)))
		{
			numRecords++;
		}
		inFile.close();                                        // �����ɮ�
	}
}

// �N�L����ƪ�l��
void initializeAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords)
{
	availableRooms[0].date = currentDate;                     // �Ĥ@�Ѭ����Ѥ��
	for (int j = 1; j < 6; j++)
		availableRooms[0].availableRooms[j] = numRooms[j];

	for (int i = 1; i <= numRecords; i++)                     // �N�L����ƨ��N 
	{
		availableRooms[i].date = currentDate;
		for (int j = 1; j < 6; j++)
			availableRooms[i].availableRooms[j] = numRooms[j];

		availableRooms[i].date.day += i-1;

		// �N�~���i��
	    // �Y��j�󥻤�Ѽ� & ����j��Q�G��
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

// �N����Ĥ@�ѽվ㬰����
void adjustAvailableRooms(AvailableRooms availableRooms[], Date currentDate, int &numRecords)
{
	int num = 0;
	for (int i = 0; i < numRecords; i++)                      // �p�⦳�X�ѹL��
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

	for (int i = 0; i < numRecords; i++)                      // �N�L����ƨ��N 
	{
		availableRooms[i] = availableRooms[i + num - 1];
	}
	numRecords -= num;
}

int compareDates(Date date1, Date date2)
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

void saveAvailableRooms(AvailableRooms availableRooms[], int numRecords)
{
	ofstream outFile("availableRooms.dat", ios::out);

	if (!outFile)                                         // �ˬd���i�_������X
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < numRecords - 1; i++)          // �N��Ƽg�J�ɮ�
		{
			outFile.write(reinterpret_cast< const char * >(&availableRooms[i]), sizeof(AvailableRooms));
		}
	}
}