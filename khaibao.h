#include <iostream>
#include <windows.h>//chua ham cls de clear man hinh
#include <string>
#include <string.h>//chua cac ham xu ly chuoi
#include <ctype.h>

#define MAXMAYBAY 15//toi da co 15 MB
#define MAXSOHIEU 16//de cho la 15 nhung vi mang char can co them 1 ky tu /0 (ket thuc chuoi) nen khai bao phai du 1
#define TYPEMB 16
#define MAXMACHUYENBAY 16

#define MAXHO 11
#define MAXTEN 16
#define MAXCMND 10

using namespace std;

/*----------------------MAY BAY-----------------------*/
struct maybay
{
	char sohieuMB[MAXSOHIEU];//khoa chinh - khong duoc trung nhau khi them vao
	char loaiMB[TYPEMB];
	int sochoMB;
	int x;//day la trang thai cua may bay: x = 1:san sang (cac chuyen bay co the update va xoa) x = 0: nguoc lai
};
typedef struct maybay MAYBAY;



struct dsmaybay
{
	int soMB = 0;
	MAYBAY nodeMB[MAXMAYBAY];//danh sach tuyen tinh cac may bay
};
typedef struct dsmaybay DSMAYBAY;

/*----------------------MAY BAY-----------------------*/





/*-------------------SUPPORT--------------------------*/
char MSCB_Depart[50][MAXMACHUYENBAY];//toi da 100 chuyen bay duoc tao va luu MSCB de check Time_Action cho chuyen bay
int Time_CB_Depart[50];//toi da 50 chuyen bay duoc tao va se co 100 nut thoi gian de set ve trang thai chuyen bay hoan tat
int z = 0;//cho chuyen bay dau tien - cu 1 chuyen bay duoc khoi tao thi z++;
/*-------------------SUPPORT--------------------------*/

/*----------------------CHUYEN BAY-----------------------*/
//char sanBay[5][15] = {"HO CHI MINH","PHU QUOC","NHA TRANG","HA NOI","CAN THO"};//diem den cua cac chuyen bay la co dinh , nen dat trong 1 mang co dinh , va khi chon diem den ta chi can chon chi so (vd: index) - khi show ra diem den thi: sanBay[index];
string sanBay[5] = {"HO CHI MINH","PHU QUOC","NHA TRANG","HA NOI","CAN THO"};
char staTus[4][15] = {"huy chuyen","con ve","het ve","hoan tat"};
struct chuyenbay
{
	char MSCB[MAXMACHUYENBAY];//khoa chinh - khong duoc trung nhau khi them vao
	int ngayDi;
	int thangDi;
	int namDi;
	int gioDi;
	string sanBay;
	int staTus;
	char sohieumb[MAXSOHIEU];
	int soluongVe;
	string *nodeVe;//nut ve la mot mang de chua DSCMND cua hanh khach / chi so la so ve, gia tri la CMND - khi tao 1 chuyen bay thi
	int soveduocdat;//them de test
};
typedef struct chuyenbay CHUYENBAY;

struct node
{
	CHUYENBAY data;
	struct node *pNext;
};
typedef struct node NODECB;


struct dschuyenbay
{
	NODECB *pHead;
	NODECB *pTail;
};
typedef struct dschuyenbay DSCHUYENBAY;

void Init(DSCHUYENBAY &l)
{
	l.pHead = l.pTail = NULL;
}
NODECB* GetNode(CHUYENBAY cb)
{
	NODECB *p = new NODECB;

	if(p == NULL)
	{
		return NULL;
	}
	p->data = cb;
	p ->pNext = NULL; // khoi tao moi lien ket
	return p;
}
/*----------------------CHUYEN BAY-----------------------*/


/*----------------------HANH KHACH-----------------------*/
/*-----CAY NHI PHAN TIM KIEM LUU TRU CAC PHAN TU KHONG TRUNG NHAU------*/
char gioiTinh[3][5] = {"NAM","NU","khac"};
struct hanhkhach
{
	char CMND[MAXCMND];
	char ho[MAXHO];
	char ten[MAXTEN];
	int gioiTinh;
};
typedef struct hanhkhach HANHKHACH;

struct nodeHK
{
	HANHKHACH data;
	nodeHK *Left;
	nodeHK *Right;
};
typedef struct nodeHK NODEHK;
typedef NODEHK* NODEHKPTR;

void InitTree(NODEHKPTR &Root)
{
	Root = NULL;//cay rong
}
/*----------------------HANH KHACH-----------------------*/
///khai bao tuong minh
NODEHKPTR KiemTraHK(NODEHKPTR p, char CMND[]);




/*----------------------To Save DSHK-----------------------*/
struct copy_hanhkhach
{
	char CMND[MAXCMND];
	char ho[MAXHO];
	char ten[MAXTEN];
	int gioiTinh;
};
typedef struct copy_hanhkhach copy_HANHKHACH;



typedef struct copy_DSHANHKHACH
{
	int soHK = 0;
	copy_HANHKHACH nodeHK[200];//mang tuyen tinh cac hanh khach
};
/*----------------------To Save DSHK-----------------------*/




/*-----chuc nang nay dang lam rieng cho viec luu du lieu hanh khach---*/
void CopyDataHK(NODEHKPTR listhk , copy_DSHANHKHACH &copy_listhk)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
{
    if(listhk!=NULL)
    {
      CopyDataHK(listhk->Left , copy_listhk);
      
      //////sao chep du lieu hanh khach tu cay nhi phan tim kiem sang mang tuyen tinh (DSHK) tam thoi
      strcpy(copy_listhk.nodeHK[copy_listhk.soHK].CMND,listhk->data.CMND);
      strcpy(copy_listhk.nodeHK[copy_listhk.soHK].ho,listhk->data.ho);
      strcpy(copy_listhk.nodeHK[copy_listhk.soHK].ten,listhk->data.ten);
      copy_listhk.nodeHK[copy_listhk.soHK].gioiTinh = listhk->data.gioiTinh;
      copy_listhk.soHK++;
      
      CopyDataHK(listhk->Right , copy_listhk);
    }
}



void DuyetDSHK(NODEHKPTR listhk)//SHOW TAT CAC CAC HANH KHACH CO TRONG DANH SACH
{
     if(listhk!=NULL)
     {
      DuyetDSHK(listhk->Left);
      ///show thong tin
      cout<<listhk->data.CMND<<endl;
      cout<<listhk->data.ho<<" "<<listhk->data.ten<<endl;
      cout<<listhk->data.gioiTinh<<endl;
      
      DuyetDSHK(listhk->Right);
     }
}



void InsertHanhKhach(NODEHKPTR &T,HANHKHACH hk)
{//theo kieu LNR
	//chen mot node vao cay
	if(T == NULL)
	{
		NODEHK *p = new NODEHK;
		strcpy(p->data.CMND,hk.CMND);
		strcpy(p->data.ho,hk.ho);
		strcpy(p->data.ten,hk.ten);
		p->data.gioiTinh = hk.gioiTinh;
		p->Left = NULL;
		p->Right = NULL;
		T = p;//T cung la mot NODEHK va p cung la mot NODEHK
	}
	
	else
	{//TREE co ton tai phan tu
		if(strcmp(T->data.CMND,hk.CMND) > 0)
		{
			return InsertHanhKhach(T->Left,hk);//chen vao node trai
		}
		else if(strcmp(T->data.CMND,hk.CMND) < 0)
		{
			return InsertHanhKhach(T->Right,hk);//chen voo node phai
		}
	}
}



/*-------------------KIEM TRA TON TAI HANH KHACH BANG CMND----------------*/
NODEHKPTR KiemTraHK(NODEHKPTR T, char soCMND[])//tra ve mot NODE *
{
	if(T == NULL)
	{
		return NULL;
	}
	else
	{
		if(strcmp(T->data.CMND, soCMND) > 0)
		{
			KiemTraHK(T->Left, soCMND);
		}
		
		else if(strcmp(T->data.CMND, soCMND) < 0)
		{
			KiemTraHK(T->Right, soCMND);
		}
		
		else //T->data.CMND == CMND -> tim thay
		return T;
	}
}
/*-------------------KIEM TRA TON TAI HANH KHACH BANG CMND----------------*/


/*-----------------KHAI BAO CHINH----------------*/
DSMAYBAY listmb;
DSCHUYENBAY listcb;
NODEHKPTR listhk;
copy_DSHANHKHACH copy_listhk;//de luu danh sach hanh khach
/*-----------------------------------------------*/

