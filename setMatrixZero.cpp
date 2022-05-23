#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void setValueArray(int *a, int n, int val){
    for (int i = 0; i < n; i++)
        a[i] = val;
}

void setValue(vector< vector<int>> &a, int n, int m ,int i, int j, int value){
    for (int temp = 0; temp < n; temp++){
        a[temp][j] = value;
    }
    for (int temp = 0; temp < m; temp++){
        a[i][temp] = value;
    }
}

void bruteForce(vector< vector<int>> &a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j]==0){
                setValue(a, n, m, i, j , -1);
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] == -1)
                a[i][j] = 0;
        }
    }
}

void dummyArrays(vector< vector<int>> &a, int n, int m){
    int *rows = new int[n];
    int *cols = new int[m];
    setValueArray(rows, n, -1);
    setValueArray(cols, m, -1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(a[i][j] == 0){
                rows[i] = 0;
                cols[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(rows[i]==0 || cols[j]==0){
                a[i][j] = 0;
            }
        }
    }
    delete[] rows;
    delete[] cols;
}

void optimisedDummyArrays(vector<vector<int>> &a, int n, int m){
    int col0 = 1;

    for (int i = 0; i < n; i++){
        if(a[i][0] == 0)
            col0 = 0;
        for (int j = 0; j < m; j++){
            if(a[i][j] == 0){
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if(a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;
        }
        if(col0 == 0)
            a[i][0] = 0;
    }
}

int main(){
    vector< vector <int> > a = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> b = {{1, 2, 3, 4, 0}, {0, 2, 3, 5, 1}, {2, 3, 1, 5, 6}};
    // bruteForce(a, 3, 3);
    // bruteForce(b, 3, 5);
    // dummyArrays(a, 3, 3);
    // dummyArrays(b, 3, 5);
    optimisedDummyArrays(a, 3, 3);
    optimisedDummyArrays(b, 3, 5);
    print(a, 3, 3);
    print(b, 3, 5);

    return 0;
}