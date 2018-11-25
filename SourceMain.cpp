#include <iostream>//chua cac ham nhap xuat cout cin
#include <math.h>//chua cac ham toan hoc nhu sqrt,abs,pow..
#include <conio.h>//chua cac ham clrscr,getch,..
#include <iomanip>//chua ham setw
#include <cstring>
#include <string>//chua ham c_str()
#include <string.h>//chua cac ham xu ly chuoi (strlen , strcmp , strlwr ... khong su dung duoc voi string )
#include <stdlib.h>//chua ham system("pause"), neu code bang visual thi them thu vien nay vao
#include <unistd.h>//chua ham sleep(n) dung de tao 1 khoang tg ngu cho chuong trinh n giay
#include <windows.h>//chua ham cls de clear man hinh
#include <ctime>//tra ve thoi gian hien tai tren he thong
#include <fstream>
#include <pthread.h>//DA LUONG
//#include mylibrary
#include "dohoa.h"
#include "mylib.h"

#include "khaibao.h"
#include "hashtime.h"//neu xay ra loi thi dua hashtime.h len phia tren khaibao.h
#include "raw.h"
#include "support.h"

//include them - neu loi thi xoa
#include <stdio.h>
#include <dos.h>
#include <sstream>

///////them thu graphics
#include <winbgim.h>


using namespace std;


void Swap(int &x , int &y){
	int temp = x;
	x = y;
	y = temp;
}

////KHONG SU DUNG NHUNG KHONG DUOC XOA HAM NAY////
int ChuyenChuoiKyTuThanhSo(char *s){
	int res = 0;
	for(int i = 0; i < strlen(s) ; i++)
	{
		res = res*10 + (s[i]-'0');
	}
	return res;
}

int CheckNamNhuan(int year){
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	return 1;
	else return 0;
}

int CheckGioKhoiHanh(int gioDi){
	if(gioDi < 0 && gioDi > 24 )
	return 0;
}


int ChuyenTime(char *s){
	int res = 0;
	for(int i = 11; i < strlen(s)- 5; i++ )
	{
		if(s[i] >= 48 && s[i] <= 57)
		{
			res = res*10 + (s[i]-'0');
		}
	}
	return res;
}


/*---------HIGHTLIGHT-NORMAL--------*/
void NormalMain (){
	SetColor(15);
	SetBGColor(8);
}
void HighLightMain (){
	SetColor(15);
	SetBGColor(3);
}
////////////////
void NormalMB (){
	SetColor(0);
	SetBGColor(9);
}
void HighLightMB (){
	SetColor(3);
	SetBGColor(7);
}
/////////////////
void NormalCB (){
	SetColor(0);
	SetBGColor(9);
}
void HighLightCB (){
	SetColor(3);
	SetBGColor(7);
}
//////////////////
void NormalManagerMB (){
	SetColor(15);
	SetBGColor(8);
}
void HighLightManagerMB (){
	SetColor(15);
	SetBGColor(3);
}
///////////////////////
void NormalManagerCB (){
	SetColor(15);
	SetBGColor(8);
}
void HighLightManagerCB (){
	SetColor(15);
	SetBGColor(3);
}
///////////////////////
void NormalOther(){
	SetColor(0);
	SetBGColor(7);
}
void HighLightOther(){
	SetColor(15);
	SetBGColor(5);
}
////////////////////
void NormalChoice (){
	SetColor(12);
	SetBGColor(8);
}
void HighLightChoice (){
	SetColor(15);
	SetBGColor(3);
}
/*-------HIGHTLIGHT-NORMAL--------*/


/*----------------------MENU MAIN-----------------------*/
const int so_item_main = 4;
const int dong_main =5;
const int cot_main = 13;
const int Up = 72;
const int Down = 80;
char thucdon [so_item_main][50] = {    "    QUAN LY MAY BAY       ",
			                  		   "    QUAN LY CHUYEN BAY    ",
			                  		   "    DAT VE CHUYEN BAY     ",
			                           "    MONITORING            "};

int MenuMain(char td [so_item_main][50])
{
  NormalMain();
  int chon = 0;
  int i;
  for ( i=0; i< so_item_main ; i++)
  { gotoxy(cot_main, dong_main +i);
    cout << td[i];
  }
  HighLightMain();
  gotoxy(cot_main,dong_main+chon);
  cout << td[chon];
  char kytu;
  
do
{
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        NormalMain();
              	gotoxy(cot_main,dong_main+chon);
              	cout << td[chon];
              	chon --;
              	HighLightMain();
              	gotoxy(cot_main,dong_main+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_main)
  			  {
  		        NormalMain();
              	gotoxy(cot_main,dong_main+chon);
              	cout << td[chon];
              	chon ++;
              	HighLightMain();
              	gotoxy(cot_main,dong_main+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 9: return 9;//TAB
  	case 27: return 27;//ESC
  	case 32: return 32;//SPACE
  	
  }// end switch
} while (1);
}
/*----------------------MENU MAIN-----------------------*/



/*----------------------MENU MANAGER MAY BAY-----------------------*/
const int so_item_managerMB = 5;
const int dong_managerMB =5;
const int cot_managerMB = 42;
const int UpMB = 72;
const int DownMB = 80;
char MenuManagerMB [so_item_managerMB][50] = {" TAO MAY BAY MOI                    ",
			                  		   		  " XOA MAY BAY                        ",
			                                  " HIEU CHINH MAY BAY                 ",
			                                  " SHOW DANH SACH MAY BAY             ",
			                                  " THONG KE LUOT THUC HIEN CHUYEN BAY "};

int MenuDongManagerMB(char td [so_item_managerMB][50])
{
  NormalManagerMB();
  int chon = 0;
  int i;
  for ( i=0; i< so_item_managerMB ; i++)
  { gotoxy(cot_managerMB, dong_managerMB +i);
    cout << td[i];
  }
  HighLightManagerMB();
  gotoxy(cot_managerMB,dong_managerMB+chon);
  cout << td[chon];
  char kytu;
  
do
{
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case UpMB :if (chon+1 >1)
  			  {
  		        NormalManagerMB();
              	gotoxy(cot_managerMB,dong_managerMB+chon);
              	cout << td[chon];
              	chon --;
              	HighLightManagerMB();
              	gotoxy(cot_managerMB,dong_managerMB+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case DownMB :if (chon+1 <so_item_managerMB)
  			  {
  		        NormalManagerMB();
              	gotoxy(cot_managerMB,dong_managerMB+chon);
              	cout << td[chon];
              	chon ++;
              	HighLightManagerMB();
              	gotoxy(cot_managerMB,dong_managerMB+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 9: return 9;//TAB
  	case 27: return 27;//ESC
  	
  }// end switch
} while (1);
}

/*----------------------MENU MANAGER MAY BAY-----------------------*/



/*----------------------MENU MANAGER CHUYEN BAY-----------------------*/
const int so_item_managerCB = 9;
const int dong_managerCB =5;
const int cot_managerCB = 42;
const int UpCB = 72;
const int DownCB = 80;
char MenuManagerCB [so_item_managerCB][50] = {" KHOI TAO CHUYEN BAY                         ",
			                  		   		  " HIEU CHINH CHUYEN BAY                       ",
			                                  " HUY CHUYEN BAY                              ",
			                                  " LUU DANH SACH CHUYEN BAY                    ",
			                                  " DANH SACH CHUYEN BAY                        ",
			                                  " DANH SACH VE CUA 1 CHUYEN BAY               ",
			                                  " DANH SACH VE TRONG CUA 1 CHUYEN BAY         ",
			                                  " DANH SACH HANH KHACH CUA 1 CHUYEN BAY       ",
			                                  " LIST CHUYEN BAY KHOI HANH (dd/mm/yyy)CON VE "};

int MenuDongManagerCB(char td [so_item_managerCB][50])
{
  NormalManagerCB();
  int chon = 0;
  int i;
  for ( i=0; i< so_item_managerCB ; i++)
  { gotoxy(cot_managerCB, dong_managerCB +i);
    cout << td[i];
  }
  HighLightManagerCB();
  gotoxy(cot_managerCB,dong_managerCB+chon);
  cout << td[chon];
  char kytu;
  
do
{
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case UpCB :if (chon+1 >1)
  			  {
  		        NormalManagerMB();
              	gotoxy(cot_managerCB,dong_managerCB+chon);
              	cout << td[chon];
              	chon --;
              	HighLightManagerCB();
              	gotoxy(cot_managerCB,dong_managerCB+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case DownCB :if (chon+1 <so_item_managerCB)
  			  {
  		        NormalManagerCB();
              	gotoxy(cot_managerCB,dong_managerCB+chon);
              	cout << td[chon];
              	chon ++;
              	HighLightManagerCB();
              	gotoxy(cot_managerCB,dong_managerCB+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case 13 : return chon+1;
  	case 9: return 9;//TAB
  	case 27: return 27;//ESC
  	
  }// end switch
} while (1);
}
/*----------------------MENU MANAGER CHUYEN BAY-----------------------*/



/*----------------------MENU MANAGER OTHER-----------------------*/
const int so_item_other = 2;
const int dong_other =5;
const int cot_other = 42;
const int UpOther = 72;
const int DownOther = 80;
char MenuOther [so_item_other][50] = {"    DANH SACH HANH KHACH     ",
									  "       TRALVER BUCKET        "};

int MenuDongOther(char td [so_item_other][50])
{
	NormalOther();
	int chon = 0;
	int i;
	for ( i=0; i< so_item_other ; i++)
  	{
		gotoxy(cot_other, dong_other +i);
    	cout << td[i];
  	}
  	HighLightOther();
  	gotoxy(cot_other,dong_other+chon);
  	cout << td[chon];
  	char kytu;
	do
	{
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu)
  		{
    		case UpOther :if (chon+1 >1)
  			{
				NormalOther();
				gotoxy(cot_other,dong_other+chon);
				cout << td[chon];
				chon --;
				HighLightOther();
				gotoxy(cot_other,dong_other+chon);
				cout << td[chon];
			}
  			  break;
  			case DownOther :if (chon+1 <so_item_other)
  			{
  		        NormalOther();
              	gotoxy(cot_other,dong_other+chon);
              	cout << td[chon];
              	chon ++;
              	HighLightOther();
              	gotoxy(cot_other,dong_other+chon);
              	cout << td[chon];
  			  }
  			  break;
  			case 13 : return chon+1;
  			case 9: return 9;//TAB
  			case 27: return 27;//ESC
  		}// end switch
	}while(1);
}
/*----------------------MENU MANAGER OTHER-----------------------*/




/*------------CHOICE YES NO--------------*/
const int so_item_choice = 2;//YES-NO
const int dong_choice =36;
const int cot_choice = 92;
const int UpChoice = 72;
const int DownChoice = 80;
char MenuChoice [so_item_choice][50] = {" YES ",
			                        	" NO  "};

int MenuSelectChoice(char td [so_item_choice][50])
{
	  NormalChoice();
  int chon = 0;
  int i;
  for ( i=0; i< so_item_choice ; i++)
  { gotoxy(cot_choice, dong_choice +i);
    cout << td[i];
  }
  HighLightChoice();
  gotoxy(cot_choice,dong_choice+chon);
  cout << td[chon];
  char kytu;
  
do
{
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu)
  {
    case UpChoice :if (chon+1 >1)
  			  {
  		        NormalChoice();
              	gotoxy(cot_choice,dong_choice+chon);
              	cout << td[chon];
              	chon --;
              	HighLightChoice();
              	gotoxy(cot_choice,dong_choice+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case DownChoice :if (chon+1 <so_item_choice)
  			  {
  		        NormalChoice();
              	gotoxy(cot_choice,dong_choice+chon);
              	cout << td[chon];
              	chon ++;
              	HighLightChoice();
              	gotoxy(cot_choice,dong_choice+chon);
              	cout << td[chon];
  			  }
  			  break;
  	case 13 : return chon;
  	}// end switch
	} while (1);
}

int choice_YesNo()
{
	int choice = 0;
	choice = MenuSelectChoice(MenuChoice);
	return choice;
}
/*------------CHOICE YES NO--------------*/


/*-------------------PHAN TRANG DSHK CUA CHUYEN BAY-------------------*/
const int so_item_paging = 2;//Left - Right
const int LeftShow = 75;//xuong
const int RightShow =77;//len

int MenuPaging()
{
  char kytu;
	do
	{
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu)
  		{

  			case RightShow :
  			  {
              	return 1;
  			  }
  			  break;
  			  
  			  case LeftShow:
			 {
  			  return -1;
			 }
  			  break;
  			  case 27:
			  {
				return 27;
			  }
			  break;
  			  
  		}// end switch
	}while(1);
}

int choice_paging()
{
	int choice = 0;
	choice = MenuPaging();
	return choice;
}
/*-------------------PHAN TRANG DSHK CUA CHUYEN BAY-------------------*/







/*------------SLIDE DSMB-------------*/
const int dong_mb = 8;
const int cot_mb = 119;
//char *listMB(0);//giong thuc don
//vi hien tai khi khai bao con tro dang chua gia tri khong xac dinh, co the chua cac du lieu quan trong
//nen khong duoc khai bao con tro ma khong khoi tao cho no 1 gia tri , de dam bao nhat moi khi khai bao 1 con tro thi khoi tao gia tri =0
//thuc te khong co dia chi 0 nao ton tai , khai bao vay chi co nghia la con tro chua he chua dia chi o nho nao ca
int MenuDongDSMB(char td [], int so_mb)
{
	NormalMB();
	int chon = 0;
	int i;
	for ( i = 0; i < so_mb*2 ; i++)
	{
		gotoxy(cot_mb, dong_mb +i);
		cout << td[i];
	}
	HighLightMB();
	gotoxy(cot_mb,dong_mb+chon);
	cout << td[chon];
	char kytu;

	do
	{
		kytu = getch();
		if (kytu==0) kytu = getch();
		switch (kytu)
		{
			case Up :if (chon > 0)
  			{
  			  	NormalMB();
              	gotoxy(cot_mb,dong_mb+chon*2);
              	cout << td[chon];
              	chon --;
              	HighLightMB();
              	gotoxy(cot_mb,dong_mb+chon*2);
              	cout << td[chon];
  			}
  			break;
  			case Down :if (chon < so_mb-1)
  			{
  		        NormalMB();
              	gotoxy(cot_mb,dong_mb+chon*2);
              	cout << td[chon];
              	chon ++;
              	HighLightMB();
              	gotoxy(cot_mb,dong_mb+ chon*2);
              	i = dong_mb + chon*2;
              	cout << td[chon];
  			}
  			  break;
  			case 13 : return chon;
  			case 27: return 27;//ESC
  	
  		}// end switch
	} while (1);
}
/*------------SLIDE DSMB-------------*/


/*------------SLIDE DSCB-------------*/
const int dong_cb = 8;
const int cot_cb = 119;

int MenuDongDSCB(char td [] , int so_cb)
{
	NormalCB();
  	int chon = 0;
  	int i;
  	for ( i=0; i < so_cb*2 ; i++)
  	{ 
  		gotoxy(cot_cb, dong_cb +i);
    	cout << td[i];
  	}
  	HighLightCB();
  	gotoxy(cot_cb,dong_cb+chon);
  	cout << td[chon];
  	char kytu;
  
	do
	{
  		kytu = getch();
  		if (kytu==0) kytu = getch();
  		switch (kytu)
  		{
    		case Up :if (chon > 0)
  			{
  			  	NormalCB();
              	gotoxy(cot_cb,dong_cb+chon*2);
              	cout << td[chon];
              	chon --;
              	HighLightCB();
              	gotoxy(cot_cb,dong_cb+chon*2);
              	cout << td[chon];
  			}
  			break;
  			case Down :if (chon < so_cb-1)
  			{
  		        NormalCB();
              	gotoxy(cot_cb,dong_cb+chon*2);
              	cout << td[chon];
              	chon ++;
              	HighLightCB();
              	gotoxy(cot_cb,dong_cb+ chon*2);
              	i = dong_cb+ chon*2;
              	cout << td[chon];
  			}
  			break;
  			case 13 : return chon;
  			case 27: return 27;//ESC
  		}// end switch
	} while (1);
}
/*------------SLIDE DSMB-------------*/




/*-----------Update MayBay va HuyChuyenBay goi no-----------*/
//int check_FullVeConTrong(CHUYENBAY cb)
//{
//	int fullvetrong = 1;//ban dau mac dinh la full ve trong
//	for(int i = 0; i < cb.soluongVe ; i++ )
//	{
//		if(cb.nodeVe[i] != "0")
//		fullvetrong = 0;//neu co mot cai ve nao ma gia tri khac 0 (dang chua so CMND) thi khong full ve trong
//	}
//	return fullvetrong;
//}



/*------------------------------------------SAVE--------------------------------------*/
/*-----------------Save MayBay------------------*/
void Save_1MB(ofstream &fileout, MAYBAY mb, int dex)// ham ghi du lieu 1 may bay vao file
{
	if(dex == 1)//may bay dau tien duoc ghi vao file
	{
		fileout << mb.sohieuMB << ",";
		fileout << mb.loaiMB << ",";
		fileout << mb.sochoMB <<",";
		fileout << mb.x;
	}
	else
	{
		fileout << endl;
		fileout << mb.sohieuMB << ",";
		fileout << mb.loaiMB << ",";
		fileout << mb.sochoMB <<",";
		fileout << mb.x;
	}
}


void Save_DSMB( DSMAYBAY listmb)//ham ghi DSMB vao file
{
	ofstream fileout;
	fileout.open("DSMB.txt", ios::out);
	int dex = 1;
	for(int i = 0 ; i < listmb.soMB ; i++)
	{
		Save_1MB(fileout, listmb.nodeMB[i],dex);dex++;
	}
	fileout.close();
}
/*-----------------Save MayBay------------------*/


/*------------SAVE CHUYEN BAY--------------*/
void Save_1CB(ofstream &fileout,CHUYENBAY cb)
{
	int timeData;
	for(int i = 0 ; i < z ; i++)
	{
		if(strcmp(MSCB_Depart[i] , cb.MSCB) == 0)
		{
			timeData = Time_CB_Depart[i];
			break;
		}
	}
	fileout << timeData<< ",";
	fileout << cb.MSCB << ",";
	fileout << cb.staTus<<",";
	fileout << cb.ngayDi << "," <<cb.thangDi << "," <<cb.namDi << ",";
	fileout << cb.gioDi << ",";
	fileout << cb.sanBay << ",";
	fileout << cb.sohieumb << ",";
	fileout << cb.soluongVe << ",";
	fileout << cb.soveduocdat <<",";
	
	/*-----------SAVE DS VE-------------*/
	for(int i = 0; i < cb.soluongVe ; i++)
	{
		if(cb.nodeVe[i] != "0")
		{
			fileout << i << "-" <<cb.nodeVe[i];
		}
		else if(cb.nodeVe[i] == "0")
		{
			fileout << i << "-";
		}
		if(i != cb.soluongVe-1)
		{
			fileout << ",";
		}
		else if(i == cb.soluongVe-1)
		{
			fileout << "|";
		}
	}
	/*-----------SAVE DS VE-------------*/
}

void Save_DSCB(DSCHUYENBAY listcb)
{
	ofstream fileout;
	fileout.open("DSCB.txt",ios::out);//app ghi them - out xoa het them moi
	for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
	{
		Save_1CB(fileout,p->data);
		if(p->pNext != NULL)
		{
			fileout << endl;
		}
	}
}
/*------------SAVE CHUYEN BAY--------------*/


bool check_FullVeConTrong(CHUYENBAY cb)
{
	bool check = true;
	for(int i = 0; i < cb.soluongVe ; i++ )
	{
		if(cb.nodeVe[i] != "0")
		{
			check = false;
			break;
		}
	}
	return check;
}
/*-----------Update MayBay va HuyChuyenBay goi no-----------*/



/*----------------------------------THAO TAC MAY BAY----------------------------------*/
int isEmptyMB(DSMAYBAY listmb)
{
	if(listmb.soMB == 0 )
	{
		return 1;
	}
	return 0;
}

int isFullMB(DSMAYBAY listmb)
{
	if(listmb.soMB == MAXMAYBAY)
	{
		return 1;
	}
	return 0;
}



/*-----------------Read MayBay------------------*/
// ham doc du lieu 1 may bay tu file
void Read_1MB(ifstream &filein, MAYBAY &mb)
{
	filein.getline(mb.sohieuMB, MAXSOHIEU, ',');
	filein.getline(mb.loaiMB, TYPEMB, ',');
	filein >> mb.sochoMB;
	mb.x = 1;//mac dinh khi doc vao la san sang
	// tao bien tam de doc cac ky tu xuong dong o cuoi dong //
	string temp;
	getline(filein, temp);
}


// ham doc danh sach may bay vao file - Luu y phai co it nhat 1 may bay trong file truoc
void Read_DSMB(ifstream &filein, DSMAYBAY &listmb){
	// doc den cuoi file thi dung
	while (!filein.eof())
{
		/*---Doc thong tin may bay---*/
		MAYBAY mb;
		Read_1MB(filein, mb);
		int check = 1;
		for(int i = 0; i < listmb.soMB ; i++ ){
			if(strcmp(mb.sohieuMB, listmb.nodeMB[i].sohieuMB) == 0)
			{
				check = 0;
			}
		}
		if(check == 1)
		{
			listmb.nodeMB[listmb.soMB] = mb;
			listmb.soMB++;
		}
	}
	filein.close();
}
/*-----------------Read MayBay------------------*/




void addMB(DSMAYBAY &listmb)
{
	while(getch()!=27)
	{
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if(isFullMB(listmb) == 1)
		{
			BoxMessage("      DANH SACH MAY BAY DAY - KHONG THEM DUOC");
			return;//bi FULL
		}
		else //chua Full
		{
			ScreenApp();
			BoxAddMayBay();
			int px = 127,py = 8;
			
			/*----------SHOW DS MAY BAY---------*/
			for(int i = 0 ; i < listmb.soMB ; i++)
			{
				gotoxy(123,py);
				cout<<listmb.nodeMB[i].sohieuMB<<"["<<listmb.nodeMB[i].x<<"]";
				py++;
				gotoxy(123,py);
				cout<<"------------------"<<endl;
				py++;
			}
			/*----------SHOW DS MAY BAY---------*/
			
			gotoxy(41,16);cout<<"                ";
			gotoxy(41,18);cout<<"                ";
			gotoxy(41,20);cout<<"                ";
		
			MAYBAY mb;
			NhapThongTinMayBay(mb , 41 , 16);
			if(mb.sohieuMB[0] == 'E')
			{
				BoxMessage("           HUY KHOI TAO MAY BAY");return;
			}
		
			if(listmb.soMB == 0)//neu chua co mb nao thi them ngay vao DSMB
			{
				mb.x = 1;//may bay duoc khoi tao luon o trang thai 1 - co the update hoac xoa
				listmb.nodeMB[listmb.soMB] = mb;
				listmb.soMB++;
			
				/*Confirm Save maybay*/
				BoxConfirmSaveFile();
				int choice = choice_YesNo();
				if(choice == 0)
				{
					int i = listmb.soMB-1;//de gan chi so vitri dua may bay vao
					ofstream fileout;
					fileout.open("DSMB.txt", ios::app);
					Save_1MB(fileout, listmb.nodeMB[i],listmb.soMB);
					fileout.close();
				}
				/*-------------------*/
				
				SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
				gotoxy(63,35);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(63,36);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(63,37);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(52,45);cout<<"                         ";//khoang trang de de len message	
				BoxMessage("          TAO MAY BAY THANH CONG");
				//return;
			}
			
			else//da co may bay trong danh sach
			{
				for(int i = 0 ; i < listmb.soMB ; i++)
				{
					int check = 0;
					if(strcmp(mb.sohieuMB, listmb.nodeMB[i].sohieuMB) == 0)
					{
						SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
						BoxMessage("         TRUNG SO HIEU - NHAP LAI");
						
						do
						{
							int choice = choice_YesNo();
							
							if (choice == 1)
							{
								BoxMessage("           HUY KHOI TAO MAY BAY");return;
							}
							else if(choice == 0)
							{
								SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
								gotoxy(92,36);cout<<"     ";//khoang trang de de len choice
								gotoxy(92,37);cout<<"     ";//khoang trang de de len choice
								gotoxy(52,45);cout<<"                         ";//khoang trang de de len message
								
								int x = 0;//khong bi trung khi nhap lai
							
								fflush(stdin);
								gotoxy(41,16);cout<<"                        ";//SHMB
								gotoxy(41,18);cout<<"                        ";//TYPEMB
								gotoxy(41,20);cout<<"                        ";//SO CHO NGOI
								
								NhapThongTinMayBay(mb , 41, 16);
								for(int i = 0 ; i < listmb.soMB ; i++)
								{
									if(strcmp(listmb.nodeMB[i].sohieuMB , mb.sohieuMB) == 0)
									{
										gotoxy(93,45);cout<<"                                   ";
										SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
										BoxMessage("         TRUNG SO HIEU - NHAP LAI");
										x = 1;//bi trung khi nhap lai - check van dang bang 0
									}
								}
								if(x == 0)//khong bi trung khi nhap lai
								{
									check = 1;
								}
							}
						}while(check != 1);
					}
				}
				
				/*------NEU KHONG TRUNG LAP THI THIET LAP CHO MAY BAY MOI------*/
				mb.x = 1;//may bay duoc khoi tao luon o trang thai 1 - co the update hoac xoa
				listmb.nodeMB[listmb.soMB] = mb;
				listmb.soMB++;//tang so phan tu cua DSMB (DSTT)
				
				/*--Confirm Save maybay--*/
				BoxConfirmSaveFile();
				int choice = choice_YesNo();
				if(choice == 0)
				{
					int i = listmb.soMB-1;
					ofstream fileout;
					fileout.open("DSMB.txt", ios::app);
					Save_1MB(fileout, listmb.nodeMB[i],listmb.soMB);
					fileout.close();
				}
				/*-----------------------*/
				
				BoxMessage("          TAO MAY BAY THANH CONG");
				SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
				gotoxy(63,35);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(63,36);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(63,37);cout<<"                                  ";//khoang trang de de len choice
				gotoxy(42,45);cout<<"                                                ";//khoang trang de de len message
			}
		}
	}//while
}


void deleteMB(DSMAYBAY &listmb , DSCHUYENBAY &listcb)
{
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(listmb.soMB == 0)
	{
		ScreenApp();
		BoxMessage("CHUA CO MAY BAY NAO TRONG DANH SACH");
		return;
	}
	else//danh sach khong bi rong
	{
		SetConsoleTextAttribute(consoleHandle, (12 << 4) | 0);	
		gotoxy(87,15);
		cout<<"          "<<endl;
		gotoxy(87,16);
		cout<<"    ESC   "<<endl;
		gotoxy(87,17);
		cout<<"          "<<endl;
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);	
		gotoxy(87,18);
		cout<<"    Huy   "<<endl;
		
		
		int index;
		ScreenApp();
		/////SHOW CAC MAY BAY CO TRONG DANH SACH//
		BoxShowDSMB();
		int px = 121,py = 8;
		for(int i = 0 ; i < listmb.soMB ; i++)
		{
			gotoxy(px+1,py);
			cout<<listmb.nodeMB[i].sohieuMB<<"["<<listmb.nodeMB[i].x<<"]";
			py++;
			gotoxy(px,py);
			cout<<"--------------------"<<endl;
			py++;
		}

		int check = 0;
		Navbar7();
		fflush(stdin);//Nhap SHMB can xoa
		char *SHMB_xoa = NhapSoHieuMayBay(MAXSOHIEU-1,62,16);
		if(SHMB_xoa[0] == 'e')
		{
			delete SHMB_xoa;
			return;//da nhan phim ESC
		}
		
		
		for(int i=0; i < listmb.soMB ; i++)
		{
			if(strcmp(listmb.nodeMB[i].sohieuMB, SHMB_xoa) == 0)
			{
				check = 1;
				if(listmb.nodeMB[i].x == 1)//nghia la trang thai co the xoa
				{
					index = i;
					for (int j = index; j < listmb.soMB-1; j++)
					{
						listmb.nodeMB[j] = listmb.nodeMB[j+1];
					}
						listmb.soMB--;
						delete SHMB_xoa;
						
						/*Confirm Save maybay*/
						BoxConfirmSaveFile();
						int choice = choice_YesNo();
						if(choice == 0)
						{
							Save_DSMB(listmb);//luu thay doi vao File
						}
						/*-------------------*/
						BoxMessage("            XOA MAY BAY THANH CONG");
						return;
				}
				else if(listmb.nodeMB[i].x == 0)
				{
					delete SHMB_xoa;
					BoxMessage("KHONG XOA DUOC DO DANG THUC HIEN CHUYEN BAY");
					return;//khong xoa duoc do dang hoat dong
				}
			}
		}
		
		if(check == 0)//nghia la da so sanh den cuoi mang nhung van chua tim duoc trung khop
		{
			BoxMessage("           NHAP SHMB KHONG CHINH XAC");
			return;	
		}
	}
}


/*---HOAT DONG THEO KIEU NUT CHON TRONG SHOW DSMB DE NGUOI QUAN LY KHONG PHAI NHAP NHAM SHMB---*/
void updateMB(DSMAYBAY &listmb,DSCHUYENBAY &listcb)//do co the co su thay doi ve ds ve cua chuyen bay nen them listcb
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	ScreenApp();
	if(listmb.soMB == 0)
	{
		BoxMessage("CHUA CO MAY BAY TRONG DANH SACH DE UPDATE");
		return;
	}
	
	else//DA CO MAY BAY TRONG DANH SACH//
	{
		ScreenApp();
		
		///SHOW DANH SACH MAY BAY///
		BoxShowDSMB();
		int px = 121,py = 8;
		for(int i = 0 ; i < listmb.soMB ; i++)
		{
			gotoxy(px+1,py);
			cout<<listmb.nodeMB[i].sohieuMB<<"["<<listmb.nodeMB[i].x<<"]";
			py++;
			gotoxy(px,py);
			cout<<"---------------------"<<endl;
			py++;
		}
		////////////////////////////////////
		
		//TAO SPLIT CHO DANH SACH MAY BAY//
		char *listMB(0);//giong thuc don
		int so_mb = listmb.soMB;
		listMB = new char[listmb.soMB*2];
		int chon;
		ScreenApp();
		//tao thanh doc de lua chon may bay
		for(int i = 0 ; i < listmb.soMB*2 ; i++)
		{
			listMB[i] = char(176);
		}
					
		while(chon != 27)
		{
			chon = MenuDongDSMB(listMB , so_mb);
			if(chon == 27)
			{
				break;
			}
			XoaManHinh();
			ScreenApp();
			BoxShow1MB(listmb.nodeMB[chon]);//nhan enter ta get duoc "chon"
			///DA CO DUOC "chon" -> THUC HIEN UPDATE
			for (int i = 0; i < listmb.soMB; i++)
			{
				if(i == chon)//tim duoc so hieu MB trong DSMB tuong ung voi pick chon
				{
					//truong hop duoc day co the nhap lai duoc SHMB cu - nhung phai khac voi cac SHMB con lai
					BoxImpementUpdateMayBay();
					fflush(stdin);
					MAYBAY mb;
					NhapThongTinMayBay(mb , 60, 17);
					if(mb.sohieuMB[0] == 'E')
					{
						BoxMessage("           HUY UPDATE MAY BAY");return;
					}
					mb.x = 1;//mac dinh khi update may bay thi de trang thai san sang
				
					for(int j=0 ; j < listmb.soMB ; j++)
					{
						if(j != i)
						{
							if(strcmp(listmb.nodeMB[j].sohieuMB , mb.sohieuMB) == 0)
							{
								BoxMessage("           SHMB KHONG DUOC TRUNG NHAU");
								return;
							}
						}
					}//da duyet het DS va khong bi trung SHMB
				
					if(listmb.nodeMB[i].x == 1)//chua co chuyen bay nao chon va ta chi cap nhap rieng MB
					{
						//can update lai nhung chuyen bay da hoan tat hoac huy chuyen nhung van con vuong lai SHMB cu
						for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
						{
							if(strcmp(p->data.sohieumb,listmb.nodeMB[i].sohieuMB) == 0)
							{
								strcpy(p->data.sohieumb,mb.sohieuMB);
							}
						}
						
						/*--Update lai MB--*/
						listmb.nodeMB[i] = mb;
						
						/*Confirm Save maybay*/
						Save_DSMB(listmb);//luu thay doi vao File
						Save_DSCB(listcb);
						/*-------------------*/
						BoxMessage("  UPDATE MAY BAY THANH CONG - LUU THAY DOI");
						return;
					}
					
					else if(listmb.nodeMB[i].x == 0)//nghia la da co chuyen bay chon no
					{
						for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
						{
							if(strcmp(p->data.sohieumb,listmb.nodeMB[chon].sohieuMB) == 0 && p->data.staTus == 1)
							{
								bool check = check_FullVeConTrong(p->data);
								if(check == true)//neu nhu chuyen bay co may bay nay chua co ai dat ve thi moi update mau bay duoc
								{
									///CHO MAY BAY
									listmb.nodeMB[i] = mb;
									//CHO CHUYEN BAY
									strcpy(p->data.sohieumb, mb.sohieuMB);
									p->data.soluongVe = mb.sochoMB;
									p->data.nodeVe = NULL;//de gan lai so luong ve moi
									p->data.nodeVe = new string[mb.sochoMB];//thiet lap lai so luong ve
									for(int i = 0; i < p->data.soluongVe ; i++)
									{
										p->data.nodeVe[i] = "0";//thiet lap full ve trong
									}
								}
				
								else if(check == false)
								{
									BoxMessage("KHONG UPDATE - DA CO HANH KHACH DAT VE TREN CHUYEN BAY");
									return;
								}
							}
						}
						
						/*Confirm Save maybay*/
						Save_DSMB(listmb);//luu thay doi vao File
						Save_DSCB(listcb);//Vi May Bay co chuyen bay duoc chon nen la cap nhap lai DSCB
						/*-------------------*/
						BoxMessage("  UPDATE MAY BAY THANH CONG - LUU THAY DOI");
						return;
					}
				}
			}
		}
	}
}


void SapXepGiamGian(int a[], int b[], int n)//Bubble Sort
{
	for(int i = 0 ; i < n-1 ; i++)
	{
		for(int j = n-1 ; j > i ; j--)
		{
			if(b[j] > b[j-1])
			{
				Swap(a[j],a[j-1]);
				Swap(b[j],b[j-1]);
			}
		}
	}
}


/*--------------------------MANAGER MAY BAY--------------------------*/
void managerMB(DSMAYBAY &listmb, DSCHUYENBAY &listcb)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	FrameMayBay();
	int chon;
	while(true)
	{
        chon = MenuDongManagerMB(MenuManagerMB);
        switch (chon)
		{
        	case 1:
			{
				addMB(listmb);
				return;
			}
        	case 2:
			{
				deleteMB(listmb,listcb);
				return;
			}
			case 3:
			{
				updateMB(listmb,listcb);//dua listcb len de cap nhap lai so cho ngoi
				return;
			}
			case 4:
			{
				if(listmb.soMB == 0)
				{
					ScreenApp();
					BoxMessage("DANH SACH MAY BAY RONG");
					return;
				}
				else
				{
					ScreenApp();
					BoxShowDSMB();
					int px = 122,py = 8;
					for(int i = 0 ; i < listmb.soMB ; i++)
					{
						gotoxy(px,py);
						cout<<listmb.nodeMB[i].sohieuMB<<"["<<listmb.nodeMB[i].x<<"]";
						py++;
						gotoxy(px,py);
						cout<<"-------------------"<<endl;
						py++;
					}
				
					////////////////////////////////////
					char *listMB(0);//giong thuc don
					int so_mb = listmb.soMB;
					listMB = new char[listmb.soMB*2];
					int chon;
					ScreenApp();
					for(int i = 0 ; i < listmb.soMB*2 ; i++)
					{
						listMB[i] = char(176);
					}
				
					while(chon != 27)
					{
						chon = MenuDongDSMB(listMB , so_mb);
						if(chon == 27)
						{
							break;
						}
						XoaManHinh();
						ScreenApp();
						BoxShowDSMB();
						int px = 122,py = 8;
						for(int i = 0 ; i < listmb.soMB ; i++)
						{
							gotoxy(px,py);
							cout<<listmb.nodeMB[i].sohieuMB<<"["<<listmb.nodeMB[i].x<<"]";
							py++;
							gotoxy(px,py);
							cout<<"-------------------"<<endl;
							py++;
						}
						BoxShow1MB(listmb.nodeMB[chon]);
						gotoxy(13,55);
						system("pause");
					}
					return;
				}
			}

			case 5:
			{
				if(listmb.soMB == 0)
				{
					BoxMessage("   CHUA CO MAY BAY TRONG DANH SACH");
					return;
				}
			
				/*-----COPY TAT CAC CAC SHMB CUA DSCB DU CHO SHMB CO TRUNG HAY KHONG TRUNG-----*/
				string SHMB_TEMP[50];int count = 0;
				for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
				{
					if(p->data.staTus == 3)//cac may bay thuc hien hoan tat chuyen bay cua no thi moi dua vao DS thong ke
					{
						stringstream ss;
						string target;
						ss << p->data.sohieumb;
						ss >> target;
						SHMB_TEMP[count] = target;count++;
					}
				}
				//ket thuc vong lap ta duoc mang cac SHMB co the trung nhau boi cac chuyen bay da co the chon chung may bay (chi xet cac chuyen bay hoan tat thi may bay moi duoc tinh luot)
				//BUOC THONG KE//
				int vitri[30];//mang luu vi tri xuat hien dau tien trong mang SHMB tam thoi
				int solan[30];//luu so lan thuc hien cua may bay co SHMB tai vi tri i trong mang tuong ung
				int nano = 0;// so luong cac SHMB khac nhau trong DS
				
				for(int i = 0 ; i < count ; i++)
				{
					int check = 0;
					int appreare = 1;//xuat hien luon bang 1 dau tien
					///kiem tra phia truoc phan tu
					for(int z = 0 ; z < i ; z++)
					{
						if(SHMB_TEMP[z] == SHMB_TEMP[i])
						check = 1;//co ton tai roi
					}
						
					if(check == 0)
					{
						for(int j = i+1 ; j < count ; j++)
						{
							if(SHMB_TEMP[i] == SHMB_TEMP[j])//vi moi phan tu la string nen so sanh "==" duoc
							appreare++;
						}
						vitri[nano] = i;//vi tri xuat hien dau tien trong mang SHMB_temp
						solan[nano] = appreare;
						nano++;
					}
				}
				///TIEN HANH SAP XEP
				BoxThongKeLuotBay();
				SapXepGiamGian(vitri,solan,nano);
				////////SHOW THONG KE/////////
		
				int px = 110;int pxturn = 135; int py = 9;
				SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
				for(int i = 0;  i < nano ; i++)
				{
					gotoxy(px,py);cout << SHMB_TEMP[vitri[i]];
					gotoxy(pxturn,py);cout<<solan[i];
					py++;
					gotoxy(px,py);
					cout<<"----------------------------";
					py++;
				}
				BoxMessage("THONG KE LUOT THUC HIEN CHUYEN BAY HOAN TAT");
				return;
			}
		
			case 27:
			{
				BoxMessage("            EXIT MANAGER AIRPLANE");
				return;
			}
    	}
	}
}

/*--------------------------MANAGER MAY BAY--------------------------*/



/*----------------------------------CHUYEN BAY-----------------------------------*/

void addCB(DSCHUYENBAY &listcb,NODECB *p)///them chuyen bay thi them vao dau danh sach vi cac chuyen bay tao roi se duoc troi ve sau, neu them vao cuoi thi rat ton thoi gian
{
	if(listcb.pHead == NULL)
	{
		listcb.pHead=listcb.pTail=p;
	}
	else
	{
		/////CHUYEN LAI THANH THEM VAO DAU/////
		p->pNext = listcb.pHead;
		listcb.pHead = p;
	}
}

bool check_TrungMSCB(DSCHUYENBAY listcb, char MSCB_temp[])
{
	for(NODECB *k = listcb.pHead ; k != NULL ; k = k->pNext)
		if(strcmp(k->data.MSCB,MSCB_temp) == 0 )
		{
			return true;//tuc la bi trung
		}
	return false;
}


void inPutCB(DSCHUYENBAY &listcb , DSMAYBAY &listmb)
{
	if(listmb.soMB == 0)
	{//truong hop chua co may bay trong danh sach may bay
		ScreenApp();
		BoxMessage("CHUA CO MAY BAY DE KHOI TAO CHUYEN BAY");
		return;//chua co may bay trong DS MB
	}
	
		
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	CHUYENBAY cb;
	BoxAddChuyenBay();
	char *MSCB_temp = NhapMaChuyenBay(MAXMACHUYENBAY-1,30,16);
	if(MSCB_temp[0] == 'e')return;//da nhan phim ESC
	///check xem ma chuyen bay co trung hay khong
	if(check_TrungMSCB(listcb,MSCB_temp) == true)
	{
		delete MSCB_temp;
		BoxMessage("MA SO CHUYEN BAY BI TRUNG");
		return;
	}
	
	/*-------------NGAY THANG NAM HIEN TAI------------*/
	time_t baygio = time(0);
   	tm *ltm = localtime(&baygio);
   	gotoxy(1,16);
	cout << "DAY: "<< ltm->tm_mday << endl;
	gotoxy(1,17);
   	cout << "MONTH: "<< 1 + ltm->tm_mon<< endl;
   	gotoxy(1,18);
   	cout << "YEAR: "<< 1900 + ltm->tm_year<< endl;
   	int daynow = ltm->tm_mday;//system day
   	int monthnow = 1 + ltm->tm_mon;//system month
   	int yearnow = 1900 + ltm->tm_year;//system year
	int Thang[12] = {31,CheckNamNhuan(yearnow)?29:28,31,30,31,30,31,31,30,31,30,31};
	/*-------------NGAY THANG NAM HIEN TAI------------*/
	
	
	char *dayDepart;
	char *monthDepart;
	int testday;
	int testmonth;
	
	int ore = 1;//true
	do
	{
		SetConsoleTextAttribute(consoleHandle, (7 << 4) | 0);
		gotoxy(31,20);cout<<"  ";gotoxy(56,20);cout<<"  ";
		
		dayDepart = NhapNgayKhoiHanhCuaChuyenBay(2,Thang[monthnow-1],31,20);
		if(dayDepart[0] == 'e')
		{
			delete MSCB_temp;
			delete dayDepart;
			return;//da nhan phim ESC
		}
		
		monthDepart = NhapThangKhoiHanhCuaChuyenBay(2,56,20);
		if(monthDepart[0] == 'e')
		{
			delete MSCB_temp;
			delete dayDepart;
			delete monthDepart;
			return;//da nhan phim ESC
		}
		
		testday = atoi(dayDepart);
		testmonth = atoi(monthDepart);
		
		if(testmonth < monthnow)
		{
			ore = 0;//neu thang nhap nho hon thang hien tai hoac lon hon so thang gioi han thi false
			BoxSetColorConSole("TIME KHONG HOP LE");
			gotoxy(51,42);cout<<"                            ";
			gotoxy(51,43);cout<<"                            ";
			gotoxy(51,44);cout<<"                            ";
			gotoxy(51,45);cout<<"                            ";
			gotoxy(51,46);cout<<"                            ";
		}
		else
		{
			ore = 1;
		}
		if(testday < daynow && testmonth <= monthnow)//neu nhu nhap day nho hon ngay hien tai thi thang phai lon hon thang hien tai
		{
			ore = 0;
			BoxSetColorConSole("TIME KHONG HOP LE");
			gotoxy(51,42);cout<<"                            ";
			gotoxy(51,43);cout<<"                            ";
			gotoxy(51,44);cout<<"                            ";
			gotoxy(51,45);cout<<"                            ";
			gotoxy(51,46);cout<<"                            ";
		}

	}while(ore != 1);
		
		
	fflush(stdin);
	char *yearDepart = NhapNamKhoiHanhCuaChuyenBay(4,81,20);
	if(yearDepart[0] == 'e')
	{
		delete MSCB_temp;
		delete dayDepart;
		delete monthDepart;
		delete yearDepart;
		return;//da nhan phim ESC
	}
		
	////////////////////////////////////////////////////
	fflush(stdin);
	char *hourDepart = NhapGioKhoiHanhCuaChuyenBay(2,31,24);
	if(hourDepart[0] == 'e')
	{
		delete MSCB_temp;
		delete dayDepart;
		delete monthDepart;
		delete yearDepart;
		delete hourDepart;
		return;//da nhan phim ESC
	}
	
	char *sanbayDen = NhapSanBayDenCuaChuyenBay(1,31,28);
	if(sanbayDen[0] == 'e')
	{
		delete MSCB_temp;
		delete dayDepart;
		delete monthDepart;
		delete yearDepart;
		delete hourDepart;
		delete sanbayDen;
		return;//da nhan phim ESC
	}
	
	int index = atoi(sanbayDen);
		
		
	/////---Check In Node Time---/////
	if(SearchNodeTime(atoi(dayDepart) , atoi(monthDepart), atoi(yearDepart), atoi(hourDepart), index-1) == true)
	{
		delete MSCB_temp;
		delete dayDepart;
		delete monthDepart;
		delete yearDepart;
		delete hourDepart;
		delete sanbayDen;
		BoxMessage("KHOI TAO CHUYEN BAY KHONG HOP LE - ERROR TIME");
		return;
	}
	
	
	int time_now;
	time_now = (yearnow*100  + monthnow) *100 + daynow;//cho nay chi test thoi chu chua dung bussiness nha
//cho nay dang sd thoi gian lay ra cua he thong - can set cho TimeDepart khi nguoi dung nhap vao


	/*--KHOI TAO THOI GIAN CHUYEN BAY SE THUC HIEN--*/
	int departure_time = (atoi(yearDepart)*100 + atoi(monthDepart)) * 100 + atoi(dayDepart);
	
    gotoxy(1,22);
   	cout << "Time Now "<< endl << time_now;
    
    
	/*---------Show DSMB de chuyen bay chon--------*/
	BoxShowDSMB();
	int px = 121,py = 8;
	for(int i = 0 ; i < listmb.soMB ; i++)
	{
		gotoxy(px+1,py);
		cout<<listmb.nodeMB[i].sohieuMB;
		py++;
		gotoxy(px,py);
		cout<<"--------------------"<<endl;
		py++;
	}
	/*---------Show DSMB de chuyen bay chon--------*/

	///////////////////////////////////////////////////////////////////////
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	///////////////////////////////////////////////////////////////////////
		
	int check = 0;
	char *sohieuMB;
	do
	{
		sohieuMB = NULL;
		fflush(stdin);
		sohieuMB = NhapSoHieuMayBay(MAXSOHIEU-1,56,32);
		if(sohieuMB[0] == 'e')
		{
			delete MSCB_temp;
			delete dayDepart;
			delete monthDepart;
			delete yearDepart;
			delete hourDepart;
			delete sanbayDen;
			delete sohieuMB;
			return;//da nhan phim ESC
		}
			
		for(int i = 0 ; i < listmb.soMB ; i++)
		{
			if(strcmp(listmb.nodeMB[i].sohieuMB , sohieuMB) == 0)
			{
				check = 1;
				break;
			}
		}
			
		if(check == 0)
		{
			BoxMessage("NHAP SHMB KHONG CHINH XAC - NHAP LAI");
			int choice = choice_YesNo();
			if(choice == 1)
			{
				delete MSCB_temp;
				delete dayDepart;
				delete monthDepart;
				delete yearDepart;
				delete hourDepart;
				delete sanbayDen;
				delete sohieuMB;
				BoxMessage("             HUY KHOI TAO CHUYEN BAY ");
				return;
			}
			else
			{
				XoaManHinh();
				SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
				gotoxy(92,36);cout<<"     ";//khoang trang de de len choice
				gotoxy(92,37);cout<<"     ";//khoang trang de de len choice
				gotoxy(56,32);cout<<"                        ";//khoang trang de de SHMB tu dang hien thi
				gotoxy(42,45);cout<<"                                                ";//khoang trang de de message
			}
		}
	}while(check != 1);//con thuc hien khi check != 1


	/////////////////////////////////////////////////////////////////////////////////////
	for(int i=0;i<listmb.soMB;i++)
	{
		if(strcmp(listmb.nodeMB[i].sohieuMB,sohieuMB) == 0)//neu tai nodeMB[i] nao trong so hieu nguoi nhap
		{
			strcpy(MSCB_Depart[z],MSCB_temp);//copy MSCB vua khoi tao gan vao mang MSCB_Depart
			///////FOR MAY BAY///////
			listmb.nodeMB[i].x = 0;//chon xong set lai = 0 de khong duoc update hay xoa MB
			//////FOR CHUYEN BAY////////
			strcpy(cb.MSCB,MSCB_temp);//dua MSCB vua nhap va cb
			cb.ngayDi = atoi(dayDepart);
			cb.thangDi = atoi(monthDepart);
			cb.namDi = atoi(yearDepart);
			cb.gioDi = atoi(hourDepart);
			cb.sanBay = sanBay[index-1];//bien string = char sanBay[i]
			strcpy(cb.sohieumb,sohieuMB);
			cb.soluongVe = listmb.nodeMB[i].sochoMB;
			cb.staTus = 1;//khi tao chuyen bay mac dinh con ve
			cb.nodeVe = new string[cb.soluongVe];//thiet lap mang ve: la mang ma moi phan tu cua mang la so CMND cua 1 hanh khach , chi so la so ve, gia tri la so CMND
			for(int i = 0; i < cb.soluongVe ; i++)//bat dau tu ve thu 1 chu khong bd tu 0
			{
				cb.nodeVe[i] = "0";
			}
			/*them*/
			cb.soveduocdat = 0;
			NODECB *p = GetNode(cb);
			addCB(listcb,p);
			Time_CB_Depart[z] = departure_time;z++;
			/*---Them NodeTime--*/
			NodeTime *nodetime = CreateNodeTime(atoi(dayDepart) , atoi(monthDepart), atoi(yearDepart), atoi(hourDepart), index-1);
			InsertNodeTime(nodetime,atoi(dayDepart));//NodeTime va ngaydi
			/*---Them NodeTime--*/
			
			/*Confirm Save chuyen bay*/
			BoxConfirmSaveFile();
			int choice = choice_YesNo();
			if(choice == 0)
			{
				Save_DSCB(listcb);
			}
			/*-----------------------*/
				
			////Giai phong vung nho////
			delete MSCB_temp;
			delete dayDepart;
			delete monthDepart;
			delete yearDepart;
			delete hourDepart;
			delete sanbayDen;
			delete sohieuMB;
			///////////////////////////
			BoxMessage("KHOI TAO CHUYEN BAY THANH CONG");
			return;//tao thanh cong
		}
	}
}


void updateCB(DSCHUYENBAY &listcb)
{
	////NGAY THANG NAM////
	time_t baygio = time(0);
   	tm *ltm = localtime(&baygio);
	////////////////////////////
   	int month = 1 + ltm->tm_mon;
   	int year = 1900 + ltm->tm_year;
	int Thang[12] = {31,CheckNamNhuan(year)?29:28,31,30,31,30,31,31,30,31,30,31};
	
	if(listcb.pHead == NULL)
	{
		BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
		return;
	}
	
	BoxShowDSCB();
	int px = 121,py = 8;
	for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
	{
		gotoxy(px,py);
		cout<<q->data.MSCB<<"["<<q->data.staTus<<"]";
		py++;
		gotoxy(px,py);
		cout<<"--------------------"<<endl;
		py++;
	}
	
	Navbar9();//de nhap MSCB
	char *MSCB = NhapMaChuyenBay(MAXMACHUYENBAY-1,68,16);
	if(MSCB[0] == 'e')
	{
		delete MSCB;
		return;//da nhan phim ESC
	}
	
	int check = 0;
	for(NODECB *k = listcb.pHead ; k != NULL ; k = k->pNext)
	{
		if(strcmp(k->data.MSCB,MSCB)==0)
		{
			check = 1;
			break;
		}
	}
	
	if(check == 0)
	{
		delete MSCB;
		BoxMessage("NHAP MA SO CHUYEN BAY KHONG CHINH XAC");
		return;
	}
	
	
	for(NODECB *p = listcb.pHead; p != NULL; p = p ->pNext)
	{
		if(strcmp(p->data.MSCB,MSCB)==0 && p->data.staTus == 1 )//khi tim duoc MSCB trung khop va trang thai ve cua chuyen bay do la chua co ai dat va status phai la con ve moi duoc update
		{//chi update duoc khi CB o trang thai con ve va phai Full ve trong
			///check Full Ve con trong
			bool kq = check_FullVeConTrong(p->data);//neu chua co hanh khach nao dat ve tren chuyen bay thi moi duoc cap nhap
			
			if(kq == true)//con Full ve trong - chua co hanh khach nao dat ve tren chuyen bay do
			{
				BoxUpdateChuyenBay();
				
				fflush(stdin);
				char *dayDepart = NhapNgayKhoiHanhCuaChuyenBay(2,Thang[month-1],62,24);
				if(dayDepart[0] == 'e')
				{
					delete MSCB;
					delete dayDepart;
					return;//da nhan phim ESC
				}
				
				fflush(stdin);
				char *monthDepart = NhapThangKhoiHanhCuaChuyenBay(2,62,26);
				if(monthDepart[0] == 'e')
				{
					delete MSCB;
					delete dayDepart;
					delete monthDepart;
					return;//da nhan phim ESC
				}
				
				fflush(stdin);
				char *yearDepart = NhapNamKhoiHanhCuaChuyenBay(4,62,28);
				if(yearDepart[0] == 'e')
				{
					delete MSCB;
					delete dayDepart;
					delete monthDepart;
					delete yearDepart;
					return;//da nhan phim ESC
				}
				
				fflush(stdin);
				char *hourDepart = NhapGioKhoiHanhCuaChuyenBay(2,62,30);
				if(hourDepart[0] == 'e')
				{
					delete MSCB;
					delete dayDepart;
					delete monthDepart;
					delete yearDepart;
					delete hourDepart;
					return;//da nhan phim ESC
				}
				
				fflush(stdin);
				char *sanbayDen = NhapSanBayDenCuaChuyenBay(1,62,32);
				if(sanbayDen[0] == 'e')
				{
					delete MSCB;
					delete dayDepart;
					delete monthDepart;
					delete yearDepart;
					delete hourDepart;
					delete sanbayDen;
					return;//da nhan phim ESC
				}
				
				
				/*-------Check for update with NodeTime--------*/
				if(SearchNodeTime(atoi(dayDepart) , atoi(monthDepart), atoi(yearDepart), atoi(hourDepart), atoi(sanbayDen)-1) == true)
				{
					delete MSCB;
					delete dayDepart;
					delete monthDepart;
					delete yearDepart;
					delete hourDepart;
					delete sanbayDen;
					BoxMessage("UPDATE CHUYEN BAY KHONG HOP LE - ERROR TIME");
					return;
				}
				/*---------------------------------------------*/
				int airport;// sanbay cu
				for(int i = 0 ; i < 5 ; i++)
				{
					if(sanBay[i] == p->data.sanBay)
					{
						airport = i;
						break;
					}
				}
				
				/*---Xoa NodeTime Cu---*/
				DeleteNodeTime(p->data.ngayDi , p->data.thangDi , p->data.namDi , p->data.gioDi ,airport);//cac thong so cu
				/*---Xoa NodeTime Cu---*/
				
				p->data.ngayDi = atoi(dayDepart);
				p->data.thangDi = atoi(monthDepart);
				p->data.namDi = atoi(yearDepart);
				p->data.gioDi = atoi(hourDepart);
				int index = atoi(sanbayDen);
				p->data.sanBay = sanBay[index-1];//bien string = char sanBay[i]
				
				/*---Them moi lai 1 NodeTime---*/
				NodeTime *nodetime = CreateNodeTime(atoi(dayDepart) , atoi(monthDepart), atoi(yearDepart), atoi(hourDepart), index-1);
				InsertNodeTime(nodetime,atoi(dayDepart));//NodeTime va ngaydi
				/*---Them moi lai 1 NodeTime---*/
				
				/*Confirm Save chuyen bay*/
				Save_DSCB(listcb);
				/*-----------------------*/
				
				delete MSCB;
				delete dayDepart;
				delete monthDepart;
				delete yearDepart;
				delete hourDepart;
				delete sanbayDen;
				BoxMessage("UPDATE CHUYEN BAY THANH CONG");
				return;
			}
			
			if(kq == false)
			{
				delete MSCB;
				BoxMessage("UPDATE THAT BAI - DA CO HANH KHACH DAT VE");
				return;
			}
		}
		else if(strcmp(p->data.MSCB,MSCB)==0 && (p->data.staTus == 0 || p->data.staTus == 2 || p->data.staTus == 3))
		{
			delete MSCB;
			BoxMessage("UPDATE THAT BAI - TRANG THAI KHONG HOP LE");
			return;
		}
	}
}



void HuyChuyenBay(DSCHUYENBAY &listcb , DSMAYBAY &listmb)
{
	if(listcb.pHead == NULL)
	{
		BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
		return;
	}
	
	BoxHuyChuyenBay();
	ScreenApp();
	BoxShowDSCB();
	int px = 121,py = 8;
	for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
		{
			gotoxy(px,py);
			cout<<q->data.MSCB<<"["<<q->data.staTus<<"]";
			py++;
			gotoxy(px,py);
			cout<<"--------------------"<<endl;
			py++;
		}
		
		int check = 0;
		fflush(stdin);
		char *MSCB_temp = NhapMaChuyenBay(MAXMACHUYENBAY-1,70,21);
		if(MSCB_temp[0] == 'e')return;//da nhan phim ESC
		for(NODECB *p = listcb.pHead; p != NULL ;p = p->pNext)
		{
			if(strcmp(MSCB_temp,p->data.MSCB) == 0)
			{
				check = 1;
				break;
			}
		}
		if(check == 0)
		{
			delete MSCB_temp;
			BoxMessage("NHAP MA SO CHUYEN BAY KHONG CHINH XAC");
			return;
		}
	
	//duyet danh sach de tim phan tu co khoa tuong ung va set trang thai huy chuyen
	for(NODECB *k = listcb.pHead; k != NULL ; k = k->pNext)
	{
		/*------Co the huy chuyen bay o trang thai con ve va FullVeTrong------*/
		if(strcmp(k->data.MSCB , MSCB_temp) == 0 && k->data.staTus == 1)//con ve
		{
			int kq = check_FullVeConTrong(k->data);//chi huy duoc khi chua co ai dat ve
			if(kq != 0)//tuc la full ve trong
			{
				//set trang thai cua may bay thuc hien chuyen bay do ve sang sang de cac chuyen bay khac chon may bay do duoc,  hoac xoa may bay do..
				for(int i = 0 ; i < listmb.soMB ; i++)
				{
					if(strcmp(k->data.sohieumb , listmb.nodeMB[i].sohieuMB) == 0)
					listmb.nodeMB[i].x = 1;//thiet lap lai trang thai co the update cho MB
				}
				
				k->data.staTus = 0;//set trang thai ve huy chuyen
				k->data.soluongVe = 0;
				k->data.nodeVe = NULL;
				
				int airport;
				for(int i = 0 ; i < 5 ; i++)
				{
					if(k->data.sanBay == sanBay[i])
					{
						airport = i;
						break;
					}
				}
				/*---Xoa NodeTime Cu---*/
				DeleteNodeTime(k->data.ngayDi , k->data.thangDi , k->data.namDi , k->data.gioDi ,airport);
				/*---Xoa NodeTime Cu---*/
				
				/*Confirm Save chuyen bay*/
				BoxConfirmSaveFile();
				int choice = choice_YesNo();
				if(choice == 0)
				{
					Save_DSCB(listcb);
				}
				/*-----------------------*/
				
				BoxMessage("HUY CHUYEN BAY THANH CONG");
				delete MSCB_temp;
				return;
			}
			else
			{
				delete MSCB_temp;
				BoxMessage("HUY CHUYEN THAT BAI - DA CO HANH KHACH DAT VE");
				return;
			}
		}
		else if(strcmp(k->data.MSCB , MSCB_temp) == 0 && k->data.staTus == 0)//da duoc huy chuyen truoc do
		{
			delete MSCB_temp;
			BoxMessage("CHUYEN BAY DA DUOC HUY CHUYEN TRUOC DO");
			return;
		}
		else if(strcmp(k->data.MSCB , MSCB_temp) == 0 && k->data.staTus == 2)//da duoc huy chuyen truoc do
		{
			delete MSCB_temp;
			BoxMessage("CHUYEN BAY DA FULL VE - KHONG HUY CHUYEN");
			return;
		}
		else if(strcmp(k->data.MSCB , MSCB_temp) == 0 && k->data.staTus == 3)//da hoan tat
		{
			delete MSCB_temp;
			BoxMessage("CHUYEN BAY DA HOAN TAT - KHONG HUY CHUYEN");
			return;
		}
	}
}


void ShowVeChuyenBay(DSCHUYENBAY listcb, char MSCB[])
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	ScreenApp();
	
	int px = 112; int py = 5;
	for(NODECB *k = listcb.pHead; k != NULL ; k = k->pNext)
	{
		if(strcmp(MSCB, k->data.MSCB) == 0)//neu tai mot node chuyen bay nao co ma chuyen bay giong voi tham so MSCB truyen len
		{
			if(k->data.staTus == 3)
			{
				BoxMessage("CHUYEN BAY DA HOAN TAT");
			}
			
			else if(k->data.staTus == 2)
			{
				BoxMessage("CHUYEN BAY DA HET VE");
			}
			
			
			else if(k->data.staTus == 0)
			{
				BoxMessage("CHUYEN BAY DA HUY CHUYEN - KHONG SHOW VE");
				return;
			}
			
			BoxShowVeChuyenBay();
			for(int i = 0; i < k->data.soluongVe ; i++)
			{
				if(i == 35)
				{
					px += 15;
					py = 5;
				}
				if(k->data.nodeVe[i] == "0")
				{
					gotoxy(px,py);py++;
					SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
					cout<<"V"<<i+1<<"|"<<k->data.nodeVe[i];
				}
				else if(k->data.nodeVe[i] != "0")
				{
					gotoxy(px,py);py++;
					SetConsoleTextAttribute(consoleHandle, ( 12 << 4) | 2);
					cout<<"V"<<i+1<<"|"<<k->data.nodeVe[i];
				}
			}
		}
	}
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
	gotoxy(13,55);
	system("pause");
}


void ShowVeTrongChuyenBay(DSCHUYENBAY listcb, char MSCB[])
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int px = 126; int py = 5;
	for(NODECB *k = listcb.pHead; k != NULL ; k = k->pNext)
	{
		if(strcmp(MSCB, k->data.MSCB) == 0)//neu tai mot node chuyen bay nao co ma chuyen bay giong voi tham bien truyen len 
		{
			if(k->data.staTus == 1)//va chuyen bay phai dang o trang thai con ve
			{
				BoxShowVeTrongChuyenBay();
				for(int i = 0; i < k->data.soluongVe ; i++)
				{
					if(k->data.nodeVe[i] == "0")
					{
						if(i == 35)
						{
							px+=9;
							py = 5;
						}
						gotoxy(px,py);py++;
						SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
						cout<<"Ve "<<i+1<<"|";
					}
				}
			}
			else
			{
				BoxMessage("CHUYEN BAY KHONG O TRANG THAI CON VE");//tuc la cac trang thai != 1
				return;
			}
			
			BoxSetColorConSole("     EXIT LIST TICKET");
			return;
		}
	}
	gotoxy(13,55);
	system("pause");
}


void ShowHK_ThuocChuyenBay(NODEHKPTR T, char CMND_temp[],int py/*dua toa do*/)//HAM ShowHanhKhachThuocChuyenBay goi no
{

   	if(strcmp(T->data.CMND,CMND_temp) == 0)
    {
     	gotoxy(53,py);
      	cout<<T->data.CMND<<endl;
      	gotoxy(70,py);
      	cout<<T->data.ho;
		gotoxy(90,py);
		cout<<T->data.ten<<endl;
      	gotoxy(114,py);
      	cout<<gioiTinh[T->data.gioiTinh-1];
///////////////////////////////////////////
	}
	 else if(strcmp(T->data.CMND, CMND_temp) < 0)
	 {
	 	ShowHK_ThuocChuyenBay(T->Right,CMND_temp,py);
	 }
    else if(strcmp(T->data.CMND, CMND_temp) > 0)
    {
    	ShowHK_ThuocChuyenBay(T->Left,CMND_temp,py);
	}
}


//*------------------------------Success-------------------------------*//
void ShowHanhKhachThuocChuyenBay(DSCHUYENBAY listcb,NODEHKPTR listhk, char MSCB[])
{
	int py = 9;
	for(NODECB *k = listcb.pHead ; k != NULL ; k = k->pNext)
	{
		if(strcmp(k->data.MSCB, MSCB) == 0)//neu nhu tai node CB nao do co ma so trung voi nhap lieu
		{
			ScreenApp();
			BoxShowDanhSachHanhKhach(MSCB,k->data.ngayDi,k->data.thangDi,k->data.namDi,k->data.gioDi,k->data.sanBay,k->data.staTus);
			int ajax = 0;
			int sumcus = 0;
			bool wix = true;//xac nhan viec Show HK tiep hay khong
			int stt = 1;
			for(int i = 0; i < k->data.soluongVe ; i++)
			{
				if(k->data.nodeVe[i] != "0")
				{
					sumcus++;//dem so luong hanh khach
				}
			}
			
			tt:
			int show_default = 0;
			for(int pos = ajax ; pos < k->data.soluongVe ; pos++ )
			{
				if(k->data.nodeVe[pos] !="0" && wix == true)//tuc la tai ve do da co so CMND -> dang co hanh khach dat -> Show hanh Khach do
				{
					show_default ++;//tang so phan tu xuat hien
					gotoxy(43,py);cout<<stt;
					gotoxy(127,py);//cung show len bang DSHK thuoc chuyen bay
					cout<<"So Ve: "<<pos+1;
					const char* temp = (k->data.nodeVe[pos]).c_str();//chuyen so CMND(string) tai ve thu i thanh char
					char *cmnd = new char[10];//khoi tao 1 mang char
					strcpy(cmnd,temp);//copy So CMND vua chuyen doi vao mang char vua khoi tao
					ShowHK_ThuocChuyenBay(listhk,cmnd,py);//nam ben khaibao.h
					py+=2;
					stt++;
					
					if(show_default %5 == 0)//show du 5 hanh khach
					{
						wix = false;
					}
				}
				
				if(wix == false)//nhan nut next va prew
				{
					int choice;
					choice = MenuPaging();
					switch(choice)
					{
						case 1://Show Next//
						{
							py = 9;//cho quay len tren de in lai
							BoxEraseListHK();
							wix = true;
							break;
						}
						
						case -1://Show Prew//
						{
							BoxEraseListHK();
							int dem = 0;
							py = 9;
							int postemp;
							for(int j  = pos ; j >= 0 ; j--)
							{
								if(dem == 10)
								{
									break;
								}
								postemp = j;
								if(k->data.nodeVe[j] !="0")//tuc la tai ve do da co so CMND -> dang co hanh khach dat -> Show hanh Khach do
								{
									dem ++;
									stt--;
								}
							}//for
								
							wix = true;
							ajax = postemp;
							goto tt;
							break;
						}
						case 27:
						{
							return;
						}
					}
				}
			}
		}
	}
}


bool Check_HetVe(CHUYENBAY cb)
{
	int tongsove = cb.soluongVe;
	int count = 0;
	for(int i = 0 ; i < tongsove ; i++)
	{
		if(cb.nodeVe[i] != "0")//nghia la no da bi dat
		{
			count++;
		}
	}
	if(count == tongsove)
	{
		return true;//chuyen bay da het ve
	}
	else return false;
}


int Check_ConVe(CHUYENBAY cb)//ShowChuyenBay_Ngay_Thang_Nam_ConVe goi no
{
	int demvetrong = 0;
	for(int i = 0 ; i < cb.soluongVe ; i++)
	{
		if(cb.nodeVe[i] == "0")
		{
			demvetrong+=1;
		}
	}
	return demvetrong;
}


void ShowChuyenBay_Ngay_Thang_Nam_ConVe(DSCHUYENBAY listcb,int ngay,int thang, int nam,int indexairport)
{
	int px = 117,py = 8;
	BoxShowChuyenBayTheoThoiGian_ConVe();
	string temp1 = sanBay[indexairport-1];
	string temp2;
	for(NODECB *k = listcb.pHead ; k != NULL; k = k->pNext)
	{
		temp2 = "";
		temp2 = k->data.sanBay;
		if(k->data.ngayDi == ngay && k->data.thangDi == thang && k->data.namDi == nam && (temp1 == temp2))
		{
			if(k->data.staTus == 1)
			{
				int soluongvetrong = Check_ConVe(k->data);
				if(soluongvetrong != 0)//tuc la con ve trong
				{
					gotoxy(px,py);
					cout<<k->data.MSCB<<" CON "<< soluongvetrong <<" VE TRONG";
					py++;
					gotoxy(px,py);
					cout<<"------------------------"<<endl;
					py++;
				}
			}
			break;
		}
	}
}


/*-----------------LOAD CHUYEN BAY-------------------*/
void Read_1CB(ifstream &filein, CHUYENBAY &cb)
{
	char timeData[10];
	char status[2];
	char day[3];
	char month[3];
	char year[5];
	char hour[3];
	char Airport[21];
	char SoHieuMB[MAXSOHIEU];
	char soluongve[3];
	char soluongveduocdat[3];
	
	filein.getline(timeData ,10, ',');
	filein.getline(cb.MSCB, MAXMACHUYENBAY, ',');
	filein.getline(status,2,',');cb.staTus = atoi(status);
	filein.getline(day,3,',');cb.ngayDi = atoi(day);
	filein.getline(month,3,',');cb.thangDi = atoi(month);
	filein.getline(year,5,',');cb.namDi = atoi(year);
	filein.getline(hour,3,',');cb.gioDi = atoi(hour);
	filein.getline(Airport,21,',');cb.sanBay = Airport;
	filein.getline(SoHieuMB,MAXSOHIEU,',');strcpy(cb.sohieumb,SoHieuMB);
	filein.getline(soluongve,3,',');cb.soluongVe = atoi(soluongve);
	filein.getline(soluongveduocdat,3,',');cb.soveduocdat = atoi(soluongveduocdat);
	
	
	/*-----------------------*/
	Time_CB_Depart[z] = atoi(timeData);
	strcpy(MSCB_Depart[z] , cb.MSCB);
	z++;//tang chi so
	/*-----------------------*/
	cb.nodeVe = new string[cb.soluongVe];
	for(int i = 0; i < cb.soluongVe ; i++)//bat dau tu ve thu 1 chu khong bd tu 0
	{
		cb.nodeVe[i] = "0";
	}
	for(int i = 0 ; i < cb.soluongVe ; i++)
	{
		char radis[3];
		char soCM[10];
		
		filein.getline(radis,3,'-');
		if(i == cb.soluongVe-1)
		{
			filein.getline(soCM,10,'|');
		}
		else
		{
			filein.getline(soCM,10,',');
		}
		stringstream ss;
		string target;
		ss << soCM;
		ss >> target;
		if(target.length() == 9)
		{
			cb.nodeVe[i] = target;
		}
	}
	string temp;
	getline(filein, temp);
}


void Read_DSCB(ifstream &filein, DSCHUYENBAY &listcb , DSMAYBAY &listmb)
{
	while(!filein.eof())
	{
		CHUYENBAY cb;
		Read_1CB(filein,cb);
		
		/*---------khoi tao NodeTime cho chuyen bay vua doc duoc---------*/
		/////---Check In Node Time---/////
		int index = 0;//de lay chi so cua mang san bay
		for(int i = 0 ; i < 5 ; i++)//5 - So luong san bay
		{
			if(cb.sanBay == sanBay[i])
			{
				index = i;
				break;
			}
		}
		if(SearchNodeTime(cb.ngayDi , cb.thangDi, cb.namDi, cb.gioDi, index) == false)//NodeTime nay chua co
		{
			//Dua Chuyen Bay vao NodeTime//
			NodeTime *nodetime = CreateNodeTime(cb.ngayDi , cb.thangDi, cb.namDi, cb.gioDi, index);
			InsertNodeTime(nodetime,cb.ngayDi);//NodeTime va ngaydi
			
			NODECB *p = GetNode(cb);
			addCB(listcb,p);
			
			
					/*------THIET LAP CHO TRANG THAI MAY BAY THUC HIEN CHUYEN BAY NAY (trang thai khac huy chuyen va hoan tat)------*/
			if(cb.staTus == 1 || cb.staTus == 2)//khi con o trang thai nay thi MB van Busy
			{
				for(int i = 0 ; i < listmb.soMB ; i++)
				{
					if(strcmp(cb.sohieumb , listmb.nodeMB[i].sohieuMB ) == 0)
					{
						listmb.nodeMB[i].x = 0;//trang thai Busy
						break;
					}
				}
			}
		/*-----------------------------------------------------------------------*/
		}
	}
	filein.close();
}
/*-------------------LOAD CHUYEN BAY-------------------*/

void managerCB(DSCHUYENBAY &listcb, DSMAYBAY &listmb, NODEHKPTR listhk)
{
	FrameChuyenBay();
	int choice;
	while(true)
	{
        choice = MenuDongManagerCB(MenuManagerCB);
        switch (choice)
		{
        	case 1:
			{
				inPutCB(listcb,listmb);
				return;
			}
		
        	case 2:
			{
				updateCB(listcb);
				return;
			}
		
			case 3:
			{
				HuyChuyenBay(listcb,listmb);
				return;
			}
		
			case 4:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO DE LUU");
					return;
				}
				Save_DSCB(listcb);
				BoxMessage("LUU DANH SACH CHUYEN BAY THANH CONG");
				return;
			}
		
			case 5:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
					return;
				}
				else//bac chuoc show DSMB
				{
					ScreenApp();
					BoxShowDSCB();
				
					int count = 0;//dem so chuyen bay co trong ds
					int px = 121,py = 8;
					for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
					{
						gotoxy(px,py);
						cout<<q->data.MSCB<<"["<<q->data.staTus<<"]";count++;
						py++;
						gotoxy(px,py);
						cout<<"---------------------"<<endl;
						py++;
					}
				
					///////////////////////////////////
					char *listCB(0);//giong thuc don
					int so_cb = count;
					listCB = new char[count*2];
					ScreenApp();
					for(int i = 0 ; i < count*2 ; i++)
					{
						listCB[i] = char(176);
					}
				
					int chon;//de chi toi vi tri ma MenuDongDSCB ben tren chon
					while(chon != 27)
					{
						chon = MenuDongDSCB(listCB , so_cb);
						if(chon == 27)
						{
							break;
						}
						XoaManHinh();
						ScreenApp();
						BoxShowDSCB();
						//////SHOW DSCB//////
						int px = 121,py = 8;
						for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
						{
							gotoxy(px,py);
							cout<<q->data.MSCB<<"["<<q->data.staTus<<"]";
							py++;
							gotoxy(px,py);
							cout<<"--------------------"<<endl;
							py++;
						}
						////////////////////
						int i = 0;
						for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
						{
							if((i) == chon)
							{
								gotoxy(13,55);
								BoxShow1CB(q->data);
								break;
							}
							i++;
						}
						gotoxy(13,55);
						system("pause");
					}
					return;
				}
			}
		
			case 6:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
					return;
				}
			
				/*---SHOW RA CAC CHUYEN BAY CO TRANG THAI CON VE - HET VE - HOAN TAT (cac chuyen bay bi huy chuyen khong can show)-----*/
				int test = 0;
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				int px = 124,py = 6;
				for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
				{
					if(p->data.staTus == 1 || p->data.staTus == 2 || p->data.staTus == 3)
					{
						test = 1;//xac nhan la co chuyen bay o trang thai con ve
						SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
						gotoxy(px,py);
						cout<<p->data.MSCB<<"["<<p->data.staTus<<"]";
						py++;
						gotoxy(px,py);
						cout<<"-----------------"<<endl;
						py++;
					}
				}
				if(test == 0)
				{
					BoxMessage("KHONG CO CHUYEN BAY O TRANG THAI CON VE");
					return;
				}
			
				Navbar1();
				char *maCB = NhapMaChuyenBay(MAXMACHUYENBAY-1 ,93, 10);
				int check = 0;//check MSCB
				for(NODECB *p = listcb.pHead; p != NULL; p = p ->pNext)
				{
					if(strcmp(maCB,p->data.MSCB) == 0)
					{
						check = 1;
						ShowVeChuyenBay(listcb,maCB);
						return;
					}
				}
				if(check == 0)
				{
					delete maCB;
					BoxMessage("NHAP MA SO CHUYEN BAY KHONG CHINH XAC");
					return;
				}
			}
		
			case 7:
			{//IN DANH SACH CAC VE CON TRONG CUA 1 CHUYEN BAY CO MSCB LA X
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
					return;
				}
			
				char arrayMACB[20][MAXMACHUYENBAY];int i = 0;
				for(NODECB *p = listcb.pHead; p != NULL; p = p ->pNext)
				{
					strcpy(arrayMACB[i], p->data.MSCB);i++;
				}
			
				
				///////SHOW CHUYEN BAY DANG CO TRANG THAI CON VE TRONG DANH SACH///////
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				int px = 96,py = 13;int test = 0;
				for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
				{
					if(p->data.staTus == 1)
					{
						test = 1;
						SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
						gotoxy(px,py);
						cout<<p->data.MSCB<<"["<<p->data.staTus<<"]";
						py++;
						gotoxy(px,py);
						cout<<"-----------------"<<endl;
						py++;
					}
				}
			
				if(test == 0)
				{
					BoxMessage("KHONG CO CHUYEN BAY O TRANG THAI CON VE");
					return;
				}
				///////////////////////////////////////////////////////
			
				Navbar2();
				fflush(stdin);
				char *maCB = NhapMaChuyenBay(MAXMACHUYENBAY-1 ,96, 11);
				int check = 0;
				for(int k = 0 ; k < i; k++)
				{
					if(strcmp(maCB,arrayMACB[k]) == 0)
					{
						check = 1;
						ShowVeTrongChuyenBay(listcb,maCB);
						return;
					}
				}
				
				if(check == 0)
				{
					delete maCB;
					BoxMessage("NHAP MSCB KHONG CHINH XAC");
					return;
				}
			}
		
			case 8:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
					return;
				}
			
				/*----------SHOW CHUYEN BAY TRONG DANH SACH----------*/
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				int px = 124,py = 6;
				for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
				{
					SetConsoleTextAttribute(consoleHandle, (7 << 4) | 3);
					gotoxy(px,py);
					cout<<p->data.MSCB<<"["<<p->data.staTus<<"]";
					py++;
					gotoxy(px,py);
					cout<<"-----------------"<<endl;
					py++;
				}
				/*----------SHOW CHUYEN BAY TRONG DANH SACH----------*/
			
			
				char arrayMACB[50][MAXMACHUYENBAY];int count = 0;
				for(NODECB *p = listcb.pHead; p != NULL; p = p ->pNext)
				{
					strcpy(arrayMACB[count], p->data.MSCB);count++;
				}
			
				fflush(stdin);
				Navbar3();
				int check = 0;
				char *maCB = NhapMaChuyenBay(MAXMACHUYENBAY-1 ,96, 12);
				for(int k = 0 ; k < count; k++)
				{
					if(strcmp(maCB,arrayMACB[k]) == 0)
					{
						system("cls");
						XoaManHinh();
						ShowHanhKhachThuocChuyenBay(listcb,listhk,maCB);
						check = 1;
						break;
					}
				}
				if(check == 0)
				{
					delete maCB;
					BoxMessage("NHAP MA SO CHUYEN BAY KHONG CHINH XAC");
					return;
				}
				gotoxy(13,55);
				system("pause");
				return;
			}
		
		
			case 9:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY NAO TRONG DANH SACH");
					return;
				}
			
				/////NGAY THANG NAM/////
				time_t baygio = time(0);
   				tm *ltm = localtime(&baygio);
   				int month = 1 + ltm->tm_mon;
   				int year = 1900 + ltm->tm_year;
				int Thang[12] = {31,CheckNamNhuan(year)?29:28,31,30,31,30,31,31,30,31,30,31};
				////////////////////////////////////////////////////////////////////////////
			
				Navbar4();//khung nhap ngay - thang - nam - san bay
				int ngay , thang , nam , sanbay;
			
				fflush(stdin);
				char *dayDepart = NhapNgayKhoiHanhCuaChuyenBay(2,Thang[month-1],49,16);//co th thay the Thang[month-1] = 28 - 29 - 30 - 31 de test
				if(dayDepart[0] == 'e')return;//da nhan phim ESC
				//////////////////////////////////////////////////////
				fflush(stdin);
				char *monthDepart = NhapThangKhoiHanhCuaChuyenBay(2,64,16);
				if(monthDepart[0] == 'e')return;//da nhan phim ESC
				////////////////////////////////////////////////////
				fflush(stdin);
				char *yearDepart = NhapNamKhoiHanhCuaChuyenBay(4,79,16);
				if(yearDepart[0] == 'e')return;//da nhan phim ESC
				////////////////////////////////////////////////////
				fflush(stdin);
				char *airport = NhapSanBayDenCuaChuyenBay(1,51,18);
				if(airport[0] == 'e')return;//da nhan phim ESC
				////////////////////////////////////////////////////
			
				ngay = atoi(dayDepart);
				thang = atoi(monthDepart);
				nam = atoi(yearDepart);
				sanbay = atoi(airport);

				ShowChuyenBay_Ngay_Thang_Nam_ConVe(listcb , ngay , thang , nam , sanbay);
				BoxMessage("DANH SACH CHUYEN BAY THEO THOI GIAN  - CON VE");
				delete dayDepart;
				delete monthDepart;
				delete yearDepart;
				delete airport;
				return;
			}
		
			case 27:
			BoxMessage("              EXIT MANAGER FLIGHT");
			return;
    	}
	}
}


/*----------------------------------CHUYEN BAY-----------------------------------*/


/*-------------SAVE HANH KHACH-----------------------*/
void Save_1HK(ofstream &fileout , copy_HANHKHACH hk)//cua mang tuyen tinh
{
	fileout << hk.CMND << ",";
	fileout << hk.ho << ",";
	fileout << hk.ten << ",";
	fileout << hk.gioiTinh;
}


void Save_DSHK(NODEHKPTR listhk , copy_DSHANHKHACH copy_listhk)
{
	ofstream fileout;
	fileout.open("DSHK.TXT",ios::out);
	CopyDataHK(listhk , copy_listhk);//de doc tu cay nhi phan tim kiem vao dstt
	for(int i = 0 ; i < copy_listhk.soHK ; i++)
	{
		Save_1HK(fileout , copy_listhk.nodeHK[i]);
		fileout << endl;
	}
}
/*-------------SAVE HANH KHACH-----------------------*/
/*----------------------------------VE-----------------------------------*/

void ShowHK_CMND(NODEHKPTR T, char CMND[])
{
	gotoxy(55,23);cout << KiemTraHK(T, CMND)->data.ho << " " << KiemTraHK(T, CMND)->data.ten;
	gotoxy(55,27);cout << KiemTraHK(T, CMND)->data.CMND;
	gotoxy(55,31);cout << gioiTinh[KiemTraHK(T, CMND)->data.gioiTinh - 1];
}


int CreatHK(NODEHKPTR &T, HANHKHACH &hk , CHUYENBAY &cb, int chonve)
{
	fflush(stdin);
	char *Ho = NhapHoTenHanhKhach(MAXHO-1,55,23);
	if(Ho[0] == 'e')return 0;//da nhan phim ESC
	strcpy(hk.ho,Ho);
	
	fflush(stdin);
	char *Ten = NhapHoTenHanhKhach(MAXTEN-1,55,26);
	if(Ten[0] == 'e')return 0;//da nhan phim ESC
	strcpy(hk.ten,Ten);
	
	fflush(stdin);
	char *CMND = NhapSoCMND(9,55,29);
	if(CMND[0] == 'e')return 0;//da nhan phim ESC
	strcpy(hk.CMND,CMND);
	
	////TAI BUOC TAO MOI 1 SO CMND VAO DSHK THI KIEM TRA XEM TRONG DSHK : NEU CO ROI THI KHONG HOP LE
	if(KiemTraHK(T,CMND) != NULL)
	{
		BoxSetColorConSole("NHAP SO CMND KHONG HOP LE");
		return 0;
	}
	
	
	///neu So CMND hop le thi tiep tuc thu hien tao moi
	fflush(stdin);
	char *GioiTinh  =NhapGioiTinh(1,55,34);
	hk.gioiTinh = atoi(GioiTinh);
	
	
	int choice = choice_YesNo();
	if(choice == 0)//YES
	{
		////them de check xem trang thai chuyen bay
		if(cb.staTus == 1)//tuc la chuyen bay dang o trang thai con ve
		{
			InsertHanhKhach(T, hk);
			stringstream ss;
			string target;
			ss << hk.CMND;//dua du lieu vao buffer cua 1 doi tuong
			ss >> target;//lay du lieu tu buffer cua doi tuong stringstream dua vao string
			//cout << target;
			cb.nodeVe[chonve-1] = target;//dua so CMND vao nodeVe cua CB
			return 1;
		}
		else return 0;
	}
	
	else if(choice == 1)//NO
	{
		return 0;
	}

}


void ShowVe_DatVe(CHUYENBAY &cb, NODEHKPTR &listhk)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (15 << 4) | 12);
	gotoxy(101,5);
	cout<<"                   "<<endl;
	gotoxy(101,6);
	cout<<"  VUI LONG CHON VE "<<endl;
	gotoxy(101,7);
	cout<<"                   "<<endl;
	
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
	for(int i = 5; i <= 46 ; i++)
	{
		gotoxy(100,i);printf("%c", 176);
	}
	
	int px = 101; int py = 8;
	for(int i = 0; i < cb.soluongVe; i++)
	{
		if(cb.nodeVe[i] == "0")
		{
			SetConsoleTextAttribute(consoleHandle, (10 << 4) | 0);
		}
		else if(cb.nodeVe[i] != "0")
		{
			SetConsoleTextAttribute(consoleHandle, ( 12 << 4) | 2);
		}
		/////
		if(i == 35)
		{
			px+=6;
			py = 8;
		}
		gotoxy(px,py);
		cout<<"Ve "<<i+1;py++;
	}


	Navbar5();
	fflush(stdin);
	gotoxy(60,14);
	char *sove = NhapSoVe(2,60,14);
	if(sove[0] == 'e')return;//da nhan phim ESC
	int chonve = atoi(sove);
	if( chonve <= 0 || chonve > cb.soluongVe)
	{
		delete sove;
		BoxSetColorConSole("CHON SO VE KHONG DUNG");
		return;
	}
		
			
	else if( cb.nodeVe[chonve-1] != "0" )
	{
		delete sove;
		BoxSetColorConSole("VE DA BI DAT");
		return;
	}
	
	
	else//nghia la so ve thich hop -> co the chon
	{
		//NHAP SO CMND DE TIM KIEM TRONG DANH SACH HANH KHACH
		Navbar6();
		fflush(stdin);
		char *soCMND_test = NhapSoCMND(9,55,16);
		if(soCMND_test[0] == 'e')
		{
			delete soCMND_test;
			return;  //da nhan phim ESC
		}

		int check_tontaiCMND = 0;
		for(int i = 0 ; i < cb.soluongVe ; i++)
		{
			const char* ve = (cb.nodeVe[i]).c_str();//chuyen kieu moi phan tu kieu string cua nodeVe ve char
			if(strcmp(ve,soCMND_test) == 0)
			check_tontaiCMND = 1;//co ton tai
		}
		
		if(check_tontaiCMND == 1)//da ton tai so CMND
		{
			delete soCMND_test;
			BoxSetColorConSole("KHONG DUOC DAT 2 VE TREN CB");
			return;
		}
		
		
		else if(check_tontaiCMND == 0)
		{//trong nodeVe cua chuyen bay chua co
			//////NEU NHU HANH KHACH DA CO TRONG DANH SACH HANH KHACH ROI -> SO CMND CO TON TAI TRONG DSHK NHUNG PHAI KIEM TRA XEM CO TON TAI TRONG (cb) dua len hay khong
			if(KiemTraHK(listhk,soCMND_test) != NULL)//da co hanh khach trong danh sach hanh khach
			{
				BoxXacNhanThongTinDatVe();
				ShowHK_CMND(listhk,soCMND_test);
				int choice = choice_YesNo();
				if(choice == 0)
				{
					if(cb.staTus == 1)//neu nhu chuyen bay dang o trang thai con ve
					{
						cb.nodeVe[chonve-1] = soCMND_test;//neu da co trong DSHK thi soCMND_test cung chinh la soCMND cua hanh khach do nen ta gan duoc
						/*them*/
						cb.soveduocdat += 1;
						BoxSetColorConSole("DAT VE THANH CONG");
						return;
					}
					else
					{
						delete soCMND_test;
						BoxSetColorConSole("DAT VE THAT BAI");
						return;
					}
				}
				else if(choice == 1)
				{
					delete soCMND_test;
					BoxSetColorConSole("HUY DAT VE");
					return;
				}
			}
		
		
			else if(KiemTraHK(listhk,soCMND_test) == NULL)///HANH KHACH CHUA CO TRONG DANH SACH
			{//thong tin chua co thi them vao danh sach
				HANHKHACH hk;
				BoxDienThongTinDatVe();
				int kq = CreatHK(listhk,hk,cb,chonve);
				if(kq == 1)
				{
					BoxSetColorConSole("DAT VE THANH CONG");
					/*them*/
					cb.soveduocdat += 1;
					return;
				}

				else if(kq == 0)
				{
					BoxSetColorConSole("DAT VE THAT BAI");
					return;
				}
			}
		}
	}
}


void DatVeMayBay(DSCHUYENBAY &listcb, NODEHKPTR &listhk)//listmb khong tham chieu vi chi can gui len dat ve so cho ngoi 
{
	///TIME////
	time_t baygio = time(0);
   	tm *ltm = localtime(&baygio);
   	int month = 1 + ltm->tm_mon;
   	int year = 1900 + ltm->tm_year;
	int Thang[12] = {31,CheckNamNhuan(year)?29:28,31,30,31,30,31,31,30,31,30,31};
	///TIME////
	
	BoxShowSanBay_DatVe();
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consoleHandle, (7 << 4) | 1);
	
	fflush(stdin);
	char *sanbayDen = NhapSanBayDenCuaChuyenBay(1,60,8);
	if(sanbayDen[0] == 'e')
	{
		delete sanbayDen;
		return;//da nhan phim ESC
	}

	int index = atoi(sanbayDen);
	
	fflush(stdin);
	char *dayDepart = NhapNgayKhoiHanhCuaChuyenBay(2,Thang[month-1],60,10);//co th thay the Thang[month-1] = 28 - 29 - 30 - 31 de test
	if(dayDepart[0] == 'e')
	{
		delete sanbayDen;
		delete dayDepart;
		return;//da nhan phim ESC
	}
	
	int ngaykhoihanh = atoi(dayDepart);
	
	//tao bien de so sanh san bay
	string temp1 = sanBay[index-1];
	
	//khi co san bay den va ngay dy thi chuong trinh tu dong tim kiem trong danh sach chuyen bay va de xuat cac chuyen bay tuong ung - neu khong thi thong bao khong co
	//tao 1 mang de chua cac MSCB tuong ung
	char mscb_temp[30][MAXMACHUYENBAY];
	int count = 0;
	for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
	{
		string temp2 = p->data.sanBay;
		if(temp1 == temp2 && (ngaykhoihanh == p->data.ngayDi) && p->data.staTus == 1)//chua lam them so sanh ngay di
		{//trung khop san bay / ngay di / trang thai con ve
			strcpy(mscb_temp[count], p->data.MSCB);count++;//neu so sanh san bay va ngay dy trong DSCB trung khop thi copy vao mang mscb_temp
		}
	}
	
	if(count == 0)//nghia la chua co chuyen bay nao tuong ung de de xuat (mang mscb khong copy duoc phan tu nao)
	{
		BoxMessage("KHONG TIM THAY CHUYEN BAY TUONG UNG");
		return;
	}
	
	
	BoxShowChuyenBayDeXuat();
	int pix = 122, piy = 8;
	for(int i = 0 ; i < count ; i++)
	{
		gotoxy(pix,piy);
		cout<<mscb_temp[i];piy++;
		gotoxy(pix,piy);
		cout<<"------------------"<<endl;
		piy++;
	}
	
	fflush(stdin);
	char *MSCB_temp = NhapMaChuyenBay(MAXMACHUYENBAY-1,52,12);
	if(MSCB_temp[0] == 'e')
	{
		delete MSCB_temp;
		return;//da nhan phim ESC
	}
	
	
	int check = 0;
	for(int i = 0 ; i < count ; i++)
	{
		if(strcmp(MSCB_temp,mscb_temp[i]) == 0)
		{
			check = 1;
			for(NODECB *p = listcb.pHead ; p != NULL ; p = p->pNext)
			{
				if(strcmp(MSCB_temp,p->data.MSCB) == 0)
				{
					ShowVe_DatVe(p->data,listhk);
					break;
				}
			}
		}
	}
	
	if(check == 0)
	{
		BoxSetColorConSole("NHAP KHONG CHINH XAC");
		return;
	}
	return;
}


/*----------------------------------VE-----------------------------------*/


/*-------------------------------HANH KHACH------------------------------*/



/*-------------LOAD HANH KHACH----------------------*/
void Read_1HK(ifstream &filein, HANHKHACH &hk)
{
	filein.getline(hk.CMND,MAXCMND,',');
	filein.getline(hk.ho, MAXHO, ',');
	filein.getline(hk.ten,MAXTEN,',');
	filein >> hk.gioiTinh;
	// tao bien tam de doc cac ky tu xuong dong o cuoi dong
	string temp;
	getline(filein, temp);
}


void Read_DSHK(ifstream &filein, NODEHKPTR &T)
{
	while(!filein.eof())
	{
		HANHKHACH hk;
		Read_1HK(filein,hk);
		if(hk.CMND[0] != NULL)//neu nhu doc ngay dau file ma co du lieu thi moi lam tiep
		{
			if(KiemTraHK(T,hk.CMND) == NULL)
			{
				InsertHanhKhach(T, hk);
			}
		}
	}
}
/*-------------LOAD HANH KHACH----------------------*/



void managerOther(NODEHKPTR &listhk)
{
	FrameOther();
	int chon;
	while(true)
	{
        chon = MenuDongOther(MenuOther);
        switch (chon)
		{
        	case 1:
			{
				if(listhk == NULL)
				{
					BoxMessage("    CHUA CO HANH KHACH TRONG DANH SACH");
					return;
				}
				XoaManHinh();
				DuyetDSHK(listhk);
				BoxMessage("    DUYET DANH SACH HANH KHACH THANH CONG");
				return;
			}
			
			case 2:
			{
				HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(consoleHandle, (7 << 4) | 5);
				Traverse();
				cout << endl <<endl;
				
				/*-------------NGAY THANG NAM------------*/
				time_t baygio = time(0);
   				tm *ltm = localtime(&baygio);
   				int day = ltm->tm_mday;//system day
   				int month = 1 + ltm->tm_mon;//system month
   				int year = 1900 + ltm->tm_year;//system year
				/*-------------NGAY THANG NAM------------*/
    			int time_exit = (year*100  + month) *100 + day;
    			cout<<"Time Now: " << time_exit<<endl;
				
				for(int i = 0 ; i < z ; i++)
				{
					cout<<MSCB_Depart[i] <<"("<<Time_CB_Depart[i]<<")" << endl;
				}
				BoxMessage("DUYET DANH SACH BUCKET THANH CONG");
//				system("pause>NULL");
				return;
			}

			case 27:
			{
				BoxMessage("EXIT MANAGER CUSTOMERS");
				return;
			}
    	}
	}
}

/*----------------------------------HANH KHACH-----------------------------------*/



/*-------------------------FOR THREAD-------------------------*/
void* BANNER(void *)
{
	while(true)
	{
		/*-------------NGAY THANG NAM------------*/
		time_t baygio = time(0);
   		tm *ltm = localtime(&baygio);
   		int day = ltm->tm_mday;//system day
   		int month = 1 + ltm->tm_mon;//system month
   		int year = 1900 + ltm->tm_year;//system year
		/*-------------NGAY THANG NAM------------*/
		
    	int time_exit = (year*100  + month) *100 + day;
    	/*-------------kiem tra het ve cua cac chuyen bay------------*/
    	for(NODECB *q = listcb.pHead ; q != NULL ; q = q->pNext)
    	{
    		if(Check_HetVe(q->data) == true && q->data.staTus != 0)
    		q->data.staTus = 2;//set ve het ve
		}
    	/*-------------kiem tra het ve cua cac chuyen bay------------*/
    	
    	for(int i = 0; i < z; i++)
    	{
    		if(time_exit >= Time_CB_Depart[i])
    		{
    			for(NODECB *k = listcb.pHead ; k != NULL ; k = k->pNext)
    			{
    				if(strcmp(k->data.MSCB,MSCB_Depart[i]) == 0 && k->data.staTus != 0 && k->data.staTus != 3)//trang thai huy chuyen khong can phai set ve h
    				{
    					//SET LAI TRANG THAI CHO CHUYEN BAY//
//    				    k->data.soluongVe = 0;
//    					k->data.nodeVe = NULL;//neu de lai cho nay thi khi xem DSHK cua chuyen bay thi cac node ve khong co gia tri CMND de ma tim kiem tu cay nhi phan de show ra ds
    					k->data.staTus = 3;
    					///////////////////////////////////
    					for(int i=0;i<listmb.soMB;i++)
    					{
    						if(strcmp(k->data.sohieumb,listmb.nodeMB[i].sohieuMB) == 0)
							{
								listmb.nodeMB[i].x = 1;//de thiet lap lai trang thai cho may bay do
								break;
							}
						}
					}
				}
			}
			
			else if(time_exit < Time_CB_Depart[i])
			{
				for(NODECB *k = listcb.pHead ; k != NULL ; k = k->pNext)
    			{
    				if(strcmp(k->data.MSCB,MSCB_Depart[i]) == 0 && k->data.staTus != 0 && k->data.staTus != 3)//cac chuyen bay o trang thai da huy chuyen khong can set lai gi het
    				{//ta co duoc MSCB//
    					for(int i=0;i<listmb.soMB;i++)
    					{
    						if(strcmp(k->data.sohieumb,listmb.nodeMB[i].sohieuMB) == 0)
							{//de thiet lap lai trang thai cho may bay do
								listmb.nodeMB[i].x = 0;
								break;
							}
						}
					}
				}
			}
		}
		Sleep(2000);
	}
}
/*-------------------------FOR THREAD-------------------------*/


/*----------------------------------MAIN-----------------------------------*/
int main()
{
   SetConsoleTitle("QUAN LY CHUYEN BAY");
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   resizeConsole(1200,750);
   
//  	VeChu();
//  	Show_banner_student();
   
   	//--------------------THREAD----------------------//
	pthread_t t;
	pthread_create(&t, NULL, BANNER, NULL); //Tao luong
	//-----------------------------------------------//
	
	/*------Init--------*/
	InitBucket();
	Init(listcb);
	InitTree(listhk);
	/*------------------*/
	
	/*-------LOAD DU LIEU TU FILE------*/
	ifstream filein1;
	ifstream filein2;
	ifstream filein3;
	
	filein1.open("DSMB.TXT", ios::in);//duoc Read truoc DSCB de Set trang thai cac may bay
	Read_DSMB(filein1,listmb);//MAYBAY
	
	filein2.open("DSCB.TXT",ios::in);
	Read_DSCB(filein2,listcb,listmb);//CHUYENBAY (them listmb de khi doc tu file co chuyen bay dang con ve thi thiet lap mb co SHMB trung voi CB ve Busy
	/*-------LOAD DU LIEU TU FILE------*/
	
	filein3.open("DSHK.TXT",ios::in);
	Read_DSHK(filein3,listhk);
	/*-------LOAD DU LIEU TU FILE------*/
	
///////////////////////////////////////////////
	int choice;
	while(true)
	{
		
		system("cls");
		ScreenApp();
		BoxShowAirPort();
    	
        choice = MenuMain(thucdon);
        switch (choice)
		{
			ScreenApp();
        
        	case 1:
			{
        		ScreenApp();
        		managerMB(listmb,listcb);
				break;
			}
       		case 2:
			{
        		ScreenApp();
        		managerCB(listcb,listmb,listhk);
				break;
			}

			case 3:
			{
				if(listcb.pHead == NULL)
				{
					BoxMessage("CHUA CO CHUYEN BAY TRONG DANH SACH");
					break;
				}
				else
				{
					DatVeMayBay(listcb,listhk);	
					/*----------MAC DINH KHI DAT VE SE LUU THAY DOI VAO FILE DE LOAD DATA CHUYEN BAY THANH CONG--------------*/
					Save_DSHK(listhk,copy_listhk);
					Save_DSCB(listcb);
					BoxMessage("                  SAVE SUCCESS      ");
					/*-----------------------*/
					break;
				}
			}
		
			case 4:
				{
					ScreenApp();
					managerOther(listhk);
					break;
				}
			
			case 27://ESC
			{
				BoxConfirmSaveFile();
				int choice = choice_YesNo();
				if(choice == 0)
				{
					/*---DSMB da duoc thay doi trong qua trinh quan ly---*/
					Save_DSMB(listmb);
					Save_DSCB(listcb);
					Save_DSHK(listhk,copy_listhk);
					BoxMessage("THOAT CHUONG TRINH - LUU DU LIEU");
				}
				else
				{
					BoxMessage("THOAT CHUONG TRINH - KHONG LUU DU LIEU");
				}
				return 0;
				break;
			}
    	}
	}

	closegraph();
	gotoxy(1,55);
	system("pause");
	return 0;
}

