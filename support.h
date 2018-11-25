/*------------------REPAIR INPUT--------------------*/

bool CheckDataMayBay(string text[])
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* sochongoi = text[2].c_str();
	if(text[0].length() == 0)
	{
		BoxMessage("          CHUA NHAP SO HIEU BAY MAY");
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		return false;
	}
	if(text[1].length() == 0)
	{
		BoxMessage("             CHUA NHAP LOAI MAY BAY");
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		return false;
	}
	if(text[2].length() == 0)
	{
		BoxMessage("             CHUA NHAP SO CHO NGOI");
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		return false;
	}
	if(atoi(sochongoi) < 20 || atoi(sochongoi) > 70)
	{
		BoxMessage("         SO CHO NGOI KHONG CHINH XAC");
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		return false;
	}
	return true;
}



void NhapThongTinMayBay(MAYBAY &mb , int x , int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int xi = x; int yi = y;//vi tri bat dau
	char c;
	int inpos = 0;
	string data[3] = {"","",""};
	gotoxy(xi,yi);
	do
	{
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		c = getch();
		switch(c)
		{
			case 13://enter
			{
				if(CheckDataMayBay(data) == true)
				{
					strcpy(mb.sohieuMB , data[0].c_str());//Chuyen kieu string sang char*
					strcpy(mb.loaiMB , data[1].c_str());
					const char* sochongoi = data[2].c_str();
					mb.sochoMB = atoi(sochongoi);
					return;
				}
				else
				{
					gotoxy(42,45);cout<<"                                                ";//khoang trang de de len message	
					gotoxy(xi,yi);
					cout<<data[inpos];
				}
					break;
			}
				
			case 8://backspace
			{
				if(data[inpos].length() > 0)
				{
					data[inpos].erase(data[inpos].length()-1 , 1);
					cout<< "\b \b";
				}
				break;
			}
			
			case 9://tab
			{
				if(inpos == 0)
				{
					yi += 2;//TYPE MB
					inpos = 1;gotoxy(xi,yi);
					cout<<data[inpos];
				}
				else if(inpos == 1)
				{
					yi += 2;//SO CHO NGOI
					inpos = 2;gotoxy(xi,yi);
					cout<<data[inpos];
				}
				else if(inpos == 2)
				{
					yi = y;//SHMB
					inpos = 0;gotoxy(xi,yi);
					cout<<data[inpos];
				}
				break;
			}
			
			case 27:{
				mb.sohieuMB[0] = 'E';//tuc la nhan duoc nut ESC va thoat
				return;
			}
			
			default:
			{
				if(inpos == 0 || inpos == 1)//SHMB - TYPEMB
				{
					if(data[inpos].length() < 15)
					{
						if( (c >= 48 && c <=57) || (c >= 97 && c <= 122) || c == '-')
						{
							gotoxy(xi,yi);cout<<"                ";
							c=toupper(c);
							data[inpos] += c;
							gotoxy(xi,yi);
							cout<< data[inpos];
						}
						break;
					}
				}
				else if(inpos == 2)//
				{
					if(data[inpos].length() < 2)//so cho ngoi
					{
						if( (c >= 48 && c <=57))
						{
							gotoxy(xi,yi);cout<<"                ";
							c=toupper(c);
							data[inpos] += c;
							gotoxy(xi,yi);
							cout<< data[inpos];
						}
						break;
					}
				}
			}
		}
	}while(c!=27);
}

/*------------------REPAIR INPUT--------------------*/





/*----------------------Nhap May Bay------------------*/
char *NhapSoHieuMayBay(int n,int xi,int yi)//HOAN CHINH//
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
		if(i < n)
		{
			if( (c >= 48 && c <=57) || (c >= 97 && c <= 122) || c == '-')
			{
				c=toupper(c);
				S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
			}
			
			else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
			if(i==0)
			{
				S[i]=NULL;
			}
		}

		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n-1)break;
	}
	S[i]='\0';
	return S;
}


char *NhapLoaiMayBay(int n,int xi,int yi)//HOAN CHINH//
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
	if( (c >= 48 && c <=57) || (c >=97 && c <= 122) || c == '-')
		{
				c=toupper(c);
				S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang

		}
		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(i==n)break;
	}
	S[i]='\0';
	return S;
}


char *NhapSoChoNgoi(int n,int xi,int yi)//toi thieu 20 cho va toi da 70 cho -HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < n || S[0] == NULL)
	{
		if(i == 0)
		{
			if(c >= 50 && c <= 55)//2-7
			{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
				{
					S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
				}
			}
		}///END i = 0
		
		else if(i > 0 && i < n)
		{
			char f = int(S[0]);
			if(f == 55)//So dau tien la so 7
			{
				if(c == 48)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
				}
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i] = NULL;
				}
			}
			else//trong khoang kia
			{
				if(c >= 48 && c <= 57)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
				}
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
			}
		}
		
		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i > 1)break;
		}
		S[i]='\0';
		return S;
}
/*----------------------Nhap May Bay------------------*/



/*---------------Nhap Thong Tin Dat Ve----------------*/
char *NhapSoVe(int n, int xi, int yi)//HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < n || S[0] == NULL)
		{

			if(i == 0)//SO DAU TIEN
			{
				if(c >= 49 && c <= 57)//cac so 1 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}	
					}	
			}/////SO DAU TIEN
			//////////////////////////////////////
			
			else if(i > 0 && i < n)
			{
				char f = int(S[0]);
				if(f == 55)//ky tu dau tien la 7
					{
						if(c == 48)//thi chi cho nhap so 0
						{
							if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
							{
								S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
							}
						}
						else if(int(c)==8 && i > 0)
						{
							cout<<"\b \b";i--;xi--;
						}
						if(i==0)
						{
							S[i]=NULL;
						}
					}
					
				else 
					{
						char g = int(S[0]);
						if(g >= 49 && g <= 54)//ky tu dau trong khoang 1-6
						{
							if(c >= 48 && c <= 57)
							{
								if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
								{
									S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
								}
							}
							else if(int(c)==8 && i > 0)
							{
								cout<<"\b \b";i--;xi--;
							}
							if(i==0)
							{
								S[i]=NULL;
							}
						}
						else if(g >= 56 && g <= 57)
						{
							if(int(c)==8 && i > 0)
							{
								cout<<"\b \b";i--;xi--;
							}
							if(i==0)
							{
								S[i]=NULL;
							}
						}
					}

			}

		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i >= 1)break;

	}
	S[i]='\0';
	return S;
}


char *NhapSoCMND(int n,int xi,int yi)//HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL || i < n)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
		if( c >= 48 && c <=57 )
			{
				if(i < n)
				{
					S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
				}
			}
		
		else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		if(int(c) == 13 && i == n-1)break;
	}
	S[i]='\0';
	return S;
}

char *NhapHoTenHanhKhach(int n,int xi, int yi)
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
		if( (c >= 65 && c <=90) || (c >= 97 && c <= 122) || c == '-')
			{
				c=toupper(c);
				S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
			}
		
		else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
			
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n-1)break;
	}
	S[i]='\0';
	return S;
}

char *NhapGioiTinh(int n,int xi, int yi)
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
		if(i < n)
		{
			if( c >= 49 && c <= 51 )
			{
				c=toupper(c);
				S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
			}
		
			else if(int(c)==8 && i > 0)
			{
				S[i]=NULL;
				cout<<"\b \b";i--;xi--;
			}
			
			if(i==0)
			{
				S[i]=NULL;
			}
		}

		
		else if(int(c)==8 && i > 0)
			{
				S[i]=NULL;
				cout<<"\b \b";i--;xi--;
			}
			
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n)break;
	}
	S[i]='\0';
	return S;
}
/*---------------Nhap Thong Tin Dat Ve----------------*/



/*-----------------Nhap Chuyen Bay-------------------*/
char *NhapMaChuyenBay(int n,int xi,int yi)//HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || S[0] == NULL)//van con phai nhap khi chua nhan phim enter va mang S chua co ptu nao
	{
		if(i < n)
		{
			if( (c >= 48 && c <=57) || (c >= 97 && c <= 122))
			{
				c=toupper(c);
				S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
			}
			
			else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
			if(i==0)
			{
				S[i]=NULL;
			}
		}

		
		else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n-1)break;
	}
	S[i]='\0';
	return S;
}

char *NhapNgayKhoiHanhCuaChuyenBay(int n, int so_ngay,int xi,int yi)//hoan thien - can sua lai theo kieu 28
{
	
	int pix = xi;
	gotoxy(xi,yi);
	
	int check = 1;
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	//////////////THANG CO 28 NGAY////////////////
	if(so_ngay == 28)//truong hop thang do co 28 ngay
	{
		while((c=getch())!=13 || i < n || S[0] == NULL)
		{
			if(i == 0)//SO DAU TIEN
			{
				if(c >= 49 && c <= 57)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
				}
			}/////SO DAU TIEN
			//////////////////////////////////////
			
			else if(i > 0 && i < n)
			{
				char f = int(S[0]);
				if(f == 49)//ky tu dau la 1
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 50)//ky tu dau la 2
				{
					if(c >= 48 && c <= 56)//thi co the nhap cac so tu 0 - 8
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
					else//ky tu dau la cac so khac
					{
						if(int(c)==8 && i > 0)
						{
							cout<<"\b \b";i--;xi--;
						}
						if(i==0)
						{
							S[i]=NULL;
						}
					}
			}//i > 0 && i < n

		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i >= 1)break;

	}
	S[i]='\0';
	return S;
	}///////////////END 28 NGAY
	
	
	else if(so_ngay == 29)
	{
		while((c=getch())!=13 || i < n || S[0] == NULL)
		{
			if(i == 0)//SO DAU TIEN
			{
				if(c >= 49 && c <= 57)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
				}
			}/////SO DAU TIEN
			//////////////////////////////////////
			
			else if(i > 0 && i < n)
			{
				char f = int(S[0]);
				if(f == 49)//ky tu dau la 1
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 50)//ky tu dau la 2
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
					else//ky tu dau la cac so khac
					{
						if(int(c)==8 && i > 0)
						{
							cout<<"\b \b";i--;xi--;
						}
						if(i==0)
						{
							S[i]=NULL;
						}
					}
			}//i > 0 && i < n

		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i >= 1)break;

	}
	S[i]='\0';
	return S;
	}///////////////END 29 NGAY
	
	
	else if(so_ngay == 30)
	{
		while((c=getch())!=13 || i < n || S[0] == NULL)
		{
			if(i == 0)//SO DAU TIEN
			{
				if(c >= 49 && c <= 57)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
				}
			}/////SO DAU TIEN
			//////////////////////////////////////
			
			else if(i > 0 && i < n)
			{
				char f = int(S[0]);
				if(f == 49)//ky tu dau la 1
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 50)//ky tu dau la 2
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 51)
				{
					if(c == 48)//chi duoc nhap so 0
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
					else//ky tu dau la cac so khac
					{
						if(int(c)==8 && i > 0)
						{
							cout<<"\b \b";i--;xi--;
						}
						if(i==0)
						{
							S[i]=NULL;
						}
					}
			}//i > 0 && i < n

		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i >= 1)break;

	}
	S[i]='\0';
	return S;
	}///////////////END 30 NGAY
	
	else if(so_ngay == 31)//hoan thien
	{
		while((c=getch())!=13 || i < n || S[0] == NULL)
		{
			if(i == 0)//SO DAU TIEN
			{
				if(c >= 49 && c <= 57)
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
				}
			}/////SO DAU TIEN
			//////////////////////////////////////
			
			else if(i > 0 && i < n)
			{
				char f = int(S[0]);
				if(f == 49)//ky tu dau la 1
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 50)//ky tu dau la 2
				{
					if(c >= 48 && c <= 57)//thi co the nhap cac so tu 0 - 9
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				
				if(f == 51)
				{
					if(c == 48 || c == 49)//chi duoc nhap so 0
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
					}
					else if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
					else//ky tu dau la cac so khac
					{
						if(int(c)==8 && i > 0)
						{
							cout<<"\b \b";i--;xi--;
						}
						if(i==0)
						{
							S[i]=NULL;
						}
					}
			}//i > 0 && i < n
		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i >= 1)break;

	}
	S[i]='\0';
	return S;
	}///////////////END 31 NGAY
}

char *NhapThangKhoiHanhCuaChuyenBay(int n,int xi,int yi)
{
	int pix = xi;
	gotoxy(xi,yi);
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < n || S[0] == NULL)
	{
	if(i == 0)//SO DAU TIEN
		{
			if(c >= 49 && c <= 57)
			{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
				{
					S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
				}
			}	
			
		}/////SO DAU TIEN
	
		//////SO THU 2
		else if(i > 0 && i < n)//i = 1
			{
				char f = int(S[0]);
				if(f == 49)//ky tu dau tien la 1
				{
					if(c >= 48 && c <= 50)//cac so 0 - 1 - 2
					{
						if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
							{
								S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
							}
					}
					if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}
				else
				{
					if(int(c)==8 && i > 0)
					{
						cout<<"\b \b";i--;xi--;
					}
					if(i==0)
					{
						S[i]=NULL;
					}
				}/////end check == 1
			}


			else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
			if(i==0)
			{
				S[i]=NULL;
			}
			
			/////TAI DAY DE TRA VE NUT ESC//////
			if(int(c)==27 && c!=13)
			{
				ESC[0] = 'e';
				return ESC;
			}//////////////////////////////////
			if(int(c) == 13 && i >= 1)break;
	}
	S[i]='\0';
	return S;
}

char *NhapNamKhoiHanhCuaChuyenBay(int n,int xi,int yi)//chi cho nhap 2018
{
	int pix = xi;
	gotoxy(xi,yi);//30-16
	int check = 1;
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < 4 || S[0] == NULL)
	{
		if(i == 0)//SO DAU TIEN
			{
				if(c == 50)//neu ky tu dau tien la so 0
				{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
					check = 0;
				}
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
		
				/////TAI DAY DE TRA VE NUT ESC//////
				if(int(c)==27 && c!=13)
				{
					ESC[0] = 'e';
					return ESC;
				}//////////////////////////////////	


			}//chi duoc nhap so 2
			if(i == 1)//SO THU 2
			{
				if(c == 48)//neu ky tu dau tien la so 0
					{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
						check = 0;
					}
					
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
			if(i==0)
				{
					S[i]=NULL;
				}
		
				/////TAI DAY DE TRA VE NUT ESC//////
				if(int(c)==27 && c!=13)
				{
					ESC[0] = 'e';
					return ESC;
				}//////////////////////////////////
			}//chi duoc nhap so 0
			
			
			if(i == 2)//SO THU 3
			{
				if(c == 49)//neu ky tu dau tien la so 0
					{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
						check = 0;
					}
					
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
		
				/////TAI DAY DE TRA VE NUT ESC//////
				if(int(c)==27 && c!=13)
				{
				ESC[0] = 'e';
				return ESC;
			}//////////////////////////////////
			}//chi duoc nhap so 1
			
			
			if(i == 3)//SO THU 4
			{
				if(c == 56)//neu ky tu dau tien la so 0
					{
					if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
						{
							S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
						}
						check = 0;
					}
					
					
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
		
				/////TAI DAY DE TRA VE NUT ESC//////
				if(int(c)==27 && c!=13)
				{
					ESC[0] = 'e';
					return ESC;
				}//////////////////////////////////
			}//chi duoc nhap so 8

		else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
		if(i==0)
		{
			S[i]=NULL;
		}
		
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n)break;
	}
	S[i]='\0';
	return S;
}

char *NhapGioKhoiHanhCuaChuyenBay(int n,int xi,int yi)//HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < n || S[0] == NULL)
	{
		int xy;
		if(i == 0)//SO DAU TIEN
		{
			if(c >= 48 && c <= 57)
			{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
			}

		}/////SO DAU TIEN
		
		else if(i > 0 && i < n)
		{
			char f = int(S[0]);//kiem tra ky tu dau tien
			if(f == 49)//ky tu dau tien la so 1
			{
				if(c >= 48 && c <= 57)//cac so tu 0 - 9
				{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
				}
				
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
			}
			else if(f == 50)//ky tu dau tien la so 2
			{
				if(c >= 48 && c <= 52)//cac so tu 0 - 4
				{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
					{
						S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
					}
				}
				
				else if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
			}
			else
			{//cac so khac 1, 2
				if(int(c)==8 && i > 0)
				{
					cout<<"\b \b";i--;xi--;
				}
				if(i==0)
				{
					S[i]=NULL;
				}
			}
		}
			
		else if(int(c)==8 && i > 0)
			{
				cout<<"\b \b";i--;xi--;
			}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && (i > 0 && i <= n))break;
	}
	S[i]='\0';
	return S;
}

char *NhapSanBayDenCuaChuyenBay(int n,int xi,int yi)//HOAN CHINH
{
	int pix = xi;
	gotoxy(xi,yi);
	char c;
	char *ESC = new char{NULL};//de nhan nut ESC khi dang nhap lieu
	char *S = new char{NULL};
	int i=0;
	while((c=getch())!=13 || i < n || S[0] == NULL)
	{
		if(i < n)
		{
			if(c >= 49 && c <=53)//1-5 do co 5 san bay den
			{
				if(c!=75 && c!=77 && c!=80 && c!=72 && int(c)!=8)
				{
					S[i]=c;cout<<c;i++;xi++;//de dua con tro di toi 1 don vi chieu ngang
				}
			}
		}
		
		else if(int(c)==8 && i > 0)
		{
			cout<<"\b \b";i--;xi--;
		}
		if(i==0)
		{
			S[i]=NULL;
		}
		/////TAI DAY DE TRA VE NUT ESC//////
		if(int(c)==27 && c!=13)
		{
			ESC[0] = 'e';
			return ESC;
		}//////////////////////////////////
		
		if(int(c) == 13 && i == n)break;
	}
	S[i]='\0';
	return S;
}
/*---------------Nhap Thong Tin Dat Ve----------------*/
