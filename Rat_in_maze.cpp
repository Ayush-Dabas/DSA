#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **a, int x, int y, int n){
    if (x < n && y < n && a[x][y] == 1)
        return true;
    return false;
}

bool RatInmaze(int **a, int x, int y, int n, int **SolArr){
    if (x == n - 1 && y == n - 1){
        SolArr[x][y] = 1;
        return true;
    }

    if (isSafe(a, x, y, n)){
        SolArr[x][y] = 1;
        if (RatInmaze(a, x + 1, y, n, SolArr))
            return true;
        if (RatInmaze(a, x, y + 1, n, SolArr))
            return true;
        SolArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter n:\n";
    cin >> n;

    int **a = new int *[n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];
    cout << "Enter a[][]:\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }

    int **SolArr = new int *[n];
    for (int i = 0; i < n; i++){
        SolArr[i] = new int[n];
        for (int j = 0; j < n; j++)
            SolArr[i][j] = 0;
    }

    if(RatInmaze(a,0,0,n,SolArr)){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
                cout << SolArr[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "-1" << endl;

    return 0;
}
/*
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1 
*/