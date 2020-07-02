#include<bits/stdc++.h>
using namespace std;
class Arr_Queue                     //implementing array queue with circular array logic to utilize space allocated to array
{
    public:
    int front=-1, rear=-1, max_size;
    int* arr;
    Arr_Queue(int l)
    {
        arr=new int[l];
        max_size=l;
    }
    void Enqueue(int data)
    {
        if ((rear+1)%(max_size-1)==front)
            cout<<"Queue Overflow"<<endl;
        else if (front==-1 && rear==-1)
        {
            arr[0]=data;
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%(max_size-1);
            arr[rear]=data;
        }
    }
    void Dequeue()
    {
        if (front==-1 && rear==-1)
            cout<<"Queue Already Empty"<<endl;
        else
        {
            if (front==rear)
                rear=front=-1;
            else
                front=(front+1)%(max_size-1);
        }
    }
    bool IsEmpty()
    {
        return (front==-1 && rear==-1);
    }
    int Peek()
    {
        if (front==-1)
        {
            cout<<"Empty Queue"<<endl;
            return(0);
        }
        else
            return(arr[front]);
    } 
    void print()
    {
        if (front!=-1)
        {
            for (int i=front;i<=rear;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"Empty Queue"<<endl;
    }
};
int main()
{
    Arr_Queue a(5);
    a.Enqueue(3);
    a.Enqueue(4);
    a.Enqueue(8);
    a.Enqueue(5);
    a.print();
    a.Dequeue();
    a.Dequeue();
    a.print();
    cout<<a.Peek();
}