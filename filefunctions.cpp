#define _CRT_SECURE_NO_WARNINGS
#include "allfunctions.h"

/*************��������� ����� ���� �� ����� � �������**************************/
void changeornot()
{
	char ans[4];
	TCHAR sPath[MAX_PATH];
	do
	{
		cout << setw(5)<<"�������� � ������� �����.��������?(yes/no) ";
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
/*********************�������� ����� � ������������ �����******************/
void filecreate()
{
	const int MAX = 2000;//������������ ����� ������
	char str[MAX], f_name[MAX_PATH]; //������ , ��� �����
	changeornot();
	cout << setw(5) <<"��� �����: ";
	cin >> f_name;
	ofstream fout(f_name); // ������ ������ ������ ofstream ��� ������ 
	cin.get(str, MAX, '/');//���� �� ����� ������ �������� ������ ����� ���� ������ ���������
	fout << str; // ������ ������ � ����
	fout.close(); // ��������� ����
	system("pause");
}
/************************************************************************/
/*********************������� �������� ����� � ������������ �����*******/
void removefile() //added 02/09/2019 21:37
{
	char ans[4], fname[MAX_PATH], dirname[MAX_PATH];
	changeornot();
	do
	{
		cout << setw(5) <<"��������� directory (dir) ��� file (fil)?";
		cin >> ans;
	} while ((strcmp(ans, "dir") > 0) && (strcmp(ans, "fil") > 0));
	if ((strcmp(ans, "fil") == 0))
	{
		cout<<"���� ��� ��������: ";
		cin>>fname;
		if (remove(fname))
		{
			cout<<"������ �������� �����"<<endl;
		}
		else
			cout << "���� ������" << endl;
		}
		else
		{
			if ((strcmp(ans, "dir") == 0))
			{
				cout << "����� ��� ��������: ";
				cin >> dirname;
				if (_rmdir(dirname) == -1)
				{
					cout << "������ �������� �����" << endl;
				}
				else
					cout << "����� �������" << endl;
			}
		}
}
/**********************************************************************/
/*******************************27/11/2019 0:02 �������� �����**********/
void openfile()
{
	char buff[255],f_name[MAX_PATH], szDirName[MAX_PATH];
	changeornot();
	GetCurrentDirectory(MAX_PATH, szDirName);
	cout << setw(5) << "��� �����: ";
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
			fin.getline(buff, 80);//sizeof(buff)); //������ i-������
			cout << buff << endl;
		}
	}
	fin.close();
}
/**********************************************************************/