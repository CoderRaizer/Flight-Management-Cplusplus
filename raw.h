#include <windows.h>


/*------------------------FRAME-------------------------*/
void FrameMayBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	gotoxy(39,5);
	cout<<"---"<<endl;
	
	for(int i = 5 ; i <= 12 ; i++)
	{
		gotoxy(41,i);cout<<"|";
	}

	gotoxy(42,12);
	for(int i = 0 ; i < 37 ; i++)
	{
		printf("%c", 223);
	}
	
	for(int i = 5 ; i <= 12 ; i++)
	{
		gotoxy(78,i);cout<<"|";
	}
}


void FrameChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(39,6);
	cout<<"---"<<endl;
	for(int i = 5 ; i <= 14 ; i++)
	{
		gotoxy(41,i);cout<<"|";
	}
	gotoxy(42,14);
	for(int i = 0 ; i < 45 ; i++)
	{
		printf("%c", 223);
	}
	for(int i = 5 ; i <= 14 ; i++)
	{
		gotoxy(87,i);cout<<"|";
	}
}


void FrameOther()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(39,7);
	cout<<"---"<<endl;
	
	gotoxy(41,5);cout<<"|";
	gotoxy(41,6);cout<<"|";
	gotoxy(41,7);cout<<"|";
	//ngang
	gotoxy(41,8);
	for(int i = 0 ; i < 31; i++)
	{
		printf("%c", 223);
	}

	gotoxy(71,5);cout<<"|";
	gotoxy(71,6);cout<<"|";
	gotoxy(71,7);cout<<"|";

}
/*------------------------FRAME-------------------------*/


/*------------------------NAVBAR-------------------------*/
void Navbar1()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);

	///////khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(91,9);
	for(int i = 0; i < 19 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(91,11);
	for(int i = 0 ; i< 19 ; i++)
	{
		printf("%c", 196);
	}
	////khung doc
	gotoxy(109,10);printf("%c", 176);
	
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(88,9); cout<<"    ";
	gotoxy(88,10);cout<<"MSCB";
	gotoxy(88,11);cout<<"    ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(12,55);
}

void Navbar2()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);

	///////khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(94,10);
	for(int i = 0; i < 19 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(94,12);
	for(int i = 0 ; i< 19 ; i++)
	{
		printf("%c", 196);
	}
	////khung doc
	gotoxy(112,11);printf("%c", 176);
	
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(88,10);cout<<"       ";
	gotoxy(88,11);cout<<" MSCB: ";
	gotoxy(88,12);cout<<"       ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(12,55);
}

void Navbar3()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);

	///////khung ngang
	gotoxy(88,11);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	for(int i = 0; i < 25 ; i++)
	{
		printf("%c", 196);
	}
	
	////khung doc
	gotoxy(88,12);printf("%c", 176);
	gotoxy(112,12);printf("%c", 176);

	gotoxy(89,12);
	cout<<"MSCB:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(88,13);
		for(int i = 0 ; i< 25 ; i++)
		{
			printf("%c", 196);
		}
	gotoxy(12,55);
}

void Navbar4()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);

	///////khung ngang
	gotoxy(41,15);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	for(int i = 0; i < 47 ; i++)
	{
		printf("%c", 196);
	}
	
	////khung doc
	gotoxy(41,16);printf("%c", 176);
	gotoxy(87,16);printf("%c", 176);

	gotoxy(42,16);cout<<"NGAY:";
	gotoxy(57,16);cout<<"THANG:";
	gotoxy(73,16);cout<<"NAM:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,17);
	for(int i = 0 ; i< 47 ; i++)
	{//ngang
		printf("%c", 196);
	}
		
	////khung doc
	gotoxy(41,18);printf("%c", 176);
	gotoxy(87,18);printf("%c", 176);
	gotoxy(42,18);cout<<"SAN BAY:";	
		
	gotoxy(41,19);
	for(int i = 0 ; i< 47 ; i++)
	{//ngang
		printf("%c", 196);
	}	
		
	gotoxy(12,55);
}

void Navbar5()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////khung doc
	gotoxy(40,14);printf("%c", 176);
	gotoxy(69,14);printf("%c", 176);
	
	gotoxy(41,14);cout<<"NHAP SO VE:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,15);
	for(int i = 0 ; i< 30 ; i++)
	{
		printf("%c", 196);
	}
}

void Navbar6()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////khung doc
	gotoxy(40,16);printf("%c", 176);
	gotoxy(69,16);printf("%c", 176);	
	gotoxy(41,16);cout<<"NHAP CMND:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,17);
	for(int i = 0 ; i< 30 ; i++)
	{
		printf("%c", 196);
	}
}

void Navbar7()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//NOTE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,26);cout<<"( Luu Y )";
	gotoxy(13,27);cout<<"- So Hieu May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,28);cout<<"- Vui Long Tat CapsLock.";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,15);
	for(int i = 0 ; i< 46 ; i++)
	{
		printf("%c", 196);
	}
	////khung doc
	gotoxy(41,16);printf("%c", 176);
	gotoxy(86,16);printf("%c", 176);
	gotoxy(42,16);
	cout<<"NHAP SHMB CAN XOA:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,17);
	for(int i = 0 ; i< 46 ; i++)
	{
		printf("%c", 196);
	}
}

void Navbar8()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,15);
	for(int i = 0 ; i< 50 ; i++)
	{
		printf("%c", 196);
	}
	////khung doc
	gotoxy(41,16);printf("%c", 176);
	gotoxy(90,16);printf("%c", 176);
	gotoxy(42,16);
	cout<<"NHAP SHMB CAN HIEU CHINH:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,17);
	for(int i = 0 ; i< 50 ; i++)
	{
		printf("%c", 196);
	}
}

void Navbar9()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,15);
	for(int i = 0 ; i< 47 ; i++)
	{
		printf("%c", 196);
	}
	////khung doc
	gotoxy(41,16);printf("%c", 176);
	gotoxy(87,16);printf("%c", 176);
	gotoxy(42,16);
	cout<<"NHAP MSCB CAN HIEU CHINH:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,17);
	for(int i = 0 ; i< 47 ; i++)
	{
		printf("%c", 196);
	}
}
/*------------------------FRAME-------------------------*/



/*------------------------INTRODUCE-------------------------*/
void VeChu()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (15 << 4) | 12);
	///////khung ngang
	gotoxy(12,4);
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
	for(int i = 0; i < 65 ; i++)
	{
		printf("%c", 220);printf("%c", 223);
	}
	cout<<endl;
	
	////khung doc
	for(int i = 5 ; i <= 51 ; i++)
	{
		gotoxy(12,i);printf("%c", 176);
	}
	
	for(int i = 5 ; i <= 51 ; i++)
	{
		gotoxy(141,i);printf("%c", 176);
	}

	
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
	gotoxy(13,47);
		for(int i = 0 ; i< 128 ; i++)
		{
			printf("%c", 223);
		}
		
	///////khung ngang
	gotoxy(12,51);
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
		for(int i = 0; i < 65 ; i++)
	{
		printf("%c", 220);printf("%c", 223);
	}
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 8);
	///F///
	gotoxy(16,13);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	
	for(int i = 14 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(15,i);
		printf("%c", 178);
	}
	
	gotoxy(15,16);
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	////F//////
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 9);
	////L/////
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(22,i);
		printf("%c", 178);
	}
	
	gotoxy(22,20);//ngang
	for(int i = 0 ; i <= 5 ; i ++)
	{
		printf("%c", 178);
	}
	////L/////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 10);
	///I////
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(29,i);
		printf("%c", 178);
	}////I////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////G////
	for(int i = 14 ; i <= 19 ; i++)
	{//doc
		Sleep(5);
		gotoxy(31,i);
		printf("%c", 178);
	}
	
	gotoxy(32,13);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	gotoxy(32,20);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	
	for(int i = 18 ; i <= 19 ; i++)
	{//doc
		Sleep(5);
		gotoxy(37,i);
		printf("%c", 178);
	}
	gotoxy(35,17);//ngang
	for(int i = 0 ; i <= 3 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	///G///
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	////H///
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(40,i);
		printf("%c", 178);
	}
	gotoxy(40,16);//ngang
	for(int i = 0 ; i <= 5 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(46,i);
		printf("%c", 178);
	}
	////H///
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 6);
	///T////
	gotoxy(48,13);//ngang
	for(int i = 0 ; i <= 8 ; i ++)
	{
		Sleep(5);
		printf("%c", 178);
	}
	
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(52,i);
		printf("%c", 178);
	}
	/////T//////
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 8);
	////M//////
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);
		gotoxy(62,i);
		printf("%c", 178);
	}
	Sleep(5);gotoxy(63,13);printf("%c", 178);
	Sleep(5);gotoxy(64,14);printf("%c", 178);
	Sleep(5);gotoxy(65,15);printf("%c", 178);
	Sleep(5);gotoxy(66,16);printf("%c", 178);
	Sleep(5);gotoxy(67,15);printf("%c", 178);
	Sleep(5);gotoxy(68,14);printf("%c", 178);
	Sleep(5);gotoxy(69,13);printf("%c", 178);
	
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(70,i);
		printf("%c", 178);
	}
	////M//////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 9);
	////A/////
	for(int i = 16 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(72,i);
		printf("%c", 178);
	}
	Sleep(5);gotoxy(73,15);printf("%c", 178);
	Sleep(5);gotoxy(74,14);printf("%c", 178);
	Sleep(5);gotoxy(75,13);printf("%c", 178);
	Sleep(5);gotoxy(76,13);printf("%c", 178);
	Sleep(5);gotoxy(77,14);printf("%c", 178);
	Sleep(5);gotoxy(78,15);printf("%c", 178);
	
	for(int i = 16 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(79,i);
		printf("%c", 178);
	}
	
	gotoxy(74,16);//ngang
	for(int i = 0 ; i <=3 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	/////A/////
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 10);
	////N////
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(81,i);
		printf("%c", 178);
	}
	Sleep(5);gotoxy(82,13);printf("%c", 178);
	Sleep(5);gotoxy(83,14);printf("%c", 178);
	Sleep(5);gotoxy(84,15);printf("%c", 178);	
	Sleep(5);gotoxy(85,16);printf("%c", 178);
	Sleep(5);gotoxy(86,17);printf("%c", 178);
	Sleep(5);gotoxy(87,18);printf("%c", 178);
	Sleep(5);gotoxy(88,19);printf("%c", 178);	
	
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(89,i);
		printf("%c", 178);
	}
	////N////

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////AA////
	for(int i = 16 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(91,i);
		printf("%c", 178);
	}
	Sleep(5);gotoxy(92,15);printf("%c", 178);
	Sleep(5);gotoxy(93,14);printf("%c", 178);
	Sleep(5);gotoxy(94,13);printf("%c", 178);
	Sleep(5);gotoxy(95,13);printf("%c", 178);
	Sleep(5);gotoxy(96,14);printf("%c", 178);
	Sleep(5);gotoxy(97,15);printf("%c", 178);
	for(int i = 16 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(98,i);printf("%c", 178);
	}
	
	gotoxy(93,16);//ngang
	for(int i = 0 ; i <=3 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	////AA////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	////G/////
	for(int i = 14 ; i <= 19 ; i++)
	{//doc
		Sleep(5);gotoxy(100,i);printf("%c", 178);
	}
	gotoxy(101,13);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	
	gotoxy(101,20);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	
	for(int i = 18 ; i <= 19 ; i++)
	{//doc
		Sleep(5);gotoxy(106,i);printf("%c", 178);
	}
	
	gotoxy(104,17);//ngang
	for(int i = 0 ; i <= 3 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	////G////
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 6);
	///E////
	for(int i = 14 ; i <= 19 ; i++)
	{//doc
		Sleep(5);gotoxy(109,i);printf("%c", 178);
	}
	gotoxy(110,13);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	
	gotoxy(110,16);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	
	gotoxy(110,20);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	///E////

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	////R/////
	for(int i = 13 ; i <= 20 ; i++)
	{//doc
		Sleep(5);gotoxy(116,i);printf("%c", 178);
	}
	
	gotoxy(117,13);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	
	for(int i = 14 ; i <= 15 ; i++)
	{//doc
		Sleep(5);gotoxy(122,i);printf("%c", 178);
	}
	
	gotoxy(117,16);//ngang
	for(int i = 0 ; i <= 4 ; i ++)
	{
		Sleep(5);printf("%c", 178);
	}
	Sleep(5);gotoxy(120,17);printf("%c", 178);
	Sleep(5);gotoxy(121,18);printf("%c", 178);
	Sleep(5);gotoxy(122,19);printf("%c", 178);
	Sleep(5);gotoxy(123,20);printf("%c", 178);
	///////R///
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 11);
	gotoxy(13,25);
	for(int i = 0; i <= 127 ; i++)
	{
		Sleep(5);printf("%c", 178);
	}
}


void Show_banner_student()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	char a[1024] = "     HOC VIEN CONG NGHE BUU CHINH VIEN THONG     VO DUY KHANH - N16DCCN076 - D16CQCN02-N     ",b[1024],c[40];
	strcpy(b,a);
	strcat(a,b);//---SEE YOU AGAIN------SEE YOU AGAIN---
	
	SetBGColor(5);SetColor(15);
	gotoxy(53,26);cout<<"  Sinh Vien Thuc Hien De Tai: VO DUY KHANH  ";
	gotoxy(53,28);cout<<"  Ma So - Lop: N16DCCN076 - D16CQCN02-N     ";
	gotoxy(53,30);cout<<"  Giang Vien: LUU NGUYEN KY THU             ";
	gotoxy(53,32);cout<<"  DE TAI: QUAN LY CHUYEN BAY                ";
	
	for(int i=0; i< strlen(a);i++)
	{
		strncpy(c,a+i,30);
		Sleep(100);

		gotoxy(60,25);
		srand(time(NULL));
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		cout<<c;
		if(i == strlen(b)-25) i = 5000;
	}
}

/*------------------------FRAME-------------------------*/


void ScreenApp()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (15 << 4) | 12);
	
	gotoxy(12,1);
	cout<<"                           "<<endl;
	gotoxy(12,2);
	cout<<"    QUAN LY CHUYEN BAY     "<<endl;
	gotoxy(12,3);
	cout<<"                           "<<endl;
	
	///////khung ngang
	gotoxy(12,4);
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
	for(int i = 0; i < 65 ; i++)
	{
		printf("%c", 220);printf("%c", 223);
	}
	cout<<endl;
	
	////khung doc
	for(int i = 5 ; i <= 51 ; i++)
	{
		gotoxy(12,i);printf("%c", 176);
	}
	
	for(int i = 5 ; i <= 51 ; i++)
	{
		gotoxy(141,i);printf("%c", 176);
	}

	
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
	gotoxy(13,47);
		for(int i = 0 ; i< 128 ; i++)
		{
			printf("%c", 223);
		}
		
	///////khung ngang
	gotoxy(12,51);
	SetConsoleTextAttribute(consoleHandle, (8 << 4) | 3);
		for(int i = 0; i < 65 ; i++)
	{
		printf("%c", 220);printf("%c", 223);
	}
}







/*------------------------------------BOX--------------------------------------------*/

void BoxSetColorConSole(string message)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	///////khung ngang
	gotoxy(51,42);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	for(int i = 0; i < 28 ; i++)
	{
		printf("%c", 196);
	}
	
	////khung doc
	gotoxy(51,43);
	printf("%c", 176);
	gotoxy(78,43);
	printf("%c", 176);
	gotoxy(51,45);
	printf("%c", 176);
	gotoxy(78,45);
	printf("%c", 176);

	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(52,43);
	cout<<"          MESSAGE         ";

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(51,44);
		for(int i = 0 ; i< 28 ; i++)
		{
			printf("%c", 196);
		}
		
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(52,45);cout<<"                         ";
	gotoxy(52,45);cout<<message;
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(51,46);//46
		for(int i = 0 ; i< 28 ; i++)
		{
			printf("%c", 196);
		}
	gotoxy(12,55);system("pause");
}

void BoxMessage(string message)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);

	///////khung ngang
	gotoxy(41,42);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	for(int i = 0; i < 50 ; i++)
	{
		printf("%c", 196);
	}
	
	////khung doc
	gotoxy(41,43);
	printf("%c", 176);
	gotoxy(90,43);
	printf("%c", 176);
	gotoxy(41,45);
	printf("%c", 176);
	gotoxy(90,45);
	printf("%c", 176);

	gotoxy(42,43);
	SetConsoleTextAttribute(consoleHandle, (0 << 4) | 15);
	cout<<"                    MESSAGE                     ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,44);
		for(int i = 0 ; i< 50 ; i++)
		{
			printf("%c", 196);
		}
		
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(42,45);cout<<"                                                ";
	gotoxy(42,45);
	cout<<message;
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,46);//46
		for(int i = 0 ; i< 50 ; i++)
		{
			printf("%c", 196);
		}
	gotoxy(105,52);
	system("pause");

}

void BoxConfirmSaveFile()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(63,35);
	cout<<"                            ";
	gotoxy(63,36);
	cout<<"    SAVE (CHANGE) IN FILE   ";
	gotoxy(63,37);
	cout<<"                            ";
}


void BoxAddMayBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(13,12);
	cout<<"                          "<<endl;
	gotoxy(13,13);
	cout<<"      THEM MAY BAY        "<<endl;
	gotoxy(13,14);
	cout<<"                          "<<endl;
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 4);
	gotoxy(13,15);
	for(int i = 0; i < 66 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(13,17);
	for(int i = 0; i < 66 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(13,19);
	for(int i = 0; i < 66 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(13,21);
	for(int i = 0; i < 66 ; i++)
	{
		printf("%c", 196);
	}
	
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);	
	gotoxy(58,22);
	cout<<"          "<<endl;
	gotoxy(58,23);
	cout<<"   ENTER  "<<endl;
	gotoxy(58,24);
	cout<<"          "<<endl;
	
	SetConsoleTextAttribute(consoleHandle, (12 << 4) | 0);	
	gotoxy(69,22);
	cout<<"          "<<endl;
	gotoxy(69,23);
	cout<<"    ESC   "<<endl;
	gotoxy(69,24);
	cout<<"          "<<endl;
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);	
	gotoxy(58,25);
	cout<<" Xac Nhan "<<endl;
	gotoxy(69,25);
	cout<<"    Huy   "<<endl;
	///NOTE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,26);cout<<"( Luu Y )";
	gotoxy(13,27);cout<<"- So Hieu May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,28);cout<<"- Loai May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,29);cout<<"- So Cho Ngoi >= 20 && <= 70.";
	gotoxy(13,30);cout<<"- Vui Long Tat CapsLock.";
	
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	gotoxy(13,16);
	cout << "NHAP SO HIEU MAY BAY :> ";//cho bat loi nhap chuoi - dang gap loi nho
	gotoxy(13,18);
	cout << "NHAP LOAI MAY BAY    :> ";
	gotoxy(13,20);
	cout << "NHAP SO CHO NGOI     :> ";//sau khi cap nhap so cho ngoi thi cap nhap so ve cua may bay
	
	for(int i = 5; i <= 46 ; i++)
	{
		gotoxy(121,i);printf("%c", 176);
	}

	SetConsoleTextAttribute(consoleHandle, (10 << 4) |0);	
	gotoxy(122,5);
	cout<<"                   "<<endl;
	gotoxy(122,6);
	cout<<"    LIST MAY BAY   "<<endl;
	gotoxy(122,7);
	cout<<"                   "<<endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 4);
	
}

void BoxDeleteMayBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 4);

	gotoxy(13,13);
	cout<<"--------------------------"<<endl;
	gotoxy(13,14);
	cout<<"|       XOA MAY BAY      |"<<endl;
	gotoxy(13,15);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(13,16);cout<<"DSMB "<<endl;
	
	gotoxy(13,17);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	////////
	gotoxy(13,18);
	SetColor(1);
	cout<<"NHAP SHMB CAN XOA: ";
	////////
	gotoxy(13,19);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(13,21);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(13,23);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
}

void BoxShowUpdateMayBay()//khong su dung
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 4);
	
	gotoxy(13,13);
	cout<<"--------------------------"<<endl;
	gotoxy(13,14);
	cout<<"|   HIEU CHINH MAY BAY   |"<<endl;
	gotoxy(13,15);//-------------------------------------------
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	
	
	gotoxy(13,17);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(13,18);SetColor(1);
	cout <<"Nhap SHMB can hieu chinh:	";

	gotoxy(13,19);
	for(int i = 0; i < 128 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
}

void BoxImpementUpdateMayBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	gotoxy(41,16);
	for(int i = 0; i < 43 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(41,18);
	for(int i = 0; i < 43 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(41,20);
	for(int i = 0; i < 43 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(41,22);
	for(int i = 0; i < 43 ; i++)
	{
		printf("%c", 196);
	}
	
	
	//////BUTTON///////////
	SetConsoleTextAttribute(consoleHandle, (12 << 4) | 0);	
	gotoxy(85,17);
	cout<<"          "<<endl;
	gotoxy(85,18);
	cout<<"    ESC   "<<endl;
	gotoxy(85,19);
	cout<<"          "<<endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(85,20);
	cout<<"    Huy   "<<endl;
	
	///NOTE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,26);cout<<"( Luu Y )";
	gotoxy(13,27);cout<<"- So Hieu May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,28);cout<<"- Loai May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,29);cout<<"- So Cho Ngoi >= 20 && <= 70.";
	gotoxy(13,30);cout<<"- Vui Long Tat CapsLock.";
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
	gotoxy(41,17);cout << "NHAP SHMB MOI   :> ";//cho bat loi nhap chuoi - dang gap loi nho
	gotoxy(41,19);cout << "NHAP LOAI MB MOI:> ";
	gotoxy(41,21);cout << "NHAP SO CHO     :> ";//sau khi cap nhap so cho ngoi thi cap nhap so ve cua may bay
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
}

void BoxShowDSMB()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(120,i);printf("%c", 176);
	}
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) |0);	
	gotoxy(121,5);
	cout<<"                    "<<endl;
	gotoxy(121,6);
	cout<<"  DANH SACH MAY BAY "<<endl;	
	gotoxy(121,7);
	cout<<"                    "<<endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
}

void BoxShow1MB(MAYBAY mb)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(85,5);cout<<"                                 ";
	gotoxy(85,6);cout<<"         DETAIL AIRPLANE         ";
	gotoxy(85,7);cout<<"                                 ";
	gotoxy(85,8);cout<<"                                 ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	for(int i = 5 ; i <= 16 ; i++)
	{
		gotoxy(84,i);cout<<"|";
	}
	
	for(int i = 5 ; i <= 16 ; i++)
	{
		gotoxy(118,i);cout<<"|";
	}

	gotoxy(84,16);
	for(int i = 0; i < 35 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(85,9);
	cout<<"SHMB    :>";
	gotoxy(100,9);cout<<"                  ";
	gotoxy(100,9);cout<<mb.sohieuMB;
	
	gotoxy(85,11);
	cout<<"LOAI MB :>";
	gotoxy(100,11);cout<<"                  ";
	gotoxy(100,11);cout<<mb.loaiMB;
	
	gotoxy(85,13);
	cout<<"SO CHO  :>";
	gotoxy(100,13);cout<<"                  ";
	gotoxy(100,13);cout<<mb.sochoMB;
	
	gotoxy(85,15);
	cout<<"STATUS    :>";
	gotoxy(100,15);cout<<"                  ";
	string status;
	if(mb.x == 1)
	{
		status = "READY";
	}
	else status = "BUSY";
	gotoxy(100,15);cout<<status;
	
}



void BoxShowAirPort()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 4);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(13,48);
	cout<<"                     "<<endl;
	gotoxy(13,49);
	cout<<"    1. HO CHI MINH   "<<endl;
	gotoxy(13,50);
	cout<<"                     "<<endl;
	
	////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 0);
	gotoxy(39,48);
	cout<<"                     "<<endl;
	gotoxy(39,49);
	cout<<"     2. PHU QUOC     "<<endl;
	gotoxy(39,50);
	cout<<"                     "<<endl;
	
	////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(67,48);
	cout<<"                     "<<endl;
	gotoxy(67,49);
	cout<<"     3. NHA TRANG    "<<endl;
	gotoxy(67,50);
	cout<<"                     "<<endl;
	
	////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (9 << 4) | 0);
	gotoxy(95,48);
	cout<<"                     "<<endl;
	gotoxy(95,49);
	cout<<"      4. HA NOI      "<<endl;
	gotoxy(95,50);
	cout<<"                     "<<endl;
	
	////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (6 << 4) | 0);
	gotoxy(121,48);
	cout<<"                    "<<endl;
	gotoxy(121,49);
	cout<<"     5. CAN THO     "<<endl;
	gotoxy(121,50);
	cout<<"                    "<<endl;
}


void BoxAddChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);	
	gotoxy(88,31);
	cout<<"          "<<endl;
	gotoxy(88,32);
	cout<<"   ENTER  "<<endl;
	gotoxy(88,33);
	cout<<"          "<<endl;

	
	SetConsoleTextAttribute(consoleHandle, (12 << 4) | 0);	
	gotoxy(98,31);
	cout<<"          "<<endl;
	gotoxy(98,32);
	cout<<"    ESC   "<<endl;
	gotoxy(98,33);
	cout<<"          "<<endl;
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);	
	gotoxy(88,34);
	cout<<" Xac Nhan "<<endl;
	gotoxy(98,34);
	cout<<"    Huy   "<<endl;
	
	///NOTE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,36);cout<<"( Luu Y )";
	gotoxy(13,37);cout<<"- Ma So Chuyen Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,38);cout<<"- Ngay-Thang-Nam-Gio chi chua cac ky tu {0-9}.";
	gotoxy(13,39);cout<<"- San Bay: Nhap So Tuong Ung Voi Bang Duoi";
	gotoxy(13,40);cout<<"- So Hieu May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,41);cout<<"- Vui Long Tat CapsLock.";
	gotoxy(13,42);cout<<"- Nhan ESC De Thoat.";
	
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(13,12);
	cout<<"                          "<<endl;
	gotoxy(13,13);
	cout<<"      THEM CHUYEN BAY     "<<endl;
	gotoxy(13,14);
	cout<<"                          "<<endl;
	
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(13,15);cout <<"            ";
	gotoxy(13,16);cout <<" NHAP MSCB  ";
	gotoxy(13,17);cout <<"            ";
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(13,18);
	for(int i = 13; i < 88 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(13,19);cout <<"            ";
	gotoxy(13,20);cout <<" NHAP NGAY  ";
	gotoxy(13,21);cout <<"            ";
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(41,19);cout <<"            ";
	gotoxy(41,20);cout <<" NHAP THANG ";
	gotoxy(41,21);cout <<"            ";
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(65,19);cout <<"            ";
	gotoxy(65,20);cout <<"  NHAP NAM  ";
	gotoxy(65,21);cout <<"            ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(13,22);
	for(int i = 13; i < 88 ; i++)
	{
		printf("%c", 196);
	}
	
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(13,23);cout <<"            ";
	gotoxy(13,24);cout <<"    GIO DI  ";
	gotoxy(13,25);cout <<"            ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(13,26);
	for(int i = 13; i < 88 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (0 << 4) | 14);
	gotoxy(13,27);cout <<"            ";
	gotoxy(13,28);cout <<"   SAN BAY  ";
	gotoxy(13,29);cout <<"            ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(13,30);
	for(int i = 13; i < 88 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (0 << 4) | 7);
	gotoxy(13,31);cout <<"                                        ";
	gotoxy(13,32);cout <<"  SO HIEU MAY BAY THUC HIEN CHUYEN BAY  ";
	gotoxy(13,33);cout <<"                                        ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(13,34);
	for(int i = 13; i < 88 ; i++)
	{
		printf("%c", 196);
	}
	
	
	////KHUNG SHOW TIME///
	gotoxy(0,15);
	for(int i = 0; i < 12 ; i++)
	{
		printf("%c", 196);
	}
	for(int i = 16 ; i <20 ; i++)
	{
		gotoxy(0,i);
		printf("%c", 176);
	}
	
	gotoxy(0,20);
	for(int i = 0; i < 12 ; i++)
	{
		printf("%c", 196);
	}

}


void BoxUpdateChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(41,19);
	cout<<"                                               "<<endl;
	gotoxy(41,20);
	cout<<"               UPDATE CHUYEN BAY               "<<endl;
	gotoxy(41,21);
	cout<<"                                               "<<endl;
	
	
	//NODE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,35);cout<<"( Luu Y )";
	gotoxy(13,36);cout<<"- Ma So Chuyen Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,37);cout<<"- Ngay-Thang-Nam-Gio chi chua cac ky tu {0-9}.";
	gotoxy(13,38);cout<<"- San Bay: Nhap So Tuong Ung Voi Bang Duoi";
	gotoxy(13,39);cout<<"- So Hieu May Bay chi chua cac ky tu {a-z},{0-9},{-}.";
	gotoxy(13,40);cout<<"- Vui Long Tat CapsLock.";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(41,23);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,25);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,27);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,29);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,31);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,33);
	for(int i = 0; i < 40 ; i++)
	{
		printf("%c", 196);
	}
	
	gotoxy(41,24);
	SetColor(3);
	cout<<"NHAP NGAY MOI  :>";

	gotoxy(41,26);
	SetColor(3);
	cout<<"NHAP THANG MOI  :>";

	gotoxy(41,28);
	SetColor(3);
	cout<<"NHAP NAM  :>";
	
	gotoxy(41,30);
	SetColor(3);
	cout<<"NHAP GIO  :>";
	
	gotoxy(41,32);
	SetColor(3);
	cout<<"NHAP SAN BAY  :>";
	
}

void BoxHuyChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(41,16);cout<<"                                               ";
	gotoxy(41,17);cout<<"                HUY CHUYEN BAY                 ";
	gotoxy(41,18);cout<<"                                               ";
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(41,20);cout<<"                            ";
	gotoxy(41,21);cout<<"NHAP MSCB CHUYEN BAY CAN HUY";
	gotoxy(41,22);cout<<"                            ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(70,23);
	for(int i = 0 ; i < 18 ; i++)
	{
		printf("%c", 196);
	}
}


void BoxShow1CB(CHUYENBAY cb)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (9 << 4) | 0);
	gotoxy(90,5);cout<<"                            ";
	gotoxy(90,6);cout<<"       DETAIL FLIGHT        ";
	gotoxy(90,7);cout<<"                            ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(89,22);
	for(int i = 0; i < 30 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	//khung doc ben trai
	for(int i = 5 ; i <= 21 ; i++ )
	{
		gotoxy(89,i);cout<<"|";
	}

	//khung doc ben phai
	for(int i = 5 ; i <= 21 ; i++ )
	{
		gotoxy(118,i);cout<<"|";
	}

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	gotoxy(90,9);
	cout<<"MSCB    :>";
	gotoxy(101,9);cout<<"                 ";
	gotoxy(101,9);cout<<cb.MSCB;
	
	gotoxy(90,11);
	cout<<"TIME    :>";
	gotoxy(101,11);cout<<"                 ";
	gotoxy(101,11);cout<<cb.ngayDi<<"/"<<cb.thangDi<<"/"<<cb.namDi;
	
	gotoxy(90,13);
	cout<<"HOUR    :>";
	gotoxy(101,13);cout<<"                 ";
	gotoxy(101,13);cout<<cb.gioDi;
	
	gotoxy(90,15);
	cout<<"AIRPORT :>";
	gotoxy(101,15);cout<<"                 ";
	gotoxy(101,15);cout<<cb.sanBay;
	
	gotoxy(90,17);
	cout<<"SHMB    :>";
	gotoxy(101,17);cout<<"                 ";
	gotoxy(101,17);cout<<cb.sohieumb;
	
	gotoxy(90,19);
	cout<<"STATUS  :>";
	gotoxy(101,19);cout<<"                 ";
	gotoxy(101,19);cout<<staTus[cb.staTus];
	
	gotoxy(90,21);
	cout<<"SO VE DUOC DAT :>";
	gotoxy(106,21);cout<<"        ";
	gotoxy(110,21);cout<<cb.soveduocdat;
	
	/*---Show Ve---*/
//	int pos = 90;int pox = 22;
//	for(int i = 0 ; i < cb.soluongVe ; i++)
//	{
//		if(cb.nodeVe[i] != "0")
//		{
//			pox++;
//			gotoxy(pos,pox);cout<<cb.nodeVe[i];
//		}
//	}
	
}

void BoxShowDSCB()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(120,i);printf("%c", 176);
	}

	SetConsoleTextAttribute(consoleHandle, (1 << 4) | 15);	
	gotoxy(121,5);
	cout<<"                    "<<endl;
	gotoxy(121,6);
	cout<<"DANH SACH CHUYEN BAY"<<endl;	
	gotoxy(121,7);
	cout<<"                    "<<endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);

}

void BoxShowChuyenBayDeXuat()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);	
	gotoxy(121,5);
	cout<<"                    "<<endl;
	gotoxy(121,6);
	cout<<" CHUYEN BAY DE XUAT "<<endl;	
	gotoxy(121,7);
	cout<<"                    "<<endl;
	
	for(int i= 5 ; i <= 46 ; i++)
	{//khung doc
		gotoxy(120,i);printf("%c", 176);
	}
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
}

void BoxShowVeChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 15);
	gotoxy(92,5);cout<<"                  ";
	gotoxy(92,6);cout<<"   DANH SACH VE   ";
	gotoxy(92,7);cout<<"                  ";

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(111,i);printf("%c", 176);
	}
}

void BoxShowVeTrongChuyenBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 15);
	gotoxy(102,5);cout<<"                       ";
	gotoxy(102,6);cout<<"   DANH SACH VE TRONG  ";
	gotoxy(102,7);cout<<"                       ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(125,i);printf("%c", 176);
	}
}

void BoxShowChuyenBayTheoThoiGian_ConVe()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 12);
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(115,i);printf("%c", 176);
	}

	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);	
	gotoxy(116,5);
	cout<<"                         "<<endl;
	gotoxy(116,6);
	cout<<"   DANH SACH CHUYEN BAY  "<<endl;	
	gotoxy(116,7);
	cout<<"                         "<<endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);	
}

void BoxShowDanhSachHanhKhach(char MSCB[],int ngaydi, int thangdi, int namdi, int giodi, string sanbayden,int status)//truyen len de hien thi MSCB
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (3 << 4) | 0);
	gotoxy(13,5);
	cout<<"                          ";
	gotoxy(13,6);
	cout<<"   DANH SACH HANH KHACH   ";
	gotoxy(13,7);
	cout<<"                          ";
	
	//////////////////////////////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (2 << 4) | 14);
	gotoxy(13,8);
	cout<<"                          ";
	gotoxy(13,9);
	cout<<"                          ";
	gotoxy(15,9);
	cout<<MSCB;SetColor(15);cout<<"  ["<<status<<"]";
	gotoxy(13,10);
	cout<<"                          ";
	//////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (2 << 4) | 14);
	gotoxy(13,12);
	cout<<"               ";
	gotoxy(13,13);
	cout<<"               ";
	gotoxy(15,13);
	cout<<ngaydi<<"/"<<thangdi<<"/"<<namdi;
	gotoxy(13,14);
	cout<<"               ";
	//////////////////////////////////////////////////////
	
	
	//////////////////////////////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (2 << 4) | 14);
	gotoxy(29,12);
	cout<<"          ";
	gotoxy(29,13);
	cout<<"          ";
	gotoxy(31,13);
	cout<<giodi<<"h";
	gotoxy(29,14);
	cout<<"          ";
	//////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (2 << 4) | 14);
	gotoxy(13,16);
	cout<<"                          ";
	gotoxy(13,17);
	cout<<"                          ";
	gotoxy(15,17);
	cout<<" To: "<<sanbayden;
	gotoxy(13,18);
	cout<<"                          ";
	//////////////////////////////////////////////////////
	
	SetConsoleTextAttribute(consoleHandle, (2 << 4) | 14);
	gotoxy(29,21);cout<<"     ";
	gotoxy(29,22);cout<<"  <  ";
	gotoxy(29,23);cout<<"     ";
	
	
	SetConsoleTextAttribute(consoleHandle, (9 << 4) | 0);
	gotoxy(34,21);cout<<"     ";
	gotoxy(34,22);cout<<"  >  ";
	gotoxy(34,23);cout<<"     ";
	
	
	SetConsoleTextAttribute(consoleHandle, (15 << 4) | 0);
	gotoxy(29,25);cout<<"Prew";
	gotoxy(34,25);cout<<"Next";
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <=23 ; i++)
	{//thanh doc
		gotoxy(40,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(41,5);cout<<"       ";
	gotoxy(41,6);cout<<"  STT  ";
	gotoxy(41,7);cout<<"       ";
	////////////////////////////
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <=23 ; i++)
	{//thanh doc
		gotoxy(48,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(49,5);cout<<"                 ";
	gotoxy(49,6);cout<<"     SO CMND     ";
	gotoxy(49,7);cout<<"                 ";
	////////////////////////////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <= 23; i++)
	{//thanh doc
		gotoxy(66,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(67,5);cout<<"                 ";
	gotoxy(67,6);cout<<"        HO       ";
	gotoxy(67,7);cout<<"                 ";
	////////////////////////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <= 23; i++)
	{//thanh doc
		gotoxy(84,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(85,5);cout<<"                       ";
	gotoxy(85,6);cout<<"          TEN          ";
	gotoxy(85,7);cout<<"                       ";
	////////////////////////////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <= 23; i++)
	{//thanh doc
		gotoxy(108,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(109,5);cout<<"               ";
	gotoxy(109,6);cout<<"   GIOI TINH   ";
	gotoxy(109,7);cout<<"               ";
	//////////////////////////////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	for(int i = 5 ; i <= 23; i++)
	{//thanh doc
		gotoxy(124,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(125,5);cout<<"                ";
	gotoxy(125,6);cout<<"     SO VE      ";
	gotoxy(125,7);cout<<"                ";
	//////////////////////////////
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 15);
	gotoxy(41,23);
	for(int i = 5 ; i < 105 ; i++)
	{
		printf("%c", 176);
	}
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
}

void BoxShowSanBay_DatVe()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,7);
		for(int i = 0 ; i< 30 ; i++)
		{
			printf("%c", 196);
		}
		
	////khung doc
	gotoxy(40,8);
	printf("%c", 176);
	gotoxy(69,8);
	printf("%c", 176);
	gotoxy(41,8);
	cout<<"CHON SAN BAY:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,9);
	for(int i = 0 ; i< 30 ; i++)
	{
		printf("%c", 196);
	}
	
	////khung doc
	gotoxy(40,10);
	printf("%c", 176);
	gotoxy(69,10);
	printf("%c", 176);
	
	gotoxy(41,10);
	cout<<"NHAP NGAY DI:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,11);
	for(int i = 0 ; i< 30 ; i++)
	{
		printf("%c", 196);
	}

	////khung doc
	gotoxy(40,12);
	printf("%c", 176);
	gotoxy(69,12);
	printf("%c", 176);
	
	gotoxy(41,12);
	cout<<"NHAP MSCB:";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,13);
	for(int i = 0 ; i< 30 ; i++)
	{
		printf("%c", 196);
	}
}

void BoxThongKeLuotBay()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 15);
	gotoxy(80,5);cout<<"                    ";
	gotoxy(80,6);cout<<"                    ";
	gotoxy(80,6);cout<<"  THONG KE LUOT BAY ";
	gotoxy(80,7);cout<<"                    ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(100,i);printf("%c", 176);
	}
	
	
	SetConsoleTextAttribute(consoleHandle, (9 << 4) | 15);
	gotoxy(101,5);cout<<"                            ";
	gotoxy(101,6);cout<<"                            ";
	gotoxy(101,6);cout<<"       SO HIEU MAY BAY      ";
	gotoxy(101,7);cout<<"                            ";
	
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	for(int i = 5 ; i <= 46 ; i++)
	{
		gotoxy(129,i);printf("%c", 176);
	}
	
	SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
	gotoxy(130,5);cout<<"           ";
	gotoxy(130,6);cout<<"           ";
	gotoxy(130,6);cout<<"  SO LUOT  ";
	gotoxy(130,7);cout<<"           ";
}


void BoxEraseListHK()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
	
	
	//STT
	for(int y = 9 ; y <= 20 ; y++)
	{
		gotoxy(43,y);cout<<"  ";
	}
	//CMND
	for(int y = 9; y <= 20 ; y++)
	{
		gotoxy(53,y);cout<<"          ";
	}
	//HO
	for(int y = 9; y <= 20 ; y++)
	{
		gotoxy(70,y);cout<<"            ";
	}
	//TEN
	for(int y = 9; y <= 20 ; y++)
	{
		gotoxy(90,y);cout<<"               ";
	}
	//GIOI TINH
	for(int y = 9 ; y <= 20; y++)
	{
		gotoxy(114,y);cout<<"     ";
	}
	//SO VE
	for(int y = 9 ; y <= 20 ; y++)
	{
		gotoxy(127,y);cout<<"            ";
	}
	
}




void BoxXacNhanThongTinDatVe()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,17);
	for(int i = 0 ; i< 58 ; i++)
	{
		printf("%c", 196);
	}
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 1);
	gotoxy(41,18);cout<<"                                                        ";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
	gotoxy(58,19);cout<<"THONG TIN HANH KHACH";
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 1);
	gotoxy(41,20);cout<<"                                                        ";
	
	
	//khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,21);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung ngang
	gotoxy(42,23);cout<<"HO VA TEN:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,25);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	//khung ngang
	gotoxy(42,27);cout<<"SO CMND:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,29);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	//khung ngang
	gotoxy(42,31);cout<<"GIOI TINH:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,33);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	gotoxy(72,34);cout<<"XAC NHAN THONG TIN";
	
	//khung ngang duoi cung
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,35);
	for(int i = 0 ; i< 58 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung doc
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////khung doc
	for(int i = 18; i < 35 ; i++)
	{
		gotoxy(40,i);printf("%c", 176);
	}
	//khung doc
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////khung doc
	for(int i = 18; i < 35 ; i++)
	{
		gotoxy(97,i);printf("%c", 176);
	}
}

void BoxDienThongTinDatVe()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//NODE
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
	gotoxy(14,38);cout<<"( Luu Y )";
	gotoxy(13,39);cout<<"- Ho Ten chi chua cac ky tu {a-z}, Khong Duoc Chua Dau Space.";
	gotoxy(13,40);cout<<"- Gioi Tinh Nhap Cac So {1,2,3}";
	gotoxy(13,41);cout<<"- Vui Long Tat CapsLock.";
	gotoxy(13,42);cout<<"- Nhan ESC De Thoat.";
	
	
	//khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(40,17);
	for(int i = 0 ; i< 58 ; i++)
	{
		printf("%c", 196);
	}
	
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 1);
	gotoxy(41,18);cout<<"                                                        ";
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
	gotoxy(56,19);cout<<"NHAP THONG TIN HANH KHACH";
	
	SetConsoleTextAttribute(consoleHandle, (5 << 4) | 1);
	gotoxy(41,20);cout<<"                                                        ";
	
	//khung ngang
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,21);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung ngang
	gotoxy(42,23);cout<<"NHAP HO:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,24);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung ngang
	gotoxy(42,26);cout<<"NHAP TEN:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,27);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung ngang
	gotoxy(42,29);cout<<"SO CMND:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,30);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung ngang
	gotoxy(42,32);
	cout << "1. " << gioiTinh[0] << "\t2." << gioiTinh[1] << "\t3." << gioiTinh[2] << endl;
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,33);
	for(int i = 0 ; i< 57 ; i++)
	{
		printf("%c", 196);
	}
	
	
	gotoxy(41,34);cout<<"GIOI TINH:";
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,35);
	for(int i = 0 ; i< 56 ; i++)
	{
		printf("%c", 196);
	}
	
	
	gotoxy(72,36);cout<<"XAC NHAN THONG TIN";
	
	//khung ngang duoi cung
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(41,38);
	for(int i = 0 ; i< 56 ; i++)
	{
		printf("%c", 196);
	}
	
	//khung doc
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	for(int i = 18; i < 39 ; i++)
	{
		gotoxy(40,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	////khung doc
	for(int i = 18; i < 39 ; i++)
	{
		gotoxy(97,i);printf("%c", 176);
	}
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);

}

/*------------------------------------BOX--------------------------------------------*/

