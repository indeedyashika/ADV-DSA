#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

node* GetNode(){
    return new node;
}

/*********************************************************************/
// Basic Linked List

node* InsBeg(node *Head,int x){
    node *P=GetNode();
    P->data=x;
    P->next=Head;
    Head=P;
    return Head;
}

node* InsAfter(node *Head,node *P,int x){
    node *Q=P->next;
    node *R=GetNode();
    R->data=x;
    P->next=R;
    R->next=Q;
    return Head;
}

node* InsEnd(node *Head,int x){
    node *Q=GetNode();
    Q->data=x;
    Q->next=NULL;
    if(Head==NULL)
        Head=Q;
    else{
        node *P=Head;
        while(P->next!=NULL)
            P=P->next;
        P->next=Q;
    }
    return Head;
}

node* DelBeg(node *Head){
    node *P=Head;
    Head=Head->next;
    delete P;
    return Head;
}

node* DelAfter(node *Head,node *P){
    node *Q=P->next;
    node *R=Q->next;
    P->next=R;
    delete Q;
    return Head;
}

node* DelEnd(node *Head){
    node *P=Head, *Q=NULL;
    while(P->next!=NULL){
        Q=P;
        P=P->next;
    }
    if(Q!=NULL)
        Q->next=NULL;
    else
        Head=NULL;
    delete P;
    return Head;
}

node* DelAllOcc(node *Head,int x){
    node *P=Head, *Q=NULL;
    while(P!=NULL){
        if(P->data==x){
            P=P->next;
            if(Q==NULL)
                Head=DelBeg(Head);
            else
                Head=DelAfter(Head,Q);
        }
        else{
            Q=P;
            P=P->next;
        }
    }
    return Head;
}

node* OrderedInsertion(node *Head,int x){
    node *P=Head, *Q=NULL;
    while(P!=NULL && x>P->data){
        Q=P;
        P=P->next;
    }
    if(Q!=NULL)
        Head=InsAfter(Head,Q,x);
    else
        Head=InsBeg(Head,x);
    return Head;
}

void Traverse(node *Head){
    node *P=Head;
    while(P!=NULL){
        cout<<P->data<<" ";
        P=P->next;
    }
    cout<<endl;
}

/*********************************************************************/
// Stack using Linked List (all O(1))

node *Top;

void InitializeStack(){
    Top=NULL;
}

void Push(int x){
    Top=InsBeg(Top,x);
}

int Pop(){
    if(Top==NULL){
        cout<<"Stack Underflows"<<endl;
        exit(1);
    }
    int x=Top->data;
    Top=DelBeg(Top);
    return x;
}

int StackTop(){
    return Top->data;
}

bool IsEmpty(){
    return Top==NULL;
}

/*********************************************************************/

int main(){
    node *Head=NULL;

    Head=InsBeg(Head,20);
    Head=InsBeg(Head,10);
    Head=InsEnd(Head,30);
    Head=InsAfter(Head,Head,15);
    cout<<"After insertions     : ";
    Traverse(Head);

    Head=InsEnd(Head,20);
    Head=InsEnd(Head,20);
    cout<<"With extra 20s       : ";
    Traverse(Head);

    Head=DelAllOcc(Head,20);
    cout<<"After DelAllOcc(20)  : ";
    Traverse(Head);

    Head=DelBeg(Head);
    cout<<"After DelBeg         : ";
    Traverse(Head);

    Head=DelEnd(Head);
    cout<<"After DelEnd         : ";
    Traverse(Head);

    node *O=NULL;
    int a[]={40,10,30,20,50};
    for(int x:a)
        O=OrderedInsertion(O,x);
    cout<<"Ordered Insertion    : ";
    Traverse(O);

    InitializeStack();
    Push('A'); Push('B'); Push('C');
    cout<<"Stack (LL) Pop       : "<<(char)Pop()<<endl;
    cout<<"Stack (LL) Top       : "<<(char)StackTop()<<endl;
    cout<<"Stack (LL) IsEmpty   : "<<(IsEmpty()?"true":"false")<<endl;
}
