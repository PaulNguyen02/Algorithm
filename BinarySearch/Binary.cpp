#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) //Ham nay tra ve chi muc (vi tri)
{
	//Goi l la ban dau, r la cuoi
  if (r >= l) 
  {
    int mid = l + (r - l) / 2;  				// Ap dung cong thuc tim chi muc giua 
    if (arr[mid] == x)							//Neu x can tim bang voi phan tu giua
      return mid;								//Tra ve chi muc giua (vi tri cua pt do trong mang)
    if (x < arr[mid])							//Neu x do be hon pt giua 
      return binarySearch(arr, l, mid - 1, x); 	//Goi lai ham de quy de chay lai mang trai
      else
      return binarySearch(arr, mid + 1, r, x);	//Goi lai ham de quy de chay lai mang phai
  }
  else
  return -1;
}
int main()
{
  int arr[] = {2, 3, 4, 10, 40};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 10;
  int result = binarySearch(arr, 0, n - 1, x);
  if (result == -1)
    cout<<x<<" xuat hien tai chi so "<< result;
  else
    cout<<x<<" xuat hien tai chi so "<< result;
}
