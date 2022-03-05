// union of two arrays and intersection
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void Print_Array(int *a, int n){
            for (int i = 0; i < n; i++)
                cout << a[i];
            cout << endl;
        }

        void Union_Using_Set(int *a, int n, int *b, int m){
            set<int> s;
            for (int i = 0; i < n; i++)
                s.insert(a[i]);
            for (int i = 0; i < m; i++)
                s.insert(b[i]);
            cout << "Number of elements after union operations : " << s.size() << endl;
            cout << "The union of set of both arrays is : ";
            for (auto itr = s.begin(); itr != s.end(); itr++)
                cout << *itr << " ";
            cout << endl;
        }

        void Union_Using_Map(int *a, int n, int *b, int m){
            map<int, int> mp;
            for (int i = 0; i < n; i++)
                mp.insert({a[i], i});
            for (int i = 0; i < m; i++)
                mp.insert({b[i], i});

            cout << "The union of both the sets using maps is : ";
            for (auto itr = mp.begin(); itr != mp.end(); itr++)
                cout << itr->first << " ";
            cout << endl;
        }

        void Union_Using_Naive(int *a, int n, int *b, int m){
            int *UNION = new int[m + n];
            for (int i = 0; i < m+n; i++)
                UNION[i] = 0;
            for (int i = 0; i < n; i++)
                UNION[i] += a[i];
            for (int i = 0; i < m ; i++){
                if(!Element_Present(a,n,b[i]))
                    UNION[n + i] += b[i];
            }

            for (int i = 0; i < m + n; i++){
                if(UNION[i]!=0)
                    cout << UNION[i] << " ";
            }

            cout << endl;

            delete[] UNION;
        }

        bool Element_Present(int *a, int n, int element){
            for (int i = 0; i < n; i++){
                if(a[i]==element)
                    return 1;
            }
            return 0;
        }

        void Intersection_Using_Naive(int *a, int n, int *b, int m){
            int temp = min(m, n);
            int *INTERSECTION = new int[temp];
            for (int i = 0; i < temp; i++)
                INTERSECTION[i] = 0;

            int i = 0, j = 0;
            while(i<n){
                for (int k = 0; k < m; k++){
                    if(a[i]==b[k]){
                            INTERSECTION[j] += a[i];
                            j++;
                            i++;
                        }
                }
                i++;
            }

            for (int k = 0; k < temp; k++){
                if(INTERSECTION[k]!=0)
                    cout << INTERSECTION[k] << " ";
            }

            cout << endl;

            delete[] INTERSECTION;
        }
};

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int b[] = {5, 6, 7, 8, 9, 10};
    int n = 7;
    int m = 6;
    class Solution s;
    s.Union_Using_Set(a, n, b, m);
    s.Union_Using_Map(a, n, b, m);
    s.Union_Using_Naive(a, n, b, m);
    s.Intersection_Using_Naive(a, n, b, m);
    return 0;
}