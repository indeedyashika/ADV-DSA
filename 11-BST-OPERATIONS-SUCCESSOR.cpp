#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    node *father;
};

/*********************************************************************/

node* newNode(int x){
    node *p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->father=NULL;
    return p;
}

/*********************************************************************/

// Insert (iterative, keeps father pointer)
node* BSTInsertion(node *t,int x){
    node *r=newNode(x);
    if(t==NULL)
        return r;
    node *p=t, *q=NULL;
    while(p!=NULL){
        q=p;
        if(x<p->data)
            p=p->left;
        else
            p=p->right;
    }
    if(x<q->data)
        q->left=r;
    else
        q->right=r;
    r->father=q;
    return t;
}

/*********************************************************************/

// Search -> returns node or NULL
node* BSTSearch(node *t,int x){
    while(t!=NULL && t->data!=x){
        if(x<t->data)
            t=t->left;
        else
            t=t->right;
    }
    return t;
}

/*********************************************************************/

node* minNode(node *t){
    while(t->left!=NULL)
        t=t->left;
    return t;
}

node* maxNode(node *t){
    while(t->right!=NULL)
        t=t->right;
    return t;
}

/*********************************************************************/

// Delete: leaf, one child, two children (replace by inorder successor)
node* BSTDeletion(node *t,int x){
    node *p=BSTSearch(t,x);
    if(p==NULL){
        cout<<x<<" not found"<<endl;
        return t;
    }
    if(p->left!=NULL && p->right!=NULL){
        node *s=minNode(p->right);
        p->data=s->data;
        p=s;
    }
    node *child=(p->left!=NULL)?p->left:p->right;
    if(child!=NULL)
        child->father=p->father;
    if(p->father==NULL)
        t=child;
    else if(p==p->father->left)
        p->father->left=child;
    else
        p->father->right=child;
    delete p;
    return t;
}

/*********************************************************************/

// Inorder Successor (uses father pointer)
node* Successor(node *p){
    if(p->right!=NULL)
        return minNode(p->right);
    node *q=p->father;
    while(q!=NULL && p==q->right){
        p=q;
        q=q->father;
    }
    return q;
}

/*********************************************************************/

void InOrder(node *t){
    if(t!=NULL){
        InOrder(t->left);
        cout<<t->data<<" ";
        InOrder(t->right);
    }
}

/*********************************************************************/

int main(){
    node *root=NULL;
    int a[]={100,50,60,200,70,130,40,120,105};
    for(int x:a)
        root=BSTInsertion(root,x);

    cout<<"Inorder : ";
    InOrder(root);
    cout<<endl;

    cout<<"Search 70 : "<<(BSTSearch(root,70)?"Found":"Not Found")<<endl;
    cout<<"Search 99 : "<<(BSTSearch(root,99)?"Found":"Not Found")<<endl;
    cout<<"Minimum : "<<minNode(root)->data<<endl;
    cout<<"Maximum : "<<maxNode(root)->data<<endl;

    for(int x:a){
        node *s=Successor(BSTSearch(root,x));
        cout<<"Successor of "<<x<<" : ";
        if(s==NULL)
            cout<<"None"<<endl;
        else
            cout<<s->data<<endl;
    }

    root=BSTDeletion(root,40);   // leaf
    cout<<"After deleting 40 : ";
    InOrder(root);
    cout<<endl;

    root=BSTDeletion(root,60);   // one child
    cout<<"After deleting 60 : ";
    InOrder(root);
    cout<<endl;

    root=BSTDeletion(root,100);  // two children (root)
    cout<<"After deleting 100 : ";
    InOrder(root);
    cout<<endl;

    root=BSTDeletion(root,99);   // not present
}
