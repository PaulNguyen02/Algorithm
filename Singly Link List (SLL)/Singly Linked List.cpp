#include<iostream>
using namespace std;
typedef struct Cell *List;	 //Tao ra con tro List co kieu la Cell (Node)
struct Cell						
{
	int val;		
	List next;			// next la kieu List va next la con tro
};
List L;  				
void Initial(List &L)		
{
	L=NULL; 				//Khoi tao 1 danh sach rong (trong do Node dau rong)
}
void Insert(List &L, int k)
{
	List p=new (Cell);				//Khai bao 1 phan tu kieu Cell
	p->val=k;
	p->next=L;						//Chen node vao dau danh sach
	L=p;
}
void INP(List &L)
{
	int n,k;
	cout<<"Nhap n";	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap k ";
		cin>>k;
		Insert(L,k);
	}
}
void OUTP(List L)
{
	List x=L;
	for(;x!=NULL;x=x->next)
	{
		cout<<" "<<x->val;
	}
}
List Search(List L)
{
	int k;
	cout<<"Nhap k can tim";
	cin>>k;
	List x;
	x=L;
	while(x!=NULL && x->val!=k)
	{
		x=x->next;	
	}
	return x;
}
void Delete(List &L, int k)
{
	if(L!= NULL)
	{
		List x=L, y=NULL;				//x la node current, x la node the mang de duyet ds, y la node truoc do
		while(x!=NULL && x->val!=k)		//Duyet dslk khi chua tim thay k
		{
			y=x; 				
			x=x->next;
		} 			
		if(x!=NULL) 			//Neu tim thay
		{
			if(y==NULL) 		//Neu doi tuong can xoa nam o dau dslk
			L=x->next; 			//Xoa dau
			else 	
			y->next=x->next; 	
			delete(x); 
		}
	}
}
List Min(List L)		//Bai 7
{
	List x=L, min=x;
	for(;x!=NULL;x=x->next)
	{
		if(min->val>x->val)
		{
			min=x;
		}
	}
	return min;
}
List Evenmax(List L)			//Cau 8
{
	List x=L, max=x;
	for(;x!=NULL;x=x->next)
	{
		if(x->val%2==0 && max->val < x->val)
		{
			max=x;
		}
	}
	return max;
}
void C9(List &L)
{
	List x,y;
	if(L!=NULL)
	{
		x=L;						//Gan x=L
		while(x!=NULL)
		{
			if(x->val%2==0)
			{
				y=x;				// Di chuyen con tro x va y len 1 bac
				x=x->next;
				Delete(L, y->val);		//Thuc hien xoa y
			}
			else
			{
				y=x;		
				x=x->next;		// Tiep tuc di chuyen con tro x va y len 1 bac
			}
		}
	}
}
int OddSum(List L)		//Tinh tong pt le (C11)
{
	int sum=0;
	for(;L!=NULL;L=L->next)
	{
		if(L->val%2==1)
		{
			sum+=L->val;
		}
	}
	return sum;
}
List DelNext(List L, List p)		//B10 C1
{
	List x;
	x=L;
	while(x!=NULL && x!=p)
	x=x->next;
	if(x==p)
		if(x->next!=NULL)
		{
			x=x->next;
			p->next=x->next;
			delete(x);
		}
}
List Delnext1(List &L, int k)
{
	Cell *p=new Cell;
	List x;
	x=L;
	while(x!=NULL && x->val!=k)
	x=x->next;
	if(x!=NULL)
	if(x->next!=NULL)
	{
		p=x;
		x=x->next;
		p->next=x->next;
		delete(x);
	}
}
int C12(List L)
{
	int sum=0;
	for(;L!=NULL;L=L->next)
	{
		if(L->val%2==0 && L->val%3==0)
		{
			sum+=L->val;
		}
	}
	return sum;
}
void Addtail(List &L, int k)			//Cau 13
{
	List x=L, p=new (Cell);
	p->val=k;
	p->next=NULL;
	if(L==NULL)
		L=p;			//Neu ds rong (head=NULL), thi gan head chinh la p
	else
	{
		while(x->next!=NULL)	//	
		{
			x=x->next;
		}	
		x->next=p;
	}
}
void INP1(List &L)
{
	int n,k;
	cout<<"Nhap n";	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap k ";
		cin>>k;
		Addtail(L,k);
	}
}
int main()
{
	cout<<endl<<"1. Nhap DSLK"<<endl;
	cout<<"2. Duyet DSLK"<<endl;
	cout<<"3. Tim kiem trong DSLK"<<endl;
	cout<<"4. Xoa 1 node khoi DSLK"<<endl;
	cout<<"5. Tim phan tu co gia tri nho nhat"<<endl;
	cout<<"6. Tim so chan nho nhat DSLK"<<endl;
	cout<<"7. Thuc hien cau 9"<<endl;
	cout<<"8. Thuc hien cau 11"<<endl;
	cout<<"9. Thuc hien cau 12"<<endl;
	cout<<"10. Thuc hien cau 13";
	int choice,k;
	do {
		cout<<endl<<"Moi chon so:"<<endl;
		cin>>choice;
		switch(choice) {
			case 1:
				{
					INP(L);
					break;
				}
			case 2:
				{
					OUTP(L);
					break;
				}
			case 3:
				{
					List a=Search(L);
					int *p=&a->val;
					cout<<"Gia tri "<<a->val<<" nam tai vi tri "<<p<<" tren bo nho";
					break;
				}
			case 4:
				{
					int k;
					cout<<"Nhap k can xoa";
					cin>>k;
					Delete(L,k);
					 break;
				}
			case 5:		//C7
				{
					List p=Min(L);
					cout<<p->val;
					break;
				}
			case 6:		//C8
				{
					List p=Evenmax(L);
					cout<<p->val;
					break;
				}
			case 7:				
				{	
					C9(L);	//C9	
					break;
				}
			case 8:				//C11
				{
					cout<<OddSum(L);
					break;
				}
			case 9:			//C12
				{
					cout<<C12(L);
					break;
				}	
			case 10:
				{
					INP1(L);	//C13
					break;	
				}
		}
	} while (true);
}
