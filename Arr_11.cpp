//Merge 2 sorted arrays without using extra space
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void answer(int *a, int n,int *b, int m){
            for (int i = m - 1; i >= 0;i--){
                int j, last = a[n - 1];
                for (j = n - 1; j >= 0 && a[j] > b[i];j--)
                    a[j + 1] = a[j];
                if(j!=n-1||last>b[i]){
                    a[j + 1] = b[i];
                    b[i] = last;
                }
            }
        }
        void MergeConcept(int *a, int *b, int n, int m){
            int i = 0, j = 0, k = n - 1;
            while(i<=k && j<m){
                if(a[i]<b[j])
                    i++;
                else
                    swap(b[j++], a[k--]);
            }
            sort(a, a + n);
            sort(b, b + m);
        }

        void Last(int *a, int *b, int n, int m){
            int i = 0;
            while(a[n-1]>b[0]){
                if(a[i]>b[0]){
                    swap(a[i], b[0]);
                    sort(b, b + m);
                }
                i++;
            }
        }

        void Print_Array(int *a, int n){
            for (int i = 0; i < n;i++)
                cout << a[i] << " ";
            cout << endl;
        }
};

int main()
{
    int a[] = {1, 2, 3, 8, 9};
    int b[] = {4, 5, 6, 7, 9};
    class Solution s;
    // s.answer(a, 5, b, 5);
    // s.MergeConcept(a, b, 5, 5);
    s.Last(a, b, 5, 5);
    s.Print_Array(a, 5);
    s.Print_Array(b, 5);
    return 0;
}