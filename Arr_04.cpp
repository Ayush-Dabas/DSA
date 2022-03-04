// Sort an element of 0's 1's and 2's
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void Sort(int *a, int n){
            cout << "This array is now going to be sorted !\n";
            int low = 0;
            int mid = 0;
            int high = n - 1;
            while(mid<=high){
                switch (a[mid])
                {
                case 0:
                    swap(a[low++], a[mid++]);
                    break;
                
                case 1:
                    mid++;
                    break;

                case 2:
                    swap(a[mid], a[high--]);
                    break;

                default:
                    break;
                }
            }
        }

        void Print_Array(int *a, int n){
            for (int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main()
{
    int a[] = {0, 1, 2, 0, 0, 1, 2, 1, 2, 1};
    int n = 10;
    class Solution s;
    s.Print_Array(a, n);
    s.Sort(a, n);
    s.Print_Array(a, n);

    return 0;
}