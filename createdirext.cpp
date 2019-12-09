
#include <windows.h>
#include <iostream>
//#include "mainfunction.h"
using std::cerr;
using std::cout;
using std::cin;
using std::endl;

int createdirect()
{	// определяем имя текущего каталога
	char  szDirName[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szDirName);
	TCHAR  sPathto1[MAX_PATH];//путь для создания
	TCHAR sPathTo2[MAX_PATH];//путь который нужно создать
	cin >> sPathTo2;
	strcpy_s(sPathto1,sPathTo2);
	CreateDirectory(sPathto1,NULL);
	return 0; 
}

//int main()
//{
//	char  szDirName[MAX_PATH];
//	createdirect();
//	return 0;
//	system("pause");
//}
