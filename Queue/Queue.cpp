#include<iostream>
#define MAX 6
using namespace std;
struct Node
{
	int data;
	Node *next;	
};
typedef struct Node *queue;
bool isempty(queue q)
{
	if(q==NULL)
	return true;
	else
	return false;
}
Node *create(int data)
{
	Node *p=new Node;
	if(p==NULL)
	{
		return p;	
	}
	p->next=NULL;
	p->data=data;
}
void Enqueue(queue &q, int data)
{
	Node *p=create(data);
	if(q==NULL)
	{
		q=p;
	}
	else
	{
		Node *ptr=q;
		while(ptr !=NULL && ptr->next !=NULL)
		{
			ptr=ptr->next;
		}
			ptr->next=p;
	}
}
int peek(queue q)
{
	if(!isempty(q))
		return q->data;
	else
		return 0;
}
int Dequeue(queue &q)
{
	if(!isempty(q))
	{
		int data =q->data; 
		Node *p=q;
		q=q->next;
		delete(p);
		return data;
	}
	else
	return 0;
}
int main()
{
	queue q=NULL;
	Enqueue(q, 5);
	Enqueue(q, 10);
	Enqueue(q, 15);
	Enqueue(q, 20);
	Enqueue(q, 25);
	cout<<"Empty Queue "<<isempty(q)<<endl;
	cout<<"First Element of queue "<<peek(q)<<endl;
	while(!isempty(q))
	{
		int data=peek(q);
		Dequeue(q);
		cout<<" "<<data<<endl;
	}
	cout<<"Empty Queue "<<isempty(q)<<endl;
}
