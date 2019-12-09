#pragma once
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include <string>
#include <fstream> 
#include <time.h> 
#include <io.h>
#include<direct.h> //удаление файлов и папок

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ofstream;
using std::ifstream;


/*функции меню*/
int mainmenu();
void menucase();
void menucomm();
/*команды для работы с каталогом*/
int getcurrdirect();
int createdirect();
void chdir();
void wadir();// Поиск файлов в каталоге
void changeornot();
/*команды для работы с файлами*/
void filecreate();
void openfile();
/*общие команды*/
void removefile();// Удалить существующий файл

