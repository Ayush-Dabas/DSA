//Write a program to reverse an array or string
#include<bits/stdc++.h>
using namespace std;

void Print_Array(int *a, int n){
    for(int i=0; i<n ; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void Reverse_Array_Iterative(int *a, int n){
    int l = 0, r = n-1;
    while(l<=r){
        swap(a[l],a[r]);
        l++;
        r--;
    }
}

void Reverse_Array_Recursive(int *a, int l, int r){
    if(l>=r)
        return;
    swap(a[l],a[r]);
    Reverse_Array_Recursive(a,l+1,r-1);
}

int main()
{
    int a[] = {1,2,3,4,5};
    cout<<"Array before reversing : ";
    Print_Array(a,5);
    cout<<"\nArray after reversing : ";
    Reverse_Array_Iterative(a,5);
    Print_Array(a,5);
    cout<<"\nFirse kari ye bakchodi : ";
    Reverse_Array_Recursive(a,0,4);
    Print_Array(a,5);
    return 0;
}