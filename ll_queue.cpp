#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next=NULL;
};
class LL_Queue
{
    public:
    Node* front=NULL;
    Node* rear=NULL;
    void Enqueue(int data)
    {
        Node* n=new Node();
        n->data=data;
        if (front==NULL && rear==NULL)
        {
            front=rear=n;
        }
        else
        {
            rear->next=n;
            rear=n;
        }
    }
    void Dequeue()
    {
        if (front==NULL && rear==NULL)
            cout<<"Queue Already Empty"<<endl;
        else
        {
            Node* garbage=front;
            if (front==rear)
                front=rear=NULL;
            else
                front=front->next;
            delete garbage;
        }
    }
    bool IsEmpty()
    {return(front==NULL && rear==NULL);}
    int Peek()
    {return(front->data);}
    void print()
    {
        Node* n=front;
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
        cout<<endl;
    }
};
int main()
{
    LL_Queue l;
    l.Enqueue(5);
    l.print();
    l.Enqueue(10);
    l.Enqueue(15);
    l.print();
    l.Dequeue();
    l.print();

}