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
	for(int i=0;i<n-1;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i]>a[j])
		Swap(a[i],a[j]);
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
