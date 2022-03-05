//WAP to cyclically rotate an array by one
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void Print_Array(int *a, int n){
            for (int i = 0; i < n; i++)
                cout << a[i] <<" ";
            cout << endl;
        }

        void Rotate_Simple(int *a, int n){
            int temp = a[n - 1];
            for (int i = n-1; i > 0 ; i--){
                a[i] = a[i - 1];
            }
            a[0] = temp;
            Print_Array(a, n);
        }

        void Rotate_Using_Two_Pointers(int *a, int n){
            int i = 0, j = n - 1;
            while(i<=j){
                swap(a[i], a[j]);
                i++;
            }
            Print_Array(a, n);
        }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    class Solution s;
    s.Rotate_Simple(a, n);
    s.Rotate_Using_Two_Pointers(a, n);
    return 0;
}