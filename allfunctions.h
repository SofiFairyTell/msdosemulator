#pragma once
#include <iostream>
#include <iomanip> 
#include <windows.h>
#include <string>
#include <fstream> 
#include <time.h> 
#include <io.h>
#include<direct.h> //�������� ������ � �����

using std::cerr;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ofstream;
using std::ifstream;


/*������� ����*/
int mainmenu();
void menucase();
void menucomm();
/*������� ��� ������ � ���������*/
int getcurrdirect();
int createdirect();
void chdir();
void wadir();// ����� ������ � ��������
void changeornot();
/*������� ��� ������ � �������*/
void filecreate();
void openfile();
/*����� �������*/
void removefile();// ������� ������������ ����

