#include <iostream>
#include <fstream>
using namespace::std;

// read in a C++ program from a cpp file, and put it to the array "program".
void load(char program[][200], int &numLines);

void deleteComments(char line[]); // if there is a single-line comment in "line", delete it.

void deleteStringConstants(char line[]); // if there are string constants in "line", delete them.

void deleteCharacterConstants(char line[]); // if there are character constants in "line", delete them.

// put all identifiers in "line" into identifiers[ numIdentifiers ].
void getIdentifiers(char line[], char identifiers[][32], int &numIdentifiers);

// if character is a letter, digit or underscore, then return true, otherwise return false.
bool legal(char character);

// print all non-number, non-keyword strings in "identifiers" into a text file.
void store(char identifiers[][32], int numIdentifiers);

bool isNumber(char string[]); // if "string" consists of digits only, then return true, otherwise return false.

bool isKeywords(char string[]); // if "string" is a keyword of C++, then return true, otherwise return false.

// if there is a nonnegtive integer i < pos such that identifiers[ pos ] is equal to identifiers[i],
// then return true; otherwise return false.
bool isDuplicate(char identifiers[][32], int pos);

const char keywords[][20] = { "auto", "break", "case", "char", "const", "continue", "default",
"define", "do", "double", "else", "enum", "extern", "float", "for",
"goto", "if", "int", "long", "register", "return", "short",
"signed", "sizeof", "static", "struct", "switch", "typedef",
"union", "unsigned", "void", "volatile", "while", "bool",
"catch", "class", "const_cast", "delete", "dynamic_cast",
"explicit", "false", "friend", "inline", "mutable", "namespace",
"new", "operator", "private", "protected", "public",
"reinterpret_cast", "static_cast", "template", "this", "throw",
"true", "try", "typeid", "typename", "using", "virtual", "include" };

int main()
{
	char program[1000][200];
	int numLines = 0;

	load(program, numLines); // reads in a C++ program from a cpp file, and put it to the array program.

	char identifiers[2000][32];
	int numIdentifiers = 0;

	for (int i = 0; i < numLines; i++)
	{
		deleteComments(program[i]); // if there is a single-line comment in program[ i ], delete it.
		deleteStringConstants(program[i]); // if there are string constants in program[ i ], delete them.
		deleteCharacterConstants(program[i]); // if there are character constants in program[ i ], delete them.
		if (strcmp(program[i], "") != 0)
		{
			// put all identifiers in program[ i ] into identifiers[ numIdentifiers ].
			getIdentifiers(program[i], identifiers, numIdentifiers);
		}
	}
	// print all non-number, non-keyword strings in "identifiers" into a text file.
	store(identifiers, numIdentifiers);

	system("pause");
}

void load(char program[][200], int &numLines)            // 讀取檔案
{
	ifstream infile("test.cpp", ios::in);

	if (infile.is_open())                                // 判斷檔案是否正常開啟
	{
		numLines = 0;
		while (!infile.eof())                            // 判斷檔案是否讀取到最後
		{
			infile.getline(program[numLines], 200);      // 一行一行讀入到 program 陣列
			numLines++;                                  // 計算總共有幾行
		}
	}
	else
	{
		cout << "Open Error" << endl;                    // 檔案無法開啟
		system("pause");
		exit(1);
	}
	infile.close();                                      // 關閉檔案 
}

void deleteComments(char line[])                         // 刪除註解
{
	int i = 0;
	// 還沒到字串的尾端並未在字串中遇到雙斜線就往右繼續找
	while (line[i] != '\0' && (line[i] != '/' || line[i + 1] != '/'))
		i++;

	if (line[i] == '/' && line[i + 1] == '/')            // 找到雙斜線就加結束字元
	{
		line[i] = '\0';
		return;
	}
}

void deleteStringConstants(char line[])                  // 刪除雙引號中的字
{
	int b = 0;
	int e;
	while (line[b] != '\0')                             
	{
		while (line[b] != '\0' && line[b] != '"')
			b++;
		if (line[b] == '\0')
			break;
		e = b + 1;
		if (line[e] == '\0')
			break;
		while (line[e] != '\0' && (line[e - 1] == '\\' || line[e] != '"'))
			e++;
		if (line[e] == '\0')
			break;
		for (int i = b; i <= e; i++)
			line[i] = ' ';
		b = e + 1;
	}
}

void deleteCharacterConstants(char line[])               // 刪除單引號中的字
{
	int b = 0;
	int e;
	while (line[b] != '\0')
	{
		while (line[b] != '\0' && line[b] != '\'')
			b++;
		if (line[b] == '\0')
			break;
		e = b + 1;
		if (line[e] == '\0')
			break;
		while (line[e] != '\0' && (line[e - 1] == '\'' || line[e] != '\''))
			e++;
		if (line[e] == '\0')
			break;
		for (int i = b; i <= e; i++)
			line[i] = ' ';
		b = e + 1;
	}
}

// 將 program 中的字串放到新的陣列
void getIdentifiers(char line[], char identifiers[][32], int &numIdentifiers)
{
	int b = 0;
	int e = 0;
	while (line[b] != '\0')                               
	{
		while (line[b] != '\0' && legal(line[b]))         // 若為符號且未到字串尾端，就跳過
			b++;

		if (line[b] == '\0')
			break;

		if (b && line[b - 1] == '\0')    
			break;

		e = b + 1;                                        // 利用 b 和 e 找到單字
		if (line[e] == '\0')           
			break;
		while (!legal(line[e]))
			e++;
		int j = 0;
		for (int i = b; i < e; i++, j++)
		{
			identifiers[numIdentifiers][j] = line[i];     // 將單字放到新的陣列中
		}
		identifiers[numIdentifiers][j] = '\0';            // 加上結束符號

		b = e + 1;
		// 判斷是否為數字或是關鍵字以及和前面重複
		if (!isNumber(identifiers[numIdentifiers]) && !isKeywords(identifiers[numIdentifiers]) &&
			!isDuplicate(identifiers, numIdentifiers))
		{
			numIdentifiers++;                             // 若無符合條件 numIdentifiers 就 +1，有重複就不加令新資料蓋過
		}
	}
}

bool legal(char character)                                // 判斷是否為符號
{
	if (character == '#' || character == '<' || character == '>' || character == ';' || character == '&' || character == '('
		|| character == '.' || character == '+' || character == '[' || character == ']' || character == '!' || character == '{' || character == '}' || character == '%'
		|| character == ')' || character == ',' || character == '=' || character == ':' || character == ' ' || character == '\0')
		return true;
	else
		return false;
}

bool isNumber(char string[])                              // 判斷是否為數字
{
	if (string[0] < '0' || string[0] > '9') return false;
	else return true;
}

bool isKeywords(char string[])                            // 判斷是否為關鍵字
{
	for (int i = 0; i < sizeof(keywords) / 20; i++) 
	{
		if (strcmp(string, keywords[i]) == 0)
			return true;
	}
	return false;
}

bool isDuplicate(char identifiers[][32], int pos)         // 判斷是否有重複
{
	for (int i = pos - 1; i >= 0; i--)  
	{
		if (strcmp(identifiers[i], identifiers[pos]) == 0)
			return true;
	}
	return false;
}

void store(char identifiers[][32], int numIdentifiers)    // 輸出到文件
{
	ofstream outfile("output.txt", ios::out);

	if (!outfile)                                         // 檢查文件可否接收輸出
	{
		cerr << "Error" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		for (int i = 0; i < numIdentifiers; i++)          // 輸出到文件 
		{
			outfile << identifiers[i] << endl;
		}
	}
}

