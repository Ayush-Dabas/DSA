#include <bits/stdc++.h>
using namespace std;

void printArray(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i]<<" ";
    cout << endl;
}

void stlMethod(int *a, int n){
    next_permutation(a, a + n);
    printArray(a, n);
}

void swapElement(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void reverseArray(int *a, int n){
    for (int i = 0; i<n/2 ; i++){
        swapElement(a[i], a[n-1-i] );
    }
}

void nextPermutaion(int *a, int n){
    int k,l;
    for (int k = n - 2; k >= 0; k--){
        if(a[k]<=a[k+1])
            break;
    }
    if(k<0){
        reverseArray(a, n);
    }
    else{
        for (int l = n - 1; l > k; l--){
            if(a[l]>a[k]){
                break;
            }
        }
        swapElement(a[k], a[l]);
        reverseArray(a, n);
    }
    
}

int main(){
    int a[3] = {1, 3, 2};
    // stlMethod(a, 3);
    nextPermutaion(a, 3);
    printArray(a, 3);
    return 0;
}