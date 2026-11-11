#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    char item[100];
    int Top;
    Stack(){ Top=-1; }
    void Push(char x){
        if(Top==99){ cout<<"Stack Overflow"<<endl; exit(1); }
        item[++Top]=x;
    }
    char Pop(){
        if(Top==-1){ cout<<"Stack Underflow"<<endl; exit(1); }
        return item[Top--];
    }
    char StackTop(){ return item[Top]; }
    bool IsEmpty(){ return Top==-1; }
};

// String Reverse
void StringReverse(string str){
    Stack S;
    int i=0;
    while(i<str.size()){
        S.Push(str[i]);
        i++;
    }
    cout<<"Reverse of "<<str<<" : ";
    while(!S.IsEmpty())
        cout<<S.Pop();
    cout<<endl;
}

// Palindrome
void PalindromeCheck(string str){
    Stack S;
    int i=0;
    while(i<str.size()){
        S.Push(str[i]);
        i++;
    }
    i=0;
    while(i<str.size()){
        char x=str[i];
        char y=S.StackTop();
        i++;
        if(x==y)
            S.Pop();
        else
            break;
    }
    if(S.IsEmpty())
        cout<<str<<" : Palindrome"<<endl;
    else
        cout<<str<<" : Not a Palindrome"<<endl;
}

// Valid Parenthesis ( )
void ValidParenthesis(string Exp){
    Stack S;
    int Flag=1;
    int i=0;
    while(i<Exp.size()){
        char x=Exp[i];
        i++;
        if(x=='(')
            S.Push(x);
        else if(x==')'){
            if(S.IsEmpty()){
                Flag=0;
                break;
            }
            else
                S.Pop();
        }
    }
    if(!S.IsEmpty() || Flag==0)
        cout<<Exp<<" : Invalid"<<endl;
    else
        cout<<Exp<<" : Valid"<<endl;
}

// Valid Brackets ( ) { } [ ]
void ValidBrackets(string Exp){
    Stack S;
    int Flag=1;
    int i=0;
    while(i<Exp.size()){
        char x=Exp[i];
        i++;
        if(x=='(' || x=='{' || x=='[')
            S.Push(x);
        else if(x==')' || x=='}' || x==']'){
            if(S.IsEmpty()){
                Flag=0;
                break;
            }
            char y=S.StackTop();
            if((x==')' && y=='(') || (x=='}' && y=='{') || (x==']' && y=='['))
                S.Pop();
            else{
                Flag=0;
                break;
            }
        }
    }
    if(!S.IsEmpty() || Flag==0)
        cout<<Exp<<" : Invalid"<<endl;
    else
        cout<<Exp<<" : Valid"<<endl;
}

int main(){
    StringReverse("axhidelsn");
    PalindromeCheck("abcba");
    PalindromeCheck("abcab");
    ValidParenthesis("(())");
    ValidParenthesis("())(");
    ValidBrackets("[{}]");
    ValidBrackets("{[]}");
    ValidBrackets("{()}}{");
    ValidBrackets("[{}()");
}
