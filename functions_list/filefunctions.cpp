#define _CRT_SECURE_NO_WARNINGS
#include "allfunctions.h"

/**
<p> Функция изменения директории</p> 
*По умолчанию все действия выполняются в папке из которой была запущена программа. 
* Назначение функции состоит в том, чтобы изменить папку в которой находится пользователь. 
*/
void changeornot()
{
	char ans[4];
	TCHAR sPath[MAX_PATH];
	do
	{
		cout << setw(5)<<"Хотите изменить текущую папку?(yes/no) ";
		cin >> ans;
	} while ((strcmp(ans, "no") > 0) && (strcmp(ans, "yes") > 0));
	
	cin.clear();

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

/**
	<p> Функция создание файла в определенной папке</p>
*Назначение функции - создания файла в текущей директории. 
* max - определение максимально возможной длины имени файла и адреса директории
* f_name - имя файла
* Ввод текста в созданный файл будет осуществляться до тех пор, пока не будет введен символ  ' / '
*/
void filecreate()
{
	const int MAX = 2000;
	char str[MAX], f_name[MAX_PATH]; 
	changeornot();
	cout << setw(5) <<"Имя файла: ";
	cin >> f_name;
	ofstream fout(f_name); 
	cin.get(str, MAX, '/');
	fout << str; 
	fout.close();
}

/**
<p>Функция для удаления файла в выбранной директории </p>
* 
*/
void removefile() //added 02/09/2019 21:37
{
	char ans[4], fname[MAX_PATH], dirname[MAX_PATH];
	changeornot();
	do
	{
		cout << setw(5) <<"Удаляется directory (dir) или file (fil)?";
		cin >> ans;
	} while ((strcmp(ans, "dir") > 0) && (strcmp(ans, "fil") > 0));
	cin.clear();
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
				if (_rmdir(dirname) == -1) //10/12/2019 15:38 не убирать эту строчку, иначе не удал¤ет файл
				{
					cout << "Ошибка удаления" << endl;
					cout << "error" << strerror(errno) << endl;
				}
				else
					cout << "Папка удалена" << endl;
			}
		}
}
/**
<p> Функция для открытия файла</p>
* 27/11/2019 0:02 открытие файла
* Пользователем вводится имя файла. Содержимое файла будет выведено на консоль. 
*/
void openfile()
{
	char buff[255],f_name[MAX_PATH], szDirName[MAX_PATH];
	changeornot();
	GetCurrentDirectory(MAX_PATH, szDirName);
	cout << setw(5) << "Имя файла";
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