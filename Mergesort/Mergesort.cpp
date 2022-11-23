#include<iostream>
using namespace std;
void Merge(int a[], int left, int mid, int right)
{
	int n1=mid-left+1;		//So luong phan tu cua mang con trai
	int n2=right-mid;		//So luong phan tu cua mang con phai
	int L[n1], R[n2];
	for(int i=0;i<n1;i++)
		L[i]=a[left+i];
	for(int j=0;j<n2;j++)
		R[j]=a[mid+1+j];
		
	int i=0,j=0, k=left;				//Khoi tao chi so bat dau cua mang luu ket qua, bat sau tu ngoai cung (left)
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
		k++;
	}
	/* Copy cac phan tu con lai cua mang L vào a (neu có) */
	while(i<n1)
	{
		a[k]=L[i];	
		k++;
		i++;
	}
	/* Copy cac phan tu con lai cua mang R vào a (neu có) */
	while (j < n2)
    {
        a[k] = R[j];
        k++;
        j++;
    }
}
/* left là chi so trai và right la chi so phai cua mang can duoc sap xep */
void MergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;		//Chi doi mang nhu tim kiem nhi phan 
        MergeSort(a, left, mid);	//Goi ham de quy chi doi mang trai
        MergeSort(a, mid+1, right); //Goi ham de quy chi doi mang phai
 
        Merge(a, left, mid, right);
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
	int a[]={10,80,30,90,40,50,70};
	int n= sizeof(a)/sizeof(a[0]);
	MergeSort(a,0,n-1);
	Print(a,n);
}
