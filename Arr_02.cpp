// Maximum and minimum of an array using minimum number of comparisons
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int Min;
    int Max;

    void Print_Solution(int a, int b){
        cout<<"The Maximum element of the array is : "<<a
        <<"\nThe Minimum element of the array is : "<<b
        <<endl;
    }
    
    void Linear_Search(int *a, int n){
        class Solution P;
        P.Max = a[0];
        P.Min = a[0];
        for(int i=0; i<n; i++){
            P.Max = max(P.Max,a[i]);
            P.Min = min(P.Min,a[i]);
        }
        Print_Solution(P.Max,P.Min);
    }

    void Pairs(int *a, int n){
        class Solution P;
        int i;
        if(n%2==0){
            P.Max = max(a[0],a[1]);
            P.Min = min(a[0],a[1]);
            i = 2;
        }
        else{
            P.Max = a[0];
            P.Min = a[0];
            i = 1;
        }
        while(i<n-1){
            if(a[i]>a[i+1]){
                if(a[i]>P.Max)
                    P.Max = a[i];
                if(a[i+1]<P.Min)
                    P.Min = a[i+1];
            }
            else{
                if(a[i+1]>P.Max)
                    P.Min = a[i+1];
                if(a[i]<P.Min)
                    P.Min = a[i];
            }
            i+=2;
        }
        Print_Solution(P.Max,P.Min);
    }
};

int main()
{
    int a[] = {9,2,3,1,10,91,5};
    int n = 7;
    class Solution S;
    S.Linear_Search(a,n);
    cout<<"<------------------------------->\n";
    S.Pairs(a,n);

    return 0;
}