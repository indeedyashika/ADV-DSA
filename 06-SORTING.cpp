#include <bits/stdc++.h>
using namespace std;

// Merge Sort : T(N)=2T(N/2)+O(N) -> O(N log N), space O(N)
void Merge(int A[],int low,int mid,int high){
    int C[high+1];
    int i=low, j=mid+1, k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j])
            C[k++]=A[i++];
        else
            C[k++]=A[j++];
    }
    while(i<=mid)
        C[k++]=A[i++];
    while(j<=high)
        C[k++]=A[j++];
    for(i=low;i<=high;i++)
        A[i]=C[i];
}

void MergeSort(int A[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}

/*********************************************************************/
// Partition (pivot = A[low]); array needs a sentinel (infinity) at A[high+1]
int Partition(int A[],int low,int high){
    int i=low;
    int j=high+1;
    int Pivot=A[low];
    do{
        do{ i++; }while(A[i]<Pivot);
        do{ j--; }while(A[j]>Pivot);
        if(i<j)
            swap(A[i],A[j]);
    }while(i<j);
    swap(A[low],A[j]);
    return j;
}

// Quick Sort : average O(N log N), worst O(N^2) on sorted input
void QuickSort(int A[],int low,int high){
    if(low<high){
        int j=Partition(A,low,high);
        QuickSort(A,low,j-1);
        QuickSort(A,j+1,high);
    }
}

// Median Partition: middle element becomes pivot
int MedianPartition(int A[],int low,int high){
    int mid=(low+high)/2;
    swap(A[low],A[mid]);
    return Partition(A,low,high);
}

void MedianQuickSort(int A[],int low,int high){
    if(low<high){
        int j=MedianPartition(A,low,high);
        MedianQuickSort(A,low,j-1);
        MedianQuickSort(A,j+1,high);
    }
}

// Randomized Partition: random element becomes pivot
int RandomizedPartition(int A[],int low,int high){
    int R=low+rand()%(high-low+1);
    swap(A[low],A[R]);
    return Partition(A,low,high);
}

void RandomizedQuickSort(int A[],int low,int high){
    if(low<high){
        int j=RandomizedPartition(A,low,high);
        RandomizedQuickSort(A,low,j-1);
        RandomizedQuickSort(A,j+1,high);
    }
}

void Print(string s,int A[],int n){
    cout<<s;
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<endl;
}

int main(){
    srand(time(0));
    int n=11;

    int A[]={5,2,9,1,3,8,6,14,12,4,11};
    MergeSort(A,0,n-1);
    Print("Merge Sort           : ",A,n);

    int B[20]={70,40,80,20,90,30,100,10,5,85};     // 10 elements + sentinel
    B[10]=INT_MAX;
    QuickSort(B,0,9);
    Print("Quick Sort           : ",B,10);

    int C[20]={5,10,15,20,25,30};                  // sorted = worst case input
    C[6]=INT_MAX;
    MedianQuickSort(C,0,5);
    Print("Median Quick Sort    : ",C,6);

    int D[20]={50,20,100,90,30,10,40,200,60,15,70};
    D[11]=INT_MAX;
    RandomizedQuickSort(D,0,10);
    Print("Randomized Quick Sort: ",D,11);
}
