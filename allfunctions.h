#pragma once
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include <string>
#include <fstream> 
#include <time.h> 
#include <io.h>
#include <stdio.h>
#include<direct.h> //удаление файлов и папок

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ofstream;
using std::ifstream;


/*функции взаимодействия с пользователем*/
void changeornot();
int mainmenu();
void menucase();
void help();
/*функции для работы с каталогом*/
int getcurrdirect();
int createdirect();
void chdir();
void wadir();// Поиск файлов в каталоге
void removefile();// Удалить существующий файл, общая функция
/* функции по для работы с файлами*/
void filecreate();
void openfile();
