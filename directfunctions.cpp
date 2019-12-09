#include "allfunctions.h"

/**********адрес текущей директории***************************************/
int getcurrdirect()
{
	DWORD  dwNumberOfChar;
	char  szDirName[MAX_PATH];

	dwNumberOfChar = GetCurrentDirectory(MAX_PATH, szDirName);// определяем имя текущего каталога
	if (dwNumberOfChar == 0)
	{
		cerr << "Get current directory failed." << endl
			<< "The last error code: " << GetLastError() << endl;
		cout << "Press any key to finish.";
		cin.get();
		return 0;
	}
		cout << setw(5) <<"Текущая папка: " << szDirName << "->";	// выводим на консоль имя текущего каталога
	 return 0;
}
/**************************************************************************/
/***********создание директории*******************************************/
int createdirect()
{	
	char  szDirName[MAX_PATH],ans[4];
	TCHAR  sPathto1[MAX_PATH],sPathTo2[MAX_PATH] ;//путь для создания и путь который нужно создать
	GetCurrentDirectory(MAX_PATH, szDirName);// определяем имя текущего каталога
	do 
		{
		cout << setw(5)<<"Введите текущая (cur) для создания папки в текущем каталоге или другое (els)  ";
		cin >> ans;
	} while ((strcmp(ans,"cur") > 0) || (strcmp(ans, "els")>0));
	if ((strcmp(ans, "cur") == 0))
	{
		cout << "Новая папка: ";
		cin >> sPathTo2;
		strcat_s(szDirName, "\\");
		strcat_s(szDirName, sPathTo2);
		strcpy_s(sPathto1, szDirName);
		CreateDirectory(sPathto1, NULL);//создать папку
	}
	else 
	{
		if ((strcmp(ans,"els") == 0))
		{
		cout << "Введите полный путь для создаваемой папки" << endl;
		cin >> sPathTo2;
		strcpy_s(sPathto1, sPathTo2);
		CreateDirectory(sPathto1, NULL);
		}
	}	return 0;
}
/************************************************************************/
/***************функция смены диска*************************************/
void chdir()
{
	TCHAR sPath[MAX_PATH], sPathTo2[MAX_PATH];
	cout << setw(5)<<"введите путь: ";
	cin >> sPathTo2;
	if (strcmp(sPathTo2, "test") == 0)
	{
		strcpy_s(sPathTo2, "C:\\testdirect\\");
	}
	strcpy_s(sPath, sPathTo2);//прим. от 25/09/2019 регистр имеет значение для диска 
	SetCurrentDirectory(sPath);
	//--------29/08/2019/ делаю этот кусок для проверки---------
	char  szDirName[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szDirName);
	cout << "Current directory name: " << szDirName << endl;
	//--------правильной  установки директории------------------
}
/**********************************************************************/
/***********функция поиска папок в папке ***************************/
//void wadir ()
//{	
//	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//сюда записать путь к папке
//	GetCurrentDirectory(MAX_PATH, szDirName);
//	int k = strlen(szDirName);
//	cin >> path;
//	if (strcmp(path, "cur") == 0)
//	{
//		cout << "path current " << szDirName << endl;
//		strcat_s(szDirName, "\\");
//		strcpy_s(path, szDirName);
//	}
//	else
//	{
//		strcat_s(path, "\\");
//	}
//	cout << path;
//	cout << "\nEnter mask (for example, *.* or *.txt):";// Запросим маску файлов 
//	cin >> mask;
//	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* что и где ищем
//	_finddata_t *lpFindData = new _finddata_t;
//	long hSearch = _findfirst(path, lpFindData);	//попробуем поискать папки в по пути
//	int dir = 0, file=0;
//	int set = 20;
//	cout << "НАЙДЕННЫЕ ФАЙЛЫ" << endl;
//	cout << "|ИМЯ\t\t\t|ДАТА ИЗМЕНЕНИЯ\t\t|ТИП\t|РАЗМЕР" << endl;
//	if (hSearch != -1)
//	{
//		do // Пока не закончатся все файлы в директории
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // Игнорируем текущую директорию и родительскую
//			{
//				if (lpFindData->attrib== FILE_ATTRIBUTE_DIRECTORY) // если найденный файл директория
//				{
//					cout << lpFindData->name <<"\n";// выводим название найденной директории
//					dir++;
//				}
//				else
//				{
//					file++;
//					char buffer[30], buffer1[30], buffer2[30];
//					ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 и ниже то же
//					ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
//					ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
//					AnsiToOem(lpFindData->name, lpFindData->name);//перекодирование имени файла на случай использования кириллицы
//					cout 
//						<< lpFindData->name << setw(set-strlen(lpFindData->name))
//						<<'|' <<buffer2<<"\t"<<'|'<<	lpFindData->attrib	<<'|'<< lpFindData->size
//						//<< "wr: " << buffer2 << "  "
//						<< endl;
//					//printf("%-12s %.24s %91d\n", lpFindData->name, buffer, lpFindData->size);
//				}
//			}
//			_findnext(hSearch, lpFindData); // продолжаем поиск в директории
//		} while (GetLastError() != ERROR_NO_MORE_FILES); // указывает, что в данном месте больше нету файлов
//	}
//	cout << "Было найдено папок: " << dir <<"\n"<< "Было найдено файлов: " <<file<< "\n";
//	cout << " file(s) in folder..." << path << "\n\n";
//	_findclose(hSearch);	// Очистка памяти
//	delete lpFindData;
//}
void wadir()
{
	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//сюда записать путь к папке
	GetCurrentDirectory(MAX_PATH, szDirName);
	int k = strlen(szDirName);
	cin >> path;
	if (strcmp(path, "cur") == 0)
	{
		cout << "path current " << szDirName << endl;
		strcat_s(szDirName, "\\");
		strcpy_s(path, szDirName);
	}
	else
	{
		strcat_s(path, "\\");
	}
	cout << path;
	cout << "\nEnter mask (for example, *.* or *.txt):";// Запросим маску файлов 
	cin >> mask;
	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* что и где ищем
	_finddata_t *lpFindData = new _finddata_t;
	long hSearch = _findfirst(path, lpFindData);	//попробуем поискать папки в по пути
	int dir = 0, file = 0;
	if (hSearch != -1)
	{
		do // Пока не закончатся все файлы в директории
		{
			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // Игнорируем текущую директорию и родительскую
			{
				if (lpFindData->attrib == FILE_ATTRIBUTE_DIRECTORY) // если найденный файл директория
				{
					cout << lpFindData->name << "\n\n";// выводим название найденной директории
					dir++;
				}
				else
				{
					file++;
					char buffer[30], buffer1[30], buffer2[30];
					ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 и ниже то же
					ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
					ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
					AnsiToOem(lpFindData->name, lpFindData->name);//перекодирование имени файла на случай использования кириллицы

					cout
						<< lpFindData->name << "  "				// Печать имени найденного файла
						<< lpFindData->attrib << "  "
						<< lpFindData->size << "  "
						<< "create: " << buffer << "  "
						<< "write: " << buffer2 << "  "
						<< "\n\n";
				}
			}
			_findnext(hSearch, lpFindData); // продолжаем поиск в директории
		} while (GetLastError() != ERROR_NO_MORE_FILES); // указывает, что в данном месте больше нету файлов
	}
	cout << "Было найдено папок: " << dir << "\n" << "Было найдено файлов: " << file << "\n";
	cout << " file(s) in folder..." << path << "\n\n";
	_findclose(hSearch);	// Очистка памяти
	delete lpFindData;
}


/******************************************************************/

/***********функция поиска папок в папке от 05/12/2019***************************/
//void wadir()
//{
//	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//сюда записать путь к папке
//	GetCurrentDirectory(MAX_PATH, szDirName);
//	int k = strlen(szDirName);
//	cin >> path;
//	if (strcmp(path, "cur") == 0)
//	{
//		cout << "path current " << szDirName << endl;
//		strcat_s(szDirName, "\\");
//		strcpy_s(path, szDirName);
//	}
//	else
//	{
//		strcat_s(path, "\\");
//	}
//	cout << path;
//	cout << "\nEnter mask (for example, *.* or *.txt):";// Запросим маску файлов 
//	cin >> mask;
//	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* что и где ищем
//	_finddata_t *lpFindData = new _finddata_t;
//	long hSearch = _findfirst(path, lpFindData);	//попробуем поискать папки в по пути
//	int dir = 0, file = 0;
//	if (hSearch != -1)
//	{
//		do // Пока не закончатся все файлы в директории
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // Игнорируем текущую директорию и родительскую
//			{
//				if (lpFindData->attrib == FILE_ATTRIBUTE_DIRECTORY) // если найденный файл директория
//				{
//					cout << lpFindData->name << "\n\n";// выводим название найденной директории
//					dir++;
//				}
//			}
//			_findnext(hSearch, lpFindData); // продолжаем поиск в директории
//		} while (GetLastError() != ERROR_NO_MORE_FILES); // указывает, что в данном месте больше нету файлов
//		do
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name))
//			{
//				if (lpFindData->attrib != FILE_ATTRIBUTE_DIRECTORY)
//				{
//						file++;
//						char buffer[30], buffer1[30], buffer2[30];
//						ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 и ниже то же
//						ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
//						ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
//						AnsiToOem(lpFindData->name, lpFindData->name);//перекодирование имени файла на случай использования кириллицы
//						cout
//						<< lpFindData->name << "  "
//						<< lpFindData->attrib << "  "
//						<< lpFindData->size << "  "
//						<< "cr: " << buffer << "  "
//						<< "wr: " << buffer2 << "  "
//						<< "\n\n";
//				}
//			}
//			_findnext(hSearch, lpFindData);
//		} while (GetLastError() != ERROR_NO_MORE_FILES);
//	
//	}
//	cout << "Было найдено папок: " << dir << "\n" << "Было найдено файлов: " << file << "\n";
//	cout << " file(s) in folder..." << path << "\n\n";
//	_findclose(hSearch);	// Очистка памяти
//	delete lpFindData;
//}
/******************************************************************/