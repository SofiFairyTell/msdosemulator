#define _CRT_SECURE_NO_WARNINGS
#include "allfunctions.h"


/*********************создание файла в определенной папке******************/
void filecreate()
{
	const int MAX = 2000;//максимальная длина строки
	char str[MAX], f_name[MAX_PATH]; //строка , имя файла
	changeornot();
	cout << setw(5) <<"Имя файла: ";
	cin >> f_name;

	ofstream fout(f_name); // создаём объект класса ofstream для записи 
	cin.get(str, MAX, '/');//пока не будет введен конечный символ будет ввод текста продолжен
	fout << str; // запись строки в файл
	fout.close(); // закрываем файл
}
/************************************************************************/

/*******************************27/11/2019 0:02 открытие файла**********/
void openfile()
{
	char buff[255],f_name[MAX_PATH], szDirName[MAX_PATH];
	changeornot();
	GetCurrentDirectory(MAX_PATH, szDirName);
	cout << setw(5) << "Имя файла: ";
	cin >> f_name;

	strcat_s(szDirName, f_name);
	ifstream fin(f_name);
	while (!fin.is_open())
	{
		cerr << "File error" << endl;
		cin.ignore();
		break;
	}
	if (fin)
	{
	while (!fin.eof())
		{
			fin.getline(buff, 80);//sizeof(buff)); //запись i-строки
			cout << buff << endl;
		}
	}
	fin.close();
}
/**********************************************************************/
