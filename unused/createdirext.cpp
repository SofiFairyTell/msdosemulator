#include <windows.h>
#include <iostream>

using std::cerr;
using std::cout;
using std::cin;
using std::endl;

/**
*<p> Функция для создания директорий</P>
* path_for_creation - путь где будет создана директория
* created_dirname - имя создаваемой директории
* @return true or false 
*/
int createdirect()
{	
	char  szDirName[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szDirName);// определяем имя текущего каталога
	TCHAR  path_for_creation[MAX_PATH];
	TCHAR  created_dirname[MAX_PATH];
	cin >> created_dirname;
	strcpy_s(path_for_creation,created_dirname);
	CreateDirectory(path_for_creation,NULL);
	return 0; 
}

