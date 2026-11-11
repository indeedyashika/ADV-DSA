#include <bits/stdc++.h>
using namespace std;

#define SIZE 10

/*********************************************************************/
// Two Stacks in One Array
// Stack 1 grows from left (Top1=-1), Stack 2 grows from right (Top2=SIZE)

class TwoStacks{
public:
    int item[SIZE];
    int Top1, Top2;

    TwoStacks(){
        Top1=-1;
        Top2=SIZE;
    }

    void Push1(int x){
        if(Top1+1==Top2){
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        Top1++;
        item[Top1]=x;
    }

    int Pop1(){
        if(Top1==-1){
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
        int x=item[Top1];
        Top1--;
        return x;
    }

    void Push2(int x){
        if(Top2-1==Top1){
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        Top2--;
        item[Top2]=x;
    }

    int Pop2(){
        if(Top2==SIZE){
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
        int x=item[Top2];
        Top2++;
        return x;
    }
};

void twoStacksProgram(){
    TwoStacks s;
    s.Push1(1);
    s.Push1(2);
    s.Push2(9);
    s.Push2(8);
    s.Push2(7);
    cout<<"Pop1 : "<<s.Pop1()<<endl;
    cout<<"Pop2 : "<<s.Pop2()<<endl;
}

/*********************************************************************/
// Simple int stack for conversions

class Stack{
public:
    int item[SIZE*4];
    int Top;

    Stack(){
        Top=-1;
    }

    void Push(int x){
        if(Top==SIZE*4-1){
            cout<<"Stack Overflow"<<endl;
            exit(1);
        }
        Top++;
        item[Top]=x;
    }

    int Pop(){
        if(Top==-1){
            cout<<"Stack Underflow"<<endl;
            exit(1);
        }
        int x=item[Top];
        Top--;
        return x;
    }

    bool IsEmpty(){
        return Top==-1;
    }
};

// Decimal to Binary
void decimalToBinary(int D){
    Stack S;
    cout<<"Binary of "<<D<<" : ";
    while(D!=0){
        int r=D%2;
        S.Push(r);
        D=D/2;
    }
    while(!S.IsEmpty()){
        int x=S.Pop();
        cout<<x;
    }
    cout<<endl;
}

// Decimal to Hexadecimal (Direct Address Table)
void decimalToHexadecimal(int D){
    char DAT[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    Stack S;
    cout<<"Hexadecimal of "<<D<<" : ";
    while(D!=0){
        int r=D%16;
        S.Push(r);
        D=D/16;
    }
    while(!S.IsEmpty()){
        int x=S.Pop();
        cout<<DAT[x];
    }
    cout<<endl;
}

/*********************************************************************/

int main(){
    twoStacksProgram();
    decimalToBinary(43);
    decimalToHexadecimal(4568);
}
