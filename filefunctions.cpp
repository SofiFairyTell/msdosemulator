#define _CRT_SECURE_NO_WARNINGS
#include "allfunctions.h"

/*************изменение папки если не хочет в текущей**************************/
void changeornot()
{
	char ans[4];
	TCHAR sPath[MAX_PATH];
	do
	{
		cout << setw(5)<<"ДЕЙСТВИЯ В ТЕКУЩЕЙ ПАПКЕ.ИЗМЕНИТЬ?(yes/no) ";
		cin >> ans;
	} while ((strcmp(ans, "no") > 0) && (strcmp(ans, "yes") > 0));
	if ((strcmp(ans, "no") == 0))
	{
		GetCurrentDirectory(MAX_PATH, sPath);
		SetCurrentDirectory(sPath);
	}
	else
	{
		if ((strcmp(ans, "yes") == 0))
		{
			chdir();
		}
	}
}
/****************************************************************************/
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
	system("pause");
}
/************************************************************************/
/*********************функция удаления файла в определенной папке*******/
void removefile() //added 02/09/2019 21:37
{
	char ans[4], fname[MAX_PATH], dirname[MAX_PATH];
	changeornot();
	do
	{
		cout << setw(5) <<"Удаляется directory (dir) или file (fil)?";
		cin >> ans;
	} while ((strcmp(ans, "dir") > 0) && (strcmp(ans, "fil") > 0));
	if ((strcmp(ans, "fil") == 0))
	{
		cout<<"Файл для удаления: ";
		cin>>fname;
		if (remove(fname))
		{
			cout<<"Ошибка удаления файла"<<endl;
		}
		else
			cout << "Файл удален" << endl;
		}
		else
		{
			if ((strcmp(ans, "dir") == 0))
			{
				cout << "Папка для удаления: ";
				cin >> dirname;
				if (_rmdir(dirname) == -1)
				{
					cout << "Ошибка удаления папки" << endl;
				}
				else
					cout << "Папка удалена" << endl;
			}
		}
}
/**********************************************************************/
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