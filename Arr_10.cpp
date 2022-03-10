//Find duplicate element in an element of n+1 elements
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int Sorting(int *a, int n){
            sort(a, a + n);
            for (int i = 0; i < n - 1; i++){
                if(a[i]==a[i+1])
                    return a[i];
            }
        }

        // int SET(int *a, int n){
        //     unordered_set<int> seen;
        //     for(auto &itr : a){
        //         if(seen.count(itr))
        //             return itr;
        //         seen.insert(itr);
        //     }
        //     return -1;
        // }

        int Neg_marking(int *a, int n){
            int duplicate = -1;
            for (int i = 0; i < n;i++){
                int curr = abs(a[i]);
                if(a[curr]<0){
                    duplicate = curr;
                    break;
                }
                a[curr] *= -1;
            }
            for (int i = 0; i < n;i++)
                a[i] = abs(a[i]);

            return duplicate;
        }

        void Answer_Sorting(int *a, int n){
            cout << "The repeated element in the array via sorting method is : " << Sorting(a, n) << endl;
            cout << "Answer via Neg approach : " << Neg_marking(a, n) << endl;
        }


};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9};
    int n = 10;

    class Solution s;
    s.Answer_Sorting(a, n);
    return 0;
}