#include<bits/stdc++.h>
using namespace std;
class Arr_Stack
{
    public:
    int top=-1,size;
    int* arr;
    Arr_Stack(int s)
    {
        size=s;
        arr=(int*)malloc(size*sizeof(int));             //dynamic allocation of array using malloc   
    }
    void push(int data)                                 //takes constant time
    {
        if (top+1>=size)
            cout<<"Stack Overflow"<<endl;
        else
        {
            top++;
            arr[top]=data;
        }
    }
    void pop()                                          //takes constant time
    {
        if (top==-1)
            cout<<"Stack Already Empty";
        else
        {
             arr[top]=0;
            top--;
        }
    }
    int Top()
    {
        return(arr[top]);
    }
    bool IsEmpty()
    {
        return(top==-1);
    }
    void print()
    {
        for (int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};
int main()
{
    Arr_Stack s(2);
    cout<<s.IsEmpty()<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<s.Top()<<" "<<s.size<<endl;
    s.push(4);
    s.print();
}