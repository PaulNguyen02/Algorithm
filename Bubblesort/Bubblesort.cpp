#include<iostream>
using namespace std;
void INP(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i<<"]=";	cin>>a[i];
	}
}
void Swap(int &b, int &c)
{
	int temp=b;
	b=c;
	c=temp;
}
void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)		//i nhay len 1 dv, tam dung cho vong lap trong lap
	{
		for (int j = n - 1; j > i; j--)		//vong lap nay dung de sap xep, duyet theo tu ngoai vao trong
		{
			if(a[j-1]>a[j])
			Swap(a[j-1],a[j]);
		}
	}
}
void Print(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
}
int main()
{
	int a[10],n;
	cout<<"Nhap n";	cin>>n;
	INP(a,n);
	BubbleSort(a,n);
	Print(a,n);
}
