//***************удалено из .cpp - createdirext 26082019*****************
//--------------------- создаем каталог--------------------------------------------------------
//	if (!CreateDirectory("C:\\Users\\Kurbatova\\source\\demo_dir", NULL))//C:\Users\Kurbatova\source\repos
//	{
//		cerr << "Create directory failed." << endl
//			<< "The last error code: " << GetLastError() << endl;
//		cout << "Press any key to finish.";
//		cin.get();
//
//		return 0;
//	}
//
//	cout << "The directory is created." << endl;
//
//	return 0;
//}
//------------конец функции создания каталога--------------------------------------------------
//TCHAR sPathTo[] = "C:\\Users\\Kurbatova\\source\\1";//директория, которую нужно создать
//-------------полезная функция потому что рабочая---------------------------------------------
//bool AQLCreateDirectory(TCHAR * sPathTo)
//{
//	//пока директория не создана, будем пытаться её создать//
//	while (CreateDirectory(sPathTo, NULL) == FALSE)
//	{
//		/* директория не создана, поэтому нужно сначала создать ”предыдущую” директорию */
//		TCHAR sTemp[MAX_PATH];
//		int k = strlen(sPathTo);
//		strcpy(sTemp, sPathTo);
//		//пытаемся найти и создать директорию самого “нижнего” уровня
//		while (CreateDirectory(sTemp, NULL) != TRUE)
//		{
//			/* пытаемся найти первичные половые признаки предыдущей директории.... */
//			while (sTemp[--k] != '\\')
//			{
//				if (k <= 1)
//			{
//					cout<<"not create"<<endl;
//					return FALSE;/* похоже, что директория создана быть вообще не может!
//					}
//			sTemp[k] = NULL;
//					}
//					/* ......а как только нашли - создать её */	
// CreateDirectory("C:\\Users\\Kurbatova\\source\\demo_dir", NULL);
//			}
//			//во время первого прохода будет создана директория “1”, во время второго – “2” и т.д.
//		}
//		return TRUE;
//	}
//}
//------------------------конец рабочей функции-----------------------------------------------------
//**************************************************************************************************

//************************удалено из menu.cpp 26082019**********************************************
//-----------------функция которая цикл запускает. сначала вывод команд,----------------------------
//-----------------потом запуск функции на их выполнение	----------------------------------------
//без цикла do..while все работает просто прекрасно. Что не так с циклом?
	/*do
	{*/

	//cout << endl
	//		<< "1.create_file function - crfil" << endl
	//		<< "2.create_directory function - crdir" << endl
	//		<< "3.delete_file fucntion - delfi" << endl
	//		<< "4.delete_directory fucntion - dldir" << endl
	//		<< "5.change_directory function - chdir" << endl
	//		<< "6.change_dick functionon -  chdis" << endl
	//		<< "7.watch_directory function - wadir" << endl
	//		<< "8.open_file function - opfil " << endl
	//		<< "9.clear screen clsrn" << endl
	//		<< "10. close program clopr" << endl;
	//	cout << "enter command" << endl;

//} while ();//зацикливается
//---------------------------------------конец функции----------------------------------------------

//********************************from menu.cpp******************************************************

	//case 2:
	//{
	//	cout << "delete_file fucntion" << endl;//delete_file fucntion
	//}
	//break;
	//case 3:
	//{
	//	//delete_directory fucntion
	//}
	//break;
	//case 4:
	//{
	//	//change_directory function
	//}
	//break;
	//case 5:
	//{
	//	//change_dick function
	//}
	//break;
	//case 6:
	//{
	//	//watch_directory function
	//}
	//break;
	//case 7:
	//{
	//	//open_file fucntion
	//}
	//break;
	//case 8:
	//{
	//	system("cls");
	//	//return true;
	//}
	//break;
	//case 9:
	//{
	//	system("cls");
	//	cout << "спасибо что открыли программу" << endl;
	//	//return false;
	//}
	//break;
//*****************************************************************************************

//***************from nenu.cpp*************************************************************
//***************22:41 30/08/2019**********************************************************
//--------------функции работают некорректно, поэтому пока убираю.-------------------------
//--------------предполагалось, что будет принимать число,---------------------------------
//--------------конвертируемое из сивольной команды----------------------------------------
			//int switchfunc(char *buf)//анализирует совпадение введенной команды с хранящейся в памяти
			//{
			//	for (int i = 0; i < prSize; ++i)
			//		if (strcmp(buf, prComm[i]))
			//		{
			//			cout << i << endl;
			//			return i;
			//		}
			//	return -1;
			//}
			//bool menuswitch(int ans)
					//{
					//	switch (ans)
					//	{
					//	case 0:
					//	{
					//		cout << "create_file function" << endl;
					//		createdirect();
					//		//create_file function
					//		//return true;
					//	}
					//	break;
					//	//case 1:
					//	//{
					//	//	cout << "create_directory function" << endl;
					//	//	//createdirect();
					//	//	//create_directory function
					//	//	//return true;
					//	//}
					//	//break;
					//
					//	default:
					//		cout << "wrong command" << endl;
					//	}
					//	  
					//return false;
					//}
//**********конец функции*********************************************************************
/***15/10/2019*******попытка использовать текущую директорию****/
/*
if (path != "current")
	{
		path[MAX_PATH] = NULL;
		while (szDirName[++k] != NULL)
		{
			cout << "its not end";
			 l = k;
		}
		if (szDirName[l] == NULL)
			szDirName[l] = '\\';
		//strcat_s(szDirName,"\\");
		cout << "path current "<<szDirName;
		strcpy_s(path,szDirName);
	}
	cout << path;
	*/
/***************************/
/***************************/
/*
int AQLCreateDirectory2(TCHAR *sPathTo2)//чет это выдает ошибку 3 22:49 (МСК) 26/08/2019
/*Most likely that means that some part of the path specified in sFullPath does not exist.
Note that CreateDirectory will not create a directory tree for you. It will only create
a new directory object in an existing directory. 27/08/2019 21:38 код ошибки означает, что нельзя
создать папку по переданному в функцию пути*/
//{
//// создаем каталог
//if (!CreateDirectory("C:\\testdirect", NULL)) //("C:\\Users\\Kurbatova\\source\\testdirect", NULL)-< не работает пока 27/08/2019 21:47
//{
//	cerr << "Create directory failed." << endl
//		<< "The last error code: " << GetLastError() << endl;
//	cout << "Press any key to finish.";
//	cin.get();
//
//	return 0;
//}
//
//cout << "The directory is created." << endl;
//
//return 0;
//}*/
/**************************/
/*delete 16.10.2019*/
/*
//*************************works 8/07/19 and now 26/08/2019 doesnt work**********************************
//bool AQLCreateDirectory(TCHAR * sPathTo)
//{
//	//пока директория не создана, будем пытаться её создать//
//	while (CreateDirectory(sPathTo, NULL) == FALSE)
//	{
//		/* директория не создана, поэтому нужно сначала создать ”предыдущую” директорию */
//TCHAR sTemp[MAX_PATH];
//int k = strlen(sPathTo);
//strcpy_s(sTemp, sPathTo);
//
////пытаемся найти и создать директорию самого “нижнего” уровня
//while (CreateDirectory(sTemp, NULL) != TRUE)
//{
//	/* ищем предыдущую директорию*/
//	while (sTemp[--k] != '\\')
//	{
//		if (k <= 1)
//			return FALSE;/* похоже, что директория создана быть вообще не может!*/
//		sTemp[k] = NULL;
//	}
//	cout << "succsess" << endl;
//	CreateDirectory("C:\\Users\\Kurbatova\\source\\testdirect", NULL);
//}
//return TRUE;
//	}
//}
//*******************************************************************************************/

/*************25/11/2019 15/16***********************/
/*	/*const int MAX=256;
	char str2a[6],str3[MAX];*/
	//cin.get(str,'.');
	//cin.sync();
	//cout << str;
	//int n;
	//for (int i = 0; i < strlen(str); i++)
	//{
	//	if ((str[i]) == ' ') break;
	//		//str2[i] = str[i];	
	//	n = i;
	//}
	//strcpy(str2, str);
	//cout <<"I READ COMMAND! "<< str2 << endl;
	//
	////strcpy_s(str,strlen(str2),str2);
	//
	////cout << "Second part of command " << str3 << endl;*/

//28/11/2019 8:44
//***************Поиск файлов в каталоге*******************************/
//void exwadir()
//{
//	char  szDirName[MAX_PATH];
//	GetCurrentDirectory(MAX_PATH, szDirName);
//	int k = strlen(szDirName);
//	char path[MAX_PATH];//сюда записать путь к папке
//	cout << "\nEnter full path (for example, C:\\):"; //тестируется по следующей папке C:\\testdirect 29/08/2019 22:19
//	cin >> path;
//	if (strcmp(path,"cur")==0)
//	{
//		cout << "path current " << szDirName << endl;
//		strcat_s(szDirName,"\\");
//		strcpy_s(path, szDirName);
//	}
//	else 
//	{
//		strcat_s(path, "\\");
//	}
//	cout << path;
//	// Запросим маску файлов 
//	char mask[15];
//	cout << "\nEnter mask (for example, *.* or *.txt):";
//	cin >> mask;
//	strcat_s(path, mask);//C:\testdirect\*.txt or C:\testdirect\*.* что и где ищем
//	_finddata_t *fileinfo = new _finddata_t;
//	// Начинаем поиск
//	long done = _findfirst(path, fileinfo);//возвращает дескриптор индентифицирующий файл или группу файлов
//	// если done будет равняться -1, 
//	// то поиск вести бесмысленно
//	int MayWeWork = done;
//	// Счетчик, содержит информацию о количестве найденых файлов.	
//	int count = 0;
//	while (MayWeWork != -1)
//	{
//		count++;
//		char buffer[30], buffer1[30], buffer2[30];
//		ctime_s(buffer, _countof(buffer), &(fileinfo->time_create));//22:55 02/09/2019 и ниже то же
//		ctime_s(buffer1, _countof(buffer1), &(fileinfo->time_access));
//		ctime_s(buffer2, _countof(buffer2), &(fileinfo->time_write));
//		AnsiToOem(fileinfo->name, fileinfo->name);//перекодирование имени файла на случай использования кириллицы
//		// Печать имени найденного файла
//		cout 
//			<< fileinfo->name <<"  "
//			<<fileinfo->attrib << "  "
//			<<fileinfo->size << "  "
//			<<"create: "<<buffer << "  "
//			<<"write: "<<buffer2<< "  "
//			<<"\n\n";
//		// Пытаемся найти следующий файл из группы
//		MayWeWork = _findnext(done, fileinfo);
//	}
//	// Вывод сообщения о количестве найденных файлов.
//	cout << "\nInformation: was found " << count;
//	cout << " file(s) in folder..." << path << "\n\n";
//	// Очистка памяти
//	_findclose(done);
//	delete fileinfo;
//}

