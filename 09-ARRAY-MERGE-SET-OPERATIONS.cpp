#include <bits/stdc++.h>
using namespace std;

// All inputs must be sorted

// Merge (keeps duplicates)
vector<int> Merge(int A[],int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            C.push_back(A[i++]);
        else
            C.push_back(B[j++]);
    }
    while(i<m)
        C.push_back(A[i++]);
    while(j<n)
        C.push_back(B[j++]);
    return C;
}

// A U B
vector<int> Union(int A[],int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            C.push_back(A[i++]);
        else if(B[j]<A[i])
            C.push_back(B[j++]);
        else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    while(i<m)
        C.push_back(A[i++]);
    while(j<n)
        C.push_back(B[j++]);
    return C;
}

// A ^ B
vector<int> Intersection(int A[],int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            i++;
        else if(B[j]<A[i])
            j++;
        else{
            C.push_back(A[i]);
            i++;
            j++;
        }
    }
    return C;
}

// A - B
vector<int> AminusB(int A[],int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            C.push_back(A[i++]);
        else if(B[j]<A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    while(i<m)
        C.push_back(A[i++]);
    return C;
}

// B - A
vector<int> BminusA(int A[],int B[],int m,int n){
    return AminusB(B,A,n,m);
}

// (A-B) U (B-A)
vector<int> SymmetricDifference(int A[],int B[],int m,int n){
    vector<int> C;
    int i=0,j=0;
    while(i<m && j<n){
        if(A[i]<B[j])
            C.push_back(A[i++]);
        else if(B[j]<A[i])
            C.push_back(B[j++]);
        else{
            i++;
            j++;
        }
    }
    while(i<m)
        C.push_back(A[i++]);
    while(j<n)
        C.push_back(B[j++]);
    return C;
}

void Print(string s,vector<int> C){
    cout<<s;
    for(int x:C)
        cout<<x<<" ";
    cout<<endl;
}

int main(){
    int A[]={5,10,20,30,50};
    int B[]={6,10,18,20,25,30};
    int m=5,n=6;

    Print("Merge        : ",Merge(A,B,m,n));
    Print("Union        : ",Union(A,B,m,n));
    Print("Intersection : ",Intersection(A,B,m,n));
    Print("A - B        : ",AminusB(A,B,m,n));
    Print("B - A        : ",BminusA(A,B,m,n));
    Print("A (-) B      : ",SymmetricDifference(A,B,m,n));
}
