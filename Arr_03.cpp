//Kth smallest element
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    void Print_Line(){
        cout<<"\n>------------------------------------<\n\n";
    }

    void Simple_Solution(int *a, int n, int k){
        sort(a,a+n);
        cout<<"The " << k << "th element of the array is : " <<a[k-1]<< endl;
    }

    void SET_Solution(int *a, int n, int k){
        set<int> s(a,a+n);
        set<int>::iterator itr = s.begin();
        advance (itr,k-1);
        cout<<"The " << k << "th element of the array is : " <<*itr<<endl;
    }

    void Map_Solution(int *a, int n, int k){
        map<int,int> m;
        for(int i=0; i<n; i++)
            m[a[i]] += 1;
        int freq = 0;
        for(auto itr = m.begin(); itr!=m.end(); itr++){
            freq += (itr->second);
            
            if(freq>=k){
                cout<<"The " << k << "th element of the array is : " <<itr->first<<endl;
                return ;
            }
        }
    }
};

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int n = 10;
    class Solution S;
    S.Simple_Solution(a,n,5);
    S.Print_Line();
    S.SET_Solution(a,n,6);
    S.Print_Line();
    S.Map_Solution(a,n,4);
    return 0;
}