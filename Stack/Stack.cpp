#include<iostream>
#define Max 8
//LIFO
using namespace std;
int top=-1;
int Stack[Max];		//Declare as global variable
bool isfull()
{
	if(top == Max-1)
	return true;
	else
	return false;
	
}
bool isempty()
{
	if(top==-1)
	return true;
	else
	return false;
}
void Push(int data)
{
	if(!isfull())
	{
		top+=1;
		Stack[top]=data;
	}
	else
	cout<<"Stack is full !";
}
int Pop()
{
	int data;
	if(!isempty())
	{
		data=Stack[top];
		top-=1;
		return data;
	}
	else
	cout<<"Stack is empty !";
}
int max()		//Dung Pop de tim phan tu max
{
	int get, max=0;
	while(!isempty())
	{
		get=Pop();
		if(max<get)
			max=get;
	}
	return max;
}
int min()
{
	int get, min;
	if(!isempty())
	{
		min=Stack[top];
		while(!isempty())
		{
				get=Pop();
			if(min>get)
				min=get;
		}
	}
	return min;
}
int sum()		//Dung Pop de tim tong
{
	int get, sum=0;
	while(!isempty())
	{
		get=Pop();
		sum+=get;
	}
	return sum;
}
int main()
{
	int data;
	while(!isfull())
	{
		cout<<"Nhap data: ";
		cin>>data;
		Push(data);
	}
	while(!isempty())
	{
		cout<<Pop()<<" ";
	}
	//cout<<max();		//Do 2 ham tren dung Pop de tim kq, ma Pop chi su dung 1 lan, nen su dung 1 trong 2 ham nay
	//cout<<min();
	//cout<<endl<<sum();
}
