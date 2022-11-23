#include<iostream>
#define Max 15
using namespace std;
typedef struct Cell *List;	 //Tao ra con tro List co kieu la Cell (Node)
struct Cell						
{
	int val;		
	List next;			// next la kieu List va next la con tro
};
typedef List Table[Max];			//Mang con tro 
Table T;
int size;				
void Initial(Table &T, int &size)		
{
	for(int i=0;i<size;i++)
	{
		T[i]=NULL;
	}
}
void Insert(List &L, int k)
{
	List p=new (Cell);				//Khai bao 1 phan tu kieu Cell
	p->val=k;
	p->next=L;						//Chen node vao dau danh sach
	L=p;
}
List Search(List L, int k)
{
	List x=L;
	while(x!=NULL&&x->val!=k)
	{
		x=x->next;
	}
	return x;
}
void Delete(List &L, int k)		//Tim va xoa
{
	if(L!=NULL)
	{
		List x=L, y=NULL;
		while(x!=NULL&&x->val!=k)
		{
			x=x->next;
			y=x;
		}
		if(x!=NULL)
		{
			if(y==NULL)
				L=x->next;
			else
			{
				y->next=x->next;
				delete x;
			}
		}
	}
}
int Hash(int k, int size)
{
	return k%size;		//Lay phan du
}
void HashInsert(Table &T, int size, int k)
{
	Insert(T[Hash(k,size)],k);
}
void INP(Table &T, int size)
{
	int k;
	for(int i=0;i<size;i++)
	{
		cout<<"Nhap k ";
		cin>>k;
		HashInsert(T,size,k);		//Chen 1 gia tri k vao Hash 
	}
}
List HashSearch(Table T, int search, int size)
{
	return Search(T[Hash(search,size)],search);
}
void HashDelete(Table &T, int size, int k)
{
	Delete(T[Hash(k,size)],k);
}
int main()
{
	char c;
	while(true)
	{
		cout<<endl<<"Chon a de tao HashTable "<<endl;
		cout<<"Chon b de tim kiem "<<endl;
		cout<<"Chon con lai de xoa "<<endl;
		cin>>c;
		switch (c)
		{
			case 'a':
			{
				int size;
				cout<<"Nhap size ";	cin>>size;
				INP(T,size);
				break;
			}
			case 'b':
			{
				int search, size;
				cout<<"Nhap size ";	cin>>size;
				cout<<"Nhap so can tim ";	cin>>search;
				List res=HashSearch(T, search, size);
				cout<<res->val;
				break;
			}
			default:
			{
				int del, size;
				cout<<"Nhap size ";	cin>>size;
				cout<<"Nhap so can xoa ";	cin>>del;
				HashDelete(T, del, size);
				break;
			}
		}
	}
}
