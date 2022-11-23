#include <stdio.h>
using namespace std;
void swap(int &b, int &c)
{
    int temp = b;
    b=c;
    c= temp;
}
void selectionSort(int a[], int n)
{
    int min;	
    for (int i = 0; i < n-1; i++)
    {
    // min bang voi dia chi hien hanh
    		min = i;
    	for(int j = i+1; j < n; j++)	//chay tu i+1 den < n
		{
			if (a[min] > a[j])				//Tim ra gia tri be nhat trong day
        	  min = j;					//lay min gan voi dia chi phan tu nho nhat
		}	
		swap(a[min], a[i]); 	// Ðoi cho phan tu nho nhat voi phan tu hien hanh
    }
}

void selectionSort1(int a[], int n)
{
    int min;	//Chi so nho nhat trong day hien hanh
    for (int i = 0; i < n-1; i++)
    {
    // Tìm phan tu nho nhat trong mang chua sap xep
    	for(int j = i+1; j < n; j++)
			if (a[j] < a[i])
        swap(a[j], a[i]); 	// Ðoi cho phan tu nho nhat voi phan tu dau tiên
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a)/sizeof(a[0]);
    selectionSort1(a, n);
    printf("Sorted array: \n");
    printArray(a, n);
}
