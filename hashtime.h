#include <iostream>//chua cac ham nhap xuat cout cin
#include <stdlib.h>//chua ham system("pause"), neu code bang visual thi them thu vien nay vao
#include <ctime>//tra ve thoi gian hien tai tren he thong

#define LIMIT 31
using namespace std;

/*---------------KHAI BAI-------------------*/
typedef struct TimeSet
{
	int ngaydi;
	int thangdi;
	int namdi;
	int giodi;
	int sanbay;
}TimeSetFlight;

typedef struct NodeTime
{
	TimeSetFlight data;
	NodeTime *Next;
};


NodeTime* CreateNodeTime(int ngaydi, int thangdi, int namdi, int giodi, int sanbay)
{
	NodeTime *t = new NodeTime;
	if(t == NULL)
	{
		cout<<"Khong Du Bo Nho De Cap Phat!!!"<<endl;system("pause");
		return NULL;
	}
	else
	{
		t->data.ngaydi = ngaydi;
		t->data.thangdi = thangdi;
		t->data.namdi = namdi;
		t->data.giodi = giodi;
		t->data.sanbay = sanbay;
		t->Next = NULL;
		return t;
	}
}

typedef struct Hash
{
	NodeTime *Head;
	NodeTime *Tail;
}HashTime;
/*---------------KHAI BAO-------------------*/


/*-------KHOI TAO HASHTIME-------*/
HashTime *Bucket = new HashTime[LIMIT];
/*-------KHOI TAO HASHTIME-------*/


/*--------------------THAO TAC VOI CAC BUCKET------------------------*/

void DeleteHeadBucket(int b)
{
	if(Bucket[b].Head != NULL)
	{
		if(Bucket[b].Head == Bucket[b].Tail)//chi co 1 NodeTime duy nhat
		{
			Bucket[b].Head = Bucket[b].Tail = NULL;
		}
		else
		{
			NodeTime *temp = Bucket[b].Head;
			Bucket[b].Head = Bucket[b].Head->Next;
			delete temp;
		}
	}
}

void DeleteTailBucket(int b)
{
	if(Bucket[b].Head != NULL)
	{
		if(Bucket[b].Head == Bucket[b].Tail)
		{
			Bucket[b].Head = Bucket[b].Tail = NULL;
		}
		else
		{
			for(NodeTime *k = Bucket[b].Head ; k != NULL ; k = k->Next)
			{
				if(k->Next == Bucket[b].Tail)//dang tro toi Node Cuoi cung
				{
					NodeTime *temp = Bucket[b].Tail;
					Bucket[b].Tail = k;
					k->Next = NULL;
					delete temp;
					break;
				}
			}
		}
	}
}



void DeleteNodeTime(int ngaydi , int thangdi , int namdi , int giodi , int sanbay)//san bay duoc chuyen kieu thanh int tu mang sanBay de sosanh
{
	if(Bucket[ngaydi].Head->data.ngaydi == ngaydi && Bucket[ngaydi].Head->data.thangdi == thangdi && Bucket[ngaydi].Head->data.namdi == namdi && Bucket[ngaydi].Head->data.giodi == giodi && Bucket[ngaydi].Head->data.sanbay == sanbay)
	{
		DeleteHeadBucket(ngaydi);
	}
	
	else if(Bucket[ngaydi].Tail->data.ngaydi == ngaydi && Bucket[ngaydi].Tail->data.thangdi == thangdi && Bucket[ngaydi].Tail->data.namdi == namdi && Bucket[ngaydi].Tail->data.giodi == giodi && Bucket[ngaydi].Tail->data.sanbay == sanbay)
	{
		DeleteTailBucket(ngaydi);
	}
	else
	{
		for(NodeTime *a = Bucket[ngaydi].Head ; a != NULL ; a = a->Next)
		{
			NodeTime *temp = a->Next;
			if(temp->data.ngaydi == ngaydi && temp->data.thangdi == thangdi && temp->data.namdi == namdi && temp->data.giodi == giodi && temp->data.sanbay == sanbay)
			{
				a->Next = temp->Next;
				delete temp;
				break;
			}
		}
	}
}



void InsertNodeTime(NodeTime *q, int ngaydi)//them vao cuoi
{
	if(Bucket[ngaydi].Head == NULL)
	{
		Bucket[ngaydi].Head = Bucket[ngaydi].Tail = q;
	}
	else
	{
		Bucket[ngaydi].Tail->Next = q;
		Bucket[ngaydi].Tail = q;
	}
}


void TraverseBuket(int b)
{
    NodeTime *a = Bucket[b].Head;
    if(a == NULL)
    {
    	cout<<"Non NodeTime This Bucket";
    	return;
	}
	else
	{
		for(NodeTime *a = Bucket[b].Head ; a != NULL ; a = a->Next)
		{
			cout<<a->data.ngaydi<<"-"<<a->data.thangdi<<"-"<<a->data.namdi<<"-"<<a->data.giodi<<"-"<<sanBay[a->data.sanbay]<<"   ";
		}
	}
}

void Traverse(){
	int x = 13; int y = 52;
	gotoxy(x,y);
    for (int b = 1 ; b <= LIMIT ; b++)
    {
    	gotoxy(x,y);
        cout << "BUCKET DAY "<<b<<" : ";
        TraverseBuket(b);
        y++;
    }
    return;
}


bool SearchNodeTime(int ngaydi, int thangdi, int namdi, int giodi, int sanbay){
    for(NodeTime *q = Bucket[ngaydi].Head; q != NULL ; q =q->Next){
    	if(q->data.ngaydi == ngaydi && q->data.thangdi == thangdi && q->data.namdi == namdi && q->data.giodi == giodi && q->data.sanbay == sanbay)
    	return true;
	}
	return false;
}
/*--------------------THAO TAC VOI CAC BUCKET------------------------*/


void InitBucket()
{
	for(int i = 1 ; i <= LIMIT ; i++)
	{
		Bucket[i].Head = NULL;
		Bucket[i].Tail = NULL;
	}
}
