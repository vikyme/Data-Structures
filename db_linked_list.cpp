#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;                                  //type of user defined data structure linked list(int)
    Node* next=NULL;                           //Next node pointer
    Node* prev=NULL;
};

class Db_Link_list                                // If we use constructor of Linked List(user defined), we can't initialize and use Node            
{                                              // in various member functions of Linked List class(gives various errors like code stops 
    public:                                    // executing after hitting new Node initialization line). On removing the constructor,
    Node* head;                                // everything works fine. why?
    int length=0;

    void print()                                   //prints all nodes of linked list
    {
        Node* n=head;
        while(n!=NULL)
        {
            cout<<n->data<<" ";
            n=n->next;
        }
        cout<<endl<<"Length of LList: "<<length<<endl;
    } 
    void insert(int d, int pos=0)                   //adds element(d) at position pos(0 indexing) and at first position(0th) by default
    {
        // cout<<"Insert "<<length<<endl;
        //Node temp1;
        Node* temp=new Node();                      //dynamically assigned memory of temp from Heap
        temp->data=d;
        // cout<<endl<<temp->data<<" "<<d<<" Im working ";
        if (length==0)
        {
            head=temp;
            length=1;
        }
        else
        {
            if (pos==0)
            {
                //cout<<"pos=0";
                head->prev=temp;
                temp->next=head;
                head=temp;
                length++;
            }
            else
            {
                //cout<<"inside";
                Node* n=head;
                int i=1;
                int flag=0;
                while(n!=NULL)
                {
                    if (i==pos)
                    {
                        flag=1;
                        break;
                    }
                    n=n->next;
                    i++;
                }
                if (flag==1)
                {
                    cout<<"Inside";
                    temp->next=n->next;
                    n->next->prev=temp;
                    temp->prev=n;
                    n->next=temp;
                    length++;
                    cout<<"Outside";
                }
                else
                {
                    cout<<"Out of Scope of linked list max length "<<length<<endl;
                }

            }
            
        }
        print();
    }

    void remove(int pos=0)                        //removes element at position pos(0 indexing) and first element by default
    {
        if (length==0)
        {
            cout<<"Empty Linked List"<<endl;
        }
        else
        {
            if (pos==0)
            {
                Node* garbage=head;        
                //cout<<"pos=0";
                head->next->prev=NULL;
                head=head->next;
                delete garbage;
                length--;
            }
            else
            {
                //cout<<"inside";
                Node* n=head;
                int i=1;
                int flag=0;
                while(n->next!=NULL)
                {
                    if (i==pos)
                    {
                        flag=1;
                        break;
                    }
                    n=n->next;
                    i++;
                }
                if (flag==1)
                {
                        Node* garbage=n->next;
                        n->next=n->next->next;
                        n->next->prev=n;
                        delete garbage;
                        //delete n->next
                    length--;
                }
                else
                {
                    cout<<"Out of Scope of linked list max length "<<length<<endl;
                }

            }
            
        }
        print();
    }
    void reverse()                          //reverse a linked list iteratively
    {
        if (length==0)
            cout<<"Empty Linked List"<<endl;
        else if (length==1)
            cout<<"Only 1 element present in Linked List, No Reverse Operation necessary"<<endl;
        else
        {
            Node* N=head->next; Node* Parent=head; Node* Child=NULL;
            head->next=NULL;
            while(N->next!=NULL)
            {
                Child=N->next;
                N->next=Parent;
                Parent=N;
                N=Child;
            }
            N->next=Parent;
            head=N;
        }
        print();
            
    }

    Node* rec_reverse(Node* N, Node* h)                          //reverse a linked list recursively
    {
        if (N->next==NULL)
        {
            // cout<<"Base Case"<<endl;
            h=N;
            return(h);
        }
        h=rec_reverse(N->next,h);
        N->next->next=N;
        N->next=NULL; 
        return h;           
    }

    void rev_rec_print(Node* N)                                                     //reverse recursive print(INGENIOUS)
    {
        if (N!=NULL)
        {
            rec_print(N->next);
            cout<<N->data<<" ";            
        }
    }


    void rec_print(Node* N)                                                     //recursive print
    {
        if (N!=NULL)
        {
            cout<<N->data<<" ";
            rec_print(N->next);
            
        }
    }
};

int main()
{
    int d1=12;
    Db_Link_list* l=new Db_Link_list();
    
    l->insert(d1);
    int d2=4;

    l->insert(5);
    
    l->insert(8,2);
    l->insert(7);
    
    cout<<"End"<<endl;
    l->remove();
    // l->reverse();
    l->head=l->rec_reverse(l->head,NULL);                         //above intialization required for recursive reverse linked list
    // l->rev_rec_print(l->head); 
    // cout<<endl;  
    // l->rec_print(l->head);                                       
    l->print(); 
    system("pause");
}