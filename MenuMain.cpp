#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "mylib.h"


using namespace std;



const int so_item_main = 5;
const int dong =5;
const int cot = 30;
const int Up = 72;
const int Down = 80;
char thucdon [so_item_main][50] = {"||> QUAN LY MAY BAY       ",
			                  		   "||> QUAN LY CHUYEN BAY    ",
			                           "||> QUAN LY HANH KHACH    ",
			                           "||> DAT VE                ",
			                           "||> ESC                   "};




void Normal () {
	SetColor(WHITE);
	SetBGColor(8);
}
void HighLight () {
	SetColor(15);
	SetBGColor(3);
}



int MenuDong(char td [so_item_main][50])
{
  Normal();
  system("cls");
  int chon = 0;
  int i;
  for ( i=0; i< so_item_main ; i++)
  { gotoxy(cot, dong +i);
    cout << td[i];
  }
  HighLight();
  gotoxy(cot,dong+chon);
  cout << td[chon];
  char kytu;
  
do {
  kytu = getch();
  if (kytu==0) kytu = getch();
  switch (kytu) {
    case Up :if (chon+1 >1)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon --;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case Down :if (chon+1 <so_item_main)
  			  {
  		        Normal();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
              	chon ++;
              	HighLight();
              	gotoxy(cot,dong+chon);
              	cout << td[chon];
  				
  			  }
  			  break;
  	case 13 : return chon+1;
  }  // end switch
  } while (1);
}



void showmaybay()
{
	cout<<"May bay"<<endl;
	system("pause");
}

void showchuyenbay()
{
	cout<<"cHUYEN bay 111"<<endl;
	system("pause");
}



