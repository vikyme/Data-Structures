#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next=NULL;
};
class Stack
{
    public:
    Node* Top=NULL;
    void push(int data)
    {
        Node* n=new Node();
        n->data=data;
        n->next=Top;
        Top=n;
    }
    void pop()
    {
        if (Top==NULL)
            cout<<"Stack Already Empty";
        else
        {
            Node* n=Top;
            Top=Top->next;
            delete n;
        }
        
    }
    Node* ret_top()
    {
        return(Top);
    }
    bool IsEmpty()
    {
        return(Top==NULL);
    }
    void print()
    {
        Node* n=Top;
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
    Stack s;
    cout<<s.IsEmpty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<s.Top->data<<endl;
    s.push(4);
    s.print();
    s.pop();
    s.print();
    stack<Node*> s1;
    Node* n=new Node();
    n->data=5;
    s1.push(n);
    cout<<s1.top()->data;
}