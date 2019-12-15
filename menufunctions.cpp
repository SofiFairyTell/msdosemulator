#define _CRT_SECURE_NO_WARNINGS 
#include "allfunctions.h"

/*************изменение папки если не хочет в текущей**************************/
void changeornot()
{
	char ans[4];
	TCHAR sPath[MAX_PATH];
	do
	{
		cout << setw(5) << "ДЕЙСТВИЯ В ТЕКУЩЕЙ ПАПКЕ.ИЗМЕНИТЬ?(yes/no) ";
		cin >> ans;
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
	} while ((strcmp(ans, "no") != 0) && (strcmp(ans, "yes") != 0));

	//cin.clear();

}
/****************************************************************************/

/*******Функция которая определяет как была введена**/
/*********команда и присваивает ей номер по списку**/
int switchfunc(char *buf)
{
	const char *prCo[] = {"exit","opf","del","dir","md","cf","cd","sft","cls","help"};
	for (int i = 0; i < 10; ++i)
	{
		if (strcmp(buf, prCo[i]) == 0)
			return i;
	}	
	return -1;
}
/**************************************************/


/****просто команды меню в одной функции**********/
void help()
{	//меню
	char str[2];
	cout << "Это раздел ПОМОЩЬ. Здесь есть перечень команд для работы с файлами и директориями с описанием. ";
	cout << "\nДля получения справки в текущем разделе после слова -- ввод -> -- введите один из параметров ниже, нажмите Enter:";
	cout<< "\nf - здесь команды для работы с файлами;\nd - здесь команды для работы с директориями;\ni - здесь команды управления программой;\nr - вернуться в основную программу;";
	cout << "\n\nОбращаем внимание, что прежде чем вводить просмотренные команды вернитесь в основную программу.";
	do
	{
		do
		{
			cout << "\nввод -> ";
			cin >> str;
		} while (strcmp(str, "f") != 0 && strcmp(str, "d") != 0 && strcmp(str, "i") != 0 && strcmp(str, "r") != 0);
		if (strcmp(str, "f") == 0)
		{
			printf("%-10s  %-35s \n", "НАЗВАНИЕ КОМАНДЫ", "ОПИСАНИЕ");
			printf("%-10s  %-35s \n", "opf", "- открытие текстового файла.");
			printf("%-10s  %-35s \n", "   ", "  после ввода команды введите имя файла.");
			printf("%-10s  %-35s \n", "сf ", "- создание файла.");
			printf("%-10s  %-35s \n", "   ", "  после ввода команды введите название файла.");
			printf("%-10s  %-35s \n", "   ", "  после нажатия на Enter вводите текст в файл.");
			printf("%-10s  %-35s \n", "   ", "  в конце предложения, чтобы закончить ввод ");
			printf("%-10s  %-35s \n", "   ", "  и закрыть файл введите символ / и нажмите Enter.");
			printf("%-10s  %-35s \n", "del", "- удаление директорий и файлов. ");
			printf("%-10s  %-35s \n", "   ", "  после ввода команды введите какой объект нужно удалить.");
			printf("%-10s  %-35s \n", "   ", "  затем введите его название. следуйте инструкциям на экране");
		}
		else
		{
			if (strcmp(str, "d") == 0)
			{
				printf("%-10s  %-35s \n", "НАЗВАНИЕ КОМАНДЫ", "ОПИСАНИЕ");
				printf("%-10s  %-35s \n", "md ", "- создание директории. ");
				printf("%-10s  %-35s \n", "   ", "  после ввода команды введите имя создаваемой директории.");
				printf("%-10s  %-35s \n", "cd ", "- изменение текущей директории. ");
				printf("%-10s  %-35s \n", "   ", "  после ввода команды введите имя директории в которую хотите перейти.");
				printf("%-10s  %-35s \n", "del", "- удаление директорий и файлов. ");
				printf("%-10s  %-35s \n", "   ", "  после ввода команды введите какой объект надо удалить.");
				printf("%-10s  %-35s \n", "   ", "  затем введите его название.");
				printf("%-10s  %-35s \n", "dir", "- просмотр директории.");
				printf("%-10s  %-35s \n", "   ", "  после ввода команды введите cur (для просмотра ");
				printf("%-10s  %-35s \n", "   ", "  текущей директории) или путь (C : \ \example) к");
				printf("%-10s  %-35s \n", "   ", "  папке которую нужно просмотреть. ");
				printf("%-10s  %-35s \n", "   ", "  здесь предусмотрена маска файла. следуйте инструкциям на экране.");
			}
			else
			{
				if (strcmp(str, "i") == 0)
				{
					printf("%-10s  %-35s \n", "НАЗВАНИЕ КОМАНДЫ", "ОПИСАНИЕ");
					printf("%-10s  %-35s \n", "cls ", "- очистка экрана.");
					printf("%-10s  %-35s \n", "exit", "- завершение работы с приложением. ");
					printf("%-10s  %-35s \n", "sft","- для связи с разработчиком. ");
				}
			}
		}
	} while (strcmp(str, "r") != 0);
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
			cout << "CREATOR MESSAGE IS ... FOUND!" << endl;
			cout << "Hi! You are reading through.\nWriter likes to know it.\nWriter is me.";
			cout << "\nI'm Sofi Fairy-Tell.\nMay be this isn't best app, but I'm tried.\n";
			cout<<"You can improve it here: https://github.com/SofiFairyTell/msdosemulator.git. \nThank you !)" << endl;
			break;
		case 8: 
			system("cls");
			break;
		case 9:
			help();
			break;
		default:
			cout << "Обработка...." << endl;
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
