#include <bits/stdc++.h>
using namespace std;

class Stack{
public:
    int item[100];
    int Top;
    Stack(){ Top=-1; }
    void Push(int x){
        if(Top==99){ cout<<"Stack Overflow"<<endl; exit(1); }
        item[++Top]=x;
    }
    int Pop(){
        if(Top==-1){ cout<<"Stack Underflow"<<endl; exit(1); }
        return item[Top--];
    }
    int StackTop(){ return item[Top]; }
    bool IsEmpty(){ return Top==-1; }
};

bool IsOperand(char c){
    return isalnum(c);
}

int Apply(int a,char op,int b){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    if(op=='/') return a/b;
    if(op=='%') return a%b;
    return (int)pow(a,b);           // ^
}

/*********************************************************************/
// Postfix Evaluation (single digit operands)
int PostfixEvaluation(string Postfix){
    Stack S;
    int i=0;
    while(i<Postfix.size()){
        char symbol=Postfix[i];
        i++;
        if(IsOperand(symbol))
            S.Push(symbol-'0');
        else{
            int b=S.Pop();
            int a=S.Pop();
            int value=Apply(a,symbol,b);
            S.Push(value);
        }
    }
    return S.StackTop();
}

// Prefix Evaluation (scan right to left; first pop is a)
int PrefixEvaluation(string Prefix){
    Stack S;
    int i=Prefix.size()-1;
    while(i>=0){
        char symbol=Prefix[i];
        i--;
        if(IsOperand(symbol))
            S.Push(symbol-'0');
        else{
            int a=S.Pop();
            int b=S.Pop();
            int value=Apply(a,symbol,b);
            S.Push(value);
        }
    }
    return S.StackTop();
}

/*********************************************************************/
// Precedence: Prcd(StackTop, Symbol) = true -> pop, false -> push
int level(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/' || c=='%') return 2;
    return 1;                        // + -
}

bool Prcd(char top,char symbol){
    if(top=='(')                     // Prcd('(',op)=F, Prcd('(',')')=F
        return false;
    if(symbol=='(')                  // Prcd(op,'(')=F
        return false;
    if(symbol==')')                  // Prcd(op,')')=T
        return true;
    if(top=='^' && symbol=='^')      // ^ is right associative
        return false;
    return level(top)>=level(symbol);
}

// Infix to Postfix (with brackets, brackets treated as operators)
string InfixToPostfix(string Infix){
    string Postfix="";
    Stack S;
    int i=0;
    while(i<Infix.size()){
        char symbol=Infix[i];
        i++;
        if(IsOperand(symbol))
            Postfix=Postfix+symbol;
        else{
            while(!S.IsEmpty() && Prcd(S.StackTop(),symbol)){
                char x=S.Pop();
                Postfix=Postfix+x;
            }
            if(symbol!=')')
                S.Push(symbol);
            else
                S.Pop();             // discard '('
        }
    }
    while(!S.IsEmpty()){
        char x=S.Pop();
        Postfix=Postfix+x;
    }
    return Postfix;
}

// Infix to Prefix: reverse (swap brackets), convert, reverse again
// Equal precedence: push (pop only for ^), pop when stack top is higher
bool PrcdPrefix(char top,char symbol){
    if(top=='(')
        return false;
    if(symbol=='(')
        return false;
    if(symbol==')')
        return true;
    if(level(top)>level(symbol))
        return true;
    if(level(top)==level(symbol) && symbol=='^')
        return true;
    return false;
}

string InfixToPrefix(string Infix){
    reverse(Infix.begin(),Infix.end());
    for(int k=0;k<Infix.size();k++){
        if(Infix[k]=='(') Infix[k]=')';
        else if(Infix[k]==')') Infix[k]='(';
    }
    string Prefix="";
    Stack S;
    int i=0;
    while(i<Infix.size()){
        char symbol=Infix[i];
        i++;
        if(IsOperand(symbol))
            Prefix=Prefix+symbol;
        else{
            while(!S.IsEmpty() && PrcdPrefix(S.StackTop(),symbol)){
                char x=S.Pop();
                Prefix=Prefix+x;
            }
            if(symbol!=')')
                S.Push(symbol);
            else
                S.Pop();             // discard '('

        }
    }
    while(!S.IsEmpty()){
        char x=S.Pop();
        Prefix=Prefix+x;
    }
    reverse(Prefix.begin(),Prefix.end());
    return Prefix;
}

/*********************************************************************/

int main(){
    cout<<"Postfix 345*+7- : "<<PostfixEvaluation("345*+7-")<<endl;
    cout<<"Postfix 732^*42^-8+ : "<<PostfixEvaluation("732^*42^-8+")<<endl;
    cout<<"Prefix -*+657-64 : "<<PrefixEvaluation("-*+657-64")<<endl;
    cout<<"Prefix +-^82^728 : "<<PrefixEvaluation("+-^82^728")<<endl;

    cout<<"a*b/c^d-e (postfix) : "<<InfixToPostfix("a*b/c^d-e")<<endl;
    cout<<"a^b^c-d/e+f (postfix) : "<<InfixToPostfix("a^b^c-d/e+f")<<endl;
    cout<<"a+(b-c*d) (postfix) : "<<InfixToPostfix("a+(b-c*d)")<<endl;
    cout<<"a*b+(c-(d/e+f*g)) (postfix) : "<<InfixToPostfix("a*b+(c-(d/e+f*g))")<<endl;
    cout<<"a^(b^(c-d*e^f)+g)^h (postfix) : "<<InfixToPostfix("a^(b^(c-d*e^f)+g)^h")<<endl;
    cout<<"(b^2-4*a*c)/(2*a) (postfix) : "<<InfixToPostfix("(b^2-4*a*c)/(2*a)")<<endl;
    cout<<"a^(b+c-(d/e+f)) (postfix) : "<<InfixToPostfix("a^(b+c-(d/e+f))")<<endl;

    cout<<"a*b/c^d-e (prefix) : "<<InfixToPrefix("a*b/c^d-e")<<endl;
    cout<<"a^b^c+d/e*f+g-h^i (prefix) : "<<InfixToPrefix("a^b^c+d/e*f+g-h^i")<<endl;
    cout<<"a+(b-c*d) (prefix) : "<<InfixToPrefix("a+(b-c*d)")<<endl;
}
