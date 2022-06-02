#include <bits/stdc++.h>
using namespace std;

class sortMatrix{
    public:
        bool bruteForce(vector<vector<int>> a, int n, int m, int key);
        bool binarySearch(vector<vector<int>> a, int key);
};

bool sortMatrix::bruteForce(vector<vector<int>> a, int n, int m, int key){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(a[i][j] == key){
                return true;
            }
        }
    }
    return false;
}

bool sortMatrix::binarySearch(vector<vector<int>> a, int key){
    int low = 0;
    if(!a.size()){
        return false;
    }
    int high = (a.size() * a[0].size()) - 1;
    while(low<=high){
        int mid = (low + (high - low) / 2);
        if(a[mid/a[0].size()][mid%a[0].size()] == key){
            return true;
        }
        else if(a[mid/a[0].size()][mid%a[0].size()] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> a = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}, {21, 22, 23, 24, 25}};
    int n = 5, m = 5;
    int k1 = 15;
    int k2 = 89;

    class sortMatrix s;
    cout<< s.bruteForce(a, n, m, k1) << endl;
    cout << s.bruteForce(a, n, m, k2) << endl;
    cout<< s.binarySearch(a, k1) << endl;
    cout << s.binarySearch(a, k2) << endl;
    

    return 0;
}