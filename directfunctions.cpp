#include "allfunctions.h"

/**********����� ������� ����������***************************************/
int getcurrdirect()
{
	DWORD  dwNumberOfChar;
	char  szDirName[MAX_PATH];

	dwNumberOfChar = GetCurrentDirectory(MAX_PATH, szDirName);// ���������� ��� �������� ��������
	if (dwNumberOfChar == 0)
	{
		cerr << "Get current directory failed." << endl
			<< "The last error code: " << GetLastError() << endl;
		cout << "Press any key to finish.";
		cin.get();
		return 0;
	}
		cout << setw(5) <<"������� �����: " << szDirName << "->";	// ������� �� ������� ��� �������� ��������
	 return 0;
}
/**************************************************************************/
/***********�������� ����������*******************************************/
int createdirect()
{	
	char  szDirName[MAX_PATH],ans[4];
	TCHAR  sPathto1[MAX_PATH],sPathTo2[MAX_PATH] ;//���� ��� �������� � ���� ������� ����� �������
	GetCurrentDirectory(MAX_PATH, szDirName);// ���������� ��� �������� ��������
	do 
		{
		cout << setw(5)<<"������� ������� (cur) ��� �������� ����� � ������� �������� ��� ������ (els)  ";
		cin >> ans;
	} while ((strcmp(ans,"cur") > 0) || (strcmp(ans, "els")>0));
	if ((strcmp(ans, "cur") == 0))
	{
		cout << "����� �����: ";
		cin >> sPathTo2;
		strcat_s(szDirName, "\\");
		strcat_s(szDirName, sPathTo2);
		strcpy_s(sPathto1, szDirName);
		CreateDirectory(sPathto1, NULL);//������� �����
	}
	else 
	{
		if ((strcmp(ans,"els") == 0))
		{
		cout << "������� ������ ���� ��� ����������� �����" << endl;
		cin >> sPathTo2;
		strcpy_s(sPathto1, sPathTo2);
		CreateDirectory(sPathto1, NULL);
		}
	}	return 0;
}
/************************************************************************/
/***************������� ����� �����*************************************/
void chdir()
{
	TCHAR sPath[MAX_PATH], sPathTo2[MAX_PATH];
	cout << setw(5)<<"������� ����: ";
	cin >> sPathTo2;
	if (strcmp(sPathTo2, "test") == 0)
	{
		strcpy_s(sPathTo2, "C:\\testdirect\\");
	}
	strcpy_s(sPath, sPathTo2);//����. �� 25/09/2019 ������� ����� �������� ��� ����� 
	SetCurrentDirectory(sPath);
	//--------29/08/2019/ ����� ���� ����� ��� ��������---------
	char  szDirName[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szDirName);
	cout << "Current directory name: " << szDirName << endl;
	//--------����������  ��������� ����������------------------
}
/**********************************************************************/
/***********������� ������ ����� � ����� ***************************/
//void wadir ()
//{	
//	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//���� �������� ���� � �����
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
//	cout << "\nEnter mask (for example, *.* or *.txt):";// �������� ����� ������ 
//	cin >> mask;
//	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* ��� � ��� ����
//	_finddata_t *lpFindData = new _finddata_t;
//	long hSearch = _findfirst(path, lpFindData);	//��������� �������� ����� � �� ����
//	int dir = 0, file=0;
//	int set = 20;
//	cout << "��������� �����" << endl;
//	cout << "|���\t\t\t|���� ���������\t\t|���\t|������" << endl;
//	if (hSearch != -1)
//	{
//		do // ���� �� ���������� ��� ����� � ����������
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // ���������� ������� ���������� � ������������
//			{
//				if (lpFindData->attrib== FILE_ATTRIBUTE_DIRECTORY) // ���� ��������� ���� ����������
//				{
//					cout << lpFindData->name <<"\n";// ������� �������� ��������� ����������
//					dir++;
//				}
//				else
//				{
//					file++;
//					char buffer[30], buffer1[30], buffer2[30];
//					ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 � ���� �� ��
//					ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
//					ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
//					AnsiToOem(lpFindData->name, lpFindData->name);//��������������� ����� ����� �� ������ ������������� ���������
//					cout 
//						<< lpFindData->name << setw(set-strlen(lpFindData->name))
//						<<'|' <<buffer2<<"\t"<<'|'<<	lpFindData->attrib	<<'|'<< lpFindData->size
//						//<< "wr: " << buffer2 << "  "
//						<< endl;
//					//printf("%-12s %.24s %91d\n", lpFindData->name, buffer, lpFindData->size);
//				}
//			}
//			_findnext(hSearch, lpFindData); // ���������� ����� � ����������
//		} while (GetLastError() != ERROR_NO_MORE_FILES); // ���������, ��� � ������ ����� ������ ���� ������
//	}
//	cout << "���� ������� �����: " << dir <<"\n"<< "���� ������� ������: " <<file<< "\n";
//	cout << " file(s) in folder..." << path << "\n\n";
//	_findclose(hSearch);	// ������� ������
//	delete lpFindData;
//}
void wadir()
{
	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//���� �������� ���� � �����
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
	cout << "\nEnter mask (for example, *.* or *.txt):";// �������� ����� ������ 
	cin >> mask;
	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* ��� � ��� ����
	_finddata_t *lpFindData = new _finddata_t;
	long hSearch = _findfirst(path, lpFindData);	//��������� �������� ����� � �� ����
	int dir = 0, file = 0;
	if (hSearch != -1)
	{
		do // ���� �� ���������� ��� ����� � ����������
		{
			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // ���������� ������� ���������� � ������������
			{
				if (lpFindData->attrib == FILE_ATTRIBUTE_DIRECTORY) // ���� ��������� ���� ����������
				{
					cout << lpFindData->name << "\n\n";// ������� �������� ��������� ����������
					dir++;
				}
				else
				{
					file++;
					char buffer[30], buffer1[30], buffer2[30];
					ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 � ���� �� ��
					ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
					ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
					AnsiToOem(lpFindData->name, lpFindData->name);//��������������� ����� ����� �� ������ ������������� ���������

					cout
						<< lpFindData->name << "  "				// ������ ����� ���������� �����
						<< lpFindData->attrib << "  "
						<< lpFindData->size << "  "
						<< "create: " << buffer << "  "
						<< "write: " << buffer2 << "  "
						<< "\n\n";
				}
			}
			_findnext(hSearch, lpFindData); // ���������� ����� � ����������
		} while (GetLastError() != ERROR_NO_MORE_FILES); // ���������, ��� � ������ ����� ������ ���� ������
	}
	cout << "���� ������� �����: " << dir << "\n" << "���� ������� ������: " << file << "\n";
	cout << " file(s) in folder..." << path << "\n\n";
	_findclose(hSearch);	// ������� ������
	delete lpFindData;
}


/******************************************************************/

/***********������� ������ ����� � ����� �� 05/12/2019***************************/
//void wadir()
//{
//	char  szDirName[MAX_PATH], path[MAX_PATH], mask[15];//���� �������� ���� � �����
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
//	cout << "\nEnter mask (for example, *.* or *.txt):";// �������� ����� ������ 
//	cin >> mask;
//	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* ��� � ��� ����
//	_finddata_t *lpFindData = new _finddata_t;
//	long hSearch = _findfirst(path, lpFindData);	//��������� �������� ����� � �� ����
//	int dir = 0, file = 0;
//	if (hSearch != -1)
//	{
//		do // ���� �� ���������� ��� ����� � ����������
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name)) // ���������� ������� ���������� � ������������
//			{
//				if (lpFindData->attrib == FILE_ATTRIBUTE_DIRECTORY) // ���� ��������� ���� ����������
//				{
//					cout << lpFindData->name << "\n\n";// ������� �������� ��������� ����������
//					dir++;
//				}
//			}
//			_findnext(hSearch, lpFindData); // ���������� ����� � ����������
//		} while (GetLastError() != ERROR_NO_MORE_FILES); // ���������, ��� � ������ ����� ������ ���� ������
//		do
//		{
//			if (strcmp(".", lpFindData->name) && strcmp("..", lpFindData->name))
//			{
//				if (lpFindData->attrib != FILE_ATTRIBUTE_DIRECTORY)
//				{
//						file++;
//						char buffer[30], buffer1[30], buffer2[30];
//						ctime_s(buffer, _countof(buffer), &(lpFindData->time_create));//22:55 02/09/2019 � ���� �� ��
//						ctime_s(buffer1, _countof(buffer1), &(lpFindData->time_access));
//						ctime_s(buffer2, _countof(buffer2), &(lpFindData->time_write));
//						AnsiToOem(lpFindData->name, lpFindData->name);//��������������� ����� ����� �� ������ ������������� ���������
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
//	cout << "���� ������� �����: " << dir << "\n" << "���� ������� ������: " << file << "\n";
//	cout << " file(s) in folder..." << path << "\n\n";
//	_findclose(hSearch);	// ������� ������
//	delete lpFindData;
//}
/******************************************************************/