#include<iostream>
using namespace std;
void INP(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]=";	cin>>a[i];
	}
}
void insertionSort(int a[], int n)
{	
	int tempkey;		
	for(int i=1;i<n-1;i++)
	{
		tempkey=a[i];			//bien nay dung de luu gia tri tam thu i 
		int j=i-1;				//vi tri truoc vi tri i
		while(j>=0&&a[j]>tempkey)		//Neu tempkey be hon cai truoc no
		{
			a[j+1]=a[j];		//Don pt phia sau len
			j--;				//Giam j va so sanh tiep voi key hien tai, neu thoa dk vong lap se tiep tuc don len
		}
		a[j+1]=tempkey;		//Neu thoat ra khoi vong lap thi truoc vi tri j-- se gan cho tempkey
	}	
}
void printArray(int a[], int n)
{
   for (int i = 0; i < n; i++)
    {
       	cout<<" "<<a[i];
	}
}
int main()
{
    int a[10],n;
    cout<<"Nhap n ";
    cin>>n;
    INP(a,n);
    insertionSort(a, n);
    cout<<"Sorted array:"<<endl;
    printArray(a, n);
}
