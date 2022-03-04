// Move all the -ve nos to begining and +ve to end
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void Partition_QuickSort(int *a, int n);
        void Two_Pointer_approach(int *a, int n);
        void DNF_Algo(int *a, int n);
        void Print_Array(int *a, int n);
};

void Solution::Print_Array(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void Solution::Partition_QuickSort(int *a, int n){
    int j = 0;
    for (int i = 0; i < n; i++){
        if(a[i]<0){
            if(i!=j)
                swap(a[i], a[j]);
            j++;
        }
    }
}

void Solution::Two_Pointer_approach(int *a, int n){
    int left = 0;
    int right = n - 1;
    while(left<=right){
        if(a[left]<0 && a[right]<0)
            left++;
        else if(a[left]>0 && a[right]<0){
            swap(a[left], a[right]);
            left++;
            right--;
        }
        else if(a[left]>0 && a[right]>0)
            right--;
        else{
            right--;
            left++;
        }
    }
}

void Solution::DNF_Algo(int *a, int n){
    int low = 0;
    int high = n - 1;
    while(low<high){
        if(a[low]<0)
            low++;
        else if(a[high]>0)
            high--;
        else
            swap(a[low], a[high]);
    }
}

int main()
{
    int a[] = {1, 4, -2, 5, -5, 10, -89, 3, -90, 83};
    int b[] = {1, 4, -2, 5, -5, 10, -89, 3, -90, 83};
    int c[] = {1, 4, -2, 5, -5, 10, -89, 3, -90, 83};
    int n = 10;
    class Solution s;
    s.Partition_QuickSort(a, n);
    s.Print_Array(a, n);
    s.Two_Pointer_approach(b, n);
    s.Print_Array(b, n);
    s.DNF_Algo(c, n);
    s.Print_Array(c, n);
    return 0;
}