#define _CRT_SECURE_NO_WARNINGS 
#include "allfunctions.h"

/*******Функция которая определяет как была введена**/
/*********команда и присваивает ей номер по списку**/
int switchfunc(char *buf)
{
	int ans = NULL;
	if (strcmp(buf, "opf")==0)
	{
		ans = 1;
	}
	else
	{
		if (strcmp(buf, "del")==0)
		{
			ans = 2;
		}
		else
		{
			if (strcmp(buf, "dir")==0)
			{
				ans = 3;
			}
			else
			{
				if (strcmp(buf, "md")==0)
					{
						ans = 4;
					}
				else
				{
					if (strcmp(buf, "cf")==0)
					{
						ans = 5;
					}
					else
					{
						if (strcmp(buf, "cd")==0)
						{
							ans = 6;
						}
						else
						{
							if (strcmp(buf, "exit")==0)
							{
								ans = 0;
							}
							else
							{
								if (strcmp(buf, "cls")==0)
								{
									ans = 8;
								}
								else
								{ 
									if (strcmp(buf, "help") == 0)
									{
										ans = 9;
									}
									else
									{
										cout << "такой команды пока не существует. введите одну из существующих команд" << endl;
										ans = 9;
									}
									
								}
									
							}
						}
							
								
					}
				}
			}
		}
	}
return ans;
}
/**************************************************/

int swfunc(char *buf)
//void swfunc(char *buf)
{
	const char *prCo[] = {"exit","opf","del","dir","md","cf","cd","nul","cls","help"};
	for (int i = 0; i < 10; ++i)
	{
		if (strcmp(buf, prCo[i]) == 0)
			//
			//	std::cout << i;
			//}
			return i;
	}	
	return -1;
}
/****просто команды меню в одной функции**********/
void menucomm()
{
	
	//меню
	cout
			<< endl << "1.open_file function - opf" << setw(45) << "4.create_directory function - md" << endl
			<< "2.delete_file fucntion - del" << setw(40)<< "5.create_file function - cf" << endl
			<< "3.watch_directory function - dir" << setw(41)<< "6.change_directory function - cd" << endl
			<< "7.clear_screen function - cls" << setw(45) << "8.change smt in current directory - cur" << endl
			<< "0 - exit\n\n";// Выход;
}
/************************************************/
/*****28/11/2019 9:00 не удаляю, потому что под вопросом******/
void slice(char *str)
{
	char str3[10];
	cin.get(str3,10,'.');
	cin.sync();
	//char str3[] = "dir/function";
	//cout << str3 << endl;
	char *pch = strtok(str3,"/");
	//char *pch2;
	strcpy(str, pch);
	
	while (pch != NULL)
	{
		cout << pch << endl;
		pch = strtok(NULL,"/");
	}

}
/***********/

/****непосредственно само меню******************/
void menucase()
{
	const int MAX = 256;
	char str[MAX];
	int ans= NULL;


	do {
		do
		{
		getcurrdirect();
		//slice(str);
		cin >> str;
		} while (strlen(str)>4);
		//ans = switchfunc(str);
		cout << "command test:   ";
		ans = swfunc(str);
		switch (ans)
		{
		case 1:
			openfile();
			break;
		case 2:
			removefile();
			break;
		case 3:
			wadir();
			break;
		case 4:
			createdirect();
			break;
		case 5:
			filecreate();
			break;
		case 6:
			chdir();
			break;
		case 7:
			//пустая команда на случай ошибок неправильного ввода
			break;
		case 8: 
			system("cls");
			break;
		case 9:
			menucomm();
			break;
		default:
			cout << "Cпасибо что использовали программу.\n Но разве что-то пошло не так <-.->?" << endl;
		}
		/***************************************************/		
	} while (ans != 0);      // Выход из программы
}
/**********************************************/
int mainmenu()
{
	setlocale(LC_ALL, "");
	menucase();
	return 0;
	system("pause");	
}