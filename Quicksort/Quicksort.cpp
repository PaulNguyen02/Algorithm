#include<iostream>
using namespace std;
void Swap(int &b, int &c)
{
	int temp=b;
	b=c;
	c=temp;
}
int Partition(int a[], int low, int high)
{
	int pivot=a[high];			//Chon phan tu cuoi cung lam goc
	int left=low;				//Chi muc trai cung
	int right=high-1;			//Chi muc gan cuôi
	while(true)
	{
		while(left<=right && a[left]<pivot)
		left++;
		while(left<=right && a[right]>pivot)
		right--;
		if(left <= right)			//Neu  left be hon right thi doi cho va tang left, giam right di
		{
			Swap(a[left],a[right]);
			left++;
			right--;
		}
		else
		break;
	}
	Swap(a[left], a[high]);					//Doi phan tu cuoi cho phan tu cua left
	return left;							//Va chon phan tu left la goc de chia ra
}
int Quicksort(int a[], int low, int high)
{
	if(low<high)
	{
		int mid=Partition(a,low,high);			//Se khong chon phan tu mid 
		Quicksort(a,low,mid-1);					//De quy qua trai/phai khien tat ca phan tu thanh pivot la mang duoc sap xep
		Quicksort(a,mid+1,high);
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
	int b,c;
	int a[]={35,33,42,10,14,19,27,44,26,31};
	int n=sizeof(a)/sizeof(a[0]);
	Quicksort(a,0,n-1);
	Print(a,n);
}
