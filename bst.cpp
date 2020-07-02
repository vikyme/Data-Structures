#include<bits/stdc++.h>
using namespace std;
class Node                                                  //Node having two pointers to implement non-linear data structure
{
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};
class BST
{
    public:
    Node* root=NULL;
    Node* search(Node* root, int d)                          //Search any integer d in bst with Node root return value
    {
        if (root==NULL)
            return NULL;
        if (root->data==d)
            return root;
        else
        {
            if (root->data>=d)
                return(search(root->left,d));            
            else
                return(search(root->right,d));                                    
        }        
    }
    void insert(int d)
    {
        Node* n=new Node();
        n->data=d;
        if (root==NULL)
        {
            root=n;
        }
        else
        {
            Node* temp=root;
            while(temp->left!=NULL && temp->right!=NULL)
            {
                if (d<=temp->data)
                    temp=temp->left;
                else
                    temp=temp->right;
            }
                if (d<=temp->data)
                    temp->left=n;
                else
                    temp->right=n;
        }
        
    }
    Node* find_min(Node* root)
    {
        if (root==NULL)
        {
            cout<<"Empty Tree";
            return (NULL);
        }
        if (root->left==NULL)
            return(root);
        else
            return find_min(root->left);
    }
    Node* find_max(Node* root)              //returns max node
    {
        if (root==NULL)
        {
            cout<<"Empty Tree";
            return (NULL);
        }
        if (root->right==NULL)
            return(root);
        else
            return find_max(root->right);
    }

    void print(Node* n)
    {
        Node* temp=n;
        if (temp==NULL)
            return;
        else 
        {
            cout<<temp->data<<" ";
            if (temp->left!=NULL)
                print(temp->left);            
            if (temp->right!=NULL)
                print(temp->right);                        
        }
    }
    int height(Node* root)                                      // Height of any node is number of edges in longest path from node to a leaf node
    {
        if (root==NULL)
            return(-1);
        else if (root->left==NULL && root->right==NULL)             //condition kind of redundant but useful since function call will take more space in stack imo
            return(0);
        else
            return 1+max(height(root->left),height(root->right));
    }
void Preorder(Node* r)                      //Order of Traversal--> root,left,right
{
    if (r==NULL)
        return;
    else
    {
        cout<<r->data<<" ";
        Preorder(r->left);
        Preorder(r->right);
    }
}
void Inorder(Node* r)                       //Order of Traversal--> left,root,right(returns a sorted array for bst)
{
    if (r==NULL)
        return;
    else
    {
        Inorder(r->left);
        cout<<r->data<<" ";
        Inorder(r->right);
    }
}
void Postorder(Node* r)                     //Order of Traversal--> left,right,root
{
    if (r==NULL)
        return;
    else
    {
        Postorder(r->left);
        Postorder(r->right);
        cout<<r->data<<" ";        
    }
}
void Levelorder(Node* r)                // Breadth First Traversal
{
    //another implementation using array(length of BST required) for every ith node store left child @ (2i+1) & right child @ (2i+2)
    if (r==NULL)
        {cout<<"Empty Tree";return;}
    queue<Node*> q;
    q.push(r);
    Node* temp;
    while (!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if (temp->left!=NULL)
            q.push(temp->left);
        if (temp->right!=NULL)
            q.push(temp->right);
    }
    
} 
bool CheckBST(Node* r, int min, int max)			//Inorder traversal can be used and check at every step if current element is greater than last element(sorted array property of Inorder traversal)
{
    if (r==NULL)
        return true;
    bool val;
	if ((min<r->data) && (max>=r->data)) 
		val=true;
	else
		val=false;
    val&=CheckBST(r->left,min,r->data);
    val&=CheckBST(r->right,r->data,max);      
    return val;  
}
Node* InorderSuccessor(Node* r, int d)          //Given root node and value of node, find the Inorder Succesor of the node
{
    Node* temp=search(r,d);
    if (temp==NULL)
    {
        cout<<"Node not found"<<endl;
        return(NULL);
    }
    else
    {
        if (temp->right!=NULL)                  //Node having Right Sub Tree
        {return(find_min(temp->right);)}
        else                                    // Node having no Right Sub Tree
        {
            Node* parent=root, ans=NULL;
            while(parent!=temp)
            {
                if (parent->data>temp->data)
                {
                    ans=parent;
                    parent=parent->left;
                }
                else
                    parent=parent->right;
            }
            return (parent);
        }
        
    }
}
Node* remove(Node* r, int d)
{
    if (r==NULL)
        {cout<<"ELement not found";return NULL;}
    else if (r->data<d)
        r->right=remove(r->right,d);
    else if (r->data>d)
        r->left=remove(r->left,d);
    else
    {
        if(r->left==NULL && r->right==NULL)         //No child
        {
            delete r;
            r= NULL;    
        }
        else if (r->right==NULL)                    //Only one child
        {
            Node* temp=r;
            r=r->left;
            delete temp;
        }
        else if (r->left==NULL)
        {
            Node* temp=r;
            r=r->right;
            delete temp;
        }
        else                                        //Two children
        {
            Node* bigg=find_max(r->left);
            r->data=bigg->data;
            r->left=remove(r->left,bigg->data);
        } 
                   
    }
    return r;
}
};

int main()
{
    BST b;
    b.insert(15);
    b.insert(10);  
    b.insert(25);    
    b.insert(12);
    b.insert(6);
    b.insert(8);
    b.insert(28);
    b.insert(4);
    b.insert(20);
    b.insert(22);
    b.insert(21); 
    b.print(b.root);
    cout<<endl;
    b.Inorder(b.root);          //shold return a sorted array for bst
    cout<<endl;
    //b.root->data=23;
    //cout<<b.CheckBST(b.root,INT_MIN,INT_MAX)<<endl;
    b.root=b.remove(b.root,15);
    //cout<<temp->data;
    b.Inorder(b.root); 
    }