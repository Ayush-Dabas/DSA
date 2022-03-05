//Find out the minimum possible difference of the height of shortest and longest towers after you have modified each tower.
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int Minimum_Height(int *a, int n, int k){
            sort(a, a + n);
            int ans = a[n - 1] - a[0];

            int temp_Min = a[n-1], temp_Max = 0;
            for (int i = 1; i < n; i++){
                temp_Max = max(a[i-1] + k, a[n-1]-k);
                temp_Min = min(a[0] + k, a[i]-k);
                ans = min(ans, temp_Max - temp_Min);
            }

            return ans;
        }
};

int main()
{
    int a[] = { 1, 10, 14, 14, 14, 15 };
    int n = 6;
    int k = 6;
    class Solution s;
    cout << s.Minimum_Height(a, n, k) << endl;    
    return 0;
}