#include <bits/stdc++.h>
using namespace std;

// 1) Factorial
int fact(int n){
    if(n==0)
        return 1;
    return n*fact(n-1);
}

// 2) Power
int Power(int a,int n){
    if(n==0)
        return 1;
    return a*Power(a,n-1);
}

// 3) GCD (subtraction)
int gcd1(int a,int b){
    if(a==b)
        return a;
    if(a>b)
        return gcd1(a-b,b);
    return gcd1(a,b-a);
}

// 4) GCD (modulus)
int gcd2(int a,int b){
    if(a==0)
        return b;
    if(b==0)
        return a;
    if(a>b)
        return gcd2(a%b,b);
    return gcd2(a,b%a);
}

// 5) Sum of digits
int sumDigits(int n){
    if(n==0)
        return 0;
    return n%10+sumDigits(n/10);
}

// 6) Sum of array elements
int sumArray(int Arr[],int n){
    if(n==-1)
        return 0;
    return Arr[n]+sumArray(Arr,n-1);
}

// 7) Fibonacci : fib(1)=0, fib(2)=1  -> O(2^n) time, O(n) space
int fib(int n){
    if(n==1 || n==2)
        return n-1;
    return fib(n-1)+fib(n-2);
}

// Fibonacci with memo (removes redundant calls) -> O(n)
int fibMemo(int n,int memo[]){
    if(n==1 || n==2)
        return n-1;
    if(memo[n]!=-1)
        return memo[n];
    memo[n]=fibMemo(n-1,memo)+fibMemo(n-2,memo);
    return memo[n];
}

// Print array elements
void PrintElements(vector<int> &arr,int i){
    if(i==arr.size())
        return;
    cout<<arr[i]<<" ";
    PrintElements(arr,i+1);
}

// Reverse array display
void PrintReverse(vector<int> &arr,int i){
    if(i<arr.size()){
        PrintReverse(arr,i+1);
        cout<<arr[i]<<" ";
    }
}

// Binary search
int BS(int A[],int low,int high,int key){
    if(low>high)
        return -1;
    int mid=(low+high)/2;
    if(A[mid]==key)
        return mid;
    if(key<A[mid])
        return BS(A,low,mid-1,key);
    return BS(A,mid+1,high,key);
}

// Tower of Hanoi
void TOH(int n,char S,char M,char D){
    if(n==1)
        cout<<S<<"->"<<D<<endl;
    else{
        TOH(n-1,S,D,M);
        cout<<S<<"->"<<D<<endl;
        TOH(n-1,M,S,D);
    }
}

int main(){
    cout<<"fact(5) = "<<fact(5)<<endl;
    cout<<"Power(2,5) = "<<Power(2,5)<<endl;
    cout<<"gcd1(35,25) = "<<gcd1(35,25)<<endl;
    cout<<"gcd2(27,33) = "<<gcd2(27,33)<<endl;
    cout<<"sumDigits(12345) = "<<sumDigits(12345)<<endl;
    int Arr[]={10,20,30,40};
    cout<<"sumArray = "<<sumArray(Arr,3)<<endl;
    cout<<"fib(8) = "<<fib(8)<<endl;
    int memo[50];
    fill(memo,memo+50,-1);
    cout<<"fibMemo(8) = "<<fibMemo(8,memo)<<endl;
    vector<int> v={1,2,3,4,5};
    cout<<"Print : ";        PrintElements(v,0);   cout<<endl;
    cout<<"Reverse : ";      PrintReverse(v,0);    cout<<endl;
    int B[]={5,10,20,30,50};
    cout<<"BS(30) index = "<<BS(B,0,4,30)<<endl;
    cout<<"Tower of Hanoi n=3 (7 moves):"<<endl;
    TOH(3,'S','M','D');
}
