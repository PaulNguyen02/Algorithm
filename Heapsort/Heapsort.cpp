#include <iostream>
using namespace std;
void Swap(int &b, int &c)
{
	int temp=b;
	b=c;
	c=temp;	
}
// Ham nay dung de maxheap
void MaxHeapify(int arr[], int n, int i)
{
    int root = i; // Khoi tao root
    int left = 2 * i + 1;   // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2
 
    // Neu root con ben phai lon hon root (cha)
    if (left < n && arr[left] > arr[root])
        root = left;
 
    // Neu root con ben phai be hon root (cha)
    if (right < n && arr[right] > arr[root])
        root = right;
 
    if (root != i) {
        Swap(arr[i], arr[root]);
        // De quy cho cac cay con lai chua maxheap tro thanh maxheap
        MaxHeapify(arr, n, root);
    }
}
 
// Ham nay dung de sap xep tren heap 
void HeapSort(int arr[], int n)
{
    // Bien doi cac cay thanh maxheap
    for (int i = n / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, n, i);
 
    // Vong lap nay se thuc hien sau khi cay la maxheap   
    for (int i = n - 1; i > 0; i--) {
        //   hoan vi phan tu dau va phan tu cuoi
        Swap(arr[0], arr[i]);
 
        // Goi tiep ham maxheap khi kich thuoc cua cay da giam
        MaxHeapify(arr, i, 0);
    }
}
 
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
int main()
{
	int b,c;
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    HeapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}
