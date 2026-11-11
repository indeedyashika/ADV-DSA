#include <bits/stdc++.h>
using namespace std;

/*********************************************************************/
// Linear Queue (array): Rear=-1, Front=0, empty when Rear-Front+1==0
class Queue{
public:
    char item[100];
    int Front, Rear, size;

    void Initialize(int s){
        size=s;
        Rear=-1;
        Front=0;
    }
    void EnQueue(char x){
        if(Rear==size-1){
            cout<<"Queue Overflow"<<endl;
            exit(1);
        }
        Rear++;
        item[Rear]=x;
    }
    char DeQueue(){
        if(Rear-Front+1==0){
            cout<<"Queue Underflow"<<endl;
            exit(1);
        }
        char x=item[Front];
        Front++;
        return x;
    }
    bool IsEmpty(){
        return Rear-Front+1==0;
    }
};

/*********************************************************************/
// Circular Queue: Rear=Front=size-1 (one cell stays vacant)
class CQueue{
public:
    char item[100];
    int Front, Rear, size;

    void Initialize(int s){
        size=s;
        Rear=size-1;
        Front=size-1;
    }
    void EnQueue(char x){
        if((Rear+1)%size==Front){
            cout<<"Queue Overflow"<<endl;
            exit(1);
        }
        Rear=(Rear+1)%size;
        item[Rear]=x;
    }
    char DeQueue(){
        if(Rear==Front){
            cout<<"Queue Underflow"<<endl;
            exit(1);
        }
        Front=(Front+1)%size;
        return item[Front];
    }
    bool IsEmpty(){
        return Rear==Front;
    }
};

/*********************************************************************/
// Queue using Linked List
struct node{
    int data;
    node *next;
};

node *Front=NULL, *Rear=NULL;

void LLInitialize(){
    Front=NULL;
    Rear=NULL;
}

void LLEnQueue(int x){
    node *P=new node;
    P->data=x;
    P->next=NULL;
    if(Rear!=NULL)
        Rear->next=P;
    else
        Front=P;
    Rear=P;
}

int LLDeQueue(){
    if(Front==NULL){
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    node *P=Front;
    Front=Front->next;
    if(Front==NULL)
        Rear=NULL;
    int x=P->data;
    delete P;
    return x;
}

bool LLIsEmpty(){
    return Front==NULL;
}

/*********************************************************************/
// Priority Queue using Array (ascending order, min at index 0)
void ArrayInsertion(int A[],int &N,int i,int x){
    int j=N-1;
    while(j>=i){
        A[j+1]=A[j];
        j--;
    }
    A[i]=x;
    N=N+1;
}

int ArrayDeletion(int A[],int &N,int i){
    int x=A[i];
    for(int j=i+1;j<=N-1;j++)
        A[j-1]=A[j];
    N=N-1;
    return x;
}

void PQEnQueueAsc(int PQ[],int &N,int x){
    int i=0;
    while(i<N && x>=PQ[i])
        i++;
    ArrayInsertion(PQ,N,i,x);
}

int PQDeQueueAsc(int PQ[],int &N){
    return ArrayDeletion(PQ,N,0);              // O(N)
}

// Reduced complexity: descending order, delete at end
void PQEnQueueDesc(int PQ[],int &N,int x){
    int i=0;
    while(i<N && x<PQ[i])
        i++;
    ArrayInsertion(PQ,N,i,x);
}

int PQDeQueueDesc(int PQ[],int &N){
    return ArrayDeletion(PQ,N,N-1);            // O(1)
}

/*********************************************************************/
// Priority Queue using Linked List (ascending ordered list)
node* PQInsAfter(node *Head,node *P,int x){
    node *R=new node;
    R->data=x;
    R->next=P->next;
    P->next=R;
    return Head;
}

node* PQEnQueue(node *PQ,int x){
    node *P=PQ, *Q=NULL;
    while(P!=NULL && x>=P->data){
        Q=P;
        P=P->next;
    }
    if(Q!=NULL)
        PQ=PQInsAfter(PQ,Q,x);
    else{
        node *R=new node;
        R->data=x;
        R->next=PQ;
        PQ=R;
    }
    return PQ;
}

int PQDeQueue(node *&PQ){
    node *P=PQ;
    int x=P->data;
    PQ=PQ->next;
    delete P;
    return x;
}

/*********************************************************************/
// Double Ended Queue using Doubly Linked List
struct dnode{
    int data;
    dnode *prev;
    dnode *next;
};

dnode *DFront=NULL, *DRear=NULL;

void InsFront(int x){
    dnode *P=new dnode;
    P->data=x;
    P->prev=NULL;
    P->next=DFront;
    if(DFront!=NULL)
        DFront->prev=P;
    else
        DRear=P;
    DFront=P;
}

void InsRear(int x){
    dnode *P=new dnode;
    P->data=x;
    P->next=NULL;
    P->prev=DRear;
    if(DRear!=NULL)
        DRear->next=P;
    else
        DFront=P;
    DRear=P;
}

int DelFront(){
    if(DFront==NULL){
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    dnode *P=DFront;
    int x=P->data;
    DFront=DFront->next;
    delete P;
    if(DFront!=NULL)
        DFront->prev=NULL;
    else
        DRear=NULL;
    return x;
}

int DelRear(){
    if(DRear==NULL){
        cout<<"Queue Underflow"<<endl;
        exit(1);
    }
    dnode *P=DRear;
    int x=P->data;
    DRear=DRear->prev;
    delete P;
    if(DRear!=NULL)
        DRear->next=NULL;
    else
        DFront=NULL;
    return x;
}

// Input restricted DEQ : InsRear + DelFront + DelRear
// Output restricted DEQ: InsFront + InsRear + DelFront

void DPrint(){
    for(dnode *P=DFront;P!=NULL;P=P->next)
        cout<<P->data<<" ";
    cout<<endl;
}

/*********************************************************************/

int main(){
    // Linear queue size 8
    Queue Q;
    Q.Initialize(8);
    Q.EnQueue('A'); Q.EnQueue('B'); Q.EnQueue('C');
    cout<<"Linear DeQueue : "<<Q.DeQueue()<<endl;
    Q.EnQueue('P'); Q.EnQueue('Q');
    cout<<"Linear F="<<Q.Front<<" R="<<Q.Rear<<endl;

    // Circular queue size 6 (notes example)
    CQueue C;
    C.Initialize(6);
    C.EnQueue('A'); C.EnQueue('B'); C.EnQueue('C');
    cout<<"Circular DeQueue : "<<C.DeQueue()<<endl;
    C.EnQueue('P'); C.EnQueue('Q');
    cout<<"Circular DeQueue : "<<C.DeQueue()<<endl;
    C.EnQueue('X'); C.EnQueue('Y');
    cout<<"Circular R="<<C.Rear<<" F="<<C.Front<<endl;

    // LL queue
    LLInitialize();
    LLEnQueue(10); LLEnQueue(20); LLEnQueue(30);
    cout<<"LL Queue DeQueue : "<<LLDeQueue()<<endl;

    // PQ array ascending
    int PQ[20], N=0;
    int a[]={10,5,6,8,100,2};
    for(int x:a) PQEnQueueAsc(PQ,N,x);
    cout<<"PQ asc array : ";
    for(int i=0;i<N;i++) cout<<PQ[i]<<" ";
    cout<<"| DeQueue : "<<PQDeQueueAsc(PQ,N)<<endl;

    // PQ array descending (reduced complexity)
    int D[20], M=0;
    for(int x:a) PQEnQueueDesc(D,M,x);
    cout<<"PQ desc array : ";
    for(int i=0;i<M;i++) cout<<D[i]<<" ";
    cout<<"| DeQueue : "<<PQDeQueueDesc(D,M)<<endl;

    // PQ linked list
    node *L=NULL;
    for(int x:a) L=PQEnQueue(L,x);
    cout<<"PQ LL DeQueue : "<<PQDeQueue(L)<<endl;

    // DEQ
    InsRear(8); InsRear(10); InsFront(4); InsRear(12);
    cout<<"DEQ : ";
    DPrint();
    cout<<"DelFront : "<<DelFront()<<"  DelRear : "<<DelRear()<<endl;
}
