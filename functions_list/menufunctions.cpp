#define _CRT_SECURE_NO_WARNINGS 
#include "allfunctions.h"

/** 
*<p> Функция переключения команды</p>
* Определяет какая была введена команда 
* Присваивает ей номер по списку**/
int switchfunc(char *buf)
{
	const char *prCo[] = {"exit","opf","del","dir","md","cf","cd","nul","cls","help"};
	for (int i = 0; i < 10; ++i)
	{
		if (strcmp(buf, prCo[i]) == 0)
			return i;
	}	
	return -1;
}


/**
* Все команды меню в одной функции
*/
void menucomm()
{	
	// предлагаем выбрать пункт меню для выполнения
	printf("%-35s  %-35s \n", "1.open_file function - opf","4.create_directory function - md");
	printf("%-35s  %-35s \n", "2.delete_file fucntion - del","5.create_file function - cf");
	printf("%-35s  %-35s \n", "3.watch_directory function - dir","6.change_directory function - cd");
	printf("%-35s  %-35s \n",  "7.clear_screen function - cls","8.change smt in current directory - cur");
	printf("%-10s \n", "0 - exit");
	
	//cout
	//		<< endl << "1.open_file function - opf" << setw(45) << "4.create_directory function - md" << endl
	//		<< "2.delete_file fucntion - del" << setw(40)<< "5.create_file function - cf" << endl
	//		<< "3.watch_directory function - dir" << setw(41)<< "6.change_directory function - cd" << endl
	//		<< "7.clear_screen function - cls" << setw(45) << "8.change smt in current directory - cur" << endl
	//		<< "0 - exit\n\n";// Âûõîä;
}
/************************************************/
/*****28/11/2019 9:00 íå óäàëÿþ, ïîòîìó ÷òî ïîä âîïðîñîì******/
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


/**
* <p> Меню с вызовом функций.</p>
* Команды вводятся символьные. 
* Для каждой команды устанавливается в соответствие номер. 
*/
void menucase()
{
	const int MAX = 256;
	char str[MAX];
	int ans= NULL;
	do 
	{
		do
		{
		getcurrdirect();
		//slice(str);
		cin >> str;
		} while (strlen(str)>4);
		ans = switchfunc(str);
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
			cout << "CREATOR MESSAGE IS ... NOT FOUND" << endl;
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
	} while (ans != 0);  // Выход из программы
}

/**
* Функция для вызова меню.
*/
int mainmenu()
{
	setlocale(LC_ALL, "");
	menucase();
	return 0;
	system("pause");	
}
