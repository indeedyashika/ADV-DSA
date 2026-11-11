#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    char item[100];
    int Top;
    int size;

    void Initialize(int s){
        size=s;
        Top=-1;
    }

    void Push(char x){
        if(Top==size-1){
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        Top=Top+1;
        item[Top]=x;
    }

    char Pop(){
        if(Top==-1){
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
        char x=item[Top];
        Top--;
        return x;
    }

    char StackTop(){
        return item[Top];
    }

    bool IsEmpty(){
        return Top==-1;
    }
};

int main(){
    // Q1: size 6 -> Push A,B,C; Pop; Top; Push D; Pop; Pop; Top; Pop
    Stack S;
    S.Initialize(6);
    S.Push('A'); S.Push('B'); S.Push('C');
    cout<<S.Pop()<<" ";
    cout<<S.StackTop()<<" ";
    S.Push('D');
    cout<<S.Pop()<<" ";
    cout<<S.Pop()<<" ";
    cout<<S.StackTop()<<" ";
    cout<<S.Pop()<<endl;
    cout<<"IsEmpty : "<<(S.IsEmpty()?"true":"false")<<endl;
    // S.Pop();  // would give Stack Underflow
}
