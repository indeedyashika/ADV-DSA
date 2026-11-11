#include <bits/stdc++.h>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
};

node* MakeNode(char x){
    node *p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

/*********************************************************************/
// Create: insert at first vacant place (level order)
node* InsertLevel(node *root,char x){
    node *r=MakeNode(x);
    if(root==NULL)
        return r;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node *p=q.front();
        q.pop();
        if(p->left==NULL){
            p->left=r;
            return root;
        }
        q.push(p->left);
        if(p->right==NULL){
            p->right=r;
            return root;
        }
        q.push(p->right);
    }
    return root;
}

/*********************************************************************/
// Depth First Traversals
void PreOrder(node *t){
    if(t!=NULL){
        cout<<t->data<<" ";
        PreOrder(t->left);
        PreOrder(t->right);
    }
}

void InOrder(node *t){
    if(t!=NULL){
        InOrder(t->left);
        cout<<t->data<<" ";
        InOrder(t->right);
    }
}

void PostOrder(node *t){
    if(t!=NULL){
        PostOrder(t->left);
        PostOrder(t->right);
        cout<<t->data<<" ";
    }
}

// Breadth First Traversal
void LevelOrder(node *t){
    if(t==NULL)
        return;
    queue<node*> q;
    q.push(t);
    while(!q.empty()){
        node *p=q.front();
        q.pop();
        cout<<p->data<<" ";
        if(p->left!=NULL)
            q.push(p->left);
        if(p->right!=NULL)
            q.push(p->right);
    }
}

/*********************************************************************/
// Search
bool Search(node *t,char x){
    if(t==NULL)
        return false;
    if(t->data==x)
        return true;
    return Search(t->left,x) || Search(t->right,x);
}

/*********************************************************************/
// Terminology
int Height(node *t){            // nodes on longest path (empty tree = 0)
    if(t==NULL)
        return 0;
    return 1+max(Height(t->left),Height(t->right));
}

int CountNodes(node *t){
    if(t==NULL)
        return 0;
    return 1+CountNodes(t->left)+CountNodes(t->right);
}

int CountLeaves(node *t){
    if(t==NULL)
        return 0;
    if(t->left==NULL && t->right==NULL)
        return 1;
    return CountLeaves(t->left)+CountLeaves(t->right);
}

/*********************************************************************/
// Tree Types
bool IsStrict(node *t){         // every node has 0 or 2 children
    if(t==NULL)
        return true;
    if(t->left==NULL && t->right==NULL)
        return true;
    if(t->left!=NULL && t->right!=NULL)
        return IsStrict(t->left) && IsStrict(t->right);
    return false;
}

bool IsComplete(node *t){       // all levels full except last, filled left to right
    queue<node*> q;
    q.push(t);
    bool gap=false;
    while(!q.empty()){
        node *p=q.front();
        q.pop();
        if(p==NULL){
            gap=true;
        }
        else{
            if(gap)
                return false;
            q.push(p->left);
            q.push(p->right);
        }
    }
    return true;
}

bool IsSkewed(node *t){         // every node has at most one child
    if(t==NULL)
        return true;
    if(t->left!=NULL && t->right!=NULL)
        return false;
    return IsSkewed(t->left) && IsSkewed(t->right);
}

/*********************************************************************/

int main(){
    // Same tree as BINARY-TREE-TRAVERSALS.cpp
    node *root=MakeNode('C');
    root->left=MakeNode('X');
    root->right=MakeNode('Y');
    root->left->left=MakeNode('T');
    root->right->left=MakeNode('M');
    root->right->right=MakeNode('N');

    cout<<"Pre-order   : ";   PreOrder(root);    cout<<endl;
    cout<<"In-order    : ";   InOrder(root);     cout<<endl;
    cout<<"Post-order  : ";   PostOrder(root);   cout<<endl;
    cout<<"Level-order : ";   LevelOrder(root);  cout<<endl;

    cout<<"Search M : "<<(Search(root,'M')?"Found":"Not Found")<<endl;
    cout<<"Search Z : "<<(Search(root,'Z')?"Found":"Not Found")<<endl;

    cout<<"Height : "<<Height(root)<<endl;
    cout<<"Nodes  : "<<CountNodes(root)<<endl;
    cout<<"Leaves : "<<CountLeaves(root)<<endl;

    cout<<"Strict   : "<<(IsStrict(root)?"Yes":"No")<<endl;
    cout<<"Complete : "<<(IsComplete(root)?"Yes":"No")<<endl;
    cout<<"Skewed   : "<<(IsSkewed(root)?"Yes":"No")<<endl;

    // Created by level-order insertion -> complete tree
    node *c=NULL;
    for(char ch:string("ABCDEF"))
        c=InsertLevel(c,ch);
    cout<<"Created tree level-order : ";
    LevelOrder(c);
    cout<<endl;
    cout<<"Created tree complete    : "<<(IsComplete(c)?"Yes":"No")<<endl;

    // Right skewed tree
    node *s=MakeNode('A');
    s->right=MakeNode('B');
    s->right->right=MakeNode('C');
    cout<<"Skewed tree skewed : "<<(IsSkewed(s)?"Yes":"No")<<endl;
}
