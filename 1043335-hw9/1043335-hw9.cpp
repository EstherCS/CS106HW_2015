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

bool check(AvailableRooms availableRooms[], int numRecords, char *ComeDate, char *LeaveDate); // �ˬd����O�_�s�b
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

	if (!inFile)                                         // �P�_�ɮ׬O�_���`�}��
	{
		cout << "Open Error" << endl;                    // �ɮ׵L�k�}��
		system("pause");
		exit(1);
	}
	else
	{
		numRecords = 0;
		while (!inFile.eof())                            // �P�_�ɮ׬O�_Ū����̫�
		{
			inFile.read(reinterpret_cast< char * >(&availableRooms[numRecords]), sizeof(AvailableRooms));
			numRecords++;
		}
		for (int i = 0; i < numRecords - 1; i++)         // �L�X���
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
	inFile.close();                                      // �����ɮ� 
}

void saveToFile(AvailableRooms availableRooms[], int numRecords)
{
	ofstream outFile("availableRooms.dat", ios::binary);

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

void makeReservation(AvailableRooms availableRooms[], int numRecords)
{
	int num;
	char ComeDate[80];   // �Ӫ����
	char LeaveDate[80];  // ���}���


	cout << "Please input the arrival date (yyyy-mm-dd): ";
	cin.getline(ComeDate,80);

	cout << "Please input the departure date (yyyy-mm-dd):";
	cin.getline(LeaveDate, 80);
	cout << endl << endl;

	if (!check(availableRooms, numRecords, ComeDate, LeaveDate))  // �ˬd����O�_�s�b
	{
		cout << "������s�b" << endl << endl;
		system("pause");
		exit(1);
	}

	cout << "Select Room Type�G\n";
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

	switch (menuchoice)  // �w�X���ж�
	{
		case 1 :
			do
			{
				cout << "How many rooms ? ( ���i�W�L 9 �� ) : ";
				cin >> num;
			} while ((num > 9) || (num < 1));
			break;
		case 2 :
			do
			{
				cout << "How many rooms ? ( ���i�W�L 5 �� ) : ";
				cin >> num;
			} while ((num > 5) || (num < 1));
			break;
		case 3:
			do
			{
				cout << "How many rooms ? ( ���i�W�L 3 �� ) : ";
				cin >> num;
			} while ((num > 3) || (num < 1));
			break;
		case 4:
			do
			{
				cout << "How many rooms ? ( ���i�W�L 5 �� ) : ";
				cin >> num;
			} while ((num > 5) || (num < 1));
			break;
		case 5:
			do
			{
				cout << "How many rooms ? ( ���i�W�L 4 �� ) : ";
				cin >> num;
			} while ((num > 4) || (num < 1));
			break;
	}
	cout << endl;

	for (int b = 0; b < numRecords; b++)
	{
		// ���Ӫ����
		if (strcmp(availableRooms[b].date, ComeDate) == 0)  
		{
			int e = b + 1;

			// �Y�n�q 02-29 �ߤW���ж�
			if (strcmp(LeaveDate, "2016-03-01") == 0)       
			{
				// ��ƥu��02-29
				while (strcmp(availableRooms[e].date, "2016-02-29") != 0)
					e++;
				for (int i = b; i <= e; i++)
				{
					availableRooms[i].singleDayAvailRooms[menuchoice] -= num;  // ��h�Q�w�q���ж���
				}
			}
			else
			{
				while (strcmp(availableRooms[e].date, LeaveDate) != 0)         // �p���Ӫ���������}���
					e++;
				for (int i = b; i < e; i++)
				{
					availableRooms[i].singleDayAvailRooms[menuchoice] -= num;  // ��h�Q�w�q���ж���
				}
			}
		}
	}	
}

bool check(AvailableRooms availableRooms[], int numRecords, char *ComeDate, char *LeaveDate)
{
	for (int i = 0; i < numRecords; i++)
	{
		if (strcmp(availableRooms[i].date, ComeDate) == 0)  // ��J����s�b�h�^�� true
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