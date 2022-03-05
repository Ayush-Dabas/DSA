// Longest subarray sum
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int Answer(int *a, int n){
            int sum = INT_MIN;
            int temp = 0;
            for (int i = 0; i < n; i++){
                temp += a[i];
                if(sum<temp)
                    sum = temp;
                if(temp<0)
                    temp = 0;
            }
            return sum;
        }
};

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    class Solution s;
    cout << s.Answer(a, n) << endl;
    return 0;
}